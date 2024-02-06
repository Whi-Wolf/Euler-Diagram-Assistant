/*#define _CRT_SECURE_NO_WARNINGS -1
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#define MAX 2010
using namespace std;
int maps[MAX][MAX];//邻接矩阵
int in[MAX];//度数
int t[MAX];//倒着的通路序列
int flag;
int k;
int Max, Min;
void DFS(int x)
{
    int i;
    for (i = Min; i <= Max; i++)
    {
        if (maps[x][i])///从任意一个与它相连的点出发
        {
            maps[x][i]--;///删去遍历完的边
            maps[i][x]--;
            DFS(i);
        }
    }
    t[++k] = x;///记录路径，因为是递归所有倒着记
}
int main()
{
    int n, i, x, y;
    Max = -9999;
    Min = 9999;
    flag = 0;
    scanf("%d", &n);//边
    for (i = 1; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        maps[x][y]++;
        maps[y][x]++;
        Max = max(x, max(y, Max));
        Min = min(x, min(y, Min));
        in[x]++;
        in[y]++;
    }
    for (i = Min; i <= Max; i++)
    {
        if (in[i] % 2)///存在奇度点，说明是欧拉通路
        {
            flag = 1;
            DFS(i);
            break;
        }
    }
    if (!flag)///全为偶度点，从标号最小的开始找
    {
        DFS(Min);
    }
    for (i = k; i >= 1; i--)
    {
        printf("%d\n", t[i]);
    }
    return 0;
}*/