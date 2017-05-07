#include <stdio.h>
/*
 * 带输出解决方案的最长公共子序列，算法导论P224
 * 算法思想：动态规划
 * 作者：JeremyWang
 */

int  r[8][7],s[8][7],X[7]={1,2,3,2,4,1,2},Y[7]={2,4,3,1,2,1};

void solude()
{
	for(int i=1;i<8;i++)											//问题的规模
	{
		for(int j=1;j<7;j++)										
		{
			if(X[i-1]==Y[j-1])										//问题的动态性
			{
				r[i][j]=r[i-1][j-1]+1;
				s[i][j]=1;
			}
			else if(r[i-1][j]>=r[i][j-1])
			{
				r[i][j]=r[i-1][j];
				s[i][j]=2;
			}
			else
			{
				r[i][j]=r[i][j-1];
				s[i][j]=3;
			}
		}
	}
}
void print_solution (int i,int j)
{
	if(i==0||j==0)
		return;
	else if(s[i][j]==1)
	{
		print_solution(i-1,j-1);
		printf("%d.",X[i-1]);
	}
	else if(s[i][j]==2)
	{
		print_solution(i-1,j);
	}
	else
		print_solution(i,j-1);
}
int main()
{
	for (int i=0;i<8;i++)
	{
		for (int j=0;j<7;j++)
		{
			r[i][j]=0;
		}
	}
	solude();
	printf("the original sequence:\n");
	for (int i=0;i<7;i++)
	{
		printf("%d.",X[i]);
	}
	printf("\n");
	for (int i=0;i<6;i++)
	{
		printf("%d.",Y[i]);
	}
	printf("\n");
	printf("The longest common subsequence:%d\n",r[7][6]);
		printf("The longest common subsequence is:");
	print_solution(7,6);
	printf("\n");
	return 1;
}