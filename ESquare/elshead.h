#ifndef DEF_ELS_HEAD
#define DEF_ELS_HEAD

#define DEE_TIMER1  1234   //һ�㽫�����о����ID���ֶ���ɺ�
#include<windows.h>
#include<time.h>
//����ǰ�Ĵ���������ִֻ��һ�Σ�
void OnCreate();

void OnPaint(HDC hDC);
//������1
void PaintSquare(HDC HMemDC);
//������2
void PaintSquare2(HDC HMemDC);

//����������Ӧ�ġ�1�����ɡ�2�����Ա㲻Ӱ�������������䣩
void Square1To2();
//�����������
int CreateRandomSquare();
//�������(��ͨ)
void SquareChange();
//�������(����)
void SquareChangeLine();

//����������鵽����
void CopySquareToBack();

//�س�����������ʼ���䣩
void OnKeyReturn(HWND hWnd);
//��������ϡ����������Σ�
void OnKeyUp(HWND hWnd);
//��������¡�����
void OnKeyDown(HWND hWnd);
//��������󡱺���
void OnKeyLeft(HWND hWnd);
//��������ҡ�����
void OnKeyRight(HWND hWnd);

//��������
void SquareDownMove();
//��������
void SquareLeftMove();
//��������
void SquareRightMove();


//����ͣ����ײ�
int SquareStopInFloor();
//����ͣ�ڷ�����
int SquareStopOnOther();
//��ֹ���ƴ�ǽ
int SquareStopLeft();
//��ֹ���ƴ�����
int SquareStopLeftO();
//��ֹ���ƴ�ǽ
int SquareStopRight();
//��ֹ���ƴ�����
int SquareStopRightO();
//�жϷ����ܷ����(��ͨ)
int JudgeSquareChange();
//�жϷ����ܷ����(����)
int JudgeSquareChangeLine();

//�������з���
void DestroySquareLine();
//��ʱ������
void OnTimer(HWND hWnd);
//��ʾ����
void ShowScore(HDC HMemDC);
//��Ϸ����
int GameOver(HWND hWnd);



#endif
