#include<bits/stdc++.h>
using namespace std;


// string rotation lps.
int main()
{
    string s, t ;
    cin>>s;
    cin>>t;
    
    string str = s+"#"+t;
    vector<int>lps(str.size(),0);
    int i =0, j =1;
    while(j<str.size())
    {
        if(str[i]==str[j])
        {
            lps[j]=i+1;
            i++;
            j++;
        }
        else
        {
            if(i>0)
            {
                i = lps[i-1];
            }
            else
            {
                lps[j]=0;
                j++;
            }
        }
    }
    // int len =;
    cout<< s.size()-lps[lps.size()-1];
    return 0;
}






// string root question .
// int main()
// {
//     string str ;
//     cin>>str;
//     vector<int>lps(str.size(),0);
//     int i =0, j =1;
//     while(j<str.size())
//     {
//         if(str[i]==str[j])
//         {
//             lps[j]=i+1;
//             i++;
//             j++;
//         }
//         else
//         {
//             if(i>0)
//             {
//                 i = lps[i-1];
//             }
//             else
//             {
//                 lps[j]=0;
//                 j++;
//             }
//         }
//     }
//     int len = str.size() - lps[str.size()-1];
//     cout<< str.size()/len;
//     return 0;
// }
