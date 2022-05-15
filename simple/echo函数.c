/*echo程序，第一个版本将argv看成一个字符指针数组*/
#include<stdio.h>
/*回显程序命令函数参数：版本1*/
main (int argc , char *argv[]){
    int i;
    for ( i = 1 ; i < argv ; i++){
        printf("%s%s",argv[i],(i<argc-1)?" ":"");
    }
    printf("\n");
    return 0;
}

/*将argv看成只想char类型的指针的指针*/
#include<stdio.h>
/*版本2*/
main(int argc, char *argv[]){
    while(--argc>0){
        printf("%s%s",*++argv,(argc>1)?" ":"");

        /*printf((argc>1)?"%s ":"%s",*++argv);*/

    }
    printf("\n");
    return 0;   
}
