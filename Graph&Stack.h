typedef int GraphKind;
typedef struct Stack {
    int StackElem[N];
    int top;
    int length;
}Stack;
typedef struct Graph {
    int GraphElem[N][N];
    //char vex[N];//���Ϊ�ַ�������
    int vexnum, arcs;
    GraphKind Gkind;
}Graph;


//��ջ
Stack PushStack(Stack S, int x) {
    S.StackElem[S.top] = x;
    S.top++;
    S.length++;
    return S;
}
