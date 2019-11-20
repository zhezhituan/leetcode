#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class BSTIterator {
public:
    std::stack<int> s;      
    BSTIterator(TreeNode* root) {
        BST(root);
    }
    
    void BST(TreeNode* root) {
        if(root==nullptr)return;
        BST(root->right);
        s.push(root->val);
        cout<<root -> val<<" "<<s.size()<<endl;
        BST(root->left);
    }
    
    /** @return the next smallest number */
    int next() {
        int temp=s.top();
        cout<<temp<<endl;
        s.pop();
        return temp;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};

int main(){
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    n2->left=n1;
    n2->right=n3;
    BSTIterator* iterator = new BSTIterator(n2);
    cout<<iterator->next();

}
