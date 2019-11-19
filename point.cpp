#include<iostream>
using namespace std;
int main(){
    int a = 0;
    const int* p1 = &a;
    int* const p2 = &a;
    cout << p1 << endl;
    cout << p2 << endl;
}