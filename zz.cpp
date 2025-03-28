
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

// //----iterative without space optimization
        vector<vector<int>> dp(n + 1, vector<int>(x + 1,0));
        // dp[i][k] = number of ways to construct sum k
        for (int i = 0; i < n; i++)
        {
            dp[i][x] = 1;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int sum = x-1; sum >=0; sum--)
            {
                int skipping = dp[i + 1][sum];
                int picking = 0;
                if (a[i] + sum <= x)
                {
                    picking = dp[i][sum + a[i]];
                }
                dp[i][sum] = (skipping + picking) % (int)(1e9 + 7);
            }
        }
        cout << dp[0][0] << endl;
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
// dp[i][k] -- no. of ways to get sum of k such that all
// all point from ci to cn are pickable and all coin
// before ci are skipped

//---transition ---//
// dp[i][k] =
// 1) skip coin i  ---  dp[i+1][k]
// 2) take coin i  --- dp[i][k-ci]

//--- final ans ---//
// dp[0][k]
