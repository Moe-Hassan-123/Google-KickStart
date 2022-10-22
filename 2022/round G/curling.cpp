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
    int rs, rh, n;
    dl x, y;
    cin >> rs >> rh;

    cin >> n;
    vector<pair<dl, bool>> balls;
    for (dl i = 0; i < n; ++i)
    {
        cin >> x >> y;
        dl dist = sqrtl((x*x) + (y*y));
        if ((dist - rs) > rh)
            continue;
        balls.push_back({dist, 1});
    }

    dl m;
    cin >> m;
    for (dl i = 0; i < m; ++i)
    {
        cin >> x >> y;
        dl dist = sqrtl((x*x) + (y*y));
        if (dist - rs > rh)
            continue;
        balls.push_back({dist, 0});
    }

    sort(all(balls));
    int ans = 0;
    bool st;

    for (dl i = 0; i < sz(balls); ++i)
    {
        if (i == 0)
            st = balls[i].S;

        if (st != balls[i].S)
            break;
        ans++;
    }

    if (st)
    {
        cout << ans << " " << 0;
    }
    else
    {
        cout << 0 << " " <<  ans;
    }
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
