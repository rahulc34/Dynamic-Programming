#include <bits/stdc++.h>
using namespace std;
int dfs(int x, vector<int> &dp, vector<int> &coins)
{
    if (x < 0)
        return INT_MAX;
    if (x == 0)
        return 0;

    if (dp[x] != -1)
        return dp[x];

    int ans = INT_MAX;
    for (auto coin : coins)
    {
        int val = dfs(x - coin, dp, coins);
        if (val == INT_MAX)
            continue;
        ans = min(ans, 1 + val);
    }

    return dp[x] = ans;
}

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

//--- using recursive dp ---//
    // vector<int> dp(x + 1, -1);
    // dfs(x, dp, v);
    // dp[x] == INT_MAX ? cout<<-1<<endl : cout<<dp[x]<<endl;

//--- using iterative dp ---//
    vector<int> dp(x + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (auto coin : v)
        {
            if (coin > i)
                continue;
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    cout << (dp[x] >= 1e9 ? -1 : dp[x]) << endl;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
}

//--- state ---//
    //dp[i] -- minimum coins required to make sum == i

//---transition ---//
    // dp[i] = dp[i-coin(1)]+ --- + dp[i-coin(nth)];

//--- final ans ---//
    //dp[n]
