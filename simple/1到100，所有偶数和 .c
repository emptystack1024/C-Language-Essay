#include<stdio.h>
int main(void){
  int i,sum =0;
  for (i=1;i<=100;i++){
    if(i%2==0){
      sum=sum+i;
    }
  }
  printf("%d",sum);
  return 0;
}
//1到100，所有偶数和 
