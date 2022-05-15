/*
本题要求实现一个计算两个数的最大公约数的简单函数。

函数接口定义：
int gcd( int x, int y );
其中x和y是两个正整数，函数gcd应返回这两个数的最大公约数。


输入样例：
32 72
输出样例：
8
*/
#include <stdio.h>
 
int gcd( int x, int y );
 
int main()
{
    int x, y;
    
    scanf("%d %d", &x, &y);
    printf("%d\n", gcd(x, y));
    
    return 0;
}
 
/* 你的代码将被嵌在这里 */
int gcd( int x, int y )
//先确定两个数中比较小的数
//for循环，直到等于0，如果中途遇到两个数都可以整除，直接跳出。
{
    int z,i;
    if(x>y)
    {   z=y;}
    else
    {   z=x;}
    for(i=z;i>0;i--)
    {   if(x%i==0&&y%i==0)
            break; 
    }
    return i;               
}
