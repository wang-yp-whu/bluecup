#include "m.h"

int m = 1 << 21;
int n = 21;
long long ans = 0;
int r[22][22] = {0};
int vis[22] = {0};

int gcd(int x, int y)//big number in the latter
{
    if(x > y)
    {
        return gcd(y, x);
    }
    if(x == 0)
    {
        return y;
    }
    else
    {
        int b = y % x;
        return gcd(b, x);
    }
}

int main()
{
    for(int i = 1;i < 21;i++)
    {
        for(int j = i + 1;j <= 21;j++)
        {
            if(gcd(i, j) == 1)
            {
                r[i][j] = r[j][i] = 1;
            }
        }
    }
    vector<long long> t = vector<long long> (21, 0);
    vector<vector<long long>> dp = vector<vector<long long>> (1 << 21, t);
    dp[1][0] = 1;
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(i >> j & 1)
            {
                for(int k = 0;k < n;k++)
                {
                    if((i - (1 << j)) >> k & 1 && r[k + 1][j + 1])
                    {
                        dp[i][j] += dp[i- (1 << j)][k];
                    }
                }
            }
        }
    }
    for(int i = 1;i < 21;i++)
    {
        ans += dp[m - 1][i];
    }
    cout << ans << endl;
    system("pause");
    return 0;
}