#include<bits/stdc++.h>

std::vector<bool> visited;
std::unordered_map<int, int> memo;

int dfs(std::vector<std::pair<int, std::vector<int>>>& graph, int i)
{
    if (visited[i])
        return 0;
    if (memo.find(i) != memo.end())
        return memo[i];

    int ans = 1;
    visited[i] = 1;
    for (int& next: graph[i].second)
    {
        if (graph[next].first < graph[i].first)
        {
            ans += dfs(graph, next);
        } 
    }

    memo[i] = ans;
    return ans;
}

int solve()
{
    int n;
    std::cin >> n;

    std::vector<std::pair<int, std::vector<int>>> graph (n+1);
    visited.resize(n+1);
    
    for (int i = 1; i <= n; ++i)
        std::cin >> graph[i].first;

    int u, v;
    for (int i = 0; i < n-1; ++i)
    {
        std::cin >> u >> v;
        graph[u].second.push_back(v);
        graph[v].second.push_back(u);
    }

    int ans = -1;
    for (int i = 1; i <= n; ++i)
    {
        dfs(graph, i);
        if (memo.size() == n)
            break;
        
        ans = std::max(ans, memo[i]);
    }

    for (auto& [k, v]: memo)
        ans = std::max(ans, v);
    return ans;
}

int main()
{
    std::cin.tie(0);A
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);

    int t = 1;
    std::cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        std::cout << "Case #" << tc << ": ";
        std::cout << solve();
        std::cout << "\n";
        visited.clear();
        memo.clear();
    }
}
