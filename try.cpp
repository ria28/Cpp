#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k;
    // cin>>n>>k;
    n=39; 
    k =20;
    int val[n] = {0 ,1, 0, 0, 0, 0, 0, 0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0, 0, 0, 0, 1, 0, 1, 0 ,1 ,0 ,1 ,0 ,1 ,0 ,1 ,1 ,0};
    
    // for(int i =0;i<n;i++){
    //     int val_;
    //     cin>>val_;
    //     val[i]=val_;
    // }
    int time =0;  
    int last_val=0;
    for(int i =0;i<n;i++){
        if(val[i]==1){
            if(last_val==0){
                time += i;
                last_val=i;
            }  
            else{
                time += abs(i-last_val)*k;
                break;
            } 
        }
    }
    cout<<time;
    
    return 0;
}