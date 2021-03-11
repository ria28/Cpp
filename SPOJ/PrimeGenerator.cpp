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


// WEIRD : BRUTE FORCE FOR THIS PROBLEM GIVES AC BUT SIEVES GIVE TLE  ...ARRAY SIZE IS QUITE LARGE MIGHT BE THE REASON
#include <iostream>
using namespace std;


bool isprime(int n){
    if(n<2) return false;
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m,n;
        cin >> m >> n;
        for(int i=m;i<=n;i++) {
            if(isprime(i))
                cout << i << '\n';
        }
        cout << '\n';
    }

}






// SEIVES GIVES TLE LOL :| 




// ll N = 1000000002;
// // vi prime(1000000002);
// vector<bool> isPrime(N, true);
// // vector<ll> pr;
// void primes()
// {
//     isPrime[0] = false;
//     isPrime[1] = false;
//     isPrime[2]=true;
//     // pr.push_back(2);
//     for (ll i = 4; i < N; i += 2)
//     {
//         isPrime[i] = false;
//     }

//     for (ll i = 3; i < N; i += 2)
//     {
//         if (isPrime[i])
//         {
//             // pr.push_back(i);
//             for (ll j = 3; i * j < N; j += 2)
//             {
//                 isPrime[i * j] = false;
//             }
//         }
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     primes();
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         ll n, m;
//         cin >> n >> m;
//         for (int i = n; i <= m; i++)
//         {
//             if (isPrime[i])
//                 cout << i << "\n";
//         }
//         cout << "\n";
//     }

//     return 0;
// }