#define _CRT_SECURE_NO_WARNINGS -1

/*原始灵感
void dfs(int x)
{
    for (int i = head[x]; i; i = nex[i])
    {
        int y = to[i];
        if (vis[i])continue;
        vis[i] = 1;
        dfs(y);
    }
    ans.push_back(x);
}
*/

#include"Head.h"

int main() {
    Graph G = {0};
    Graph Gcopy;
    Stack S;
    int i,j,v0,v1, start,choice=1,count=1;
    int* num;
    int road[N];
    char go='y',ch;

    printf("欢迎使用欧拉图助手\n");
    while(go=='y')
    {
        printf("******菜单*******\n");
        switch (count) {
        case 1:
            printf("1、构建新图\n");
            printf("输入选项：");
            scanf("%d", &choice);
            if (choice != 1)
            {
                printf("输入错误！\n");
                exit(0);
            }
            count=2;
            break;

        case 2:
            printf("1、构建新图\n");
            printf("2、计算欧拉回路/通路\n");
            printf("输入选项：");
            scanf("%d", &choice);
            if (choice != 1&&choice!=2)
            {
                printf("输入错误！\n");
                exit(0);
            }
            count=3;
            break;

        default:
            printf("1、构建新图\n");
            printf("2、计算欧拉回路/通路\n");
            printf("3、可视化\n");
            printf("\n");
            printf("输入选项：");
            scanf("%d", &choice);
            if (choice == 1)
                count = 2;
        }

        switch(choice)
        {
        case 1:
            printf("输入的图是有向图请输入0，无向图请输入1：");
            scanf("%d", &G.Gkind);
            if (G.Gkind != 0 && G.Gkind != 1)
            {
                printf("输入错误\n");
                exit(0);
            }
            printf("输入结点数、边数：");
            scanf("%d%d", &G.vexnum, &G.arcs);

            //邻接矩阵全置0
            for (i = 0; i < G.vexnum; i++)
                for (j = 0; j < G.vexnum; j++)
                    G.GraphElem[i][j] = 0;

            //输入边
            if (!G.Gkind)
                printf("先输弧尾，再输弧头，例：0 1（0指向1）\n");
            printf("输入边的两个顶点（有效顶点为0~%d）：", G.vexnum - 1);
            for (i = 0; i < G.arcs; i++)
            {
                scanf("%d%d", &v0, &v1);
                if (v0 < 0 || v0 >= G.vexnum || v1 < 0 || v1 >= G.vexnum)
                    printf("输入有错，请检查\n");/////////停止
                G.GraphElem[v0][v1]++;
                if (G.Gkind)
                    G.GraphElem[v1][v0]++;
            }
            break;

            //判断是否有欧拉通路
        case 2:
            num = (int*)malloc(sizeof(int));
            if (G.Gkind)
                start = JudgeEulerUD(G, num);
            else
                start = JudgeEulerD(G, num);
            
            //找通路
            if (*num == 0 || *num == 2)
            {
                S.length = 0;
                S.top = 0;
                Gcopy = G;
                S = Hierhoizer(Gcopy, S, start);
                if (*num == 2)
                    printf("欧拉通路为：");
                else
                    printf("欧拉回路为：");
                i = 0;
                while (S.top != 0) {

                    S.top--;
                    road[i] = S.StackElem[S.top];
                    printf("%d", S.StackElem[S.top]);
                    S.length--;
                    i++;
                }
                printf("\n");
            }
            else
            {
                printf("No Euler path\n");
                count = 2;
            }
            break;

            //可视化
        case 3:
            show(G, road);
        default:
            break;
        }
        printf("继续使用吗？（y/n）：");
        while ((ch = getchar()) != '\n' && ch != EOF);
        scanf("%c", &go);
        
        
    }
    return 0;
}