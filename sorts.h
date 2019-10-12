#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>


struct sheep
{
    std::string name;
    int weight;
    sheep(std::string n="",int w=0):weight(w),name(n){};
    bool operator>(const sheep& b){
        return weight>b.weight;
    }
    
};

template <typename T>
void bubble(std::vector<T> &v,bool compare(T &a,T &b));

template <typename T>
void qsort(std::vector<T> &v,int l,int r,bool compare(T &a,T &b));

template <typename T>
void showV(std::vector<T> &v,std::string tostring(T &a));

template <typename T>
void bubble(std::vector<T> &v,bool compare(T &a,T &b)){
    int len=v.size();
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-1-i;j++){
            if(!compare(v[j],v[j+1])){
                T temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
}

template <typename T>
void qsort(std::vector<T> &v,int l,int r,bool compare(T &a,T &b)){
    if(l>r)return;
    int i=l,j=r;
    T temp=v[l];
    T t;
   
    while(i!=j){
        while(compare(temp,v[j])&&i<j)
        j--;
        while(!compare(temp,v[i])&&i<j)
        i++;
        if(i<j){
            t=v[i]; 
            v[i]=v[j];
            v[j]=t;
        }
    }
    v[l]=v[i];
    v[i]=temp;
    qsort(v,l,i-1,compare);
    qsort(v,i+1,r,compare);
}

template <typename T>
void showV(std::vector<T> &v,std::string tostring(T &a)){
    for(T t:v){
        std::cout<<tostring(t)<<" ";
    }
    std::cout<<std::endl;
}


