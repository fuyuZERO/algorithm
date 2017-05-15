#include <stdio.h>
#include <algorithm>
using namespace std;
/*
 * 0-1��������
 * �㷨˼�룺��̬�滮����ά�������Ż�
 * w[]�����Ʒ��������v[]�������Ʒ�ļ�ֵ
 * ���ߣ�JeremyWang
 */

#define n 300                                          			       //n�������ޣ�m��Ʒ��
#define m 10

int  r[n+1],w[]={95,75,23,73,50,22,6,57,89,98},v[]={89,59,19,43,100,72,44,16,7,64},sum[n];

/*
1.��ÿһ�㣬С��w[j]��λ�ò��ø��£���Ϊ�����Ų��£�
2.����ֻ��Ҫ���r[v]��ֵ������ǰһ����Ʒ����ʵֻҪ֪��r[v-w[m-1]]���ɡ��Դ����ƣ�
���Ե�i����������ʵֻ��Ҫ֪����f[v-sum{w[i..n]}]���ɣ��������е�
for i=0..m
for v=V..0
���Ըĳ�
for i=1..m
bound=max{v-sum{w[i..n],w[j]}��
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