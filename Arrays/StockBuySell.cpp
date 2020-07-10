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

        cout << "Buy on day: " << buy<< "\t Sell on day: " << sell << endl;
    }
}

int main(int args, char **argc)
{
    int price[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(price) / sizeof(price[0]);

    stockBuySell(price, n);

    return 0;
}