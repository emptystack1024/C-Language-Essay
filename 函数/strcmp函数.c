/*strcmp：根据s按照字典顺序大于小于或等于t的结果分别返回负整数正整数0*/
int strcmp(char *s,char *t){
    int i;

    for(i=0;s[i]==t[i];i++){
        if(s[i]=='\0'){
            return 0;
        }
    }
    return s[i]-t[i];
}


int strcmp(char *s,char *t){
    for( ;*s=*t;s++,t++){
        if(*s=='\0'){
            return 0;
        }
    }
    return *s-*t;
}

/*简化理解版本*/
int strcmp(char *d,char *s){
    while(*d==*s){
        if('\0'==*d){
            return 0;
        }
        d++;
        s++;
    }
    return (*d-*s);
}

/*如果只想比较前n个字符*/
int strcmp(char *d,char *s,int n){
    if(n>=0){
        while(n--&&(*d==*s)){
            if('\0'==*d){
                return 0;
            }
            d++;
            s++;
        }
        if(n<0){
            return 0;
        }
        else{
            return (*d-*s);
        }
    }
    return -1;
}
