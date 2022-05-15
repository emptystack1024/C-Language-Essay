#include<stdio.h>
//用之前的素数判断素数 
int isprime(int x,int knowprimes[],int numberofkonwnprimes)
{
      int ret=1;
      int i;
      for(i=0;i<numberofkonwnprimes;i++){
             if(x%knowprimes[i]==0){
                     ret=0;
                     break;
                 }
      }
return ret;
}
int main(void){
const int number=100;
int prime[number]={2};
int count =1;
int i=3;
while (count<number){
            if (isprime(i,prime,count)){
            prime[count++]=i;
            }
            i++;
}
for (i=0;i<number;i++){
       printf("%d",prime[i]);
       if((i+1)%5){
           printf("\t");
           }else printf("\n");
           }
           return 0;
}

