#include <stdio.h>
/*
 *使用“分治”的思想求一个数组的最大子数组
 *使用结构体作为返回值，算法导论P40
 *作者：JeremyWang
 */
 struct subarray
 {
	 int low;
	 int high;
	 int sum;
 };

 struct subarray find_cross_subarray(int *a,int low,int mid,int high)
 {
	 int sum=0,lsum=-1000,rsum=-1000,mlow,mhigh;
	 for(int i=mid;i>=low;i--)
	 {
		sum+=a[i];
		if(sum>lsum)
		{
			lsum=sum;
			mlow=i;
		}
	 }
	 sum=0;
	 for(int j=mid+1;j<=high;j++)
	 {
		sum+=a[j];
		if(sum>rsum)
		{
			rsum=sum;
			mhigh=j;
		}
	 }
	 struct subarray A={mlow,mhigh,lsum+rsum};
	 return A;
 };
 struct subarray find_maxmum_subarray(int *a,int low,int high)
 {
	int mid;
	struct subarray L,H,C;
	if(low==high)
	 {

		struct subarray A={low,low,a[low]};
		return A;
	 }
	else
    {
		mid=(low+high)/2;
		//分治
		L=find_maxmum_subarray(a,low,mid);
		H=find_maxmum_subarray(a,mid+1,high);
		C=find_cross_subarray(a,low,mid,high);
		//将子问题合并
		if(L.sum>=H.sum&&L.sum>=C.sum)
			return L;
		else if(H.sum>L.sum&&H.sum>C.sum)
			return H;
		else
			return C;
	}
 };
 int main()
 {
	int a[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	printf("The array is:");
	for(int i=0;i<16;i++)
    {
		printf("%d.",a[i]);
	}
	printf("\n");

	struct subarray A=find_maxmum_subarray(a,0,15);
    printf("low=%d,high=%d,sum=%d",A.low,A.high,A.sum);
	printf("\n");
 }