#include<stdio.h>
#include<math.h> 
int pd(int x);
int main(){
	int a,b;
	int he=0;
	int sum=0;
	int yue,p;
	scanf("%d %d",&a,&b);
	if(a<1||b>500){
		printf("error");
		goto end;
	}
	if(a==b&&pd(a)==0){
		goto jiewei;
	}
	else if(a==b&&pd(a)==1){
		he=1;
		sum=a;
		goto jiewei;
	}
	else{
		for(yue=a;yue<=b;yue++){
			p=pd(yue);
			if(pd(yue)==1){
				sum+=yue;
				he++;
			}
		}
	}
	jiewei:
	printf("%d %d",he,sum);
	end:
	return 0;
	
}
 int pd(int m)
{
	int i;
	if(m==0)return 0;
	if(m==1) return 0;
	for(i=2;i<=sqrt(m);i++)
	if (m%i==0) break;
	if(i<=sqrt(m)) return 0;
	else return 1;
 } 

