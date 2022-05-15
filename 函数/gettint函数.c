#include <stdio.h>
#define BUFSIZE 100
/*gettint函数：将输入中的下一个整型数赋值给*pn*/
int getch(void);
void ungetch(int);

char buf[BUFSIZE];//用于ungetch函数的缓冲区
int bufp=0;//buf中下一个空闲位置

int getint (int *pn){
    int c,sign;
    
    while (isspace (c=getch()))/*跳过空白符*/
        ;
    if(!isdigit(c)&&c!=EOF&&c!='+'&&c!='-'){
        ungetch(c);/*输入不是一个数字*/
        return 0;
    }
    sign=(c=='-')?-1:1;
    if(c=='+'||c=='-')
        c=getch();
    for(*pn=0;indigit(c);c=getch())
        *pn=10* *pn +(c-'0');
    *pn *= sign;
    if(c!=EOF)
        ungetch(c);
    return c;
}

int getch(void){//取一个字符（可能是压回的字符)
	return (bufp>0)?buf[--bufp]:getchar();
	}

void ungetch(int c)//把字符压回到输入中
{
	if (bufp>=BUFSIZE)
  		printf("ungetch:too many characters\n");
	else
  		buf[bufp++]=c;
}
