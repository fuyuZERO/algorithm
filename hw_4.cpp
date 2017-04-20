#include<stdio.h>
#include<process.h>

#define READFILENAME "input.txt"
#define WRITEFILENAME "output.txt"
#define MAX 100

int NUM[MAX];

/********************************读取文件********************************/
int readFile(int *k,int *sum)
{
	FILE *fp;
	int i;
	if((fp=fopen(READFILENAME,"rb"))==NULL)
	{
		printf("open error!\n");
		return -1;
	}
	fscanf(fp,"%d/n",k);
	for(i=0;i<*k;i++)
	{
		fscanf(fp,"%d ",&NUM[i]);
		*sum+=NUM[i];
	}
	fclose(fp);
	return 0;
}

/********************************输出文件********************************/
int writeFile(double result)
{
	FILE *fp;
	if((fp=fopen(WRITEFILENAME,"wb"))==NULL)
	{
		printf("open error!\n");
		return -1;
	}
	fprintf(fp,"%f",result);
	fclose(fp);
	return 0;
}

/********************************递归函数********************************/
int min(int k,int sum,double *result)
{
	int i,j,p,pval;
	double lval=0.0,rval=0.0,val=0.0,nval;
	for(i=0;i<k;i++)
	{
		p=0;
		pval=0;
		for(j=0;j<k;j++)
			if(NUM[j]>pval)
			{
				p=j;
				pval=NUM[j];
			}
		NUM[p]=-1;
		nval=1.0*pval/sum;
		if(lval<rval)
		{
			*result+=lval*nval;
			lval+=val+nval;
			rval+=nval*(i+1);
		}
		else
		{
			*result+=rval*nval;
			rval+=val+nval;
			lval+=nval*(i+1);
		}
		val+=nval;
	}
	return 0;
}

/********************************主函数********************************/
int main()
{
	int k,sum=0,i;
	double result=0.0;
	if(readFile(&k,&sum)==-1) return 0;
	min(k,sum,&result);
	if(writeFile(result)==-1) return 0;
	printf("SUCCESS\n");
	system("notepad output.txt");
	return 0;
}