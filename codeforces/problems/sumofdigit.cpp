// https://www.codechef.com/submit/FLOW006
#include<iostream>
using namespace std;
int add(int no){
    int rem =0;
    while(no >0){
        rem += no%10;
        no =no/10;        
    }
    return rem;
}
int main(){
    int t,no;
    cin>>t;

    while(t-->0){
        cin>>no;
        cout<<add(no);
    }
    return 0;
}