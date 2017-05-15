#include <stdio.h>
/*
 * 0-1背包问题
 * 算法思想：动态规划
 * w[]存放物品的重量，v[]存放了物品的价值，最大背包容量10
 * 作者：JeremyWang
 */

#define n 300                                          			       //n背包上限，m物品数
#define m 10

int  r[m+1][n+1],s[m+1][n+1],w[]={95,75,23,73,50,22,6,57,89,98},v[]={89,59,19,43,100,72,44,16,7,64};

void solude()
{
	int j;
	for(int j=1;j<=n;j++)			              			//for(for())->问题的规模
	{
		for(int i=1;i<=m;i++)		
		{
			if(j<w[i-1])						//"if..else if..if"—>问题的动态性
			{
				r[i][j]=r[i-1][j];
				s[i][j]=1;
			}
			else if(r[i-1][j]>r[i-1][j-w[i-1]]+v[i-1])
			{
				r[i][j]=r[i-1][j];
				s[i][j]=1;
			}
			else
			{
				r[i][j]=r[i-1][j-w[i-1]]+v[i-1];
				s[i][j]=2;
			}
		}
	}
}


void print_solution (int i,int j)
{
	if(i==0)
		return;
	else if(s[i][j]==2)
	{
		printf("%d.",i);
		i-=1;
		j-=w[i-1];
		print_solution(i,j);
	}
	else
	{
		i-=1;
		print_solution(i,j);
	}
}


int main()
{
	for (int i=0;i<m+1;i++)
	{
		for (int j=0;j<n+1;j++)
		{
			r[i][j]=0;
			s[i][j]=0;
		}
	}
	solude();
	printf("The max package:%d\n",r[m][n]);
	print_solution(m,n);
	printf("\n");
	return 1;
}
