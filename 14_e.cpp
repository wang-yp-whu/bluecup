#include "m.h"

int cnt = 0;
int c[200001] = {0};    int f[200001] = {0};
int visited[200001] = {0};

void buildtree(int n, vector<vector<int>> &child)
{
    for(int i = 1;i <= n;i++)
    {
        if(f[i])
        {
            child[f[i]].push_back(i);
        }
    }
}

void dfs(vector<vector<int>> &child, int x,int color[])//表示从X开始深度优先遍历
{
    visited[x] = 1;
    color[c[x]] += 1; 
    for(int i = 0;i < child[x].size();i++)
    {
        if(!visited[child[x][i]])
        {
            dfs(child, child[x][i], color);
        }
    }
    return ;
}

int main()
{
    int color[200001] = {0};
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> c[i] >> f[i];
    }
    vector<int> t;
    vector<vector<int>> child = vector<vector<int>> (n + 1, t);
    buildtree(n, child);
    for(int i = 1;i <= n;i++)
    {
        memset(visited, 0, sizeof(visited));
        memset(color, 0, sizeof(color));
        dfs(child, i, color);
        int flag = 0;
        for(int j = 1;j <= n;j++)
        {
            if(color[j] != 0 && flag == 0)
            {
                flag = color[j];
            }
            if(color[j] != 0 && color[j] != flag)
            {
                flag = 0;
                break;
            }
        }
        if(flag != 0)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    system("pause");
    return 0;
}