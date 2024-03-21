#include "m.h"

bool compare(string nums)
{
    int lens = nums.size();
    for(int i = 0, j = lens - 1;i < j;i++, j--)
    {
        if(nums[i] > nums[j])
        {
            return true;
        }
        if(nums[i] < nums[j])
        {
            return false;
        }
    }
    return false;
}

int main()
{
    string num;
    cin >> num;
    int len = num.size();
    int cnt = 0;
    for(int i = 0;i < len - 1;i++)
    {
        for(int j = i + 1;j < len;j++)
        {
            if(num[i] > num[j])
            {
                cnt++;
            }
            if(num[i] == num[j])
            {
                string nums = num.substr(i, j - i + 1);
                if(compare(nums))
                {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    system("pause");
    return 0;
}
/*
#include <bits/stdc++.h>
#define int long long
//#define endl '/n'
using namespace std;
int  n;
string s;
signed main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);
    //cout.tie(0);
        cin >> s;
        for (int i = 0; i < s.size()-1; i++)
        {
            for (int j = i+1; j < s.size(); j++)
            {
                if(s[i]>s[j])
                n++;
                if(s[i]==s[j])
                {
                    int x=i;
                    int y=j;
                while(1)
                {
                 x++;
                 y--;
                 if(x>=y||s[x]<s[y])
                 break;
                 if(s[x]>s[y])
                 {
                   n++;
                   break;
                 }
                }
                }
            } 
        }
        cout<<n;
    return 0;
}*/