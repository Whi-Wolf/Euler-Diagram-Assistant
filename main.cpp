#define _CRT_SECURE_NO_WARNINGS -1

/*ԭʼ���
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

    printf("��ӭʹ��ŷ��ͼ����\n");
    while(go=='y')
    {
        printf("******�˵�*******\n");
        switch (count) {
        case 1:
            printf("1��������ͼ\n");
            printf("����ѡ�");
            scanf("%d", &choice);
            if (choice != 1)
            {
                printf("�������\n");
                exit(0);
            }
            count=2;
            break;

        case 2:
            printf("1��������ͼ\n");
            printf("2������ŷ����·/ͨ·\n");
            printf("����ѡ�");
            scanf("%d", &choice);
            if (choice != 1&&choice!=2)
            {
                printf("�������\n");
                exit(0);
            }
            count=3;
            break;

        default:
            printf("1��������ͼ\n");
            printf("2������ŷ����·/ͨ·\n");
            printf("3�����ӻ�\n");
            printf("\n");
            printf("����ѡ�");
            scanf("%d", &choice);
            if (choice == 1)
                count = 2;
        }

        switch(choice)
        {
        case 1:
            printf("�����ͼ������ͼ������0������ͼ������1��");
            scanf("%d", &G.Gkind);
            if (G.Gkind != 0 && G.Gkind != 1)
            {
                printf("�������\n");
                exit(0);
            }
            printf("����������������");
            scanf("%d%d", &G.vexnum, &G.arcs);

            //�ڽӾ���ȫ��0
            for (i = 0; i < G.vexnum; i++)
                for (j = 0; j < G.vexnum; j++)
                    G.GraphElem[i][j] = 0;

            //�����
            if (!G.Gkind)
                printf("���仡β�����仡ͷ������0 1��0ָ��1��\n");
            printf("����ߵ��������㣨��Ч����Ϊ0~%d����", G.vexnum - 1);
            for (i = 0; i < G.arcs; i++)
            {
                scanf("%d%d", &v0, &v1);
                if (v0 < 0 || v0 >= G.vexnum || v1 < 0 || v1 >= G.vexnum)
                    printf("�����д�����\n");/////////ֹͣ
                G.GraphElem[v0][v1]++;
                if (G.Gkind)
                    G.GraphElem[v1][v0]++;
            }
            break;

            //�ж��Ƿ���ŷ��ͨ·
        case 2:
            num = (int*)malloc(sizeof(int));
            if (G.Gkind)
                start = JudgeEulerUD(G, num);
            else
                start = JudgeEulerD(G, num);
            
            //��ͨ·
            if (*num == 0 || *num == 2)
            {
                S.length = 0;
                S.top = 0;
                Gcopy = G;
                S = Hierhoizer(Gcopy, S, start);
                if (*num == 2)
                    printf("ŷ��ͨ·Ϊ��");
                else
                    printf("ŷ����·Ϊ��");
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

            //���ӻ�
        case 3:
            show(G, road);
        default:
            break;
        }
        printf("����ʹ���𣿣�y/n����");
        while ((ch = getchar()) != '\n' && ch != EOF);
        scanf("%c", &go);
        
        
    }
    return 0;
}