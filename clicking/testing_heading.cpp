#define CLICK_CUSTOMBUFFER
#define CLICK_CUSTOMWDD
#define CLICK_CUSTOMWDLMT
//要在clicking之前定义预处理宏 
#include<iostream>
#include<windows.h>
using namespace std;

COORD CBufferSize={80,25};
const int WDD=5,WDLMT=205;
#include"clicking.h"
using namespace clicking;
int main()
{
	cout<<"即将打开example";
	Sleep(1000);
	_example();
}
