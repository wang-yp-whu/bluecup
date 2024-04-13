#include "m.h"

int main()
{ 
    int ans=2; //第一个圆把平面分成2部分 
    for (int i=2; i<=20; i++) 
    { 
        ans+=(i-1)*2; //第i个圆依次和前面(i-1)个圆产生(i-1)2个交点，即被分成(i-1)*2段，亦即产生(i-1)*2个部分 
    } 
    int n=20; ans+=n*2; //第一条直线和20个圆相交，平面增加2n部分 
    for (int i=2; i<=20; i++) 
    { 
        ans+=(2*n+i); //第i条直线和前面20个圆和i-1条线最多产生40+i-1个焦点，被分成40+i段，亦即增加40+i个部分 
    } 
    cout << ans << endl;
    system("pause");
    return 0;
}