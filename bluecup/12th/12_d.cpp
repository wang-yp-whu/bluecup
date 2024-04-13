#include "m.h"

int route[2022][2022] = {0};
// long long ans = 0x7fffffffffffffff;
// int target = 2021;

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

// void dfs(int x, long long sum)
// {
//     if(sum >= ans)
//     {
//         return ;
//     }
//     if(x == target)
//     {
//         if(sum < ans)
//         {
//             ans = sum;
//         }
//         return ;
//     }
//     for(int i = x + 1;i <= target && i <= x + 21;i++)
//     {
//         dfs(i, sum + route[x][i]);
//     }
// }

int main()
{
    memset(route, 0, sizeof(route));
    for(int i = 1; i <= 2021;i++)
    {
        for(int j = i + 1;j <= i + 21 && j <= 2021;j++)
        {
            route[i][j] = i * j / gcd(i, j);
        }
    }
    //dfs(1, 0);
    // use dp is the best choice
    int dp[2022] = {0};
    for(int i = 1;i <= 2021;i++)
    {
        for(int j = i + 1;j <= i + 21 && j <= 2021;j++)
        {
            if(!dp[j])
            {
                dp[j] = dp[i] + route[i][j];
            }
            else
            {
                dp[j] = min(dp[j], dp[i] + route[i][j]);
            }
        }
    }
    cout << dp[2021] << endl;
    system("pause");
    return 0;
}