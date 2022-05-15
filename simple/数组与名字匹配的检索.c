#include<stdio.h>
//检索 
int amount[]={1,5,10,25,50};
char *name[]={"penny","nickel","dime","quarter","half-dollar"}; 
int search(int key,int a[],int length){
      int ret=-1;
      int i;
      for(i=0;i<length;i++){
            if(a[i]==key){
                    ret=i;
                    break;
              }
        }
      return ret;
}
int main(){
           int b;
           
           printf("请输入你要搜索的数：\n");
           scanf("%d",&b);
           int r=search(b,amount,sizeof(amount)/sizeof(amount[0]));
           printf("%d\n",r);
           if(r>-1){
           	printf("%s\n",name[r]);
		   }else{
		   	printf("不存在\n");
		   }
           return 0;
}


