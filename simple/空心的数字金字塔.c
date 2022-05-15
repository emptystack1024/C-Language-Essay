/*空心的数字金字塔
本题要求实现一个函数，输出n行空心的数字金字塔。

函数接口定义：
void hollowPyramid( int n );
其中n是用户传入的参数，为[1, 9]的正整数。要求函数按照如样例所示的
格式打印出n行空心的数字金字塔，请注意，最后一行的第一个数字前没有空格。

输入样例：
5
输出样例：
    1
   2 2
  3   3
 4     4
555555555
*/

#include <stdio.h>

void hollowPyramid ( int n );

int main()
{    
    int n;

    scanf("%d", &n);
    hollowPyramid ( n );

    return 0;
}

/* 你的代码将被嵌在这里 */
void hollowPyramid( int n ){
   int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=2*n-1;j++){
            if(i==n) printf("%d",i);
            else{
                if(j==n-i+1) printf("%d",i);
                else if(j==n+i-1) printf("%d",i);
                else if(j<n-i+1||(j>n-i+1&&j<n+i-1)) printf(" ");//注意空格位置只能存在于两个区间，否则错误
            }
        }
        printf("\n");
    }
}

#include <stdio.h>
 
void hollowPyramid ( int n );
 
int main()
{    
    int n;
 
    scanf("%d", &n);
    hollowPyramid ( n );
 
    return 0;
}
 
/* 你的代码将被嵌在这里 */
void hollowPyramid(int n){               //注意大小写
    int i,j;
    int min=1;
    for(i=1;i<=n;i++){
        for(j=n-i;j>0;j--){           //空格
            printf(" ");
        }
         if(i==1)printf("%d\n",i);             //i为一时的情况。
        else if(i==n){                            //i为n时的情况。
            for(j=1;j<=2*n-1;j++)printf("%d",i);
        }
        else {                       //中间的情况。
            printf("%d",i);              //开头的数字。
            for(j=1;j<=min;j++){            //中间的空格。
                printf(" ");
            }printf("%d\n",i);              //末尾的数字。
            min+=2;
        }
    }
}
