#include <stdio.h>

int main()
{
	int a,b;

	scanf("%d %d", &a, &b);

	double c = (a+b)/2.0;
	
	printf("%d和%d的平均值=%f\n", a, b, c);

	return 0;
}

/*do-while*/
/*
#include<stdio.h>
int main()
{
	int number;
	int sum=0;
	int count=0;
	
	do{
		scanf("%d",&number);
		if (number!=-1){
			sum += number;
			count ++;
		}
	} while(number!=-1);
	
	printf("平均值为%f\n",1.0*sum/count);
	
	return 0;
}

*/
