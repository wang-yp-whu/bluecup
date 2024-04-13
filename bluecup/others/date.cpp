#include "m.h"

//未加入闰年判断导致输出不合法日期，败笔

int main()
{
    string date;
    date.resize(9);
    cin >> date;
    int num1 = 0, num2 = 0, num3 = 0;
    int year = 0, month = 0, day = 0;
    num1 = (date[0] - '0') * 10 + date[1] - '0';
    num2 = (date[3] - '0') * 10 + date[4] - '0';
    num3 = (date[6] - '0') * 10 + date[7] - '0';
    vector<string> ans;
    int weight[3][2];
    //1.year - month - day
    string t;
    if(num1 >= 60)
    {
        year = 1900 + num1;
    }
    else
    {
        year = 2000 + num1;
    }
    t = t + to_string(year) + '-';
    if(num2 >= 10)
    {
        t += to_string(num2) + '-';
    }
    else
    {
        t = t + '0' + to_string(num2) + '-';
    }
    if(num3 >= 10)
    {
        t += to_string(num3);
    }
    else
    {
        t = t + '0' + to_string(num3);
    }
    ans.push_back(t);
    weight[0][0] = year * 100 + num2 * 10 + num3;
    weight[0][1] = 0;
    //2.day - month - year
    string t1;
    if(num3 >= 60)
    {
        year = 1900 + num3;
    }
    else
    {
        year = 2000 + num3;
    }
    t1 = t1 + to_string(year) + '-';
    if(num2 >= 10)
    {
        t1 += to_string(num2) + '-';
    }
    else
    {
        t1 = t1 + '0' + to_string(num2) + '-';
    }
    if(num1 >= 10)
    {
        t1 += to_string(num1);
    }
    else
    {
        t1 = t1 + '0' + to_string(num1);
    }
    ans.push_back(t1);
    weight[1][0] = year * 100 + num2 * 10 + num1;
    weight[1][1] = 1;
    //3.month - day - year
    string t2;
    if(num3 >= 60)
    {
        year = 1900 + num3;
    }
    else
    {
        year = 2000 + num3;
    }
    t2 = t2 + to_string(year) + '-';
    if(num1 >= 10)
    {
        t2 += to_string(num1) + '-';
    }
    else
    {
        t2 = t2 + '0' + to_string(num1) + '-';
    }
    if(num2 >= 10)
    {
        t2 += to_string(num2);
    }
    else
    {
        t2 = t2 + '0' + to_string(num2);
    }
    ans.push_back(t2);
    weight[2][0] = year * 100 + num1 * 10 + num2;
    weight[2][1] = 2;

    for(int i = 0;i < 2;i++)
    {
        for(int j = i + 1; j < 3;j++)
        {
            if(weight[i][0] > weight[j][0])
            {
                int tmp = 0;
                tmp = weight[i][0];
                weight[i][0] = weight[j][0];
                weight[j][0] = tmp;
                tmp = weight[i][1];
                weight[i][1] = weight[j][1];
                weight[j][1] = tmp;
            }
        }
    }
    cout << weight[0][0] << ' ' << weight[1][0] << ' ' << weight[2][0] << endl;
    for(int i = 0;i < 3;i++)
    {
        if(i > 0)
        {
            if(weight[i][0] == weight[i - 1][0])
            {
                continue;
            }
        }
        cout << ans[weight[i][1]] << endl;
    }
    system("pause");
    return 0;
}

//正确解法，写起来思路清晰，面面俱到
int max_days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool check(int year,int month,int day)
{
    if(month ==0 || month > 12) return false;
    if(day == 0) return false;
    if(month != 2){
        if(day > max_days[month]) return false;
    }
    else{
        int leap = (year % 4 == 0 && year % 100) || (year % 400 == 0);
        if(day > 28 + leap) return false;
    }
    return true;
}

int main()
{
    int a,b,c;
    scanf("%d/%d/%d",&a,&b,&c);
    for(int data=19600101;data<=20591231;data++)
    {
        int year = data / 10000, month = data % 10000 / 100, day = data % 100;
        if(check(year,month,day))
        {
            if(year % 100 == a && month == b && day== c ||
                month == a && day == b && year % 100== c ||
                day == a && month == b && year % 100== c)
                printf("%d-%02d-%02d\n",year,month,day);
        }

    }
    return 0;
}