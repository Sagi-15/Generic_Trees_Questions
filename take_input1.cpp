#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode<T>*> children; //stores address of its children
        TreeNode(T data){
            this->data=data;
        }
};
void printTree(TreeNode<int> *root){
    /*handling edge cases*/
    if(root==NULL){
        return;
    }
    /*first print root ka data*/
    cout<<root->data<<":";
    /*Now, print root ke children saare*/
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<" ";
    }
    cout<<endl;
    /*Now call recursively on root ke children ie. subtree
    mann liya aur assume ki sahi answer print kar dega*/
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]); //recursively print the subtree
    }
}
TreeNode<int>* takeInput(){
    /*returns root of tree after take input of elements*/
    int rootData;
    cout<<"Enter node data : ";
    cin>>rootData;
    TreeNode<int> *root=new TreeNode<int>(rootData);
    int number_of_children_of_root;
    cout<<"Enter number of children of "<<root->data<<": ";
    cin>>number_of_children_of_root;
    /*Now jitne children honge utne hi subtrees so sbke liye recursive call*/
    for(int i=0;i<number_of_children_of_root;i++){
        TreeNode<int> *child=takeInput();//so child mei har baar subtrees ke root ka address aa jayega
        root->children.push_back(child);
    }
    return root;
}
int main(){
    TreeNode<int> *root=takeInput();
    printTree(root);
}