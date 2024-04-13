#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<int> h;
int n;
int a[100001] = {0};

int main()
{
  // 请在此输入您的代码
  cin >> n;
  for(int i = 1;i <= n;i++)
  {
      cin >> a[i];
  }
  for(int i = 1;i <= n;i++)
  {
      if(!h.count(a[i]))
      {
          h.insert(a[i]);
      }
      else
      {
          while(h.count(a[i]))
          {
              a[i]++;
          }
          h.insert(a[i]);
      }
  }
  for(int i = 1;i <= n;i++)
  {
      cout << a[i];
      cout << ' ';
  }
  cout << endl;
  return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int n;
    int a[100005]={0}, b[1000005] = { 0 };
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        while (b[a[i]] != 0)
        {
            b[a[i]]++;
            a[i]+=(b[a[i]]-1);
        }
        b[a[i]]++;
        cout << a[i] << ' ';
    }
    return 0;
}//for the first one is over-time;