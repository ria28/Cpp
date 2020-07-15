// https://www.geeksforgeeks.org/stock-buy-sell/
#include <iostream>

using namespace std;

void stockBuySell(int price[], int n)
{
    int i = 0;
    while (i < n - 1)
    {
        while (price[i + 1] <= price[i])
            i++;

        int buy = i;

        while (price[i + 1] >= price[i])
            i++;
        int sell = i;

        i++;

        cout << "Buy on day: " << buy << "\t Sell on day: " << sell << endl;
    }
}
// https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/
void stockBuySell2(int price[], int n,int k)
{
    int i = 0;
    int sum = 0;
    int flag = 0;
    while (i < n - 1)
    {
        if (flag < k)
        {
            while (price[i + 1] <= price[i])
                i++;

            int buy = i;
            flag++;

            while (price[i + 1] >= price[i])
                i++;
            int sell = i;

            i++;

            cout << "Buy on day: " << buy << "\t Sell on day: " << sell << endl;
            sum += price[sell] - price[buy];
        }
    }
    cout << sum;
}

int main(int args, char **argc)
{
    int price[] = { 12, 14, 17, 10, 14, 13, 12, 15 };
    int n = sizeof(price) / sizeof(price[0]);

    // stockBuySell(price, n);
    int k = 3;
    stockBuySell2(price, n,k);

    return 0;
}