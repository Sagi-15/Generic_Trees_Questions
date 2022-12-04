#include <iostream>
#include <queue>
#include <vector>
using namespace std;
template <typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode<T>*> children;
};
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root){
    TreeNode<int> *largest=root;
    TreeNode<int> *second_largest=NULL;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(q.empty()==false){
        TreeNode<int> *current=q.front();
        q.pop();
        for(int i=0;i<current->children.size();i++){
            q.push(current->children[i]);
        }
        if(current->data>largest->data){
            second_largest=largest;
            largest=current;
        }
        else if(current->data<largest->data and second_largest==NULL){
            second_largest=current;
        }
    }
    return second_largest;
}