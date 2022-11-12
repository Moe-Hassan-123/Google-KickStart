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
    int m, n, j;
    cin >> m >> n >> j;
    vector<int> john (n);
    vector<int> best (n);
    for (int i = 0; i < m; ++i)
    {
        if (i == (j-1))
        {
            for (int z = 0;z < n; ++z)
            {
                cin >> john[z];
            }
            continue;
        }
        int v;
        for (int i = 0;i < n; ++i)
        {
            cin >> v;
            if (best[i] < v)
                best[i] = v;            
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans+=max(0, best[i]-john[i]);
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
