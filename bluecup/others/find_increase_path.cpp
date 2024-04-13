#include "m.h"
using namespace std;

int n, m;
int res = 0, minn = 0;
vector<vector<int>> g;
int vis[205][205] = {0};
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

bool islegal(int x, int y)
{
    if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y])
    {
        return true;
    }
    return false;
}

void dfs(int x, int y, int step)
{
    int f = 0;
    vis[x][y] = 1;
    for(int i = 0;i < 4;i++)
    {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(islegal(nx, ny) && g[nx][ny] > g[x][y])
        {
            f = 1;
            dfs(nx, ny, step + 1);
            vis[nx][ny] = 0;
        }
    }
    if(!f)
    {
        if(step > res)
        {
            res = step;
        }
        return ;
    }
}

int main()
{
  // 请在此输入您的代码
  cin >> n >> m;
  vector<int> t = vector<int> (m, 0);
  for(int i = 0;i < n;i++)
  {
      g.push_back(t);
  }
  for(int i = 0;i < n;i++)
  {
      for(int j = 0;j < m;j++)
      {
          cin >> g[i][j];
      }
  }
  for(int i = 0;i < n;i++)
  {
      for(int j = 0;j < n;j++)
      {
          memset(vis, 0, sizeof(vis));
          dfs(i, j, 1);
      }
  }
  cout << res << endl;
  return 0;
}