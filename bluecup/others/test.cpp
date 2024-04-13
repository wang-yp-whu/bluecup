#include "m.h"

int main()
{
    vector<int> a{1, 2, 3, 4, 5};
    vector<int> b = a;
    b[2] = 8;
    for(int i = 0;i < 5;i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
    for(int i = 0;i < 5;i++)
    {
        cout << b[i] << ' ';
    }
    system("pause");
    return 0;
}