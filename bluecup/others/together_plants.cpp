#include "m.h"
using namespace std;

int n, m, k;
int vis[8][8] = {0};
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

bool islegal(int x, int y)
{
    if(x >= 1 && x <= m && y >= 1 && y <= n && vis[x][y] == 0)
    {
        return true;
    }
    return false;
}

void dfs(int x, int y, vector<set<int>> &matrix, int ans)
{
    int f = 0;
    vis[x][y] = ans;
    int mul1 = (x - 1) * n + y;
    for(int i = 0;i < 4;i++)
    {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        int mult = (nx - 1) * n + ny;
        if(islegal(nx, ny) && matrix[mul1].count(mult))
        {
            f = 1;
            dfs(nx, ny, matrix, ans);
        }
    }
    for(int i = 1;i <= m;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(vis[i][j] == 0)
            {
                dfs(i, j, matrix, ans + 1);
            }
        }
    }
}

int main()
{
  // 请在此输入您的代码
  cin >> m >> n;
  cin >> k;
  int a, b, ans = 1;
  set<int> t;
  vector<set<int>> matrix = vector<set<int>> (n * m + 1, t);
  for(int i = 0;i < k;i++)
  {
      cin >> a >> b;
      matrix[a].insert(b);
      matrix[b].insert(a);
  }
  dfs(1, 1, matrix, ans);
  for(int i = 1;i <= m;i++)
  {
    for(int j = 1;j <= n;j++)
    {
        if(vis[i][j] > ans)
        {
            ans = vis[i][j];
        }
    }
  }
  cout << ans << endl;
  return 0;
}

#include <iostream>
using namespace std;
const int N=1000010;
//记录父根
int p[N];
//查找加优化，不知道的可以先学一下这个算法
int find(int x){
  if(p[x]!=x)p[x]=find(p[x]);
  return p[x];
}
int main()
{
  int n,m,k;
  cin>>n>>m>>k;
//并查集初始化，所有植物自成一类
  for(int i=1;i<=n*m;i++){
    p[i] = i;
  }

  for(int i=0;i<k;i++){
    int a , b;
    scanf("%d%d",&a,&b);
    int pa = find(a), pb = find(b);
 //合并集合
    if(pa ! = pb)  p[pa] = pb; 
  }
  int res=0;
//当p[i]=i 说明他是父根，也说明他代表一种植物
  for(int i=1;i<=n*m;i++){
    if(p[i]==i) res++;
  }
  cout<<res<<endl;
  return 0;
}