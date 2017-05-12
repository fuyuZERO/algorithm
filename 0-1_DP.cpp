#include <stdio.h>
/*
 * 0-1背包问题
 * 算法思想：动态规划
 * w[]存放物品的重量，v[]存放了物品的价值，最大背包容量10
 * 作者：JeremyWang
 */

int  r[6][11],s[6][11],w[]={2,2,6,5,4},v[]={6,3,5,4,6};

void solude()
{
	int j;
	for(int j=1;j<=10;j++)						//for(for())->问题的规模
	{
		for(int i=1;i<=5;i++)		
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
	for (int i=0;i<6;i++)
	{
		for (int j=0;j<11;j++)
		{
			r[i][j]=0;
			s[i][j]=0;
		}
	}
	solude();
	printf("The max package:%d\n",r[5][10]);
	print_solution(5,10);
	printf("\n");
	return 1;
}
