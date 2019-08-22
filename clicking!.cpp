
/**----------------------------------------------------------------
Clicking_System() **完整版**
About{
Create:lz
Coded:V1.0 to latest:lz
Debug:V1.0 to latest:lz
Other license:
//The first run will be interrupted because of the initialize of "options.txt".
//Run _example() to learn to use or ask the editor.
//You can edit it as you like,and you'd better tell lz about it.
//I will be thankful if you discover any bug in it.

PS:并没有装逼，都是自己翻的awa... 

--本程序(clicking)由linze原创，需要外传请通知作者，感谢配合！
如果你需要将其作为礼物或者仅仅作为交流用途发给别人，你只需注明原作者即可。
（其实我也只是编来玩，没有谋求利益的意思，这还可以被更多人认可，为什么不呢？）
联系作者：qq:1612162886(验证信息注明你是通过程序备注找到的)；洛谷ID：43845（是OIer就来luogu啊）
}
**/


#include<iostream>
#include<cstdio>
#include<cmath>
#include<pthread.h>
#include<fstream>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
using namespace std;
#define TD() (SetConsoleTextAttribute(OPhandle,FOREGROUND_INTENSITY ))
#define TDBlue() (SetConsoleTextAttribute(OPhandle,FOREGROUND_INTENSITY |FOREGROUND_BLUE))
#define TDGreen() (SetConsoleTextAttribute(OPhandle,FOREGROUND_INTENSITY |FOREGROUND_GREEN))
#define TDRed() (SetConsoleTextAttribute(OPhandle,FOREGROUND_INTENSITY |FOREGROUND_RED))
#define TDYellow() (SetConsoleTextAttribute(OPhandle,FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_GREEN))
#define TDPink() (SetConsoleTextAttribute(OPhandle,FOREGROUND_INTENSITY |FOREGROUND_RED |FOREGROUND_BLUE))
#define TDCyan() (SetConsoleTextAttribute(OPhandle,FOREGROUND_INTENSITY |FOREGROUND_GREEN |FOREGROUND_BLUE))
#define TBlue() (SetConsoleTextAttribute(OPhandle,FOREGROUND_BLUE))
#define TGreen() (SetConsoleTextAttribute(OPhandle,FOREGROUND_GREEN))
#define TRed() (SetConsoleTextAttribute(OPhandle,FOREGROUND_RED))
#define BDBlue() (SetConsoleTextAttribute(OPhandle,BACKGROUND_INTENSITY |BACKGROUND_BLUE))
#define BDGreen() (SetConsoleTextAttribute(OPhandle,BACKGROUND_INTENSITY |BACKGROUND_GREEN))
#define BDRed() (SetConsoleTextAttribute(OPhandle,BACKGROUND_INTENSITY |BACKGROUND_RED))
#define BDYellow() (SetConsoleTextAttribute(OPhandle,BACKGROUND_INTENSITY |BACKGROUND_RED |BACKGROUND_GREEN))
#define BDPink() (SetConsoleTextAttribute(OPhandle,BACKGROUND_INTENSITY |BACKGROUND_RED |BACKGROUND_BLUE))
#define BDCyan() (SetConsoleTextAttribute(OPhandle,BACKGROUND_INTENSITY |BACKGROUND_GREEN |BACKGROUND_BLUE))
#define BBlue() (SetConsoleTextAttribute(OPhandle,BACKGROUND_BLUE))
#define BGreen() (SetConsoleTextAttribute(OPhandle,BACKGROUND_GREEN))
#define BRed() (SetConsoleTextAttribute(OPhandle,BACKGROUND_RED))
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
#define DD() (SetConsoleTextAttribute(OPhandle, wOldColorAttrs))
#define HCR() {CursorInfo.bVisible = false;SetConsoleCursorInfo(OPhandle, &CursorInfo);}
#define SCR() {CursorInfo.bVisible = true;SetConsoleCursorInfo(OPhandle, &CursorInfo);}
#define ChWp( Px, Py, Cx, Cy) (MoveWindow(hwnd,Px,Py,Cx,Cy,TRUE))
#define StWp( Px, Py) (SetWindowPos(hwnd, HWND_NOTOPMOST, Px, Py, 0, 0,SWP_NOSIZE))
#define DS() {RECT nowr;GetWindowRect(hwnd,&nowr);StWp(rect.left,rect.top+1);StWp(rect.left,rect.top);ChWp(rect.left,rect.top+50,rect.right-rect.left,rect.bottom-rect.top-50);ChWp(rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top);}
#define lInitial() {SetWindowLong(hwnd, GWL_STYLE, wOldLong);SetConsoleTitle(CTitle);DS();TOPBROAD=30;}
#define lSuspend() (SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & WS_CAPTION))
#define lFreeze() {SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_CAPTION);DS();TOPBROAD=8;}
#define chck( k1, k2) ((k1&0x80)&&(k2&0x80))

//CSYS NORMAL SYMBOL!--------------------------------
//!!!:请勿调换变量声明顺序，否则后果自负! 
//struct csysb{int k,wd;};
struct CWCN{int dl,wd,ls;}tcwcn;

const char Cnp=''/*(char)1:USE IT if you need to recognize the next two char as a chinese*/,Endnp='}';
string Msbl[]={"|","*","#","+",""," ","  ","│","┃","┆","┇","┊","┋","╳","□","■","█","▌","○","●","☆","★","?","?","?"},Msbt[]={"-","*","#","+",""," ","  ","─","━","┄","┅","┈","┉","╳","□","■","█","▄","○","●","☆","★","?","?","?"};
string Wdbdsl[]={"|","*","#","+"," ","!","?","'",".","+"},Wdbdst[]={"-","*","#","+"," ","!","?","'",".","="};
const char Ch0[]="┼",Ch1[]="╋",En0[]="+",En1[]="*",Sp0[]="╬",Sp1[]="#";//光标形式 (1个半角或全角字符)
const string OptionsForge="[DoNOTModify]Identifier:ClickingVersonsV2.6-By LZ-\n[WindowPosition](left,width,top,heigh)\n4\n-1 -1 -1 -1\n[Trans;wOldColorAttrs]\n4\n1 7 8 16\n[EOUT:EoutDelay,IDDTFP]\n2\n7 25\n[WindowVerson](<8:0;>7:1)\n1\n0\n[ProcessName](Format:*.exe)\n-1\nclicking!.exe\n"/*0 0 677 459*/,Verson="ClickingVersonsV2.6\nCreated by Lz\n",Licenses="License:\n \n ----------------------------------------------------------------\n Clicking_System()\n About{\n Create:lz\n Coded:V1.0 to latest:lz\n Debug:V1.0 to latest:lz\n Other license:\n //The first run will be interrupted because of the initialize of 'options.txt'.\n //Run _example() to learn to use or ask the editor.\n //You can edit it as you like,and you'd better tell lz about it.\n //I will be thankful if you discover any bug in it.\n \n PS:并没有装逼，都是自己翻的awa... \n \n --本程序(clicking)由linze原创，需要外传请通知作者，感谢配合！\n 如果你需要将其作为礼物或者仅仅作为交流用途发给别人，你只需注明原作者即可。\n （其实我也只是编来玩，没有谋求利益的意思，这还可以被更多人认可，为什么不呢？）\n 联系作者：qq:1612162886(验证信息注明你是通过程序备注找到的)；洛谷ID：43845（是OIer就来luogu啊）\n }\n \n **完整版**\n Help:[2019.7.19]\n 这个程序就是一个可DIY的拥有鼠标控制功能的程序，你可以通过鼠标来控制程序，告诉他你想干嘛，而不再使用键盘\n 教程稍稍冗(rǒng)长，请见谅！\n \n 接下来是教程：如果你是制作者，请看①；如果你是使用者，请看②。\n \n \n \n \n \n \n \n \n①：\n 	\n 	想要编一个属于自己的鼠标控制程序吗？？赶紧往下看吧！\n 	\n 	本程序包含三个板块：1.菜单写入器；2.菜单执行（选择）器；3.区域选择器。\n 	虽然程序里有很多别的干货，但是出于线程稳定和变量依赖考虑，不建议单独调用。\n 	\n 	☆数据公开：\n 	string Msbl[]={'|','*','#','+','',' ','  ','│','┃','┆','┇','┊','┋','╳','□','■','█','▌','○','●','☆','★','?','?','?'},Msbt[]={'-','*','#','+','',' ','  ','─','━','┄','┅','┈','┉','╳','□','■','█','▄','○','●','☆','★','?','?','?'};\n 	string Wdbdsl[]={'|','*','#','+',' ','!','?',''','.','+'},Wdbdst[]={'-','*','#','+',' ','!','?',''','.','='};\n 	const char Ch0[]='┼',Ch1[]='╋',En0[]='+',En1[]='*',Sp0[]='╬',Sp1[]='#';//光标形式 (1个半角或全角字符)\n 	\n 	//颜色参考 \n 	FOREGROUND_BLUE 0x1 蓝色字\n 	FOREGROUND_GREEN 0x2 绿色字\n 	FOREGROUND_RED 0x4 红色字\n 	FOREGROUND_INTENSITY 0x8（加亮）\n 	BACKGROUND_BLUE 0x10 蓝色背景\n 	BACKGROUND_GREEN 0x20 绿色背景\n 	BACKGROUND_RED 0x40 红色背景\n 	BACKGROUND_INTENSITY 0x80（加亮） \n 	\n 	\n 	★★★从这里开始就是如何编一个鼠标控制程序的过程了，跟着看下去包你看懂\n 	★Step1.\n 	1.void cwd(int wd,int wdbds,string wdtp,int cwl,int cwt,int cwr,int cwb)//window writing system窗口创建系统\n 	2.void cw(int wd,int x,int y,string s,int ct,string cm,int cml,int cmt,int cmdl,int cmmd,int cmbds,int cl)//menu writing system菜单写入系统*\n 	\n 	\n 	用法：cwd用于创建窗口，cw用于写入文字用于执行的菜单（也就是在屏幕上会显示的东西）\n 	☆注意要先创建才能写入\n 	解释:1:	wd：你的窗口编号（如果你只有一个窗口，你就写个1或者随便编个数）\n 	wdbds:你的窗口边框形式（可以在上面的Wdbdsl和Wdbdst选一对，他们是一一对应的，填写他们是数组中的第几个）\n 	wdtp:你的窗口标题（不用担心，程序已经帮你自动居中了，不过要注意不能超过窗口宽度）\n 	cwl:你的窗口左坐标（你的窗口显示出来时，左边框的坐标）\n 	cwt:你的窗口上坐标（全都同上）\n 	cwr:右坐标（全都同上）\n 	cwb:下坐标（全都同上）\n 	2:	wd:你的窗口编号（你创建的窗口的编号）\n 	x,y:文字的起始点坐标（是绝对坐标而不是相对窗口位置坐标）\n 	s:你的文字内容\n 	ct:文字值（就是你点击他的时候程序会返回一个什么值，如果想要他不返回（就是点它也没反应）就填0，不要填负数，因为负数是保留值）\n 	cm:它的注释，就是你的鼠标停留在上面时会弹出一个小窗口显示着（如果不要就填''，然后接下来cml,cmt,cmdl,cmmd,cmbds都可以填0）\n 	cml,cmt:注释的位置（绝对坐标），如果懒可以两个都填-1，程序会自动帮你分配\n 	cmdl:你的鼠标停留在上面过多少时间才显示注释（单位ms）\n 	cmmd:注释样式（0：默认；1:3D，2:闪电字幕（可以自己试试看））\n 	cmbds:注释边框模式（可以从Msbl和Msbt里面选一对，和窗口边框样式规则一样）\n 	cl:注释颜色（填写的时候可以填FOREGROUND_BLUE...也可以填0x1...，如果要混色的话在两个属性之间加个'|'）\n 	★Step2.\n 	1.void ent(int dl/*LEAST 50!*/,int wd,int ls,int wt)//menu choosing system starter菜单选择系统启动程序* \n 	\n 	用法：ent用于启动窗口选择主程序\n 	解释:1:dl:刷新间隔时间（就是这个程序多久反应一次（。。。），单位ms，建议不小于50ms）\n 	wd:窗口编号\n 	ls:返回值可持续性（就是你点击了一个有效选择（就是前面的ct>0）以后，如果ls=1，那么菜单会返回值后继续运行，否则他会返回值后退出）\n 	wt:是否启动线程（如果wt=1那么你要等这个菜单把值返回了，退出了，你的程序才能继续运行；如果wt=0，那么你的程序可以继续运行，而他会作为另外一个线程启动）\n 	\n 	★Step3.\n 	了解了主程序用法之后，介绍几个变量：\n 	1.Enabled(bool)		这个变量在选择程序运行时会变为true(1),退出时会变为false(0),但是，你可以在它运行时通过在你的主程序里更改Enabled为0来停止他\n 			☆☆☆为了防止乱码，程序末尾一定要记得Enabled=0；否则你会在屏幕上看到一堆字符，而且严重的会导致内存泄漏\n 	2.dqx,dqy(short int)	这两个是指当前光标所在的坐标（然而好像没什么用）\n 	3.ww(string)		这个字符串指的是窗口的排列顺序（由上到下指0~size()-1），不过因为不能引起及时刷新，所以建议只是读取而不要更改\n 	☆4.chv[](int[])	很多同学会疑问：既然是多线程，返回值我怎么获取？（我都为常规获取返回值的步骤感到恶心）不过别担心，我特地把所有返回值存进了这个数组里，既保障了分离运行，又可以可连续传值。\n 			要提取返回值时，chv[0]是总个数（如果它的值是0那么代表没有返回值）,可以用这样的语句:while(chv[0]==0)Sleep(100)或者执行你自己的语句，跳出循环后写一个xxx=chv[chv[0]--(一定要记得--)]便可以了\n 	☆5.ccv(int)		这个变量是指鼠标停留在的文字上的值（就算没有点下去也会取得到值），可以在循环中用if(ccv==...)执行\n 			设计这个变量主要有一个很有用的用途：如果它的值是某个文字的值，那么马上用cw在旁边写一句话（提示用），可以有效迅速地反馈\n 	☆6.tasks_sys[](int[])	因为多线程运行的时候如果你的程序在输出一个什么就会导致光标错位，所以想到了个办法\n 		这里要介绍几个函数：\n 		1.spclr(int wd)（用来显示窗口,wd是编号）\n 		2.wcrr(int wd)（用来删除一个窗口，然后被删除的窗口就会永久消失，除非你重新创建写入）\n 			因为有时候互动需要，可能要显示一个窗口或者删除一个窗口，所以添加了这个数组\n 			如果你要显示一个窗口:tasks_sys[++tasks_sys[0]]=窗口编号\n 			如果你要删除一个窗口:tasks_sys[++tasks_sys[0]]=窗口编号的相反数（就是加个负号）\n 	7.movable_sys[](bool[])	这个程序是可以拖动窗口的（尽管有点慢），如果你想要禁止你的窗口被移动，你可以调用lock(你的窗口编号)或者movable_sys[编号]=1;要解锁的话只需再调用一遍lock(编号)或movable_sys[编号]=0即可\n  8.fsx,fsy	这两个变量是指控制台的字体大小（宽，长；单位像素），可以在属性-字体-大小 查看。因技术有限，没有添加自动校准系统，如果要改需要在程序里改\n 	☆☆接下来的这些变量可以在options.txt修改（提示：options.txt会自动出现，无需理会）\n 	8.ial,iar,iat,iab	这四个变量是指窗口（是控制台，就是整个程序进程的窗口）的左、宽、上、高（注意顺序），如果不想调（懒+1）填四个-1即可\n 	9.Trans			(transparent 透明)，如果Trans=0，那么你将无法看到非焦点（就是在后面的）窗口。但是如果你的电脑严重卡顿，可以将其修改为0。\n 	10.wOldColorAttrs	(Window Old Color Attributes 窗口默认颜色属性)建议不要改，默认7，除非你想看到一个红色、蓝色、绿色为背景的窗口？\n 	11.EoutDelay		话说注释里面有个模式叫闪电字幕，而这个变量就是控制其输出快慢的（越大越慢），单位ms\n 	12.IDDTFP		(并不是缩写，我乱编的 停止注释偏移)当闪电字幕在输出的时候，如果你不想看了怎么办？是不是挪开鼠标？对的，你只需要挪开IDDTFP像素就可以停止了（所以你知道这是干嘛的了吧）\n 	13.WindowVerson		Win10用户注意了！\n 			话说从Win10开始，微软肥肠的贴心，为中国客户的Win10电脑里面的（退格符）一次退两格（为了防止把中文字切成两半）。\n 			但是这就把我的程序搞傻了，闪电字幕全都没掉，至今没找到两全之策。所以只能再加一个参数。如果你是Win10用户请把它改成1\n 	★附.\n 	前面介绍了有个函数叫区域选择器。不过因为这个函数我从V2左右就已经完成了，后来都没改过，本来不打算介绍。不过既然有点用处，也介绍一下。\n 	void cost(int left,int top,int right,int down,int &px,int &py)//area selecting区域选择* \n 	\n 	用法：屏幕会变黑，你需要在上面点上一下，就会显示十字准星，接着程序会返回你选择的坐标。可以用于区域选择\n 	解释：	left,top;right,down:选择的区域（如果超过这两个点那么他就不会显示十字准星）\n 	px，py：这两个变量是用于传回的，不需要有传入值，否则会被覆盖\n 	--由LZ编写 \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n②：\n 	要使用一个鼠标控制程序很简单，几乎不需要用到键盘（如果你是编写者也建议你看一下） \n 	首先，你要根据程序提示，等到你看到你的鼠标下有一个'+'时代表你可以用鼠标了（如果编写者自定义了光标则另当别论） \n 	你如果要选择一个选项，你只需要点击那个文字即可。\n 	如果你想知道某个选项的帮助，1.把鼠标在上面停留一会看是否会弹出一个窗口（注释）；\n 	2.看看把鼠标停在上面时会不会在旁边（或者另一个窗口）显示一个什么 \n 	最后：这个程序好不好用其实取决于编写他的人，请遵照程序的提示。\n 	 --由LZ编写 \n 	 \n \n \n \nUpdate:\n \n --本程序(clicking)由linze原创，需要外传请通知作者，感谢配合！\n  \n V0.1/*首版*/\n congratulation!Clicking()函数诞生了，修复横竖不分显示现象，是Lz编的一个允许鼠标移动的C++程序哦！\n V1.0/*2019清明特辑*/\n 添加了中文插件，并确定和记录了初始窗口位置和颜色。\n V1.1\n Lz爆肝允许了窗口移动，修复了大部分BUG包括连点（但是他偷懒了），准备添加注释插件。\n V2.0/*2019清明特辑*/\n 冒着被*的危险，成功添加注释插件！注释功能多样，还具备即时刷新功能，快来探索吧！\n V2.1\n SetConsoleTextAttribute(OPhandle,0x20|0x80)启动！允许五颜六色的标签啦！\n V2.2\n 填充了标签，修复了超界漏洞（Debug程序越来越长了呵呵），还有让那个信息框识字（中文）。。。\n 因为psy建议，添加了防止win10的闪电字幕出现卡字现象的插件，添加了win10稳定模式\n V2.3\n 添加了窗口功能（当场吐血），现在知道xy轴混用的危害了（qwq抓了一星期臭虫）。另外抓了一个自添加注释就隐藏的bug，今天总算把它揪出来了——右移时一次跳两格。还精简了函数变量。。\n 还有一个惊讶地发现，clicking已经快炸内存了……119688kb（116.87890625MB），但是用电脑管家加速后剩396kb（不足1MB），有种扎心感觉\n V2.3开始可以公布了~AWA~，因为楼主的功能已经差不多了（好像也没啥好打了）\n V2.4\n V2.3没有考虑Trans的情况于是发现了一大堆新bug，决定再肝一场。。。配置也多了很多，可以不用改内置就改设置啦\n 决定2.3、2.4因为有bug，所以更改为2.5才公布。接下来还有V2.5版准备添加线程（速度嗖嗖的）\n V2.5\n 成功添加多线程，虽然给操作带来了巨大麻烦和巨多bug（好像每一次都有很多），但是成功为其可游戏操作奠基。添加了拖动取消功能和锁定窗口（不允许拖动）功能。\n 还特地肝了一个教程（lj）出来\n 虽然有些人认为现在图形库那么发达，随便用个java、VC，或者c++装个EGE、Box2D都比他好（其实我也想学），但是怎么说呢，有个能面向大众（懒awa）的鼠标控制程序还是挺有创意的吧。。。\n 如果有时间会将其转换为头文件，将正式公开V2.5[rep].rar\n V2.6\n 进行了小改\n 上次被我妈和刘姐姐测试了一下发现她们一拿到的反应——这个怎么用啊？(...)不过后来发现是因为中年人们使用鼠标习惯了用尖尖对准按钮，我们喜欢整个挪上去，所以进行了一些些改动。另外因为字体需要，爆肝（真的很惨）了一个活动字体变量fsx和fsy(我估计以后不会再添加这些恶心的东西了)，又花了一下午。另外修了一些小bug\n 添加了精简版（其实就是删了几个注释。。。），为了时它体积小一些、使用没那么繁琐（但是改起来就繁琐了）\n 本来8.1已经定稿了，后来想着觉得不对劲，8.18从重庆刚回来就干，总算把校准搞定了（我不会再弄他了。。。恶心。。。）另外完善了冻结窗口做法\n \n V2.6最后完成于2019.8.18\n \n \n \n \n #define 敬请期待! 楼主lz又偷懒了!\n \n";
const int Ath[15]={67,79,68,69,68,32,66,89,58,76,105,110,90,101,46};

int Options[525][135],Optionstot,Optionstringtot,WinVer,Enabled;//输入数据，总数，Windows版本，线程是否启动，返回数据
string Optionstring[105];
int mxl,mxh;/*msgbox() NEEDED*/
string ww=""/*当前窗口顺序*/;
char cc;//调试getch()用 

//Function declare
int INTSc(int linenum, int number);
bool Form_load();
bool VerVerify();
bool Pr(char* fileName, int linenum,string ot);
void gotoxy(int x,int y);


//API SYMBOL
const HWND hwnd=GetForegroundWindow();
const HANDLE OPhandle = GetStdHandle(STD_OUTPUT_HANDLE);
RECT rect;
LONG wOldLong=GetWindowLong(hwnd, GWL_STYLE);
CONSOLE_CURSOR_INFO CursorInfo;


bool _VerVerify=VerVerify();
const int EoutDelay=INTSc(3,1),IDDTFP=INTSc(3,2),WDD=15,WDLMT=205,Trans=INTSc(2,1),wOldColorAttrs=INTSc(2,2);//闪电字幕延时(!>5) 注释终止偏移  窗口累积最大个数 窗口数组大小  非焦点窗口可见性  默认窗口文字颜色 

short int cz_sys[WDD][WDLMT][WDLMT],cml_sys[WDD][WDLMT][WDLMT],cmt_sys[WDD][WDLMT][WDLMT],cmmd_sys[WDD][WDLMT][WDLMT],cmdl_sys[WDD][WDLMT][WDLMT],cmbds_sys[WDD][WDLMT][WDLMT],cl_sys[WDD][WDLMT][WDLMT],tasks_sys[WDD*3],crif_sys[WDLMT][WDLMT],movable_sys[WDD];
short int wdl_sys[WDD],wdt_sys[WDD],wdr_sys[WDD],wdb_sys[WDD],chv[WDLMT*WDLMT],ccv,ccvn,dqx,dqy;
string c_sys[WDD][WDLMT][WDLMT],cm_sys[WDD][WDLMT][WDLMT],wdtp_sys[WDD];
int ial=INTSc(1,1),iar=INTSc(1,2),iat=INTSc(1,3),iab=INTSc(1,4),BROAD=8,TOPBROAD=30,fsx=INTSc(2,3),fsy=INTSc(2,4);
char CTitle[1005];
//int wl=ial/fsx,wr=iar/fsx,wt=iat/fsy,wb=iab/fsy;
const int lm=sqrt(sizeof(c_sys)/8/WDD)-5;
bool _Form_load=Form_load();



//LOADING AREA-------------------------------------

inline int INTSc(int linenum, int number)
{
	return Options[linenum][number];//From the Options[][];
/*
	ifstream in(fileName);
	if(!NoUnicode)
	{
		ifstream CHKN(fileName);
		wchar_t chkn;
		CHKN.read((char *)(&chkn), 2);
		if(chkn==0xFFFE||chkn==0xFEFF){cout<<"UNC!";return -1;}
	}
	int ans;string data;
	for(int i=1;i<linenum;i++)getline(in,data);
	for(int i=1;i<=number;i++)in>>ans;
	in.close();
	return ans;
*/
}
inline bool Pr(char* fileName, int linenum,string ot)
{
	if(fileName=="*A")
	{
		ofstream out("options.txt",ios::out);
		out<<OptionsForge;
		return out.is_open();
	}
	
	ifstream in(fileName,ios::in);
	char data[511][128];int cnt=1;
	while(in.peek()!=EOF)
	{
		in.getline(data[cnt],127);
		cnt++;
	}
	in.close();
	ofstream ou(fileName,ios::out);
	for(int i=0;i<ot.size();i++)
	data[linenum][i]=ot[i];
	data[linenum][ot.size()]='\0';
	for(int i=1;i<=cnt;i++)
	ou<<data[i];
	ou.close();
	return true;
}
/*UnicodeScanner (Already disabled)
inline int UINTSc(char* fileName, int linenum, int number)
{
	ifstream in(fileName);
	int ans;string anss;
	wchar_t wch;
	in.read((char *)(&wch), 2);
	for(int i=0;i<linenum-1;)//Line positioning
	{
		in.read((char *)(&wch), 2);
		if (wch == 0x000D)
		{
			in.read((char *)(&wch), 2);
			i++;
		}
	}
	for(int i=0;i<number-1;)//Space positioning
	{
		in.read((char *)(&wch), 2);
		if ((char)wch == ' ')
		{
			i++;
		}
	}
	for(int i=0;;)//Number positioning
	{
		in.read((char *)(&wch), 2);
		if ((char)wch == ' ')
		{
			break;
		}
		else
		{
			ans*=10;
			ans+=((char)wch)-48;
		}
	}
	in.close();
	return ans;
}
*/

inline string HEXR(int k) //dec->hex
{
	string tmp="",ans="";
    while(k)
    {
    	tmp+=k%16<10?k%16+'0':k%16-10+'a';
        k/=16;
    }
    for(int i=tmp.size()-1;i>=0;i--)
    ans+=tmp[i];
    return ans;
}
inline string StCh(int k)//转换数字为字符串 
{
	string ans="";
	while(k)
	{
		ans=char((k%10)+'0')+ans;
		k/=10;
	}
	return ans;
}
void FontSizer()	//调整字体大小（仅完整版包含） 
{
	Pr((char*)"tmp.bat",1,"@echo off\nreg QUERY HKCU\\Console /v FontSize >que.txt");
	system("tmp.bat");
	ifstream in("que.txt",ios::in);
	char tmp[155];
	string data,tmps;
	int o=0;
	while(in.peek()!=EOF)
	{
		in.getline(tmp,128);
		data=tmp;
		if(data.find(HEXR(fsy*65536+fsx))!=string::npos)
		{
			o=1;
			break;
		}
	}
	in.close();
	if(o==0)
	{
		cout<<"请允许修改注册表，这是为了使字体适合本程序设置\n如要更改，请更改options.txt中的fsx和fsy\n";
		tmps="reg ADD HKCU\\Console /v FontSize /t REG_DWORD /f /d "+StCh(fsy*65536+fsx);
		system(tmps.c_str());
//		Pr((char*)"a.bat",1,"reg QUERY HKCU\\Console /v FontSize >que.txt");
		DD();
		tmps="if not exist \".\\"+Optionstring[1]+"\" echo 请不要改动exe的名字！请将其改回："+Optionstring[1]+"，否则无法启动";
		system(tmps.c_str());
		tmps="start "+Optionstring[1];
		system("del tmp.bat");
		system("del que.txt");
		system(tmps.c_str());
		exit(0);
	}
	system("del tmp.bat");
	system("del que.txt");
	system("reg ADD HKCU\\Console /v FontSize /t REG_DWORD /f /d 0x00100008");
	return;
}

bool VerVerify()
{
	//Verson Verify
	int Ln=2;
	system("attrib -r -a options.txt");
	ifstream in("options.txt");
	int ans;char anss[64];
	in.getline(anss,64);
	if(anss!=OptionsForge.substr(0,50))
	{
		TD();
		printf("The Options(options.txt) have not be initialize or it is broken!\a\n程序设置未初始化\n你需要重新启动程序来正常运行\n");
		TDCyan();
		printf("If you first get the progress,don't be afraid.Just RESTART.\n如果该提示重复出现，请联系Lz\n");
		Rst:;
		TRed();BDYellow();
		cout<<"Please RESTART LATER\n请稍候重启该程序！\n";
		BGreen();TDPink();
		cout<<"\nVERSON:"<<Verson<<"\nReWriting...\n";
		if(!Pr((char*)"*A",0,""))
		{
			TDRed();
			MessageBox(hwnd,"E.1:初始化错误","Process Erruption",MB_OK);
			cout<<"Initialize faild\a\t[Any key to continue]\nPlease contact the author\n请重新获取";
			char cc=getch();
			in.close();
			exit(0);
			return 0;
		}
		TDGreen();
		cout<<"Initialize succeed\t[Any key to continue]\n[任意键继续]\t";
		char cc=getch();
		in.close();
		exit(0);
		return 0;
	}
	int n;char ccc;
	while(in.peek()!=EOF)
	{
		Optionstot++;
		in.getline(anss,128);
		in>>n;
		if(n==-1)
		{
			in.getline(anss,128);
			in.getline(anss,128);
			Optionstring[++Optionstringtot]=anss;
		}
		else
		{
			for(int i=1;i<=n;i++)
			in>>Options[Optionstot][i];
		}
		in>>ccc;
	}
	return 1;
}
bool Form_load()
{
	gotoxy(0,0);DD();
//	system("chcp 936");//For the computer without the correct codepage 
	GetConsoleCursorInfo(OPhandle, &CursorInfo);//获取控制台光标信息
	for(int w=0;w<WDD;w++)
	for(int i=0;i<WDLMT;i++)
	for(int j=0;j<WDLMT;j++)
	{
		cl_sys[w][i][j]=wOldColorAttrs;
		c_sys[w][i][j]=" ";
	}
	
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(OPhandle,&csbi);
	COORD size={255,255};
	SetConsoleScreenBufferSize(OPhandle,size);
	WinVer=INTSc(4,1);
	GetWindowRect(hwnd,&rect);
	if(ial==-1) ial=rect.left;
	if(iar==-1) iar=rect.right;
	if(iat==-1) iat=rect.top;
	if(iab==-1) iab=rect.bottom;
	ChWp(ial,iat,iar-ial,iab-iat);
	GetWindowText(hwnd, CTitle, 1000);
	FontSizer();
	system("cls");
	return 1;
}
inline void gotoxy(int x,int y)//cursor position setting光标位置设置 
{
	SetConsoleCursorPosition(OPhandle,(COORD){x,y});
}

//INITIALIZE COMPLETED----------------------------------------------------------------


void eout(string s,int sx,int sy)//Thank YYC for this code--lighting subtitles!闪电字幕 
{
  int i=0,m=0,p=EoutDelay;
  char sds;sx++;
  gotoxy(sx,sy);POINT pt;bool TKmoved;
  TKmoved=KEY_DOWN(MOUSE_MOVED);GetCursorPos(&pt);
  int nwpx=pt.x,nwpy=pt.y;
  while(i<s.size()&&!(max(abs(pt.x-nwpx),abs(pt.y-nwpy))>IDDTFP||KEY_DOWN(MOUSE_MOVED)!=TKmoved))
   {
       if (s[i]==Endnp)
        {
          if (s[i-1]>0)
           cout<<' ';
           sy++;
           gotoxy(sx,sy);
        }
       if (s[i]!=Endnp)
        {
          cout<<'|';
          if (!kbhit())
           Sleep(p);
          cout<<"\b┃";
          if (!kbhit())
           Sleep(p);
          if(WinVer)cout<<"\b ▊";
          else cout<<"\b\b ▊";
          if (!kbhit())
           Sleep(p);
          if (kbhit() && i%3==0)
           sds=getch();
          if (s[i]<0)
           {
             cout<<"\b\b\b"<<s[i]<<s[i+1];
             i++;
           }
          else
           cout<<"\b\b\b"<<s[i];
        }
     i++;
     if (!kbhit())
      Sleep(p);
  Sleep(p);GetCursorPos(&pt);
   }
   cout<<" \b";
   return;
}
void cost(int left,int top,int right,int down,int &px,int &py)//area selecting区域选择* 
{
	Sleep(10);
	system("mode con cols=175 lines=50");
	ChWp(0,0,1600,900);
	POINT pt;int o=0;
	while(!o)
	{
		while(KEY_DOWN(MOUSE_MOVED))
		{
			system("cls");GetCursorPos(&pt);
			if(pt.x/fsx<left||pt.y/fsy<top||pt.x/fsx>right||pt.y/fsy>down)continue;
			px=pt.x/fsx;py=pt.y/fsy;gotoxy(pt.x/fsx-2,pt.y/fsy-2);
			cout<<Sp0;gotoxy(pt.x/fsx-2,pt.y/fsy-1);
			cout<<pt.x/fsx<<"*"<<pt.y/fsy;o=1;Sleep(50);
			gotoxy(pt.x/fsx-2,pt.y/fsy-2);cout<<"  ";
			gotoxy(pt.x/fsx-2,pt.y/fsy-1);cout<<"        ";
		}
	}
	system("cls");cout<<"select area:"<<px<<"*"<<py<<endl;
	Sleep(1000);ChWp(rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top);
	return;
}
void clr(int sx,int sy,int ex,int ey,int wd)
//explain:from(sx,sy)to(ex,ey)
{
	int bs;WORD TMPCL=0;
	for(int i=sx;i<=ex;i++)
	{
		gotoxy(sy,i);
		for(int j=sy;j<=ey;j++)
		{
			bs=0;
			for(int ii=0;ii<ww.size();ii++)
			if(Trans&&j>=wdl_sys[ww[ii]-'0']&&j<=wdr_sys[ww[ii]-'0']&&i>=wdt_sys[ww[ii]-'0']&&i<=wdb_sys[ww[ii]-'0'])
			{
				bs=ww[ii]-'0';break;
			}
			if(bs==0)bs=wd;
			if(cz_sys[bs][i][j]!=-1)
			{
				SetConsoleTextAttribute(OPhandle,cl_sys[bs][i][j]);
				printf("%s",c_sys[bs][i][j].c_str());
				if(c_sys[bs][i][j].size()==2)j++;
			}
			else
			{
				SetConsoleTextAttribute(OPhandle,cl_sys[bs][i][j-1]);
				printf("\b%s",c_sys[bs][i][j-1].c_str());
			}
		}
	}
	gotoxy(0,0);
	return;
}
void wcrr(int k)
{
	for(int i=0;i<WDLMT;i++)
	for(int j=0;j<WDLMT;j++)
	{
		c_sys[k][i][j]=" ";
		cz_sys[k][i][j]=0;
		cm_sys[k][i][j]="";
		cmt_sys[k][i][j]=0;
		cml_sys[k][i][j]=0;
		cmdl_sys[k][i][j]=0;
		cmmd_sys[k][i][j]=0;
		cmbds_sys[k][i][j]=0;
		cl_sys[k][i][j]=wOldColorAttrs;
	}
	for(int i=0;i<ww.size();i++)
	if(ww[i]-'0'==k){ww.erase(i,1);break;}
	if(ww.size()==0) clr(wdt_sys[k],wdl_sys[k],wdb_sys[k],wdr_sys[k],0);
	else clr(wdt_sys[k],wdl_sys[k],wdb_sys[k],wdr_sys[k],ww[0]-'0');
	return;
}
inline void sprf()
{
	int bs;
	for(int i=0;i<WDLMT;i++)
	for(int j=0;j<WDLMT;j++)
	if(crif_sys[i][j])
	{
		gotoxy(j,i);
		bs=ww[0]-'0';crif_sys[i][j]=0;
		for(int ii=0;ii<ww.size();ii++)
		if(Trans&&j>=wdl_sys[ww[ii]-'0']&&j<=wdr_sys[ww[ii]-'0']&&i>=wdt_sys[ww[ii]-'0']&&i<=wdb_sys[ww[ii]-'0'])
		{
			bs=ww[ii]-'0';break;
		}
		if(cz_sys[bs][i][j]!=-1)
		{
			SetConsoleTextAttribute(OPhandle,cl_sys[bs][i][j]);
			printf("%s",c_sys[bs][i][j].c_str());
		}
		else
		{
			SetConsoleTextAttribute(OPhandle,cl_sys[bs][i][j-1]);
			printf("\b%s",c_sys[bs][i][j-1].c_str());
		}
	}
	return;
}
void spclr(int wd)
{
	for(int i=wdt_sys[wd];i<=wdb_sys[wd];i++)
	{
		for(int j=wdl_sys[wd];j<=wdr_sys[wd];j++)
		if(Trans||(c_sys[wd][i][j]!=" "||cl_sys[wd][i][j]!=wOldColorAttrs))
		{
			gotoxy(j,i);
			if(cz_sys[wd][i][j]!=-1)
			{
				SetConsoleTextAttribute(OPhandle,cl_sys[wd][i][j]);
				printf("%s",c_sys[wd][i][j].c_str());
			}
			else
			{
				SetConsoleTextAttribute(OPhandle,cl_sys[wd][i][j-1]);
				printf("\b%s",c_sys[wd][i][j-1].c_str());
			}
		}
	}
	gotoxy(0,0);
	return;
}
void msgbox(int wd,int sx,int sy,int cl,string msg,int md,int bdstyle)//MessageBox信息框 
//explain:SHOWpos(sx,sy),MSG:msg,showing mod,BoardStyle[See Msbl Msbt]
{
	int cnt=0,xl=0,tpo=0;
	int mxh=0,mxl=0;
	int maxc=(iar-ial)/fsx-2-sx,chc=1,cmp=0;
	if(maxc<0)return;
	msg+=" ";
	/* It's a pity that I delete the mode because of the function improvment.
	for(int i=0;i<msg.size();i++)
	{
		if(msg[i]==Cnp){cmp=1;msg.erase(i,1);}else cmp=0;
		if(msg[i]!=Endnp)cnt++;
		else {cnt=0;continue;}
		if((chck(msg[i],msg[i+1])||cmp)&&chc){chc=0;}
		else if(chc==0){chc=1;}
//		Use this to find Chinese which can't distinguish
//		if(chc==0)msg.insert(i,1,'1'),i++;
		if(cnt>maxc-12&&(!chck(msg[i],msg[i+1])||chc==0)&&(msg[i+1]!='}'))
		{
			msg.insert(i,1,Endnp);i++;
			cnt=0;
		}
	}*/
	cnt=0;
	WORD TMPCL=cl;
	TMPCL&=~FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(OPhandle,TMPCL|FOREGROUND_INTENSITY);
	string l=Msbl[bdstyle],t=Msbt[bdstyle];
	for(;cnt<msg.size();mxh++)
	{
		gotoxy(sx,sy+mxh+1);
		printf("%s",l.c_str());
		if(md==2)while(msg[cnt]!=Endnp&&cnt<msg.size())cnt++,xl++;
		else while(msg[cnt]!=Endnp&&cnt<msg.size())
		{
			cnt++;xl++;
		}
		mxl=max(mxl,xl);
		xl=0;cnt++;
	}
	if(l.size()>1)tpo+=3;
	mxl+=tpo;mxl+=2; 
	if(mxl%2==0)mxl+=1;
	
	::mxh=mxh+5;::mxl=mxl+5;
	cnt=xl=0;
	if(md!=2)
	for(int i=1;i<=mxh;i++)
	{
		gotoxy(sx+1+max(tpo-2,0),sy+i);
		while(cnt<msg.size()&&msg[cnt]!=Endnp)
		{
			printf("%c",msg[cnt]);
			cnt++;xl++;
		}
		for(int j=1;j<=mxl-xl-max(0,tpo-3);j++)printf(" ");
		xl=0;cnt++;
	}
	for(int i=1;i<=mxh;i++)
	{
		gotoxy(mxl+sx+1,sy+i);
		printf("%s",l.c_str());
	}
	if(md==1)
	{
		SetConsoleTextAttribute(OPhandle,TMPCL);
		for(int i=1;i<=mxh+max(tpo-1,1);i++)
		{
			gotoxy(mxl+sx+max(tpo-2,0)+2,sy+i);
			printf("%s",l.c_str());
		}
		SetConsoleTextAttribute(OPhandle,TMPCL|FOREGROUND_INTENSITY);
	}
	if(l.size()>1)mxl=mxl/2;
	gotoxy(sx,sy);
	for(int i=1;i<=mxl+2&&i+sx+1<iar-30;i++)printf("%s",t.c_str());
	gotoxy(sx,sy+mxh+1);
	for(int i=1;i<=mxl+2&&i+sx+1<iar-30;i++)printf("%s",t.c_str());
	if(md==1)
	{DD();
		SetConsoleTextAttribute(OPhandle,TMPCL);
		gotoxy(sx,sy+mxh+2);
		for(int i=1;i<=mxl+3;i++)printf("%s",t.c_str());
		SetConsoleTextAttribute(OPhandle,TMPCL|FOREGROUND_INTENSITY);
	}
	if(md==2)
	{
			if(t.size()==2)mxl*=2;
		for(int i=1;i<=mxh;i++)
		{
			gotoxy(sx+1+max(tpo-2,0),sy+i);
			for(int i=1;i<=mxl&&i+sx+1<iar-30;i++)printf(" ");
		}
		eout(msg,sx+1,sy+1);
	}
	return;
}
void lock(int wd)
{
	movable_sys[wd]=!movable_sys[wd];
	return;
}
void cw(int wd,int x,int y,string s,int ct,string cm,int cml,int cmt,int cmdl,int cmmd,int cmbds,int cl)//menu writing system菜单写入系统*
//explain:window:wd(it will be auto existed),boardstyle:wdbds(See Wdbdsl Wdbdst),start from (x,y), text:s, return value:ct, comment:cm, comment start from (cml,cmt) [-1 means auto]
{
	int cmp=0,cxl,cxt;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='}')
		{
			x++;
			for(int j=0;j<=i;j++)
			s.erase(0,1);
			i=0;
		}
		if(s[i]==Cnp){cmp=1;s.erase(i,1);}
		cz_sys[wd][x][y+i]=ct;
		crif_sys[x][y+i]=1;
		if(cml==-1)cxl=x+1;else cxl=cml;
		if(cmt==-1)cxt=y+i;else cxt=cmt;
		cm_sys[wd][x][y+i]=cm;
		cmt_sys[wd][x][y+i]=cxt;
		cml_sys[wd][x][y+i]=cxl;
		cmdl_sys[wd][x][y+i]=cmdl;
		cmmd_sys[wd][x][y+i]=cmmd;
		cmbds_sys[wd][x][y+i]=cmbds;
		cl_sys[wd][x][y+i]=cl;
		if(chck(s[i],s[i+1])||cmp)
		{
			c_sys[wd][x][y+i]=s.substr(i,2);
			cz_sys[wd][x][y+i+1]=-1;
			cmt_sys[wd][x][y+i+1]=cxt;
			cml_sys[wd][x][y+i+1]=cxl;
			cmdl_sys[wd][x][y+i+1]=cmdl;
			cmmd_sys[wd][x][y+i+1]=cmmd;
			cmbds_sys[wd][x][y+i+1]=cmbds;
			cl_sys[wd][x][y+i+1]=cl;
			i++;cmp=0;
		}
		else
		{
			c_sys[wd][x][y+i]=s[i];
		}
	}
	return ;
}
void cwd(int wd,int wdbds,string wdtp,int cwl,int cwt,int cwr,int cwb)//window writing system窗口创建系统
{
	int o=0;
	string wdbdst="";
	for(int i=1;i<=cwr-cwl;i++)wdbdst+=Wdbdst[wdbds];
	wdl_sys[wd]=cwl;
	wdt_sys[wd]=cwt;
	wdr_sys[wd]=cwr;
	wdb_sys[wd]=cwb;
	wdtp_sys[wd]=wdtp;
	ww.insert(0,1,(char)wd+'0');
	cw(wd,cwt,cwl,wdbdst,-2,"",0,0,0,0,0,wOldColorAttrs|0x8);
	cw(wd,cwb,cwl,wdbdst,-2,"",0,0,0,0,0,wOldColorAttrs|0x8);
	for(int i=cwt;i<=cwb;i++)
	{
		cw(wd,i,cwl,Wdbdsl[wdbds],-2,"",0,0,0,0,0,wOldColorAttrs|0x8);
		cw(wd,i,cwr,Wdbdsl[wdbds],-2,"",0,0,0,0,0,wOldColorAttrs|0x8);
	}
	cw(wd,cwt,(cwl+cwr)/2-wdtp.size()/2,wdtp,-2,"",0,0,0,0,0,wOldColorAttrs|0x8);
	//Disabled
//	cw(wd,cwt,cwr-6,"[ ][ ]",0,"",0,0,0,0,0,wOldColorAttrs);
//	cw(wd,cwt,cwr-5,"-",-3,"",0,0,0,0,0,wOldColorAttrs|0x8|0x10|0x80);
//	cw(wd,cwt,cwr-2,"X",-4,"",0,0,0,0,0,wOldColorAttrs|0x8|0x10|0x80);
	return;
}
void* chw(void* cwcn)//menu choosing system菜单选择系统* 
//cwcn来自主线程的传递 
{
	CWCN* tcwcn=(CWCN*)cwcn;
	int wd=tcwcn->wd,dl=tcwcn->dl,ls=tcwcn->ls;
	if(Trans==0)system("cls");
	else
	{
		for(int i=ww.size()-1;i>=0;i--)if(ww[i]-'0'!=wd)spclr(ww[i]-'0');
	}
	spclr(wd);
	gotoxy(1,1);
	POINT pt;int l=0,t=0,r=0,b=0,cpst=0,cmdl=0,tdqx,tdqy;bool TKmoved=0;
//	GetCursorPos(&pt);
//	GetWindowRect(hwnd,&rect);
//	ial=rect.left+BROAD;
//	iar=rect.right;
//	iat=rect.top+TOPBROAD;
//	iab=rect.bottom;
	int bs=wd,o=0;
	for(int i=0;i<ww.size();i++)
	if(ww[i]-'0'==wd){ww.erase(i,1);ww.insert(0,1,(char)wd+'0');o=1;break;}
	if(!o)return NULL;
	Enabled=1;
	goto A;
	while(Enabled)
	{
		sprf();
		Sleep(dl-cpst);cpst=0;
		GetCursorPos(&pt);
//		while(pt.y<iat||pt.y>iab-fsy*4||pt.x<ial||pt.x>iar-fsx*4)
		{
//			Sleep(dl*2),GetCursorPos(&pt);
			GetWindowRect(hwnd,&rect);
			if(rect.left!=-32000) 
			{
				ial=rect.left+BROAD;
				iar=rect.right;
				iat=rect.top+TOPBROAD;
				iab=rect.bottom;
			}
		} 
		if(cz_sys[bs][dqy][dqx]==-1)dqx--,pt.x-=fsx;
		if(cm_sys[wd][dqy][dqx]!=""&&((pt.x-ial)/fsx==dqx||(pt.x-ial)/fsx==dqx+1)&&(pt.y-iat)/fsy==dqy)
		{
			TKmoved=KEY_DOWN(MOUSE_MOVED);
			while(((pt.x-ial)/fsx==dqx||(pt.x-ial)/fsx==dqx+1)&&(pt.y-iat)/fsy==dqy&&KEY_DOWN(MOUSE_MOVED)==TKmoved)
			{
				GetCursorPos(&pt);
				if(cmdl==cmdl_sys[wd][dqy][dqx]/dl)
				{
					Sleep(cmdl_sys[wd][dqy][dqx]%dl);
					cpst=cmdl_sys[wd][dqy][dqx]%dl;
					msgbox(bs,cmt_sys[wd][dqy][dqx],cml_sys[wd][dqy][dqx],cl_sys[wd][dqy][dqx],cm_sys[wd][dqy][dqx],cmmd_sys[wd][dqy][dqx],cmbds_sys[wd][dqy][dqx]);
				}
				cmdl++;
				Sleep(dl-cpst);cpst=0;
				if(!Enabled)return NULL;
				for(;tasks_sys[0]>=1;tasks_sys[0]--)
				if(tasks_sys[tasks_sys[0]]>0)
				{
					for(int i=0;i<ww.size();i++)
					if(ww[i]-'0'==tasks_sys[tasks_sys[0]]){ww.erase(i,1);break;}
					spclr(tasks_sys[tasks_sys[0]]);
					ww.insert(0,1,(char)tasks_sys[tasks_sys[0]]+'0');
					bs=wd=tasks_sys[tasks_sys[0]];
				}
				else 
				{
					if(wd== -tasks_sys[tasks_sys[0]])
					{
						if(ww.size()==1){wcrr(-tasks_sys[tasks_sys[0]]);system("cls");Enabled=0;return NULL;}
						if(cm_sys[wd][dqy][dqx]!="") clr(cml_sys[wd][dqy][dqx],cmt_sys[wd][dqy][dqx],cml_sys[wd][dqy][dqx]+mxh,cmt_sys[wd][dqy][dqx]+mxl,ww[1]-'0');
						bs=wd=ww[1]-'0';
						spclr(ww[1]-'0');
					}
					wcrr(-tasks_sys[tasks_sys[0]]);
				}
			}
			if(cm_sys[wd][dqy][dqx]!="") clr(cml_sys[wd][dqy][dqx],cmt_sys[wd][dqy][dqx],cml_sys[wd][dqy][dqx]+mxh,cmt_sys[wd][dqy][dqx]+mxl,wd);
		}
		SetConsoleTextAttribute(OPhandle,(WORD)cl_sys[bs][dqy][dqx]);
		cmdl=0;gotoxy(dqx,dqy);
		printf("%s",c_sys[bs][dqy][dqx].c_str());
		A:;
		dqx=max((pt.x-ial)/fsx,(long)0);
		dqy=max((pt.y-iat)/fsy,(long)0);
		if(cz_sys[bs][dqy][dqx]==-1)dqx--,pt.x-=fsx;
		bs=wd;
		if(Trans)
		{
			bs=0;
			for(int i=0;i<ww.size();i++)
			if(dqx>=wdl_sys[ww[i]-'0']&&dqx<=wdr_sys[ww[i]-'0']&&dqy>=wdt_sys[ww[i]-'0']&&dqy<=wdb_sys[ww[i]-'0'])
			{
				bs=ww[i]-'0';break;
			}
			if(bs==0)bs=wd;
		}
		if(KEY_DOWN(MOUSE_MOVED))
		{
					
			if(cz_sys[wd][(pt.y-iat)/fsy][(pt.x-ial)/fsx]>0)
			{
				while(KEY_DOWN(MOUSE_MOVED))Sleep(dl);
				clr(cml_sys[wd][dqy][dqx],cmt_sys[wd][dqy][dqx],cml_sys[wd][dqy][dqx]+mxh,cmt_sys[wd][dqy][dqx]+mxl,wd);
				gotoxy(dqx,dqy);
				cout<<c_sys[wd][dqy][dqx];
				GetCursorPos(&pt);
				if(cz_sys[wd][(pt.y-iat)/fsy][(pt.x-ial)/fsx]==-1)pt.x-=fsx;
				if(cz_sys[wd][(pt.y-iat)/fsy][(pt.x-ial)/fsx]<=0)continue;
				SetConsoleTextAttribute(OPhandle,wOldColorAttrs);
				chv[++chv[0]]=cz_sys[wd][(pt.y-iat)/fsy][(pt.x-ial)/fsx];
				if(!ls){Enabled=0;system("cls");return NULL;}
			}
			
			if(cz_sys[bs][(pt.y-iat)/fsy][(pt.x-ial)/fsx]==-2&&movable_sys[bs]==0)
			{
				while(KEY_DOWN(MOUSE_MOVED))
				{
					tdqx=max((pt.x-ial)/fsx,(long)0);
					tdqy=max((pt.y-iat)/fsy,(long)0);
					gotoxy(tdqx,tdqy);
					
					cout<<Sp1;Sleep(dl);
					GetCursorPos(&pt);
				}
				system("cls");
				wd=bs;
				short int tcz_sys[WDLMT][WDLMT],tcml_sys[WDLMT][WDLMT],tcmt_sys[WDLMT][WDLMT],tcmmd_sys[WDLMT][WDLMT],tcmdl_sys[WDLMT][WDLMT],tcmbds_sys[WDLMT][WDLMT],tcl_sys[WDLMT][WDLMT];
				string tc_sys[WDLMT][WDLMT],tcm_sys[WDLMT][WDLMT];
				for(int i=wdt_sys[wd];i<=wdb_sys[wd];i++)
				for(int j=wdl_sys[wd];j<=wdr_sys[wd];j++)
				{
					tc_sys[i][j]=c_sys[wd][i][j];
					tcz_sys[i][j]=cz_sys[wd][i][j];
					tcm_sys[i][j]=cm_sys[wd][i][j];
					tcmt_sys[i][j]=cmt_sys[wd][i][j];
					tcml_sys[i][j]=cml_sys[wd][i][j];
					tcmdl_sys[i][j]=cmdl_sys[wd][i][j];
					tcmmd_sys[i][j]=cmmd_sys[wd][i][j];
					tcmbds_sys[i][j]=cmbds_sys[wd][i][j];
					tcl_sys[i][j]=cl_sys[wd][i][j];
				}
				wcrr(wd);ww.insert(0,1,(char)wd+'0');
				int pl=wdl_sys[wd],pt=wdt_sys[wd];
				int tmpx=tdqx-dqx,tmpy=tdqy-dqy;
				if(wdl_sys[wd]< -tmpx)tmpx= 0-wdl_sys[wd];
				if(wdt_sys[wd]< -tmpy)tmpy= 0-wdt_sys[wd];
				
				wdl_sys[wd]=max(0,wdl_sys[wd]+tmpx);
				wdt_sys[wd]=max(0,wdt_sys[wd]+tmpy);
				wdr_sys[wd]=max(0,wdr_sys[wd]+tmpx);
				wdb_sys[wd]=max(0,wdb_sys[wd]+tmpy);
				for(int i=wdt_sys[wd];i<=wdb_sys[wd];i++)
				for(int j=wdl_sys[wd];j<=wdr_sys[wd];j++)
				{
					c_sys[wd][i][j]=tc_sys[i-tmpy][j-tmpx];
					cz_sys[wd][i][j]=tcz_sys[i-tmpy][j-tmpx];
					cm_sys[wd][i][j]=tcm_sys[i-tmpy][j-tmpx];
					cmt_sys[wd][i][j]=tcmt_sys[i-tmpy][j-tmpx]+tmpx;
					cml_sys[wd][i][j]=tcml_sys[i-tmpy][j-tmpx]+tmpy;
					cmdl_sys[wd][i][j]=tcmdl_sys[i-tmpy][j-tmpx];
					cmmd_sys[wd][i][j]=tcmmd_sys[i-tmpy][j-tmpx];
					cmbds_sys[wd][i][j]=tcmbds_sys[i-tmpy][j-tmpx];
					cl_sys[wd][i][j]=tcl_sys[i-tmpy][j-tmpx];
				}
				o=0; 
				for(int i=0;i<ww.size();i++)
				if(ww[i]-'0'==bs){ww.erase(i,1);ww.insert(0,1,(char)bs+'0');o=1;break;}
				if(Trans==1)
				{
					for(int i=ww.size()-1;i>=0;i--)if(ww[i]-'0'!=wd) spclr(ww[i]-'0');
				}
				spclr(wd);
			}
			/*if(cz_sys[bs][(pt.y-iat)/fsy][(pt.x-ial)/fsx]==-3)
			{
				if(ww.size()==1)continue;
				for(int i=0;i<ww.size();i++)
				if(ww[i]-'0'==bs){ww.erase(i,1);break;}//cout<<ww;char cc=getch();
				SetConsoleTextAttribute(OPhandle,wOldColorAttrs);system("cls");
				for(int i=0;i<ww.size();i++)spclr(ww[i]-'0');
				bs=wd=ww[0];
			}
			if(cz_sys[bs][(pt.y-iat)/fsy][(pt.x-ial)/fsx]==-4)
			{
				if(ww.size()!=1)
				{
					wcrr(bs);
					for(int i=0;i<ww.size();i++)spclr(ww[i]-'0');
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
			if(bs!=wd)
			{
				for(int i=0;i<ww.size();i++)
				if(ww[i]-'0'==bs){ww.erase(i,1);break;}
				spclr(bs);
				ww.insert(0,1,(char)(bs+'0'));
				wd=bs;
			}
			else 
			{
				SetConsoleTextAttribute(OPhandle,(WORD)cl_sys[bs][dqy][dqx]);
				gotoxy(dqx,dqy);
				if(c_sys[bs][dqy][dqx].size()>1)
				cout<<Ch1;
				else cout<<En1;
			}
		}
		else
		{
			SetConsoleTextAttribute(OPhandle,(WORD)cl_sys[bs][dqy][dqx]);
			gotoxy(dqx,dqy);
			if(c_sys[bs][dqy][dqx].size()>1)
			cout<<Ch0;
			else cout<<En0;
		}
		if(cz_sys[bs][dqy][dqx]>0)ccv=cz_sys[bs][dqy][dqx];		//有效值
		if(cz_sys[bs][dqy][dqx]!=-1)ccvn=cz_sys[bs][dqy][dqx];	//即时值

		for(;tasks_sys[0]>=1;tasks_sys[0]--)
		if(tasks_sys[tasks_sys[0]]>0)
		{
			for(int i=0;i<ww.size();i++)
			if(ww[i]-'0'==tasks_sys[tasks_sys[0]]){ww.erase(i,1);break;}
			spclr(tasks_sys[tasks_sys[0]]);
			ww.insert(0,1,(char)tasks_sys[tasks_sys[0]]+'0');
			bs=wd=tasks_sys[tasks_sys[0]];
		}
		else 
		{
			if(wd== -tasks_sys[tasks_sys[0]])
			{
				if(ww.size()==1){wcrr(-tasks_sys[tasks_sys[0]]);system("cls");Enabled=0;return NULL;}
				if(cm_sys[wd][dqy][dqx]!="") clr(cml_sys[wd][dqy][dqx],cmt_sys[wd][dqy][dqx],cml_sys[wd][dqy][dqx]+mxh,cmt_sys[wd][dqy][dqx]+mxl,ww[1]-'0');
				bs=wd=ww[1]-'0';
				spclr(ww[1]-'0');
			}
			wcrr(-tasks_sys[tasks_sys[0]]);
		}
			
			//DEBUG tools
//				gotoxy(dqx+1,dqy+1);printf("#pxy(abs):(%d,%d) <%d,%d>;dxy:%d %d#   \n",pt.x,pt.y,pt.x-ial,pt.y-iat,dqx,dqy);
//				gotoxy(dqx+1,dqy+2);printf("#WInfo.l%d t%d r%d b%d#   \n",ial,iat,iar,iab);
//				Sleep(205);
//				if(kbhit()&&getch()=='c')spclr(ww[0]-'0');
	}
	return NULL;
}
void ent(int dl/*LEAST 50!*/,int wd,int ls,int wt)//menu choosing system starter菜单选择系统启动程序* 
//explain:Fps:1000/dl(ms),which menu,whether going on when get values,whether waiting
{
	Enabled=1;
	CWCN* cwcn;
	tcwcn.dl=dl;
	tcwcn.wd=wd;
	tcwcn.ls=ls;
	cwcn=&tcwcn;
	if(wt) chw((void*)cwcn);
	else
	{
		pthread_t tids;
		pthread_create(&tids, NULL, chw, (void*)cwcn);
	}
	return;
}
void _example()
{
 int a,b,ans;char cc=0;
// cout<<"select player area:\n(click it!)";cost(10,10,75,45,a,b);system("cls");
cwd(1,0,"EXAMPLE",0,0,33,20);
cwd(3,2,"提示",35,0,55,20);
system("mode con cols=80 lines=25");
 cw(1,1,1,"-------------菜单-------------",0,"看我干嘛awa}我只是一个标题...",-1,-1,1000,1,3,0x2|0x8);
 cw(1,3,15,"开始play",1,"点此来开始游戏}等等，楼主还没放游戏呢qwq",-1,-1,0,1,0,0x4|0x1|0x8|0x80|0x20);
 cw(1,6,15,"退出exit",2,"单击退出",-1,-1,0,0,0,wOldColorAttrs);
 cw(1,10,5,"弹出一个新的窗口awa",3,"。。。}...}!",-1,-1,500,1,7,0x4);
 cw(1,11,5,"锁定\\解锁窗口",4,"",0,0,0,0,0,wOldColorAttrs);
 cw(1,7,1,"光标示例:┼╋+*╬#",15,"好看吗？}如果你不满意，可以通过程序首行的“光标形式”更改}多种多样，只有想不到没有做不到！}",8,15,600,2,21,0x2|0x10|0x8|0x80);
 cw(3,2,36,"挪动你的鼠标~",5,"敢不敢点我一下",0,0,0,0,0,wOldColorAttrs|0x8);
 cw(3,18,36,"关闭",6,"",0,0,0,0,0,wOldColorAttrs|0x8|0x4);
 cw(3,16,36,"查看帮助\\版本信息",20,"",0,0,0,0,0,0x8);
 tasks_sys[++tasks_sys[0]]=3;lock(3);
 gotoxy(0,0);ent(50,1,1,0);
 while(ans!=2&&Enabled)
 {
 	while(!chv[0])
	 {
	 	Sleep(100);
	 	if(ccv==1)
	 	{
	 		cw(3,5,36,"这是样例程序，}所以没有游戏}可以自己写鸭！",0,"",0,0,0,0,0,0x2|0x8);
	 		while(ccvn==1&&!chv[0])Sleep(50);
	 		cw(3,5,36,"              }            }              ",0,"",0,0,0,0,0,0);
		 }
		if(ccv==6)
	 	{
	 		cw(3,5,36,"且慢，请三思}关掉的话}没有提示了哦...",0,"",0,0,0,0,0,0x4|0x8);
	 		while(ccvn==6&&!chv[0])Sleep(50);
	 		cw(3,5,36,"            }        }               ",0,"",0,0,0,0,0,0);
		 }
		 if(ccv==4)
		 {
		 	lFreeze();
		 	while(ccvn==4&&!chv[0])Sleep(50);
		 	Sleep(3000);ccv=0;
		 	lInitial();
		 }
		 if(ccv==15)
		 {
		 	cw(3,5,36,"可惜，}这只能在程序里更改",0,"没什么好看的",-1,-1,0,0,1,0x1|0x8|0x20|0x80);
	 		while(ccvn==15&&!chv[0])Sleep(50);
	 		cw(3,5,36,"      }                  ",0,"",0,0,0,0,0,0);
		 }
	 }
 	ans=chv[chv[0]];chv[0]--;
 	if(ans==3){
 		cwd(2,1,"I AM THE 弹窗",10,7,25,15);
 		cw(2,8,11,"关掉",9,"点啊}其实点其他的键也会关掉qwq",-1,-1,0,0,0,wOldColorAttrs);
 		tasks_sys[++tasks_sys[0]]=2;
 		while(!chv[0])Sleep(100);
	 }
 	if(ans==9)tasks_sys[++tasks_sys[0]]=-2;
	 if(ans==5) system("start notepad");
	 if(ans==6) tasks_sys[++tasks_sys[0]]=-3;
	 if(ans==20)
	 {
	 	ofstream of("Note.txt");
	 	of<<Licenses;
	 	of<<"\n"<<Verson;
	 	of.close();
	 	system("Note.txt");
	 }

  //mains?[with both(a,b)]
 }
 Enabled=0;
 system("cls");
 
}
int main()
{
	cout<<"这是样例程序！\n(当前字体)"<<fsx<<" "<<fsy<<endl;
	cout<<"获得更多帮助请按 H \n观看实例请按 E \n";
	char cc=getch();
	if(cc=='H'||cc=='h')
	{
		ofstream of("Note.txt");
	 	of<<Licenses;
	 	of<<"\n"<<Verson;
	 	of.close();
	 	system("Note.txt");
	}
	if(cc=='E'||cc=='e')
	{
		_example();
		for(int i=1;i<=5;i++)wcrr(i); 
	}
 return 0;
}
