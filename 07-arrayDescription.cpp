#include<vector>
#include<iostream>
using namespace std;

bool valid(int a, int m)
{
    return (a >= 0 && a <= m);
}

void solve()
{
    int M = 1e9 + 7;
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        if (arr[0] == 0 || arr[0] == i)
            dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i - 1] != 0 && arr[i - 1] != j)
            {
                dp[i][j] = 0;
                continue;
            }

            for (int prev = j - 1; prev <= j + 1; prev++)
            {
                if (!valid(prev, m))
                    continue;
                dp[i][j] = (dp[i][j] + dp[i - 1][prev]) % M;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= m; i++)
    {
        ans = (ans + dp[n][i]) % M;
    }

    cout << ans << endl;
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

//---state
  //dp[i][j] = number of ways to fill prefix till [0 .. i]
  // such that the number is j

//---transition
  //when the current arr[i] is zero of zrr[i] == j
  // dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i+1][j]; 
  
  //else dp[i][j] = 0;

//---base case
  //if(arr[0]==0) all dp[1][something] = 1;
  // else dp[1][arr[0]] = 1;

//---final subproblem
  //sum of all the last index of dp
