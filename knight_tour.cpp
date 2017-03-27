#include<stdio.h>
#include <iostream>
using namespace std;
#define N 8

bool backtracking(int x,int y,int cnt);

int isSafe(int x, int y, int solution[N][N])
{
    if ( x >= 0 && x < N && y >= 0 && y < N && solution[x][y] == -1)
        return 1;
    return 0;
}

/* ��ӡ����sol */
void printSolution(int sol[N][N])
{
	printf("find one solution :\n");
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
}

//�洢�������
int solution[N][N];

//�����˷�������8���߷�
int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

bool KnightTour()
{
    /* ��ʼ�� */
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            solution[x][y] = -1;

    if(backtracking(0, 0, 1) == false)
    {
        printf("Solution does not exist");
        return false;
    }
    else
        printSolution(solution);

    return true;
}

bool backtracking(int x,int y,int cnt){
	//�洢���ʼ�¼
	solution[x][y] = cnt;

	//���������еĸ���
	if(cnt == N*N){
		return true;
	}
	int next_x, next_y;
	//һ�γ������п����ƶ��ĸ���
	for(int i=0; i<8; i++){
		next_x = x + xMove[i];
		next_y = y + yMove[i];

		//�жϸø����Ƿ���Է���
		if( isSafe(next_x, next_y, solution) ){

			//�ҵ�������� ��ֱ�ӷ���
			if( backtracking(next_x,next_y,cnt+1) == true ) return true;
		}
	}
	solution[x][y] = -1; //���ݲ���. δ�ҵ��������
	return false;
}

int main()
{
	KnightTour();
    return 0;
}