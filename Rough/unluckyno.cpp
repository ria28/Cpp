#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll la = log(1e9)/log(2);
vector<ll>start(la);
void precomp()
{
    
	for(ll i=1;i<=la;i++)
    {
		start[i-1]= pow(2,i)-1;
    }
}

ll func(int n)
{
    int strt_idx = floor(log(n)/log(2.0));	
    // cout<<strt_idx<<" ";
    int strt = start[strt_idx-1];
    string start_no = to_string(pow(10,strt_idx));
    // cout<<start_no<<" ";
    for(int i = start_no.size()-1;i>=0;i--)
    {
		if(start_no[i]=='0')
            start_no[i]='1';
    }
    ll start_number = stoi(start_no);
    // cout<<start_number<<" ";
    ll dif = n-strt;
    cout<<strt;
    // for(ll i =0;i<dif ;)
    // {
    //     // cout<<start_number<<" ";
    //     start_number ++;
    //     string str = to_string(start_number);
    //     if(str[0] != '1' && str[0] != '3')
    //         continue;
    //     int prod =1;
    //     bool flag = true;
        
    //     for(int i =0;i<str.size();i++)
    //     {
	// 		prod *= str[i];
    //         double ele = log(prod)/log(3.0);
    //         if(ceil(ele) != floor(ele))
    //         {
    //             flag = false;
    //             break;
    //         }
    //     }
    //     if(flag)
    //         i++;   
    // }
    
    return start_number;    
    
}

int main() {
    ll n;
    cin>>n;
    precomp();
    // vector<string>demo={"1","3"};
    // cout<<"rfrf";
    cout<<func(n);    
    // return 0;
    return 0;
}