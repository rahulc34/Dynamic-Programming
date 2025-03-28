#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int j, vector<vector<int>> &dp)
{
    int n = dp.size();
    if (i >= n || j >= n)
        return 0;
    if (i == n - 1 && j == n - 1)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = (dfs(i + 1, j, dp) + dfs(i, j + 1, dp)) % (int)(1e9 + 7);
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    // //-----recursive ways of solution
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            grid[i][j] = c;
            if (c == '*')
                dp[i][j] = 0;
        }
    }

    // if (dp[n - 1][n - 1] == 0 || dp[0][0] == 0)
    // {
    //     cout << 0 << endl;
    //     return;
    // }
    // else
    //     dp[n - 1][n - 1] = 1;
    // dfs(0, 0, dp);
    // cout << dp[0][0] << endl;

    //-----iterative ways of solution
    vector<vector<int>> dp2(n, vector<int>(n));
    if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*')
    {
        cout << 0 << endl;
        return;
    }
    else
        dp2[n - 1][n - 1] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == n - 1)
                continue;
            if (grid[i][j] == '*')
                dp2[i][j] = 0;
            else
            {
                int down = i < n - 1 ? dp2[i + 1][j] : 0;
                int right = j < n - 1 ? dp2[i][j + 1] : 0;
                dp2[i][j] = (right + down) % (int)(1e9 + 7);
            }
        }
    }

    cout<<dp2[0][0]<<endl;
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