#include <bits/stdc++.h>
using namespace std;
int M = 1e9 + 7;

int get(int n, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];

    dp[n] = 0;
    for (int i = 1; i <= 6; i++)
    {
        dp[n] = (dp[n] + get(n - i, dp)) % M;
    }

    return dp[n];
}
void solve()
{
    int n;
    cin >> n;

// // recursive solve
    // vector<int> dp(n + 1, -1);
    // get(n, dp);
    // cout<<dp[n];

// iterative solve
    vector<int>dp(n+1,0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (j > i)
                break;
            dp[i] = (dp[i] + dp[i - j]) % M;
        }
    }
    cout << dp[n];
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
    //dp[i] -- number of ways to get sum == i

//---transition ---//
    // dp[i] = dp[i-1]+ --- + dp[i-6];

//--- final ans ---//
    //dp[n]
