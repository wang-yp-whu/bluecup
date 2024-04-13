#include "m.h"
using namespace std;

int n = 0, cnt = 0;
vector<int> a;
vector<int> b;
int use[200000] = {0};

void func(int x)
{
    for(int i = n - 1;i >= 0;i--)
    {
        if(use[i] == 0 && 2 * a[x] > b[i])
        {
            use[i] = 1;
            cnt++;
            break;
        }
    }
}

int main()
{
  // 请在此输入您的代码
  cin >> n;
  int x, y;
  for(int i = 0;i < n;i++)
  {
      cin >> x;
      a.push_back(x);
  }
  for(int i = 0;i < n;i++)
  {
      cin >> y;
      b.push_back(y);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for(int i = 0;i < n;i++)
  {
      func(i);
  }
  cout << cnt << endl;
  return 0;
}