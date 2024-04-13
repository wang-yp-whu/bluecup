// #include "m.h"
// using namespace std;

// long long s = 20000101;
// long long e = 20000000101;
// int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// bool is_leap(int year)
// {
//     if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//     {
//         return true;
//     }
//     return false;
// }

// bool islegal(long long n)
// {
//     int date = n % 100;
//     if(date > 31 || date == 0)
//     {
//         return false;
//     }
//     n /= 100;
//     int month = n % 100;
//     if(month > 12 || month == 0)
//     {
//         return false;
//     }
//     if(month != 2 && date > m[month])
//     {
//         return false;
//     }
//     int year = n / 100;
//     if(month == 2)
//     {
//         if(is_leap(year))
//         {
//             if(date > 29)
//             {
//                 return false;
//             }
//         }
//         else
//         {
//             if(date > 28)
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// int main()
// {
//   // 请在此输入您的代码
//   int cnt = 0;
//   for(long long i = s;i <= e;i++)
//   {
//       if(islegal(i))
//       {
//           long long tmp = i;
//           int dd = tmp % 100;
//           tmp /= 100;
//           int mm = tmp % 100;
//           tmp /= 100;
//           if(tmp % mm == 0 && tmp % dd == 0)
//           {
//               cnt++;
//           }
//       }
//   }
//   cout << cnt << endl;
//   return 0;
// }

#include "m.h"
using namespace std;

int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int year)
{
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        return true;
    }
    return false;
}

bool islegal(int n)
{
    int date = n % 100;
    if(date > 31 || date == 0)
    {
        return false;
    }
    n /= 100;
    int month = n % 100;
    if(month > 12 || month == 0)
    {
        return false;
    }
    if(month != 2 && date > m[month])
    {
        return false;
    }
    int year = n / 100;
    if(month == 2)
    {
        if(is_leap(year))
        {
            if(date > 29)
            {
                return false;
            }
        }
        else
        {
            if(date > 28)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
  // 请在此输入您的代码
  int cnt = 0;
  for(int i = 19000101;i <= 99991231;i++)
  {
      if(islegal(i))
      {
          int tmp = i;
          int dd = tmp % 100;
          dd = dd % 10 + dd / 10;
          tmp /= 100;
          int mm = tmp % 100;
          mm = mm % 10 + mm / 10;
          tmp /= 100;
          int sum = tmp % 10 + tmp / 1000;
          tmp /= 10;
          sum += tmp % 10;
          tmp /= 10;
          sum += tmp % 10;
          if(sum == dd + mm)
          {
              cnt++;
          }
      }
  }
  cout << cnt << endl;
  return 0;
}