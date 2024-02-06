typedef int GraphKind;
typedef struct Stack {
    int StackElem[N];
    int top;
    int length;
}Stack;
typedef struct Graph {
    int GraphElem[N][N];
    //char vex[N];//结点为字符再启用
    int vexnum, arcs;
    GraphKind Gkind;
}Graph;


//入栈
Stack PushStack(Stack S, int x) {
    S.StackElem[S.top] = x;
    S.top++;
    S.length++;
    return S;
}
