#include <bits/stdc++.h>
using namespace std;
int get(int x, vector<int> &dp, vector<int> &v)
{
    if (x < 0)
        return 0;
    if (x == 0)
        return 1;

    if (dp[x] != -1)
        return dp[x];

    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans = (ans + get(x - v[i], dp, v)) % (int)(1e9 + 7);
    }

    return dp[x] = ans;
}

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

// recursive ways
    // vector<int> dp(x + 1, -1);
    // get(x, dp, v);
    // cout << dp[x] << endl;

// iterative ways
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (auto coin : v)
        {
            if (coin > i)
                continue;

            dp[i] = (dp[i] + dp[i - coin]) % (int)(1e9 + 7);
        }
    }
    cout << dp[x] << endl;
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
    //dp[i] -- numbers of ways to get sum == i

//---transition ---//
    // dp[i] = dp[i-coin(1)]+ --- + dp[i-coin(nth)];

//--- final ans ---//
    //dp[n]
