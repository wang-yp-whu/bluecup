#include "m.h"
using namespace std;
#define maxx 10000000000

int n, m;
vector<vector<int>> limit;
// int matrix[10001][10001] = {0};
int x, y, c, d = 0;
long long min1 = 0x7fffffff, min2 = 0x7fffffff; 

void dijkstra(int id, vector<vector<int>>& matrix)
{
    vector<long long> dp = vector<long long> (n + 1, maxx);
    vector<int> a;
    set<int> b;
    a.push_back(1);
    for(int i = 2;i <= n;i++)
    {
        if(matrix[1][i] != 0)
        {
            dp[i] = matrix[1][i];
        }
        b.insert(i);
    }
    int cnt = 0;
    while(b.size() > 0)
    {
        int len = a.size();
        int minn = 100000, idx = 0;
        for(int i = 0;i < len;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                if(b.count(j))
                {
                    if(matrix[a[i]][j] > 0 && dp[j] == maxx)
                    {
                        dp[j] = dp[a[i]] + matrix[a[i]][j];
                    }
                    if(matrix[a[i]][j] > 0 && dp[j] != maxx)
                    {
                        if(dp[j] > dp[a[i]] + matrix[a[i]][j])
                        {
                            dp[j] = dp[a[i]] + matrix[a[i]][j];
                        }
                    }
                    if(dp[j] < minn)
                    {
                        idx = j;
                        minn = dp[j];
                    }
                }
            }
        }
        b.erase(idx);
        a.push_back(idx);
    }
    if(id == 1)
    {
        min1 = dp[n];
    }
    else
    {
        min2 = dp[n];
    }
}

int main()
{
  // 请在此输入您的代码
  cin >> n >> m;
  vector<int> tmp = vector<int> (n + 1, 0);
  vector<vector<int>> matrix = vector<vector<int>> (n + 1, tmp);
  for(int i = 0;i < m;i++)
  {
      d = 0;
      cin >> x >> y >> c >> d;
      if(matrix[x][y] == 0 && d == 0)
      {
        matrix[x][y] = matrix[y][x] = c;
      }
      if(matrix[x][y] > 0 && matrix[x][y] > c && d == 0)
      {
        matrix[x][y] = matrix[y][x] = c;
      }
      if(d)
      {
          vector<int> t;
          t.push_back(x);
          t.push_back(y);
          t.push_back(c);
          limit.push_back(t);
      }
  }
  dijkstra(1, matrix);
  int k = limit.size();
  for(int i = 0;i < k;i++)
  {
      if(limit[i][2] < matrix[limit[i][0]][limit[i][1]] || matrix[limit[i][0]][limit[i][1]] == 0)
      {  
        matrix[limit[i][0]][limit[i][1]] = matrix[limit[i][1]][limit[i][0]] = limit[i][2];
      }
  }
  dijkstra(2, matrix);
  cout << min1 << endl << min2 << endl;
  cout << min1 - min2 << endl;
  system("pause");
  return 0;
}