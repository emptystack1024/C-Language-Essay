#include<stdio.h>
int main()
{
	int number;
	int sum=0;
	int count=0;
	int t=0;
	
	
	do{
		scanf("%d",&number);
		if (number!=-1){
			sum += number;
			count ++;
		}
		if(t<number){
			t=number;
		}
	} while(number!=-1);
	
	printf("平均值为%f\n",1.0*sum/count);
	printf("最大的数为%d",t);
	
	return 0;
}

