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
class Pair{
    public:
        TreeNode<int> *node;
        int level;
};
void replaceWithDepthValue(TreeNode<int>* root){
    queue<Pair*> q;
    Pair *initial=new Pair;
    initial->level=0;
    initial->node=root;
    q.push(initial);
    root->data=initial->level;
    while(q.empty()==false){
        Pair *front=q.front();
        q.pop();
        for(int i=0;i<front->node->children.size();i++){
            front->node->children[i]->data=front->level+1;
            Pair *newchild=new Pair;
            newchild->level=front->level+1;
            newchild->node=front->node->children[i];
            q.push(newchild);
        }
    }
}