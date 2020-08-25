#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/make-largest-palindrome-changing-k-digits/
string highestValuePalindrome(string s, int n, int k)
{
    int start = 0;
    int end = n - 1;
    string palin = s;

    while (start < end)
    {
        if (palin[start] != palin[end])
        {
            palin[start] = palin[end] = max(palin[start], palin[end]);
            k--;
        }
        start++;
        end--;
    }
    // cout<<palin;

    if (k < 0)
        return "-1";

    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        if (palin[l] < '9')
        {
            // cout<< palin[l]<<" "<<palin[r];
            if (l == r && k > 0)
            {
                palin[l] = palin[r] = '9';
                k--;
            }

            if (k >= 2 && palin[l] == s[l] && palin[r] == s[r])
            {
                palin[l] = palin[r] = '9';
                k -= 2;
            }

            else if (k >= 1 && (palin[l] != s[l] || palin[r] != s[r]))
            {
                palin[l] = palin[r] = '9';
                k--;
            }
        }
        l++;
        r--;
    }
    return palin;
}

// https://www.geeksforgeeks.org/lexicographically-first-palindromic-string/
string findOddAndRemoveItsFreq(int *freq)
{
    string odd_str = "";
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] % 2 != 0)
        {
            freq[i]--;
            odd_str = odd_str + (char)(i + 'a');
            return odd_str;
        }
    }
    return odd_str;
}
string findPalindromicString(string str, int n)
{
    int freq[26] = {0};
    for (int i = 0; i < n; i++)
        freq[str[i] - 'a']++;

    // for(int i=0;i<26;i++)
    //     cout<<freq[i];

    int count = 0;
    if (n % 2 == 1) //odd
    {
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] % 2 == 1)
                count++;
        }
        if (count == 0)
            return "not possible";
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] % 2 != 0)
                return "not possible!";
        }
    }
    // cout << count;
    if (count > 1)
        return "not possible";

    string front = "";
    string rear = "";
    string odd_char = findOddAndRemoveItsFreq(freq);
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
            for (int j = 0; j < freq[i] / 2; j++)
            {
                front += (char)(i + 'a');
                rear = (char)(i + 'a') + rear;
            }
    }
    return (front + odd_char + rear);
}

// https://www.geeksforgeeks.org/longest-non-palindromic-substring/
bool isPalindrome(string str, int n)
{
    for (int i = 0; i < n / 2; i++)
        if (str[i] != str[n - 1 - i])
            return false;

    return true;
}

int maxLengthNonPalinSubstring(string str)
{
    int n = str.length();
    int i;
    for (i = 0; i < n; i++)
        if (str[i] != str[0])
            break;

    if (i == n)
        return 0;

    if (isPalindrome(str, n))
        return n - 1;
    return n;
}

int main(int args, char **argc)
{
    // string s = "0011";
    // int k = 1;
    string s = "11331";
    int k = 4;
    int n = s.length();
    // cout << highestValuePalindrome(s, n, k);

    string str = "malayalam";
    // string str = "nope";
    // string str ="racecar";
    // cout << findPalindromicString(str, str.length());

    string str2 = "abba";
    cout << "Maximum length = " << maxLengthNonPalinSubstring(str2);
}