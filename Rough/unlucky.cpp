
// 1 3  --> 2
// 11 13 31 33  --> 4
// 111 113 131 133 311 313 331 333   -> 8

// use queue---------


#include <bits/stdc++.h>
using namespace std;
#define ll long long
// vector<ll> start;
ll la = log(1e9)/log(2);
vector<ll>start(la);
void precomp()
{
    
	for(ll i=1;i<=la;i++)
    {
		start[i-1]= pow(2,i)-1;
    }
}
// string ans;
vector<string> res;
void recur(int digits, vector<string> &arr, string asf)
{
    // cout<<" efwrw";
    if (asf.size() >= digits)
    {
        res.push_back(asf);
        return;
    }
    // cout << asf << " ";
    // for (int i = 0; i < arr.size(); i++)
    // {

        // if (asf.size() == 0)
        // {
        //     recur(digits, arr, "1" + arr[0]);
        //     recur(digits, arr, "1" + arr[1]);
        //     recur(digits, arr, "3" + arr[0]);
        //     recur(digits, arr, "3" + arr[1]);
        // }
        // else
        // {
            recur(digits, arr, arr[0] + asf);
            recur(digits, arr, arr[1] + asf);
        // }
    // }
    // recur(digits-1,)
}

string func(vector<string> &arr, int n, int cnt)
{
    int strt_idx = floor(log(n) / log(2.0)); // digits
    int strt = start[strt_idx-1];   // 1 3 7 15  31 -->starting idx of 1 digit , 2 digit , 3 digi... resp
    // cout<<strt<<"\n";
    recur(strt_idx, arr, "");
    sort(res.begin(),res.end());
    // for (auto s : res)
    // {
    //     cout << s << " ";
    // }
    
    return res[n-strt];
}

int main()
{
    ll n;
    cin >> n;
    precomp();
    vector<string> demo = {"1", "3"};
    cout<<func(demo, n, 0);
    return 0;
}