#include "m.h"

const int N = 10;
int g[N][N];
int p[N];
bool st[N];
int n,m,res;

void add(int a,int b)
{
    g[a][b]=g[b][a]=1;
}

int find(int x)
{
    if(p[x]!=x) return p[x]=find(p[x]);
    return p[x];
}

bool check()
{
    for(int i=1;i<=7;i++)
        p[i]=i;

    for(int i=1;i<=7;i++)
        for(int j=1;j<=7;j++)
    {
        if(st[i] && st[j] && g[i][j])
            p[find(j)]=find(i);
    }

    int cnt=0;
    for(int i=1;i<=7;i++)
        if(st[i] && p[i]==i)
        cnt++;

    return cnt==1;
}

void dfs(int u)
{
    if(u>=8)
    {
        if(check())
            res++;
        return ;
    }

    st[u]=true;
    dfs(u+1);

    st[u]=false;
    dfs(u+1);
}

int main()
{
    add(1,2); add(1,6);
    add(2,3); add(2,7);
    add(3,4); add(3,7);
    add(4,5); add(5,6); add(5,7);
    add(6,7); add(6,1);

    dfs(1);

    cout << res << endl;

    return 0;
}