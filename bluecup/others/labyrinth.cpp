#include "m.h"
using namespace std;

int dir[4][2] = {1, 0, 0, -1, 0, 1, -1, 0};
char direction[4] = {'D', 'L', 'R', 'U'};
char t[30][50];
int vis[30][50] = {0};
int ans = 0x7fffff;
vector<string> res;
string r;

bool islegal(int x, int y)
{
    if(x >= 0 && x < 30 && y >= 0 && y < 50 && t[x][y] != '1' && !vis[x][y])
    {
        return true;
    }
    return false;
}

void dfs(int x, int y, int step, string r)
{
    vis[x][y] = 1;
    if(x == 29 && y == 49)
    {
        if(step <= ans)
        {
            ans = step;
            res.push_back(r);
        }
        return ;
    }
    if(step > 190)
    {
        return ;
    }
    for(int i = 0;i < 4;i++)
    {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(islegal(nx, ny))
        {
            dfs(nx, ny, step + 1, r + direction[i]);
            vis[nx][ny] = 0;
        }
    }
}

int main()
{
  // 请在此输入您的代码
  
  for(int i = 0;i < 30;i++)
  {
      for(int j = 0;j < 50;j++)
      {
          cin >> t[i][j];
      }
  }
  dfs(0, 0, 0, r);
  cout << res[res.size() - 1] << endl;
  string str1 = res[0];
  string str2 = "DDDDRRURRRRRRDRRRRDDDLDDRDDDDDDDDDDDDRDDRRRURRUURRDDDDRDRRRRRRDRRURRDDDRRRRUURUUUUUUULULLUUUURRRRUULLLUUUULLUUULUURRURRURURRRDDRRRRRDDRRDDLLLDDRRDDRDDLDDDLLDDLLLDLDDDLDDRRRRRRRRRDDDDDDRR";
  int len1 = str1.size(), len2 = str2.size();
  cout << len1 << endl << len2 << endl;
  if(str1.compare(str2) == 0)
  {
	cout << "yes" << endl;
  }
  else
  {
	cout << "not" << endl;
  }
  return 0;
}