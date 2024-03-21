#include "m.h"
using namespace std;

typedef  long long  ll;

ll vis[4005],prime[4005],cnt;

void Prime()
{
    for(int i=2;i<=3982;i++)
    {
        if(vis[i]==0)
        {
            prime[++cnt] = i;
            for(int j=2*i;j<=3982;j+=i)
                vis[j]=1;
        }    
    }
} 


int check(ll a)
{
    int num = 0;
    if(a == 1)
    {
        return 1;
    }
    for(int i=1;i <= cnt && a > 1;i++)
    {
        int sum=0;
        if(a % prime[i] == 0)
        {
            num += 1;
        }
        while(a % prime[i] == 0)
        {
            a /= prime[i];
            sum++;
        }
        if(sum == 1)
        {
            return 0;
        }
        if(num > 2)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    cnt = 0;
    Prime();
    int t;
    cin >> t;
    while(t)
    {
        ll a;
        scanf("%lld",&a);
        if(check(a))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
        t--;
    }
    system("pause");
    return 0;
}