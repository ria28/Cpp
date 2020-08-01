#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string.h>
#define MAX_CHARS 256

using namespace std;

// https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> map;
    for (string s : strs)
    {
        string temp = s;
        sort(s.begin(), s.end());
        map[s].push_back(temp);
    }

    vector<vector<string>> result;
    for (auto i : map)
    {
        result.push_back(i.second);
    }
    return result;
}

// https://www.geeksforgeeks.org/anagram-substring-search-search-permutations/

bool compare(char arr1[], char arr2[])
{
    for (int i = 0; i < MAX_CHARS; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}
void search(char *pat, char *txt) // search(char pat[], char txt[])
{
    int M = strlen(pat);
    int N = strlen(txt);
    // cout<<M<<N;

    char countP[MAX_CHARS] = {0};
    char countTW[MAX_CHARS] = {0};

    for (int i = 0; i < M; i++)
    {
        (countP[pat[i]])++;
        (countTW[txt[i]])++;
    }

    for (int i = M; i < N; i++)
    {
        if (compare(countP, countTW))
            cout << (i - M);

        // adding new element of current window to array
        (countTW[txt[i]])++;
        // deleting previous element of prev window from array
        (countTW[txt[i - M]])--;
    }

    // for last window
    if (compare(countP, countTW))
        cout << (N - M);
}

// https://www.geeksforgeeks.org/check-two-strings-k-anagrams-not/
int arekAnagrams(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    int count1[MAX_CHARS] = {0};
    int count2[MAX_CHARS] = {0};

    for (int i = 0; i < str1.length(); i++)
    {
        count1[str1[i]]++;
        count2[str2[i]]++;
    }
    int count =0;

    for(int i=0; i<MAX_CHARS; i++)
    {
        if(count1[i]>count2[i])
            count += abs(count1[i]-count2[i]);
    }

    return count ;
}

int main(int args, char **argv)
{
    vector<string> list{"cat", "dog", "ogd", "god", "atc"};
    vector<vector<string>> out1 = groupAnagrams(list);
    // print out1

    char txt[] = "BACDGABCDA";
    char pat[] = "ABCD";
    // search(pat, txt);

    string str1 = "anagram";
    string str2 = "grammar";
    int k = 2;
    if (arekAnagrams(str1, str2)==k)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}