// https://www.geeksforgeeks.org/form-minimum-number-from-given-sequence/
#include <iostream>

using namespace std;
string getMinNumberForPattern(string seq)
{
    int n = seq.length();
    string result(n + 1, ' ');

    int count = 1;

    for (int i = 0; i <= n; i++)
    {
        if (i == n || seq[i] == 'I')
        {
            for (int j = i - 1; j >= -1; j--)
            {
                result[j + 1] = '0' + count++;
                if (j >= 0 && seq[j] == 'I')
                    break;
            }
        }
    }
    return result;
}
int main(int args, char **argc)
{
    string inputs[] = {"IDID", "I", "DD", "II", "DIDI", "IIDDD", "DDIDDIID"};

    for (string input : inputs)
    {
        cout << getMinNumberForPattern(input) << "\n";
    }
    return 0;
}