#include"elshead.h"
char g_Square[20][10] = { 0 };
char g_RandomSquare[2][4] = { 0 };//随机小方块
int g_nSquareID = -1;//不同方块的标识
int g_nLine = -1;// 记录方块起点所在的行和列
int g_nList = -1;
int g_nScore = 0;//分数

void OnCreate()
{
	//种种子
	srand((unsigned int)time(NULL));
	//产生随机方块
	CreateRandomSquare();
	//复制随机方块到背景
	 CopySquareToBack();
}
//画纸
void OnPaint(HDC hDC)
{
	//创建兼容性DC
	HDC hMemDC = CreateCompatibleDC(hDC);
	//创建一张纸,先在纸上把东西“画出来”，再一起显示在纸上，防止边画边显示所产生的闪烁
	HBITMAP hBitmapBack = CreateCompatibleBitmap(hDC,500,600);
	//关联起来
	SelectObject(hMemDC, hBitmapBack);
	PaintSquare(hMemDC);
	PaintSquare2(hMemDC);
	ShowScore(hMemDC);
	//传递
	BitBlt(hDC, 0, 0, 500, 600, hMemDC,0,0,SRCCOPY);
	
	DeleteDC(hMemDC);
	DeleteObject(hBitmapBack);
}
//显示分数
void ShowScore(HDC HMemDC)
{
	HBRUSH hOldBrush;
	HBRUSH hNewBrush2 = CreateSolidBrush(RGB(153, 143, 218));
	char strScore[10] = { 0 };
	hOldBrush = SelectObject(HMemDC, hNewBrush2);
	Rectangle(HMemDC, 300, 0, 500, 600);
	_itoa(g_nScore,strScore,10);
	TextOut(HMemDC, 360, 50, "分数", strlen("分数"));
	TextOut(HMemDC, 310, 100, "欢迎来到俄罗斯方块", strlen("欢迎来到俄罗斯方块"));
	TextOut(HMemDC, 320, 120, "按回车键开始", strlen("按回车键开始"));
	TextOut(HMemDC, 310, 140, "方向键控制移动及变形", strlen("方向键控制移动及变形"));
	TextOut(HMemDC, 375, 65, strScore, strlen(strScore));
	hNewBrush2 = SelectObject(HMemDC, hOldBrush);
	DeleteObject(hNewBrush2);
}
//画方块
void PaintSquare(hMemDC)
{
	int i, j;
	HBRUSH hOldBrush;
	HBRUSH hNewBrush1 =  CreateSolidBrush(RGB(255,106,106));
	HBRUSH hNewBrush3 = CreateSolidBrush(RGB(129, 183, 117));
	//画大背景方块
	hOldBrush = SelectObject(hMemDC, hNewBrush3);
	Rectangle(hMemDC, 0, 0, 300, 600);
	hNewBrush3 = SelectObject(hMemDC, hOldBrush);
	DeleteObject(hNewBrush3);
	//遍历数组
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
//画方块2
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
//产生随机方块
int CreateRandomSquare()
{
	int nIdex = rand() % 7;//产生七种不同的随机块
	switch (nIdex)
	{
	case 0://对数组赋值只能一个一个去做
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
//复制随机方块到背景
void CopySquareToBack()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//j+3 保证在中心出现
			g_Square[i][j+3] = g_RandomSquare[i][j];
		}
	}
}


//回车键函数（启用定时器,开始下落）
void OnKeyReturn(HWND hWnd)
{
	//第三个参数是毫秒，将第四个参数有具体的函数改成NULL，则它会每隔一段时间产生一个消息
	SetTimer(hWnd, DEE_TIMER1, 500, NULL);
}
//方向键“上”函数
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
		//旋转变形
		if (1 == JudgeSquareChange())
		{
			SquareChange();
		}
		//else
		//{
		//}
	
		break;
	case 5:
		//正方形不变形
		return;
	case 6:
		//长条形特殊变形
		if (1 == JudgeSquareChangeLine())
		{
			SquareChangeLine();
		}
	
		break;
	}
	OnPaint(hDC);
	ReleaseDC(hWnd, hDC);
}
//方向键“下”函数
void OnKeyDown(HWND hWnd)
{
	OnTimer(hWnd);
}
//方向键“左”函数
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
//方向键“右”函数
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
//计时器函数
void OnTimer(HWND hWnd)
{
	HDC hDC = GetDC(hWnd);
	//方块下落
	
	if (1 == SquareStopInFloor() && 1 == SquareStopOnOther())//没到底层&&下面没有方块，所以继续下落
			{
				SquareDownMove();
				g_nLine++;
			}
			else//否则产生新的方块
			{
				//1To2
				Square1To2();
				//消除行
				DestroySquareLine();
				if (0 == GameOver(hWnd))
				{
					KillTimer(hWnd, DEE_TIMER1);
					return ;
				}
				//产生随机方块
				CreateRandomSquare();
				//复制随机方块到背景
				CopySquareToBack();
			}
	
	//画出来
	OnPaint(hDC);//此处不调用PaintSquare(hMemDC); 先在“纸上”画
	ReleaseDC(hWnd, hDC);
}
//游戏结束
int GameOver(HWND hWnd)
{
	int j = 0;
	for (j = 0; j < 10; j++)
	{
		if (2 == g_Square[0][j])
		{
			MessageBox(hWnd, "游戏结束", "提示", MB_OK);
			return 0;
		}
	}
	return 1;
}

//方块下移
void SquareDownMove()
{
	for (int i = 19; i >= 0; i--)//因为是下移，故从下行向上行检索，从而避免重复检索
	{
		for (int j = 0; j < 10; j++)
		{
			if (1 == g_Square[i][j])//检索到1，就将下行同列变为1，自身变为0
			{
				g_Square[i][j] = 0;
				g_Square[i+1][j] = 1;
			}
		}
	}
}
//方块左移
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
//方块右移
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


//方块停在最底部
int SquareStopInFloor()
{
	for (int j = 0; j < 10; j++)
	{
		if (1 == g_Square[19][j])
		{
			return 0;//返回0  结束函数
		}
	}
	return 1;
}
//方块停在方块上
int SquareStopOnOther()
{
	for (int i = 19; i >= 0; i--)//倒着检索
	{
		for (int j = 0; j < 10; j++)
		{
			if (1 == g_Square[i][j])//检索到1，就检索其(有方块的)下一行是否有2
			{
				if (2 == g_Square[i + 1][j])
				{
					return 0;//下一行有2（方块），不可下落
				}
			}
		}
	}
	return 1;
}
//禁止左移穿墙
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
//禁止左移穿方块
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
//禁止右移穿墙
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
//禁止右移穿方块
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
//判断方块能否变形
int JudgeSquareChange()
{
	for (int i=0;i<3;i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (2 == g_Square[g_nLine + i][g_nList + j])//3*3方块中有 已固定的方块
			{
				return 0;//返回0，不能变形
			}
		}
	}
	/*//方块在边界不可变形
	if (g_nList<0 || g_nList + 2>9)
	{
		return 0;
	}
	*/
	//方块在边界可以变形
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
//判断方块能否变形(长条)
int JudgeSquareChangeLine()
{
	int g_nList2 = g_nList + 1;
	int j1= 0, j2 = 0;
	for (j1 = 1; j1< 4; j1++)//右边
	{
		if (2 == g_Square[g_nLine][g_nList2 +j1] || g_nList2 + j1>9)
		{
			break;//退出for循环，得到j1的值
		}
	}

	for (j2= 1; j2< 4; j2++)//右边
	{
		if (2 == g_Square[g_nLine][g_nList2 - j2] || g_nList2 -j2<0)
		{
			break;//退出for循环，得到j1的值
		}
	}

	if ((j1 + j2 - 2) < 3)
	{
		return  0;//不可变形
	}
	return 1;
}

//将方块所对应的“1”码变成“2”（以便不影响其他方块下落）
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
//方块变形(普通)
void SquareChange()
{
	int i=0, j=0;
	int ntemp=2;//行 变形控制变量,记得声明变量时一定要记得赋个初值
	char ChangeSquare[3][3] = {0};
		//复制方块(3*3方块组)
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			ChangeSquare[i][j] = g_Square[g_nLine+i][g_nList+j];
		}
	}
	//方块变形并复制回去,每次变形前都相当于进行了初始化，故后面几次变形同第一次变形
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
//方块变形(长条)
void SquareChangeLine()
{
	//判断是横着的还是竖着的
	if (1==g_Square[g_nLine][g_nList])//横着的
	{
				//清零
				g_Square[g_nLine][g_nList] = 0;
				g_Square[g_nLine][g_nList+2] = 0;
				g_Square[g_nLine][g_nList+3] = 0;
				//不同情况赋值
				if (2 == g_Square[g_nLine + 1][g_nList + 1])//标记方块（左数第二个）贴着 下面固定方块的情况
				{
					g_Square[g_nLine -1][g_nList + 1] = 1;
					g_Square[g_nLine -2][g_nList + 1] = 1;
					g_Square[g_nLine -3][g_nList + 1] = 1;
				}
				else if (2 == g_Square[g_nLine + 2][g_nList + 1])//标记方块与 下面固定方块隔一个的情况
				{
					g_Square[g_nLine - 1][g_nList + 1] = 1;
					g_Square[g_nLine - 2][g_nList + 1] = 1;
					g_Square[g_nLine +1][g_nList + 1] = 1;
				}
				else//标记方块与 下面固定方块隔两个及两个以上的情况
				{
					g_Square[g_nLine-1][g_nList+1] = 1;
					g_Square[g_nLine+1][g_nList + 1] = 1;
					g_Square[g_nLine+2][g_nList + 1] = 1;
				}
	
	}
	else//竖着的
	{
				//清零
				g_Square[g_nLine - 1][g_nList + 1] = 0;
				g_Square[g_nLine + 1][g_nList + 1] = 0;
				g_Square[g_nLine + 2][g_nList + 1] = 0;
				//赋值
				if (2 == g_Square[g_nLine][g_nList + 2]||8==g_nList)//标记方块贴着 右边固定方块或墙 的情况
				{
					g_Square[g_nLine][g_nList] = 1;
					g_Square[g_nLine][g_nList - 1] = 1;
					g_Square[g_nLine][g_nList - 2] = 1;
					//改变标记，左移两个
					g_nList = g_nList - 2;
				}
				else if (2 == g_Square[g_nLine][g_nList + 3]||7==g_nList)//标记方块与 右边固定方块或墙 隔一个的情况
				{
					g_Square[g_nLine][g_nList] = 1;
					g_Square[g_nLine][g_nList +2] = 1;
					g_Square[g_nLine][g_nList -1] = 1;
					//改变标记,左移一个
					g_nList = g_nList - 1;
				}
				else if (2 == g_Square[g_nLine][g_nList] || 0==g_nList+1)//标记方块贴着 左边固定方块或墙的情况
				{
					g_Square[g_nLine][g_nList+2] = 1;
					g_Square[g_nLine][g_nList +3] = 1;
					g_Square[g_nLine][g_nList +4] = 1;
					//改变标记，右移一个
					g_nList = g_nList +1;
				}
				else//一般情况
				{
					g_Square[g_nLine][g_nList] = 1;
					g_Square[g_nLine][g_nList + 2] = 1;
					g_Square[g_nLine][g_nList + 3] = 1;
				}
	}
}

//消除满行方块
void DestroySquareLine()
{
	int i = 0, j = 0, ntemp1 = 0,nSum=0,j2=0;
	for (i=19;i>=0;i--)
	{
		for (j = 0; j < 10; j++)
		{
			nSum += g_Square[i][j];//计算一行的和
		}
		if (20 == nSum)//每个方块值是2，和为20代表满行
		{
			//消除行
			for (ntemp1= i - 1; ntemp1 >= 0; ntemp1--)
			{
				for (j2 = 0; j2 < 10; j2++)
				{
					g_Square[ntemp1 + 1][j2] = g_Square[ntemp1][j2];//（将所有方块整体向下移动一格）
				}
			}
			g_nScore++;
			i = 20;//重新赋值给i，保证每次都能从最下面的一行遍历起，此语句是条件执行
			//i=20要写在if里面，不然会造成无休止的循环，不写i=19的原因是执行完这步后会执行i--，
		}
		nSum= 0;//清零
		
	}
}

//_CRT_SECURE_NO_WARNINGS
