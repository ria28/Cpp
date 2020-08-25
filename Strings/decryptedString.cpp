#include <iostream>
using namespace std;

char encodedChar(string str, int k)
{
    string expand = "";
    for (int i = 0; str[i] != 0;)
    {
        string temp = "";
        int freq = 0;

        while (str[i] >= 'a' && str[i] <= 'z')
        {
            temp.push_back(str[i]);
            i++;
        }

        while (str[i] >= '1' && str[i] <= '9')
        {
            freq = 10 * freq + str[i] - '0';
            i++;
        }

        for (int j = 0; j < freq; j++)
            expand.append(temp);
    }

    return expand[k -1];
}

int main(int args, char **argc)
{
    string str = "ab4c12ed3";
    int k = 21;
    cout << encodedChar(str, k) << endl;
}