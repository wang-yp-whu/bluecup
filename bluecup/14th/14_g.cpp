#include "m.h"

int n = 0, m = 0, q = 0;
int weight = -1, dis = 0x7fffffff;
int ma[1000][1000] = {0};
int vis[1000] = {0};

void dfs(int x, int y)
{
    if(x == y)
    {
        if(dis > weight)
        {
            weight = dis;
        }
        return ;
    }
    for(int i = 1; i <= n;i++)
    {
        int d;
        if(ma[x][i] != 0 && !vis[i])
        {
            vis[i] = 1;
            if(ma[x][i] < dis)
            {
                d = dis;
                dis = ma[x][i];
            }
            dfs(i, y);
            vis[i] = 0;
            dis = d;
        }
    }
}

int main()
{
    cin >> n >> m >> q;
    vector<int> ans = vector<int> (q, 0);
    int u, v, w;
    for(int i = 0;i < m;i++)
    {
        cin >> u >> v >> w;
        ma[u][v] = w;
        ma[v][u] = w;
    }
    int x, y;
    for(int i = 0;i < q;i++)
    {
        cin >> x >> y;
        memset(vis, 0, sizeof(vis));
        vis[x] = 1;
        dfs(x, y);
        ans[i] = weight;
        //ans.push_back
        weight = -1;
        dis = 0x7fffffff;
    }
    for(int i = 0;i < q;i++)
    {
        cout << ans[i] << endl;
    }
    system("pause");
    return 0;
}