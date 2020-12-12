
/**----------------------------------------------------------------
Clicking_System () **������**
About{
Create:lz
Coded:V1.0 to latest:lz,yyc
Debug:V1.0 to latest:lz
Contributor:yyc,Icy_Ybk
Other license:
//Run _example() to learn to use or ask the editor.
//I will be thankful if you discover any bug in it.
PS:��û��װ�ƣ������Լ�����awa... 
֪ʶ�������Э��
����Ʒ����֪ʶ��������-����ҵ��ʹ��-��ͬ��ʽ���� 4.0 �������Э�������ɡ�
https://creativecommons.org/Licence/by-nc-sa/4.0/
��ϵ���ߣ�qq:1612162886(��֤��Ϣע������ͨ������ע�ҵ���)�����ID��43845����OIer����luogu����
Github��ַ��https://github.com/ystkc/Public-Project/tree/master/clicking 
}
**/

#ifndef _CLICKING_
#define _CLICKING_
#endif


#include<cstdio>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<windows.h>
#include<pthread.h>

#ifndef WIN_PTHREADS_H
#error please use TDM-GCC 4.9.2 library.
#endif

#include<cmath>
#include<conio.h>
#include<tchar.h>

/*LZ���X�mר��color��*/
#define TextDeep() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_INTENSITY ))
#define TextNormal() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_RED |FOREGROUND_BLUE |FOREGROUND_GREEN ))
#define TextDeepBlue() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_INTENSITY |FOREGROUND_BLUE))
#define TextDeepGreen() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_INTENSITY |FOREGROUND_GREEN))
#define TextDeepRed() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_INTENSITY |FOREGROUND_RED))
#define TextDeepYellow() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN))
#define TextDeepPink() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_BLUE))
#define TextDeepCyan() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_INTENSITY |FOREGROUND_GREEN |FOREGROUND_BLUE))
#define TextBlue() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_BLUE))
#define TextGreen() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_GREEN))
#define TextRed() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_RED))
#define BackgroundDeepBlue() (SetConsoleTextAttribute(COutputHandle,BACKGROUND_INTENSITY |BACKGROUND_BLUE))
#define BackgroundDeepGreen() (SetConsoleTextAttribute(COutputHandle,BACKGROUND_INTENSITY |BACKGROUND_GREEN))
#define BackgroundDeepRed() (SetConsoleTextAttribute(COutputHandle,BACKGROUND_INTENSITY |BACKGROUND_RED))
#define BackgroundDeepYellow() (SetConsoleTextAttribute(COutputHandle,BACKGROUND_INTENSITY |BACKGROUND_RED |BACKGROUND_GREEN))
#define BackgroundDeepPink() (SetConsoleTextAttribute(COutputHandle,BACKGROUND_INTENSITY |BACKGROUND_RED |BACKGROUND_BLUE))
#define BackgroundDeepCyan() (SetConsoleTextAttribute(COutputHandle,BACKGROUND_INTENSITY |BACKGROUND_GREEN |BACKGROUND_BLUE))
#define BackgroundBlue() (SetConsoleTextAttribute(COutputHandle,BACKGROUND_BLUE))
#define BackgroundGreen() (SetConsoleTextAttribute(COutputHandle,BACKGROUND_GREEN))
#define BackgroundRed() (SetConsoleTextAttribute(COutputHandle,BACKGROUND_RED))
/*
//��ɫ�ο� 
FOREGROUND_BLUE 0x1
FOREGROUND_GREEN 0x2
FOREGROUND_RED 0x4
FOREGROUND_INTENSITY 0x8
BACKGROUND_BLUE 0x10
BACKGROUND_GREEN 0x20
BACKGROUND_RED 0x40
BACKGROUND_INTENSITY 0x80
*/

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define CW_USEDEFAULT       ((int)0x80000000)
#define OptionsDeep() (SetConsoleTextAttribute(COutputHandle, wOldColorAttrs==0?7:wOldColorAttrs))
#define HightLight() (SetConsoleTextAttribute(COutputHandle, 0x1|0x4|0x8|0x20|0x40|0x80))
#define HideCursor() {CCursorInfo.bVisible = false;SetConsoleCursorInfo(COutputHandle, &CCursorInfo);}
#define ShowCursor() {CCursorInfo.bVisible = true;SetConsoleCursorInfo(COutputHandle, &CCursorInfo);}
#define AutoAlign() {GetWindowRect(CMainHwnd,&CWindowRect);if(CWindowRect.left!=-32000)CConsoleLeft=CWindowRect.left+CConsoleBoard,CConsoleRight=CWindowRect.right-CConsoleTopBoard,CConsoleTop=CWindowRect.top+CConsoleTopBoard,CConsoleBottom=CWindowRect.bottom-CConsoleBoard;}
#define ChangeWindowPosition( Px, Py, Cx, Cy) (MoveWindow(CMainHwnd,Px,Py,Cx,Cy,TRUE))
#define SetWindowPosition( Px, Py) (SetWindowPos(CMainHwnd, HWND_NOTOPMOST, Px, Py, 0, 0,SWP_NOSIZE))
#define Oscillate(WindowRect) {SetWindowPosition(WindowRect.left,WindowRect.top+1);SetWindowPosition(WindowRect.left,WindowRect.top);ChangeWindowPosition(WindowRect.left,WindowRect.top+50,WindowRect.right-WindowRect.left,WindowRect.bottom-WindowRect.top-50);ChangeWindowPosition(WindowRect.left,WindowRect.top,WindowRect.right-WindowRect.left,WindowRect.bottom-WindowRect.top);}
#define lInitial() {SetWindowLong(CMainHwnd, GWL_STYLE, CWindowOldLong);SetConsoleTitle(CTitle);Oscillate(CTempRect);CConsoleTopBoard=30;}
#define lSuspend() {SetWindowLong(CMainHwnd, GWL_STYLE, GetWindowLong(CMainHwnd, GWL_STYLE) & WS_CAPTION);CTempRect=CWindowRect;}
#define lFreeze() {SetWindowLong(CMainHwnd, GWL_STYLE, GetWindowLong(CMainHwnd, GWL_STYLE) & ~WS_CAPTION);CConsoleTopBoard=8;CTempRect=CWindowRect;Oscillate(CTempRect);}
#define ChineseCheck( k1, k2) ((k1&0x80)&&(k2&0x80))

//#define CLICK_RELEASE	//ȥ��һ���޹���� 
//#define CLICK_SIMPLE	//����� 

//������Ҫ���۽��ˣ�����û��һ����ʽ��ͷ�ļ���Ѻ���ʵ��һ��������һ��ͷ�ļ�����
//�������˾���û��Ҫ��ʵ�ֺͽӿڷ��� 
class Click {//�鹹�� 
public:
#ifndef CLICK_SIMPLE//��һЩ��ֵĶ�������򻯰�Ͳ�Ҫ�� 
	virtual int INTSc(int linenum, int number) const = 0;//�ļ��� 
	virtual bool LinePr(char* COptionsFileName, int linenum,std::string ot)const = 0;//�ļ�д(��COptionsFileName�ļ���linenum��Ϊot)
	virtual void CAreaSelect(int left,int top,int right,int down,int &px,int &py)const = 0;//area selecting����ѡ��* 
	virtual void _example()const = 0;
#endif
	
//	virtual -Click();
	virtual void CWriteWindow(int wd,int x,int y,std::string s,int ct,std::string cm,int cml,int cmt,int cmdl,int cmmd,int cmbds,int cl)const = 0;//menu writing system�˵�д��ϵͳ*
	virtual void CShowWindow(int wd)const = 0;//��ʾ����k ,������CEnabled=0ʱ���� 
	virtual void CHideWindow(int wd)const = 0;//���ش���k ,������CEnabled=0ʱ����
	virtual void CCreateWindow(int wd,int wdbds,std::string wdtp,int cwl,int cwt,int cwr,int cwb)const = 0;//window writing system���ڴ���ϵͳ
	virtual void CDeleteWindow(int k)const = 0;//ɾ������k 
	virtual void msgbox(int wd,int sx,int sy,int cl,std::string msg,int md,int bdstyle)const = 0;//MessageBox��Ϣ�� 
	virtual void CLockWindow(int wd)const = 0;
	virtual void COpenThread(int delay/*LEAST 50!*/,int window,int to_be_continued)const = 0;//menu choosing system starter�˵�ѡ��ϵͳ��������_�߳�* 
	virtual void COpenWindow(int delay/*LEAST 50!*/,int window,int to_be_continued)const = 0;//menu choosing system starter�˵�ѡ��ϵͳ��������_�ȴ�* 
	virtual void CCloseWindow()const = 0;
};

#include"clicking.cpp"
