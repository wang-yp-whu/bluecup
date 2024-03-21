#include "m.h"

int n, k;
vector<int> a;
vector<int> dp;

int main()
{
  // 请在此输入您的代码
  cin >> n >> k;
  a.resize(n + 1);
  dp.resize(n + 1);
  for(int i = 1;i <= n;i++)
  {
      cin >> a[i];
  }
  dp[0] = 0;
  dp[1] = 1;
  for(int i = 2;i <= n;i++)
  {
      if(a[i] >= a[i - 1])
      {
          dp[i] = dp[i - 1] + 1;
      }
      else
      {
          dp[i] = 1;
      }
  }
  int cnt = 0, ans = -1;
  for(int i = 1;i <= n - k;i++)
  {
      int j = i + k;
      cnt = dp[i] + k;
      while(j < n && a[j + 1] >= a[i] && dp[j + 1] > 1)
      {
          cnt++;
          j++;
      }
      if(cnt > ans)
      {
          ans = cnt;
      }
  }
  cout << ans << endl;
  system("pause");
  return 0;
}