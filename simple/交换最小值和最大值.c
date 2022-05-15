/*交换最小值和最大值*/
/*本题要求编写程序，先将输入的一系列整数中的最小值与第一个数交换，然后将最大值与最后一个数交换，最后输出交换后的序列。

注意：题目保证最大和最小值都是唯一的。

输入格式：
输入在第一行中给出一个正整数N（≤10），第二行给出N个整数，数字间以空格分隔。

输出格式：
在一行中顺序输出交换后的序列，每个整数后跟一个空格。

输入样例：
5
8 2 5 1 4
输出样例：
1 2 5 4 8 */

#include<stdio.h>

void swap(int v[],int i,int j);

int main(){
	int a;
	scanf("%d",&a);
	int shuzu[a];
	int i=0;
	for( ;i<a;i++){
		scanf("%d",&shuzu[i]);
	}
	int* zhi;
	zhi=&shuzu[0];
	int x=0,y=0;
	int v=1000,u=0;
	for(i=0;i<a;i++){
		if(x<*zhi){
			x=*zhi;/*x为最大值*/ 
			y=i;
		}
		if(v>*zhi){
			v=*zhi;/*v为最小值*/ 
			u=i;
		}	
		zhi++;
	}
	swap(shuzu,y,a-1);
	swap(shuzu,u,0);
	for(i=0;i<a;i++){
		printf("%d ",shuzu[i]);	
	}
	return 0;
}
void swap(int v[],int i,int j){
    int temp;
    temp=v[i];
    v[i]=v[j];
    v[j]=temp;
    
}

/*
#include <stdio.h>
int main() {
    int i, j = 0, m = 0, n, k[11], min, max, p;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &k[i]);
    }

    min = k[0];               //最小值
    for (i = 1; i < n; i++) { //得到最小值
        if (k[i] < min) {
            m = i;
            min = k[i];
        }
    }

    p = k[0]; //最小值与第一个数交换
    k[0] = min;
    k[m] = p;

    max = k[0];               //最大值
    for (i = 1; i < n; i++) { //得到最大值
        if (k[i] > max) {
            j = i;
            max = k[i];
        }
    }

    p = k[n - 1]; //最大值与最后一个数交换
    k[n - 1] = max;
    k[j] = p;

    for (i = 0; i < n; i++) {
        printf("%d ", k[i]);
    }
}
*/
