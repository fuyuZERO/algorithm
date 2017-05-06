#include<stdio.h>

#define READFILENAME "input.txt"
#define WRITEFILENAME "output.txt"

int A[8][8],m,n,s;

int legal(int t)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<t;j++)
		{
			if(A[t][i]==A[j][i])
			return 0;
		}
	}
	return 1;
}

void swap(int t,int p,int i)
{
	int x;
	x=A[t][p];
	A[t][p]=A[t][i];
	A[t][i]=x;
}

void print()
{
	printf("_______%d_______\n",s);
	printf("%d,%d,%d\n",A[0][0],A[0][1],A[0][2]);
	printf("%d,%d,%d\n",A[1][0],A[1][1],A[1][2]);
	printf("%d,%d,%d\n",A[2][0],A[2][1],A[2][2]);
	printf("________________\n");
}

void backtrack(int t,int p)
{
	if(t>=m)
	{
		s++;
	    print();
	}
	else
	{
		if(p>n-1)
		{
			if(legal(t))backtrack(t+1,0);
		}
		else
		{
			for(int i=p;i<=n-1;i++)
			{
				swap(t,p,i);
				backtrack(t,p+1);
				swap(t,p,i);
			}
		}
	}
}

int readFile()
{
	FILE *fp;
	if((fp=fopen(READFILENAME,"rb"))==NULL)
	{
		printf("open error!\n");
		return -1;
	}
	fscanf(fp,"%d %d/n",&m,&n);
	if(m<1||m>8||n<1||n>8||m>n)
	{
		printf("value error!\n");
		return -1;
	}
	fclose(fp);
	return 0;
}

int writeFile()
{
	FILE *fp;
	if((fp=fopen(WRITEFILENAME,"wb"))==NULL)
	{
		printf("open error!\n");
		return -1;
	}
	fprintf(fp,"%d",s);
	fclose(fp);
	return 0;
}

int main()
{
	for (int i=0;i<8;i++)
	{
		for (int j=0;j<8;j++)
		{
			A[i][j]=j+1;
		}
	}
	s=0;
	if(readFile()==-1) return 0;
	backtrack(0,0);
	if(writeFile()==-1) return 0;
	printf("%d,%d,%d",m,n,s);
	return 0;
}