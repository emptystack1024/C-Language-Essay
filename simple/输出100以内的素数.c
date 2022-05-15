#include<stdio.h>

int main(){
	int x;

	for(x=2;x<100;x++){
		int i;
	    int y=1;
	    for(i=2;i<x;i++){
		    if(x%i==0){
		    	y=0;
		        break;
		    }
	    }
	        if(y==1){
	           	printf("%d\n",x);
	           
	        }
			

}
	return 0;
}


/*输出前50个素数*/
/*if*/
/*
#include<stdio.h>

int main(){
	int x;
	int t=0;
	for(x=2;x<1000;x++){
		int i;
	    int y=1;
	    for(i=2;i<x;i++){
		    if(x%i==0){
		    	y=0;
		        break;
		    }
        }
	        if(y==1){
	           	printf("%d\n",x);
	           	t++;
	            }
	        if(t==50){
	        	break;
			}

}
	return 0;
}
*/

/*while*/
/*
#include<stdio.h>

int main(){
	int x;
	x=2;
	int cnt=0;
	while(cnt<50){
		int i;
	    int y=1;
	    for(i=2;i<x;i++){
		    if(x%i==0){
		    	y=0;
		        break;
		        }
	        }
	        if(y==1){
	           	printf("%d\n",x);
	           	cnt++;
	        }
		    x++;
}
    printf("\n");
	return 0;
}
*/
