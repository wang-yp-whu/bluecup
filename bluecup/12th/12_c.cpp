#include "m.h"

int main()
{
  // 请在此输入您的代码
  long long num=2021041820210418;
  //其实为什么我们那样去想，因为那样去想最简单，最不费脑子。但是我们发现那种方法很多组都是无效的，也就是出现不是num因子的数字出现
  //因此这样的计算毫无意义反而给我们的CPU增加负担；
  //好，简化的目的摆明了，找num的因子呗~
  //但是我们事先不知道num到底有多少因子，因此这里可以设置一个vector容器，产生一个就压进vector容器里
  vector<long long> divisor;//因为因子也可能是num本身，所以咱们的因子容器设置为long long类型的
  //我们开始找因子，只需要找到num的平方根即可，因为如果再往后找的话，就找到之前小于num平方根的i除得的num中对应于i的较大的因子；
  //这里对于较大的因子我们可以通过循环里的j得到
  for(long long i=1;i<=sqrt(num);i++)
  {
    if(num%i==0)
    {
      divisor.push_back(i);
      long long j=num/i;
      if(j!=i)
      {
        divisor.push_back(j);//如果是因子就将因子压入因子容器里
      }
    }
  }
  //设置好题解是count初值为0
  int count=0;
  //设置三个迭代器遍历因子容器找三个因子相乘就是num的组合，答案就在这些组合里面
  vector<long long>::iterator a,b,c;
  for(a=divisor.begin();a!=divisor.end();a++)
  {
    for(b=divisor.begin();b!=divisor.end();b++)
    {
      for(c=divisor.begin();c!=divisor.end();c++)
      {
        if((*a)*(*b)*(*c)==num)
        {
          count++;
        }
      }
    }
  }
  cout<<count<<endl;//输出结果，问题结束！
  system("pause");
  return 0;
}