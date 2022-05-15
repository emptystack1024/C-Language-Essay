#include<stdio.h>
int max(int a[],int len){
	int maxid=0;
	for(int i=1;i<len;i++){
		if(a[i]>a[maxid]){
			maxid=i;
		}
	}
	return maxid;
}
//找出数组中最大的数
int main(){
	int a[]={2,15,49,54,45,69,46,4};
	
	int len=sizeof(a)/sizeof(a[0]);
	for(int i=len-1;i>0;i--){
	int maxid=max(a,i+1);
	//将a[maxid]和a[len-1]做交换
	int t=a[maxid];
	a[maxid]=a[i];
	a[i]=t;
	}
	for(int i=0;i<len;i++){
		printf("%d\n",a[i]);
	}
	
} 

