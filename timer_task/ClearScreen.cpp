#include<bits\stdc++.h>
#include<windows.h>
using namespace std;
void clearScreen()
{
    HANDLE OPhandle;
    CONSOLE_SCREEN_BUFFER_INFO bufInfo;
    SMALL_RECT scroll;
    COORD newCursorPointer;
    CHAR_INFO ciFill;

    OPhandle = GetStdHandle(STD_OUTPUT_HANDLE);
    if(!GetConsoleScreenBufferInfo(OPhandle, &bufInfo))
        return;

	
	//cls
	    scroll.Left = 0;
    scroll.Top = 0;
    scroll.Right = bufInfo.dwSize.X;
    scroll.Bottom = bufInfo.dwSize.Y;
    newCursorPointer.X = 0;
    newCursorPointer.Y = -bufInfo.dwSize.Y;
    ciFill.Char.UnicodeChar = L'1';
    ciFill.Attributes = bufInfo.wAttributes;
    ScrollConsoleScreenBufferW(OPhandle, &scroll, NULL, newCursorPointer, &ciFill);
    newCursorPointer.Y = 0;
    SetConsoleCursorPosition(OPhandle, newCursorPointer);
	
	
	//
	printf("aaa\naaaaa\naaaaaaa\naaaaaaaaa");
	
	
	GetConsoleScreenBufferInfo(OPhandle, &bufInfo);
    scroll.Left = 0;
    scroll.Top = bufInfo.dwCursorPosition.Y;
    scroll.Right = bufInfo.dwSize.X;
    scroll.Bottom = bufInfo.dwCursorPosition.Y;
    newCursorPointer.X = 0;
    newCursorPointer.Y = -bufInfo.dwSize.Y;
    ciFill.Char.UnicodeChar = L' ';
    ciFill.Attributes = bufInfo.wAttributes;
    ScrollConsoleScreenBufferW(OPhandle, &scroll, NULL, newCursorPointer, &ciFill);
    newCursorPointer.X = 0;
	newCursorPointer.Y = bufInfo.dwCursorPosition.Y;
    SetConsoleCursorPosition(OPhandle, newCursorPointer);
}
//--------------------- 
//作者：Icy_Ybk 
//来源：CSDN 
//原文：https://blog.csdn.net/icy_ybk/article/details/79285245 
//版权声明：本文为博主原创文章，转载请附上博文链接！
int main()
{
//	cout<<"Screen\tCleaner\n";
//	system("pause");
//	double c=clock();
	clearScreen();
	getchar();
//	printf("dl\t%.3lfs\n",(clock()-c)*1.000/CLOCKS_PER_SEC);
//	system("pause");
//	cout<<"system\tcls\n";
//	system("pause");
//	c=clock();
//	system("cls");
//	printf("dl\t%.3lfs\n",(clock()-c)*1.000/CLOCKS_PER_SEC);
//	system("pause");
}
