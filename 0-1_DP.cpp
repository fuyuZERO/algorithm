#include <stdio.h>
/*
 * 0-1��������
 * �㷨˼�룺��̬�滮
 * w[]�����Ʒ��������v[]�������Ʒ�ļ�ֵ����󱳰�����10
 * ���ߣ�JeremyWang
 */

int  r[6][11],s[6][11],w[]={2,2,6,5,4},v[]={6,3,5,4,6};

void solude()
{
	int j;
	for(int j=1;j<=10;j++)						//for(for())->����Ĺ�ģ
	{
		for(int i=1;i<=5;i++)		
		{
			if(j<w[i-1])						//"if..else if..if"��>����Ķ�̬��
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
