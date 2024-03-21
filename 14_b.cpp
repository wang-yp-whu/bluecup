#include "m.h"

//错了，因为不可以在100分之后还答题，没有考虑这一点
/*
f[0][0]=1;
  for(int i=0;i<30;i++)
  {
    for(int j=0;j<=9;j++)
    {
      //true 
      f[i+1][j+1]+=f[i][j];
      //false
      f[i+1][0]+=f[i][j];
      //give up
      if(j==7)res+=f[i][7];
    }
  }
  cout<<res+f[30][7];
*/
int main()
{
    //vector<int> q = vector<int> (31, 0);
    // we assume it that in the Ith question he dropped and scored 70
    //对于q[i],必须保证dp[i - 6]---q[i]全部回答正确，并且q[i - 7]回答错误，其余无论
    //pow(2,0)
    long long cnt = 1;
    for(int i = 8;i <= 30;i++)
    {
        int d = 1;
        for(int j = 1; j <= i - 8;j++)
        {
            d *= 2;
        }
        cnt += d;
    }
    cout << cnt << endl;
    //8388608
    system("pause");
    return 0;
}