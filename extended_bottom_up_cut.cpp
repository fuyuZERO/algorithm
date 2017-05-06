#include <stdio.h>
/*
 * 带输出解决方案的钢条切割问题，算法导论209
 * 算法思想：动态规划
 * 作者：JeremyWang
 */

int  r[11],s[10],p[10]={1,5,8,9,10,17,17,20,24,30},n;

void cut_rod()
{
	for(int i=0;i<n;i++)			//问题的规模
	{
		for(int j=0;j<=i;j++)		//问题的动态性
		{
			if(r[i+1]<p[j]+r[i-j])
			{
				r[i+1]=p[j]+r[i-j];
				s[i]=j+1;
			}
		}
	}
}
void print_solution ()
{
	while(n>0)
	{
		printf("%d..",s[n-1]);
		n-=s[n-1];
	}
}
int main()
{
	for (int i=0;i<11;i++)
	{
		r[i]=0;
	}
	printf("Please enter the lenth of steal bar:");
	scanf("%d",&n);
	cut_rod();
	printf("The best money:%d\n",r[n]);
	print_solution();
	return 1;
}

