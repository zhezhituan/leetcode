#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};



Node* func(vector<vector<int>>& grid,int i,int j,int len){
    Node* root =new Node(NULL,NULL,NULL,NULL,NULL,NULL);
    cout<<i<<j<<len<<endl;
    if(len==1){
        grid[i][j]==0?root->val=false:root->val=true;
        root->isLeaf=true;
        cout<<"a";
        return root;
    }
    
    Node* Node_tl = func(grid,i,j,len/2);
    Node* Node_tr = func(grid,i,j+len/2,len/2);
    Node* Node_bl = func(grid,i+len/2,j,len/2);
    Node* Node_br = func(grid,i+len/2,j+len/2,len/2);
    if(Node_tl->val)cout<<"a";
    else cout<< "b";
    
    if( (!(Node_tl->val^Node_tr->val))&&
        (!(Node_bl->val^Node_br->val))&&
        (!(Node_tl->val^Node_bl->val))){
        root->val=Node_bl->val;
        root->isLeaf=true;
        cout<<"leaf"<<endl;
        return root;
    }
    else{
        cout<<"No"<<endl;
        return new Node(NULL,false,Node_tl,Node_tr,Node_bl,Node_br);
    }
}
Node* construct(vector<vector<int>>& grid) {
    Node* res = func(grid,0,0,grid.size());
    return res;
}
int main(){
    vector<vector<int> > a={{1,1},{1,1}};
    Node* res = construct(a);
    if(res->val){
        cout<<"a";
    } else {
        cout<<"b";
    }
    
}

