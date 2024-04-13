#include "m.h"

int n, m;
int cnt = 0x7fffffff;
double a[31] = {0};

void dfs(double now, int step, int idx, double target)
{
    if(abs(now - target) < 0.1)
    {
        if(step < cnt)
        {
            cnt = step;
            return ;
        }
    }
    if(step > cnt || idx == n)
    {
        return ;
    }
    dfs(now, step, idx + 1, target);//不取此瓜
    dfs(now + a[idx] / 2, step + 1, idx + 1, target);//取一半
    dfs(now + a[idx], step, idx + 1, target);//全取
}

int main()
{
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    double t = m / 1.0;
    double now = 0.0;
    int step = 0;
    int idx = 0;
    dfs(now, step, idx, t);
    if(cnt != 0x7fffffff)
    {
        cout << cnt << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    system("pause");
    return 0;
}

//本人写的买瓜函数是正确的，只是到最后超出时间限制

#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;

int n,m,ans=50;
int v[50], suf[50];

int min(int a,int b)
{
  return a>b?b:a;
}

void dfs(int sum,int pos,int cnt)
{
    if(cnt>=ans) return ;
    if(sum==m) ans=min(ans,cnt);
    if(pos>=n||sum>=m||sum+suf[pos]<m) return ;
    dfs(sum+v[pos],pos+1,cnt);
    dfs(sum+v[pos]/2,pos+1,cnt+1);
    dfs(sum,pos+1,cnt);
}

int maint()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);//这些语句是为了让输入输出流的速度变快
    cin>>n>>m;
    m<<=1;
    for(int i=0;i<n;i++) cin>>v[i],v[i]<<=1;
    sort(v,v+n,greater<>());
    for(int i=n-1;i>=0;i--)
    suf[i]=suf[i+1]+v[i];
    dfs(0,0,0);
    if(ans==50) cout<<-1;
    else cout<<ans;
    return 0;
}