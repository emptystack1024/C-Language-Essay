//atoi函数：将字符串s转换为相应的整形数 
int atoi(char s[]) {
	int i,n;
	
	n=0;
	for(i=0;s[i]>='0'&&s[i]<='9';++i){
		n=10*n+(s[i]-'0');		
	}
	
	return n;
}

//atoi函数：利用atof函数把字符串s转换为整数
int atoi(char s[]){
	double atof(char s[]);
	return (int) atof(s);
}


#include<ctype.h>
/*aoti函数：将s转换为整型数：版本二*/
int atoi(char s[]){
	int i,n,sign;
	for(i=0;isspace(s[i]);i++)//跳过空白符 
	{
		;
	}
	sign=(s[i]=='-')?-1:1;
	if (s[i]=='+'||s[i]=='-')//跳过符号
	{
		i++;
	 } 
	for(n=0;isdigit(s[i]);i++){
		n=10*n+(s[i]-'0');
	}
	return sign*n;
} 
#include <ctype.h>
//atof函数：把字符串s转换为相应的双精度浮点数
double stof(char s[]){
  	double val,power;
  	int i,sign;
  	for (i=0;isspace(s[i]);i++)//跳过空白符
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



