#include <stdio.h>
#include <malloc.h> 

/*
 * ���������������
 * �㷨˼�룺���ݷ�
 * ���ߣ�JeremyWang
 */

#define n 5                                     //nΪ��Ʊ������mΪ��������Ʊ��
#define m 4

//max�������������ʵ���ֵ��x[n]���ÿһ����ѡ����Ʊ���,node��¼�������Ľ����
int x[n],max,node=0;                            

void backtrack(int t,int* x_var_0,int m_var_0,int* y_0)
{
	if(t>=n)                                    //������Ҷ�ڵ����²�����
	{
		if(m_var_0>max)
		{
			max=m_var_0;
			for(int i=0;i<n;i++)
			{
				x[i]=x_var_0[i];
			}
		}
		return;
	}
	else
	{
		//ÿһ�����ʵ�ȡֵֻ����x_var_0[t-1]��m_var_0+1֮�䣬������֦��
		for(int i=x_var_0[t-1]+1;i<=m_var_0+1;i++)  
		{
			//x_var[]�����ѡȡ����Ʊ��ֵ��m_var��ű��������������
			int m_var,*x_var,*y;
			x_var=(int*)malloc(sizeof(int)*n);
			y=(int*)malloc(sizeof(int)*2000); 
			for(int k=0;k<n;k++)
			{
				x_var[k]=x_var_0[k];
			}
			for(int k=0;k<2000;k++)
			{
				y[k]=y_0[k];
			}

			x_var[t]=i;

			//�ؼ������±��������������ʣ�����
			//˼�룺�Ե�����������y[]��ͨ����y[]�Ĳ����������˱��������������ʣ�ʱ�临�Ӷ�ΪO(n)
			for(int j=0;j<x_var[t]*m;j++)
			{
				if(y[j]<m)
				{  
					for(int num=1;num<=m-y[j];num++)  
						if(y[j]+num<y[j+i*num])  
							y[j+i*num]=y[j]+num;  
		        }  
		    }  
		    m_var = m_var_0;  
	        while(y[m_var+1]<=m) m_var++;  
			
			backtrack(t+1,x_var,m_var,y);

			node++;
			free(x_var);
		    free(y);
		 } 
	 }
}

int main()
{
	//����һ������ݳ�ʼ������һ����Ʊֻ��ȡ1
	int *x_var=(int*)malloc(sizeof(int)*n);
	int *y=(int*)malloc(sizeof(int)*2000);
	x_var[0]=1;
	for(int i=1;i<n;i++)
	{
		x_var[i]=0;
	}
	for(int i=0;i<=m;i++)
		y[i]=i;
	for(int i=m;i<2000;i++)
		y[i]=100;
	
	//���ݣ�dfs
	backtrack(1,x_var,m,y);
	
	//������н��
	printf("The max stamps:%d\n",max);
	printf("The selected stamps is:");
	for(int i=0;i<n;i++)
	{
		printf("%d.",x[i]);
	}
	printf("\n");
	printf("nodes:%d\n",node);

	free(x_var);
    free(y);
	return 0;
}