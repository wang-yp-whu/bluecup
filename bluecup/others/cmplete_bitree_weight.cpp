#include "m.h"
using namespace std;

int n = 0, hh = 0;
int a[100001] = {0};
long long num = -100000000000;
long long sum = 0;

int main()
{
  // 请在此输入您的代码
  cin >> n;
  for(int i = 1;i <= n;i++)
  {
      cin >> a[i];
  }
  int d = 1, dd = 2, h = 1;
  while(d <= n)
  {
      sum = -1000000000000;
      for(int i = d;i < dd && i <= n;i++)
      {
            if(sum == -1000000000000)
            {
                sum = 0;
            }
          sum += a[i];
      }
      if(sum > num)
      {
          num = sum;
          hh = h;
      }
      h++;
      d = dd;
      dd *= 2;
  }
  cout << hh << endl; 
  return 0;
}