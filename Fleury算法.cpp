/*#define _CRT_SECURE_NO_WARNINGS -1
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int ans[200];
int top;
int N, M;
int mp[200][200];
void dfs(int x)
{
    int i;
    top++;
    ans[top] = x;
    for (i = 1; i <= N; i++)
    {
        if (mp[x][i] > 0)
        {
            mp[x][i] = mp[i][x] = 0;///ɾ���˱�
            dfs(i);
            break;
        }
    }
}

void fleury(int x)
{
    int brige, i;
    top = 1;
    ans[top] = x;///��������Euler·����
    while (top >= 0)
    {
        brige = 0;
        for (i = 1; i <= N; i++) /// ��ͼ����һ���߲��Ǹ�ߣ��ţ�
        {
            if (mp[ans[top]][i] > 0)///����һ��������չ�ı�
            {
                brige = 1;
                break;
            }
        }
        if (!brige)/// ���û�е������չ���������ջ
        {
            printf("%d ", ans[top]);
            top--;
        }
        else     /// �����������ŷ��·��
        {
            top--;///Ϊ�˻���
            dfs(ans[top + 1]);
        }
    }
}

int main()
{
    int x, y, deg, num, start, i, j;
    scanf("%d%d", &N, &M);
    memset(mp, 0, sizeof(mp));
    for (i = 1; i <= M; i++)
    {
        scanf("%d%d", &x, &y);
        mp[x][y] = 1;
        mp[y][x] = 1;
    }
    num = 0;
    start = 1;///�����ʼ��Ϊ1
    for (i = 1; i <= N; i++)
    {
        deg = 0;
        for (j = 1; j <= N; j++)
        {
            deg += mp[i][j];
        }
        if (deg % 2 == 1)///��ȶ���
        {
            start = i;
            num++;
        }
    }
    if (num == 0 || num == 2)
    {
        fleury(start);
    }
    else
    {
        puts("No Euler path");
    }
    return 0;
}*/