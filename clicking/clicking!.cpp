
/**----------------------------------------------------------------
Clicking_System () **完整版**
About{
Create:lz
Coded:V1.0 to latest:lz,yyc
Debug:V1.0 to latest:lz
Contributor:yyc,Icy_Ybk
Other license:
//Run _example() to learn to use or ask the editor.
//I will be thankful if you discover any bug in it.
PS:并没有装逼，都是自己翻的awa... 
知识共享许可协议
本作品采用知识共享署名-非商业性使用-相同方式共享 4.0 国际许可协议进行许可。
https://creativecommons.org/Licence/by-nc-sa/4.0/
（其实我也只是编来玩，没有谋求利益的意思，这还可以被更多人认可，为什么不呢？）
联系作者：qq:1612162886(验证信息注明你是通过程序备注找到的)；洛谷ID：43845（是OIer就来luogu啊）
Github地址：https://github.com/ystkc/Public-Project/tree/master/clicking 
}
**/

//#ifndef _CLICKING_//如果你想把我当作cpp来编译，那么请注释掉这三行 
//#define _CLICKING_
//#endif


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
using namespace std;

/*LZ的蒟蒻专用color库*/
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
//颜色参考 
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

//#define CLICK_RELEASE//去除一切无关输出 
//#define CLICK_SIMPLE//精简版 

//接下来要大开眼界了，估计没有一个正式的头文件会把函数实现一股脑塞进一个头文件里面
//不过个人觉得没必要把实现和接口分离 



//CSYS NORMAL SYMBOL!--------------------------------

//Library
const char ChineseSymbol=''/*(char)1:USE IT if you need to recognize the next two char as a chinese*/,EndlSympol='}';
string MessageboxLeftBoard[]={"|","*","#","+",""," ","  ","│","┃","┆","┇","┊","┋","╳","□","■","█","▌","○","●","☆","★","?","?","?"}
	  ,MessageboxTopBoard[]={"-","*","#","+",""," ","  ","─","━","┄","┅","┈","┉","╳","□","■","█","▄","○","●","☆","★","?","?","?"};
string WindowLeftBoard[]={"|","*","#","+"," ","!","?","'",".","+"}
	  ,WindowTopBoard[]={"-","*","#","+"," ","!","?","'",".","="};
char Ch0[]="┼",Ch1[]="╋",En0[]="+",En1[]="*",Sp0[]="╬",Sp1[]="#";//光标形式 (1个半角或全角字符)
const string Version="ClickingVersionsV2.7\nCreated by Lz\n"
			,Licence="Licence:\n\nClicking_System()\nAbout{\nCreate:lz\nCoded:V1.0 to latest:lz,yyc\nDebug:V1.0 to latest:lz\nContributor/cooperation:yyc\nOther Attentions:\n//Run _example() to learn to use or ask the editor.\n//You can edit it as you like,but not in commercial usage.\n//I will be thankful if you discover any bug in it.\n\nPS:并没有装逼，都是自己翻的awa... \n\n--本程序(clicking.cpp;clicking.exe)以及教程(Note.txt，Tutor.txt)由lz原创。\n\n本作品采用知识共享署名-非商业性使用-相同方式共享 4.0 国际许可协议进行许可。\nThis project is licensed under the Creative Commons Attribution BY - NC - SA 4.0 international license agreement.\nmore information ：https://creativecommons.org/licenses/by-nc-sa/4.0/\n你可以进行改编，演绎，或者作为交流用途分享给他人，但请注明原作者，请勿用于商业用途，感谢配合！\n*本作品指文件夹下的所有cpp,exe和txt文件\n\n联系作者: 1612162886@qq.com；洛谷ID：43845（是OIer就来luogu啊）\n}\n";
const int CAuthority[15]={67,79,68,69,68,32,66,89,58,76,105,110,90,101,46};
char* COptionsFileName=const_cast<char*>("options.txt");
#ifndef CLICK_SIMPLE
const string OptionsForge="[DoNOTModify]Identifier:ClickingVersionsV2.7-By LZ-\n[WindowPosition](left,width,top,heigh)\n4\n-1 -1 -1 -1 \n[Trans;wOldColorAttrs;CFontSizeX;CFontSizeY;FocusVisible]\n5\n1 7 8 16 2 \n[EOUT:EoutDelay,IDDTFP]\n2\n20 25\n[WindowVersion](Disabled)\n1\n0 \n[ProcessName](Format:*.exe)\n-1\nclicking!.exe\n[FontSize](Format:X1 Y1 X2 Y2...)\n12\n3 5 5 8 6 12 8 16 8 18 10 20\n[FontInfo](Format:x1 y1 x2 y2...)\n12\n2663 517 1600 325 1327 208 2000 426 1000 142 800 125\n[FontIndex](Format:n1 0 n2 0...)\n12\n0 0 2 0 7 0 1 0 13 0 15 0 \n\n\n"
/*更新信息*/,Note="Version:\n\nClickingVersionsV2.7\nCreated by Lz\n\n----------------------------------------------------------------\n\n\n**完整版**\n\nUpdate:\n \nV0.1/*首版*/\ncongratulation!Clicking()函数诞生了，修复横竖不分显示现象，是Lz编的一个允许鼠标移动的C++程序哦！\nV1.0/*2019清明特辑*/\n添加了中文插件，并确定和记录了初始窗口位置和颜色。\nV1.1\nLz爆肝允许了窗口移动，修复了大部分BUG包括连点（但是他偷懒了），准备添加注释插件。\nV2.0/*2019清明特辑*/\n冒着被*的危险，成功添加注释插件！注释功能多样，还具备即时刷新功能，快来探索吧！\nV2.1\nSetConsoleTextAttribute(OPhandle,0x20|0x80)启动！允许五颜六色的标签啦！\nV2.2\n填充了标签，修复了超界漏洞（Debug程序越来越长了呵呵），还有让那个信息框识字（中文）。。。\n因为psy建议，添加了防止win10的闪电字幕出现卡字现象的插件，添加了win10稳定模式\nV2.3\n添加了窗口功能（当场吐血），现在知道xy轴混用的危害了（qwq抓了一星期臭虫）。另外抓了一个自添加注释就隐藏的bug，今天总算把它揪出来了——右移时一次跳两格。还精简了函数变量。。\n还有一个惊讶地发现，clicking已经快炸内存了……119688kb（116.87890625MB），但是用电脑管家加速后剩396kb（不足1MB），有种扎心感觉\nV2.3开始可以公布了~AWA~，因为楼主的功能已经差不多了（好像也没啥好打了）\nV2.4\nV2.3没有考虑Trans的情况于是发现了一大堆新bug，决定再肝一场。。。配置也多了很多，可以不用改内置就改设置啦\n决定2.3、2.4因为有bug，所以更改为2.5才公布。接下来还有V2.5版准备添加线程（速度嗖嗖的）\nV2.5\n成功添加多线程，虽然给操作带来了巨大麻烦和巨多bug（好像每一次都有很多），但是成功为其可游戏操作奠基。添加了拖动取消功能和锁定窗口（不允许拖动）功能。\n还特地肝了一个教程（lj）出来\n虽然有些人认为现在图形库那么发达，随便用个java、VC，或者c++装个EGE、Box2D都比他好（其实我也想学），但是怎么说呢，有个能面向大众（懒awa）的鼠标控制程序还是挺有创意的吧。。。\n如果有时间会将其转换为头文件，将正式公开V2.5[rep].rar\nV2.6\n进行了小改\n上次被我妈和刘姐姐测试了一下发现她们一拿到的反应——这个怎么用啊？(...)不过后来发现是因为中年人们使用鼠标习惯了用尖尖对准按钮，我们喜欢整个挪上去，所以进行了一些些改动。另外因为字体需要，爆肝（真的很惨）了一个活动字体变量fsx和fsy(我估计以后不会再添加这些恶心的东西了)，又花了一下午。另外修了一些小bug\n添加了精简版（其实就是删了几个注释。。。），为了时它体积小一些、使用没那么繁琐（但是改起来就繁琐了）\n本来8.1已经定稿了，后来想着觉得不对劲，8.18从重庆刚回来就干，总算把校准搞定了（我不会再弄他了。。。恶心。。。）另外完善了冻结窗口做法\nV2.7(UNFINISHED,pre1) \n初三第一次大测后初改 \n对速度进行了改进，（puts的速度实在太令人震惊了） \n而且深受格式之害，决定对整个程序重整（虽然对功能并没有什么改进） \n初三中考后二改\n发现了一个奇怪但是有用的字体函数，爆肝了两天啃了下来，现在clicking可以适应各种电脑字体了\n加了设置系统，打开程序时按住Tab可以进入（因为判断时间很短，建议打开之前先按住Tab）\n另外发现一个bug，我把所有的version（版本）写成了verson（打脸*INF）\nV2.7pre1最后完成于2020.7.27\nV2.7\n改了变量名让其变得简单易懂，另外提供了\n#define CLICK_RELEASE\n#define CLICK_SIMPLE\n模式，不过VEHICLE模式就废弃了。还学会了PipeCMD，初始化速度↑\n接着用一周的时间乱斗BUGS，成功修复了──中文切分，CAreaRefresh的刷新问题，CSpeedRefresh的前景刷新，eout的win10不适应性，颜色排除注释bug，example无效循环刷新，1,1角落空格bug，颜色刷新bug，卡弹出窗口bug，移动失效bug，线程退出未完成bug，还有Trans的一点点小毛病...我不想再列举了，他们令我反胃\n然后目前测试，没有bug了！！！！！\n最后进行了小改动，为了接下来的大插件(保密)做准备──CPause，FV和CButton的三态，CCurrentTopWindow，CClickable\n另外将程序大小降到了28MB（不过还没加vector，不然会更小）\n而且这是最后一个不是头文件版本，以后clicking!将会变成clicking.h重新出现（又将是一场恶战...）\n\n\n\n#define 敬请期待!  lz又偷懒了!\n\n"
			,Tutor="Help:[2020.12.12]\n这个程序就是一个可DIY的拥有鼠标控制功能的程序，你可以通过鼠标来控制程序，告诉他你想干嘛，而不再使用键盘\n教程稍稍冗(rǒng)长，请见谅！\n\n☆☆☆☆①：提前注意\n	\n	1.clicking需要gcc4.9.2的头文件(pthread.h系统)，因此请先更新你的C++到5.11版本\n	另外，本程序/插件对语法没有要求，C++03即可(宏__cplusplus值大于199711L即可)\n	\n	2.虽然程序里有很多别的干货，但是出于线程稳定和变量依赖考虑，请按照说明使用。\n	\n	3.程序运行时若遇到黑屏但线程持续运行，乱码或者你认为是bug的情况，请贴上你的代码向LZ踢馆，随时欢迎~\n	Github地址 https://github.com/ystkc/Public-Project/tree/master/clicking \n	洛谷id：43845\n	邮箱：1612162886@qq.com\n	\n★★★★数据公开(稍后会一一解释)：\n变量:	string MessageboxLeftBoard[]={'|','*','#','+','',' ','  ','│','┃','┆','┇','┊','┋','╳','□','■','█','▌','○','●','☆','★','?','?','?'},MessageboxTopBoard[]={'-','*','#','+','',' ','  ','─','━','┄','┅','┈','┉','╳','□','■','█','▄','○','●','☆','★','?','?','?'};\n	string WindowLeftBoard[]={'|','*','#','+',' ','!','?',''','.','+'},WindowTopBoard[]={'-','*','#','+',' ','!','?',''','.','='};\n	const char Ch0[]='┼',Ch1[]='╋',En0[]='+',En1[]='*',Sp0[]='╬',Sp1[]='#';//光标形式 (1个半角或全角字符)\n	char* COptionsFileName=const_cast<char*>('options.txt');\n	char CTitle[1005];//程序窗口标题\n	int CEnabled,CPause,CButton=2,CClickable=1,FV=2,CTopCurrentWindow;//线程是否启动,暂停（鼠标移出窗口） 按钮特效开关  是否允许选择 当前窗口是否置顶 \n	COORD CBufferSize={80,25};//更改窗口大小应该在此处 \n	WDD=5,//窗口数量 //可以在主程序里自己定义，此处仅供参考 \n	WDLMT=205,//窗口大小（长边）//可以在主程序里自己定义，此处仅供参考 \n函数:	public:\n#ifndef CLICK_SIMPLE//有一些奇怪的东西如果简化版就不要了 \n	int INTSc(int linenum, int number) ;//文件读，不需要掌握\n	bool LinePr(char* COptionsFileName, int linenum,std::string ot);//文件写(把COptionsFileName文件第linenum变为ot)，不需要掌握\n	void CAreaSelect(int left,int top,int right,int down,int &px,int &py);//area selecting区域选择* \n	void _example();\n#endif\n	void CWriteWindow(int wd,int x,int y,std::string s,int ct,std::string cm,int cml,int cmt,int cmdl,int cmmd,int cmbds,int cl);//menu writing system菜单写入系统*\n	void CShowWindow(int wd);//显示窗口k ,可以在CEnabled=0时调用 \n	void CHideWindow(int wd);//隐藏窗口k ,可以在CEnabled=0时调用\n	void CCreateWindow(int wd,int wdbds,std::string wdtp,int cwl,int cwt,int cwr,int cwb);//window writing system窗口创建系统\n	void CDeleteWindow(int k);//删除窗口k \n	void msgbox(int wd,int sx,int sy,int cl,std::string msg,int md,int bdstyle);//MessageBox信息框 \n	void CLockWindow(int wd);\n	void COpenThread(int delay/*LEAST 50!*/,int window,int to_be_continued);//menu choosing system starter菜单选择系统启动程序_线程* \n	void COpenWindow(int delay/*LEAST 50!*/,int window,int to_be_continued);//menu choosing system starter菜单选择系统启动程序_等待* \n	void CCloseWindow();\n	\n	#define CLICK_RELEASE//去除一切无关输出 \n	#define CLICK_SIMPLE//精简版 \n	\n	\n★★★★从这里开始就是如何编一个鼠标控制程序的过程了\n	\n★	Step0.包括clicking.h或者在clicking!.cpp的基础上修改int main()函数\n	看清楚区别了吗？头文件是没有'!'的。V2.7以后都推荐用头文件法，如果是头文件会定义宏_CLICKING_。\n	\n★	Step预处理.\n	☆程序提供了很多奇怪的宏，程序本身也要用到，但是他们是独立的，所以用用也可以。但如果你发现了下面没有介绍的宏，除非你清楚你在做什么，否则不要调用。\n	#define OptionsDeep() (SetConsoleTextAttribute(COutputHandle, wOldColorAttrs==0?7:wOldColorAttrs))\n		还原为options.txt中的文字颜色\n	#define HightLight() (SetConsoleTextAttribute(COutputHandle, 0x1|0x4|0x8|0x20|0x40|0x80))\n		高亮文字（带有亮黄色背景）\n	#define HideCursor() {CCursorInfo.bVisible = false;SetConsoleCursorInfo(COutputHandle, &CCursorInfo);}\n		隐藏控制台那个一闪一闪的像个下划线的光标，即可以美观，又可以提高速度（实测有效）\n	#define ShowCursor() {CCursorInfo.bVisible = true;SetConsoleCursorInfo(COutputHandle, &CCursorInfo);}\n		还原那个一闪一闪的光标\n	#define ChangeWindowPosition( Px, Py, Cx, Cy) (MoveWindow(CMainHwnd,Px,Py,Cx,Cy,TRUE))\n		改变窗口位置和长宽，（Px,Py）是左上点的坐标(单位：像素)，Cx,Cy分别是宽和高(单位：像素)，被他Change过的窗口是不能在被人工拉大的，但是可以被缩小(我也很无奈)\n	#define SetWindowPosition( Px, Py) (SetWindowPos(CMainHwnd, HWND_NOTOPMOST, Px, Py, 0, 0,SWP_NOSIZE))\n		改变窗口位置，PxPy含义同上，但是他变不了长宽哦\n	#define Oscillate(WindowRect) {SetWindowPosition(WindowRect.left,WindowRect.top+1);SetWindowPosition(WindowRect.left,WindowRect.top);ChangeWindowPosition(WindowRect.left,WindowRect.top+50,WindowRect.right-WindowRect.left,WindowRect.bottom-WindowRect.top-50);ChangeWindowPosition(WindowRect.left,WindowRect.top,WindowRect.right-WindowRect.left,WindowRect.bottom-WindowRect.top);}\n		振荡(不是试管)控制台窗口。这里要明确一下，程序里的窗口是用字符虚拟的，控制台窗口指的是有关闭最大化最小化按钮标题之类的大框框。振荡是用来弥补lFreeze功能不足使用的，也不会产生你想象的滑稽效果，因此除非你很清楚你在做什么，不要调用它\n	#define lSuspend() {SetWindowLong(CMainHwnd, GWL_STYLE, GetWindowLong(CMainHwnd, GWL_STYLE) & WS_CAPTION);CTempRect=CWindowRect;}\n		穿透控制台窗口（不是个好东西，可以使点击穿过窗口，但在程序回复之前你就再也点不到它了，你甚至点不到他的关闭按钮）\n	#define lFreeze() {SetWindowLong(CMainHwnd, GWL_STYLE, GetWindowLong(CMainHwnd, GWL_STYLE) & ~WS_CAPTION);CConsoleTopBoard=8;CTempRect=CWindowRect;Oscillate(CTempRect);}\n		冻结控制台窗口（其实是把窗口标题删掉，这样就拖动不了了），如果你是用过Change宏，那么它将被限制为最大长宽，冻结不会对其造成影响。\n	#define lInitial() {SetWindowLong(CMainHwnd, GWL_STYLE, CWindowOldLong);SetConsoleTitle(CTitle);Oscillate(CTempRect);CConsoleTopBoard=30;}\n		还原窗口属性，使得窗口属性被还原，所有的冻结，穿透属性都会被取消。\n	#define AutoAlign() {GetWindowRect(CMainHwnd,&CWindowRect);if(CWindowRect.left!=-32000)CConsoleLeft=CWindowRect.left+CConsoleBoard,CConsoleRight=CWindowRect.right-CConsoleTopBoard,CConsoleTop=CWindowRect.top+CConsoleTopBoard,CConsoleBottom=CWindowRect.bottom-CConsoleBoard;}\n		自动对齐，用来告诉线程──你的窗口被移动了。为什么要呢？因为有时候Freeze或者Oscillate之后子线程反应不过来，就要提醒一下他（所以呢上述四个宏调用之后最好都AutoAlign一下）\n	#define TextDeep() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_INTENSITY ))\n	#define TextNormal() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_RED |FOREGROUND_BLUE |FOREGROUND_GREEN ))\n	#define TextDeepBlue() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_INTENSITY |FOREGROUND_BLUE))\n	#define TextDeepGreen() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_INTENSITY |FOREGROUND_GREEN))\n	#define TextDeepRed() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_INTENSITY |FOREGROUND_RED))\n	#define TextDeepYellow() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN))\n	#define TextDeepPink() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_BLUE))\n	#define TextDeepCyan() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_INTENSITY |FOREGROUND_GREEN |FOREGROUND_BLUE))\n	#define TextBlue() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_BLUE))\n	#define TextGreen() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_GREEN))\n	#define TextRed() (SetConsoleTextAttribute(COutputHandle,FOREGROUND_RED))\n	#define BackgroundDeepBlue() (SetConsoleTextAttribute(COutputHandle,BACKGROUND_INTENSITY |BACKGROUND_BLUE))\n	#define BackgroundDeepGreen() (SetConsoleTextAttribute(COutputHandle,BACKGROUND_INTENSITY |BACKGROUND_GREEN))\n	#define BackgroundDeepRed() (SetConsoleTextAttribute(COutputHandle,BACKGROUND_INTENSITY |BACKGROUND_RED))\n	#define BackgroundDeepYellow() (SetConsoleTextAttribute(COutputHandle,BACKGROUND_INTENSITY |BACKGROUND_RED |BACKGROUND_GREEN))\n	#define BackgroundDeepPink() (SetConsoleTextAttribute(COutputHandle,BACKGROUND_INTENSITY |BACKGROUND_RED |BACKGROUND_BLUE))\n	#define BackgroundDeepCyan() (SetConsoleTextAttribute(COutputHandle,BACKGROUND_INTENSITY |BACKGROUND_GREEN |BACKGROUND_BLUE))\n	#define BackgroundBlue() (SetConsoleTextAttribute(COutputHandle,BACKGROUND_BLUE))\n	#define BackgroundGreen() (SetConsoleTextAttribute(COutputHandle,BACKGROUND_GREEN))\n	#define BackgroundRed() (SetConsoleTextAttribute(COutputHandle,BACKGROUND_RED))\n		这些是颜色库（没有任何风险，随便调用，时间开销大约是0.01ms一次），调用它们可以改变文字以及背景颜色，Cyan-青色\n	FOREGROUND_BLUE 0x1\n	FOREGROUND_GREEN 0x2\n	FOREGROUND_RED 0x4\n	FOREGROUND_INTENSITY 0x8\n	BACKGROUND_BLUE 0x10\n	BACKGROUND_GREEN 0x20\n	BACKGROUND_RED 0x40\n	BACKGROUND_INTENSITY 0x80\n		你还可以将上述的单词替换成上面的16进制数来缩短程序，但请你确保你自己别把他搞混了（摘自wincon.h）\n	\n	☆然后你还需要定义一些变量~\n	const int WDD=;这个是最大窗口数，不需要太多，你要多少个窗口，就定义为窗口数+1就好了\n	const int WDLMT=;这个是最大窗口行数和列数（的最大值），这个取决于什么呢？假如你的窗口放到最大了一共97行，150列，那么就填151；如果你不想他这么大（这意味着巨大的内存开销），但是又担心他被最大化，可以使用Change函数规范一下最大值\n	COORD CBufferSize={,};这个是缓存区大小。原则上他应该和窗口大小一样就ok了(如果97行，150列，那就填{98,151})，如果大了会怎样？会出现滚动条，可以自己权衡要不要。但是如果你不定义，他会被定义成{80,25},并且会warning(作为头文件时)\n	\n	\n★	Step1.首先当然是创建窗口了\n	1.void CCreateWindow(int wd,int wdbds,std::string wdtp,int cwl,int cwt,int cwr,int cwb);//window writing system窗口创建系统\n	2.void CWriteWindow(int wd,int x,int y,std::string s,int ct,std::string cm,int cml,int cmt,int cmdl,int cmmd,int cmbds,int cl);//menu writing system菜单写入系统*\n	\n	解释:\n	1:CCreateWindow用于创建窗口，CWriteWindow用于写入文字用于执行的菜单（也就是在屏幕上会显示的东西）☆注意要先创建才能写入，但是即使线程开始了，你仍然可以不受限制继续写入\n	wd：你的窗口编号（如果你只有一个窗口，你就写个1或者随便编个数）\n	wdbds:你的窗口边框形式（可以在上面的WindowLeftBoard和WindowTopBoard选一对，他们是一一对应的，填写他们是数组中的第几个）\n	wdtp:你的窗口标题（不用担心，程序已经帮你自动居中了，不过要注意不能超过窗口宽度，不然会发生事故）\n	cwl:你的窗口左坐标（你的窗口显示出来时，左边框的坐标）\n	cwt:你的窗口上坐标（全都同上）\n	cwr:右坐标（全都同上）\n	cwb:下坐标（全都同上）\n	\n	2:写入你的窗口，你可以先写好，然后调用Show函数(稍后解释)让它显示，用户就可以点击你写入的文字进行选择，然后你就可以根据返回的值获取用户选择了你哪条文字\n	wd:你的窗口编号（你创建的窗口的编号）\n	x,y:文字的起始点坐标（是绝对坐标而不是相对窗口位置坐标）\n	s:你的文字内容，如果你想要换行，可以在里面插入一个‘}’来换行\n	ct:文字值（就是你点击他的时候程序会返回一个什么值，如果想要他不返回（就是点它也没反应）就填0，如果填负数那么将不会返回，也请不要填32767,它是窗口边框识别值）\n	cm:它的注释，就是你的鼠标停留在上面时会弹出一个小窗口显示着（如果不要就填''，然后接下来cml,cmt,cmdl,cmmd,cmbds都可以填0）\n	cml,cmt:注释的位置（绝对坐标），如果懒可以两个都填-1，程序会自动帮你分配\n	cmdl:你的鼠标停留在上面过多少时间才显示注释（单位ms）\n	cmmd:注释样式（0：默认；1:3D，2:闪电字幕（可以自己试试看））\n	cmbds:注释边框模式（可以从MessageboxLeftBoard和MessageboxTopBoard里面选一对，和窗口边框样式规则一样）\n	cl:注释颜色（填写的时候可以填FOREGROUND_BLUE...也可以填0x1...，如果要混色的话在两个属性之间加个'|'，混合颜色参考上面的颜色宏）\n	\n★	Step2.开始你的表演\n	\n	void COpenThread(int delay/*LEAST 50!*/,int window,int to_be_continued);//menu choosing system starter菜单选择系统启动程序_线程* \n	void COpenWindow(int delay/*LEAST 50!*/,int window,int to_be_continued);//menu choosing system starter菜单选择系统启动程序_等待* \n	\n	用法：用于启动窗口选择主程序，让用户根据你的提示选择。\n	解释:\n	dl:刷新间隔时间（就是这个程序多久反应一次（但是由于误差挺大。。。），单位ms，建议不小于20ms）\n	window:初始的窗口编号。如果你显示(后面会解释如何显示)了多个窗口，那么用户可以看到他们而且可以切换到显示的窗口。\n	to_be_continued:返回值可持续性（就是你点击了一个有效选择（就是前面的ct>0）以后，如果ls=1，那么菜单会返回值后继续运行，否则他会返回值后退出）\n	wt被删掉了，但是若调用Thread则相当于不等待(启动线程后主线程返回),wt=0；启动Window则相当于主线程自己进去跑，也就相当于等待,wt=1；\n	\n	\n★	Step3.编辑/监视你的窗口\n	线程启动以后，使用下面的操作可以让你的表演更精彩（？？）具体是用来做什么的，看下去便知\n	这一Step有很多不同的操作，我用提问方式列举，为了方便查找，每个操作都用一行表示。正确查看方式：先按home看前半部分，再按end看后半部分~\n	\n	Q1.我如何知道我的线程在运行？它如果崩溃了我如何得知？\n	A.CEnabled(bool)\n	这是一个状态变量，当CEnabled=1时Run函数运行，反之则停止，但是手动改变他并没有什么用\n	\n	Q2.我如何知道现在光标在哪里？\n	A.CCurrentX,CCurrentY(short int)\n	这两个是指当前光标所在的坐标（可以确定光标的位置，单位：字符(不是像素哦)，以窗口左上角为(1,1)）。如果你想知道像素，可以使用GetCursorPosition函数(是windows.h中的WinAPI函数，可自行查阅资料)\n	\n	Q3.我如何显示我的窗口？既然有多个窗口，那可以更改/查看窗口顺序吗？（层叠顺序）\n	A.CWindowOrder(string)\n	void CShowWindow(int wd);\n	void CHideWindow(int wd);\n	CWindowOrder指的是窗口的排列顺序（由上到下指0~size()-1），不过只能读取而不能更改。\n	通过ShowWindow和HideWindow可以显示你的窗口并且放到最上层。\n	\n	Q4.我如何知道用户点了什么？或者他是否点击？\n	☆A.CChoseValue[](int[])\n	子线程会把返回值存进一个全局数组，既保障了分离运行，又可以可连续传值。要提取返回值时，CChoseValue[0]是总个数（如果它的值是0那么代表用户没有点击什么）。\n	可以用这样的语句提取返回值:while(CChoseValue[0]==0)Sleep(20);（Sleep可以换成你自己的语句）跳出循环后写一个xxx=CChoseValue[CChoseValue[0]--(一定要记得--)]便可以取到最近的值\n	\n	Q5.我如何知道用户想要点击什么？\n	☆A.CCurrentValidValue(int)\n	CCurrentValue(int)\n	CCurrentValidValue可以预览鼠标停留在的文字上的有效值（就算没有点下去也会取得到值）并且会自动过滤空值，负值，可以在循环中用if(CCurrentValidValue==...)执行（但请注意，为防止重复执行，条件语句最后请将CCurrentValidValue设置为0）。\n	而CCurrentValue会返回任何值，包括空值(0)和负值(-1等等)\n	设计这个变量主要有一个很有用的用途：如果它的值是某个文字的值，那么马上用CWriteWindow在旁边写一句话（提示用），可以有效迅速地反馈\n	\n	Q6.线程运行时我可以执行system('cls')吗？我可以自己输出别的文字吗？\n	☆A.CTasks_sys[](int[])\n	void msgbox(int wd,int sx,int sy,int cl,std::string msg,int md,int bdstyle);//MessageBox信息框 \n	答案是千万不要。\n	因为多线程运行的时候如果两个线程一起输出可能导致光标错位，乱码，甚至原地炸掉，所以我想到了个办法，用这个语句：CTasks_sys[++CTasks_sys[0]]=0;即可代替\n	但是请注意，这个方法只有在线程运行(CEnabled==1)时有效，如果线程已经停止，你可以放心执行cls。另外提示：本程序附带void lr()可以起到system('cls')作用（也只能在线程停止时使用），时间开销大约是cls的1/10。\n	如果你想要自己输出文字，一个方法是通过CWrite，二个就是把线程关掉(后面会说怎么关)。\n	三个就是弹窗。弹窗怎么办？首先创建一个窗口（步骤和普通窗口一样），写好东西之后把它CShowWindow出来，然后马上把一个叫做CTopCurrentWindow的int变量设置为他的编号，用户就只能在你的弹窗内进行操作。取消时只需CTopCurrentWindow=0即可。\n	四个方法就是关掉线程后（务必！）使用msgbox,wd是依赖窗口编号（填0即可），sxsy左上角位置（单位：字符），cl文字和背景颜色，msg要写的信息(同样}可以换行)，md模式（同Step1.CWriteWindow的注释模式）,bdstyle边框（同Step1.CWriteWindow的注释边框）\n	\n	Q7.我如何删除一条文字/一个窗口？\n	A.void CDeleteWindow(int wd);\n	本程序没有直接删除文字的函数，但是你可以通过CWrite一串空格来掩盖掉，换行符}对空格同样有效。\n	CDeleteWindow()用来删除一个窗口，然后被删除的窗口就会永久消失，除非你重新创建写入\n	\n	Q8.我不想用户改变我的窗口顺序/位置？我想置顶某个窗口？\n	A.CTopCurrentWindow(int)\n	如果你想将某窗口置顶，可以使用CTopCurrentWindow=顶层窗口编号即可锁定窗口顺序，将其赋值为零即可解除。\n	如果你想锁定窗口位置，使用CLockWindow(窗口编号)即可锁定，在锁定后再调用一次即可解锁。（按住窗口标题再拖动就能改变未锁定的窗口位置，请放心，他不会被拖到边界外）\n	\n	Q9.我不想用户点击的时候显示什么加号乘号，制表符，色块之类？\n	A.FV(int∈{0,1,2})，CButton(int∈{0,1,2})，CClickable(int∈{0,1})\n	FV=0：不显示任何光标符号；FV=1：只显示*╋号；FV=2：显示所有+*┼╋光标符号\n	CButton=0：不显示色块；CButton=1：在鼠标正下方显示一个色块；CButton=2：给鼠标下方的所有有效文字染色（有效文字：他们的ct值相同，而且是正数，并且在同一行）；\n	CClickable=0：用户的点击不会得到响应，它不会影响FV对光标符号的控制，也不会影响CButton对色块的控制。你可以得到CCurrentValue和CCurrentValidValue，但你得不到CChoseValue，直到你把CClickable设置为1。\n	\n	Q10.我怎么知道/调整字体大小？\n	A.CFontSizeX(int),CFontSizeY(int)\n	这两个变量是指控制台的字体大小（宽，长；单位像素），和 控制台标题右键-属性-字体-大小 的值相同。\n	调整字体系统还在实验中。如果你想要某个字体，在options.txt中的CFontSizeX一栏更改即可(长 宽（单位：像素）)因为调整字体系统不稳定，定义了CLICK_SIMPLE或CLICK_RELEASE可以禁用调整字体系统，此时字体会跟从系统默认字体\n	\n	Q11.我怎么知道用户是否把鼠标放在窗口内？\n	A.CCurrentWD(int),CPause(int)\n	如果你指的是字符虚拟窗口：CCurrentWD可以告诉你现在的顶层焦点窗口编号\n	如果你指的是控制台窗口：CPause为1时代表不在，反之则在。\n	\n	Q12.我想知道些奇怪的东西（搪塞）\n	A.void CAreaSelect(int left,int top,int right,int down,int &px,int &py);//area selecting区域选择* \n	好吧满足一下好奇心。\n	有个古董函数叫区域选择器。因为这个函数V0.1就已经完成了，后来都没怎么改过（他，完整地见证了clicking从0.1到2.7的全部过程），本来不打算介绍。不过既然有点用处，也介绍一下。（请勿在子线程启动时调用）\n	用法：屏幕会最大化，你需要在上面点上一下，就会显示十字准星，接着程序会返回你选择的坐标（单位：字符）。可以用于区域选择\n	解释：	left,top;right,down:选择的区域（如果超过这两个点那么他就不会显示十字准星并且等待）\n	px，py：这两个变量是用于传回的，不需要有传入值，否则会被覆盖\n	\n	Q13.INTSc和Pr是用来干什么的（搪塞*2）\n	A.好吧两个好奇一次满足。\n	他俩也是历史悠久，INTSc如今已经废弃了，使用它可以读取options.txt第linenum行第number个数据（仅限int类型）；Pr是写入options.txt用的，会把ot字符串写入到COptionsFileName文件的第linenum行（覆盖原来内容）。另外：如果第一次启动，预处理程序会启动它，传递一个'*A'作为文件名，此时他就会产生options.txt（仅未定义CLICK_SIMPLE的程序有效）\n	\n	Q14.我想调整控制台窗口初始属性？（例如大小位置背景之类的）\n	（提示：options.txt会自动出现，无需理会）\n	下面展示options.txt的内容（//后面是解释，options.txt里面是没有的）\n	[DoNOTModify]Identifier:ClickingVersionsV2.7-By LZ-//版本信息，除非你很清楚你在做什么，否则不要更改\n	[WindowPosition](left,width,top,heigh)//窗口位置和长宽（单位：像素）\n	4\n	-1 -1 -1 -1 \n	[Trans;wOldColorAttrs;CFontSizeX;CFontSizeY;FocusVisible]//Trans无需理会;wOldColorAttrs窗口所有文字初始颜色，参照文字属性函数的混色;CFontSizeXCFontSizeY调整控制台字体，他们只有在没有定义CLICK_SIMPLE或CLICK_RELEASE时才有效（参考Q10）;FocusVisible就是FV的初始值（参考Q9）\n	5\n	1 7 8 16 2 \n	[EOUT:EoutDelay,IDDTFP]//EoutDelay:闪电字幕两个字符之间间隔最小值（最大值是最小值的三倍，单位：ms）；IDDTFP:闪电字幕终止的鼠标最大偏移（单位：像素），除非你很清楚你在做什么，否则不要更改\n	2\n	20 25\n	[WindowVersion](Disabled)//原来用于识别Windows版本，现在已经找到了函数，故废弃\n	1\n	0 \n	[ProcessName](Format:*.exe)//程序的名字，原来用于调整字体，现在已经没有实质性用处\n	-1\n	clicking!.exe\n	[FontSize](Format:X1 Y1 X2 Y2...)//字体大小（单位：像素），除非你很清楚你在做什么，否则不要更改\n	12\n	3 5 5 8 6 12 8 16 8 18 10 20\n	[FontInfo](Format:x1 y1 x2 y2...)//字体比例，除非你很清楚你在做什么，否则不要更改\n	12\n	2663 517 1600 325 1327 208 2000 426 1000 142 800 125\n	[FontIndex](Format:n1 0 n2 0...)//字体编号，除非你很清楚你在做什么，否则不要更改\n	12\n	0 0 2 0 7 0 1 0 13 0 15 0 \n	\n	另外告诉一个小秘密：程序一启动立即长按Tab，你会发现不一样的天地（仅对未定义CLICK_RELEASE和CLICK_SIMPLE的程序有效）\n	\n★	Step4.打完收工\n	等等？这个用说吗？return 0;搞定\n	如果这样的话你可能会面临乱码，内存泄漏，甚至被误判病毒的危险。\n	如何安全关闭？使用void CCloseThread();尽管它需要多一些时间（取决于你的电脑性能,10ms到1000ms不等），但可以保证子线程安全关闭，并且不影响再次打开。\n	\n	\n	所以现在你应该明白了──不就是个操作系统吗？不稀罕。\n	这其实是以前我一个小小的希望；我希望不用图形插件就能编出鼠标控制的程序。操作系统并没意思，真正决定是否有意思的是创意，是那个使用操作系统程序。什么意思呢？一切皆在于你。\n	\n	那么祝你玩得开心！\n	\n	 --由LZ编写 \n	 \n";
#else
const string Note_simple="帮助:\n（你可以把我理解为操作系统）\n如果你不理解──这个程序是一个用鼠标操纵的程序。\n有多方便呢？他不用你按键盘，只需点击屏幕上的文字就能作出选择，稍后程序还会给你使用提示。\n\n\n\n\nV2.7-simple最后完成于2020.12.06\n\n\n当前版本	V2.7-simple\n完成时间	2020.12.06\n";
#endif
//空间声明 
struct CWCN{int dl,wd,ls;}TempCWCN;/*线程传递数据 NEEDED*/ 
int Options[525][135],Optionstot,Optionstringtot;//设置板块
string Optionstring[105];/*options.txt<-VerVerify NEEDED*/ 
char CTitle[1005];//程序窗口标题
string CWindowOrder="";//窗口顺序
int CMessageXLine,CMessageXHeight;/*msgbox() NEEDED*/
pthread_t CRecentTids;
int CEnabled,CPause,Trans=1,CButton=2,CLatestNum,CClickable=1,FV=2,CTopCurrentWindow;//线程是否启动,暂停（鼠标移出窗口）非焦点窗口可见性  按钮特效开关  当前运行线程编号 是否允许选择 当前窗口是否置顶 
int CurrentFontSizeX,CurrentFontSizeY,CurrentFontIndex;//(current-)当前字体大小 
/*p rivate*/ char cc;//全局getch() 
//API SYMBOL
HWND CMainHwnd=GetForegroundWindow();//主窗口句柄 
HWND CConsoleHwnd=GetConsoleWindow();//控制台句柄 
HANDLE COutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);//输出句柄 
CONSOLE_SCREEN_BUFFER_INFO CConsoleScreenBufferInfo;//窗口缓冲区信息 
RECT CWindowRect,CTempRect;//窗口位置，缓存WindowRect
LONG CWindowOldLong=GetWindowLong(CMainHwnd, GWL_STYLE);//窗口样式，用于隐藏标题 
CONSOLE_CURSOR_INFO CCursorInfo;//光标信息，用于隐藏光标 
#ifndef CBufferSize
#ifdef _CLICKING_
	#warning:DEFINE CBufferSize={x,y} as *COORD* to define buffer size,or it will be {80,25}.
#endif
COORD CBufferSize={80,25};//更改窗口大小应该在此处 
#endif

//Function declare
int INTSc(int linenum, int number);
bool LinePr(char* COptionsFileName, int linenum,string ot);
int GetSystemVersion();
void gotoxy(int x,int y);
bool Form_load();
bool VerVerify();


//PRELOAD 请勿调换顺序！ 
/*p rivate*/ bool _VerVerify=VerVerify();//数据检查和读取 
//常量 
/*p rivate*/ const int
		EoutDelay=Options[3][1],IDDTFP=Options[3][2],//闪电字幕延时(!>5) 注释终止偏移  窗口累积最大个数
#ifndef WDD//可以在主程序里自己定义，此处仅供参考 
		WDD=5,//窗口数量 
#endif
#ifndef WDLMT
		WDLMT=205,//窗口大小（长边） 
#endif
		wOldColorAttrs=Options[2][2],//默认窗口文字颜色 
		CMD_MAXCHAR=512;//PipeCMD最大输出长度 
int		WinVer=GetSystemVersion(),//系统版本（用于修复Win10中文\b的双倍回格） 
		CFontSizeX=Options[2][3],CFontSizeY=Options[2][4];//字体大小 宽*长pixel
//主系统 
short int 
/*基础*/			CValue_sys[WDD][WDLMT][WDLMT],CColor_sys[WDD][WDLMT][WDLMT],
/*注释系统*/		CCommentLeft_sys[WDD][WDLMT][WDLMT],CCommentTop_sys[WDD][WDLMT][WDLMT],CCommentMode_sys[WDD][WDLMT][WDLMT],CCommentDelay_sys[WDD][WDLMT][WDLMT],CCommentBoard_sys[WDD][WDLMT][WDLMT],
/*由主线程加入任务*/CTasks_sys[WDD*3],
/*当前位置是否更新*/CIfRefresh_sys[WDD][WDLMT][WDLMT],
/*该窗口是否可移动*/CMovable_sys[WDD],
/*窗口系统基础*/	CWindowLeft_sys[WDD],CWindowTop_sys[WDD],CWindowRight_sys[WDD],CWindowBottom_sys[WDD],
/*返回值储存*/		CChoseValue[WDLMT*WDLMT],
/*预读鼠标下文字*/	CCurrentValidValue,
/*筛去空格*/		CCurrentValue,
/*当前光标位置*/	CCurrentY,CCurrentX,
/*当前窗口*/		CCurrentWD,
/*按钮变色系统*/	CTempColor,ColoredValue,ColoredPositionX,ColoredPositionY,ColoredColor,
/*鼠标像素位置*/	CConsoleLeft=Options[1][1],CConsoleRight=Options[1][2],CConsoleTop=Options[1][3],CConsoleBottom=Options[1][4],
/*边框宽度标题宽度*/CConsoleBoard=8,CConsoleTopBoard=30;
short int tCValue_sys[WDLMT][WDLMT],tCCommentLeft_sys[WDLMT][WDLMT],tCCommentTop_sys[WDLMT][WDLMT],tCCommentMode_sys[WDLMT][WDLMT],tCCommentDelay_sys[WDLMT][WDLMT],tCCommentBoard_sys[WDLMT][WDLMT],tCColor_sys[WDLMT][WDLMT];
				string tCChar_sys[WDLMT][WDLMT],tCComment_sys[WDLMT][WDLMT];//用于搬运窗口，临时 
string 
/*字符库*/	CChar_sys[WDD][WDLMT][WDLMT],
/*注释库*/	CComment_sys[WDD][WDLMT][WDLMT],
/*窗口标题*/CWindowTopic_sys[WDD];

/*p rivate*/ bool _Form_load=Form_load();//全局预加载 


//basic plugins基础插件 

/*p rivate*/ int INTSc(int linenum, int number)//文件读 
{
	if (_VerVerify)//因为IntSc本来为了读取设置，因为VerVerify已经读取过了，所以直接调用 
	return Options[linenum][number];//From the Options[][];
	
	
	ifstream in(COptionsFileName);
	int ans;string data;
	for (int i=1;i<linenum&&in.peek()!=EOF;i++)getline(in,data);
	for (int i=1;i<=number&&in.peek()!=EOF;i++)in>>ans;
	in.close();
	return ans;
}
#ifndef CLICK_SIMPLE
/*p rivate*/ bool LinePr(char* COptionsFileName, int linenum,string ot)//文件写(把COptionsFileName文件第linenum变为ot)
{
	if (COptionsFileName=="*A")
	{
		ofstream out (::COptionsFileName,ios::out);
		out<<OptionsForge;
		return out.is_open();
	}
	
	ifstream in(COptionsFileName);
	char data[511][256];int cnt=1;
	while (in.peek()!=EOF)
	{
		in.getline (data[cnt],255);
		cnt++;
	}
	in.close();
	ofstream out (COptionsFileName,ios::out);
	for (int i=0;i<ot.size();i++)
	data[linenum][i]=ot[i];
	data[linenum][ot.size()]='\0';
	for (int i=1;i<=cnt;i++)
	out<<data[i]<<endl;
	out.close();
	return true;
}
/*p rivate*/ string HEXR(int k) //dec->hex十进制转十六进制 
{
	string tmp="",ans="";
    while (k)
    {
    	tmp+=k%16<10?k%16+'0':k%16-10+'a';
        k/=16;
    }
    for (int i=tmp.size()-1;i>=0;i--)
    ans+=tmp[i];
    return ans;
}
/*p rivate*/ string StCh(int k)//int->string
{
	string ans="";
	int sig=0;
	if (k<0)sig=1,k=-k;
	if (k==0)return "0";
	while(k)
	{
		ans=char((k%10)+'0')+ans;
		k/=10;
	}
	if (sig)ans="-"+ans;
	return ans;
}

#endif
//advanced plugins高级插件 
inline void gotoxy(int x,int y)//cursor position setting光标位置设置 
{
	SetConsoleCursorPosition(COutputHandle,(COORD){y,x});
}
inline void lr()//fast cls光速清屏,调用它相当于system("cls")
//本函数来自https://blog.csdn.net/icy_ybk/article/details/79285245 ,特别感谢原作者Icy_Ybk ,有改动 
{
	SMALL_RECT scroll;
	COORD newCursorPointer;
	CHAR_INFO ciFill;
	
	if(!GetConsoleScreenBufferInfo(COutputHandle, &CConsoleScreenBufferInfo))
		return;
	
	scroll.Left = 0;
	scroll.Top = 0;
	scroll.Right = CConsoleScreenBufferInfo.dwSize.X;
	scroll.Bottom = CConsoleScreenBufferInfo.dwSize.Y;
	newCursorPointer.X = 0;
	newCursorPointer.Y = -CConsoleScreenBufferInfo.dwSize.Y;
	ciFill.Char.UnicodeChar = L' ';
	ciFill.Attributes = CConsoleScreenBufferInfo.wAttributes;
	ScrollConsoleScreenBufferW(COutputHandle, &scroll, NULL, newCursorPointer, &ciFill);
	newCursorPointer.Y = 0;
	SetConsoleCursorPosition(COutputHandle, newCursorPointer);
	return;
}
int GetSystemVersion()
{
	OSVERSIONINFOEX os;
	os.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	if(GetVersionEx((OSVERSIONINFO *)&os))
	{
		string vname;
#ifndef OLD_VERSION
		if (os.dwMajorVersion==4 && os.dwMinorVersion==0 && os.dwPlatformId==VER_PLATFORM_WIN32_NT)return 0;//Windows NT 4.0
		if (os.dwMajorVersion==4 && os.dwMinorVersion==0 && os.dwPlatformId==VER_PLATFORM_WIN32_WINDOWS)return 0;//Windows 95
		if (os.dwMajorVersion==4 && os.dwMinorVersion==10)return 0;//Windows 98
		if (os.dwMajorVersion==4 && os.dwMinorVersion==90)return 0;//Windows Me
		if (os.dwMajorVersion==5 && os.dwMinorVersion==0)return 0;//Windows 2000
		if (os.dwMajorVersion==5 && os.dwMinorVersion==1)return 0;//Windows XP
		if (os.dwMajorVersion==6 && os.dwMinorVersion==0)return 0;//Windows Vista
#endif
		if (os.dwMajorVersion==6 && os.dwMinorVersion==1)return 0;//Windows 7
		if (os.dwMajorVersion==10 && os.dwMinorVersion==0)return 1;//Windows 10
	}
	return 0;//failed
}
void CExeCMD(char* cmd,char* result)
{
	char buffer[CMD_MAXCHAR]={'\0'};
	FILE* pipe = _popen(cmd, "r"); //打开管道执行命令
	if (!pipe)
	{
#ifndef CLICK_RELEASE
		TextDeep();puts("E3.1:无法启动PipeCMD");TextNormal();
#endif
		return ;//运行失败
	}
	while (!feof(pipe))
	{
		if (fgets (buffer, CMD_MAXCHAR, pipe))//将管道输出到result中
		{
			strcat(result,buffer);
		}
	}
	_pclose(pipe);//关闭管道
	strcat(result,const_cast<char*>("\0"));
	return ;
}
struct CONSOLE_FONT//FontSizer needed
{
	DWORD index; 
	COORD dim;
};
/*p rivate*/ int FindFont(int CFontSizeX,int CFontSizeY)//FontSizer needed
{
	for(int i=1;i<=Options[6][0];i+=2)
	if (Options[6][i]==CFontSizeX&&Options[6][i+1]==CFontSizeY)
	return i;
	TextDeepRed();
#ifndef CLICK_RELEASE
	printf("[FindFont]Warning:%dx%d FontID NO FOUND\n",CFontSizeX,CFontSizeY);//警告找不到字体的编号 
#endif
	TextNormal();
	return -1;
}
/*p rivate*/ void FontSizer()	//adjust font size调整字体大小
{ 
	HMODULE hKernel32 = GetModuleHandle("kernel32");
	typedef BOOL (WINAPI *PROCSETCONSOLEFONT)(HANDLE, DWORD);
	PROCSETCONSOLEFONT SetConsoleFont = (PROCSETCONSOLEFONT)GetProcAddress(hKernel32,"SetConsoleFont");
	//因为不管是否需要查找字体信息，都需要设置字体，因此放到if外 
#ifndef CLICK_RELEASE
	puts ("---Query Current Font");
#endif
	int i=0,o=0;
	string tmps,tmp;
	char buffer[CMD_MAXCHAR<<4];
	Rst:;
	CExeCMD(const_cast<char*>("reg QUERY HKCU\\Console /v FontSize"),buffer);
	tmp=buffer;
	if (tmp.find("0x50003") != string::npos)CurrentFontSizeX=3,CurrentFontSizeY=5;
	else if (tmp.find("0x80005") != string::npos)CurrentFontSizeX=5,CurrentFontSizeY=8;
	else if (tmp.find("0xc0006") != string::npos)CurrentFontSizeX=6,CurrentFontSizeY=12;
	else if (tmp.find("0x100008") != string::npos || tmp.find("0x0") != string::npos)CurrentFontSizeX=8,CurrentFontSizeY=16;
	else if (tmp.find("0x120008") != string::npos)CurrentFontSizeX=8,CurrentFontSizeY=18;
	else if (tmp.find("0x14000a") != string::npos)CurrentFontSizeX=10,CurrentFontSizeY=20;
	else if (tmp.find("0000") != string::npos)//Win10的奇怪字体储存方式 
	{
		if (tmp.find( "0x50000") != string::npos)CurrentFontSizeX=3,CurrentFontSizeY=6;
		else if (tmp.find( "0x60000") != string::npos)CurrentFontSizeX=3,CurrentFontSizeY=7;
		else if (tmp.find( "0x70000") != string::npos)CurrentFontSizeX=4,CurrentFontSizeY=8;
		else if (tmp.find( "0x80000") != string::npos)CurrentFontSizeX=4,CurrentFontSizeY=9;
		else if (tmp.find( "0xa0000") != string::npos)CurrentFontSizeX=5,CurrentFontSizeY=11;
		else if (tmp.find( "0xc0000") != string::npos)CurrentFontSizeX=6,CurrentFontSizeY=14;
		else if (tmp.find( "0xe0000") != string::npos)CurrentFontSizeX=7,CurrentFontSizeY=16;
		else if (tmp.find("0x100000") != string::npos)CurrentFontSizeX=8,CurrentFontSizeY=18;
		else if (tmp.find("0x120000") != string::npos)CurrentFontSizeX=9,CurrentFontSizeY=21;
		else if (tmp.find("0x140000") != string::npos)CurrentFontSizeX=10,CurrentFontSizeY=23;
		else if (tmp.find("0x1c0000") != string::npos)CurrentFontSizeX=14,CurrentFontSizeY=32;
		else if (tmp.find("0x240000") != string::npos)CurrentFontSizeX=18,CurrentFontSizeY=41;
		else if (tmp.find("0x480000") != string::npos)CurrentFontSizeX=36,CurrentFontSizeY=82;
		else if (tmp.find("0x520000") != string::npos)CurrentFontSizeX=41,CurrentFontSizeY=94;
		else if (tmp.find("0x5e0000") != string::npos)CurrentFontSizeX=47,CurrentFontSizeY=107;
		else if (tmp.find("0x6b0000") != string::npos)CurrentFontSizeX=54,CurrentFontSizeY=122;
		else if (tmp.find("0x7a0000") != string::npos)CurrentFontSizeX=61,CurrentFontSizeY=139;
		WinVer=Options[4][1];
	}
	else
	{
#ifndef CLICK_RELEASE
		TextDeep();puts("E2:无法获取可识别的注册表字体信息");TextNormal();
#endif
		if (MessageBox(CConsoleHwnd,"E2:无法获取有效的注册表字体信息\n请确认您是否给予了访问权限","Process Erruption",MB_RETRYCANCEL)==IDRETRY)goto Rst;
	}
	CurrentFontIndex=Options[8][FindFont(CurrentFontSizeX,CurrentFontSizeY)];
#ifndef CLICK_RELEASE
	printf("Current Font Size:%d x %d\n",CurrentFontSizeX,CurrentFontSizeY);
#endif
	
	//获取系统的字体大小 
#ifndef CLICK_SIMPLE
#ifndef CLICK_RELEASE
	if (Options[8][0]==0)
	{
		TextDeep();puts("检测到字体信息未添加");TextNormal();
		Options[8][0]=Options[6][0];
		typedef BOOL (WINAPI *PROCGETCONSOLEFONTINFO)(HANDLE,BOOL,DWORD,CONSOLE_FONT*);
		typedef COORD (WINAPI *PROCGETCONSOLEFONTSIZE)(HANDLE,DWORD);
		typedef DWORD (WINAPI *PROCGETNUMBEROFCONSOLEFONTS)();
		typedef BOOL (WINAPI *PROCGETCURRENTCONSOLEFONT)(HANDLE,BOOL,CONSOLE_FONT*);
		
		PROCGETCONSOLEFONTINFO GetConsoleFontInfo = (PROCGETCONSOLEFONTINFO)GetProcAddress(hKernel32,"GetConsoleFontInfo");
		PROCGETCONSOLEFONTSIZE GConsoleFontSize = (PROCGETCONSOLEFONTSIZE)GetProcAddress(hKernel32,"GetConsoleFontSize");
		PROCGETNUMBEROFCONSOLEFONTS GetNumberOfConsoleFonts = (PROCGETNUMBEROFCONSOLEFONTS)GetProcAddress(hKernel32,"GetNumberOfConsoleFonts");
		PROCGETCURRENTCONSOLEFONT GCurrentConsoleFont = (PROCGETCURRENTCONSOLEFONT)GetProcAddress(hKernel32,"GetCurrentConsoleFont");
		int nNumFont;
		double dvx,dvy;
		
		nNumFont = GetNumberOfConsoleFonts();
		printf("本系统有%d种字体大小\n",nNumFont);
		CONSOLE_FONT *pFonts = new CONSOLE_FONT[nNumFont];
		GetConsoleFontInfo(COutputHandle, 0, nNumFont, pFonts);
		for(int i=0;i<nNumFont;i++)
		{
			dvx=pFonts[i].dim.X*1.000/CurrentFontSizeX*100;
			dvy=pFonts[i].dim.Y*1.000/CurrentFontSizeY*100;
//			printf("tmp:%d %d\n",pFonts[i].dim.X,pFonts[i].dim.Y);
//			printf("ID%d:%.3lf x %.3lf\n",i,dvx,dvy);
			for (int j=1;j<=Options[6][0];j+=2)
			{
				if (abs(dvx-Options[7][j])<10
				&&  abs(dvy-Options[7][j+1])<10)
				{
					printf ("ID%d:确认为%d x %d字体\n",i,Options[6][j],Options[6][j+1]);
					Options[8][j]=i;
					break;
				}
			}
		}
		//restore to options.txt
		tmps=StCh(Options[8][0]);
		LinePr(COptionsFileName,24,tmps);
		tmps="";
		
		for (int i=1;i<=Options[8][0];i++)
		tmps=tmps+StCh(Options[8][i])+" ";
		LinePr(COptionsFileName,25,tmps);
		tmps="";
		puts ("---Restoring Local Font Info完成");
	}
	if (CurrentFontSizeX!=Options[2][3]||CurrentFontSizeY!=Options[2][4])
	for (int i=1;i<=Options[6][0];i+=2)
	if (Options[6][i]==Options[2][3]&&Options[6][i+1]==Options[2][4])
	{
		SetConsoleFont(COutputHandle,Options[8][i]);
		CurrentFontIndex=Options[8][i];
		break;
	}
#else
	CFontSizeX=CurrentFontSizeX,CFontSizeY=CurrentFontSizeY;
#endif
#else
	CFontSizeX=CurrentFontSizeX,CFontSizeY=CurrentFontSizeY;
#endif
	return;
	//以下是旧版本(本来是当心坠物需要临时编的) 
	//在options里面更改CFontSizeX和CFontSizeY可以改变，但是要重新启动，不是特别需要就算了吧... 
#ifdef CLICK_OLDVERSION
	puts("--FontSizer.old");
	system("reg QUERY HKCU\\Console /v FontSize >tmp.txt");
	fstream in("tmp.txt",ios::in);
	char tmp[155];
	string data,tmps;
	int o=0;
	while(!in.eof())
	{
		in.getline(tmp,128);
		data=tmp;
		if(data.find(HEXR(CFontSizeY*65536+CFontSizeX))!=string::npos)
		{
			o=1;
			break;
		}
	}
	in.close();
	system("del tmp.txt");
	if(o==0)
	{
		puts("\n请允许修改注册表，这是为了使字体适合本程序设置\n如要更改，请更改options.txt中的CFontSizeX和CFontSizeY");
		tmps="reg ADD HKCU\\Console /v FontSize /t REG_DWORD /f /d "+StCh(CFontSizeY*65536+CFontSizeX);
		system(tmps.c_str());
		tmps="if not exist \".\\"+Optionstring[1]+"\" echo 请将本程序exe名字改回："+Optionstring[1]+"，否则无法启动";
		system(tmps.c_str());//警告 
		tmps="start \""+Optionstring[1]+"\" \""+Optionstring[1]+"\"";
		system(tmps.c_str());//重启 
		exit(0);
	}
	system("reg ADD HKCU\\Console /v FontSize /t REG_DWORD /f /d 0x00100008");
	return;
#endif
}
#ifndef CLICK_RELEASE
#ifndef CLICK_SIMPLE
const int junior=5;
const int senior[junior+1]={1,4,4,3,2,1};
char menu[][15][55]={
	{"Set System"}
	,{"1.WindowPosition","(Current)","拖拽窗口到你想要的位置然后Enter保存↓","保存","恢复默认"}
	,{"2.FontSize","(Current)","增大字号","减小字号","恢复默认"}
	,{"3.WindowVersion","(Current)","本Windows版本是Win7或以下","本Windows版本是Win7以上"}
	,{"4.ProcessName","(Current)","更改"}
	,{"5.保存并退出","按Enter或者Backspace保存并退出"}
};
/*p rivate*/ bool SetSystem()
{
	puts("--Preload");
	FontSizer();
	//FontSizer needed
	HMODULE hKernel32 = GetModuleHandle("kernel32");
	typedef BOOL (WINAPI *PROCSETCONSOLEFONT)(HANDLE, DWORD);
	PROCSETCONSOLEFONT SetConsoleFont = (PROCSETCONSOLEFONT)GetProcAddress(hKernel32,"SetConsoleFont");
	
	cc=0;
	int cs=0,css=0,ext=0;
	string tmps;
	while(cc!=8&&cc!=27)
	{
		TextNormal();lr();
		//digital refresh
		tmps="目前设置"+StCh(Options[1][1])+" "+StCh(Options[1][2])+" "+StCh(Options[1][3])+" "+StCh(Options[1][4]);
		strncpy(menu[1][1], tmps.c_str(), tmps.length() + 1);
		tmps="目前设置 ID"+StCh(CurrentFontIndex);
		strncpy(menu[2][1], tmps.c_str(), tmps.length() + 1);
		tmps="目前设置:";
		if(Options[4][1]==1)tmps=tmps+"Win7以上";
		else tmps=tmps+"Win7或以下";
		strncpy(menu[3][1], tmps.c_str(), tmps.length() + 1);
		tmps="目前设置:"+Optionstring[1];
		strncpy(menu[4][1], tmps.c_str(), tmps.length() + 1);

		//menu output-trunk
		gotoxy(0,0);
		for (int i=0;i<junior+1;i++)puts(menu[i][0]);
		//menu output-branch
		if (ext)
		for (int i=0;i<senior[cs]+1;i++)
		{
			gotoxy(i,30);
			puts(menu[cs][i]);
		}
		gotoxy(23,0);
		TextDeepCyan();puts("↑↓←→切换\tEnter选择\tBackspace保存并返回\tEsc不保存返回");TextNormal();
		//HL
		if (!ext&&cs!=0)
		{
			gotoxy(cs,0);
			HightLight();
			puts(menu[cs][0]);
			TextNormal();
		}
		if (ext)
		{
			gotoxy(0,30);
			puts(menu[cs][0]);
			gotoxy(css,30);
			HightLight();
			puts(menu[cs][css]);
			TextNormal();
		}
		
		cc=getch();
		
		if(cc==-32)
		{
			cc=getch();
			switch ((int)cc)
			{
				case 80:
				if (!ext)
				cs++,cs=(cs-1)%junior+1;
				else
				css++,css=(css-1)%senior[cs]+1;
				break;
				case 75:
				ext=0;
				break;
				case 72:
				if (!ext)
				cs--;
				if (cs<=0)cs=junior;
				else
				css--;
				if (css<=0)css=senior[cs];
				break;
				case 77:
				ext=1;
				css=1;
				break;
			}
		}
		if (cc==13)
		{
			if (cs==1)
			{
				if (css==4)Options[1][1]=Options[1][2]=Options[1][3]=Options[1][4]=-1;
				else
				{
					GetWindowRect(CMainHwnd,&CWindowRect);
					Options[1][1]=CWindowRect.left;
					Options[1][2]=(CWindowRect.right-CWindowRect.left)/Options[2][3];//CFontSizeX
					Options[1][3]=CWindowRect.top;
					Options[1][4]=(CWindowRect.bottom-CWindowRect.top)/Options[2][4];//CFontSizeY
				}
			}
			if (cs==5)
			{
				cc=8;
			}
			if (cs==2)
			{
				if (css==2)
				{
//					printf("%d %d x %d\n",CurrentFontIndex,CurrentFontSizeX,CurrentFontSizeY);system("pause");
					for(int i=1;i<=Options[8][0]-2;i+=2)
					if (CurrentFontIndex==Options[8][i])
					{
						CurrentFontIndex=Options[8][i+2];
						break;
					}
					SetConsoleFont(COutputHandle,CurrentFontIndex);
				}
				if (css==3)
				{
//					printf("%d %d x %d\n",CurrentFontIndex,CurrentFontSizeX,CurrentFontSizeY);system("pause");
					for(int i=1+2;i<=Options[8][0];i+=2)
					if (CurrentFontIndex==Options[8][i])
					{
						CurrentFontIndex=Options[8][i-2];
						break;
					}
					SetConsoleFont(COutputHandle,CurrentFontIndex);
				}
				if (css==4)
				{
					CurrentFontIndex=Options[8][FindFont(CurrentFontSizeX,CurrentFontSizeY)];
					SetConsoleFont(COutputHandle,CurrentFontIndex);
				}
			}
			if (cs==3)
			{
				if (css==2)
				{
					Options[4][1]=0;
				}
				if (css==3)
				{
					Options[4][1]=1;
				}
			}
			if (cs==4)
			{
				gotoxy (21,0);
				HightLight();puts("请输入本程序的名称(*.exe)，无需双引号");TextNormal();
				getline(cin,tmps);
//				很遗憾，c++没有收录libcomdlg32.a库文件，所以无法实现了 
//				虽然可以手动添加，不过为了不给后来的编辑添加麻烦还是算了 
//				TCHAR szBuffer[MAX_PATH] = {0};   
//				OPENFILENAME ofn= {0};   
//				ofn.lStructSize = sizeof(ofn);   
//				ofn.CMainHwndOwner = CConsoleHwnd;   
//				ofn.lpstrFilter = _T("本程序的EXE文件(*.exe)\0*.exe\0");//要选择的文件后缀   
//				ofn.lpstrInitCConsoleLeftDir = _T("%userprofile%\\desktop");//默认的文件路径   
//				ofn.lpstrFile = szBuffer;//存放文件的缓冲区   
//				ofn.nMaxFile = sizeof(szBuffer)/sizeof(*szBuffer);   
//				ofn.nFilterIndex = 0;   
//				ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER ;//标志如果是多选要加上OFN_ALLOWMULTISELECT  
//				BOOL bSel = GetOpenFileName(&ofn);  
//				printf("路径:%s\n",szBuffer);
				Optionstring[1]=tmps;
			}
		}
	}
	if (cc==8)
	{
		gotoxy(23,0);
		HightLight();puts("保存设置中...");TextNormal();
		//1Winp
		tmps="";
		for (int i=1;i<=4;i++)
		tmps=tmps+StCh(Options[1][i])+" ";
		LinePr(COptionsFileName,4,tmps);
		//2Fonts
		tmps="";
		for(int i=1;i<=Options[8][0];i+=2)
		if (CurrentFontIndex==Options[8][i])
		{
			Options[2][3]=Options[6][i];
			Options[2][4]=Options[6][i+1];
			break;
		}
		for (int i=1;i<=5;i++)
		tmps=tmps+StCh(Options[2][i])+" ";
		LinePr(COptionsFileName,7,tmps);
		//3Winv
		tmps="";
		for (int i=1;i<=1;i++)
		tmps=tmps+StCh(Options[4][i])+" ";
		LinePr(COptionsFileName,13,tmps);
		//4Proc
		LinePr(COptionsFileName,16,Optionstring[1]);
		
		Sleep(200);
	}
	else 
	{
		lr();
		return 0;
	}
	lr();
	TextDeepCyan();puts("Version Verify->Set System完成");TextNormal();
	return 1;
}
#endif
#endif
/*p rivate*/ bool VerVerify()//设置检查读取 
{
#ifndef CLICK_SIMPLE
	int Ln=2;
	int ans;
	char anss[128],ccc;
#ifndef CLICK_RELEASE
	puts ("Version Verify");
	HightLight();
	puts("请允许读写、批处理和注册操作");
	puts ("所有操作经多方测试，可以信任~\n");
	TextNormal();
#endif
	//Version Verify&Options Creating
	system("attrib -r -a options.txt");
	ifstream in("options.txt");
	in.getline(anss,128);
	in.close();
	if (anss!=OptionsForge.substr(0,51))
	{
	
		TextDeep();
		puts ("The Options(options.txt) have not be initCConsoleLeftize or it is broken!");
		puts("程序设置未初始化");
		HightLight();
		cout<<"Please RESTART LATER\n请稍候重启该程序！\n";
		TextNormal();
		cout<<"\nVERSION:"<<Version<<"\nReWriting...\n";
		Rst:;	//Reset Mark 
		if(!LinePr((char*)"*A",0,""))
		{
			TextDeepRed();
			if (MessageBox(CConsoleHwnd,"E1:初始化错误\n请联系lz询问原因\n请允许读写、批处理和注册操作\n所有操作经多方测试，可以信任~","Process Erruption",MB_RETRYCANCEL)==IDRETRY)
			goto Rst;
#ifndef CLICK_RELEASE
			cout<<"Initialize faild\a\t[Any key to continue]\n";
#endif
			char cc=getch();
			exit(0);
		}
#ifndef CLICK_RELEASE
		TextDeepGreen();
		cout<<"InitCConsoleLeftize succeed\t[Any key to continue]\n[任意键继续]\t\n\n";
		TextNormal();
#endif
	}
	Reread:;
	//Read Options.txt
	in.open("options.txt",ios::in);
	in.getline(anss,64);
	while(in.peek()!=EOF)
	{
		Optionstot++;
		in.getline(anss,128);
		in>>Options[Optionstot][0];
		if(Options[Optionstot][0]==-1)
		{
			in.getline(anss,128);
			in.getline(anss,128);
			Optionstring[++Optionstringtot]=anss;
		}
		else
		{
			for(int i=1;i<=Options[Optionstot][0];i++)
			in>>Options[Optionstot][i];
		}
		in>>ccc;
	}
#ifndef CLICK_RELEASE
	Sleep(200);
	if (kbhit())
	{
		if (getch()==9)
		{
			puts("--Setting System(Tab)");
			Sleep(750);
			if (SetSystem()==0)goto Reread;
		}
	}
#endif
#else//if you want to change options of litemode,change it here! 
#define O(a,b) Options[a][b]
	Optionstringtot=1;
	Optionstring[1]="clicking!.exe";
	Optionstot=6;
	O(0,0)=0;
	O(1,0)=4;
	O(1,1)=-1;O(1,2)=-1;O(1,3)=-1;O(1,4)=-1;
	O(2,0)=5;
	O(2,1)=1;O(2,2)=7;O(2,3)=8;O(2,4)=16;O(2,5)=0;
	O(3,0)=2;
	O(3,1)=7;O(3,2)=25;
	O(4,0)=1;
	O(4,1)=0;
	O(5,0)=-1;
	O(5,1)=0;
	O(6,0)=12;
	O(6,1)=3;O(6,2)=5;O(6,3)=5;O(6,4)=8;O(6,5)=6;O(6,6)=12;
	O(6,7)=8;O(6,8)=16;O(6,9)=8;O(6,10)=18;O(6,11)=10;O(6,12)=20;
	O(7,0)=12;
	O(7,1)=2663;O(7,2)=517;O(7,3)=1600;O(7,4)=325;O(7,5)=1327;O(7,6)=208;
	O(7,7)=2000;O(7,8)=426;O(7,9)=1000;O(7,10)=142;O(7,11)=800;O(7,12)=125;
	O(8,0)=12;
	O(8,1)=0;O(8,2)=0;O(8,3)=2;O(8,4)=0;O(8,5)=7;O(8,6)=0;
	O(8,7)=1;O(8,8)=0;O(8,9)=13;O(8,10)=0;O(8,11)=15;O(8,12)=0;
//		{4,-1,-1,-1,-1},
//		{5,1,7,8,16,0},
//		{2,7,25},
//		{1,0},
//		{-1},
//		{12,3,5,5,8,6,12,8,16,8,18,10,20},
//		{12,2663,517,1600,325,1327,208,2000,426,1000,142,800,125},
//		{12,0,0,2,0,7,0,1,0,13,0,15,0}
#endif
	Trans=Options[2][1];
	FV=Options[2][5];//为了给他俩调顺序，允许修改，只能把预处理放在这儿了 
	return 1;
}
/*p rivate*/ bool Form_load()
{
#ifndef CLICK_RELEASE
	puts("Process Preload");
	//API类 
	//有些电脑的codepage不对，所以显示不了中文，但是改过一次以后都不用了 
	puts("--Codepage");
#endif
//	system("chcp 936");
#ifndef CLICK_RELEASE
	puts("--Buffer Size");
#endif
	SetConsoleScreenBufferSize(COutputHandle,CBufferSize);
#ifndef CLICK_RELEASE
	puts("--Font Sizer");
#endif
	FontSizer();//调整字体大小，可禁用 
#ifndef CLICK_RELEASE
	puts("--Screen Position");
#endif
	GetWindowRect(CMainHwnd,&CWindowRect);
	if(CConsoleLeft==-1) CConsoleLeft=CWindowRect.left;
	if(CConsoleRight==-1) CConsoleRight=CWindowRect.right;
	else
	{
		CConsoleRight+=4;
		CConsoleRight*=CurrentFontSizeX;
		CConsoleRight+=CConsoleLeft;
	}
	if(CConsoleTop==-1) CConsoleTop=CWindowRect.top;
	if(CConsoleBottom==-1) CConsoleBottom=CWindowRect.bottom;
	else
	{
		CConsoleBottom+=4;
		CConsoleBottom*=CurrentFontSizeY;
		CConsoleBottom+=CConsoleTop;
	}
//	printf("%d %d %d %d\n",CConsoleLeft,CConsoleRight,CConsoleTop,CConsoleBottom);
	ChangeWindowPosition(CConsoleLeft,CConsoleTop,CConsoleRight-CConsoleLeft,CConsoleBottom-CConsoleTop);//假如options中的窗口位置不是-1，那么移动窗口到指定位置 
	//移除 快速编辑 插入 模式
#ifndef CLICK_RELEASE
	puts("--Insertion Mode");
#endif
	DWORD mode;
	GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;
	mode &= ~ENABLE_INSERT_MODE;
	mode &= ~ENABLE_MOUSE_INPUT;
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), mode);
#ifndef CLICK_RELEASE
	puts("--Cursor Info");
#endif
	GetConsoleCursorInfo(COutputHandle, &CCursorInfo);//获取控制台光标信息
//	CCursorInfo.bVisible=bvisible;//因为控制台并不确定什么时候要显示光标，故不调试 
//	SetConsoleCursorInfo(COutputHandle, &CCursorInfo);
#ifndef CLICK_RELEASE
	puts("--Buffer Info");
#endif
	GetConsoleScreenBufferInfo(COutputHandle,&CConsoleScreenBufferInfo);//获取缓冲信息 
#ifndef CLICK_RELEASE
	puts("--Window Title");
#endif
	GetWindowText(CMainHwnd,CTitle,1000);//获取窗口标题 
#ifndef CLICK_RELEASE
	puts("API类完成");
#endif
	//CLICKING类 
	for(int w=0;w<WDD;w++)//预处理背景 
	for(int i=0;i<WDLMT;i++)
	for(int j=0;j<WDLMT;j++)
	{
		CColor_sys[w][i][j]=wOldColorAttrs;
		CChar_sys[w][i][j]=" ";
	}
#ifndef CLICK_RELEASE
	puts("C类完成\n");
	lr();
#endif
	return 1;
}

//INITIALIZE COMPLETED----------------------------------------------------------------

/*p rivate*/ void eout(string s,int sx,int sy)//Thank YYC for this code--lighting subtitles!闪电字幕 
//本函数来自yyc“妙手偶得”，原本编录于OIBox，可惜现在OIBox不用c++编了。有改动 
{
	int i=0,m=0,p=EoutDelay,lineot=0;//p:调速 (ms)
	//lineot:当前行已经输出了多少个字符 
	POINT pt;//这个用于检测鼠标是否已经离开了一定范围（临时中断）
	bool TKmoved;//这个用于检测鼠标是否点击（也要临时中断） 
	char sds;
	sx++;//sx，sy这两个参数是为了配合msgbox的指定位置输出 ,但是sx有1单位偏移 
	gotoxy(sy,sx);
	TKmoved=KEY_DOWN(MOUSE_MOVED);
	GetCursorPos(&pt);
	int nwpx=pt.x,nwpy=pt.y;
	while(i<s.size()
	&& !( max(abs(pt.x-nwpx),abs(pt.y-nwpy))>IDDTFP || KEY_DOWN (MOUSE_MOVED)!=TKmoved))
	{
		if (s[i]==EndlSympol)
		{
//			if (s[i-1]>0)
//			cout<<' ';
			sy++;lineot=-1;
			gotoxy(sy,sx);
		}
		if (s[i]!=EndlSympol)
		{
			gotoxy(sy,sx+lineot);
			cout<<'|';
			if (!kbhit())Sleep(p);
			gotoxy(sy,sx+lineot);
			cout<<"┃";
			if (!kbhit())Sleep(p);
			gotoxy(sy,sx+lineot);
			cout<<"▊";
			if (!kbhit())Sleep(p);
			if (kbhit() && i%3==0)sds=getch();
			if (s[i]<0)
			{
				gotoxy(sy,sx+lineot);
				cout<<s[i]<<s[i+1];
				i++;lineot++;
			}
			else
			{
				gotoxy(sy,sx+lineot);
				cout<<s[i];
			}
		}
		i++;
		if (!kbhit())Sleep(p);
		Sleep(p);
		GetCursorPos(&pt);
		lineot++;
	}
	cout<<" ";
	gotoxy(sx,sy+lineot);
	return;
}
#ifndef CLICK_SIMPLE
void CAreaSelect(int left,int top,int right,int down,int &px,int &py)//area selecting区域选择* 
//这是clicking的最早期版本，原来用于选择一个范围，作为窗口的大小，只是暂时不需要了 
{
	POINT pt;int o=0;
	system("mode con cols=175 lines=50");
	ChangeWindowPosition(0,0,1600,900);
	while(!o)
	{
		while(KEY_DOWN(MOUSE_MOVED))
		{
			lr();GetCursorPos(&pt);
			if (pt.x/CFontSizeX<left || pt.y/CFontSizeY<top || pt.x/CFontSizeX>right || pt.y/CFontSizeY>down)continue;
			px=pt.x/CFontSizeX,py=pt.y/CFontSizeY;
			gotoxy (pt.y/CFontSizeY-2,pt.x/CFontSizeX-2);
			cout<<Sp0;
			gotoxy(pt.y/CFontSizeY-1,pt.x/CFontSizeX-2);
			cout<<pt.x/CFontSizeX<<"*"<<pt.y/CFontSizeY;
			o=1;Sleep(50);
			gotoxy(pt.y/CFontSizeY-2,pt.x/CFontSizeX-2);cout<<"  ";
			gotoxy(pt.y/CFontSizeY-1,pt.x/CFontSizeX-2);cout<<"        ";
		}
	}
	lr();cout<<"select area:"<<px<<"*"<<py<<endl;//px,py是选择的范围 
	Sleep(1000);
	ChangeWindowPosition(CWindowRect.left,CWindowRect.top,CWindowRect.right-CWindowRect.left,CWindowRect.bottom-CWindowRect.top);//还原原窗口大小 
	return;
}
#endif
void CAreaRefresh(int sx,int sy,int ex,int ey)
//explain:from(sx,sy)to(ex,ey)将sx,sy到ex,ey之间的空间还原（为原来的窗口内容） 
{
//	printf("ACLR:%d %d-%d %d\n%s",sx,sy,ex,ey,CWindowOrder.c_str());
	int bs,ctextcolour=wOldColorAttrs,CTempWD=CCurrentWD,BeSwitched=0;
	string tmp="";
//#ifndef OLD_VERSION
//	for (int i=sx;i<=ex;i++)
//	{
//		if (tmp!="")
//		{
//			SetConsoleTextAttribute (COutputHandle,ctextcolour);
//			cout<<tmp;
//			ctextcolour=CColor_sys[bs][i][sy];
//			tmp="";
//		}
////		gotoxy(22,0);
////		cout<<i<<" "<<sy<<"   ";
////		Sleep(200);
////		cout<<"\b\b\b\b\b\b\b\b                ";
//
//		//更新CTempWD
//		if (!Trans)bs=CWindowOrder[0]-'0';//若设置了"仅顶层窗口可见"
//		else
//		for (int ii=0;ii<CWindowOrder.size();ii++)//否则查找当前位置属于哪个窗口 
//		if (sy-1>=CWindowLeft_sys[CWindowOrder[ii]-'0'] && sy-1<=CWindowRight_sys[CWindowOrder[ii]-'0'] && i>=CWindowTop_sys[CWindowOrder[ii]-'0'] && i<=CWindowBottom_sys[CWindowOrder[ii]-'0'])//判断当前位置属于窗口
//		{
//			CTempWD=CWindowOrder[ii]-'0';
//			break;
//		}
//		LastIsChinese=0;
//		
//		gotoxy(i,sy);
//		for (int j=sy;j<=ey;j++)
//		{
//			bs=0;
//			if (!Trans)bs=CWindowOrder[0]-'0';//若设置了"仅顶层窗口可见"
//			else
//			for (int ii=0;ii<CWindowOrder.size();ii++)//否则查找当前位置属于哪个窗口 
//			if (j>=CWindowLeft_sys[CWindowOrder[ii]-'0'] && j<=CWindowRight_sys[CWindowOrder[ii]-'0'] && i>=CWindowTop_sys[CWindowOrder[ii]-'0'] && i<=CWindowBottom_sys[CWindowOrder[ii]-'0'])//判断当前位置属于窗口
//			{
//				bs=CWindowOrder[ii]-'0';
//				break;
//			}
//			if (bs!=CTempWD)//窗口之间必须完成输出 
//			{
//			//gotoxy(24,0);cout<<"bswd"<<" "<<bs<<" "<<CTempWD;cc=getch();
//				CTempWD=bs;
//				SetConsoleTextAttribute (COutputHandle,ctextcolour);
//				cout<<tmp;
//				gotoxy(i,j);
//				tmp="";
////				if (CValue_sys[bs][i][j]==-1)
////				tmp=" ";//补齐行首 
////				else
////				tmp=CChar_sys[bs][i][j];
////				j++;
//			}
//			
//			if (CValue_sys[bs][i][j]==-1)
//			{
//				if (!LastIsChinese)
//				{
//					cout<<'\b';
//					j-=2;
//				}
//				j++;
//			}
//			if (CColor_sys[bs][i][j]==ctextcolour)
//			{
//				tmp=tmp+CChar_sys[bs][i][j];
//			}
//			else
//			{
//				SetConsoleTextAttribute (COutputHandle,ctextcolour);
//				cout<<tmp;
//				ctextcolour=CColor_sys[bs][i][j];
//				tmp=CChar_sys[bs][i][j];
//			}
//			if (CChar_sys[bs][i][j].size()>1)LastIsChinese=1;
//			else LastIsChinese=0;
////旧版本：完全令人想不到的是，scanf比cin快，但printf却像拖拉机一样慢，比puts慢4倍左右,比cout慢十倍以上! 
////			if (CValue_sys[bs][i][j]!=-1)
////			{
////				SetConsoleTextAttribute (COutputHandle,CColor_sys[bs][i][j]);
////				printf ("%s",CChar_sys[bs][i][j].c_str());
////				if (CChar_sys[bs][i][j].size()==2)j++;
////			}
////			else
////			{
////				SetConsoleTextAttribute (COutputHandle,CColor_sys[bs][i][j-1]);
////				printf ("\b%s",CChar_sys[bs][i][j-1].c_str());
////			}
//		}
//	}
//#else
	//更新CTempWD
	if (!Trans)bs=CWindowOrder[0]-'0';//若设置了"仅顶层窗口可见"
	else
	for (int ii=0;ii<CWindowOrder.size();ii++)//否则查找当前位置属于哪个窗口 
	if (sy>=CWindowLeft_sys[CWindowOrder[ii]-'0'] && sy<=CWindowRight_sys[CWindowOrder[ii]-'0'] && sx>=CWindowTop_sys[CWindowOrder[ii]-'0'] && sx<=CWindowBottom_sys[CWindowOrder[ii]-'0'])//判断当前位置属于窗口
	{
		bs=CWindowOrder[ii]-'0';
		break;
	}
//	LastIsChinese=0;
	for (int i=sx;i<=ex;i++)
	{
		for (int j=sy;j<=ey;j++)
		{
			ctextcolour=CColor_sys[bs][i][j];
			gotoxy(i,j);
			while (j<=ey)
			{
				//更新CTempWD
				if (!Trans)CTempWD=CWindowOrder[0]-'0';//若设置了"仅顶层窗口可见"
				else
				for (int ii=0;ii<CWindowOrder.size();ii++)//否则查找当前位置属于哪个窗口 
				if (j>=CWindowLeft_sys[CWindowOrder[ii]-'0'] && j<=CWindowRight_sys[CWindowOrder[ii]-'0'] && i>=CWindowTop_sys[CWindowOrder[ii]-'0'] && i<=CWindowBottom_sys[CWindowOrder[ii]-'0'])//判断当前位置属于窗口
				{
					CTempWD=CWindowOrder[ii]-'0';
					if (bs != CTempWD)
					{
						bs=CTempWD;
						j--;
						BeSwitched=1;//发生了窗口切换 
					}
					break;
				}
				if (BeSwitched)
				{BeSwitched=0;break;}//接受窗口切换消息 
				CIfRefresh_sys[bs][i][j]=0;
				if (CValue_sys[bs][i][j]==-1)
				{
//					if (CChar_sys[bs][i][j-1].size()<=1)//该中文后半块被切开 
//					tmp=" ",j++;
//					else
					if (j==sy)
					{
						ctextcolour=CColor_sys[bs][i][j-1];
						tmp=CChar_sys[bs][i][j-1];//输出被切断的中文 
						gotoxy(i,j-1);//回退一格用于补齐中文 
					}
					j++;//(不管是否截断)中文已经输出了，跳过 
				}
				if (CColor_sys[bs][i][j]==ctextcolour)
				{
					tmp=tmp+CChar_sys[bs][i][j];
				}
				else
				{
					j--;//颜色不同，下一轮再处理，把光标回移1
					break;//退出循环再处理已吸收数据 
				}
				j++;
			}
			//因为是矩阵，必然会有输出 
				SetConsoleTextAttribute (COutputHandle,ctextcolour);
				cout<<tmp;
				tmp="";
//旧版本：完全令人想不到的是，scanf比cin快，但printf却像拖拉机一样慢，比puts慢4倍左右,比cout慢十倍以上! 
//			if (CValue_sys[bs][i][j]!=-1)
//			{
//				SetConsoleTextAttribute (COutputHandle,CColor_sys[bs][i][j]);
//				printf ("%s",CChar_sys[bs][i][j].c_str());
//				if (CChar_sys[bs][i][j].size()==2)j++;
//			}
//			else
//			{
//				SetConsoleTextAttribute (COutputHandle,CColor_sys[bs][i][j-1]);
//				printf ("\b%s",CChar_sys[bs][i][j-1].c_str());
//			}
		}
	}
//#endif
//	gotoxy(22,0);
//	printf("finish");Sleep(500);cout<<"\b\b  ";
	return;
}
void CWriteWindow(int wd,int x,int y,string s,int ct,string cm,int cml,int cmt,int cmdl,int cmmd,int cmbds,int cl)//menu writing system菜单写入系统*
//explain:window:wd(it will be auto existed),boardstyle:wdbds(See WindowLeftBoard WindowTopBoard),start from (x,y), text:s, return value:ct, comment:cm, comment start from (cml,cmt) [-1 means auto]
{
	int cmp=0,cxl,cxt;//cxl,cxt是注释起始位置 cmp标记是否是中文 
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='}')
		{
			x++;
			s=s.substr(i+1,s.size()-i);
			i=0;
		}
		if(s[i]==ChineseSymbol){cmp=1;s.erase(i,1);}//ChineseSymbol标记后面的两个字符是全角字符 
		CValue_sys[wd][x][y+i]=ct;
		CIfRefresh_sys[wd][x][y+i]=1;
		if(cml==-1)cxl=x+1;else cxl=cml;
		if(cmt==-1)cxt=y+i;else cxt=cmt;
		CComment_sys[wd][x][y+i]=cm;
		CCommentTop_sys[wd][x][y+i]=cxt;
		CCommentLeft_sys[wd][x][y+i]=cxl;
		CCommentDelay_sys[wd][x][y+i]=cmdl;
		CCommentMode_sys[wd][x][y+i]=cmmd;
		CCommentBoard_sys[wd][x][y+i]=cmbds;
		CColor_sys[wd][x][y+i]=cl;
		if(ChineseCheck(s[i],s[i+1])||cmp)//chck 判断这两个字符是否组成中文 
		{
			CChar_sys[wd][x][y+i]=s.substr(i,2);
			CValue_sys[wd][x][y+i+1]=-1;
			CIfRefresh_sys[wd][x][y+i+1]=1;
			CComment_sys[wd][x][y+i+1]=cm;
			CCommentTop_sys[wd][x][y+i+1]=cxt;
			CCommentLeft_sys[wd][x][y+i+1]=cxl;
			CCommentDelay_sys[wd][x][y+i+1]=cmdl;
			CCommentMode_sys[wd][x][y+i+1]=cmmd;
			CCommentBoard_sys[wd][x][y+i+1]=cmbds;
			CColor_sys[wd][x][y+i+1]=cl;
			i++;cmp=0;
		}
		else
		{
			CChar_sys[wd][x][y+i]=s[i];
		}
	}
	return;
}
void CAllRefresh()
{
//	printf("CLR:%d %d %d %d\n",(CConsoleBottom-CConsoleTop-CConsoleTopBoard),(CConsoleRight-CConsoleLeft-CConsoleBoard),(CConsoleBottom-CConsoleTop-CConsoleTopBoard)/CFontSizeY-2,(CConsoleRight-CConsoleLeft-CConsoleBoard)/CFontSizeX-2);
	CAreaRefresh(0,0,(CConsoleBottom-CConsoleTop-CConsoleTopBoard-CConsoleBoard)/CFontSizeY,(CConsoleRight-CConsoleLeft-(CConsoleBoard<<1))/CFontSizeX);
	return;
}
void CSpeedRefresh(int Count,...)//快速刷新，只刷新被更新的窗口位置 ，原来的spclr替换为本函数 
{
	int bs,ctextcolour=-1,*tmpnum=&Count,BeCovered=0,CTempWD=0,tasktmp;
	string tmp="";
	if (!Count)//若Count=0则刷新全局，否则刷新指定的窗口 
	{
		//执行part (执行Show\Hide标记的任务)
		for(;CTasks_sys[0]>=1;CTasks_sys[0]--)
		{
			tasktmp=CTasks_sys[CTasks_sys[0]];
			if(tasktmp>0)//显示某个窗口 
			{
				CSpeedRefresh(1,tasktmp);
			}
			else if (tasktmp<0)
			{
				tasktmp=-tasktmp;
				CAreaRefresh(CWindowTop_sys[tasktmp],CWindowLeft_sys[tasktmp],CWindowBottom_sys[tasktmp],CWindowRight_sys[tasktmp]);//刷新窗口内的全部字符 
				if (tasktmp==CCurrentWD)//防止窗口去注释不空 
				CAreaRefresh(CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY],CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY],CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXHeight,CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXLine);//清除注释
			}
			else//tasktmp==0
			{
				SetConsoleTextAttribute(COutputHandle,wOldColorAttrs);
				lr();//为了清除不必要的颜色 
				CAllRefresh();
			}
		}
		
		for (int wd=CWindowOrder.size()-1;wd>=0;wd--)
		{
			bs=CWindowOrder[wd]-'0';
			for (int i=CWindowTop_sys[bs];i<=CWindowBottom_sys[bs];i++)
			{
				for (int j=CWindowLeft_sys[bs];j<=CWindowRight_sys[bs];j++)
				if (CIfRefresh_sys[bs][i][j])
				{
//					if (CMessageXHeight&&CMessageXLine//触发了comment 
//					&&i>=CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY]
//					&&i<=CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXHeight
//					
//					&&j>=CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY]
//					&&j<=CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXLine//假如刷新在msgbox范围就会造成搞笑效果
//					||
//					bs!=CTempWD)
//					continue;

	//				gotoxy(23,0);
	//				cout<<i<<" "<<j;
	//				Sleep(50);
	//				cout<<"\b\b\b\b\b     ";
					
					ctextcolour=CColor_sys[bs][i][j];
					gotoxy(i,j);
					while (j<=CWindowRight_sys[bs]&&CIfRefresh_sys[bs][i][j])
					{
						if (!Trans)CTempWD=CWindowOrder[0]-'0';//若设置了"仅顶层窗口可见"
						else
						for (int ii=0;ii<CWindowOrder.size();ii++)//否则查找当前位置属于哪个窗口 
						if (j>=CWindowLeft_sys[CWindowOrder[ii]-'0'] && j<=CWindowRight_sys[CWindowOrder[ii]-'0'] && i>=CWindowTop_sys[CWindowOrder[ii]-'0'] && i<=CWindowBottom_sys[CWindowOrder[ii]-'0'])//判断当前位置属于窗口
						{
							CTempWD=CWindowOrder[ii]-'0';
							if (bs!=CTempWD)//刷新的位置被遮盖 
							{
								j=CWindowRight_sys[CWindowOrder[ii]-'0']+1;
								BeCovered=1;
							}
							break;
						}
						if (CMessageXHeight&&CMessageXLine//触发了comment 
						&&i>=CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY]
						&&i<=CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXHeight
						
						&&j>=CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY]
						&&j<=CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXLine//假如刷新在msgbox范围就会造成搞笑效果
						)
						{
							j=CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXLine+1;//直接跳过msgbox 
							continue;
						}
						if (BeCovered)
						{BeCovered=0;continue;}//接受被覆盖的消息 
						
						CIfRefresh_sys[bs][i][j]=0;
						if (CValue_sys[bs][i][j]==-1)
						{
							if (CChar_sys[bs][i][j-1].size()<=1)//该中文后半块被切开 
							tmp=" ";
							j++;
						}
						if (CColor_sys[bs][i][j]==ctextcolour)
						{
							tmp=tmp+CChar_sys[bs][i][j];
						}
						else
						{
							j--;//颜色不同，下一轮再处理，把光标回移1
							break;//退出循环再处理已吸收数据 
						}
						j++;
					}
					if (tmp!="")
					{
						SetConsoleTextAttribute (COutputHandle,ctextcolour);
						cout<<tmp;
						tmp="";
					}
				}
			}
		}
		for (int i=0;i<=(CConsoleBottom-CConsoleTop-CConsoleTopBoard-CConsoleBoard)/CFontSizeY;i++)//刷新野地里的光标、注释之类 
		{
			for (int j=0;j<=(CConsoleRight-CConsoleLeft-(CConsoleBoard<<1))/CFontSizeX;j++)
			if (CIfRefresh_sys[0][i][j])
			{
				ctextcolour=CColor_sys[0][i][j];
				gotoxy(i,j);
				while (j<=(CConsoleRight-CConsoleLeft-(CConsoleBoard<<1))/CFontSizeX&&CIfRefresh_sys[0][i][j])
				{
					if (CMessageXHeight&&CMessageXLine//触发了comment 
					&&i>=CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY]
					&&i<=CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXHeight
					
					&&j>=CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY]
					&&j<=CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXLine//假如刷新在msgbox范围就会造成搞笑效果
					)
					{
						j=CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXLine+1;//直接跳过msgbox 
						continue;
					}
					
					CIfRefresh_sys[0][i][j]=0;
					if (CValue_sys[0][i][j]==-1)
					{
						if (CChar_sys[0][i][j-1].size()<=1)//该中文后半块被切开 
						tmp=" ";
						j++;
					}
					if (CColor_sys[0][i][j]==ctextcolour)
					{
						tmp=tmp+CChar_sys[0][i][j];
					}
					else
					{
						j--;//颜色不同，下一轮再处理，把光标回移1
						break;//退出循环再处理已吸收数据 
					}
					j++;
				}
				if (tmp!="")
				{
					SetConsoleTextAttribute (COutputHandle,ctextcolour);
					cout<<tmp;
					tmp="";
				}
			}
		}
	}
	else
	for (int wd=1;wd<=Count;wd++)//该处替换spclr()函数 ，刷新bs内的所有(包括空格)字符
	{
		*tmpnum++;*tmpnum++;//我也不知道为什么要加两次，但是这样才有数据 
		bs=*tmpnum;
		for (int i=CWindowTop_sys[bs];i<=CWindowBottom_sys[bs];i++)
		for (int j=CWindowLeft_sys[bs];j<=CWindowRight_sys[bs];j++)
		{
//			while (j<=CWindowRight_sys[bs])
//			{
//				if (CValue_sys[bs][i][j]==-1)
//				{
//					if (!LastIsChinese)
//					{
//						tmp+=CChar_sys[bs][i][j-1];
//						cout<<'\b';
//					}
//					j++;
//				}
//				if (CColor_sys[bs][i][j]==ctextcolour)
//				{
//					tmp=tmp+CChar_sys[bs][i][j];
//				}
//				else
//				{
//					SetConsoleTextAttribute (COutputHandle,ctextcolour);
//					cout<<tmp;
//					tmp=CChar_sys[bs][i][j];
//					ctextcolour=CColor_sys[bs][i][j];
//				}
//				if (CChar_sys[bs][i][j].size()>1)LastIsChinese=1;
//				else LastIsChinese=0;
//				j++;
//			}
//			if (tmp!="")
//			{
//				SetConsoleTextAttribute (COutputHandle,ctextcolour);
//				cout<<tmp;
//				tmp="";
//			}
			gotoxy(i,j);
			ctextcolour=CColor_sys[bs][i][j];
			while (j<=CWindowRight_sys[bs])
			{
				CIfRefresh_sys[bs][i][j]=0;
				if (CValue_sys[bs][i][j]==-1)
				{
					if (CChar_sys[bs][i][j-1].size()<=1)//该中文后半块被切开 
					tmp=" ";
					j++;
				}
				if (CColor_sys[bs][i][j]==ctextcolour)
				{
					tmp=tmp+CChar_sys[bs][i][j];
				}
				else
				{
					j--;//颜色不同，下一轮再处理，把光标回移1
					break;//退出循环再处理已吸收数据 
				}
				j++;
			}
			if (tmp!="")
			{
				SetConsoleTextAttribute (COutputHandle,ctextcolour);
				cout<<tmp;
				tmp="";
			}
		}
	}
	return;
}
void CShowWindow(int wd)//显示窗口k ,可以在CEnabled=0时调用 
{
	for(int i=0;i<CWindowOrder.size();i++)
	if (CWindowOrder[i]-'0'==wd)
	{
		CWindowOrder.erase(i,1);
		break;
	}
	CWindowOrder.insert(0,1,(char)(wd+'0'));
	CTasks_sys[++CTasks_sys[0]]=wd;
	return;
}
void CHideWindow(int wd)//隐藏窗口k ,可以在CEnabled=0时调用
{
	for(int i=0;i<CWindowOrder.size();i++)
	if(CWindowOrder[i]-'0'==wd)
	{
		CWindowOrder.erase(i,1);
		break;
	}
	CTasks_sys[++CTasks_sys[0]]=-wd;
	return;
}
/*p rivate*/ void CCreateWindow(int wd,int wdbds,string wdtp,int cwl,int cwt,int cwr,int cwb)//window writing system窗口创建系统
{
	int o=0;
	string tmp="";
	CWindowLeft_sys[wd]=cwl;
	CWindowTop_sys[wd]=cwt;
	CWindowRight_sys[wd]=cwr;
	CWindowBottom_sys[wd]=cwb;
	CWindowTopic_sys[wd]=wdtp;

	for(int i=1;i<=cwr-cwl;i++)tmp+=WindowTopBoard[wdbds];
	CWriteWindow(wd,cwt,cwl,tmp,32767,"",0,0,0,0,0,wOldColorAttrs|0x8);
	CWriteWindow(wd,cwb,cwl,tmp,0,"",0,0,0,0,0,wOldColorAttrs|0x8);
	tmp="";
	for(int i=1;i<=cwb-cwt+1;i++)tmp+=WindowLeftBoard[wdbds]+'}';
	CWriteWindow(wd,cwt,cwl,tmp,0,"",0,0,0,0,0,wOldColorAttrs|0x8);
	CWriteWindow(wd,cwt,cwr,tmp,0,"",0,0,0,0,0,wOldColorAttrs|0x8);
	CWriteWindow(wd,cwt,(cwl+cwr)/2-wdtp.size()/2,wdtp,32767,"",0,0,0,0,0,wOldColorAttrs|0x8);
	//本来想添加，不过至今还没编写 
//	cw(wd,cwt,cwr-6,"[ ][ ]",0,"",0,0,0,0,0,wOldColorAttrs);
//	cw(wd,cwt,cwr-5,"-",-3,"",0,0,0,0,0,wOldColorAttrs|0x8|0x10|0x80);
//	cw(wd,cwt,cwr-2,"X",-4,"",0,0,0,0,0,wOldColorAttrs|0x8|0x10|0x80);
	return;
}
void CDeleteWindow(int k)//删除窗口k 
{
	CHideWindow(k);
	for(int i=0;i<WDLMT;i++)//删除它的数据 
	for(int j=0;j<WDLMT;j++)
	{
		CChar_sys[k][i][j]=" ";
		CValue_sys[k][i][j]=0;
		CComment_sys[k][i][j]="";
		CCommentTop_sys[k][i][j]=0;
		CCommentLeft_sys[k][i][j]=0;
		CCommentDelay_sys[k][i][j]=0;
		CCommentMode_sys[k][i][j]=0;
		CCommentBoard_sys[k][i][j]=0;
		CColor_sys[k][i][j]=wOldColorAttrs;
	}
	return;
}
/*p rivate*/ void msgbox(int wd,int sx,int sy,int cl,string msg,int md,int bdstyle)//MessageBox信息框 
//explain:SHOWpos(sx,sy),MSG:msg,showing mod,BoardStyle[See MessageboxLeftBoard MessageboxTopBoard]
{
	int cnt=0,xl=0,tpo=2,CMessageXHeight=0,CMessageXLine=0;//cnt:当前处理到第cnt个字符； 
	string tmp="";
	string l=MessageboxLeftBoard[bdstyle],t=MessageboxTopBoard[bdstyle];//边框字符 
	int maxc=(CConsoleRight-CConsoleLeft)/CFontSizeX-2-sx,chc=1,cmp=0;//maxc：该框最大的宽度（窗口内） 
	if(maxc<0)return;
	WORD TMPCL=cl;
	TMPCL&=~FOREGROUND_INTENSITY;//为了产生强调效果，先把本身有的INTENSITY去掉 
	SetConsoleTextAttribute(COutputHandle,TMPCL|FOREGROUND_INTENSITY);
	msg+=" ";//为了掩盖闪电字幕的一点点bug 
	/* It's a pity that I delete the mode because of the function improvment.
	for(int i=0;i<msg.size();i++)
	{
		if(msg[i]==ChineseSymbol){cmp=1;msg.erase(i,1);}else cmp=0;
		if(msg[i]!=EndlSympol)cnt++;
		else {cnt=0;continue;}
		if((ChineseCheck(msg[i],msg[i+1])||cmp)&&chc){chc=0;}
		else if(chc==0){chc=1;}
//		Use this to find Chinese which can't distinguish
//		if(chc==0)msg.insert(i,1,'1'),i++;
		if(cnt>maxc-12&&(!ChineseCheck(msg[i],msg[i+1])||chc==0)&&(msg[i+1]!='}'))
		{
			msg.insert(i,1,EndlSympol);i++;
			cnt=0;
		}
	}*/
	
	for(;cnt<msg.size();CMessageXHeight++)//预求CMessageXLine:统计本字符串最长的一行有多少个字符 CMessageXHeight:共有多少行 
	{
		while(msg[cnt]!=EndlSympol&&cnt<msg.size())//char EndlSympol='}';换行标志
		{
			cnt++;xl++;//xl:统计当前行有多少个字符 
		}
		CMessageXLine=max(CMessageXLine,xl);
		xl=0;cnt++;
	}
	
	//以下的+..数据都是经过多次测试得到，不作详细解释 
	if(l.size()>1)tpo+=3;//如果边框是全角字符，那么信息框最右坐标偏移+3，加上原本的+2就是+5 
	CMessageXLine+=tpo; //把位移加到信息框最右坐标
	if(CMessageXLine%2==0)CMessageXLine+=1;//为了防止l是全角字符时边角突出来半个字符，CMessageXLine要是奇数 
	::CMessageXHeight=CMessageXHeight+5;::CMessageXLine=CMessageXLine+5;//备份到全局变量，方便后期请出信息框
	cnt=xl=0;
	
	for(int i=1;i<=CMessageXHeight;i++)
	{
		gotoxy(sy+i,sx);//到达行的第一个字符 
		cout<<l;//★输出左边框 
		if(md!=2)//★输出信息框内容 mode2:闪电字幕，信息框内容是最后输出的
		{
			while(cnt<msg.size()&&msg[cnt]!=EndlSympol)//输出该行 
			{
				tmp+=msg[cnt];
				cnt++;xl++;
			}
			cout<<tmp;
			tmp="";
		}
		for(int j=1;j<=CMessageXLine-xl-max(tpo-4,0);j++)tmp+=" ";//补全空格
		cout<<tmp<<l;//★输出右边框 
		tmp="";
		xl=0;cnt++;
	}
	
	if(md==1)//阴影效果 
	{
		SetConsoleTextAttribute(COutputHandle,TMPCL);
		for(int i=1;i<=CMessageXHeight+max(tpo-3,1);i++)//左侧阴影 
		{
			gotoxy(sy+i,CMessageXLine+sx+max(tpo-4,0)+2);
			cout<<l;
		}
		SetConsoleTextAttribute(COutputHandle,TMPCL|FOREGROUND_INTENSITY);
	}
	if(t.size()>1)CMessageXLine=CMessageXLine/2;//★输出顶底部边框 ,如果 t是全角字符，那么要少一半 
	for(int i=1;i<=CMessageXLine+2&&i+sx+1<CConsoleRight-30;i++)tmp+=t;
	gotoxy(sy,sx);cout<<tmp;
	gotoxy(sy+CMessageXHeight+1,sx);cout<<tmp;//tmp在mode1可能还要用，先不清空 
	if(md==1)//输出底部阴影 
	{
		SetConsoleTextAttribute(COutputHandle,TMPCL);
		gotoxy(sy+CMessageXHeight+2,sx);
		tmp+=t;
		cout<<tmp;
		SetConsoleTextAttribute(COutputHandle,TMPCL|FOREGROUND_INTENSITY);
	}
	if(md==2)
	{
		eout(msg,sx+1,sy+1);
	}
	return;
}
void CLockWindow(int wd)
{
	CMovable_sys[wd]=!CMovable_sys[wd];
	return;
}
void* CRunWindow(void* cwcn)//menu choosing system菜单选择系统* 
//cwcn来自主线程的传递 
{
	CWCN* TempCWCN=(CWCN*)cwcn;
	int dl=TempCWCN->dl,ls=TempCWCN->ls,ThreadNum=CLatestNum;//CCurrentWD焦点窗口，dl刷新频率，ls是否持续运行  
	//ThreadNum进程标识，若与CLatestNum不符则退出线程，同时设CEnabled为0 
	CCurrentWD=TempCWCN->wd;
	//为了提高运行效率，请设置dl在25到100之间 
	//解释：FV=0隐藏全部光标；=1隐藏未点击光标；=2全部显示
	//CButton=0不使用按钮特效；=1 开启单字符加亮；=2开启按钮加亮 
	if(Trans==0)
	{
		lr();
		CSpeedRefresh(1,CCurrentWD);
	}
	else CAllRefresh();

 	POINT pt;
	int t=0,cpst=0,cmdl=0,tCCurrentY,tCCurrentX,bs=CCurrentWD;
	bool TKmoved=0;//是否改变鼠标操作 
	CCurrentY=CCurrentX=1;

	while(CLatestNum==ThreadNum)
	{
		//待机part 
		do
		{
			Sleep(dl);
			GetCursorPos(&pt);
			AutoAlign();
			CSpeedRefresh(0);
			if (pt.y<CConsoleTop||pt.y>CConsoleBottom-(CFontSizeY<<2)||pt.x<CConsoleLeft||pt.x>CConsoleRight-(CFontSizeX<<2))
			CPause=1;//暂停
			else CPause=0;
		}
		while(CPause);
		
		pt.x-=CConsoleLeft;
		pt.y-=CConsoleTop;
//		gotoxy(23,0);
//		cout<<pt.x/CFontSizeX<<" "<<pt.y/CFontSizeY<<endl<<CCurrentY<<" "<<CCurrentX<<"   ";
		cmdl=CMessageXHeight=CMessageXLine=0;
		while((pt.x)/CFontSizeX==CCurrentY
		&&(pt.y)/CFontSizeY==CCurrentX
		&&!KEY_DOWN(MOUSE_MOVED))//鼠标按下时不允许出现注释 
		{
			if((CTopCurrentWindow==0 || CTopCurrentWindow==CCurrentWD) && CComment_sys[CCurrentWD][CCurrentX][CCurrentY]!=""//存在注释 
			&&cmdl==CCommentDelay_sys[CCurrentWD][CCurrentX][CCurrentY]/dl)//到达注释时间 
			{
				Sleep(CCommentDelay_sys[CCurrentWD][CCurrentX][CCurrentY]%dl);//等够cmdl中的ms数 
				cpst=CCommentDelay_sys[CCurrentWD][CCurrentX][CCurrentY]%dl;//后面补回 
				SetConsoleTextAttribute(COutputHandle,CColor_sys[CCurrentWD][CCurrentX][CCurrentY]);
				msgbox(CCurrentWD,CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY],CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY],ColoredColor,CComment_sys[CCurrentWD][CCurrentX][CCurrentY],CCommentMode_sys[CCurrentWD][CCurrentX][CCurrentY],CCommentBoard_sys[CCurrentWD][CCurrentX][CCurrentY]);
			}
			GetCursorPos(&pt);
			pt.x-=CConsoleLeft;
			pt.y-=CConsoleTop;
			Sleep(dl-cpst);cpst=0;//cpst因为注释导致的延时 
			CSpeedRefresh(0);
			cmdl++;
		}
		if(cmdl*dl>=CCommentDelay_sys[CCurrentWD][CCurrentX][CCurrentY]//确认触发了comment 
		&&CComment_sys[CCurrentWD][CCurrentX][CCurrentY]!="")
		CAreaRefresh(CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY],CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY],CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXHeight,CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXLine);//清除注释
		cmdl=CMessageXHeight=CMessageXLine=0;
		
		//填坑part
		if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1)//实在没办法，中文真的不好改 
		{
//			SetConsoleTextAttribute(COutputHandle,(WORD)CColor_sys[CCurrentWD][CCurrentX][CCurrentY-1]);
//			gotoxy(CCurrentX,CCurrentY-1);
//			cout<<CChar_sys[CCurrentWD][CCurrentX][CCurrentY-1];
			CIfRefresh_sys[CCurrentWD][CCurrentX][CCurrentY-1]=1;
		}
		CIfRefresh_sys[CCurrentWD][CCurrentX][CCurrentY]=1;
		
		//partB
		if (CButton==1)
		{
			if (ColoredColor)
			{//偷了一个小懒，本来Button=1的时候不用左右染色，为了还原Color2，姑且这么写着吧 
				while(ColoredPositionY>0
				&&(CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==ColoredValue||
				CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==-1)//保证连续性 
				&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==CTempColor)//保证颜色连续性 
					ColoredPositionY--;//向左找到最左端 
				while((CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==ColoredValue||
				CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==-1)
				&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==CTempColor)
				{
					CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=ColoredColor;//还原 
					CIfRefresh_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=1;
					ColoredPositionY++;//向右染色
				}
				ColoredColor=0;//用ColoredColor判断是否需要还原 
			}
			//输出sec
			CCurrentY=(pt.x)/CFontSizeX;//储存当前位置坐标，为了和下一刻对比 
			CCurrentX=(pt.y)/CFontSizeY;
			bs=0;
			if(Trans)//bs当前焦点窗口，CCurrentWD默认焦点窗口 
			{
				for(int i=0;i<CWindowOrder.size();i++)
				if(CCurrentY>=CWindowLeft_sys[CWindowOrder[i]-'0']&&CCurrentY<=CWindowRight_sys[CWindowOrder[i]-'0']
				&&CCurrentX>=CWindowTop_sys[CWindowOrder[i]-'0']&&CCurrentX<=CWindowBottom_sys[CWindowOrder[i]-'0'])
				{
					bs=CWindowOrder[i]-'0';
					break;
				}
			}
			else
			{
				if(CCurrentY>=CWindowLeft_sys[CWindowOrder[0]-'0']&&CCurrentY<=CWindowRight_sys[CWindowOrder[0]-'0']
				&&CCurrentX>=CWindowTop_sys[CWindowOrder[0]-'0']&&CCurrentX<=CWindowBottom_sys[CWindowOrder[0]-'0'])
				{
					bs=CWindowOrder[0]-'0';
				}
				else bs=0;
			}
			CSpeedRefresh(0);//本身刷新颜色就需要refresh，而如果锁定窗口也需要，故放在此处 
			//如果锁定了窗口 sec
			if (CTopCurrentWindow && bs!=CTopCurrentWindow)
			{
				CCurrentWD=bs;
				continue;
			}
			//如果切换了窗口 sec
			if (bs!=CCurrentWD)
			{
				CCurrentWD=bs;
				if (bs)
				{
					CShowWindow(CCurrentWD);
					CSpeedRefresh(1,CCurrentWD);
				}
			}
			//鼠标停留 sec
			ColoredPositionX=CCurrentX,ColoredPositionY=CCurrentY;//位置的tmp
			if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1)ColoredValue=CValue_sys[CCurrentWD][CCurrentX][CCurrentY-1];
			else ColoredValue=CValue_sys[CCurrentWD][CCurrentX][CCurrentY];//变色的是哪个按钮
			ColoredColor=//原来是啥色 
			CTempColor=CColor_sys[CCurrentWD][CCurrentX][CCurrentY];//变啥色
			if ((ColoredColor&(0x10|0x20|0x40|0x80))==0)//如果没有背景
			{
				CTempColor|=0x1|0x2|0x4|0x8|0x10|0x20|0x40;//深白色字体+暗白色背景 
			}
			else CTempColor|=0x8| 0x80;
			if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1)
			{
				CColor_sys[CCurrentWD][CCurrentX][CCurrentY-1]=CTempColor;
				CIfRefresh_sys[CCurrentWD][CCurrentX][CCurrentY-1]=1;
			}
			CColor_sys[CCurrentWD][CCurrentX][CCurrentY]=CTempColor;
			CIfRefresh_sys[CCurrentWD][CCurrentX][CCurrentY]=1;
		}
		else //partA
		if (CButton==2)
		{
			//还原color sec
			CSpeedRefresh(0);//防止闪现，必须先刷新 
			if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]>0 || CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1 && CValue_sys[CCurrentWD][CCurrentX][CCurrentY-1]>0)
			//Button=2时对于=0根本不睬，因此特别小心判断条件(一定有三部分) 
			//本身有值 或者前板块有值 
			if (ColoredColor)
			{
				while(ColoredPositionY>0
				&&(CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==ColoredValue||
				CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==-1)//保证连续性 
				&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==CTempColor)//保证颜色连续性 
					ColoredPositionY--;//向左找到最左端 
				while((CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==ColoredValue||
				CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==-1)
				&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==CTempColor)
				{
					CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=ColoredColor;//还原 
					CIfRefresh_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=1;
					ColoredPositionY++;//向右染色
				}
				ColoredColor=0;//用ColoredColor判断是否需要还原 
			}
			//以下三个sec ABpart是一样的 
			//输出sec
			CCurrentY=(pt.x)/CFontSizeX;//储存当前位置坐标，为了和下一刻对比 
			CCurrentX=(pt.y)/CFontSizeY;
			bs=0;
			if(Trans)//bs当前焦点窗口，CCurrentWD默认焦点窗口 
			{
				for(int i=0;i<CWindowOrder.size();i++)
				if(CCurrentY>=CWindowLeft_sys[CWindowOrder[i]-'0']&&CCurrentY<=CWindowRight_sys[CWindowOrder[i]-'0']
				&&CCurrentX>=CWindowTop_sys[CWindowOrder[i]-'0']&&CCurrentX<=CWindowBottom_sys[CWindowOrder[i]-'0'])
				{
					bs=CWindowOrder[i]-'0';
					break;
				}
			}
			else
			{
				if(CCurrentY>=CWindowLeft_sys[CWindowOrder[0]-'0']&&CCurrentY<=CWindowRight_sys[CWindowOrder[0]-'0']
				&&CCurrentX>=CWindowTop_sys[CWindowOrder[0]-'0']&&CCurrentX<=CWindowBottom_sys[CWindowOrder[0]-'0'])
				{
					bs=CWindowOrder[0]-'0';
				}
				else bs=0;
			}
			//如果锁定了窗口 sec
			if (CTopCurrentWindow && bs!=CTopCurrentWindow)
			{
				CCurrentWD=bs;
				CSpeedRefresh(0);
				continue;
			}
			//如果切换了窗口 sec
			if (bs!=CCurrentWD)
			{
				CCurrentWD=bs;
				if (bs)
				{
					CShowWindow(CCurrentWD);
					CSpeedRefresh(1,CCurrentWD);
				}
			}
			//鼠标停留sec
			ColoredColor=CColor_sys[CCurrentWD][CCurrentX][CCurrentY];//给注释留一条活路 
			if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]>0 || CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1 && CValue_sys[CCurrentWD][CCurrentX][CCurrentY-1]>0)
			{
				ColoredPositionX=CCurrentX,ColoredPositionY=CCurrentY;//位置的tmp
				if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1)ColoredValue=CValue_sys[CCurrentWD][CCurrentX][CCurrentY-1];
				else ColoredValue=CValue_sys[CCurrentWD][CCurrentX][CCurrentY];//变色的是哪个按钮
				ColoredColor=//原来是啥色 
				CTempColor=CColor_sys[CCurrentWD][CCurrentX][CCurrentY];//变啥色
				if ((ColoredColor&(0x10|0x20|0x40|0x80))==0)//如果没有背景
				{
					CTempColor|=0x1|0x2|0x4|0x8|0x10|0x20|0x40;//深白色字体+暗白色背景 
				}
				else CTempColor|=0x8| 0x80;//深色字体+深色背景 
				while(ColoredPositionY>0
				&&(CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==ColoredValue||
				CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==-1)
				&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==ColoredColor)
					ColoredPositionY--;//向左找到最左端 
				while((CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==ColoredValue||
				CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==-1)
				&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==ColoredColor)
				{
					CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=CTempColor;
					CIfRefresh_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=1;
					ColoredPositionY++;//向右染色
				}
			}
		}
		else if (CButton==0)
		{
			if (ColoredColor)
			{//偷了一个小懒，本来Button=0的时候根本不用染色，为了还原Color2，姑且这么写着吧 
				while(ColoredPositionY>0
				&&(CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==ColoredValue||
				CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==-1)//保证连续性 
				&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==CTempColor)//保证颜色连续性 
					ColoredPositionY--;//向左找到最左端 
				while((CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==ColoredValue||
				CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==-1)
				&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==CTempColor)
				{
					CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=ColoredColor;//还原 
					CIfRefresh_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=1;
					ColoredPositionY++;//向右染色
				}
				ColoredColor=0;//用ColoredColor判断是否需要还原 
			}
			//以下三个sec ABpart是一样的 
			//输出sec
			CCurrentY=(pt.x)/CFontSizeX;//储存当前位置坐标，为了和下一刻对比 
			CCurrentX=(pt.y)/CFontSizeY;
			bs=0;
			if(Trans)//bs当前焦点窗口，CCurrentWD默认焦点窗口 
			{
				for(int i=0;i<CWindowOrder.size();i++)
				if(CCurrentY>=CWindowLeft_sys[CWindowOrder[i]-'0']&&CCurrentY<=CWindowRight_sys[CWindowOrder[i]-'0']
				&&CCurrentX>=CWindowTop_sys[CWindowOrder[i]-'0']&&CCurrentX<=CWindowBottom_sys[CWindowOrder[i]-'0'])
				{
					bs=CWindowOrder[i]-'0';
					break;
				}
			}
			else
			{
				if(CCurrentY>=CWindowLeft_sys[CWindowOrder[0]-'0']&&CCurrentY<=CWindowRight_sys[CWindowOrder[0]-'0']
				&&CCurrentX>=CWindowTop_sys[CWindowOrder[0]-'0']&&CCurrentX<=CWindowBottom_sys[CWindowOrder[0]-'0'])
				{
					bs=CWindowOrder[0]-'0';
				}
				else bs=0;
			}
			//如果锁定了窗口 sec
			if (CTopCurrentWindow && bs!=CTopCurrentWindow)
			{
				CCurrentWD=bs;
				CSpeedRefresh(0);
				continue;
			}
			//如果切换了窗口 sec
			if (bs!=CCurrentWD)
			{
				CCurrentWD=bs;
				if (bs)
				{
					CShowWindow(CCurrentWD);
					CSpeedRefresh(1,CCurrentWD);
				}
			}
			ColoredColor=CColor_sys[CCurrentWD][CCurrentX][CCurrentY];//给注释留一条活路 
		}
		
		if(KEY_DOWN(MOUSE_MOVED) && CClickable)//CClickable=0时为预览模式 
		{
			if (CButton==2 && (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]>0 || CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1 && CValue_sys[CCurrentWD][CCurrentX][CCurrentY-1]>0))//改颜色when 点击 
			{
				t=CTempColor;
				CTempColor=ColoredColor;
				if ((ColoredColor&(0x10|0x20|0x40|0x80))==0)//没有背景 
				{
					CTempColor|=0x80;//去除深色字体+深黑色背景 
					CTempColor&=~(0x8);
				}
				else CTempColor&=~(0x80|0x8);//去除深色背景字体 
				
				while(ColoredPositionY>0
				&&(CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==ColoredValue||
				CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==-1)
				&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==t)
					ColoredPositionY--;//向左找到最左端 
				while((CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==ColoredValue||
				CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==-1)
				&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==t)
				{
					CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=CTempColor;
					CIfRefresh_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=1;
					ColoredPositionY++;//向右染色
				}
			}
			else if (CButton==1)
			{
				t=CTempColor;
				CTempColor=ColoredColor;
				if ((ColoredColor&(0x10|0x20|0x40|0x80))==0)//没有背景 
				{
					CTempColor|=0x80;//去除深色字体+深黑色背景 
					CTempColor&=~(0x8);
				}
				else CTempColor&=~(0x80|0x8);//去除深色背景字体 
				
				if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1)
				{
					CColor_sys[CCurrentWD][CCurrentX][CCurrentY-1]=CTempColor;
					CIfRefresh_sys[CCurrentWD][CCurrentX][CCurrentY-1]=1;
				}
				CColor_sys[CCurrentWD][CCurrentX][CCurrentY]=CTempColor;
				CIfRefresh_sys[CCurrentWD][CCurrentX][CCurrentY]=1;
			}
			
			//输出光标 (鼠标点击)
			t=0;//t=0代表鼠标没有点击有效值 
			if (FV)//>0
			{
				if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1)//实在没办法，中文真的不好改 
				{
					SetConsoleTextAttribute(COutputHandle,(WORD)CColor_sys[CCurrentWD][CCurrentX][CCurrentY-1]);
					gotoxy(CCurrentX,CCurrentY-1);
					{
						if(CChar_sys[CCurrentWD][CCurrentX][CCurrentY-1].size()>1)
						cout<<Ch1;
						else cout<<En1;
					}
				}
				else
				{
					SetConsoleTextAttribute(COutputHandle,(WORD)CColor_sys[CCurrentWD][CCurrentX][CCurrentY]);
					gotoxy(CCurrentX,CCurrentY);
					{
						if(CChar_sys[CCurrentWD][CCurrentX][CCurrentY].size()>1)
						cout<<Ch1;
						else cout<<En1;
					}
				}
			}
			if((CValue_sys[CCurrentWD][CCurrentX][CCurrentY]>0//点击了、选择了按钮 
			||CValue_sys[CCurrentWD][CCurrentX][CCurrentY-1]>0)//全角字符的后半块 
			&& CValue_sys[CCurrentWD][CCurrentX][CCurrentY-1]!=32767)//非拖动操作 
			{
				CSpeedRefresh(0);
				while(KEY_DOWN(MOUSE_MOVED))Sleep(dl);//等待鼠标弹起 
				if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1)//全角字符的后半块 
				{
					gotoxy(CCurrentX,CCurrentY-1);//输出回那个字符 
					SetConsoleTextAttribute(COutputHandle,CColor_sys[CCurrentWD][CCurrentX][CCurrentY-1]);
					cout<<CChar_sys[CCurrentWD][CCurrentX][CCurrentY-1];
				}
				else
				{
					gotoxy(CCurrentX,CCurrentY);//输出回那个字符 
					SetConsoleTextAttribute(COutputHandle,CColor_sys[CCurrentWD][CCurrentX][CCurrentY]);
					cout<<CChar_sys[CCurrentWD][CCurrentX][CCurrentY];
				}
				
				t=0;
				GetCursorPos(&pt);//这个地方为了探测点击以后有无移开鼠标（取消操作） 
				pt.x-=CConsoleLeft;
				pt.y-=CConsoleTop;
				if(CValue_sys[CCurrentWD][(pt.y)/CFontSizeY][(pt.x)/CFontSizeX]==-1)pt.x-=CFontSizeX;//如果这是全角字符的后半块，那么转移 
				if(CValue_sys[CCurrentWD][(pt.y)/CFontSizeY][(pt.x)/CFontSizeX]<=0)t=1;//鼠标移开了 
				if (!t)
				{
					CChoseValue[++CChoseValue[0]]=CValue_sys[CCurrentWD][(pt.y)/CFontSizeY][(pt.x)/CFontSizeX];//将值储存到CChoseValue中 
					if(!ls){OptionsDeep();CEnabled=0;lr();return NULL;}//ls是否持续返回值 
				}
			}
			
			if((CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==32767 || CValue_sys[CCurrentWD][CCurrentX][CCurrentY-1]==32767 )
			&&CMovable_sys[CCurrentWD]==0)//移动窗口(点击了边框)，CMovable_sys可否移动 
			{
				if (ColoredColor)
				{//继续偷了一个小懒
					while(ColoredPositionY>0
					&&(CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==ColoredValue||
					CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==-1)//保证连续性 
					&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==CTempColor)//保证颜色连续性 
						ColoredPositionY--;//向左找到最左端 
					while((CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==ColoredValue||
					CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==-1)
					&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==CTempColor)
					{
						CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=ColoredColor;//还原 
						CIfRefresh_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=1;
						ColoredPositionY++;//向右染色
					}
					ColoredColor=0;//用ColoredColor判断是否需要还原 
				}
				tCCurrentX=tCCurrentY=0;
				while(KEY_DOWN(MOUSE_MOVED))//跟踪想要移去的地方 
				{
					GetCursorPos(&pt);
					if (pt.y<CConsoleTop||pt.y>CConsoleBottom-CConsoleBoard-CConsoleTopBoard-(CFontSizeY<<2)//超出边框 
					||pt.x<CConsoleLeft||pt.x>CConsoleRight-(CConsoleBoard<<1)-(CFontSizeX<<2))
					break;
					pt.x-=CConsoleLeft;
					pt.y-=CConsoleTop;
					tCCurrentY=max(pt.x/CFontSizeX,(long)0);
					tCCurrentX=max(pt.y/CFontSizeY,(long)0);
					gotoxy(tCCurrentX,tCCurrentY);
					cout<<Sp1;
					Sleep(dl);
				}
				for(int i=CWindowTop_sys[CCurrentWD];i<=CWindowBottom_sys[CCurrentWD];i++)
				for(int j=CWindowLeft_sys[CCurrentWD];j<=CWindowRight_sys[CCurrentWD];j++)//搬家 
				{
					tCChar_sys[i][j]=CChar_sys[CCurrentWD][i][j];
					tCValue_sys[i][j]=CValue_sys[CCurrentWD][i][j];
					tCComment_sys[i][j]=CComment_sys[CCurrentWD][i][j];
					tCCommentTop_sys[i][j]=CCommentTop_sys[CCurrentWD][i][j];
					tCCommentLeft_sys[i][j]=CCommentLeft_sys[CCurrentWD][i][j];
					tCCommentDelay_sys[i][j]=CCommentDelay_sys[CCurrentWD][i][j];
					tCCommentMode_sys[i][j]=CCommentMode_sys[CCurrentWD][i][j];
					tCCommentBoard_sys[i][j]=CCommentBoard_sys[CCurrentWD][i][j];
					tCColor_sys[i][j]=CColor_sys[CCurrentWD][i][j];
				}
				int tmpy=tCCurrentY-CCurrentY,tmpx=tCCurrentX-CCurrentX;
				if(CWindowLeft_sys[CCurrentWD]< -tmpy)tmpy= 0-CWindowLeft_sys[CCurrentWD];//超出左边框 
				if(CWindowTop_sys[CCurrentWD]< -tmpx)tmpx= 0-CWindowTop_sys[CCurrentWD];//超出上边框 
				if(CWindowRight_sys[CCurrentWD]+tmpy>(CConsoleRight-CConsoleLeft-(CConsoleBoard<<1))/CFontSizeX-2)//超出右边框 
				tmpy=(CConsoleRight-CConsoleLeft-(CConsoleBoard<<1))/CFontSizeX-2-CWindowRight_sys[CCurrentWD];
				if(CWindowBottom_sys[CCurrentWD]+tmpx>(CConsoleBottom-CConsoleTop-CConsoleTopBoard-CConsoleBoard)/CFontSizeY)//超出下边框 
				tmpx=(CConsoleBottom-CConsoleTop-CConsoleTopBoard-CConsoleBoard)/CFontSizeY-CWindowBottom_sys[CCurrentWD];
				 
				CDeleteWindow(CCurrentWD);//Delete包括hide 
				CWindowLeft_sys[CCurrentWD]=max(0,CWindowLeft_sys[CCurrentWD]+tmpy);
				CWindowTop_sys[CCurrentWD]=max(0,CWindowTop_sys[CCurrentWD]+tmpx);
				CWindowRight_sys[CCurrentWD]=max(0,CWindowRight_sys[CCurrentWD]+tmpy);
				CWindowBottom_sys[CCurrentWD]=max(0,CWindowBottom_sys[CCurrentWD]+tmpx);
				for(int i=CWindowTop_sys[CCurrentWD];i<=CWindowBottom_sys[CCurrentWD];i++)
				for(int j=CWindowLeft_sys[CCurrentWD];j<=CWindowRight_sys[CCurrentWD];j++)
				{
					CChar_sys[CCurrentWD][i][j]=tCChar_sys[i-tmpx][j-tmpy];
					CValue_sys[CCurrentWD][i][j]=tCValue_sys[i-tmpx][j-tmpy];
					CComment_sys[CCurrentWD][i][j]=tCComment_sys[i-tmpx][j-tmpy];
					CCommentTop_sys[CCurrentWD][i][j]=tCCommentTop_sys[i-tmpx][j-tmpy]+tmpy;
					CCommentLeft_sys[CCurrentWD][i][j]=tCCommentLeft_sys[i-tmpx][j-tmpy]+tmpx;
					CCommentDelay_sys[CCurrentWD][i][j]=tCCommentDelay_sys[i-tmpx][j-tmpy];
					CCommentMode_sys[CCurrentWD][i][j]=tCCommentMode_sys[i-tmpx][j-tmpy];
					CCommentBoard_sys[CCurrentWD][i][j]=tCCommentBoard_sys[i-tmpx][j-tmpy];
					CColor_sys[CCurrentWD][i][j]=tCColor_sys[i-tmpx][j-tmpy];
				}
				CShowWindow(CCurrentWD);
				CTasks_sys[0]-=2;//前面两个都是要统一refresh的，不如后面一次搞定 
				CTasks_sys[++CTasks_sys[0]]=0;//清屏 
				CSpeedRefresh(0);
			}
			/*if(CValue_sys[bs][(pt.y)/CFontSizeY][(pt.x)/CFontSizeX]==-3)
			{
				if(CWindowOrder.size()==1)continue;
				for(int i=0;i<CWindowOrder.size();i++)
				if(CWindowOrder[i]-'0'==bs){CWindowOrder.erase(i,1);break;}//cout<<CWindowOrder;char cc=getch();
				OptionsDeep();lr();
				for(int i=0;i<CWindowOrder.size();i++)spclr(CWindowOrder[i]-'0');
				bs=CCurrentWD=CWindowOrder[0];
			}
			if(CValue_sys[bs][(pt.y)/CFontSizeY][(pt.x)/CFontSizeX]==-4)
			{
				if(CWindowOrder.size()!=1)
				{
					wcrr(bs);
					for(int i=0;i<CWindowOrder.size();i++)spclr(CWindowOrder[i]-'0');
				}
				else
				{
//					cw(WDD-1,1,"CONFIRM",0,0,16,8,1,1,"Exit the process?",0,"If you click Yes,you will leave this page",-1,-1,0,0,1,0x8);
//					cw(WDD-1,-1,"CONFIRM",0,0,16,8,1,1,"YES",1,"",-1,-1,0,0,1,0x4|0x8);
//					cw(WDD-1,-1,"CONFIRM",0,0,16,8,1,1,"NO",2,"",-1,-1,0,0,1,0x8);
//					if(chw(50,WDD-1,0)==1)
//					{
//						wcrr(WDD-1);
//						wcrr(bs);
//						return 0;
//					}
//					else wcrr(WDD-1);
				}
				
			}*/
			
			//还原color 
			if (CButton==2)
			if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]>0 || CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1 && CValue_sys[CCurrentWD][CCurrentX][CCurrentY-1]>0)
			{
				while(ColoredPositionY>0
				&&(CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==ColoredValue||
				CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==-1)
				&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==CTempColor)
					ColoredPositionY--;//向左找到最左端 
				while((CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==ColoredValue||
				CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==-1)
				&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==CTempColor)
				{
					CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=ColoredColor;//还原 
					CIfRefresh_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=1;
					ColoredPositionY++;//向右染色
				}
			}
			else if (CButton==1)
			{
				if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1)
				{
					CColor_sys[CCurrentWD][CCurrentX][CCurrentY-1]=ColoredColor;
					CIfRefresh_sys[CCurrentWD][CCurrentX][CCurrentY-1]=1;
				}
				CColor_sys[CCurrentWD][CCurrentX][CCurrentY]=ColoredColor;
				CIfRefresh_sys[CCurrentWD][CCurrentX][CCurrentY]=1;
			}
		}
		else if (FV>1)//如果不点击时光标不可见，那么输出原字符 ,否则输出光标0 
		{
			if (CValue_sys[bs][CCurrentX][CCurrentY]==-1)
			{
				SetConsoleTextAttribute(COutputHandle,(WORD)CColor_sys[bs][CCurrentX][CCurrentY-1]);
				gotoxy(CCurrentX,CCurrentY-1);
				if(CChar_sys[bs][CCurrentX][CCurrentY-1].size()>1)
				cout<<Ch0;
				else cout<<En0;
			}
			else 
			{
				SetConsoleTextAttribute(COutputHandle,(WORD)CColor_sys[bs][CCurrentX][CCurrentY]);
				gotoxy(CCurrentX,CCurrentY);
				if(CChar_sys[bs][CCurrentX][CCurrentY].size()>1)
				cout<<Ch0;
				else cout<<En0;
			}
		}
		if(CValue_sys[bs][CCurrentX][CCurrentY]>0)CCurrentValidValue=CValue_sys[bs][CCurrentX][CCurrentY];		//最近的有效值
		if(CValue_sys[bs][CCurrentX][CCurrentY]==-1)CCurrentValidValue=CValue_sys[bs][CCurrentX][CCurrentY-1];
		CCurrentValue=CValue_sys[bs][CCurrentX][CCurrentY];	//即时值
		
		
			//DEBUG tools
//				gotoxy(23,0);//printf("#pxy(abs):(%d,%d) <%d,%d>;dxy:%d %d;Ch:%s;V:%d#   \nCo:%d",pt.x,pt.y,pt.x,pt.y,CCurrentY,CCurrentX,CChar_sys[CCurrentWD][CCurrentX][CCurrentY].c_str(),CValue_sys[CCurrentWD][CCurrentX][CCurrentY],CColor_sys[CCurrentWD][CCurrentX][CCurrentY]);
//				gotoxy(23,0);printf("#WInfo.l%d t%d r%d b%d#   \n",CConsoleLeft,CConsoleTop,CConsoleRight,CConsoleBottom);
//				Sleep(100);
				if (kbhit()&&getch()=='c')CAllRefresh();
	}
	OptionsDeep();
	CEnabled=0;
	lr();
	return NULL;
}
void COpenThread(int delay/*LEAST 50!*/,int window,int to_be_continued)//menu choosing system starter菜单选择系统启动程序_线程* 
//explain:Fps:1000/dl(ms),which menu,whether going on when get values,whether waiting
{
	CWCN* cwcn;
	TempCWCN.dl=delay;
	TempCWCN.wd=window;
	TempCWCN.ls=to_be_continued;
	cwcn=&TempCWCN;
	CEnabled=1;
	CLatestNum++;
	if (CLatestNum>10000)CLatestNum%=10000;
	
	pthread_create(&CRecentTids, NULL, CRunWindow, (void*)cwcn);
	return;
}
void COpenWindow(int delay/*LEAST 50!*/,int window,int to_be_continued)//menu choosing system starter菜单选择系统启动程序_等待* 
//explain:Fps:1000/dl(ms),which menu,whether going on when get values,whether waiting
{
	CWCN* cwcn;
	TempCWCN.dl=delay;
	TempCWCN.wd=window;
	TempCWCN.ls=to_be_continued;
	cwcn=&TempCWCN;
	CEnabled=1;
	CLatestNum++;
	if (CLatestNum>10000)CLatestNum%=10000;
	
	CRunWindow((void*)cwcn);
	return;
}
void CCloseWindow()
{
	CLatestNum++;
	while (CEnabled)Sleep(25);
	return;
}
#ifndef CLICK_RELEASE
void _example()
{
 int a,b,ans;char cc=0;
 HideCursor();
// cout<<"select player area:\n(click it!)";cost(10,10,75,45,a,b);lr();
CCreateWindow(1,0,"EXAMPLE",0,0,33,20);
CCreateWindow(3,2,"提示",35,0,55,20);
//system("mode con cols=80 lines=25");//Warn 
 CWriteWindow(1,1,1,"-------------菜单-------------",0,"看我干嘛awa}我只是一个标题...",-1,-1,1000,1,3,0x2|0x8);
 CWriteWindow(1,3,15,"开始play",1,"点此来开始游戏}等等，楼主还没放游戏呢qwq",-1,-1,0,1,0,0x4|0x1|0x8|0x80|0x20);
 CWriteWindow(1,6,15,"退出exit",2,"单击退出",-1,-1,0,0,0,wOldColorAttrs);
 CWriteWindow(1,10,5,"弹出一个新的窗口awa",3,"。。。}...}!",-1,-1,500,1,7,0x4);
 CWriteWindow(1,11,5,"锁定\\解锁窗口",4,"",0,0,0,0,0,wOldColorAttrs);
 CWriteWindow(1,7,1,"光标示例:┼╋+*╬#",15,"好看吗？}如果你不满意，可以通过程序首行的“光标形式”更改}多种多样，只有想不到没有做不到！}",8,15,600,2,21,0x2|0x10|0x8|0x80);
 CWriteWindow(3,2,36,"挪动你的鼠标~",5,"敢不敢点我一下",0,0,0,0,0,wOldColorAttrs|0x8);
 CWriteWindow(3,18,36,"关闭",6,"",0,0,0,0,0,wOldColorAttrs|0x8|0x4);
 CWriteWindow(3,17,36,"查看帮助\\版本信息",20,"",0,0,0,0,0,0x8);
 CWriteWindow(3,10,36,"光标",0,"改变控制台光标可见性",-1,-1,0,0,1,0x1|0x8);
 CWriteWindow(3,10,41,"s",30,"",0,0,0,0,0,0x1|0x2|0x4);
 CWriteWindow(3,10,43,"h",31,"",0,0,0,0,0,0x1|0x2|0x4);
 CWriteWindow(3,11,36,"准星",0,"改变CLICKING系统光标可见性",-1,-1,0,0,1,0x1|0x8);
 CWriteWindow(3,11,41,"0",32,"",0,0,0,0,0,0x1|0x2|0x4);
 CWriteWindow(3,11,43,"1",33,"",0,0,0,0,0,0x1|0x2|0x4);
 CWriteWindow(3,11,45,"2",34,"",0,0,0,0,0,0x1|0x2|0x4);
 CWriteWindow(3,12,36,"透视",0,"非焦点窗口可见性",-1,-1,0,0,1,0x1|0x8);
 CWriteWindow(3,12,41,"0",35,"",0,0,0,0,0,0x1|0x2|0x4);
 CWriteWindow(3,12,43,"1",36,"",0,0,0,0,0,0x1|0x2|0x4);
 CWriteWindow(3,13,36,"按钮",0,"改变按钮特效",-1,-1,0,0,1,0x1|0x8);
 CWriteWindow(3,13,41,"0",37,"",0,0,0,0,0,0x1|0x2|0x4);
 CWriteWindow(3,13,43,"1",38,"",0,0,0,0,0,0x1|0x2|0x4);
 CWriteWindow(3,13,45,"2",39,"",0,0,0,0,0,0x1|0x2|0x4);
 if (WinVer || Options[4][1])CWriteWindow(3,15,36,"使用Windows7运行}获得更好效果~",40,"使用Win10进行预览将可能出现闪电字幕无法显示}中文字符出现乱码,字体缺陷等问题，其实他们不是bug}改用Windows7将解决这些问题",5,5,100,0,0,0x1|0x2|0x8|0x80);
 
//此处不能用/*CTasks_sys[++CTasks_sys[0]]=3;*/，而应该用CShowWindow()，为了插入窗口顺序 
 CLockWindow(3);
 CShowWindow(3);
 CShowWindow(1);
 COpenThread(20,1,1);//COpenThread之前的这些函数都是可以自由调用的，不受CEnabled限制 
 while(ans!=2&&CEnabled)
 {
 	while(!CChoseValue[0])
	 {
	 	Sleep(100);
	 	if (CPause)
	 	{
	 		Sleep(200);
	 		SetConsoleTitle("程序错误(Main)ErrorCode:0536[Terminate][Ignore][Report]");
	 		while (CPause)Sleep(50);
	 		SetConsoleTitle("你真这么相信我？你人(bei)真(pian)好(le)");
	 		Sleep(1000);
	 		SetConsoleTitle(CTitle);
		}
	 	if(CCurrentValidValue==1)
	 	{
	 		CWriteWindow(3,5,36,"这是样例程序，}所以没有游戏}可以自己写鸭！",0,"",0,0,0,0,0,0x2|0x8);
	 		while((CCurrentValue==-1||CCurrentValue==1)&&!CChoseValue[0])Sleep(50);CCurrentValidValue=0;//ValidValue一定要记得清空，否则有可能重复执行 
	 		CWriteWindow(3,5,36,"              }            }              ",0,"",0,0,0,0,0,wOldColorAttrs);
		 }
		if(CCurrentValidValue==6)
	 	{
	 		CWriteWindow(3,5,36,"且慢，请三思}关掉的话}没有提示了哦...",0,"",0,0,0,0,0,0x4|0x8);
	 		while((CCurrentValue==-1||CCurrentValue==6)&&!CChoseValue[0])Sleep(50);CCurrentValidValue=0;
	 		CWriteWindow(3,5,36,"            }        }               ",0,"",0,0,0,0,0,wOldColorAttrs);
		 }
		 if(CCurrentValidValue==4)
		 {
		 	lFreeze();
		 	while((CCurrentValue==-1||CCurrentValue==4)&&!CChoseValue[0])Sleep(50);CCurrentValidValue=0;
		 	CCurrentValue=CCurrentValidValue=0;
		 	lInitial();
		 	Sleep(100);
		 	AutoAlign();
		 	Sleep(200);
		 	CTasks_sys[++CTasks_sys[0]]=0;
		 	HideCursor()
		 }
		 if(CCurrentValidValue==15)
		 {
		 	CWriteWindow(3,5,36,"可惜，}这只能在程序里更改",0,"没什么好看的",-1,-1,0,0,1,0x1|0x8|0x20|0x80);
	 		while((CCurrentValue==-1||CCurrentValue==15)&&!CChoseValue[0])Sleep(50);CCurrentValidValue=0;
	 		CWriteWindow(3,5,36,"      }                  ",0,"",0,0,0,0,0,wOldColorAttrs);
		 }
	 }
 	ans=CChoseValue[CChoseValue[0]];CChoseValue[0]--;
 	if(ans==3){
 		CCreateWindow(2,1,"I AM THE 弹窗(锁定)",10,7,25,15);
 		CWriteWindow(2,8,11,"关掉",9,"不要点",-1,-1,0,0,0,wOldColorAttrs);
 		CShowWindow(2);CTopCurrentWindow=2;
 		while(1)
		 {
		 	Sleep(100);
		 	if (CChoseValue[CChoseValue[0]]==9)break;
		 	CChoseValue[0]=0;
		 }
 		CTopCurrentWindow=0;
	 }
 	if(ans==9)CHideWindow(2);//CDeleteWindow(2);亦可 
	 if(ans==5) system("start notepad");
	 if(ans==6) CHideWindow(3);
	 if(ans==20)
	 {
	 	ofstream of("Note.txt");
	 	of<<Licence;
	 	of<<"\n"<<Version;
	 	of.close();
	 	system("Note.txt");
	 }
	 if (ans>=30)
	 {
	 	if (ans==30)ShowCursor()
	 	else if (ans==31)HideCursor()
	 	else if (ans<=34)FV=ans-32;
	 	else if (ans<=36)Trans=ans-35,CTasks_sys[++CTasks_sys[0]]=0;//增加一个0代表全局刷新 
	 	else if (ans<=39)CButton=ans-37;
	 }
  //mains?[with both(a,b)]
 }
CCloseWindow();
 lr();
 return ;
}
#endif
#ifndef _CLICKING_//头文件不能有main 
int main(int argc,char* argv[])
{
	cout<<"这是样例程序！\n(当前字体)"<<CurrentFontSizeX<<" "<<CurrentFontSizeY<<endl;
	cout<<"获得更多帮助请按 H \n观看实例请按 E \n";
	char cc=getch();
	if(cc=='H'||cc=='h')
	{
		ofstream of("Note.txt");
#ifndef CLICK_SIMPLE
	 	of<<Note;
#else
		of<<Note_simple;
#endif
	 	of<<"\n"<<Version;
	 	of.close();
#ifndef CLICK_SIMPLE
	 	of.open("Tutor.txt");
	 	of<<Tutor;
	 	of.close();
	 	system("start \"\" Tutor.txt");
#endif
	 	of.open("Licence.txt");
	 	of<<Licence;
	 	of.close();
	 	system("start \"\" Licence.txt");
	 	system("start \"\" Note.txt");
	}
	if(cc=='E'||cc=='e')
	{
#ifndef CLICK_RELEASE
		_example();
		for(int i=1;i<=3;i++) CDeleteWindow(i);
#else
		puts("\n[Main]WARNING:_example() not found\nDisable CLICK_RELEASE to avoid");
		Sleep(500);
#endif
	}
 return 0;
}
#endif
