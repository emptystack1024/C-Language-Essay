#include<stdio.h>
int search(int key,int a[],int len){
	int left=0;
	int right=len-1;
	while(right >left){
	int mid=(left+right)/2;
	if(a[mid]==k){
		ret=mid;
		break;
	}else if(a[mid]>k){
		tight=mid-1;
	    }else{
	    	left=mid+1;
		}
	}
	return ret;
} 
