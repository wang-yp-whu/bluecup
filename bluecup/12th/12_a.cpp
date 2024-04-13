#include "m.h"

long long ans = 1;
int num[10] = {0};

bool can(long long ans)
{
    while(ans)
    {
        num[ans % 10] -= 1;
        if(num[ans % 10] < 0)
        {
            return false;
        }
        ans /= 10;
    }
    return true;
}

int main()
{
    for(int i = 0;i < 10;i++)
    {
        num[i] = 2021;
    }
    while(can(ans))
    {
        ans++;
    }
    ans -= 1;
    cout << ans << endl;
    system("pause");
    return 0;
}