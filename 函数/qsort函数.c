/*qsort函数：以递增的顺序对数组v[left]...v[right]排序*/

void swap(int v[],int i,int j){
    int temp;
    temp=v[i];
    v[i]=v[j];
    v[j]=temp; 
}

void qsort (int v[],int left,int right){
    int i,last;
    void swqp(int v[],int i,int j);
    if(left >= right ){/*若数组包含的元素数小于2*/
        return ;/*则不执行任何操作*/
    }
    swap(v,left,(left+right)/2);/*将划分子集的元素*/
    last =left;/*移动到v[0]*/
    for(i=left+1;i<=right;i++){/*划分子集*/
        if(v[i]<v[left]){
            swap(v,++last,i);/*恢复划分子集的元素*/
        }
    }
    swap(v,left,last);
    qsort(v,left,last-1);
    qsort(v,last+1,right);
}
