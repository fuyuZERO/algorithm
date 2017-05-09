#include<stdio.h>

#include <stdlib.h>

/*
* 最小重量机器设计问题
* 算法思想：启发式搜索，回溯法，优先队列由二叉堆维护
* 作者：JeremyWang
*/

int c[3][3]={{1,2,3},{3,2,1},{2,2,2}},w[3][3]={{1,2,3},{3,2,1},{2,2,2}},m,n,d,ss,s[3];

struct Node;
struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

//定义一个搜索节点
struct Node
{
	int wn; //当前的总重量，启发函数
	int cn; //当前的总价格
	int cs; //搜索树中的层数
	int l[3]; //记录之前搜索的节点
};

//定义一个二叉堆,堆中每一个元素是一个Node,按Node.wn排序的最小堆
struct HeapStruct
{
	int Capacity;
	int Size;
	struct Node *Fringe;
};

//Insert(上滤)向二叉堆插入一个元素，DeleteMin(下滤)从二叉堆删除一个元素
void Insert(struct Node N,PriorityQueue H)
{
	int i;
	for (i=++H->Size;H->Fringe[i/2].wn>N.wn;i/=2)
	H->Fringe[i]=H->Fringe[i/2];
	H->Fringe[i]=N;
}
struct Node DeleteMin(PriorityQueue H)
{
	int i,Child;
	struct Node MinNode,LastNode;

	MinNode=H->Fringe[1];
	LastNode=H->Fringe[H->Size--];

	for(i=1;i*2<=H->Size;i=Child)
	{
		Child=i*2;
		if(Child!=H->Size&&H->Fringe[Child+1].wn<H->Fringe[Child].wn)
        Child++;

	    if(LastNode.wn>H->Fringe[Child].wn)
	    H->Fringe[i]=H->Fringe[Child];
		 else
			 break;
	}
	H->Fringe[i]=LastNode;
	return MinNode;
}

int main()
{
	d=4;

	PriorityQueue H;
	H=(PriorityQueue)malloc(sizeof(struct HeapStruct));
	H->Capacity=39;
	H->Size=0;
	H->Fringe=(Node*)malloc(39*sizeof(struct Node));

	struct Node a={5,1,1,{1,0,0}};
	struct Node b={6,2,1,{2,0,0}};
	struct Node f={7,3,1,{3,0,0}};

	Insert(a,H);
	Insert(b,H);
	Insert(f,H);

	while(1)
	{
	    struct Node X=DeleteMin(H);
		ss=X.wn;
		for(int i=0;i<3;i++)
	    {
			s[i]=X.l[i];
		}
	    printf("delete wn:%d\n",X.wn);
		for(int i=0;i<3;i++)
		{
	       printf("%d.",s[i]);
		}
		printf("\n");
		if(X.cs>=3)                                        //已经搜索到树的底部
			break;
		for(int i=0;i<3;i++)
		{
			if(c[X.cs][i]+X.cn<=d)                                  //减枝条件是重量不超d
		   {
			 s[X.cs]=i+1;
			 struct Node Y={X.wn+w[X.cs][i]-2,c[X.cs][i],X.cs+1,{s[0],s[1],s[2]}};//将可以扩展的节点插入优先队列
		     Insert(Y,H);
			 printf("insert wn:%d,cn:%d\n",Y.wn,Y.cn);
             for(int i=0;i<3;i++)
				{
					printf("%d.",s[i]);
		        }
                printf("\n");
           }
         }
       }

	   printf("Total Weight:%d\n",ss);
	   printf("Choice Company:\n");
	   for(int i=0;i<3;i++)
	   {
	     printf("%d.",s[i]);
	   }
	   printf("\n");

	   free(H->Fringe);
	   free(H);    
}