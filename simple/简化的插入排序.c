/*简化的插入排序*/
/*本题要求编写程序，将一个给定的整数插到原本有序的整数序列中，使结果序列仍然有序。

输入格式：
输入在第一行先给出非负整数N（<10）；第二行给出N个从小到大排好顺序的整数；第三行给出一个整数X。

输出格式：
在一行内输出将X插入后仍然从小到大有序的整数序列，每个数字后面有一个空格。

输入样例：
5
1 2 4 5 7
3
输出样例：
1 2 3 4 5 7 */

#include<stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	if(a<10){
		int shuzu[a];
		int i=0;
		for( ;i<a;i++){
			scanf("%d",&shuzu[i]);
		}
		int jia;
		scanf("%d",&jia);
		int shuzu2[a+1];
		if(jia<shuzu[0]||jia<=0){
			shuzu2[0]=jia;
			for(i=0;i<a;i++){
				shuzu2[i+1]=shuzu[i];
			}
			for(i=0;i<=a;i++){
				printf("%d ",shuzu2[i]);
			}
			goto jiewei;
		}else if(jia>shuzu[a-1]){
			shuzu2[a]=jia;
			for(i=0;i<a;i++){
				shuzu2[i+1]=shuzu[i];
			}
			for(i=0;i<=a;i++){
				printf("%d ",shuzu2[i]);
			}
			goto jiewei;
		}
		
		int* zhi;
		zhi=&shuzu[0];
		int* zhi2;
		zhi2=&shuzu[1];
		
		for(i=0;i<a;i++){
			shuzu2[i]=shuzu[i];
			if(jia>*zhi&&jia<*zhi2){
				shuzu2[i+1]=jia;
				break;
			}else if(jia==*zhi){
				shuzu2[i+1]=jia;
				break;
			}
			zhi++;
			zhi2++;
		}
		for(i+=1;i<a;i++){
			shuzu2[i+1]=shuzu[i];
		}
		for(i=0;i<=a;i++){
			printf("%d ",shuzu2[i]);
		}

	}
	jiewei:
	return 0;	
}

/*
#include<stdio.h>
int main(){
    int n,i,j;
    scanf("%d",&n);
    int a[n+1];
    for(i=0;i<=n;i++)
    scanf("%d",&a[i]);
 
    for(i=0;i<n;i++) if(a[i]>a[n])
    {a[i]=a[i]+a[n];a[n]=a[i]-a[n];a[i]=a[i]-a[n];}//交换
 
    for(i=0;i<=n;i++)
    printf("%d ",a[i]);
    return 0;
}
*/


/*
#include <stdio.h>
int main()
{
	int n,i,j,x;
	scanf("%d",&n);
    int a[n+1];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&x);
 
	for(i=0;i<n;i++) if(a[i]>x)
    break;//找位置
	for (j=n-1;j>=i;j--){
		a[j+1]=a[j];
	}//移位置
	a[i]=x;//放入
	for(i=0;i<n+1;i++)
	printf("%d ",a[i]);
    return 0;
 } 
 */
