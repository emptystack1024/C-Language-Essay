/*strcpy函数：将指针t指向的字符串复制到指针s指向的位置，使用数组下标实现的版本*/
void strcpy(char* s,char* t){
    int i;
    i=0;
    while((s[i]=t[i])!='\0'){
        i++;
    }
}

/*strcpy函数：将指针t指向的字符串复制到指针s之乡的位置，用指针方式实现的版本1*/
#include<stdio.h>
void strcpy(char* s,char *t){
    while((*s=*t)!='\0'){
        s++;
        t++;
    }
}

/*strcpy函数：将指针t指向的字符串复制到指针s之乡的位置，用指针方式实现的版本2*/
void strcpy(char *s,char *t){
    while((*s++=*t++)!='\0'){
        ;
    }
}

/*strcpy函数：将指针t指向的字符串复制到指针s之乡的位置，用指针方式实现的版本3*/

void strcpy(char *s,char *t){
    while(*s++=*t++)
        ;
}
