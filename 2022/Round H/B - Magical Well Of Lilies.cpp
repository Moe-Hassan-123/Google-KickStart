#include<bits/stdc++.h>

std::map<int, int> memo;

int solve(int n)
{
    if (n <= 5)
        return n;
    if (memo.find(n) != memo.end())
        return memo[n];

    memo[n] = n;
    for (int i = 2 ; i < sqrt(n); ++i)
    {
        if (n % i == 0)
            memo[n] = std::min(memo[n], solve(n/i));
    }

    return memo[n];
}

int main()
{
    for (int j = 1; j <= 20; ++j)
    {
        memo[j] = j;
        for (int i = 5; i < j/2+1; ++i)
        {
            memo[j] = std::min(memo[j], (j%i) + ((j/i)-1)*2 + i + 4);
        }
    }
    
    int t = 1;
    std::cin >> t;   
    for (int tc = 1; tc <= t; ++tc)
    {
        std::cout << "Case #" << tc << ": ";
        int n;
        std::cin >> n;
        std::cout << solve(n);
        std::cout << "\n";
    }
}
