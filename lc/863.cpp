#include<iostream>
#include<stdio.h>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include"stringToTree.h"
using namespace std;

unordered_map<TreeNode*,vector<TreeNode*> > m;
void buildmap(TreeNode* root,TreeNode* par){
    if(root==nullptr) return ;
    if(m.count(root)==0){
        vector<TreeNode*> v;
        if(root->left)v.push_back(root->left);
        if(root->right)v.push_back(root->right);
        if(par)v.push_back(par);
        m[root]=v;
    }
    buildmap(root->left,root);
    buildmap(root->right,root);
}    
vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    vector<int> res;
    if(root ==nullptr || K<0)return res;
    buildmap(root,nullptr);
    unordered_set<TreeNode*> visited;
    queue<TreeNode*> q;
    visited.insert(target);
    q.push(target);
    while(!q.empty()){
        int size =q.size();
        if(K==0){
            while(!q.empty()){
                res.push_back(q.front()->val);
                q.pop();
            }
            break;
        }
        for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            for(TreeNode* t:m[node]){
                if(visited.count(t)==0){
                    q.push(t);
                    visited.insert(t);
                }
            }
            q.pop();
        }
        K--;
    }
    return res;
}

int main(){
    string s="[0,1,null,null,2,null,3,null,4]";
    TreeNode* root = stringToTreeNode(s);
    TreeNode* target = root;
    vector<int> res=distanceK(root,target,0);
    for(int i:res) cout<<i<<" ";
    int t;
    cin>> t;
}