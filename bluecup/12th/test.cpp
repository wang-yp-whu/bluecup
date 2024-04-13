#include "m.h"

int gcd(int x,int y)
{
    return !y?x:gcd(y,x%y);
}

int main()
{
    int f[2022];
    memset(f,0,sizeof f);
    for(int i = 1;i <= 2021;i++) 
    {
        for(int j = i+1;j <= i+21;j++) 
        {
            if(j > 2021)
                break;
            if(f[j] == 0)
                f[j] = f[i]+j*i/gcd(i,j);
            else    
                f[j] = min(f[j],f[i]+j*i/gcd(i,j));
        }
    }
    cout << f[2021] << endl;
    return 0;
}