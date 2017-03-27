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

/* 打印数组sol */
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

//存储解决方案
int solution[N][N];

//马跳八方，共有8中走法
int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

bool KnightTour()
{
    /* 初始化 */
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
	//存储访问记录
	solution[x][y] = cnt;

	//访问完所有的格子
	if(cnt == N*N){
		return true;
	}
	int next_x, next_y;
	//一次尝试所有可以移动的格子
	for(int i=0; i<8; i++){
		next_x = x + xMove[i];
		next_y = y + yMove[i];

		//判断该格子是否可以访问
		if( isSafe(next_x, next_y, solution) ){

			//找到解决方案 就直接返回
			if( backtracking(next_x,next_y,cnt+1) == true ) return true;
		}
	}
	solution[x][y] = -1; //回溯操作. 未找到解决方案
	return false;
}

int main()
{
	KnightTour();
    return 0;
}