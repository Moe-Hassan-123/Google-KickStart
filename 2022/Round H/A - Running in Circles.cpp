#include<bits/stdc++.h>

long long solve()
{
    long long lap, n;
    std::cin >> lap >> n;
    long long cur = 0, ans = 0,v;
    char dir;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v >> dir;
        if (dir != 'C')
        {
            v = 0 - v;
        }
        cur += v;

        long long diff = abs(cur / lap);
        if (cur > 0)
            cur -= diff*lap;
        else
            cur += diff*lap;
        ans += diff;
    }
    return ans;
}

int main()
{
    int t = 1;
    std::cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        std::cout << "Case #" << tc << ": " ;
        std::cout << solve();
        std::cout << "\n";
    }
}
