#include"elshead.h"
char g_Square[20][10] = { 0 };
char g_RandomSquare[2][4] = { 0 };//���С����
int g_nSquareID = -1;//��ͬ����ı�ʶ
int g_nLine = -1;// ��¼����������ڵ��к���
int g_nList = -1;
int g_nScore = 0;//����

void OnCreate()
{
	//������
	srand((unsigned int)time(NULL));
	//�����������
	CreateRandomSquare();
	//����������鵽����
	 CopySquareToBack();
}
//��ֽ
void OnPaint(HDC hDC)
{
	//����������DC
	HDC hMemDC = CreateCompatibleDC(hDC);
	//����һ��ֽ,����ֽ�ϰѶ�����������������һ����ʾ��ֽ�ϣ���ֹ�߻�����ʾ����������˸
	HBITMAP hBitmapBack = CreateCompatibleBitmap(hDC,500,600);
	//��������
	SelectObject(hMemDC, hBitmapBack);
	PaintSquare(hMemDC);
	PaintSquare2(hMemDC);
	ShowScore(hMemDC);
	//����
	BitBlt(hDC, 0, 0, 500, 600, hMemDC,0,0,SRCCOPY);
	
	DeleteDC(hMemDC);
	DeleteObject(hBitmapBack);
}
//��ʾ����
void ShowScore(HDC HMemDC)
{
	HBRUSH hOldBrush;
	HBRUSH hNewBrush2 = CreateSolidBrush(RGB(153, 143, 218));
	char strScore[10] = { 0 };
	hOldBrush = SelectObject(HMemDC, hNewBrush2);
	Rectangle(HMemDC, 300, 0, 500, 600);
	_itoa(g_nScore,strScore,10);
	TextOut(HMemDC, 360, 50, "����", strlen("����"));
	TextOut(HMemDC, 310, 100, "��ӭ��������˹����", strlen("��ӭ��������˹����"));
	TextOut(HMemDC, 320, 120, "���س�����ʼ", strlen("���س�����ʼ"));
	TextOut(HMemDC, 310, 140, "����������ƶ�������", strlen("����������ƶ�������"));
	TextOut(HMemDC, 375, 65, strScore, strlen(strScore));
	hNewBrush2 = SelectObject(HMemDC, hOldBrush);
	DeleteObject(hNewBrush2);
}
//������
void PaintSquare(hMemDC)
{
	int i, j;
	HBRUSH hOldBrush;
	HBRUSH hNewBrush1 =  CreateSolidBrush(RGB(255,106,106));
	HBRUSH hNewBrush3 = CreateSolidBrush(RGB(129, 183, 117));
	//���󱳾�����
	hOldBrush = SelectObject(hMemDC, hNewBrush3);
	Rectangle(hMemDC, 0, 0, 300, 600);
	hNewBrush3 = SelectObject(hMemDC, hOldBrush);
	DeleteObject(hNewBrush3);
	//��������
	hOldBrush = SelectObject(hMemDC, hNewBrush1);
	for (i=0;i<20;i++)
	{
		for (j=0;j<10;j++)
		{
			if (1 == g_Square[i][j])
			{
				Rectangle(hMemDC, j*30, i*30, j*30+30, i*30+30);
			}
		}
	}
	hNewBrush1 = SelectObject(hMemDC, hOldBrush);
    DeleteObject(hNewBrush1);
	
}
//������2
void PaintSquare2(hMemDC)
{
	int i, j;
	HBRUSH hOldBrush;
	HBRUSH hNewBrush2 = CreateSolidBrush(RGB(124, 150, 237));
	hOldBrush = SelectObject(hMemDC, hNewBrush2);
	for (i = 0; i<20; i++)
	{
		for (j = 0; j<10; j++)
		{
			if (2 == g_Square[i][j])
			{
				Rectangle(hMemDC, j * 30, i * 30, j * 30 + 30, i * 30 + 30);
			}
		}
	}
	hNewBrush2 = SelectObject(hMemDC, hOldBrush);
	DeleteObject(hNewBrush2);
}
//�����������
int CreateRandomSquare()
{
	int nIdex = rand() % 7;//�������ֲ�ͬ�������
	switch (nIdex)
	{
	case 0://�����鸳ֵֻ��һ��һ��ȥ��
		g_RandomSquare[0][0] = 1, g_RandomSquare[0][1] = 1, g_RandomSquare[0][2] = 0,g_RandomSquare[0][3] = 0;
		g_RandomSquare[1][0] = 0, g_RandomSquare[1][1] = 1, g_RandomSquare[1][2] = 1,g_RandomSquare[1][3] = 0;
		g_nLine = 0;
		g_nList = 3;
		break;
	case 1:
		g_RandomSquare[0][0] = 0, g_RandomSquare[0][1] = 1, g_RandomSquare[0][2] = 1, g_RandomSquare[0][3] = 0;
		g_RandomSquare[1][0] = 1, g_RandomSquare[1][1] = 1, g_RandomSquare[1][2] = 0, g_RandomSquare[1][3] = 0;
		g_nLine = 0;
		g_nList = 3;
		break;
	case 2:
		g_RandomSquare[0][0] = 0, g_RandomSquare[0][1] = 0, g_RandomSquare[0][2] = 1, g_RandomSquare[0][3] = 0;
		g_RandomSquare[1][0] = 1, g_RandomSquare[1][1] = 1, g_RandomSquare[1][2] = 1, g_RandomSquare[1][3] = 0;
		g_nLine = 0;
		g_nList = 3;
		break;
	case 3:
		g_RandomSquare[0][0] = 1, g_RandomSquare[0][1] = 0, g_RandomSquare[0][2] = 0, g_RandomSquare[0][3] = 0;
		g_RandomSquare[1][0] = 1, g_RandomSquare[1][1] = 1, g_RandomSquare[1][2] = 1, g_RandomSquare[1][3] = 0;
		g_nLine = 0;
		g_nList = 3;
		break;
	case 4:
		g_RandomSquare[0][0] = 0, g_RandomSquare[0][1] = 1, g_RandomSquare[0][2] = 0, g_RandomSquare[0][3] = 0;
		g_RandomSquare[1][0] = 1, g_RandomSquare[1][1] = 1, g_RandomSquare[1][2] = 1, g_RandomSquare[1][3] = 0;
		g_nLine = 0;
		g_nList = 3;
		break;
	case 5:
		g_RandomSquare[0][0] = 1, g_RandomSquare[0][1] = 1, g_RandomSquare[0][2] = 0, g_RandomSquare[0][3] = 0;
		g_RandomSquare[1][0] = 1, g_RandomSquare[1][1] = 1, g_RandomSquare[1][2] = 0, g_RandomSquare[1][3] = 0;
		g_nLine = 0;
		g_nList = 4;
		break;
	case 6:
		g_RandomSquare[0][0] = 1, g_RandomSquare[0][1] = 1, g_RandomSquare[0][2] = 1, g_RandomSquare[0][3] = 1;
		g_RandomSquare[1][0] = 0, g_RandomSquare[1][1] = 0, g_RandomSquare[1][2] = 0, g_RandomSquare[1][3] = 0;
		g_nLine = 0;
		g_nList = 3;
		break;
	}
	g_nSquareID = nIdex;
	return nIdex;
}
//����������鵽����
void CopySquareToBack()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//j+3 ��֤�����ĳ���
			g_Square[i][j+3] = g_RandomSquare[i][j];
		}
	}
}


//�س������������ö�ʱ��,��ʼ���䣩
void OnKeyReturn(HWND hWnd)
{
	//�����������Ǻ��룬�����ĸ������о���ĺ����ĳ�NULL��������ÿ��һ��ʱ�����һ����Ϣ
	SetTimer(hWnd, DEE_TIMER1, 500, NULL);
}
//��������ϡ�����
void OnKeyUp(HWND hWnd)
{
	HDC hDC = GetDC(hWnd);
	switch (g_nSquareID)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		//��ת����
		if (1 == JudgeSquareChange())
		{
			SquareChange();
		}
		//else
		//{
		//}
	
		break;
	case 5:
		//�����β�����
		return;
	case 6:
		//�������������
		if (1 == JudgeSquareChangeLine())
		{
			SquareChangeLine();
		}
	
		break;
	}
	OnPaint(hDC);
	ReleaseDC(hWnd, hDC);
}
//��������¡�����
void OnKeyDown(HWND hWnd)
{
	OnTimer(hWnd);
}
//��������󡱺���
void OnKeyLeft(HWND hWnd)
{
	if (1 == SquareStopLeft() && 1 == SquareStopLeftO())
	{
		HDC hDC = GetDC(hWnd);
		SquareLeftMove();
		g_nList--;
		OnPaint(hDC);
		ReleaseDC(hWnd, hDC);
	}

}
//��������ҡ�����
void OnKeyRight(HWND hWnd)
{
	if (1 == SquareStopRight() && 1 == SquareStopRightO())
	{
		HDC hDC = GetDC(hWnd);
		SquareRightMove();
		g_nList++;
		OnPaint(hDC);
		ReleaseDC(hWnd, hDC);
	}
}
//��ʱ������
void OnTimer(HWND hWnd)
{
	HDC hDC = GetDC(hWnd);
	//��������
	
	if (1 == SquareStopInFloor() && 1 == SquareStopOnOther())//û���ײ�&&����û�з��飬���Լ�������
			{
				SquareDownMove();
				g_nLine++;
			}
			else//��������µķ���
			{
				//1To2
				Square1To2();
				//������
				DestroySquareLine();
				if (0 == GameOver(hWnd))
				{
					KillTimer(hWnd, DEE_TIMER1);
					return ;
				}
				//�����������
				CreateRandomSquare();
				//����������鵽����
				CopySquareToBack();
			}
	
	//������
	OnPaint(hDC);//�˴�������PaintSquare(hMemDC); ���ڡ�ֽ�ϡ���
	ReleaseDC(hWnd, hDC);
}
//��Ϸ����
int GameOver(HWND hWnd)
{
	int j = 0;
	for (j = 0; j < 10; j++)
	{
		if (2 == g_Square[0][j])
		{
			MessageBox(hWnd, "��Ϸ����", "��ʾ", MB_OK);
			return 0;
		}
	}
	return 1;
}

//��������
void SquareDownMove()
{
	for (int i = 19; i >= 0; i--)//��Ϊ�����ƣ��ʴ����������м������Ӷ������ظ�����
	{
		for (int j = 0; j < 10; j++)
		{
			if (1 == g_Square[i][j])//������1���ͽ�����ͬ�б�Ϊ1�������Ϊ0
			{
				g_Square[i][j] = 0;
				g_Square[i+1][j] = 1;
			}
		}
	}
}
//��������
void SquareLeftMove()
{
	for (int i = 0; i <20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (1 == g_Square[i][j])
			{
				g_Square[i][j] = 0;
				g_Square[i ][j-1] = 1;
			}
		}
	}
}
//��������
void SquareRightMove()
{
	for (int i = 0; i <20; i++)
	{
		for (int j = 9; j >=0; j--)
		{
			if (1 == g_Square[i][j])
			{
				g_Square[i][j] = 0;
				g_Square[i][j +1] = 1;
			}
		}
	}
}


//����ͣ����ײ�
int SquareStopInFloor()
{
	for (int j = 0; j < 10; j++)
	{
		if (1 == g_Square[19][j])
		{
			return 0;//����0  ��������
		}
	}
	return 1;
}
//����ͣ�ڷ�����
int SquareStopOnOther()
{
	for (int i = 19; i >= 0; i--)//���ż���
	{
		for (int j = 0; j < 10; j++)
		{
			if (1 == g_Square[i][j])//������1���ͼ�����(�з����)��һ���Ƿ���2
			{
				if (2 == g_Square[i + 1][j])
				{
					return 0;//��һ����2�����飩����������
				}
			}
		}
	}
	return 1;
}
//��ֹ���ƴ�ǽ
int SquareStopLeft()
{
	for (int i = 0; i < 20; i++)
	{
		if (1 == g_Square[i][0])
		{
			return 0;
		}
	}
	return 1;
}
//��ֹ���ƴ�����
int SquareStopLeftO()
{
	for (int i = 0; i <20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (1 == g_Square[i][j])
			{
				if (2 == g_Square[i][j-1])
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
//��ֹ���ƴ�ǽ
int SquareStopRight()
{
	for (int i = 0; i < 20; i++)
	{
		if (1 == g_Square[i][9])
		{
			return 0;
		}
	}
	return 1;
}
//��ֹ���ƴ�����
int SquareStopRightO()
{
	for (int i = 0; i <20; i++)
	{
		for (int j = 9; j >=0; j--)
		{
			if (1 == g_Square[i][j])
			{
				if (2 == g_Square[i][j +1])
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
//�жϷ����ܷ����
int JudgeSquareChange()
{
	for (int i=0;i<3;i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (2 == g_Square[g_nLine + i][g_nList + j])//3*3�������� �ѹ̶��ķ���
			{
				return 0;//����0�����ܱ���
			}
		}
	}
	/*//�����ڱ߽粻�ɱ���
	if (g_nList<0 || g_nList + 2>9)
	{
		return 0;
	}
	*/
	//�����ڱ߽���Ա���
	if (g_nList < 0)
	{
		g_nList = 0;
	}
	else if (g_nList>9)
	{
		g_nList = 7;
	}

	return 1;
}
//�жϷ����ܷ����(����)
int JudgeSquareChangeLine()
{
	int g_nList2 = g_nList + 1;
	int j1= 0, j2 = 0;
	for (j1 = 1; j1< 4; j1++)//�ұ�
	{
		if (2 == g_Square[g_nLine][g_nList2 +j1] || g_nList2 + j1>9)
		{
			break;//�˳�forѭ�����õ�j1��ֵ
		}
	}

	for (j2= 1; j2< 4; j2++)//�ұ�
	{
		if (2 == g_Square[g_nLine][g_nList2 - j2] || g_nList2 -j2<0)
		{
			break;//�˳�forѭ�����õ�j1��ֵ
		}
	}

	if ((j1 + j2 - 2) < 3)
	{
		return  0;//���ɱ���
	}
	return 1;
}

//����������Ӧ�ġ�1�����ɡ�2�����Ա㲻Ӱ�������������䣩
void Square1To2()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (1 == g_Square[i][j])
			{
				g_Square[i][j] = 2;
			}
		}
	}
}
//�������(��ͨ)
void SquareChange()
{
	int i=0, j=0;
	int ntemp=2;//�� ���ο��Ʊ���,�ǵ���������ʱһ��Ҫ�ǵø�����ֵ
	char ChangeSquare[3][3] = {0};
		//���Ʒ���(3*3������)
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			ChangeSquare[i][j] = g_Square[g_nLine+i][g_nList+j];
		}
	}
	//������β����ƻ�ȥ,ÿ�α���ǰ���൱�ڽ����˳�ʼ�����ʺ��漸�α���ͬ��һ�α���
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			g_Square[g_nLine + i][g_nList + j] = ChangeSquare[ntemp][i];
			ntemp--;
		}
		ntemp=2;
	}
}
//�������(����)
void SquareChangeLine()
{
	//�ж��Ǻ��ŵĻ������ŵ�
	if (1==g_Square[g_nLine][g_nList])//���ŵ�
	{
				//����
				g_Square[g_nLine][g_nList] = 0;
				g_Square[g_nLine][g_nList+2] = 0;
				g_Square[g_nLine][g_nList+3] = 0;
				//��ͬ�����ֵ
				if (2 == g_Square[g_nLine + 1][g_nList + 1])//��Ƿ��飨�����ڶ��������� ����̶���������
				{
					g_Square[g_nLine -1][g_nList + 1] = 1;
					g_Square[g_nLine -2][g_nList + 1] = 1;
					g_Square[g_nLine -3][g_nList + 1] = 1;
				}
				else if (2 == g_Square[g_nLine + 2][g_nList + 1])//��Ƿ����� ����̶������һ�������
				{
					g_Square[g_nLine - 1][g_nList + 1] = 1;
					g_Square[g_nLine - 2][g_nList + 1] = 1;
					g_Square[g_nLine +1][g_nList + 1] = 1;
				}
				else//��Ƿ����� ����̶�������������������ϵ����
				{
					g_Square[g_nLine-1][g_nList+1] = 1;
					g_Square[g_nLine+1][g_nList + 1] = 1;
					g_Square[g_nLine+2][g_nList + 1] = 1;
				}
	
	}
	else//���ŵ�
	{
				//����
				g_Square[g_nLine - 1][g_nList + 1] = 0;
				g_Square[g_nLine + 1][g_nList + 1] = 0;
				g_Square[g_nLine + 2][g_nList + 1] = 0;
				//��ֵ
				if (2 == g_Square[g_nLine][g_nList + 2]||8==g_nList)//��Ƿ������� �ұ߹̶������ǽ �����
				{
					g_Square[g_nLine][g_nList] = 1;
					g_Square[g_nLine][g_nList - 1] = 1;
					g_Square[g_nLine][g_nList - 2] = 1;
					//�ı��ǣ���������
					g_nList = g_nList - 2;
				}
				else if (2 == g_Square[g_nLine][g_nList + 3]||7==g_nList)//��Ƿ����� �ұ߹̶������ǽ ��һ�������
				{
					g_Square[g_nLine][g_nList] = 1;
					g_Square[g_nLine][g_nList +2] = 1;
					g_Square[g_nLine][g_nList -1] = 1;
					//�ı���,����һ��
					g_nList = g_nList - 1;
				}
				else if (2 == g_Square[g_nLine][g_nList] || 0==g_nList+1)//��Ƿ������� ��߹̶������ǽ�����
				{
					g_Square[g_nLine][g_nList+2] = 1;
					g_Square[g_nLine][g_nList +3] = 1;
					g_Square[g_nLine][g_nList +4] = 1;
					//�ı��ǣ�����һ��
					g_nList = g_nList +1;
				}
				else//һ�����
				{
					g_Square[g_nLine][g_nList] = 1;
					g_Square[g_nLine][g_nList + 2] = 1;
					g_Square[g_nLine][g_nList + 3] = 1;
				}
	}
}

//�������з���
void DestroySquareLine()
{
	int i = 0, j = 0, ntemp1 = 0,nSum=0,j2=0;
	for (i=19;i>=0;i--)
	{
		for (j = 0; j < 10; j++)
		{
			nSum += g_Square[i][j];//����һ�еĺ�
		}
		if (20 == nSum)//ÿ������ֵ��2����Ϊ20��������
		{
			//������
			for (ntemp1= i - 1; ntemp1 >= 0; ntemp1--)
			{
				for (j2 = 0; j2 < 10; j2++)
				{
					g_Square[ntemp1 + 1][j2] = g_Square[ntemp1][j2];//�������з������������ƶ�һ��
				}
			}
			g_nScore++;
			i = 20;//���¸�ֵ��i����֤ÿ�ζ��ܴ��������һ�б����𣬴����������ִ��
			//i=20Ҫд��if���棬��Ȼ���������ֹ��ѭ������дi=19��ԭ����ִ�����ⲽ���ִ��i--��
		}
		nSum= 0;//����
		
	}
}

//_CRT_SECURE_NO_WARNINGS
