#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> prices(n), pages(n);

    for (int i = 0; i < n; i++)
        cin >> prices[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    //---- iterative dp solution
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            int page = pages[i - 1], price = prices[i - 1];

            int skip = dp[i - 1][j];
            int take = (j >= price ? dp[i - 1][j - price] + page : 0);

            dp[i][j] = max(take, skip);
        }
    }
    cout << dp[n][x] << endl;

    // // space optimization
    // vector<int> prev(x + 1, 0);
    // for (int i = 1; i <= n; i++)
    // {
    //     vector<int> curr(x + 1, 0);
    //     for (int j = 1; j <= x; j++)
    //     {
    //         int page = pages[i - 1], price = prices[i - 1];

    //         int skip = prev[j];
    //         int take = (j >= price ? prev[j - price] + page : 0);

    //         curr[j] = max(take, skip);
    //     }
    //     prev = curr;
    // }
    // cout << prev[x] << endl;
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
// dp[i][j] -- max no. of pages possibel with total price
//<= j and using books only from 0 to i-1
// (i.e using the first i books)
// here we taraverse in reverse order

//---transition ---//
// dp[i][j] = min(dp[i-1][j], dp[i-1][j-prices[i-1]] + pages[i-1]);

//--- final ans ---//
// dp[n][x]
