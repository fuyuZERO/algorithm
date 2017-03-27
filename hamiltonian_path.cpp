#include <iostream>
#include <stdio.h>
using namespace std;
const int V = 5;

void printSolution(int path[])
{
    printf ("Solution Exists:"
            " Following is one Hamiltonian Cycle \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", path[i]);

    printf(" %d ", path[0]);
    printf("\n");
}

//path记录路径，visited记录顶点是否访问过，len记录当前路径的长度
bool hamCycleRecall(int graph[V][V], int path[V], bool visited[V],int len){
	if(len == V){ //访问到最后一个顶点
		if( graph[ path[V-1] ][0] == 1) //有到0点的边
			return true;
		else
			return false;
	}
	//遍历其它顶点
	for(int v = 1; v<V; v++){
		//如果没访问过，并且有边相连
		if(!visited[v] && graph[ path[len-1] ][v] ==1){
			visited[v] = true;
			path[len] = v;

			//找到了就直接返回
			if( hamCycleRecall(graph, path, visited, len+1) )
				return true;

			path[len] = -1;
			visited[v] = false;
		}
	}
	return false;
}

//查找从第一个顶点0开始，能否找到一条哈密顿回路。
bool hamCycle(int graph[V][V]){
	int path[V] = {-1};
	bool visited[V] = {0};
	path[0] = 0; 
	visited[V] = true; //第一个顶点标记为访问过

	//第一个顶点已确定，len从1开始
	if( hamCycleRecall(graph, path,visited, 1) == false){
		 printf("\nSolution does not exist");
		 return false;
	}

	printSolution(path);
	return true;
}

//测试
int main() {
/* 创建以下的图
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)-------(4)    */
	 int graph[V][V] = {{0, 1, 0, 1, 0},
	                      {1, 0, 1, 1, 1},
	                      {0, 1, 0, 0, 1},
	                      {1, 1, 0, 0, 1},
	                      {0, 1, 1, 1, 0},
	                     };

	hamCycle(graph);
	return 0;
}