#include "m.h"

int vis[10],a[5][5],ans[5][5];
int n,cnt;
pair<int ,int>p[10];

bool check(){
    int sum=a[1][1]+a[2][2]+a[3][3];
    if(sum!=a[1][3]+a[2][2]+a[3][1]) return false;
    for(int i=1;i<=3;i++){
    int tmp1=0,tmp2=0;
    for(int j=1;j<=3;j++)tmp1+=a[i][j],tmp2+=a[j][i];//行和列的和相等 
    if(tmp1!=sum||tmp2!=sum) return false;
    }
    return true;
} 

void dfs(int now){
    if(now>n){
        if(check()){
            cnt++;
            for(int i=1;i<=3;i++)
                for(int j=1;j<=3;j++)
                    ans[i][j]=a[i][j];
        }
        return;
    }
    int x=p[now].first,y=p[now].second;
    for(int k=1;k<=9;k++)
    {
        if(vis[k])continue;
        a[x][y]=k;
        vis[k]=1;
        dfs(now+1);
        a[x][y]=0;
        vis[k]=0;
    }
}

int main()
{
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
            if(!a[i][j])p[++n]=make_pair(i,j);
            vis[a[i][j]]=1;    
        }
    dfs(1);
    if(cnt==1){
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                cout<<ans[i][j]<<" \n"[j==3];
            }
    else cout<<"Too Many\n";
    return 0;
 }