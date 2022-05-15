 #include<stdio.h>
int main(){
 int a,N,blank,other;
 int digit,letter;
 char ch;
 blank=other=letter=digit=0;
 scanf("%d",&N);
 for(a=0;a<=N;a++){  
 ch=getchar(); 
 if(ch>='0'&&ch<='9')
  ++digit;
 else if(ch==' '||ch=='\n')
  ++blank;
 else if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
  ++letter;
 else
  ++other;
 }
 printf("letter = %d, blank = %d, digit = %d, other = %d",letter,blank-1,digit,other);
 return 0;
}
