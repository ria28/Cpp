#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
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

    return 0;
}