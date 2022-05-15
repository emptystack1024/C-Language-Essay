//binsearch函数：在v[0]<=v[1]<=v[2]<=...<=v[n-1]中查找x
int binsearch(int x,int v[],int n){
	int low,high,mid;
	low=0;
	high=n-1;
	while(low<=high){
		mid=(low+high)/2;
		if (x<v[mid]){
			high=mid-1;
		}
		else if(x>v[mid]){
			low=mid+1;
		}
		else /*找到了匹配的值*/
			return mid;
	}
	return -1;
}
