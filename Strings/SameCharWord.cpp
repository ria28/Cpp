#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string.h>
const int MAX_CHARS = 256;
using namespace std;

// Generates a key from given string. The key
// contains all unique characters of given string in
// SORTED  order consisting of only distinct elements.

// https://www.geeksforgeeks.org/print-words-together-set-characters/
string findKey(string word)
{
    vector<bool> vis(26, false);
    for (int i = 0; i < word.length(); i++)
        vis[word[i] - 'a'] = true;

    string key;
    for (int i = 0; i < 26; i++)
        if (vis[i])
            key += (char)(i + 'a');

    return key;
}

void wordsWithSameCharSet(string words[], int n)
{
    unordered_map<string, vector<int>> map;
    for (int i = 0; i < n; i++)
    {
        string key = findKey(words[i]);
        map[key].push_back(i);
    }

    for (auto it = map.begin(); it != map.end(); it++)
    {
        for (auto j = (*it).second.begin(); j != (*it).second.end(); j++)
        {
            cout << words[*j] << " ";
        }
        // cout << "\n";
    }
}

//https://www.geeksforgeeks.org/generate-all-binary-strings-from-given-pattern/
void print(string str, int index)
{
    if (index == str.length())
    {
        cout << str << endl;
        return;
    }
    if (str[index] == '?')
    {
        str[index] = '1';
        print(str, index + 1);

        str[index] = '0';
        print(str, index + 1);
    }
    else
        print(str, index + 1);
}

// https://www.geeksforgeeks.org/smallest-window-contains-characters-string/

string findSubString(string str)
{
    // to find distinct alphabets
    vector<bool> vis(MAX_CHARS, false);
    int distinct = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (!vis[str[i]])
        {
            vis[str[i]] = true;
            distinct++;
        }
    }

    int curr_count[MAX_CHARS] = {0};
    int count = 0, start = 0, min_len = INT64_MAX, start_idx;
    for (int i = 0; i < str.length(); i++)
    {
        curr_count[str[i]]++;

        if (curr_count[str[i]] == 1)
            count++;

        if (count == distinct)
        {
            while (curr_count[str[start]] > 1)
            {
                curr_count[str[start]]--;
                start++;
            }

            int len_window = i - start + 1;
            if (min_len > len_window)
            {
                min_len = len_window;
                start_idx = start;
            }
        }
    }

    return str.substr(start, min_len);
}

// https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
string findSubString2(string str, string pat)
{
    int len1 = str.length();
    int len2 = pat.length();

    if (len1 < len2)
        return "";

    int hash_str[MAX_CHARS] = {0};
    int hash_pat[MAX_CHARS] = {0};

    for (int i = 0; i < len2; i++)
        hash_pat[pat[i]]++;

    int start = 0, count = 0, min_len = INT64_MAX, start_idx = -1;
    for (int j = 0; j < len1; j++)
    {
        hash_str[str[j]]++;

        cout << str[j] << " ";
        if (hash_pat[str[j]] != 0 && hash_str[str[j]] <= hash_pat[str[j]])
            count++;

        // cout<<count;
        if (count == len2)
        {
            // cout<<count;
            while (hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0)
            {
                if (hash_str[str[start]] > hash_pat[str[start]])

                    hash_str[str[start]]--;

                start++;
            }

            int len_window = j - start + 1;
            cout << len_window;
            if (min_len > len_window)
            {
                // cout<<min_len;
                //update
                min_len = len_window;
                start_idx = start;
            }
        }
    }
    // if (start_idx == -1)
    //     return "hell";
    cout << min_len;
    return str.substr(start, min_len);
}

int main(int args, char **argc)
{
    // string words[] = {"may", "student", "students", "dog",
    //                   "studentssess", "god", "cat", "act", "tab",
    //                   "bat", "flow", "wolf", "lambs", "amy", "yam",
    //                   "balms", "looped", "poodle"};
    string words[] = {"cat", "dog", "tac", "god", "act"};
    int n = sizeof(words) / sizeof(words[0]);
    // wordsWithSameCharSet(words, n);

    string str = "1??0?101";
    // print(str, 0);

    string str2 = "aabcbcdbca";
    // cout << "Smallest window containing all distinct characters is: "<< findSubString(str2);

    // string str3 = "this is a test string";
    // string pattern = "tist";
    string str3 = "geeksforgeeks";
    string pattern = "ork";
    cout << "smallest window in a string containing all char of another string : " << findSubString2(str3, pattern);

    return 0;
}