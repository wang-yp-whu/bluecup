#include <stdio.h>        
#include <string.h>
#define N 100002

int main()
{
    char s[N];
    int last[26];    //记录 a~z中每个字符最后被扫描的位置，即下标 
    int pre[N];        //记录前面与第i个字符相同的字符的位置，即下标 
    int next[N];    //记录后面与第i个字符相同的字符的位置，即下标 
    gets(s);
    int k,i,l;
    int sum=0;        //sum=sum+(i-pre[i])*(next[i]-i)  
    l=strlen(s);    //字符串长度
    for(i=0; i<26; i++)    //由于下标从0开始，所有字符在没出现第一次前都是 -1 
        last[i]=-1;
        
    for(i=0; i<l; i++)
    {
        k=s[i]-'a';
        pre[i]=last[k];    //前面与第i个字符相同的字符的位置
        last[k]=i;    //更新字符的位置 
    }
    
    for(i=0; i<26; i++)    //由于下标从0开始，从后面到前面，所有字符在没出现第一次前都是 l
        last[i]=l;
        
    for(i=l-1; i>=0; i--)
    {
        k=s[i]-'a';
        next[i]=last[k];    //后面与第i个字符相同的字符的位置
        last[k]=i;    //更新字符的位置 
    }
    
    for(i=0; i<l; i++)
    {
        sum+=(i-pre[i])*(next[i]-i);
        //(i-pre[i])为前面与第i个字符相同的字符与s[i]的距离
        //(next[i]-i)为后面与第i个字符相同的字符与s[i]的距离
    }
    printf("%d",sum);
    //system("pause");
    return 0;
}