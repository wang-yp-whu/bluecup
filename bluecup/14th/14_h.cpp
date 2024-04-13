#include "m.h"

int Xor(int a[], int n)
{
    int sum = 0;
    for(int i = 0;i < n;i++)
    {
        int ans = a[i];
        for(int j = i;j < n;j++)
        {
            ans = ans ^ a[j];
            sum += ans;
        }
    }
    return sum;
}

int main()
{
    int n = 0;
    cin >> n;
    int a[n] = {0};
    for(int i = 0; i < n;i++)
    {
        a[i] = i + 1;
    }
    if(n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    long long r = Xor(a, n);
    cout << r << endl;
    system("pause");
    return 0;
}