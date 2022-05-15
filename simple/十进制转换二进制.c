/*
十进制转换二进制
本题要求实现一个函数，将非负整数n转换为二进制后输出。

函数接口定义：
void dectobin( int n );
函数dectobin应在一行中打印出二进制的n。建议用递归实现。*/

#include <stdio.h>

void dectobin( int n );

int main()
{
    int n;
    
    scanf("%d", &n);
    dectobin(n);
    
    return 0;
}

/* 你的代码将被嵌在这里 */
void dectobin( int n ){
    if(n/2>0){
        dectobin(n/2);
    }
    printf("%d",n%2);//在递归后面，逆向打印
}
/*非递归法
void dectobin( int n )
{
    int a[10];
    int temp, i;

    do
    {
        a[i++] = n % 2;
    }while ((n /= 2) != 0);
    for (--i; i >= 0; i--)
        printf("%d", a[i]);
}
本题要求实现一个函数，将正整数n转换为二进制后输出。*/
