#pragma once
typedef struct Button {
	int x, y, width, height;
	COLORREF color;
	char context[500];
}Button,*PtrButton;

typedef struct Text {
	int x, y;
	int width;
	int height;
	char context[500] ;
}Text, * PtrText;

PtrText SetText(PtrText text, ExMessage m, int i) {
	char chs[3];
	text = (PtrText)malloc(sizeof(Text));
	text->x = m.x;
	text->y = m.y;
	text->width = 5;
	text->height = 5;
	strcpy(text->context, "V\0");
	sprintf(chs, "%d", i);//����㣨���������ã�
	strcat(text->context, chs);

	return text;
}

PtrButton createButton(int x,int y,int width,int height,char* str) {
	PtrButton button = (PtrButton)malloc(sizeof(Button));
	assert(button);
	button->x = x;
	button->y = y;
	button->width = width;
	button->height = height;
	button->color = RGB(204, 213, 240);
	strcpy(button->context,str);
	return button;
}

void drawButton(PtrButton button) {
	int xx, yy,textw,texth;
	setfillcolor(button->color);
	fillrectangle(button->x,button->y,button->x+button->width,button->y+button->height);
	setbkmode(TRANSPARENT);
	textw = textwidth(button->context);
	texth = textheight(button->context);
	xx = button->x + (button->width - textw) / 2;
	yy = button->y + (button->height-texth) / 2;
	settextcolor(BLACK);
	outtextxy(xx,yy,button->context);
}

int inButton(PtrButton button, ExMessage m) {
	if (m.x > button->x && m.x<button->x + button->width
		&& m.y>button->y && m.y < button->y + button->height)
	{
		button->color = RGB(236, 244, 255);
		return 1;
	}
	button->color = RGB(204, 213, 240);
	return 0;

}



//���ӻ���������ʾ����·��
void show(Graph G,int* road) {
	int i = 0,j=0;
	PtrText text = NULL;
	Text info;
	ExMessage* vex;
	ExMessage temp;
	ExMessage m;
	char button1name[] = "��λ";
	char button2name[] = "����";
	PtrButton reset, end;
	initgraph(800, 800);
	BeginBatchDraw();
	vex = (ExMessage*)malloc(sizeof(ExMessage) * G.vexnum);
	reset = createButton(100, 500, 100, 50, button1name);//����㣺const char* ���͵�ʵ����char* ���͵��ββ�����
	end = createButton(400, 500, 100, 50, button2name);
	info.x = 10; info.y = 0;
	//strcpy(info.context,"��������˳�����ɽ�㡣\n��������꣬������������ʼ��ʾŷ��·����\n��Ҫ������Ͻǣ����̻Ῠס�����ܺϷ�����������\n");
	//����㣺û���Զ����й���
	while (1)
	{
		settextstyle(25, 0, "����");
		settextcolor(WHITE);
		outtextxy(info.x, info.y, "��������˳�����ɽ�㡣");
		outtextxy(info.x, info.y + 40, "��������꣬������������ʼ��ʾŷ��·����");
		outtextxy(info.x, info.y + 80, "��Ҫ������Ͻǣ����̻Ῠס�����ܺϷ�����������");
		drawButton(reset);
		drawButton(end);
		
		if (i < G.vexnum)
		{
			peekmessage((vex + i), EM_MOUSE);
			if (inButton(reset, vex[i])&& vex[i].message == WM_LBUTTONDOWN)
			{
				
				for (i = G.vexnum; i >= 0; i--)
				{
					vex[i].message = 0;
					vex[i].x = -1;
					vex[i].y = -1;
				}
				i = 0;
				//flushmessage(EX_MOUSE);
				cleardevice();
			}
			else if (inButton(end, vex[i])&& vex[i].message == WM_LBUTTONDOWN)
			{
				closegraph();
				return;
			}
			else if (vex[i].message == WM_LBUTTONDOWN)
			{
				circle(vex[i].x, vex[i].y, 10);
				settextcolor(WHITE);
				text = SetText(text, vex[i], i);
				
				outtextxy(text->x, text->y, text->context);
				i++;
			}

		}
		else
		{
			setlinecolor(WHITE);
			setlinestyle(10);
			if (j < G.arcs)
			{
				peekmessage(&temp, EM_MOUSE);
				if (inButton(reset, temp)&& temp.message == WM_LBUTTONDOWN)
				{
					for (i = G.vexnum; i >= 0; i--)
						vex[i].message = 0;
					j = 0;
					temp.message = 0;
					temp.x = -1;
					temp.y = -1;
					i = 0;
					m.message = 0;//����㣺��λ����ʾ��ȫ
					//flushmessage(EX_MOUSE);
					cleardevice();
				}
				else if (inButton(end, temp)&& temp.message == WM_LBUTTONDOWN)
				{
					closegraph();
					return;
				}
				else if (temp.message == WM_LBUTTONDOWN)
				{
					line(vex[road[j]].x, vex[road[j]].y, vex[road[j + 1]].x, vex[road[j + 1]].y);
					j++;
					temp.message = 0;
				}
			}
			else
			{
				peekmessage(&m, EM_MOUSE);
				if (inButton(reset, m)&& m.message == WM_LBUTTONDOWN)
				{
					for (i = G.vexnum-1; i >= 0; i--)
					{
						vex[i].message = 0;
						vex[i].x = -1;
						vex[i].y = -1;
					}
					j = 0;
					temp.message = 0;
					temp.x = -1;
					temp.y = -1;
					i = 0;
					m.message = 0;
					flushmessage(EX_MOUSE);
					cleardevice();
				}
				else if (inButton(end, m) && m.message == WM_LBUTTONDOWN)
				{
					closegraph();
					return;
				}
			}
			//ֱ���˳�
			//{
			//	peekmessage(&temp, EM_MOUSE);
			//	if (temp.message == WM_LBUTTONDOWN)
			//		break;
			//}

		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	closegraph();
	return;
}