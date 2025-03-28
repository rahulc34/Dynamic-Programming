#include <vector>
#include <iostream>
using namespace std;
vector<int> getPrime(int n)
{
    vector<int> vis(n + 1, 0);
    vector<int> prime;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            prime.push_back(i);
            for (int j = 1; j * i <= n; j++)
            {
                vis[j * i] = 1;
            }
        }
    }
    return prime;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> prime = getPrime(n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((long long)prime[0] * i > n)
            break;

        int l = 0, r = prime.size()-1, ind = 0;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if ((long long)prime[m] * i <= n)
            {
                l = m + 1;
                ind = m;
            }
            else
                r = m - 1;
        }
        ans += ind + 1;
    }

    cout << ans << endl;
    return;
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