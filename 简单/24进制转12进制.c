#include<stdio.h>
int main(){
 int a,b;
 scanf("%d:%d",&a,&b);
 if(a/12==0){
  printf("%d:%d AM",a,b);
 }
 else if(a/12==1){
  if(a==12){
   printf("%d:%d PM",a,b);
  }else
  printf("%d:%d PM",a-12,b);
 }
 else
  printf("ERROR!!!!!");
 return 0; 
} 
