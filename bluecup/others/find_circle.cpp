#include "m.h"

const int N=2e5+10;//因为是无向图,要add两遍,所以idx应该是两倍
int h[N],e[N],ne[N],idx;
int q[N],tt=-1,hh=0;
int d[N];
bool st[N];

void add(int a,int b)
{
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void top(int n)
{
  for(int i = 1;i <= n;i++)
    if(d[i] == 1) 
        q[++tt]=i;
  while(hh <= tt)
  {
    int t = q[hh++];
    for(int i = h[t];i != -1;i = ne[i])
    {
      int j = e[i];
      if(--d[j] == 1) q[++tt] = j;
    }
  }
}

int main()
{
  memset(h,-1,sizeof(h));
  int n;
  cin >> n;
  for(int i = 0;i < n;i++)
  {
    int a, b;
    scanf("%d %d",&a,&b);
    add(a, b),add(b, a);
    d[a]++,d[b]++;
  }
  top(n);
  for(int i = 1;i <= n;i++)
    if(d[i] > 1)  
        printf("%d ",i);
  system("pause");
  return 0;
}