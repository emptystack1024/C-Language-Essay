#include<stdio.h>
#define MAXLINE 1000//最大输入行的长度

int getline (char line[],int max);
int strindex (char source[],char searchfor[]);

char pattern[]="ould";//待查找的模式
//找出所有与模式匹配的行
main(){
	char line[MAXLINE];
	int found=0;
	while (getline(line ,MAXLINE)>0)
		if (strindex(line ,pattern)>=0){
    		printf("%s",line);
    		found++;
			}
  	return found;
}
//getline 函数：将行保存到s中，并返回该行的长度
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
//strindex函数：返回t在s中的位置，若未找到则返回－1
int strindex(char s[],char t[]){
	int i,j,k;
	for(i=0;s[i]!='\0';i++){
		for(j=i,k=0;t[k]!='\0' && s[j]==t[k];j++,k++)
      		;
    if(k>0&&t[k]=='\0'){
    	return i;
        }
    }
    return -1;
}


/*版本2*/
#include <stdio.h>
#include<string.h>
#define MAXLINE 1000

int getline(char *argv[]);

/*find函数：打印与第一个参数指定的模式匹配的行*/
main(int argc,char *argv[]){
	char line[MAXLINE];
	int found=0;

	if(argc != 2){
		printf("Usage: find pattern\n");
	}
	else{
		while(getline(line,MAXLINE)>0){
			if(strstr(line,argv[1])!=NULL){
				/*标准库函数strstr（s,t）返回一个指针
				，该指针指向字符串t在字符串s中第一次出
				现的位置，如果未找到则返回NULL*/
				printf("%s",line);
				found++;
			}
		}
	}
	return found;
}

/*系统中的C语言程序有一个公共的约定:以负号开头的参数
表示一个可选标志或参数。假定用-x（代表“除……之外”)表示打
印所有与模式不匹配的文本行，用-n(代表“行号”）表示打印行
号，那么下列命令:

find -x -n模式
将打印所有与模式不匹配的行，并在每个打印行前面加上行号

可选参数应该允许以任意次序出现，同时，程序的其余部分应
该与命令行中参数的数目无关。此外，如果可选参数能够组合使
用，将会给使用者带来更大的方便，比如:

find -nX模式*/

/*版本3*/
#include<stdio.h>
#include<string.h>
#define  MAXLINE 1000

int getline (char *line,int max);

/*find函数：打印与第一个参数指定的模式匹配的行*/
main(int argc,char *argv[]){
	char line [MAXLINE];
	long lineno =0;

	int c,except=0,number=0,found=0;
	while(--argc>0&&(*++argv)[0]=='-'){
		while(c=*++argv[0]){
			switch (c)
			{
			case 'x':
				except=1;
				break;
			case 'n':
				number=1;
				break;
			default:
				printf("find:illegal option %c\n",c);
				argc=0;
				found=-1;
				break;
			}
		}
	}
	if(argc!=1){
		printf("Usage :find -x -n pattern\n");
	}else{
		while(getline(line,MAXLINE)>0){
			lineno++;
		}
		if((strstr(line,*argv)!=NULL)!=except){
			if(number){
				printf("%ld:",lineno);
			}
			printf("%s",line);
			found++;
		}
	}
	return found;
}


/*版本4*/
#include <stdio.h>
#include <string.h>

#define MAXLINE 100
int mygetline(char s[], int lim);

int main(int argc, char** argv){
	char line[MAXLINE];
	long lineno = 0;
	int except = 0, number = 0, found = 0;
	int bRet = 0;
	int nLine = 0;

	char* pSearch = NULL;

	for (int i = 1; i < argc; i++){
		char* pInd = argv[i];
		if ('-' == *pInd){
			pInd++;
			while (*pInd){
				switch (*pInd){
				case 'n':
					number = 1;
					break;
				case 'x':
					except = 1;
					break;
				default:
					goto FINISH;
				}
				pInd++;
			}
		}else{
			if (NULL == pSearch){
				pSearch = pInd;
			}
		}
	}
	if (NULL == pSearch){
		goto FINISH;
	}
	//开始处理
	nLine = mygetline(line, MAXLINE);
	while (nLine > 0){
		int bPrint = 0;
		lineno++;
		if (NULL != strstr(line, pSearch)){//找到了
			bPrint = !except;
		}
		else{//没找到
			bPrint = except;
		}
		if (bPrint){
			if (number){
				printf("%ld:", lineno);
			}
			printf("%s", line);

			found++;
		}
		nLine = mygetline(line, MAXLINE);
    }
	bRet = 1;
FINISH:
	if (!bRet){
		printf("usage: %s -n -v \'search text\'\n", argv[0]);
	}
	return found;
}

int mygetline(char s[], int lim){//char* p1 = alloc(9);

	int nLeft = lim;
	int i = 0;
	while (nLeft > 1){
		int c = getchar();
		if (EOF == c){
			break;
		}
		else if ('\n' == c){
			s[i++] = c;
			nLeft--;
			break;
		}
		else{
			s[i++] = c;
			nLeft--;
		}
	}
	if (nLeft > 0){
		s[i] = '\0';
	}
	return i;
}
