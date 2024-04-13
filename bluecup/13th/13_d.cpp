#include "m.h"

long long int a[100001] = {0};
int n, m, x;
int l, r;
unordered_map<int, int> t;

void Xor(int left, int right, vector<string> &ans)
{
  int i = 0, f = 0;
  for(i = left; i < right;i++)
  {
    int k = a[i] ^ x;
    if(t[k] <= right && t[k] >= left && t[k] != i)
    {
      ans.push_back("yes");
      f = 1;
      //break;
      return ;
    }
  }
  if(!f)
  {
    for(int i = left;i < right;i++)
    {
        for(int j = i + 1;j <= right;j++)
        {
            if((a[i] ^ a[j]) == x)
            {
                f = 1;
                ans.push_back("yes");
                //break;
                return ;
            }
        }
        if(f)
        {
            break;
        }
    }
  }
    if(!f)
    {
        ans.push_back("no");
    }
}

int main()
{
  // 请在此输入您的代码
  cin >> n >> m >> x;
  vector<string> ans;
  for(int i = 1;i <= n;i++)
  {
    cin >> a[i];
    t[a[i]] = i;
  }
  for(int i = 0;i < m;i++)
  {
    cin >> l >> r;
    Xor(l, r, ans);
  }
  for(int i = 0;i < n;i++)
  {
    cout << ans[i] << endl;
  }
  system("pause");
  return 0;
}