#include <stdio.h>
#include <stdlib.h>
#define N 6
   int arr[N]={32,12,7, 78, 23,45};
void exchange(int *arr, int a, int b){
	int tem;
	tem=arr[a];
	arr[a]=arr[b];
	arr[b]=tem;
}
int partition(int *arr, int low, int high){
	int x,i,j;
	x=arr[high];
	i=low-1;
	for(j=low;j<high;j++)
	{
		if(arr[j]<x)
		{
			i=i+1;
			exchange(arr,i,j);
		}
	}
	exchange(arr,i+1,high);
	return i+1;
}
void quick_sort(int *arr, int start, int end){
    int pos;
    if (start<end){
        pos = partition(arr, start, end);
        quick_sort(arr,start,pos-1);
        quick_sort(arr,pos+1,end);
    }
    return;
}
int main(void){
    int i;
    printf("before sort:\n");
    for(i=0;i<N;i++)
        printf("%d\t",arr[i]);
    quick_sort(arr,0,N-1);
    printf("\nafter sort:\n");
    for(i=0; i<N; i++)
        printf("%d\t", arr[i]);
    printf ("\n");
    system("pause");
    return 0;
}
