#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>
#include <stack>
int calculate(string s)
{
    int len = s.length();
    if (len == 0)
        return 0;
    stack<int> stack;
    int currentNumber = 0;
    char operation = '+';
    for (int i = 0; i < len; i++)
    {
        char currentChar = s[i];
        if (isdigit(currentChar))
        {
            currentNumber = (currentNumber * 10) + (currentChar - '0');
        }
        cout<<currentChar<<" ->"<<currentNumber<<" ";
        if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1)
        {
            if (operation == '-')
            {
                // cout<<currentNumber<<" ";
                stack.push(-currentNumber);
            }
            else if (operation == '+')
            {
                stack.push(currentNumber);
            }
            else if (operation == '*')
            {
                int stackTop = stack.top();
                stack.pop();
                stack.push(stackTop * currentNumber);
            }
            else if (operation == '/')
            {
                int stackTop = stack.top();
                stack.pop();
                stack.push(stackTop / currentNumber);
            }
            operation = currentChar;
            currentNumber = 0;
        }
    }
    int result = 0;
    while (stack.size() != 0)
    {
        result += stack.top();
        stack.pop();
    }
    return result;
}

int main()
{
    cout << calculate("22-3*5");
    return 0;
}
