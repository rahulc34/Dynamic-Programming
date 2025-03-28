#include <bits/stdc++.h>
using namespace std;
int dfs(int num, vector<int> &dp)
{
    if (dp[num] != -1)
        return dp[num];

    string digits = to_string(num);

    int ans = INT_MAX;
    for (auto &digit : digits)
    {
        if (digit == '0')
            continue;
        ans = min(ans, dfs((num - (digit - '0')), dp) + 1);
    }

    return dp[num] = ans == INT_MAX ? 0 : ans;
}

void solve()
{
    int n;
    cin >> n;

    //---recursive ways
    // vector<int> dp(n + 1, -1);
    // dp[0] = 0;
    // dfs(n, dp);
    // cout << dp[n] << endl;

    //---iterative way
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        string s = to_string(i);
        for (auto digit : s)
        {
            if (digit == '0')
                continue;
            dp[i] = min(dp[i], dp[i - (digit - '0')] + 1);
        }
    }

    cout << dp[n] << endl;
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
    //dp[i] -- minimum numbers of ways to get sum == i

//---transition ---//
    // dp[i] = dp[i-digit(first of i)]+ --- + dp[i-digit(last of i)];

//--- final ans ---//
    //dp[n]

