/*有向图判断是否有欧拉通路*/
int JudgeEulerD(Graph G, int* num) {
    int start, end, deg, i, j, flagout = 0, flagin = 0;
    *num = 0;
    start = 0;///这里初始化为0
    for (i = 0; i < G.vexnum; i++)
    {
        deg = 0;
        for (j = 0; j < G.vexnum; j++)
        {
            deg = deg + G.GraphElem[i][j] - G.GraphElem[j][i];
        }
        if (deg != 0)
        {
            if (deg == 1)
            {
                start = i;
                flagout++;
            }
            else if (deg == -1)
            {
                end = i;
                flagin++;
            }
            else
                (*num) = 3;
            (*num)++;
        }

    }
    if (flagout == 1 && flagin == 1)
        *num = 2;
    return start;
}

/*无向图判断是否有欧拉通路*/
int JudgeEulerUD(Graph G, int* num) {
    int start, deg, i, j;
    *num = 0;
    start = 0;///这里初始化为0
    for (i = 0; i < G.vexnum; i++)
    {
        deg = 0;
        for (j = 0; j < G.vexnum; j++)
        {
            deg += G.GraphElem[i][j];
        }
        if (deg % 2 == 1)///奇度顶点
        {
            start = i;
            (*num)++;
        }
    }

    return start;
}
