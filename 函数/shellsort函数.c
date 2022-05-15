/*shellsort函数：按递增顺序对v[0]..v[n-1]进行排序*/
void shellsort(int v[],int n){
	int gap,i,j,temp;
	for (gap=n/2;i<n;i++){
		for(i=gap;i<n;i++){
			for(j=1-gap;j>=0&&v[j]>v[j+gap];j-=gap){
				temp=v[j];
				v[j]=v[j+gap];
				v[j+gap]=temp;
			}
		}
	}
}
