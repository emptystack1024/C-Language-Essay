//逆波兰计算器
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>//为了使用atof函数

#define MAXOF 100//操作数或运算符最大长度
#define NUMBER  '0' //标识找到一个数
#define MAXVAL 100
#define BUFSIZE 100

char buf[BUFSIZE];//用于ungetch函数的缓冲区
int bufp=0;//buf中下一个空闲位置

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int );
main(){
	int type;
	double op2;
	char s[MAXOF];

while((type=getop(s))!=EOF){
  	switch (type){
    	case NUMBER:
      		push(atof(s));
      		break;
    	case '+':
     		push(pop()+pop());
     		break;
    	case '*':
    		push(pop()*pop());
    		break;
    	case '-':
    		op2=pop();
    		push(pop()/op2);
    		break;
    	case '/':
    		op2=pop();
    		if (op2!=0.0){
        		push(pop()/op2);
        		}	
      		else
        		printf("error:zero divisor\n");
     			break;
    	case '\n':
     		printf("\t%.8g\n",pop());
     		break;
    	default:
    		printf("error:unknown command %s\n",s);
      		break;
    	}
}
return 0;
}

int getop(char s[]){
	int i,c;
	while ((s[0]=c=getch())==' '||c=='\t')
  		;
	s[1]='\0';
	if(!isdigit(c)&&c!='-')
  		return c;//不是数
	i=0;
	if (isdigit(c))
  		while(isdigit(s[++i]=c=getch()))
    		;
    if(c=='.')//收集小数部分 
    	while (isdigit(s[++i]=c=getch()))
    		;
	s[i]='\0';
	if (c!= EOF )
  		ungetch(c);
	return NUMBER;
} 

int sp=0;
double val[MAXVAL];

void push(double f){
	if (sp<MAXVAL){
  		val[sp++]=f;
		}
	else
  		printf("error : stack full,can't push %g\n");
}

double pop(void){
	if (sp>0)
  		return val[--sp];
  	
	else {
 		printf("error:stack rmpty\n");
 		return 0.0;
	}
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


//逆波兰计算器

/*  ***  代表第一次修改-->/**/
/*  ***  代表第二次修改-->/***/

/*实现目标：如果有另一个人需要在你输入时要紧急计算，能暂存你的计算
，然后先运行他的运算*/
/*
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>//为了使用atof函数

#define MAXOF 100//操作数或运算符最大长度
#define NUMBER  '0' //标识找到一个数
#define MAXVAL 100
#define BUFSIZE 100

char buf[BUFSIZE];//用于ungetch函数的缓冲区
int bufp=0;//buf中下一个空闲位置

int g_esp=MAXVAL-1;/***//*栈的移动的指针*/
int g_ebp=MAXVAL-1;/***//*栈的固定的指针*/
double val[MAXVAL];/***/
int g_esp_a;/**//*为了实现目的的第二指针*/
int g_ebp_a; /**/

void start();/**//*具体实现目标的函数*/
void end();/**/

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int );
main(){
	int panduan=0;/**/
	int type;
	double op2;
	char s[MAXOF];

	while((type=getop(s))!=EOF){
  		switch (type){
    		case NUMBER:
      			push(atof(s));
      			break;
    		case '+':
    	 		push(pop()+pop());
     			break;
    		case '*':
    			push(pop()*pop());
	    		break;
    		case '-':
    			op2=pop();
    			push(pop()/op2);
	    		break;
    		case '/':
    			op2=pop();
    			if (op2!=0.0){
        			push(pop()/op2);
	        		}	
    	  		else
        			printf("error:zero divisor\n");
     				break;
     		case 'a':/**//*当输入a时转入新的运算*//*必须是‘ ’+‘a’才行*/
     			start();/**/
     			panduan=1;/**//*判断运算的情况*/
     			getch();/**//*为了吞掉‘a’后的那个回车也就是‘\n’*/
     			break;/**/
    		case '\n':
	     		printf("\t%.8g\n",pop());
	     		if(panduan==1){/**/
	     			printf("end:");/**/
	     			end();/**/
				}/**/
    	 		break;
    		default:
	    		printf("error:unknown command %s\n",s);
    	  		break;
    		}
	}
	return 0;
}

int getop(char s[]){
	int i,c;
	while ((s[0]=c=getch())==' '||c=='\t')
  		;
	s[1]='\0';
	if(!isdigit(c)&&c!='-')
  		return c;//不是数
	i=0;
	if (isdigit(c))
  		while(isdigit(s[++i]=c=getch()))
    		;
    if(c=='.')//收集小数部分 
    	while (isdigit(s[++i]=c=getch()))
    		;
	s[i]='\0';
	if (c!= EOF )
  		ungetch(c);
	return NUMBER;
} 

int sp=0;

void push(double f){/**/
	if(g_esp>0){/**/
		val[g_esp]=f;/**/
		g_esp--;/**/
	}/**/
	else{/**/
		printf("stack overflow\n");/**/
	}/**/
}

double pop(void){/**/
	if(g_esp==(MAXVAL-1)){/**/
		printf("stack empty\n");/**/
		return 0.0;/**/
	}/**/
	else{/**/
		g_esp++;/**/
		double f=val[g_esp];/**/
		return f;/**/
	}/**/
}/**/

void start(){
	g_esp_a=g_esp;
	g_ebp_a=g_ebp;
	g_ebp=g_esp;
}

void end(){
	g_esp=g_esp_a;
	g_ebp=g_ebp_a;
	
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
*/

  
 //逆波兰计算器

/*  ***  代表第一次修改-->/**/
/*
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>//为了使用atof函数

#define MAXOF 100//操作数或运算符最大长度
#define NUMBER  '0' //标识找到一个数
#define MAXVAL 100
#define BUFSIZE 100

char buf[BUFSIZE];//用于ungetch函数的缓冲区
int bufp=0;//buf中下一个空闲位置

int g_esp=MAXVAL-1;/**/
int g_ebp=MAXVAL-1;/**/
double val[MAXVAL];/**/


void start();/**/
void end();/**/

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int );
main(){
	int panduan=0;/**/
	int type;
	double op2;
	char s[MAXOF];

	while((type=getop(s))!=EOF){
  		switch (type){
    		case NUMBER:
      			push(atof(s));
      			break;
    		case '+':
    	 		push(pop()+pop());
     			break;
    		case '*':
    			push(pop()*pop());
	    		break;
    		case '-':
    			op2=pop();
    			push(pop()/op2);
	    		break;
    		case '/':
    			op2=pop();
    			if (op2!=0.0){
        			push(pop()/op2);
	        		}	
    	  		else
        			printf("error:zero divisor\n");
     				break;
     		case 'a':/**/
     			start();/**/
     			panduan++;/**//*1*/
     			printf("start:");/**//*1*/
     			getch();/**/
     			break;/**/
    		case '\n':
	     		printf("\t%.8g\n",pop());
	     		if(panduan>0){/**//*1*/
	     			panduan--;/*1*/
	     			printf("end:");/**/
	     			end();/**/
				}/**/
    	 		break;
    		default:
	    		printf("error:unknown command %s\n",s);
    	  		break;
    		}
	}
	return 0;
}

int getop(char s[]){
	int i,c;
	while ((s[0]=c=getch())==' '||c=='\t')
  		;
	s[1]='\0';
	if(!isdigit(c)&&c!='-')
  		return c;//不是数
	i=0;
	if (isdigit(c))
  		while(isdigit(s[++i]=c=getch()))
    		;
    if(c=='.')//收集小数部分 
    	while (isdigit(s[++i]=c=getch()))
    		;
	s[i]='\0';
	if (c!= EOF )
  		ungetch(c);
	return NUMBER;
} 

int sp=0;

void push(double f){/**/
	if(g_esp>0){/**/
		val[g_esp]=f;/**/
		g_esp--;/**/
	}/**/
	else{/**/
		printf("stack overflow\n");/**/
	}/**/
}

double pop(void){/**/
	if(g_esp==(MAXVAL-1)){/**/
		printf("stack empty\n");/**/
		return 0.0;/**/
	}/**/
	else{/**/
		g_esp++;/**/
		double f=val[g_esp];/**/
		return f;/**/
	}/**/
}/**/

void start(){/**//*1*/
	push(g_esp);/**//*1*/
	push(g_ebp);/**//*1*/
}/**//*1*/

void end(){/**//*1*/
	g_ebp=(int)pop();/**//*1*/
	g_esp=(int)pop();/**//*1*/
	
}/**//*1*/

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

*/ 
