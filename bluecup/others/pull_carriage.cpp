#include "m.h"
using namespace std;

queue<char> a;
queue<char> b;
vector<char> q;
int win = 0, cnt = 0, f = 0;
int start = 0, rear = 0;

void play()
{
    if(a.size() == 0 || b.size() == 0)
    {
        cnt = 100000;
        f = 1;
        string winner;
        while(a.size())
        {
            winner += a.front();
            a.pop();
        }
        while(b.size())
        {
            winner += b.front();
            b.pop();
        }
        cout << winner << endl;
    }
    if(win == 1)
    {
        char t = b.front();
        b.pop();
        q[rear] = t;
        rear++;
        int i = start;
        for(i = start; i < rear - 1;i++)
        {
            if(q[i] == t)
            {
                break;
            }
        }
        if(i == rear - 1)
        {
            win = 0;
        }
        else
        {
            for(int j = rear - 1;j >= i;j--)
            {
                b.push(q[j]);
            }
            rear = i;
        }
    }
    else
    {
        char t = a.front();
        a.pop();
        q[rear] = t;
        rear++;
        int i = start;
        for(i = start; i < rear - 1;i++)
        {
            if(q[i] == t)
            {
                break;
            }
        }
        if(i == rear - 1)
        {
            win = 1;
        }
        else
        {
            for(int j = rear - 1;j >= i;j--)
            {
                a.push(q[j]);
            }
            rear = i;
        }
    }
}

int main()
{
  // 请在此输入您的代码
  q.resize(10000);
  string stra, strb;
  cin >> stra;
  cin >> strb;
  int lena = stra.size(), lenb = strb.size();
  for(int i = 0;i < lena;i++)
  {
      a.push(stra[i]);
  }
  for(int i = 0;i < lenb;i++)
  {
      b.push(strb[i]);
  }
  while(cnt < 10001)
  {
      play();
      cnt++;
  }
  if(!f)
  {
      cout << -1 << endl;
  }
  system("pause");
  return 0;
}