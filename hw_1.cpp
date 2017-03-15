#include<stdio.h>
#define MAX 1000
#define READFILENAME "input.txt"
#define WRITEFILENAME "output.txt"

int readFile(double *min,double *max,double *NUM);
int writeFile(double result);

int main()
{
	double NUM[MAX],avg,min=10000,max=0,div=0,f1,f2;
	int k,i,n;

	if((n=readFile(&min,&max,NUM))==-1) return 0;
	avg=(max-min)/((double)(n-1));
	double *low=new double[n-1];
	double *high=new double[n-1];

	for(int i=0;i<n-1;i++)
	{
		high[i]=min;
		low[i]=max;
	}

	for(i=0;i<n;i++)
	{
		k=(int)((NUM[i]-NUM[0])/avg);
		if(NUM[i]>high[k])
			high[k]=NUM[i];
		if(NUM[i]<low[k])
			low[k]=NUM[i];
	}

	f1=low[0];
	f2=high[0];
	for(i=0;i<n-1;i++)
	{ 
			if(	high[i]==min);
			else
			{
				f2=low[i];
				if(div<(f2-f1))
				div=f2-f1;
				f1=high[i];
			}
	}
	writeFile(div);
	delete []low;
	delete []high;
	return 0;
}

int readFile(double *min,double *max,double *NUM)
{
	FILE *fp;
	int n,i;
	if((fp=fopen(READFILENAME,"rb"))==NULL)
	{
		printf("open error!\n");
		return -1;
	}
	fscanf(fp,"%d/n",&n);
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%lf ",&NUM[i]);
		if(NUM[i]<*min) *min=NUM[i];
		if(NUM[i]>*max) *max=NUM[i];
	}
	fclose(fp);
	return n;
}

int writeFile(double result)
{
	int i=0;
	FILE *fp;
	if((fp=fopen(WRITEFILENAME,"wb"))==NULL)
	{
		printf("open error!\n");
		return -1;
	}
	fprintf(fp,"%.1lf",result);
	fclose(fp);
	return 0;
}

