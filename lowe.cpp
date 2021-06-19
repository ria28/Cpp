#include <iostream>
#include<vector>
#include<climits>
using namespace std;

int ans = INT_MAX;
void recur(vector<int>&arr , int src , int dest,int cnt,vector<bool>&vis)
{
	if(src == dest)
	{
		ans = min(ans ,cnt);
		// return;
	}
	// cout<<src<<" ";
	vis[src] = true;
	int back = (src-arr[src] + dest+1)%(dest+1);
	int fwd = (src + arr[src]) %(dest+1);

	if(!vis[back])
	recur(arr , back , dest , cnt +1 , vis);

	if(!vis[fwd])
	recur(arr , fwd , dest , cnt +1 , vis);
    vis[src] = false;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
        cin>>n;
		vector<int>arr(n);
		int x,y; 
		cin>>x>>y;
		for(int i=0; i<n;i++)
		{
			int ele;
			cin>>ele;
			arr[i]=ele;
		}
		vector<bool>vis(n,0);
		recur(arr,x-1,y-1,0,vis);
		cout<<ans<<"\n";
		ans =0;
	}

    return 0;

}

