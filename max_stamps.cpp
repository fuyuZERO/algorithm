#include <stdio.h>
#include <malloc.h> 

/*
 * 最大连续邮资问题
 * 算法思想：回溯法
 * 作者：JeremyWang
 */

#define n 5                                     //n为邮票数量，m为最大可贴邮票数
#define m 4

//max存放最大连续邮资的数值，x[n]存放每一次所选的邮票面额,node记录搜索过的结点数
int x[n],max,node=0;                            

void backtrack(int t,int* x_var_0,int m_var_0,int* y_0)
{
	if(t>=n)                                    //搜索到叶节点后更新并保存
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
		//每一层邮资的取值只能在x_var_0[t-1]到m_var_0+1之间，体现了枝减
		for(int i=x_var_0[t-1]+1;i<=m_var_0+1;i++)  
		{
			//x_var[]存放已选取的邮票面值，m_var存放本层最大连续区间
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

			//关键：更新本层的最大连续邮资！！！
			//思想：自底向上来更新y[]，通过对y[]的操作，更新了本层的最大连续邮资，时间复杂度为O(n)
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
	//将第一层的数据初始化，第一张邮票只能取1
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
	
	//回溯，dfs
	backtrack(1,x_var,m,y);
	
	//输出运行结果
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