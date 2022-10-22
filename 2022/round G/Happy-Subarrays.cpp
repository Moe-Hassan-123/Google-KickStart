#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x)  ((dl) (x).size())

#define PB push_back
#define F first
#define S second

#define dl long double

void solve()
{
    int n;
    cin >> n;
    vector<int> vc (n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vc[i];
    }
    int ans = 0;
    for (int i = 0;i < n; ++i)
    {
        int prefix = 0;
        if (vc[i]<0)continue;
        for (int j = i; j < n; ++j)
        {
            prefix += vc[j];
            if (prefix < 0)break; 
            ans += prefix;
        }
    }
    cout << ans;
}


int32_t main()
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
