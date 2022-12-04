#include <iostream>
#include <queue>
#include <vector>
using namespace std;
template <typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode<T>*> children;
        TreeNode(T data){
            this->data=data;
        }
};
TreeNode<int>* take_input_level_wise(){
    int rootData;
    cout<<"Enter root node ka data : ";
    cin>>rootData;
    /*Now make the root node*/
    TreeNode<int> *root=new TreeNode<int>(rootData);
    /*Ab queue mei push this root node
    queue make of node pointer type so that 
    aage node se uske child access aur connect kar ske*/
    queue<TreeNode<int>*> pending_children_queue;//aisa queue jismei whi nodes daale hue hai jiske saare children humne input nahi liya tha
    pending_children_queue.push(root);
    /*Now jab tak queue not empty kaam:
        i)front nikalo
        ii)get all children of front
        iii)front se children ko connect
        iv)children ko queue mei push
        v)front ke children push ho chuke so now pop*/
    while(pending_children_queue.empty()==false){
        /*executing (i)*/
        TreeNode<int> *NodeJiskaChildAbhiInputMeiLenge=pending_children_queue.front();
        int number_of_children_of_yeh_node;
        cout<<"Enter number of children of "<<NodeJiskaChildAbhiInputMeiLenge->data<<" : ";
        cin>>number_of_children_of_yeh_node;
        for(int i=0;i<number_of_children_of_yeh_node;i++){
            int child_data;
            cout<<"Enter data of child number "<<i+1<<" of "<<NodeJiskaChildAbhiInputMeiLenge->data<<" : ";
            cin>>child_data;
            TreeNode<int> *children_of_front=new TreeNode<int>(child_data);
            /*aise above se (ii) executed*/
            /*Now iii ie. connect children ko front se*/
            NodeJiskaChildAbhiInputMeiLenge->children.push_back(children_of_front);
            /*Now queue mei push children ko*/
            pending_children_queue.push(children_of_front);
        }
        /*Now pop as front ke saare children pushed in queue now*/
        pending_children_queue.pop();
    }
    return root;
}
void printLevelWise(TreeNode<int>* root){
    queue<TreeNode<int>*> q;
    q.push(root);
    while(q.empty()==false){
        TreeNode<int> *Node_to_be_printed=q.front();
        q.pop();
        cout<<Node_to_be_printed->data<<":";
        int i=0;
        for(;i<Node_to_be_printed->children.size();i++){
            /*size-1 so that last mei , nahi*/
            if(i==Node_to_be_printed->children.size()-1){
                cout<<Node_to_be_printed->children[i]->data;
            }
            else{
                cout<<Node_to_be_printed->children[i]->data<<",";
            }
            q.push(Node_to_be_printed->children[i]);
        }
        cout<<endl;
    }
}
void print_nodes_at_level_k(TreeNode<int> *root,int k){
    /*base case ismei needed as for loop
    se answer can't get isse as actually print karna hai*/
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    for(int i=0;i<root->children.size();i++){
        /*joh node tree ke liye level k 
        woh subtree k liye level k-1*/
        print_nodes_at_level_k(root->children[i],k-1);
    }
}