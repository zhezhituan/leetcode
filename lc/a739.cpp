#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
vector<int> dailyTemperatures(vector<int>& T) {
        int i=T.size();
        int j=i;
        vector<int> res(i,0);
        res[i-1]=0;
        for(i=T.size()-2;i>=0;i--){
            j=i+1;
            while(j<T.size()){
                if(res[j]==0&&T[i]>=T[j])break;
                if(T[i]<T[j]){
                    res[i]=j-i;
                    break;
                    }
                else j=j+res[j];
                }
            //std::cout<<res[i];
            }
    
        return res;
        
    }
int main(){
    vector<int> a={73,74,75,71,69,72,76,73};
    vector<int> b=dailyTemperatures(a);
    for(int x:b){
        cout<<x<<" ";
    }
}
