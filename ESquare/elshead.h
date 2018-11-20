#ifndef DEF_ELS_HEAD
#define DEF_ELS_HEAD

#define DEE_TIMER1  1234   //一般将程序中具体的ID数字定义成宏
#include<windows.h>
#include<time.h>
//开启前的创建函数（只执行一次）
void OnCreate();

void OnPaint(HDC hDC);
//画方块1
void PaintSquare(HDC HMemDC);
//画方块2
void PaintSquare2(HDC HMemDC);

//将方块所对应的“1”码变成“2”（以便不影响其他方块下落）
void Square1To2();
//产生随机方块
int CreateRandomSquare();
//方块变形(普通)
void SquareChange();
//方块变形(长条)
void SquareChangeLine();

//复制随机方块到背景
void CopySquareToBack();

//回车键函数（开始下落）
void OnKeyReturn(HWND hWnd);
//方向键“上”函数（变形）
void OnKeyUp(HWND hWnd);
//方向键“下”函数
void OnKeyDown(HWND hWnd);
//方向键“左”函数
void OnKeyLeft(HWND hWnd);
//方向键“右”函数
void OnKeyRight(HWND hWnd);

//方块下移
void SquareDownMove();
//方块左移
void SquareLeftMove();
//方块右移
void SquareRightMove();


//方块停在最底部
int SquareStopInFloor();
//方块停在方块上
int SquareStopOnOther();
//禁止左移穿墙
int SquareStopLeft();
//禁止左移穿方块
int SquareStopLeftO();
//禁止右移穿墙
int SquareStopRight();
//禁止右移穿方块
int SquareStopRightO();
//判断方块能否变形(普通)
int JudgeSquareChange();
//判断方块能否变形(长条)
int JudgeSquareChangeLine();

//消除满行方块
void DestroySquareLine();
//计时器函数
void OnTimer(HWND hWnd);
//显示分数
void ShowScore(HDC HMemDC);
//游戏结束
int GameOver(HWND hWnd);



#endif
