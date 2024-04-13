#include "m.h"
using namespace std;

int n, m;
long long ans = 0;

void dfs(int d, int sum)
{
    if(sum < 0 || d > n)
    {
        return ;
    }
    if(d == n && sum == 0)
    {
        ans += 1;
        return ;
    }
    for(int i = 0;i < 10;i++)
    {
        dfs(d + 1, sum - i);
    }
}

void func()
{
    long long res = 0;
    int depth = 1;
    for(int i = 1;i <= 9 && i <= m;i++)
    {
        ans = 0;
        dfs(depth, m - i);
        res += ans % 998244353;
    }
    res %= 998244353;
    cout << res << endl;
}

int main()
{
  // 请在此输入您的代码
  cin >> n >> m;
  func();
  getchar();
  return 0;
}