// #include "m.h"

// long long ans = 0;
// set<long long> w;
// vector<long long> weight = vector<long long> (100, 0);
// vector<long long> sum = vector<long long> (100, 0);

// int main()
// {
//     int n = 0;
//     cin >> n;
//     for(int i = 1;i <= n;i++)
//     {
//         cin >> weight[i];
//     }
//     weight[0] = 0;
//     sum[0] = 0;
//     for(int i = 1;i <= n;i++)
//     {
//         sum[i] = weight[i] + sum[i - 1];
//     }
//     for(int i = 0;i < n;i++)
//     {
//         for(int j = i + 1;j <= n;j++)
//         {
//             w.insert(sum[j] - sum[i]);
//         }
//     }
//     ans = w.size();
//     cout << ans << endl;
//     system("pause");
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
ll a[200];
ll summ=0;
ll ans=0;
int dp[200][200000];
//dp[i][j]表示用到前i个砝码，能否称出j重量
//1为可以，0为不可以

int main()
{
  // 请在此输入您的代码
  cin>>N;
  for(int i=1;i<=N;i++)
  {
    cin>>a[i];
    summ+=a[i];
  }

  for(int i=1;i<=N;i++)
  {
    for(int j=1;j<=summ;j++)
    {//遍历所有可能的重量
      dp[i][j]=dp[i-1][j];//继承前一个状态
      if(dp[i][j]==0)
      {//如果普通继承下来，发现这个不行呢？
        if(j==a[i]) 
            dp[i][j]=1;//如果需要的重量正好就是第i个砝码，那么可以
        if(dp[i-1][j+a[i]]==1) 
            dp[i][j]=1;//如果前i-1个能搞出j+a[i]重量，那么把第i个砝码放到另一侧就行
        if(dp[i-1][abs(j-a[i])]==1) 
            dp[i][j]=1;//如果前i-1个砝码能搞出abs(j-a[i])重量
        //那么把第i个砝码放同侧就行
      }
    }
  }

  for(int j=1;j<=summ;j++)
  {
    if(dp[N][j]==1) ans++;//遍历，看dp[][]==1的个数，就是答案
  }
  cout<<ans<<endl;
  system("pause");
  return 0;
}//思路与此法相差甚多，不如之处还有很多