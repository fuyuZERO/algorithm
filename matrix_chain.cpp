#include <stdio.h>
/*
 * �������������ľ������ˣ��㷨����P213
 * �㷨˼�룺��̬�滮
 * ���ߣ�JeremyWang
 */

int  r[7][7],s[6][6],p[10]={30,35,15,5,10,20,25};

void solude()
{
	int j;
	for(int l=2;l<=6;l++)											//����Ĺ�ģ
	{
		for(int i=1;i<=6-l+1;i++)		
		{
			j=i+l-1;
			r[i][j]=100000;
			for(int k=i;k<j;k++)									//����Ķ�̬��
			{
				if(r[i][k]+r[k+1][j]+p[i-1]*p[k]*p[j]<r[i][j])
				{
					r[i][j]=r[i][k]+r[k+1][j]+p[i-1]*p[k]*p[j];
					s[i][j]=k;		
				}
			}

		}
	}
}
void print_solution (int i,int j)
{
	if(i==j)
		printf("A%d",i);
	else
		{
			printf("(");
			print_solution (i,s[i][j]);
			print_solution (s[i][j]+1,j);
			printf(")");
		}
}
int main()
{
	for (int i=0;i<7;i++)
	{
		for (int j=0;j<7;j++)
		{
			r[i][j]=0;
		}
	}
	solude();
	printf("The least operation:%d\n",r[1][6]);
	print_solution(1,6);
	printf("\n");
	return 1;
}
