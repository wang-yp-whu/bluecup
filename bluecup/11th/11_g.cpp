#include "m.h"

#include <iostream>
using namespace std;

int day_limit[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool islegal(string &num, int d)
{
    int day = d % 100;
    if(day == 0 || day > 31)
    {
        return false;
    }
    int month = (num[4] - '0') * 10 + num[5] - '0';
    if(month == 0 || month > 12)
    {
        return false;
    }
    int year = d / 10000;
    if(month != 2)
    {
        if(day > day_limit[month])
        {
            return false;
        }
    } 
    if(month == 2)
    {
        if(year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
        {
            if(day > 29)
            {
                return false;
            }
        }
        else
        {
            if(day > 28)
            {
                return false;
            }
        }
    }
    return true;
}

bool backword(string &num)
{
    int len = num.size();
    for(int i = 0,j = len - 1;i <= j;i++, j--)
    {
        if(num[i] != num[j])
        {
            return false;
        }
    }
    return true;
}

bool isab(string &num)
{
    char a = num[0], b = num[1];
    if(num[0] != a || num[2] != a || num[5] != a || num[7] != a)
    {
        return false;
    }
    if(num[1] != b || num[3] != b || num[4] != b || num[6] != b)
    {
        return false;
    }
    return true;
}

int main()
{
  // 请在此输入您的代码
  int date = 0, f = 0, f1 = 0;
  cin >> date;
  for(int i = date + 1;i <= 100000000;i++)
  {
    string num = to_string(i);
    if(islegal(num, i))
    {
        if(backword(num) && f == 0)
        {
            cout << i << endl;
            f = 1;
        }
        if(isab(num) && f1 == 0)
        {
            cout << i << endl;
            f1 = 1;
        }
    }
    if(f && f1)
    {
        break;
    }
  }
  system("pause");
  return 0;
}