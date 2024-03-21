#include <iostream>
using namespace std;

int f[12][12];//下标从1开始
char d[12][12];
int n,m;

//检查填0/1时是否符合条件,当填完[x,y]时，[x-1,y-1]已经不受影响，若是最后一列，则[x-1,y]也不受影响
bool check(int x,int y)
{
  if(d[x][y]=='_') 
    return true;
  int cnt=0;
  for(int i=-1;i<=1;i++)
  {
    for(int j=-1;j<=1;j++)
    {
      cnt+=f[x+i][y+j];
    }
  }
  if(cnt==d[x][y]-'0')
    return true;
  return false;
}

//深搜试探，从左往右，从上往下
void dfs(int x,int y)
{
  if(x==n+1)
  {//全部摆放好了，检查是否符合最后一行
    for(int y=1;y<=m;y++)
    {
      if(!check(n,y))
        return;
    }
    //找到答案，直接输出，结束
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        cout<<f[i][j];
      }
      cout<<endl;
    }
    return;
  }

  if(y==m)
  {//到了最后一列，准备换行
    f[x][y]=0;
    if(x==1 || (y==1 && check(x-1,y)) || (check(x-1,y-1) && check(x-1,y)))
    {
      dfs(x+1,1);//换行
    }

    f[x][y]=1;//0不可行，回溯，试1
    if(x==1 || (y==1 && check(x-1,y)) || (check(x-1,y-1) && check(x-1,y)))
    {
      dfs(x+1,1);//换行
    }
  }
  else
  {//没到换行，遍历下一列
    f[x][y]=0;
    if(x==1 || y==1 ||(check(x-1,y-1)))
      dfs(x,y+1);
    
    f[x][y]=1;
    if(x==1 || y==1 || check(x-1,y-1))
      dfs(x,y+1);
  }
}

int main()
{
  // 请在此输入您的代码
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>d[i][j];
    }
  }
  dfs(1,1);
  system("pause");
  return 0;
}