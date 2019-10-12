#include "sorts.h"

bool myfun(sheep& a,sheep& b){
    return a.weight>b.weight;
}

std::string my2str(sheep& a){
    return a.name+std::to_string(a.weight);
}

int main(){
    std::vector<sheep> res;
    res.push_back(sheep("a",1));
    res.push_back(sheep("b",2));
    res.push_back(sheep("c",3));
    res.push_back(sheep("d",4));
    res.push_back(sheep("e",131));
    res.push_back(sheep("f",122));
    //bubble(res,myfun);
    qsort(res,0,int(res.size()-1),myfun);
    showV(res,my2str);
    int a;
    std::cin>>a;
}