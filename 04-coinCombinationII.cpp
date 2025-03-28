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
    //     vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    //     // dp[i][k] = number of ways to construct sum k
    //     for (int i = 0; i < n; i++)
    //     {
    //         dp[i][0] = 1;
    //     }
    //     for (int i = n - 1; i >= 0; i--)
    //     {
    //         for (int sum = 1; sum <= x; sum++)
    //         {
    //             int skipping = dp[i + 1][sum];
    //             int picking = 0;
    //             if (a[i] <= sum)
    //             {
    //                 picking = dp[i][sum - a[i]];
    //             }
    //             dp[i][sum] = (skipping + picking) % (int)(1e9 + 7);
    //         }
    //     }
    //     cout << dp[0][x] << endl;

//--- space optimization
    vector<int> nextState(x + 1, 0);
    nextState[0] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> currState(x + 1, 0);
        currState[0] = 1;
        for (int sum = 1; sum <= x; sum++)
        {
            int not_pick = nextState[sum];
            int pick = 0;
            if (a[i] <= sum)
                pick = currState[sum - a[i]];

            currState[sum] = (pick + not_pick)%(int)(1e9 + 7);
        }
        nextState = currState;
    }

    cout << nextState[x] << endl;
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
