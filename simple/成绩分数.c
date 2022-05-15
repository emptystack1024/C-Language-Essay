#include <stdio.h>
int main(){
 int a,b;
 scanf("%d",&a);
 if(a>=90&&a<=100)
  b='A';
 else if(a>=80&&a<90)
  b='B';
 else if(a>=70&&a<80) 
  b='C';
 else if(a>=60&&a<70)
  b='D';
 else if(a>=0&&a<60)
  b='E';
 printf("%c",b);
 return 0;
}
