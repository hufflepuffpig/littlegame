#include<Windows.h>
#include<tchar.h>
#define DOWN 1
#define UP 2
#define LEFT 3
#define RIGHT 4

HINSTANCE hInst;
HBITMAP hBitmap_standdown,hBitmap_standdown_Mask,hBitmap_background,
		hBitmap_rundown1,hBitmap_rundown1_Mask,hBitmap_rundown2,hBitmap_rundown2_Mask,
		hBitmap_runleft1,hBitmap_runleft1_Mask,hBitmap_runleft2,hBitmap_runleft2_Mask,
		hBitmap_standleft,hBitmap_standleft_Mask,
		hBitmap_runright1,hBitmap_runright1_Mask,hBitmap_runright2,hBitmap_runright2_Mask,
		hBitmap_standright,hBitmap_standright_Mask,
		hBitmap_runup1,hBitmap_runup1_Mask,hBitmap_runup2,hBitmap_runup2_Mask,
		hBitmap_standup,hBitmap_standup_Mask,
		hBitmap_NPC,hBitmap_NPCMask,
		hBitmap_NPCHwndPic;

LRESULT CALLBACK WndProc(HWND hwnd,UINT uimsg,WPARAM wparam,LPARAM lparam)
{
	static HWND MainHwnd,NPCHwnd;
	static int cxClient,cyClient;
	if(uimsg==WM_CREATE)
	{
		hBitmap_background=LoadBitmap(hInst,TEXT("background"));
		hBitmap_standdown=LoadBitmap(hInst,TEXT("stand_down"));
		hBitmap_standdown_Mask=LoadBitmap(hInst,TEXT("stand_downMask"));
		hBitmap_rundown1=LoadBitmap(hInst,TEXT("run_down1"));
		hBitmap_rundown1_Mask=LoadBitmap(hInst,TEXT("run_down1Mask"));
		hBitmap_rundown2=LoadBitmap(hInst,TEXT("run_down2"));
		hBitmap_rundown2_Mask=LoadBitmap(hInst,TEXT("run_down2Mask"));

		hBitmap_standleft=LoadBitmap(hInst,TEXT("stand_left"));
		hBitmap_standleft_Mask=LoadBitmap(hInst,TEXT("stand_leftMask"));
		hBitmap_runleft1=LoadBitmap(hInst,TEXT("run_left1"));
		hBitmap_runleft1_Mask=LoadBitmap(hInst,TEXT("run_left1Mask"));
		hBitmap_runleft2=LoadBitmap(hInst,TEXT("run_left2"));
		hBitmap_runleft2_Mask=LoadBitmap(hInst,TEXT("run_left2Mask"));

		hBitmap_standright=LoadBitmap(hInst,TEXT("stand_right"));
		hBitmap_standright_Mask=LoadBitmap(hInst,TEXT("stand_rightMask"));
		hBitmap_runright1=LoadBitmap(hInst,TEXT("run_right1"));
		hBitmap_runright1_Mask=LoadBitmap(hInst,TEXT("run_right1Mask"));
		hBitmap_runright2=LoadBitmap(hInst,TEXT("run_right2"));
		hBitmap_runright2_Mask=LoadBitmap(hInst,TEXT("run_right2Mask"));

		hBitmap_standup=LoadBitmap(hInst,TEXT("stand_up"));
		hBitmap_standup_Mask=LoadBitmap(hInst,TEXT("stand_upMask"));
		hBitmap_runup1=LoadBitmap(hInst,TEXT("run_up1"));
		hBitmap_runup1_Mask=LoadBitmap(hInst,TEXT("run_up1Mask"));
		hBitmap_runup2=LoadBitmap(hInst,TEXT("run_up2"));
		hBitmap_runup2_Mask=LoadBitmap(hInst,TEXT("run_up2Mask"));

		hBitmap_NPC=LoadBitmap(hInst,TEXT("NPC"));
		hBitmap_NPCMask=LoadBitmap(hInst,TEXT("NPCMask"));

		hBitmap_NPCHwndPic=LoadBitmap(hInst,TEXT("NPCHwndPic"));

		MainHwnd=CreateWindow(TEXT("MainView"),NULL,WS_CHILD | WS_VISIBLE,0,0,0,0,hwnd,(HMENU)1,((LPCREATESTRUCT)lparam)->hInstance,NULL);
		NPCHwnd=CreateWindow(TEXT("NPCView"),NULL,WS_CHILD,0,0,0,0,hwnd,(HMENU)2,((LPCREATESTRUCT)lparam)->hInstance,NULL);
		return 0;
	}
	else if(uimsg==WM_SIZE)
	{
		cxClient=LOWORD(lparam);
		cyClient=HIWORD(lparam);
		MoveWindow(MainHwnd,0,0,cxClient,cyClient,true);
		MoveWindow(NPCHwnd,0,cyClient-65,cxClient,65,true);
		return 0;
	}
	else if(uimsg==WM_SETFOCUS)
	{
		if(IsWindowVisible(MainHwnd))
			SetFocus(MainHwnd);
		else if(IsWindowVisible(NPCHwnd))
			SetFocus(NPCHwnd);
		return 0;
	}
	else if(uimsg==WM_USER)
	{
		if(wparam==0)//进入NPC界面
		{
			//ShowWindow(MainHwnd,SW_HIDE);
			ShowWindow(NPCHwnd,SW_SHOW);
			SetFocus(NPCHwnd);
		}
		else if(wparam==1)//退出NPC界面
		{
			ShowWindow(NPCHwnd,SW_HIDE);
			ShowWindow(MainHwnd,SW_SHOW);
			SetFocus(MainHwnd);
		}
		return 0;
	}
	else if(uimsg==WM_DESTROY)
	{
		DeleteObject(hBitmap_background);
		DeleteObject(hBitmap_standdown);
		DeleteObject(hBitmap_standdown_Mask);
		DeleteObject(hBitmap_rundown1);
		DeleteObject(hBitmap_rundown1_Mask);
		DeleteObject(hBitmap_rundown2);
		DeleteObject(hBitmap_rundown2_Mask);

		DeleteObject(hBitmap_standleft);
		DeleteObject(hBitmap_standleft_Mask);
		DeleteObject(hBitmap_runleft1);
		DeleteObject(hBitmap_runleft1_Mask);
		DeleteObject(hBitmap_runleft2);
		DeleteObject(hBitmap_runleft2_Mask);

		DeleteObject(hBitmap_standright);
		DeleteObject(hBitmap_standright_Mask);
		DeleteObject(hBitmap_runright1);
		DeleteObject(hBitmap_runright1_Mask);
		DeleteObject(hBitmap_runright2);
		DeleteObject(hBitmap_runright2_Mask);

		DeleteObject(hBitmap_standup);
		DeleteObject(hBitmap_standup_Mask);
		DeleteObject(hBitmap_runup1);
		DeleteObject(hBitmap_runup1_Mask);
		DeleteObject(hBitmap_runup2);
		DeleteObject(hBitmap_runup2_Mask);

		DeleteObject(hBitmap_NPC);
		DeleteObject(hBitmap_NPCMask);
		DeleteObject(hBitmap_NPCHwndPic);

		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd,uimsg,wparam,lparam);
}

LRESULT CALLBACK MainWndProc(HWND hwnd,UINT uimsg,WPARAM wparam,LPARAM lparam)
{
	static int cxClient,cyClient,iCurrentx,iCurrenty;
	static bool fDrawInitPerson=true;
	static int iDirection=DOWN;
	HDC hdc,hdcMem,hdcMemMask,hdcMemBackground;
	PAINTSTRUCT ps;
	
	if(uimsg==WM_SIZE)
	{
		cxClient=LOWORD(lparam);
		cyClient=HIWORD(lparam);
		iCurrentx=cxClient/2-35/2;
		iCurrenty=cyClient/2-30;
		return 0;
	}
	else if(uimsg==WM_PAINT)
	{
		hdc=BeginPaint(hwnd,&ps);

		hdcMemBackground=CreateCompatibleDC(hdc);
		SelectObject(hdcMemBackground,hBitmap_background);
		StretchBlt(hdc,0,0,cxClient,cyClient/2,hdcMemBackground,0,0,240,160,SRCCOPY);
		DeleteDC(hdcMemBackground);

		hdcMem=CreateCompatibleDC(hdc);
		hdcMemMask=CreateCompatibleDC(hdc);
		SelectObject(hdcMem,hBitmap_NPC);
		SelectObject(hdcMemMask,hBitmap_NPCMask);
		BitBlt(hdc,0,cyClient/2-60,35,60,hdcMemMask,0,0,0x220326);
		BitBlt(hdc,0,cyClient/2-60,35,60,hdcMem,0,0,SRCPAINT);
		DeleteDC(hdcMem);
		DeleteDC(hdcMemMask);

		if(fDrawInitPerson)
		{
			hdcMem=CreateCompatibleDC(hdc);
			hdcMemMask=CreateCompatibleDC(hdc);
			if(iDirection==DOWN)
			{
				SelectObject(hdcMem,hBitmap_standdown);
				SelectObject(hdcMemMask,hBitmap_standdown_Mask);
			}
			else if(iDirection==UP)
			{
				SelectObject(hdcMem,hBitmap_standup);
				SelectObject(hdcMemMask,hBitmap_standup_Mask);
			}
			else if(iDirection==LEFT)
			{
				SelectObject(hdcMem,hBitmap_standleft);
				SelectObject(hdcMemMask,hBitmap_standleft_Mask);
			}
			else if(iDirection==RIGHT)
			{
				SelectObject(hdcMem,hBitmap_standright);
				SelectObject(hdcMemMask,hBitmap_standright_Mask);
			}
			BitBlt(hdc,iCurrentx,iCurrenty,35,60,hdcMemMask,0,0,0x220326);
			BitBlt(hdc,iCurrentx,iCurrenty,35,60,hdcMem,0,0,SRCPAINT);
			DeleteDC(hdcMemMask);
			DeleteDC(hdcMem);
		}

		EndPaint(hwnd,&ps);
		return 0;
	}
	else if(uimsg==WM_KEYDOWN)
	{
		RECT rect;
		hdc=GetDC(hwnd);
		hdcMem=CreateCompatibleDC(hdc);
		hdcMemMask=CreateCompatibleDC(hdc);
		if(wparam==VK_DOWN)
		{
			SelectObject(hdcMem,hBitmap_rundown1);
			SelectObject(hdcMemMask,hBitmap_rundown1_Mask);
			fDrawInitPerson=false;
			InvalidateRect(hwnd,NULL,true);
			UpdateWindow(hwnd);
			BitBlt(hdc,iCurrentx,min(iCurrenty+5,cyClient-60),35,60,hdcMemMask,0,0,0x220326);
			BitBlt(hdc,iCurrentx,min(iCurrenty+5,cyClient-60),35,60,hdcMem,0,0,SRCPAINT);
			Sleep(100);
			SelectObject(hdcMem,hBitmap_standdown);
			SelectObject(hdcMemMask,hBitmap_standdown_Mask);
			InvalidateRect(hwnd,NULL,true);
			UpdateWindow(hwnd);
			BitBlt(hdc,iCurrentx,min(iCurrenty+10,cyClient-60),35,60,hdcMemMask,0,0,0x220326);
			BitBlt(hdc,iCurrentx,min(iCurrenty+10,cyClient-60),35,60,hdcMem,0,0,SRCPAINT);
			Sleep(100);
			SelectObject(hdcMem,hBitmap_rundown2);
			SelectObject(hdcMemMask,hBitmap_rundown2_Mask);
			InvalidateRect(hwnd,NULL,true);
			UpdateWindow(hwnd);
			BitBlt(hdc,iCurrentx,min(iCurrenty+15,cyClient-60),35,60,hdcMemMask,0,0,0x220326);
			BitBlt(hdc,iCurrentx,min(iCurrenty+15,cyClient-60),35,60,hdcMem,0,0,SRCPAINT);
			Sleep(100);
			SelectObject(hdcMem,hBitmap_standdown);
			SelectObject(hdcMemMask,hBitmap_standdown_Mask);
			InvalidateRect(hwnd,NULL,true);
			UpdateWindow(hwnd);
			BitBlt(hdc,iCurrentx,min(iCurrenty+20,cyClient-60),35,60,hdcMemMask,0,0,0x220326);
			BitBlt(hdc,iCurrentx,min(iCurrenty+20,cyClient-60),35,60,hdcMem,0,0,SRCPAINT);

			iCurrenty=min(iCurrenty+20,cyClient-60);
			iDirection=DOWN;
			
		}
		
		else if(wparam==VK_LEFT)
		{
			SelectObject(hdcMem,hBitmap_runleft1);
			SelectObject(hdcMemMask,hBitmap_runleft1_Mask);
			fDrawInitPerson=false;
			InvalidateRect(hwnd,NULL,true);
			UpdateWindow(hwnd);
			BitBlt(hdc,max(iCurrentx-5,0),iCurrenty,35,60,hdcMemMask,0,0,0x220326);
			BitBlt(hdc,max(iCurrentx-5,0),iCurrenty,35,60,hdcMem,0,0,SRCPAINT);
			Sleep(100);
			SelectObject(hdcMem,hBitmap_standleft);
			SelectObject(hdcMemMask,hBitmap_standleft_Mask);
			InvalidateRect(hwnd,NULL,true);
			UpdateWindow(hwnd);
			BitBlt(hdc,max(iCurrentx-10,0),iCurrenty,35,60,hdcMemMask,0,0,0x220326);
			BitBlt(hdc,max(iCurrentx-10,0),iCurrenty,35,60,hdcMem,0,0,SRCPAINT);
			Sleep(100);
			SelectObject(hdcMem,hBitmap_runleft2);
			SelectObject(hdcMemMask,hBitmap_runleft2_Mask);
			InvalidateRect(hwnd,NULL,true);
			UpdateWindow(hwnd);
			BitBlt(hdc,max(iCurrentx-15,0),iCurrenty,35,60,hdcMemMask,0,0,0x220326);
			BitBlt(hdc,max(iCurrentx-15,0),iCurrenty,35,60,hdcMem,0,0,SRCPAINT);
			Sleep(100);
			SelectObject(hdcMem,hBitmap_standleft);
			SelectObject(hdcMemMask,hBitmap_standleft_Mask);
			InvalidateRect(hwnd,NULL,true);
			UpdateWindow(hwnd);
			BitBlt(hdc,max(iCurrentx-20,0),iCurrenty,35,60,hdcMemMask,0,0,0x220326);
			BitBlt(hdc,max(iCurrentx-20,0),iCurrenty,35,60,hdcMem,0,0,SRCPAINT);

			iCurrentx=max(iCurrentx-20,0);
			iDirection=LEFT;
		}

		else if(wparam==VK_RIGHT)
		{
			SelectObject(hdcMem,hBitmap_runright1);
			SelectObject(hdcMemMask,hBitmap_runright1_Mask);
			fDrawInitPerson=false;
			InvalidateRect(hwnd,NULL,true);
			UpdateWindow(hwnd);
			BitBlt(hdc,min(iCurrentx+5,cxClient-35),iCurrenty,35,60,hdcMemMask,0,0,0x220326);
			BitBlt(hdc,min(iCurrentx+5,cxClient-35),iCurrenty,35,60,hdcMem,0,0,SRCPAINT);
			Sleep(100);
			SelectObject(hdcMem,hBitmap_standright);
			SelectObject(hdcMemMask,hBitmap_standright_Mask);
			InvalidateRect(hwnd,NULL,true);
			UpdateWindow(hwnd);
			BitBlt(hdc,min(iCurrentx+10,cxClient-35),iCurrenty,35,60,hdcMemMask,0,0,0x220326);
			BitBlt(hdc,min(iCurrentx+10,cxClient-35),iCurrenty,35,60,hdcMem,0,0,SRCPAINT);
			Sleep(100);
			SelectObject(hdcMem,hBitmap_runright2);
			SelectObject(hdcMemMask,hBitmap_runright2_Mask);
			InvalidateRect(hwnd,NULL,true);
			UpdateWindow(hwnd);
			BitBlt(hdc,min(iCurrentx+15,cxClient-35),iCurrenty,35,60,hdcMemMask,0,0,0x220326);
			BitBlt(hdc,min(iCurrentx+15,cxClient-35),iCurrenty,35,60,hdcMem,0,0,SRCPAINT);
			Sleep(100);
			SelectObject(hdcMem,hBitmap_standright);
			SelectObject(hdcMemMask,hBitmap_standright_Mask);
			InvalidateRect(hwnd,NULL,true);
			UpdateWindow(hwnd);
			BitBlt(hdc,min(iCurrentx+20,cxClient-35),iCurrenty,35,60,hdcMemMask,0,0,0x220326);
			BitBlt(hdc,min(iCurrentx+20,cxClient-35),iCurrenty,35,60,hdcMem,0,0,SRCPAINT);

			iCurrentx=min(iCurrentx+20,cxClient-35);
			iDirection=RIGHT;
		}

		else if(wparam==VK_UP)
		{
			SelectObject(hdcMem,hBitmap_runup1);
			SelectObject(hdcMemMask,hBitmap_runup1_Mask);
			fDrawInitPerson=false;
			InvalidateRect(hwnd,NULL,true);
			UpdateWindow(hwnd);
			BitBlt(hdc,iCurrentx,max(iCurrenty-5,cyClient/2-30),35,60,hdcMemMask,0,0,0x220326);
			BitBlt(hdc,iCurrentx,max(iCurrenty-5,cyClient/2-30),35,60,hdcMem,0,0,SRCPAINT);
			Sleep(100);
			SelectObject(hdcMem,hBitmap_standup);
			SelectObject(hdcMemMask,hBitmap_standup_Mask);
			InvalidateRect(hwnd,NULL,true);
			UpdateWindow(hwnd);
			BitBlt(hdc,iCurrentx,max(iCurrenty-10,cyClient/2-30),35,60,hdcMemMask,0,0,0x220326);
			BitBlt(hdc,iCurrentx,max(iCurrenty-10,cyClient/2-30),35,60,hdcMem,0,0,SRCPAINT);
			Sleep(100);
			SelectObject(hdcMem,hBitmap_runup2);
			SelectObject(hdcMemMask,hBitmap_runup2_Mask);
			InvalidateRect(hwnd,NULL,true);
			UpdateWindow(hwnd);
			BitBlt(hdc,iCurrentx,max(iCurrenty-15,cyClient/2-30),35,60,hdcMemMask,0,0,0x220326);
			BitBlt(hdc,iCurrentx,max(iCurrenty-15,cyClient/2-30),35,60,hdcMem,0,0,SRCPAINT);
			Sleep(100);
			SelectObject(hdcMem,hBitmap_standup);
			SelectObject(hdcMemMask,hBitmap_standup_Mask);
			InvalidateRect(hwnd,NULL,true);
			UpdateWindow(hwnd);
			BitBlt(hdc,iCurrentx,max(iCurrenty-20,cyClient/2-30),35,60,hdcMemMask,0,0,0x220326);
			BitBlt(hdc,iCurrentx,max(iCurrenty-20,cyClient/2-30),35,60,hdcMem,0,0,SRCPAINT);

			iCurrenty=max(iCurrenty-20,cyClient/2-30);
			iDirection=UP;
		}

		else if(wparam==VK_SPACE)
		{
			if(iDirection==LEFT)
			{
				SelectObject(hdcMem,hBitmap_runleft1);
				SelectObject(hdcMemMask,hBitmap_runleft1_Mask);
				fDrawInitPerson=false;
				InvalidateRect(hwnd,NULL,true);
				UpdateWindow(hwnd);
				BitBlt(hdc,max(0,iCurrentx-8),max(0,iCurrenty-10),35,60,hdcMemMask,0,0,0x220326);
				BitBlt(hdc,max(0,iCurrentx-8),max(0,iCurrenty-10),35,60,hdcMem,0,0,SRCPAINT);
				Sleep(100);
				SelectObject(hdcMem,hBitmap_standleft);
				SelectObject(hdcMemMask,hBitmap_standleft_Mask);
				InvalidateRect(hwnd,NULL,true);
				UpdateWindow(hwnd);
				BitBlt(hdc,max(0,iCurrentx-16),iCurrenty,35,60,hdcMemMask,0,0,0x220326);
				BitBlt(hdc,max(0,iCurrentx-16),iCurrenty,35,60,hdcMem,0,0,SRCPAINT);

				iCurrentx=max(0,iCurrentx-16);
			}
			else if(iDirection==RIGHT)
			{
				SelectObject(hdcMem,hBitmap_runright1);
				SelectObject(hdcMemMask,hBitmap_runright1_Mask);
				fDrawInitPerson=false;
				InvalidateRect(hwnd,NULL,true);
				UpdateWindow(hwnd);
				BitBlt(hdc,min(cxClient-35,iCurrentx+8),max(0,iCurrenty-10),35,60,hdcMemMask,0,0,0x220326);
				BitBlt(hdc,min(cxClient-35,iCurrentx+8),max(0,iCurrenty-10),35,60,hdcMem,0,0,SRCPAINT);
				Sleep(100);
				SelectObject(hdcMem,hBitmap_standright);
				SelectObject(hdcMemMask,hBitmap_standright_Mask);
				InvalidateRect(hwnd,NULL,true);
				UpdateWindow(hwnd);
				BitBlt(hdc,min(cxClient-35,iCurrentx+16),iCurrenty,35,60,hdcMemMask,0,0,0x220326);
				BitBlt(hdc,min(cxClient-35,iCurrentx+16),iCurrenty,35,60,hdcMem,0,0,SRCPAINT);

				iCurrentx=min(cxClient-35,iCurrentx+16);
			}
			else if(iDirection==UP && iCurrentx==0 && iCurrenty==cyClient/2-30)
			{
				SendMessage((HWND)GetWindowLong(hwnd,GWL_HWNDPARENT),WM_USER,0,0);
			}
		}

		DeleteDC(hdcMemMask);
		DeleteDC(hdcMem);
		ReleaseDC(hwnd,hdc);

		return 0;
	}
	else if(uimsg==WM_SETFOCUS)
	{
		fDrawInitPerson=true;
		InvalidateRect(hwnd,NULL,true);
		return 0;
	}

	return DefWindowProc(hwnd,uimsg,wparam,lparam);
}

LRESULT CALLBACK NPCWndProc(HWND hwnd,UINT uimsg,WPARAM wparam,LPARAM lparam)
{
	HDC hdc,hdcSrc;
	PAINTSTRUCT ps;
	if(uimsg==WM_PAINT)
	{
		hdc=BeginPaint(hwnd,&ps);
		hdcSrc=CreateCompatibleDC(hdc);
		SelectObject(hdcSrc,hBitmap_NPCHwndPic);
		BitBlt(hdc,0,0,50,65,hdcSrc,0,0,SRCCOPY);
		DeleteDC(hdcSrc);

		SetBkMode(hdc,TRANSPARENT);
		SetTextColor(hdc,RGB(255,255,255));
		TextOut(hdc,52,0,TEXT("你遇见一对情侣秀恩爱，你会怎么做？"),wcslen(TEXT("你遇见一对情侣秀恩爱，你会怎么做？")));
		TextOut(hdc,52,20,TEXT("A.默默祝福     B.果断烧死"),wcslen(TEXT("A.默默祝福     B.果断烧死")));
		EndPaint(hwnd,&ps);
		return 0;
	}
	else if(uimsg==WM_CHAR)
	{
		if(wparam=='a')
		{
			static int iKeep[100][4];
			int cx,cy,x1,y1,x2,y2;
			HWND hwnd;
			HDC hdcSrc,hdcMem;
			HBITMAP hBitmap;

			if(LockWindowUpdate(hwnd=GetDesktopWindow()))
			{
				hdcSrc=GetDCEx(hwnd,NULL,DCX_CACHE | DCX_LOCKWINDOWUPDATE);
				hdcMem=CreateCompatibleDC(hdcSrc);
				cx=GetSystemMetrics(SM_CXSCREEN)/10;
				cy=GetSystemMetrics(SM_CYSCREEN)/10;
				hBitmap=CreateCompatibleBitmap(hdcSrc,cx,cy);
				SelectObject(hdcMem,hBitmap);

				srand((int)GetCurrentTime());
				for(int i=0;i<2;i++)
				{
					for(int j=0;j<100;j++)
					{
						if(i==0)
						{
							iKeep[j][0]=x1=cx*(rand()%10);
							iKeep[j][1]=y1=cy*(rand()%10);
							iKeep[j][2]=x2=cx*(rand()%10);
							iKeep[j][3]=y2=cy*(rand()%10);
						}
						else
						{
							x1=iKeep[100-1-j][0];
							y1=iKeep[100-1-j][1];
							x2=iKeep[100-1-j][2];
							y2=iKeep[100-1-j][3];
						}
						BitBlt(hdcMem,0,0,cx,cy,hdcSrc,x1,y1,SRCCOPY);
						BitBlt(hdcSrc,x1,y1,cx,cy,hdcSrc,x2,y2,SRCCOPY);
						BitBlt(hdcSrc,x2,y2,cx,cy,hdcMem,0,0,SRCCOPY);
						Sleep(10);
					}
				}


				DeleteDC(hdcMem);
				ReleaseDC(hwnd,hdcSrc);
				DeleteObject(hBitmap); 
				LockWindowUpdate(NULL);
			}
		}
		else if(wparam=='b')
		{
			//hdc=GetDC(hwnd);
			//TextOut(hdc,0,100,TEXT("走到左右侧边缘，空格跳出就行"),wcslen(TEXT("走到左右侧边缘，空格跳出就行")));
			//ReleaseDC(hwnd,hdc);
			//Sleep(4000);
			SendMessage((HWND)GetWindowLong(hwnd,GWL_HWNDPARENT),WM_USER,1,0);
		}
		return 0;
	}
	return DefWindowProc(hwnd,uimsg,wparam,lparam);
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,LPSTR szCmdLine,int iCmdShow)
{
	TCHAR szAPPName[]=TEXT("GameTrying");
	HWND hwnd;
	MSG msg;
	hInst=hInstance;
	WNDCLASS wndcls;
	wndcls.cbClsExtra=0;
	wndcls.cbWndExtra=0;
	wndcls.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	wndcls.hCursor=LoadCursor(NULL,IDC_ARROW);
	wndcls.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	wndcls.hInstance=hInstance;
	wndcls.lpfnWndProc=WndProc;
	wndcls.lpszClassName=szAPPName;
	wndcls.lpszMenuName=NULL;
	wndcls.style=CS_VREDRAW | CS_HREDRAW;
	RegisterClass(&wndcls);

	wndcls.hIcon=NULL;
	wndcls.lpfnWndProc=MainWndProc;
	wndcls.lpszClassName=TEXT("MainView");
	RegisterClass(&wndcls);

	wndcls.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);
	wndcls.lpfnWndProc=NPCWndProc;
	wndcls.lpszClassName=TEXT("NPCView");
	RegisterClass(&wndcls);

	hwnd=CreateWindow(szAPPName,TEXT("Title"),WS_OVERLAPPEDWINDOW & !WS_THICKFRAME,CW_USEDEFAULT,CW_USEDEFAULT,320,480,
		NULL,NULL,hInstance,NULL);
	ShowWindow(hwnd,iCmdShow);
	UpdateWindow(hwnd);

	while(1)
	{
		bool bGetMsg=GetMessage(&msg,NULL,0,0);
		if(bGetMsg)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
			break;
	}
}