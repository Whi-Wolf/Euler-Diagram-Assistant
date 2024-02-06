/*��һ���ڽ��*/
int FirstNod(Graph G, int x) {
    int i;
    for (i = 0; i < G.vexnum; i++)
        if (G.GraphElem[x][i])
            return i;
    return -1;
}

/*����һ���ڽ��*/
int NextNod(Graph G, int x, int i) {
    int j;
    for (j = i; j < G.vexnum; j++)
        if (G.GraphElem[x][j])
            return j;
    return -1;
}


/*�����㷨��Hierhoizer��������DFS
�൱�ںܶ໷�Ĳ���
*/
Stack Hierhoizer(Graph &G, Stack S, int x)
{
    int i;
    for (i = FirstNod(G, x); i >= 0; i = NextNod(G, x, i))
    {
        G.GraphElem[x][i]--;
        if (G.Gkind)
           G.GraphElem[i][x]--;
        S = Hierhoizer(G, S, i);
    }
    S = PushStack(S, x);
    return S;
}
