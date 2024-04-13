#include "m.h"
#define max 10000

/*
这道题我本以为是一道几何，没想到可以用二分，
只需要最后切出来的正方形个数大于等于给定的数即可
实在是给了我很大启示
*/

int n = 0, k = 0;
vector<int> h = vector<int> (100000, 0);
vector<int> w = vector<int> (100000, 0);

bool isvalid(int x)
{
    int sum = 0;
    for(int i = 0; i < n;i++)
    {
        sum += (h[i] / x) * (w[i] / x);
    }
    if(sum >= k)
    {
        return true;
    }
    return false;
}

int main()
{
    cin >> n >> k;
    for(int i = 0;i < n;i++)
    {
        cin >> h[i] >> w[i];
    }
    int left = 1, right = 10000;
    int ans = 0;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(isvalid(mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}