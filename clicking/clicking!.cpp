
/**----------------------------------------------------------------
Clicking_System () **完整版**
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

知识共享许可协议
本作品采用知识共享署名-非商业性使用-相同方式共享 4.0 国际许可协议进行许可。
https://creativecommons.org/Licence/by-nc-sa/4.0/

--本程序(clicking)由linze原创，需要外传请通知作者，感谢配合！
如果你需要将其作为礼物或者仅仅作为交流用途发给别人，你只需注明原作者即可。
（其实我也只是编来玩，没有谋求利益的意思，这还可以被更多人认可，为什么不呢？）
联系作者：qq:1612162886(验证信息注明你是通过程序备注找到的)；洛谷ID：43845（是OIer就来luogu啊）
}
**/


#include<cstdio>
//bool NXYD() {puts("主程序正在全速加载...");}
//bool CCJM=NXYD();
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<windows.h>
#include<pthread.h>
#include<cmath>
#include<conio.h>
#include<tchar.h>
using namespace std;

/*LZ的蒟蒻专用color库*/
#define TD() (SetConsoleTextAttribute(OPhandle,FOREGROUND_INTENSITY ))
#define TN() (SetConsoleTextAttribute(OPhandle,FOREGROUND_RED |FOREGROUND_BLUE |FOREGROUND_GREEN ))
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
#define DD() (SetConsoleTextAttribute(OPhandle, wOldColorAttrs==0?7:wOldColorAttrs))
#define HL()/*high lighter*/ (SetConsoleTextAttribute(OPhandle, 0x1|0x4|0x8|0x20|0x40|0x80))
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

//Library
const char Cnp=''/*(char)1:USE IT if you need to recognize the next two char as a chinese*/,Endnp='}';
string Msbl[]={"|","*","#","+",""," ","  ","│","┃","┆","┇","┊","┋","╳","□","■","█","▌","○","●","☆","★","?","?","?"}
	  ,Msbt[]={"-","*","#","+",""," ","  ","─","━","┄","┅","┈","┉","╳","□","■","█","▄","○","●","☆","★","?","?","?"};
string Wdbdsl[]={"|","*","#","+"," ","!","?","'",".","+"}
	  ,Wdbdst[]={"-","*","#","+"," ","!","?","'",".","="};
const char Ch0[]="┼",Ch1[]="╋",En0[]="+",En1[]="*",Sp0[]="╬",Sp1[]="#";//光标形式 (1个半角或全角字符)
const string OptionsForge="[DoNOTModify]Identifier:ClickingVersionsV2.7-By LZ-\n[WindowPosition](left,width,top,heigh)\n4\n-1 -1 -1 -1 \n[Trans;wOldColorAttrs;fsx;fsy;FocusVisible]\n5\n1 7 8 16 0 \n[EOUT:EoutDelay,IDDTFP]\n2\n7 25\n[WindowVersion](<=Win7:0;>Win7:1)\n1\n0 \n[ProcessName](Format:*.exe)\n-1\nclicking!.exe\n[FontSize](Format:X1 Y1 X2 Y2...)\n12\n3 5 5 8 6 12 8 16 8 18 10 20\n[FontInfo](Format:x1 y1 x2 y2...)\n12\n2663 517 1600 325 1327 208 2000 426 1000 142 800 125\n[FontIndex](Format:n1 0 n2 0...)\n12\n0 0 2 0 7 0 1 0 13 0 15 0 \n\n\n"
			,Version="ClickingVersionsV2.7\nCreated by Lz\n"
			,Licence="Licence:\n\nClicking_System()\nAbout{\nCreate:lz\nCoded:V1.0 to latest:lz,yyc\nDebug:V1.0 to latest:lz\nContributor/cooperation:yyc\nOther Attentions:\n//Run _example() to learn to use or ask the editor.\n//You can edit it as you like,but not in commercial usage.\n//I will be thankful if you discover any bug in it.\n\nPS:并没有装逼，都是自己翻的awa... \n\n--本程序(clicking.cpp;clicking.exe)以及教程(Note.txt，Tutor.txt)由lz原创。\n\n本作品采用知识共享署名-非商业性使用-相同方式共享 4.0 国际许可协议进行许可。\nThis project is licensed under the Creative Commons Attribution BY - NC - SA 4.0 international license agreement.\nmore information ：https://creativecommons.org/licenses/by-nc-sa/4.0/\n你可以进行改编，演绎，或者作为交流用途分享给他人，但请注明原作者，请勿用于商业用途，感谢配合！\n*本作品指文件夹下的所有cpp,exe和txt文件\n\n（其实我也只是编来玩，没有谋求利益的意思，这还可以被更多人认可，给更多程序员带来便利，为什么不呢？）\n联系作者：qq:1612162886(验证信息注明你是通过程序备注找到的)；洛谷ID：43845（是OIer就来luogu啊）\n}\n"
			,Note="Version:\n\nClickingVersionsV2.7(pre1)\nCreated by Lz\n\n----------------------------------------------------------------\n\n\n**完整版**\n\nUpdate:\n \nV0.1/*首版*/\ncongratulation!Clicking()函数诞生了，修复横竖不分显示现象，是Lz编的一个允许鼠标移动的C++程序哦！\nV1.0/*2019清明特辑*/\n添加了中文插件，并确定和记录了初始窗口位置和颜色。\nV1.1\nLz爆肝允许了窗口移动，修复了大部分BUG包括连点（但是他偷懒了），准备添加注释插件。\nV2.0/*2019清明特辑*/\n冒着被*的危险，成功添加注释插件！注释功能多样，还具备即时刷新功能，快来探索吧！\nV2.1\nSetConsoleTextAttribute(OPhandle,0x20|0x80)启动！允许五颜六色的标签啦！\nV2.2\n填充了标签，修复了超界漏洞（Debug程序越来越长了呵呵），还有让那个信息框识字（中文）。。。\n因为psy建议，添加了防止win10的闪电字幕出现卡字现象的插件，添加了win10稳定模式\nV2.3\n添加了窗口功能（当场吐血），现在知道xy轴混用的危害了（qwq抓了一星期臭虫）。另外抓了一个自添加注释就隐藏的bug，今天总算把它揪出来了——右移时一次跳两格。还精简了函数变量。。\n还有一个惊讶地发现，clicking已经快炸内存了……119688kb（116.87890625MB），但是用电脑管家加速后剩396kb（不足1MB），有种扎心感觉\nV2.3开始可以公布了~AWA~，因为楼主的功能已经差不多了（好像也没啥好打了）\nV2.4\nV2.3没有考虑Trans的情况于是发现了一大堆新bug，决定再肝一场。。。配置也多了很多，可以不用改内置就改设置啦\n决定2.3、2.4因为有bug，所以更改为2.5才公布。接下来还有V2.5版准备添加线程（速度嗖嗖的）\nV2.5\n成功添加多线程，虽然给操作带来了巨大麻烦和巨多bug（好像每一次都有很多），但是成功为其可游戏操作奠基。添加了拖动取消功能和锁定窗口（不允许拖动）功能。\n还特地肝了一个教程（lj）出来\n虽然有些人认为现在图形库那么发达，随便用个java、VC，或者c++装个EGE、Box2D都比他好（其实我也想学），但是怎么说呢，有个能面向大众（懒awa）的鼠标控制程序还是挺有创意的吧。。。\n如果有时间会将其转换为头文件，将正式公开V2.5[rep].rar\nV2.6\n进行了小改\n上次被我妈和刘姐姐测试了一下发现她们一拿到的反应——这个怎么用啊？(...)不过后来发现是因为中年人们使用鼠标习惯了用尖尖对准按钮，我们喜欢整个挪上去，所以进行了一些些改动。另外因为字体需要，爆肝（真的很惨）了一个活动字体变量fsx和fsy(我估计以后不会再添加这些恶心的东西了)，又花了一下午。另外修了一些小bug\n添加了精简版（其实就是删了几个注释。。。），为了时它体积小一些、使用没那么繁琐（但是改起来就繁琐了）\n本来8.1已经定稿了，后来想着觉得不对劲，8.18从重庆刚回来就干，总算把校准搞定了（我不会再弄他了。。。恶心。。。）另外完善了冻结窗口做法\nV2.7(UNFINISHED,pre1) \n初三第一次大测后初改 \n对速度进行了改进，（puts的速度实在太令人震惊了） \n而且深受格式之害，决定对整个程序重整（虽然对功能并没有什么改进） \n初三中考后二改\n发现了一个奇怪但是有用的字体函数，爆肝了两天啃了下来，现在clicking可以适应各种电脑字体了\n加了设置系统，打开程序时按住Tab可以进入（因为判断时间很短，建议打开之前先按住Tab）\n另外发现一个bug，我把所有的version（版本）写成了verson（打脸*INF）\nV2.7pre1最后完成于2020.7.27\n\n\n\n\n#define 敬请期待!  lz又偷懒了!\n\n"
			,Note_simple="**精简版**\n帮助:[2019.8.18]\n说白了，电脑怎么用就怎么用\n\n这个程序是一个用鼠标操纵的程序（仅此而已）。\n使用时将光标准心对准文字点击就能选择。\n如果其他窗口遮住了文字，可以拖动边框来移开，但部分窗口可能不允许。\n\n\n帮助只有那么多，后面的不用看了\n\nV2.7pre1-simple最后完成于2020.7.27\n\n\n当前版本	V2.7pre1-simple\n完成时间	2020.7.27\n\n\n#define 敬请期待! 楼主lz又偷懒了!\n\n"
			,Tutor="Help:[2019.7.19]注意:这个教程将只适用于clickingV2.7pre1，V2.7正式版将有较大改动\n这个程序就是一个可DIY的拥有鼠标控制功能的程序，你可以通过鼠标来控制程序，告诉他你想干嘛，而不再使用键盘\n教程稍稍冗(rǒng)长，请见谅！\n\n接下来是教程：如果你是制作者，请看①；如果你是使用者，请看②。\n\n\n\n\n\n\n\n\n①：\n	\n	想要编一个属于自己的鼠标控制程序吗？？赶紧往下看吧！\n	\n	本程序包含三个板块：1.菜单写入器；2.菜单执行（选择）器；3.区域选择器。\n	虽然程序里有很多别的干货，但是出于线程稳定和变量依赖考虑，不建议单独调用。\n	\n	☆数据公开：\n	string Msbl[]={'|','*','#','+','',' ','  ','│','┃','┆','┇','┊','┋','╳','□','■','█','▌','○','●','☆','★','?','?','?'},Msbt[]={'-','*','#','+','',' ','  ','─','━','┄','┅','┈','┉','╳','□','■','█','▄','○','●','☆','★','?','?','?'};\n	string Wdbdsl[]={'|','*','#','+',' ','!','?',''','.','+'},Wdbdst[]={'-','*','#','+',' ','!','?',''','.','='};\n	const char Ch0[]='┼',Ch1[]='╋',En0[]='+',En1[]='*',Sp0[]='╬',Sp1[]='#';//光标形式 (1个半角或全角字符)\n	\n	//颜色参考 \n	FOREGROUND_BLUE 0x1 蓝色字\n	FOREGROUND_GREEN 0x2 绿色字\n	FOREGROUND_RED 0x4 红色字\n	FOREGROUND_INTENSITY 0x8（加亮）\n	BACKGROUND_BLUE 0x10 蓝色背景\n	BACKGROUND_GREEN 0x20 绿色背景\n	BACKGROUND_RED 0x40 红色背景\n	BACKGROUND_INTENSITY 0x80（加亮） \n	\n	\n	★★★从这里开始就是如何编一个鼠标控制程序的过程了，跟着看下去包你看懂\n	★Step1.\n	1.void cwd(int wd,int wdbds,string wdtp,int cwl,int cwt,int cwr,int cwb)//window writing system窗口创建系统\n	2.void cw(int wd,int x,int y,string s,int ct,string cm,int cml,int cmt,int cmdl,int cmmd,int cmbds,int cl)//menu writing system菜单写入系统*\n	\n	\n	用法：cwd用于创建窗口，cw用于写入文字用于执行的菜单（也就是在屏幕上会显示的东西）\n	☆注意要先创建才能写入\n	解释:1:	wd：你的窗口编号（如果你只有一个窗口，你就写个1或者随便编个数）\n	wdbds:你的窗口边框形式（可以在上面的Wdbdsl和Wdbdst选一对，他们是一一对应的，填写他们是数组中的第几个）\n	wdtp:你的窗口标题（不用担心，程序已经帮你自动居中了，不过要注意不能超过窗口宽度）\n	cwl:你的窗口左坐标（你的窗口显示出来时，左边框的坐标）\n	cwt:你的窗口上坐标（全都同上）\n	cwr:右坐标（全都同上）\n	cwb:下坐标（全都同上）\n	2:	wd:你的窗口编号（你创建的窗口的编号）\n	x,y:文字的起始点坐标（是绝对坐标而不是相对窗口位置坐标）\n	s:你的文字内容\n	ct:文字值（就是你点击他的时候程序会返回一个什么值，如果想要他不返回（就是点它也没反应）就填0，不要填负数，因为负数是保留值）\n	cm:它的注释，就是你的鼠标停留在上面时会弹出一个小窗口显示着（如果不要就填''，然后接下来cml,cmt,cmdl,cmmd,cmbds都可以填0）\n	cml,cmt:注释的位置（绝对坐标），如果懒可以两个都填-1，程序会自动帮你分配\n	cmdl:你的鼠标停留在上面过多少时间才显示注释（单位ms）\n	cmmd:注释样式（0：默认；1:3D，2:闪电字幕（可以自己试试看））\n	cmbds:注释边框模式（可以从Msbl和Msbt里面选一对，和窗口边框样式规则一样）\n	cl:注释颜色（填写的时候可以填FOREGROUND_BLUE...也可以填0x1...，如果要混色的话在两个属性之间加个'|'）\n	★Step2.\n	1.void ent(int dl/*LEAST 50!*/,int wd,int ls,int wt)//menu choosing system starter菜单选择系统启动程序* \n	\n	用法：ent用于启动窗口选择主程序\n	解释:1:dl:刷新间隔时间（就是这个程序多久反应一次（。。。），单位ms，建议不小于50ms）\n	wd:窗口编号\n	ls:返回值可持续性（就是你点击了一个有效选择（就是前面的ct>0）以后，如果ls=1，那么菜单会返回值后继续运行，否则他会返回值后退出）\n	wt:是否启动线程（如果wt=1那么你要等这个菜单把值返回了，退出了，你的程序才能继续运行；如果wt=0，那么你的程序可以继续运行，而他会作为另外一个线程启动）\n	\n	★Step3.\n	了解了主程序用法之后，介绍几个变量：\n	1.Enabled(bool)		这个变量在选择程序运行时会变为true(1),退出时会变为false(0),但是，你可以在它运行时通过在你的主程序里更改Enabled为0来停止他\n			☆☆☆为了防止乱码，程序末尾一定要记得Enabled=0；否则你会在屏幕上看到一堆字符，而且严重的会导致内存泄漏\n	2.dqx,dqy(short int)	这两个是指当前光标所在的坐标（然而好像没什么用）\n	3.ww(string)		这个字符串指的是窗口的排列顺序（由上到下指0~size()-1），不过因为不能引起及时刷新，所以建议只是读取而不要更改\n	☆4.chv[](int[])	很多同学会疑问：既然是多线程，返回值我怎么获取？（我都为常规获取返回值的步骤感到恶心）不过别担心，我特地把所有返回值存进了这个数组里，既保障了分离运行，又可以可连续传值。\n			要提取返回值时，chv[0]是总个数（如果它的值是0那么代表没有返回值）,可以用这样的语句:while(chv[0]==0)Sleep(100)或者执行你自己的语句，跳出循环后写一个xxx=chv[chv[0]--(一定要记得--)]便可以了\n	☆5.ccv(int)		这个变量是指鼠标停留在的文字上的值（就算没有点下去也会取得到值），可以在循环中用if(ccv==...)执行\n			设计这个变量主要有一个很有用的用途：如果它的值是某个文字的值，那么马上用cw在旁边写一句话（提示用），可以有效迅速地反馈\n	☆6.tasks_sys[](int[])	因为多线程运行的时候如果你的程序在输出一个什么就会导致光标错位，所以想到了个办法\n		这里要介绍几个函数：\n		1.spclr(int wd)（用来显示窗口,wd是编号）\n		2.wcrr(int wd)（用来删除一个窗口，然后被删除的窗口就会永久消失，除非你重新创建写入）\n			因为有时候互动需要，可能要显示一个窗口或者删除一个窗口，所以添加了这个数组\n			如果你要显示一个窗口:tasks_sys[++tasks_sys[0]]=窗口编号\n			如果你要删除一个窗口:tasks_sys[++tasks_sys[0]]=窗口编号的相反数（就是加个负号）\n	7.movable_sys[](bool[])	这个程序是可以拖动窗口的（尽管有点慢），如果你想要禁止你的窗口被移动，你可以调用lock(你的窗口编号)或者movable_sys[编号]=1;要解锁的话只需再调用一遍lock(编号)或movable_sys[编号]=0即可\n 8.fsx,fsy	这两个变量是指控制台的字体大小（宽，长；单位像素），可以在属性-字体-大小 查看。因技术有限，没有添加自动校准系统，如果要改需要在程序里改\n	☆☆接下来的这些变量可以在options.txt修改（提示：options.txt会自动出现，无需理会）\n	8.ial,iar,iat,iab	这四个变量是指窗口（是控制台，就是整个程序进程的窗口）的左、宽、上、高（注意顺序），如果不想调（懒+1）填四个-1即可\n	9.Trans			(transparent 透明)，如果Trans=0，那么你将无法看到非焦点（就是在后面的）窗口。但是如果你的电脑严重卡顿，可以将其修改为0。\n	10.wOldColorAttrs	(Window Old Color Attributes 窗口默认颜色属性)建议不要改，默认7，除非你想看到一个红色、蓝色、绿色为背景的窗口？\n	11.EoutDelay		话说注释里面有个模式叫闪电字幕，而这个变量就是控制其输出快慢的（越大越慢），单位ms\n	12.IDDTFP		(并不是缩写，我乱编的 停止注释偏移)当闪电字幕在输出的时候，如果你不想看了怎么办？是不是挪开鼠标？对的，你只需要挪开IDDTFP像素就可以停止了（所以你知道这是干嘛的了吧）\n	13.WindowVerson		Win10用户注意了！\n			话说从Win10开始，微软肥肠的贴心，为中国客户的Win10电脑里面的（退格符）一次退两格（为了防止把中文字切成两半）。\n			但是这就把我的程序搞傻了，闪电字幕全都没掉，至今没找到两全之策。所以只能再加一个参数。如果你是Win10用户请把它改成1\n	★附.\n	前面介绍了有个函数叫区域选择器。不过因为这个函数我从V2左右就已经完成了，后来都没改过，本来不打算介绍。不过既然有点用处，也介绍一下。\n	void cost(int left,int top,int right,int down,int &px,int &py)//area selecting区域选择* \n	\n	用法：屏幕会变黑，你需要在上面点上一下，就会显示十字准星，接着程序会返回你选择的坐标。可以用于区域选择\n	解释：	left,top;right,down:选择的区域（如果超过这两个点那么他就不会显示十字准星）\n	px，py：这两个变量是用于传回的，不需要有传入值，否则会被覆盖\n	--由LZ编写 \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n②：\n	要使用一个鼠标控制程序很简单，几乎不需要用到键盘（如果你是编写者也建议你看一下） \n	首先，你要根据程序提示，等到你看到你的鼠标下有一个'+'时代表你可以用鼠标了（如果编写者自定义了光标则另当别论） \n	你如果要选择一个选项，你只需要点击那个文字即可。\n	如果你想知道某个选项的帮助，1.把鼠标在上面停留一会看是否会弹出一个窗口（注释）；\n	2.看看把鼠标停在上面时会不会在旁边（或者另一个窗口）显示一个什么 \n	最后：这个程序好不好用其实取决于编写他的人，请遵照程序的提示。\n	 --由LZ编写 \n	 \n\n\n";
const int Ath[15]={67,79,68,69,68,32,66,89,58,76,105,110,90,101,46};
COORD fontsize[55];
char* fileName=const_cast<char*>("options.txt");
//空间声明 
struct CWCN{int dl,wd,ls;}tcwcn;/*线程传递数据 NEEDED*/ 
int Options[525][135],Optionstot,Optionstringtot;//设置板块
string Optionstring[105];/*options.txt<-VerVerify NEEDED*/ 
char CTitle[1005];//程序窗口标题 
string ww="";//窗口顺序
int mxl,mxh;/*msgbox() NEEDED*/
int Enabled;//线程是否启动
int cfsx,cfsy,cindex;//(current-)当前字体大小 
char cc;//全局getch() 
//API SYMBOL
HWND hwnd=GetForegroundWindow();//主窗口句柄 
HWND Chwnd=GetConsoleWindow();//控制台句柄 
HANDLE OPhandle = GetStdHandle(STD_OUTPUT_HANDLE);//输出句柄 
CONSOLE_SCREEN_BUFFER_INFO csbi;//窗口缓冲区信息 
RECT rect;//窗口位置 
LONG wOldLong=GetWindowLong(hwnd, GWL_STYLE);//窗口样式，用于隐藏标题 
CONSOLE_CURSOR_INFO CursorInfo;//光标信息，用于隐藏光标 
COORD buffersize={80,255};//缓冲区大小 


//Function declare
int INTSc(int linenum, int number);
bool Pr(char* fileName, int linenum,string ot);
void gotoxy(int x,int y);
bool Form_load();
bool VerVerify();


//PRELOAD 请勿调换顺序！ 
bool _VerVerify=VerVerify();//数据检查和读取 
//常量 
const int EoutDelay=INTSc(3,1),IDDTFP=INTSc(3,2),FV=INTSc(2,5),//闪电字幕延时(!>5) 注释终止偏移  窗口累积最大个数
		  WDD=15,//窗口数量 
		  WDLMT=205,//窗口大小（长边） 
		  Trans=INTSc(2,1),wOldColorAttrs=INTSc(2,2),//非焦点窗口可见性  默认窗口文字颜色 
		  WinVer=INTSc(4,1),//系统版本（用于修复Win10中文\b的双倍回格） 
		  fsx=INTSc(2,3),fsy=INTSc(2,4),//字体大小 宽*长pixel
		  bvisible=INTSc(2,5);
//主系统 
short int 
/*基础*/			cz_sys[WDD][WDLMT][WDLMT],cl_sys[WDD][WDLMT][WDLMT],
/*注释系统*/		cml_sys[WDD][WDLMT][WDLMT],cmt_sys[WDD][WDLMT][WDLMT],cmmd_sys[WDD][WDLMT][WDLMT],cmdl_sys[WDD][WDLMT][WDLMT],cmbds_sys[WDD][WDLMT][WDLMT],
/*由主线程加入任务*/tasks_sys[WDD*3],
/*当前位置是否更新*/crif_sys[WDLMT][WDLMT],
/*该窗口是否可移动*/movable_sys[WDD],
/*窗口系统基础*/	wdl_sys[WDD],wdt_sys[WDD],wdr_sys[WDD],wdb_sys[WDD],
/*返回值储存*/		chv[WDLMT*WDLMT],
/*预读鼠标下文字*/	ccv,
/*筛去空格*/		ccvn,
/*当前光标位置*/	dqx,dqy,
/*鼠标像素位置*/	ial=INTSc(1,1),iar=INTSc(1,2),iat=INTSc(1,3),iab=INTSc(1,4),
/*边框宽度标题宽度*/BROAD=8,TOPBROAD=30;
string 
/*字符库*/	c_sys[WDD][WDLMT][WDLMT],
/*注释库*/	cm_sys[WDD][WDLMT][WDLMT],
/*窗口标题*/wdtp_sys[WDD];

bool _Form_load=Form_load();//全局预加载 


//basic plugins基础插件 
inline int INTSc(int linenum, int number)//文件读 
{
	if (_VerVerify)
	return Options[linenum][number];//From the Options[][];
	
	
	ifstream in(fileName);
	int ans;string data;
	for (int i=1;i<linenum&&in.peek()!=EOF;i++)getline(in,data);
	for (int i=1;i<=number&&in.peek()!=EOF;i++)in>>ans;
	in.close();
	return ans;
}
inline bool Pr(char* fileName, int linenum,string ot)//文件写 
{
	if (fileName=="*A")
	{
		ofstream out (::fileName,ios::out);
		out<<OptionsForge;
		return out.is_open();
	}
	
	ifstream in(fileName);
	char data[511][256];int cnt=1;
	while (in.peek()!=EOF)
	{
		in.getline (data[cnt],255);
		cnt++;
	}
	in.close();
	ofstream out (fileName,ios::out);
	for (int i=0;i<ot.size();i++)
	data[linenum][i]=ot[i];
	data[linenum][ot.size()]='\0';
	for (int i=1;i<=cnt;i++)
	out<<data[i]<<endl;
	out.close();
	return true;
}
inline string HEXR(int k) //dec->hex
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
inline string StCh(int k)//int->string
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

//advanced plugins高级插件 
inline void gotoxy(int x,int y)//cursor position setting光标位置设置 
{
	SetConsoleCursorPosition(OPhandle,(COORD){x,y});
}
void lr()//fast cls光速清屏 
{
	SMALL_RECT scroll;
	COORD newCursorPointer;
	CHAR_INFO ciFill;
	
	if(!GetConsoleScreenBufferInfo(OPhandle, &csbi))
		return;
	
	scroll.Left = 0;
	scroll.Top = 0;
	scroll.Right = csbi.dwSize.X;
	scroll.Bottom = csbi.dwSize.Y;
	newCursorPointer.X = 0;
	newCursorPointer.Y = -csbi.dwSize.Y;
	ciFill.Char.UnicodeChar = L' ';
	ciFill.Attributes = csbi.wAttributes;
	ScrollConsoleScreenBufferW(OPhandle, &scroll, NULL, newCursorPointer, &ciFill);
	newCursorPointer.Y = 0;
	SetConsoleCursorPosition(OPhandle, newCursorPointer);
}
struct CONSOLE_FONT//FontSizer needed
{
 DWORD index; 
 COORD dim;
 };
int FindFont(int fsx,int fsy)//FontSizer needed
{
	for(int i=1;i<=Options[6][0];i+=2)
	if (Options[6][i]==fsx&&Options[6][i+1]==fsy)
	return i;
	TDRed();
	printf("[FindFont]Warning:%dx%d FontID NO FOUND\n",fsx,fsy);
	TN();
	return -1;
}
void FontSizer()	//adjust font size调整字体大小
{ 
		HMODULE hKernel32 = GetModuleHandle("kernel32");
		typedef BOOL (WINAPI *PROCSETCONSOLEFONT)(HANDLE, DWORD);
		PROCSETCONSOLEFONT SetConsoleFont = (PROCSETCONSOLEFONT)GetProcAddress(hKernel32,"SetConsoleFont");
	
	puts ("---Query Current Font");
	Rst:;
	system("if exist tmp.txt erase tmp.txt /q");
	system("reg QUERY HKCU\\Console /v FontSize >tmp.txt");
	fstream in("tmp.txt",ios::in);
	char tmp[155];
	string data,tmps;
	int o=0;
	{
		while((cc!='0'||in.peek()!='x')&&in.peek()!=EOF)cc=in.get();
		if (in.peek()==EOF)
		{
			TD();puts("E2:无法获取注册表字体信息");TN();
			if (MessageBox(Chwnd,"E2:无法获取注册表字体信息","Process Erruption",MB_RETRYCANCEL)==IDRETRY)goto Rst;
		}
		in.get();
		in>>data;
		if (data=="50003")cfsx=3,cfsy=5;
		if (data=="80005")cfsx=5,cfsy=8;
		if (data=="c0006")cfsx=6,cfsy=12;
		if (data=="100008"||data=="0")cfsx=8,cfsy=16;
		if (data=="120008")cfsx=8,cfsy=18;
		if (data=="14000a")cfsx=10,cfsy=20;
		cindex=Options[8][FindFont(cfsx,cfsy)];
	}
	in.close();
	system("if exist tmp.txt erase tmp.txt /q");
	printf("Current Font Size:%d x %d(0x%s)\n",cfsx,cfsy,data.c_str());
	
	//获取系统的字体大小 
	if (Options[8][0]==0)
	{
		TD();puts("检测到字体信息未添加");TN();
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
		GetConsoleFontInfo(OPhandle, 0, nNumFont, pFonts);
		for(int i=0;i<nNumFont;i++)
		{
			dvx=pFonts[i].dim.X*1.000/cfsx*100;
			dvy=pFonts[i].dim.Y*1.000/cfsy*100;
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
		Pr(fileName,24,tmps);
		tmps="";
		
		for (int i=1;i<=Options[8][0];i++)
		tmps=tmps+StCh(Options[8][i])+" ";
		Pr(fileName,25,tmps);
		tmps="";
		puts ("---Restoring Local Font Info完成");
	}
	for (int i=1;i<=Options[6][0];i+=2)
	if (Options[6][i]==Options[2][3]&&Options[6][i+1]==Options[2][4])
	{
		SetConsoleFont(OPhandle,Options[8][i]);
		cindex=Options[8][i];
		break;
	}
//	system("pause");
	return;
	/*
	//以下是旧版本(本来是当心坠物需要临时编的) 
	//在options里面更改fsx和fsy可以改变，但是要重新启动，不是特别需要就算了吧... 
	
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
		if(data.find(HEXR(fsy*65536+fsx))!=string::npos)
		{
			o=1;
			break;
		}
	}
	in.close();
	system("del tmp.txt");
	if(o==0)
	{
		puts("\n请允许修改注册表，这是为了使字体适合本程序设置\n如要更改，请更改options.txt中的fsx和fsy");
		tmps="reg ADD HKCU\\Console /v FontSize /t REG_DWORD /f /d "+StCh(fsy*65536+fsx);
		system(tmps.c_str());
		tmps="if not exist \".\\"+Optionstring[1]+"\" echo 请不要改动exe的名字！请将其改回："+Optionstring[1]+"，否则无法启动";
		system(tmps.c_str());//警告 
		tmps="start \""+Optionstring[1]+"\" \""+Optionstring[1]+"\"";
		system(tmps.c_str());//重启 
		exit(0);
	}
	system("reg ADD HKCU\\Console /v FontSize /t REG_DWORD /f /d 0x00100008");
	return;*/
}
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
bool SetSystem()
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
		TN();lr();
		//digital refresh
		tmps="目前设置"+StCh(Options[1][1])+" "+StCh(Options[1][2])+" "+StCh(Options[1][3])+" "+StCh(Options[1][4]);
		strncpy(menu[1][1], tmps.c_str(), tmps.length() + 1);
		tmps="目前设置 ID"+StCh(cindex);//+"."+StCh(Options[6][cindex])+" "+StCh(Options[6][cindex+1])
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
			gotoxy(30,i);
			puts(menu[cs][i]);
		}
		gotoxy(0,23);
		TDCyan();puts("↑↓←→切换\tEnter选择\tBackspace保存并返回\tEsc不保存返回");TN();
		//HL
		if (!ext&&cs!=0)
		{
			gotoxy(0,cs);
			HL();
			puts(menu[cs][0]);
			TN();
		}
		if (ext)
		{
			gotoxy(30,0);
			puts(menu[cs][0]);
			gotoxy(30,css);
			HL();
			puts(menu[cs][css]);
			TN();
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
					GetWindowRect(hwnd,&rect);
					Options[1][1]=rect.left;
					Options[1][2]=(rect.right-rect.left)/Options[2][3];//fsx
					Options[1][3]=rect.top;
					Options[1][4]=(rect.bottom-rect.top)/Options[2][4];//fsy
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
//					printf("%d %d x %d\n",cindex,cfsx,cfsy);system("pause");
					for(int i=1;i<=Options[8][0]-2;i+=2)
					if (cindex==Options[8][i])
					{
						cindex=Options[8][i+2];
						break;
					}
					SetConsoleFont(OPhandle,cindex);
				}
				if (css==3)
				{
//					printf("%d %d x %d\n",cindex,cfsx,cfsy);system("pause");
					for(int i=1+2;i<=Options[8][0];i+=2)
					if (cindex==Options[8][i])
					{
						cindex=Options[8][i-2];
						break;
					}
					SetConsoleFont(OPhandle,cindex);
				}
//				printf("%d !\n",cindex);cc=getch();
				if (css==4)
				{
					cindex=Options[8][FindFont(cfsx,cfsy)];
					SetConsoleFont(OPhandle,cindex);
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
				gotoxy (0,21);
				HL();puts("请输入本程序的名称(*.exe)，无需双引号");TN();
				getline(cin,tmps);
//				很遗憾，c++没有收录libcomdlg32.a库文件，所以无法实现了 
//				虽然可以手动添加，不过为了不给后来的编辑添加麻烦还是算了 
//				TCHAR szBuffer[MAX_PATH] = {0};   
//				OPENFILENAME ofn= {0};   
//				ofn.lStructSize = sizeof(ofn);   
//				ofn.hwndOwner = Chwnd;   
//				ofn.lpstrFilter = _T("本程序的EXE文件(*.exe)\0*.exe\0");//要选择的文件后缀   
//				ofn.lpstrInitialDir = _T("%userprofile%\\desktop");//默认的文件路径   
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
		gotoxy(0,23);
		HL();puts("保存设置中...");TN();
		//1Winp
		tmps="";
		for (int i=1;i<=4;i++)
		tmps=tmps+StCh(Options[1][i])+" ";
//		printf("[%s]%d\n",tmps.c_str(),Options[1][1]);
		Pr(fileName,4,tmps);
		//2Fonts
		tmps="";
		for(int i=1;i<=Options[8][0];i+=2)
		if (cindex==Options[8][i])
		{
			Options[2][3]=Options[6][i];
			Options[2][4]=Options[6][i+1];
			break;
		}
		for (int i=1;i<=5;i++)
		tmps=tmps+StCh(Options[2][i])+" ";
		Pr(fileName,7,tmps);
		//3Winv
		tmps="";
		for (int i=1;i<=1;i++)
		tmps=tmps+StCh(Options[4][i])+" ";
		Pr(fileName,13,tmps);
		//4Proc
		Pr(fileName,16,Optionstring[1]);
		
		Sleep(200);
	}
	else 
	{
		lr();
		return 0;
	}
	lr();
	TDCyan();puts("Version Verify->Set System完成");TN();
	return 1;
}
bool VerVerify()//设置检查读取 
{
	int Ln=2;
	int ans;
	char anss[128],ccc;
	puts ("Version Verify");
	HL();puts("请允许读写、批处理和注册操作");
	puts ("所有操作经多方测试，可以信任~\n");TN();
	//Version Verify&Options Creating
	system("attrib -r -a options.txt");
	ifstream in("options.txt");
	in.getline(anss,128);
	in.close();
	if (anss!=OptionsForge.substr(0,51))
	{
		TD();
		puts ("The Options(options.txt) have not be initialize or it is broken!\n程序设置未初始化");
		HL();
		cout<<"Please RESTART LATER\n请稍候重启该程序！\n";
		TN();
		cout<<"\nVERSION:"<<Version<<"\nReWriting...\n";
		Rst:;	//Reset Mark 
		if(!Pr((char*)"*A",0,""))
		{
			TDRed();
			if (MessageBox(Chwnd,"E1:初始化错误","Process Erruption",MB_RETRYCANCEL)==IDRETRY)
			goto Rst;
			cout<<"Initialize faild\a\t[Any key to continue]\n请联系lz询问原因";
			char cc=getch();
			exit(0);
		}
		TDGreen();
		cout<<"Initialize succeed\t[Any key to continue]\n[任意键继续]\t\n\n";
//		char cc=getch();
		TN();
//		exit(0);
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
	return 1;
}
bool Form_load()
{
	puts("Process Preload");
	//API类 
	//有些电脑的codepage不对，所以显示不了中文，但是改过一次以后都不用了 
	puts("--Codepage");
//	system("chcp 936");
	puts("--Buffer Size");
	SetConsoleScreenBufferSize(OPhandle,buffersize);
	puts("--Font Sizer");
	FontSizer();//调整字体大小，可禁用 
	puts("--Screen Position");
	GetWindowRect(hwnd,&rect);
	if(ial==-1) ial=rect.left;
	if(iar==-1) iar=rect.right;
	else
	{
		iar+=4;
		iar*=cfsx;
		iar+=ial;
	}
	if(iat==-1) iat=rect.top;
	if(iab==-1) iab=rect.bottom;
	else
	{
		iab+=4;
		iab*=cfsy;
		iab+=iat;
	}
//	printf("%d %d %d %d\n",ial,iar,iat,iab);
	ChWp(ial,iat,iar-ial,iab-iat);//假如options中的窗口位置不是-1，那么移动窗口到指定位置 
	//移除 快速编辑 插入 模式
	puts("--Insertion Mode");
	DWORD mode;
	GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;
	mode &= ~ENABLE_INSERT_MODE;
	mode &= ~ENABLE_MOUSE_INPUT;
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), mode);
	puts("--Cursor Info");
	GetConsoleCursorInfo(OPhandle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible=bvisible;
	SetConsoleCursorInfo(OPhandle, &CursorInfo);
	puts("--Buffer Info");
	GetConsoleScreenBufferInfo(OPhandle,&csbi);//获取缓冲信息 
	puts("--Window Title");
	GetWindowText(hwnd, CTitle, 1000);//获取窗口标题 
	puts("API类完成");
	//CLICKING类 
	for(int w=0;w<WDD;w++)//预处理背景 
	for(int i=0;i<WDLMT;i++)
	for(int j=0;j<WDLMT;j++)
	{
		cl_sys[w][i][j]=wOldColorAttrs;
		c_sys[w][i][j]=" ";
	}
	puts("C类完成\n");
	lr();
	return 1;
}

//INITIALIZE COMPLETED----------------------------------------------------------------
//7.23EditMArk

void eout(string s,int sx,int sy)//Thank YYC for this code--lighting subtitles!闪电字幕 
{
	int i=0,m=0,p=EoutDelay;//调速 
	POINT pt;//这个用于检测鼠标是否已经离开了一定范围（临时中断）
	bool TKmoved;//这个用于检测鼠标是否点击（也要临时中断） 
	char sds;
	sx++;//sx，sy这两个参数是为了配合msgbox的指定位置输出 ,但是sx有1单位偏移 
	gotoxy(sx,sy);
	TKmoved=KEY_DOWN(MOUSE_MOVED);
	GetCursorPos(&pt);
	int nwpx=pt.x,nwpy=pt.y;
	while(i<s.size() && !( max(abs(pt.x-nwpx),abs(pt.y-nwpy))>IDDTFP || KEY_DOWN (MOUSE_MOVED)!=TKmoved))
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
			if (!kbhit())Sleep(p);
			cout<<"\b┃";
			if (!kbhit())Sleep(p);
			if (WinVer)cout<<"\b ▊";
			else cout<<"\b\b ▊";
			if (!kbhit())Sleep(p);
			if (kbhit() && i%3==0)sds=getch();
			if (s[i]<0)
			{
				cout<<"\b\b\b"<<s[i]<<s[i+1];
				i++;
			}
			else
			cout<<"\b\b\b"<<s[i];
		}
		i++;
		if (!kbhit())Sleep(p);
		Sleep(p);
		GetCursorPos(&pt);
	}
	cout<<" \b";
	return;
}
void cost(int left,int top,int right,int down,int &px,int &py)//area selecting区域选择* 
{
	//这是clicking的最早期版本，原来用于选择一个范围，作为窗口的大小，只是暂时不需要了 
	POINT pt;int o=0;
	system("mode con cols=175 lines=50");
	ChWp(0,0,1600,900);
	while(!o)
	{
		while(KEY_DOWN(MOUSE_MOVED))
		{
			system("cls");GetCursorPos(&pt);
			if (pt.x/fsx<left || pt.y/fsy<top || pt.x/fsx>right || pt.y/fsy>down)continue;
			px=pt.x/fsx,py=pt.y/fsy;
			gotoxy (pt.x/fsx-2,pt.y/fsy-2);
			cout<<Sp0;
			gotoxy(pt.x/fsx-2,pt.y/fsy-1);
			cout<<pt.x/fsx<<"*"<<pt.y/fsy;
			o=1;Sleep(50);
			gotoxy(pt.x/fsx-2,pt.y/fsy-2);cout<<"  ";
			gotoxy(pt.x/fsx-2,pt.y/fsy-1);cout<<"        ";
		}
	}
	system("cls");cout<<"select area:"<<px<<"*"<<py<<endl;//px,py是选择的范围 
	Sleep(1000);
	ChWp(rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top);
	return;
}
void clr(int sx,int sy,int ex,int ey,int wd)
//explain:from(sx,sy)to(ex,ey)
{
	int bs;
	string tmp;
	for (int i=sx;i<=ex;i++)
	{
		gotoxy(sy,i);
		for (int j=sy;j<=ey;j++)
		{
			bs=0;
			if (Trans)
			for (int ii=0;ii<ww.size();ii++)
			if (j>=wdl_sys[ww[ii]-'0'] && j<=wdr_sys[ww[ii]-'0'] && i>=wdt_sys[ww[ii]-'0'] && i<=wdb_sys[ww[ii]-'0'])//判断当前位置属于窗口
			//wd 焦点窗口，bs当前位置窗口 
			{
				bs=ww[ii]-'0';
				break;
			}
			if (bs==0)bs=wd;
			if (cz_sys[bs][i][j]!=-1)//这是个全角字符 
			{
				SetConsoleTextAttribute (OPhandle,cl_sys[bs][i][j]);
				printf ("%s",c_sys[bs][i][j].c_str());
				if (c_sys[bs][i][j].size()==2)j++;
			}
			else
			{
				SetConsoleTextAttribute (OPhandle,cl_sys[bs][i][j-1]);
				printf ("\b%s",c_sys[bs][i][j-1].c_str());
			}
		}
	}
	gotoxy(0,0);
	return;
}
//4.10EDITMARK
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
				gotoxy(dqx,dqy);
				if(c_sys[bs][dqy][dqx].size()>1)
				cout<<Ch1;
				else cout<<En1;
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
				{
					if(c_sys[bs][dqy][dqx].size()>1)
					cout<<Ch1;
					else cout<<En1;
				}
			}
		}
		else
		{
			SetConsoleTextAttribute(OPhandle,(WORD)cl_sys[bs][dqy][dqx]);
			gotoxy(dqx,dqy);
			if(FV==0)
			{
				cout<<c_sys[bs][dqy][dqx];
			}
			else
			{
				if(c_sys[bs][dqy][dqx].size()>1)
				cout<<Ch0;
				else cout<<En0;
			}
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
//system("mode con cols=80 lines=25");//Warn 
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
	 	of<<Licence;
	 	of<<"\n"<<Version;
	 	of.close();
	 	system("Note.txt");
	 }

  //mains?[with both(a,b)]
 }
 Enabled=0;
 system("cls");
 
}
int main(int argc,char* argv[])
{ 
//检测滚轮动作 
//当鼠标移出窗口外时挂起进程
//连续点击如果切换窗口 
//	_example();
//	return 0;
	cout<<"这是样例程序！\n(当前字体)"<<fsx<<" "<<fsy<<endl;
	cout<<"获得更多帮助请按 H \n观看实例请按 E \n";
	char cc=getch();
	if(cc=='H'||cc=='h')
	{
		ofstream of("Note.txt");
	 	of<<Note;
	 	of<<"\n"<<Version;
	 	of.close();
	 	of.open("Licence.txt");
	 	of<<Licence;
	 	of.close();
	 	of.open("Tutor.txt");
	 	of<<Tutor;
	 	of.close();
	 	system("start \"\" Tutor.txt");
	 	system("start \"\" Licence.txt");
	 	system("start \"\" Note.txt");
	}
	if(cc=='E'||cc=='e')
	{
		_example();
		for(int i=1;i<=5;i++)wcrr(i); 
	}
 return 0;
}
