#include"elshead.h"
#include"resource.h"
LRESULT CALLBACK PELSFK(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//������
//WINAPI�� ����Լ��
//�����һ���������ڵ�Ψһ��ʶ
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//��ʼ��������
	//һ����ʮ������Ա�����ɶ�Ҳ������
	WNDCLASSEX wc;//WNDCLASS ��һ����չ������
	HWND hWnd;
	MSG mSg;
	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)COLOR_HIGHLIGHTTEXT;//���ڱ�������������ɫ����Ϣ
	//���Ĺ���ڲ�ͬ�����е���ʾ
	wc.hCursor = LoadCursor(hInstance,MAKEINTRESOURCE( IDC_NODROP));//����ϵͳ����ʽ LoadCursor(NULL,IDC_SIZENESW);
    //���ڵ�ͼ��
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE( IDI_ICON1));//����ϵͳͼ���ʽ  LoadIcon(NULL, IDI_ERROR);

	wc.hIconSm = NULL;//��Ļ�·���Сͼ��
	wc.hInstance = hInstance;
	wc.lpfnWndProc = PELSFK;//�ص������ĵ�ַ
	wc.lpszClassName = "els";//�������Ψһ��ʶ�����֣������ڸ�����ϵͳʶ��
	wc.lpszMenuName = NULL;//�˵�����
	wc.style = CS_HREDRAW | CS_VREDRAW;//��ֱ��ˮƽ

	//ע�ᴰ�ڶ����������ĳ�ʼ�����ڵĹ���ʧ�ܣ���˹���Ҳ��ʧ�ܣ�
	if (0==RegisterClassEx(&wc))//RegisterClassEx(&wc)����ֵ��ATOM��unsigned short����
	{
		int a = GetLastError();//�������ͨ�����ô˺��������Ի�ȡ����ı��룬�Ӷ��õ��������Ϣ
		return 0;//���ע�ᴰ����ʧ�ܣ�����0
	}

	//��������
	hWnd = CreateWindowEx(WS_EX_TOPMOST, "els", "���Ϸ���", WS_OVERLAPPEDWINDOW, 100, 30, 500, 640,
		NULL, NULL, hInstance, NULL);
	if (NULL==hWnd)
	{
		return 0;//������ڴ���ʧ�ܷ���0
	}

	//��ʾ����
	//��������ֵ��������ʾ����0��������ʾ���ط�0
	ShowWindow(hWnd, nCmdShow);//nCmdShow ������SW_SHOWNORMAL; ������ʾ
	
	//��Ϣѭ��
	//NULL��ʾ�ɴ���ǰʵ����������Ϣ����NULLֻ�����ض����ڵ���Ϣ; 0��0��ʾ�ɽ���������Ϣ
	while (GetMessage(&mSg,NULL,0,0))
	{
		//������Ϣ
		TranslateMessage(&mSg);//����Ϣ�����̰�������������ɵ��Եײ�ĵ��ź�ת��Ϊ����ϵͳ��ʶ����ַ�
	    //�ַ���Ϣ
		DispatchMessage(&mSg);//��׼��Ϣ ������Ϣ ֪ͨ��Ϣ �Զ�����Ϣ
	}
	return 0;
}

//��Ϣ�ص�����
//long
LRESULT CALLBACK PELSFK(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT pt;
	HDC hDC;
	switch (uMsg)
	{
	case WM_CREATE://���ڴ�������ִֻ��һ��
	    OnCreate();
		break;
	case WM_PAINT://�����ڴ�С�ı䣬�����ص�ʱ��������Ϣ
		hDC = BeginPaint(hWnd,&pt);//getDC  ���ڿɲ�������ı�ʶ
		//�������ϵ�����********************************************************************************************************
		OnPaint( hDC);
		//***********************************************************************************************************************
		EndPaint(hWnd,&pt);
		break;
	case WM_KEYDOWN:
	{
					   switch (wParam)
					   {
						   //�س�
					   case VK_RETURN:
						   OnKeyReturn(hWnd);
						   break;

						   //�ϱ���
					   case VK_UP:
						   OnKeyUp(hWnd);
						   break;

						   //�¼���
					   case VK_DOWN:
						   OnKeyDown(hWnd);
						   break;

						   //����
					   case VK_LEFT:
						   OnKeyLeft( hWnd);
						   break;

						   //����
					   case VK_RIGHT:
						   OnKeyRight(hWnd);
						   break;
					   }
	}
		break;

		//��ʱ����������Ϣ����
	case WM_TIMER:
		OnTimer(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);//ϵͳĬ�ϴ������Ϣ���൱��MFC�е�  return FALSE��
}
