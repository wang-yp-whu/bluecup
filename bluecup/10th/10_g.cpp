#include "m.h"
using namespace std;

int n, m, t;
int p[100001] = {0};
set<int> priority;
vector<vector<int>> time_table;
int hashh[100001] = {0};

void check()
{
    for(int i = 1;i <= t;i++)
    {
        memset(hashh, 0, sizeof(hashh));
        int len = time_table[i].size();
        for(int j = 0;j < len;j++)
        {
            hashh[time_table[i][j]] = 1;
            p[time_table[i][j]] += 2;
            if(p[time_table[i][j]] > 5)
            {
                priority.insert(time_table[i][j]);
            }
        }
        for(int k = 1;k <= n;k++)
        {
            if(!hashh[k])
            {
                if(p[k] > 0)
                {
                    p[k]--;
                }
                if(priority.count(k) && p[k] < 4)
                {
                    priority.erase(k);
                }
            }
        }
    }
}

int main()
{
  // 请在此输入您的代码
  cin >> n >> m >> t;
  vector<int> tmp;
  for(int i = 0;i <= t;i++)
  {
      time_table.push_back(tmp);
  }
  int ts = 0, id = 0;
  for(int i = 0;i < m;i++)
  {
      cin >> ts >> id;
      time_table[ts].push_back(id);
  }
  check();
  cout << priority.size() << endl;
  system("pause");
  return 0;
}