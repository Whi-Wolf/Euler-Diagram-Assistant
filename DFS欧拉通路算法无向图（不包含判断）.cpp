/*#define _CRT_SECURE_NO_WARNINGS -1
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#define MAX 2010
using namespace std;
int maps[MAX][MAX];//�ڽӾ���
int in[MAX];//����
int t[MAX];//���ŵ�ͨ·����
int flag;
int k;
int Max, Min;
void DFS(int x)
{
    int i;
    for (i = Min; i <= Max; i++)
    {
        if (maps[x][i])///������һ�����������ĵ����
        {
            maps[x][i]--;///ɾȥ������ı�
            maps[i][x]--;
            DFS(i);
        }
    }
    t[++k] = x;///��¼·������Ϊ�ǵݹ����е��ż�
}
int main()
{
    int n, i, x, y;
    Max = -9999;
    Min = 9999;
    flag = 0;
    scanf("%d", &n);//��
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
        if (in[i] % 2)///������ȵ㣬˵����ŷ��ͨ·
        {
            flag = 1;
            DFS(i);
            break;
        }
    }
    if (!flag)///ȫΪż�ȵ㣬�ӱ����С�Ŀ�ʼ��
    {
        DFS(Min);
    }
    for (i = k; i >= 1; i--)
    {
        printf("%d\n", t[i]);
    }
    return 0;
}*/