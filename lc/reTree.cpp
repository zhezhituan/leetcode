#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void show(vector<int> v){
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}
    int findPos(vector<int> &v,int tar){
        for(int i=0;i<v.size();i++){
            if(v[i]== tar)return i;
        }
        return -1;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size()==0)return NULL;
        TreeNode* root = new TreeNode(pre[0]);
        cout<<pre[0]<<" ";
        if(pre.size()==1)return root;
        root = new TreeNode(pre[0]);
        int pos = findPos(vin,pre[0]);
        cout<<pos<<" "<<endl;
        int left=pos;
        int right=vin.size()-pos-1;
        if(pos>=0){
            if(left==0){
                root -> right = reConstructBinaryTree(
                    vector<int>(pre.begin()+1,pre.end()),
                    vector<int>(vin.begin()+1,vin.end())
                );
                root -> left = NULL;
            }
            else if(right == 0){
                root -> left = reConstructBinaryTree(
                    vector<int>(pre.begin()+1,pre.end()),
                    vector<int>(vin.begin(),vin.end()-1)
                );
                root -> right = NULL;
            }
            else {
                cout<<"a"<<endl;
                show(vector<int>(pre.begin()+1,pre.begin()+left+1));
                show(vector<int>(vin.begin(),vin.begin()+left));
                cout<<"b"<<endl;
                root->left = reConstructBinaryTree(
                    vector<int>(pre.begin()+1,pre.begin()+left+1),
                    vector<int>(vin.begin(),vin.begin()+left)
                );
                cout<<endl;
                cout<<left<<" "<<"go right"<<" "<<right;
                root->right = reConstructBinaryTree(
                    vector<int>(pre.end()-right,pre.end()),
                    vector<int>(vin.end()-right,vin.end())
                );
            }
            return root;
        }  
    }


int main(){
    vector<int> pre={1,2,4,7,3,5,6,8};
    vector<int> vin={4,7,2,1,5,3,8,6};

    TreeNode* node = reConstructBinaryTree(pre,vin);
    return 0;
}
