#include "m.h"

int n, x;
int a[100001],b[100001];
int ans;

bool check(int l)
{
	int cnt = 0X7FFFFFFF;
	for(int i = l+1; i <= n; i++)
    {
		cnt= min(cnt,b[i]-b[i-l]);
	}
	return cnt >= 2*x;
}

int main()
{
	cin >> n >> x;
	ans = n;
	for(int i = 2; i <= n; i++)
    {
		cin >> a[i];
		b[i] = b[i-1] + a[i];
	}
	int l = 1, r = n;
	while(l < r)
    {
		int mid = (l + r) >> 1;
		if(check(mid))
        {
			r = mid; 
			ans = mid;
		}
        else
        {
			l = mid+1;
		}
	} 
	cout << ans << endl;
    system("pause");
	return 0;
}