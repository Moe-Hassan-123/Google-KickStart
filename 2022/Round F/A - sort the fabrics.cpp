#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x)  ((int) (x).size())

#define PB push_back
#define F first
#define S second

#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<pair<string, int>> names (n);
    vector<pair<int, int>> durability (n);
    string s;
    int dur, id;
    for (int i = 0; i < n; ++i)
    {
        cin >> s >> dur >> id;
        names[i] = {s, id};
        durability[i] = {dur, id};
    }
    sort(all(names));
    sort(all(durability));
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (names[i].S == durability[i].S)
            ans++;
    }
    cout << ans;
}


int main()
{
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
        cout << "\n";
    }
}
