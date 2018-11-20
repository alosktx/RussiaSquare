#include"elshead.h"
#include"resource.h"
LRESULT CALLBACK PELSFK(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//主函数
//WINAPI： 调用约定
//句柄：一个数，窗口的唯一标识
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//初始化窗口类
	//一共是十二个成员，不可多也不可少
	WNDCLASSEX wc;//WNDCLASS 的一个拓展窗口类
	HWND hWnd;
	MSG mSg;
	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)COLOR_HIGHLIGHTTEXT;//窗口背景，可设置颜色等信息
	//鼠标的光标在不同窗口中的显示
	wc.hCursor = LoadCursor(hInstance,MAKEINTRESOURCE( IDC_NODROP));//加载系统光标格式 LoadCursor(NULL,IDC_SIZENESW);
    //窗口的图标
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE( IDI_ICON1));//加载系统图标格式  LoadIcon(NULL, IDI_ERROR);

	wc.hIconSm = NULL;//屏幕下方的小图标
	wc.hInstance = hInstance;
	wc.lpfnWndProc = PELSFK;//回调函数的地址
	wc.lpszClassName = "els";//窗口类的唯一标识（名字），用于给操作系统识别
	wc.lpszMenuName = NULL;//菜单名字
	wc.style = CS_HREDRAW | CS_VREDRAW;//垂直，水平

	//注册窗口对象（如果上面的初始化窗口的过程失败，则此过程也会失败）
	if (0==RegisterClassEx(&wc))//RegisterClassEx(&wc)返回值是ATOM，unsigned short类型
	{
		int a = GetLastError();//如果出错，通过调用此函数，可以获取错误的标码，从而得到错误的信息
		return 0;//如果注册窗口类失败，返回0
	}

	//创建窗口
	hWnd = CreateWindowEx(WS_EX_TOPMOST, "els", "唐氏方块", WS_OVERLAPPEDWINDOW, 100, 30, 500, 640,
		NULL, NULL, hInstance, NULL);
	if (NULL==hWnd)
	{
		return 0;//如果窗口创建失败返回0
	}

	//显示窗口
	//函数返回值，隐藏显示返回0，正常显示返回非0
	ShowWindow(hWnd, nCmdShow);//nCmdShow 中隐藏SW_SHOWNORMAL; 正常显示
	
	//消息循环
	//NULL表示可处理当前实例的所有消息，非NULL只处理特定窗口的消息; 0，0表示可接受所有消息
	while (GetMessage(&mSg,NULL,0,0))
	{
		//翻译消息
		TranslateMessage(&mSg);//将消息（键盘按键，鼠标点击）由电脑底层的电信号转换为操作系统可识别的字符
	    //分发消息
		DispatchMessage(&mSg);//标准消息 命令消息 通知消息 自定义消息
	}
	return 0;
}

//消息回调函数
//long
LRESULT CALLBACK PELSFK(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT pt;
	HDC hDC;
	switch (uMsg)
	{
	case WM_CREATE://窗口创建初期只执行一次
	    OnCreate();
		break;
	case WM_PAINT://当窗口大小改变，或有重叠时产生此消息
		hDC = BeginPaint(hWnd,&pt);//getDC  窗口可操作区域的标识
		//画窗口上的内容********************************************************************************************************
		OnPaint( hDC);
		//***********************************************************************************************************************
		EndPaint(hWnd,&pt);
		break;
	case WM_KEYDOWN:
	{
					   switch (wParam)
					   {
						   //回车
					   case VK_RETURN:
						   OnKeyReturn(hWnd);
						   break;

						   //上变形
					   case VK_UP:
						   OnKeyUp(hWnd);
						   break;

						   //下加速
					   case VK_DOWN:
						   OnKeyDown(hWnd);
						   break;

						   //左移
					   case VK_LEFT:
						   OnKeyLeft( hWnd);
						   break;

						   //右移
					   case VK_RIGHT:
						   OnKeyRight(hWnd);
						   break;
					   }
	}
		break;

		//计时器产生的消息函数
	case WM_TIMER:
		OnTimer(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);//系统默认处理的消息。相当于MFC中的  return FALSE？
}
