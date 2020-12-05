#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n ;
        cin>>n;
        string str;
        cin>>str;
        bool flag = false;
        for(int i =0; i<n; i++)
        {
            if(str[i]=='I')
            {
                cout<<"INDIAN\n";
                flag = 1;
                break;
            }
            if(str[i]=='Y')
            {
                cout<<"NOT INDIAN\n";
                flag =1;
                break;
            }
            
        }
        if(!flag)
        cout<<"NOT SURE\n";
    }
    return 0;
}