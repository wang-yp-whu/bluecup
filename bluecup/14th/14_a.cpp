#include "m.h"

int main()
{
    long long i = 10;
    int cnt = 0;
    while(i <= 100000000)
    {
        string num = to_string(i);
        if(num.size() % 2 == 0)
        {
            int sum1 = 0, sum2 = 0;
            for(int j = 0, k = num.size() - 1;j < k;j++, k--)
            {
                sum1 += num[j] - '0';
                sum2 += num[k] - '0';
            }
            if(sum1 == sum2)
            {
                cnt++;
            }
            i++;
        }
        else
        {
            i *= 10;
        }
    }
    cout << cnt << endl;
    //4430091
    system("pause");
    return 0;
}