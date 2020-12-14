#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int getNum(string s, unordered_map<char,int>map)
{
    int no =0;
    for(int i =0; i<s.size();i++)
    {
        if(map.find(s[i]) != map.end())
        {
            no = no *10 + map[s[i]];          
        }
    }
    return  no;
}


void crypto(string unique, int idx, vector<bool> &usedNos, unordered_map<char, int> map, string s1, string s2, string s3)
{
    if(idx == unique.size())
    {
        int num1 = getNum(s1,map);
        int num2 = getNum(s2,map);
        int num3 = getNum(s3,map);

        if(num1 + num2 == num3)
        {
            for(int i =0;i<26;i++)
            {
                char a = 'a'+i;
                if(map.find(a) != map.end())
                {
                    cout<<a<<"->"<<map[a];                    
                }
            }
        }
    }
    char s = unique[idx];
    for (int i = 0; i <= 9; i++)
    {
        if(!usedNos[i])
        {
            map[s]=i;
            usedNos[i]=true;
            crypto(unique, idx+1,usedNos,map,s1,s2,s3);
            usedNos[i]=false;
            map[s]=-1;
        }
    }
}

int main()
{
    // send more money
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    unordered_map<char, int> map;
    string unique = "";
    for (int i = 0; i < s1.size(); i++)
    {
        if (map.find(s1[i]) == map.end())
        {
            map[s1[i]] = -1;
            unique += s1[i];
        }
    }
    for (int i = 0; i < s2.size(); i++)
    {
        if (map.find(s2[i]) == map.end())
        {
            map[s2[i]] = -1;
            unique += s2[i];
        }
    }
    for (int i = 0; i < s3.size(); i++)
    {
        if (map.find(s3[i]) == map.end())
        {
            map[s3[i]] = -1;
            unique += s3[i];
        }
    }
    vector<bool> usedNos(10, false);
    crypto(unique, 0, usedNos, map, s1, s2, s3);
    return 0;
}