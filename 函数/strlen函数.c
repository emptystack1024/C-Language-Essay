//strlen函数：返回s的长度
int strlen(char s[])
{
	int i;
	
	i=0;
	while(s[i]!='\0'){
		++i;
	}
	
	return i;
 } 


/*另一种写法*/
int strlen(char *s){
	int n;
	for(n=0;*s!='\0';s++){
		n++;
	}
	return n;
}

/*另一种写法*/
int strlen(char *s){
	char *p=s;
	while (*p!='\0')
		p++;
	return p-s;
}
