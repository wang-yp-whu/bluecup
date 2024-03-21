#include "m.h"

int n, len;
int cnt = 0;

struct good
{
    int x, y, z;
    int numth;
    int flag;
}gd[200000];

void scan_sort()
{
    while(cnt <= n)
    {
        for(int i = 0;i < n;i++)
        {
            
        }
    }
}

int main()
{
    cin >> n >> len;
    int xp, yp, zp;
    for(int i = 0;i < n;i++)
    {
        cin >> xp >> yp >> zp;
        gd[i].x = xp;
        gd[i].y = yp;
        gd[i].z = zp;
        gd[i].flag = 0;
    }
    scan_sort();
    system("pause");
    return 0;
}