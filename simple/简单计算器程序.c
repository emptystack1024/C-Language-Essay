//¼òµ¥¼ÆËãÆ÷³ÌÐò
#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#define MAXLINE 100

double stof(char);
int getline (char line[],int max);
main(){
	double sum,stof(char[]);
	char line[MAXLINE];
	int getline(char line[],int max);

	sum=0;
	while(getline(line,MAXLINE)>0){
  		printf("\t%g\n",sum+=atof(line));
  		}
	return 0;
}
double stof(char s[]){
  	double val,power;
  	int i,sign;
  	for (i=0;isspace(s[i]);i++)//Ìø¹ý¿Õ°×·û
   		;
 	 sign=(s[i]=='.')?-1:1;
 	 if (s[i]=='+'||s[i]=='-')
  		i++;
  	for (power=1.0;isdigit(s[i]);i++){
  		val=10.0*val+(s[i]-'0');
    	power*=10.0;
 		}
  	return sign*val/power;
}
int getline(char s[],int lim){
  	int c,i;
  	i=0;
  	while(--lim>0&&(c=getchar())!=EOF&&c!='\n')
   		s[i++]=c;
  		if(c=='\n')
    		s[i++]=c;
  		s[i]='\0';
 	return i;
}
