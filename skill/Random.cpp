#include<iostream>
#include<random>
using namespace std;
signed main() {
    mt19937 mt(hash<string>(":poop:"));
    for(int i=1;i<=5;i++) cout<<mt()<<" \n"[i==5];
    return 0;
}