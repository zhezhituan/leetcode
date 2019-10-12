#include<iostream>
#include<stdlib.h>
#include"sorts.h"
#include<stdio.h>
#include <algorithm>
#include<vector>

bool myfun(sheep& a,sheep& b){
    return a.weight>b.weight;
}

std::string my2str(sheep& a){
    return a.name+std::to_string(a.weight);
}

template<typename T>
void swaps(T i1,T i2){
    auto i=*i1;
    *i1=*i2;
    *i2=i;
}
//下一个全排列 
template<typename T>
bool next_p(T t1,T t2){
    T t=t2-2;
    while(t >= t1 && !(*(t+1)>*(t))){
        t--;
    }
    if(t==t1-1)return false;
    T tt=t2-1;
    while( !(*tt>*t) ) tt--;
    swaps(t,tt);
    t++;
    t2--;
    while(t<=t2){
        swaps(t,t2);
        t++;
        t2--;
    }
    return true;
}
template<typename T>
void show(T t1,T t2){
    for(T t=t1;t<t2;t++){
        std::cout<<*t<<" ";
    }    
    std::cout<<std::endl;
}
int main(){
    // std::vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // while(next_p(v.begin(),v.end())){
    //     show(v.begin(),v.end());
    // }
    std::vector<sheep> res;
    res.push_back(sheep("a",1));
    res.push_back(sheep("b",2));
    res.push_back(sheep("c",3));
    res.push_back(sheep("d",4));
    // qsort(res,0,int(res.size()-1),myfun);
    // showV(res,my2str);
    if(*(res.begin()+1)>*(res.begin())){
        std::cout<<"aa";
    }
    while(next_p(res.begin(),res.end())){
         showV(res,my2str);
    }
    int a;
    std::cin>>a;

}