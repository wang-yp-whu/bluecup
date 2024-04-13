#include "m.h"
using namespace std;

int n;
int d[50];
set<int> gr;

int main()
{
  // 请在此输入您的代码
  cin >> n;
  int minn = 10000, maxx = 0;
  for(int i = 0;i < n;i++)
  {
      cin >> d[i];
  }
  for(int i = 0;i < n - 1;i++)
  {
      for(int j = i + 1;j < n;j++)
      {
          int mul = d[i] * d[j];
          if(mul > maxx)
          {
              maxx = mul;
          }
          if(mul < minn)
          {
              minn = mul;
          }
          gr.insert(mul);
      }
  }
  int dif = gr.size();
  cout << minn;
  cout << ' ';
  cout << maxx;
  cout << ' ';
  cout << dif << endl;
  return 0;
}