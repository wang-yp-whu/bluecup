#include "m.h"

//第一次运行超时
//第二次仍超
//直接算奇数的个数和4的倍数的个数
int main()
{
    long long L, R;
    long long cnt = 0;
    cin >> L >> R;
    if(L % 2 == 0)
    {
        if(R % 2 == 0)
        {
            cnt = (R - L) / 2;
        }
        else
        {
            cnt = (R - L) / 2 + 1;
        }
        cnt += (R - L + 1) / 4;
        /*for(long long x = L;x <= R;)
        {
            if(x % 4 == 0)
            {
                cnt++;
                x += 4;
            }
            else
            x += 2;
        }*/
        int i = 0;
        for(i = L;i <= R;i++)
        {
            if(i % 4 == 0)
            {
                break;
            }
        }
        cnt += (R - i) / 4 + 1;
    }
    else
    {
        if(R % 2 == 0)
        {
            cnt = (R - L) / 2 + 1;
        }
        else
        {
            cnt = (R - L) / 2 + 1;
        }
        /*
        for(long long x = L + 1;x <= R;)
        {
            if(x % 4 == 0)
            {
                cnt++;
                x += 4;
            }
            else
            x += 2;
        }*/
        int i = 0;
        for(i = L;i <= R;i++)
        {
            if(i % 4 == 0)
            {
                break;
            }
        }
        cnt += (R - i) / 4 + 1;
    }
    cout << cnt << endl;
    system("pause");
    return 0;
}