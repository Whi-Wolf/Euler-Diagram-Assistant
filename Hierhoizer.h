/*第一个邻结点*/
int FirstNod(Graph G, int x) {
    int i;
    for (i = 0; i < G.vexnum; i++)
        if (G.GraphElem[x][i])
            return i;
    return -1;
}

/*找下一个邻结点*/
int NextNod(Graph G, int x, int i) {
    int j;
    for (j = i; j < G.vexnum; j++)
        if (G.GraphElem[x][j])
            return j;
    return -1;
}


/*核心算法，Hierhoizer，利用了DFS
相当于很多环的并集
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
