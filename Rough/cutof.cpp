#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)

class stu
{
public:
    unsigned long long f;
    unsigned long long all;
    unsigned long long id;
    stu()
    {
    }
    stu(unsigned long long f, unsigned long long all, unsigned long long id)
    {
        this->f = f;
        this->all = all;
        this->id = id;
    }
};

bool comp_f(stu s1, stu s2)
{
    if (s1.f > s2.f)
        return s1.f > s2.f;
    else if (s1.all > s2.all)
        return s1.all > s2.all;
    else
        return s1.id > s2.id;
}

vector<stu> engineeringCutoff(ll n, vector<vector<ll>> &marks)
{
    vector<stu> data;
    ll s = 0;
    for (auto arr : marks)
    {
        if (arr[1] < 35 || arr[2] < 35 || arr[3] < 35 || arr[4] < 35 || arr[5] < 35)
            continue;
        ll f_sum = arr[1] + arr[2] + arr[3];
        ll all = f_sum + arr[4] + arr[5];
        ll id = arr[0];
        data.resize(s);
        s++;
        data.emplace_back(stu(f_sum, all, id));
    }
    sort(data.begin(), data.end(), comp_f);
    return data;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll n;
    cin >> n;
    vector<vector<unsigned long long>> marks(n);
    vector<stu> arr;
    unsigned long long id;
    unsigned long long s0, s1, s2, s3, s4;
    unsigned long long s = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> id >> s0 >> s1 >> s2 >> s3 >> s4;
        marks[i] = {id, s0, s1, s2, s3, s4};
        if (s0 < 35 || s1 < 35 || s3 < 35 || s4 < 35 || s2 < 35)
            continue;
        unsigned long long f_sum = s0 + s1 + s2;
        unsigned long long all = f_sum + s3 + s4;
        unsigned long long id_ = id;
        // arr.resize(s);
        // s++;
        stu stud = stu(f_sum, all, id_);
        // arr.insert(arr.begin() + i, stud);
        arr.push_back(stud);
        s++;
    }
    // vector<stu> ans = engineeringCutoff(n, marks);
    sort(arr.begin(), arr.end(), comp_f);
    vector<unsigned long long> data(s + 1);

    for (unsigned long long i = 0; i < arr.size(); i++)
    {
        // data.push_back(arr.at(i).id);
        data.insert(data.begin() + i, arr[i].id);
        // cout << arr.at(i).id << " ";
    }

    for (unsigned long long i = 0; i < s; i++)
    {
        // data.push_back(arr.at(i).id);
        cout << data.at(i) << " ";
    }

    cout << "\n";
}