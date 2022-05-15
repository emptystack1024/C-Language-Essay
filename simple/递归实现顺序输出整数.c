/*
R6-2 递归实现顺序输出整数 (20 分)
本题要求实现一个函数，对一个整数进行按位顺序输出。

函数接口定义：
void printdigits( int n );
函数printdigits应将n的每一位数字从高位到低位顺序打印出来，每位数字占一行。
*/

#include <stdio.h>

void printdigits( int n );

int main()
{
    int n;
    
    scanf("%d", &n);
    printdigits(n);

    return 0;
}

/* 你的代码将被嵌在这里 */
void printdigits(int n)
{
    if (n >= 10)
    {
        printdigits(n / 10);
    }

    printf("%d\n", n % 10);
}

