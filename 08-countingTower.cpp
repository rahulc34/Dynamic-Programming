#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> dp(1e6 + 1, vector<int>(2));
void solve()
{
    int MOD = (int)(1e9 + 7);
    int n;
    cin >> n;

    // dp[n][0] = 1;
    // dp[n][1] = 1;
    // for (int i = n - 1; i > 0; i--)
    // {
    //     dp[i][0] = (2LL * dp[i + 1][0] + dp[i + 1][1]) % MOD;
    //     dp[i][1] = (4LL * dp[i + 1][1] + dp[i + 1][0]) % MOD;
    // }
    // cout << (dp[1][0] + dp[1][1]) % MOD << endl;

    //---space optimization
    int a = 1, b = 1;
    for (int i = n - 1; i > 0; i--)
    {
        int x = (2LL * a + b) % MOD;
        int y = (4LL * b + a) % MOD;
        a = x, b = y;
    }

    cout << (a + b) % MOD << endl;
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
    cin >> tt;
    while (tt--)
    {
        solve();
    }
}