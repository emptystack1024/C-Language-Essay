#include<stdio.h>
#include<math.h>
int main(){
	int a,n;
	scanf("%d %d",&a,&n);
	int i,ii,z;
	int h=0;
	int hh=0;
	
	for(i=1;i<=n;i++){//求出每一个数 
		
		z=a;
		for(ii=0;ii<i;ii++){//弄出每一个书shu 
			z=pow(10,ii)*a;
			hh+=z;
		}
		h+=z;

	}

	printf("s = %d",hh);
	return 0;
} 
