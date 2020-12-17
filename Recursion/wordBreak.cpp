#include <iostream>
#include <unordered_set>
using namespace std;

// given string :   microsofthiring
// given words :  micro soft hi ring microsoft hiring

// make sentences out of these
// 1. micro soft hi ring
// 2. microsoft hi ring
// 3. micro soft hiring
// 4. microsoft hiring

void wordBreak(string str, unordered_set<string> words, string asf)
{
    if (str.size() == 0)
    {
        cout << asf << "\n";
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        string left = str.substr(0, i + 1);
        string right = str.substr(i + 1);
        if (words.find(left) != words.end())
        {
            wordBreak(right, words, asf + left + " ");
        }
    }
}

int main()
{
    string str;
    cin >> str;
    int n;
    cin >> n;
    unordered_set<string> words(n);
    while (n--)
    {
        string ele;
        cin >> ele;
        words.insert(ele);
    }
    wordBreak(str, words, "");
    return 0;
}