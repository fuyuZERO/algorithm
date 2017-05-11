#include <stdio.h>

int binary_search(int *a,int x,int r,int l)
{
	int m;
	while(r>=l)
	{
		m=(r+l)/2;
		if(a[m]==x)
			return m;
		else if(a[m]>x)
			r=m-1;
		else
			l=m+1;		
	}
	return -1;
}

int main()
{
	int a[7]={0,1,2,3,4,7,10};
	printf("The array is:");
	for(int i=0;i<8;i++)
	{
		printf("%d.",a[i]);
	}
	printf("\n");

	//²âÊÔ¶ş·ÖËÑË÷
	printf("3 in the position:%d\n",binary_search(a,10,7,0));

}
