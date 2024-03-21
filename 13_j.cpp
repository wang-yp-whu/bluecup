#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;

long long n, m, q;
long long int dp[10001][10001] = {0};
vector<string> ans;
vector<int> lt;
vector<int> rt;

void DP()
{
    int len = lt.size();
    for(int i = 0;i < len - 1;i++)
    {
        for(int j = i + 1;j < len;j++)
        {
            if(rt[i] + 1 == lt[j])
            {
                dp[lt[i]][rt[j]] = dp[lt[i]][rt[i]] + dp[lt[j]][rt[j]];
                lt.push_back(lt[i]);
                rt.push_back(rt[j]);
            }
            else if(rt[i] == rt[j])
            {
                if(lt[i] < lt[j])
                {
                    dp[lt[i]][lt[j] - 1] = dp[lt[i]][rt[i]] - dp[lt[j]][rt[j]];
                    lt.push_back(lt[i]);
                    rt.push_back(lt[j] - 1);
                }
                else
                {
                    dp[lt[j]][lt[i] - 1] = dp[lt[j]][rt[j]] - dp[lt[i]][rt[i]];
                    lt.push_back(lt[j]);
                    rt.push_back(lt[i] - 1);
                }
            }
            else if(lt[i] == lt[j])
            {
                if(rt[i] > rt[j])
                {
                    dp[rt[j] + 1][rt[i]] = dp[lt[i]][rt[j]] - dp[lt[j]][rt[j]];
                    lt.push_back(rt[j] + 1);
                    rt.push_back(rt[i]);
                }
                else
                {
                    dp[rt[i] + 1][rt[i]] = -dp[lt[i]][rt[j]] + dp[lt[j]][rt[j]];
                    lt.push_back(rt[i] + 1);
                    rt.push_back(rt[j]);
                }
            }
        }
    }
}

void check(int x, int y)
{
    if(dp[x][y] != -1)
    {
        ans.push_back(to_string(dp[x][y]));
    }
    else
    {
        ans.push_back("UNKNOWN");
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> q;
    for(int i = 0;i < m;i++)
    {
        int l, r, s;
        cin >> l >> r >> s;
        lt.push_back(l);
        rt.push_back(r);
        dp[l][r] = s;
    }
    DP();
    for(int i = 0;i < q;i++)
    {
        int x, y;
        cin >> x >> y;
        check(x, y);
    }
    for(int i = 0;i < ans.size();i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}