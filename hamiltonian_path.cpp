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

//path��¼·����visited��¼�����Ƿ���ʹ���len��¼��ǰ·���ĳ���
bool hamCycleRecall(int graph[V][V], int path[V], bool visited[V],int len){
	if(len == V){ //���ʵ����һ������
		if( graph[ path[V-1] ][0] == 1) //�е�0��ı�
			return true;
		else
			return false;
	}
	//������������
	for(int v = 1; v<V; v++){
		//���û���ʹ��������б�����
		if(!visited[v] && graph[ path[len-1] ][v] ==1){
			visited[v] = true;
			path[len] = v;

			//�ҵ��˾�ֱ�ӷ���
			if( hamCycleRecall(graph, path, visited, len+1) )
				return true;

			path[len] = -1;
			visited[v] = false;
		}
	}
	return false;
}

//���Ҵӵ�һ������0��ʼ���ܷ��ҵ�һ�����ܶٻ�·��
bool hamCycle(int graph[V][V]){
	int path[V] = {-1};
	bool visited[V] = {0};
	path[0] = 0; 
	visited[V] = true; //��һ��������Ϊ���ʹ�

	//��һ��������ȷ����len��1��ʼ
	if( hamCycleRecall(graph, path,visited, 1) == false){
		 printf("\nSolution does not exist");
		 return false;
	}

	printSolution(path);
	return true;
}

//����
int main() {
/* �������µ�ͼ
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