#include <stdio.h>
#include <algorithm>
using namespace std;
/*
 * 0-1背包问题
 * 算法思想：动态规划，降维，常数优化
 * w[]存放物品的重量，v[]存放了物品的价值
 * 作者：JeremyWang
 */

#define n 300                                          			       //n背包上限，m物品数
#define m 10

int  r[n+1],w[]={95,75,23,73,50,22,6,57,89,98},v[]={89,59,19,43,100,72,44,16,7,64},sum[n];

/*
1.对每一层，小于w[j]的位置不用更新，因为根本放不下；
2.由于只需要最后r[v]的值，倒推前一个物品，其实只要知道r[v-w[m-1]]即可。以此类推，
对以第i个背包，其实只需要知道到f[v-sum{w[i..n]}]即可，即代码中的
for i=0..m
for v=V..0
可以改成
for i=1..m
bound=max{v-sum{w[i..n],w[j]}；
*/

void solude()
{
	sum[m]=w[m];
	for(int i=m-1;i>=0;i--)
	    sum[i]=w[i]+sum[i+1];
	for(int j=0;j<m;j++)			              			
	{
		for(int i=n,k=max(n-sum[j],w[j]);i>=k;i--)		
		{
			if(r[i]<r[i-w[j]]+v[j])
				r[i]=r[i-w[j]]+v[j];
		}
	}
}

int main()
{
	for(int i=0;i<=n;i++)
		r[i]=0;
	solude();
	printf("The max package:%d\n",r[n]);
	return 1;
}