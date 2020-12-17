#include <iostream>
using namespace std;

bool isPalindrome(string str)
{
    int i = 0, j = str.size() - 1;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void palimParti(string str, string asf)
{
    if (str.size() == 0)
    {
        cout << asf << "\n";
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        string sub = str.substr(0, i + 1);
        string ros = str.substr(i + 1, str.size());
        if (isPalindrome(sub))
        {
            palimParti(ros, asf + " (" + sub + ") ");
        }
    }
}

//abaaba
int main()
{
    string str;
    cin >> str;
    palimParti(str, "");
    return 0;
}