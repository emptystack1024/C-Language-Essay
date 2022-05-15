#define ALLOWSIZE 10000/*可用空间大小*/
static char allocbuf[ALLOWSIZE];/*alloc使用的存储区*/
static char *allocp=allocbuf;/*下一个空闲位置*/

char *alloc (int n){/*返回指向n个字符的指针*/
    if(allocbuf+ALLOWSIZE-allocp>=n){/*有足够的空闲空间*/
        allocp+=n;
        return allocp-n;/*分配前的指针p*/
    }else 
        return 0;
}

void afree(char *p){/*释放p指向的存储区*/
    if(p>=allocbuf&&p<allocbuf+ALLOWSIZE)
        allocp=p;
}
