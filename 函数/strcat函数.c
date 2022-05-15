//strcat函数：将字符串t连接到字符串s的尾部；s必须有足够大的空间
void strcat(char s[],char t[]){
	int i,j;
	i=j=0;
	while (s[i]!='\0'){/*判断是否为字符串s的尾部*/
		i++;
	}
	while((s[i++]=t[j++])!='\0'){/*拷贝t*/
		;
	}
} 
