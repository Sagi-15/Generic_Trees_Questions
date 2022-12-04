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
bool isPresent(TreeNode<int> *root,int x){
    /*first we check if x is in root
    then recursion ko bol subtrees mei dekh ke aao
    ek mei bhi x => x is present in tree*/

    /*edge case*/
    if(root==NULL){
        return false;
    }
    /*checking if root hi x or not*/
    else if(root->data==x){
        return true;
    }
    else if(root->data!=x){
        /*now recursion se bol check on neeche walle subtrees*/
        bool answer=false;//root mei false ab aage true => or se true overall
        for(int i=0;i<root->children.size();i++){
            bool smallAnswer=isPresent(root->children[i],x);
            /*small answer mei true agar subtree ith mei x ho*/
            answer=(answer) or (smallAnswer);
        }
        return answer;
    }
}