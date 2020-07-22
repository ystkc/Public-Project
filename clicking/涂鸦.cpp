
/**----------------------------------------------------------------
Clicking_System()	**精简版** ·涂鸦 
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

--本程序(clicking)由linze原创，未经许可不得外传，谢谢合作！
如果你需要将其作为礼物或者仅仅作为交流用途发给别人，你只需告诉作者即可。
（其实我也只是编来玩，没有谋求利益的意思，这还可以被更多人认可，为什么不呢？）
联系作者：qq:1612162886；洛谷ID：43845（不要看了，蒟蒻一枚）
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
#define lInitial() (SetWindowLong(hwnd, GWL_STYLE, wOldLong))
#define ChWp( Px, Py, Cx, Cy) (MoveWindow(hwnd,Px,Py,Cx,Cy,TRUE))
#define StWp( Px, Py) (SetWindowPos(hwnd, HWND_NOTOPMOST, Px, Py, 0, 0,SWP_NOSIZE))
#define lSuspend() (SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & WS_CAPTION))
#define lFreeze() {SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_CAPTION);RECT nowr;GetWindowRect(hwnd,&nowr);StWp(rect.left,rect.top+1);StWp(rect.left,rect.top);ChWp(rect.left,rect.top+50,rect.right-rect.left,rect.bottom-rect.top-50);ChWp(rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top);}
#define chck( k1, k2) ((k1&0x80)&&(k2&0x80))

//CSYS NORMAL SYMBOL!--------------------------------
//!!!:请勿调换变量声明顺序，否则后果自负! 
//struct csysb{int k,wd;};
struct CWCN{int dl,wd,ls;}tcwcn;

const char Cnp=''/*(char)1:USE IT if you need to recognize the next two char as a chinese*/,Endnp='}';
string Msbl[]={"|","*","#","+",""," ","  ","│","┃","┆","┇","┊","┋","╳","□","■","█","▌","○","●","☆","★","?","?","?"},Msbt[]={"-","*","#","+",""," ","  ","─","━","┄","┅","┈","┉","╳","□","■","█","▄","○","●","☆","★","?","?","?"};
string Wdbdsl[]={"|","*","#","+"," ","!","?","'",".","+"},Wdbdst[]={"-","*","#","+"," ","!","?","'",".","="};
const char Ch0[]="┼",Ch1[]="╋",En0[]="+",En1[]="*",Sp0[]="╬",Sp1[]="#";//光标形式 (1个半角或全角字符)
const string OptionsForge="[DoNOTModify]Identifier:ClickingVersonsV2.6-By LZ-\n[WindowPosition](left,width,top,heigh)\n4\n-1 -1 -1 -1\n[Trans;wOldColorAttrs]\n2\n1 7\n[EOUT:EoutDelay,IDDTFP]\n2\n7 25\n[WindowVerson](<8:0;>7:1)\n1\n0\n"/*0 0 677 459*/,Verson="ClickingVersonsV2.6\nCreated by Lz\n",Licenses="License:\n \n ----------------------------------------------------------------\n Clicking_System()\n About{\n Create:lz\n Coded:V1.0 to latest:lz\n Debug:V1.0 to latest:lz\n Other license:\n //The first run will be interrupted because of the initialize of 'options.txt'.\n //Run _example() to learn to use or ask the editor.\n //You can edit it as you like,and you'd better tell lz about it.\n //I will be thankful if you discover any bug in it.\n \n PS:并没有装逼，都是自己翻的awa... \n \n --本程序(clicking)由linze原创，需要外传请通知作者，感谢配合！\n 如果你需要将其作为礼物或者仅仅作为交流用途发给别人，你只需告诉作者即可。\n （其实我也只是编来玩，没有谋求利益的意思，这还可以被更多人认可，为什么不呢？）\n 联系作者：qq:1612162886；洛谷ID：43845（不要看了，蒟蒻一枚）\n }\n \n \n Help:[2019.7.19]\n 本程序为精简版，如果想获得更多帮助或者获取完整版，可以联系Lz-qq1612162886;\n \n 当前版本	V2.6-s\n 完成时间	2019.7.31\n \n \n \nUpdate:\n \n --本程序(clicking)由linze原创，需要外传请通知作者，感谢配合！\n  \n 所有版本：\n V0.1/*首版*/\n V1.0/*2019清明特辑*/\n V1.1\n V2.0/*2019清明特辑*/\n V2.1\n V2.2\n V2.3\n V2.4\n V2.5\n V2.6\n \n V2.6最后完成于2019.7.31\n \n \n #define 敬请期待! 楼主lz又偷懒了!\n \n";
const int Ath[15]={67,79,68,69,68,32,66,89,58,76,105,110,90,101,46};

int WinVer,Enabled;//输入数据，总数，Windows版本，线程是否启动，返回数据
int mxl,mxh;/*msgbox() NEEDED*/
string ww=""/*当前窗口顺序*/;
char cc;//调试getch()用 

//Function declare
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


const int EoutDelay=7,IDDTFP=25,WDD=15,WDLMT=205,Trans=0,wOldColorAttrs=7;//闪电字幕延时(!>5) 注释终止偏移  窗口累积最大个数 窗口数组大小  非焦点窗口可见性  默认窗口文字颜色 

short int cz_sys[WDD][WDLMT][WDLMT],cml_sys[WDD][WDLMT][WDLMT],cmt_sys[WDD][WDLMT][WDLMT],cmmd_sys[WDD][WDLMT][WDLMT],cmdl_sys[WDD][WDLMT][WDLMT],cmbds_sys[WDD][WDLMT][WDLMT],cl_sys[WDD][WDLMT][WDLMT],tasks_sys[WDD*3],crif_sys[WDLMT][WDLMT],movable_sys[WDD];
short int wdl_sys[WDD],wdt_sys[WDD],wdr_sys[WDD],wdb_sys[WDD],chv[WDLMT*WDLMT],ccv,ccvn,dqx,dqy;
string c_sys[WDD][WDLMT][WDLMT],cm_sys[WDD][WDLMT][WDLMT],wdtp_sys[WDD];
int ial=-1,iar=-1,iat=-1,iab=-1,fsx=8,fsy=16;
int wl=ial/8,wr=iar/8,wt=iat/16,wb=iab/16;
const int lm=sqrt(sizeof(c_sys)/8/WDD)-5;
bool _Form_load=Form_load();



//LOADING AREA-------------------------------------
string hs="■";
short int COLOR=0;

inline int INTSc(char* filename,int linenum, int number)
{
//	return Options[linenum][number];//From the Options[][];
///*
	ifstream in(filename);
//	if(!NoUnicode)
//	{
//		ifstream CHKN(filename);
//		wchar_t chkn;
//		CHKN.read((char *)(&chkn), 2);
//		if(chkn==0xFFFE||chkn==0xFEFF){cout<<"UNC!";return -1;}
//	}
	int ans;string data;
	for(int i=1;i<linenum;i++)getline(in,data);
	for(int i=1;i<=number;i++)in>>ans;
	in.close();
	return ans;
//*/
}
inline bool Pr(char* fileName, int linenum,string ot)
{
	if(fileName=="*A")
	{
		ofstream out("options.txt",ios::out);
		out<<OptionsForge;
		return out.is_open();
	}
	
	fstream io(fileName,ios::in);
	char data[511][128];int cnt=0;
	while(!io.eof() )
	{
		cnt++;
		io.getline(data[cnt],128);
	}
	io.close();
	ot.copy(data[linenum],ot.size(),0);
	io.open(fileName,ios::out);
	for(int i=1;i<=cnt;i++)
	io<<data[i];
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
	WinVer=0;
	GetWindowRect(hwnd,&rect);
	if(ial==-1) ial=rect.left;
	if(iar==-1) iar=rect.right;
	if(iat==-1) iat=rect.top;
	if(iab==-1) iab=rect.bottom;
	ChWp(ial,iat,iar-ial,iab-iat);
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
	}//system("pause");
	for(int i=1;i<=mxh;i++)
	{
		gotoxy(mxl+sx+1,sy+i);
		printf("%s",l.c_str());
	}//system("pause");
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
	}//system("pause");
	if(md==2)
	{
			if(t.size()==2)mxl*=2;
		for(int i=1;i<=mxh;i++)
		{
			gotoxy(sx+1+max(tpo-2,0),sy+i);
//			if(t.size()==1)mxl/=2;
			for(int i=1;i<=mxl&&i+sx+1<iar-30;i++)printf(" ");
//			for(int j=1;j<=mxl*2-max(0,tpo-3);j++)printf(" ");
		}//system("pause");
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
	DD();
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
	if(Trans==1)
	{
		for(int i=ww.size()-1;i>=0;i--)if(ww[i]-'0'!=wd)spclr(ww[i]-'0');
	}
	gotoxy(1,1);
	POINT pt;int l=0,t=0,r=0,b=0,cpst=0,cmdl=0,tdqx,tdqy;bool TKmoved=0;
	GetCursorPos(&pt);GetWindowRect(hwnd,&rect);
	ial=rect.left;
	iar=rect.right;
	iat=rect.top;
	iab=rect.bottom;
	wl=ial/fsx,wr=iar/fsx-1,wt=iat/fsy,wb=iab/fsy-1;
	int bs=wd,o=0;
	for(int i=0;i<ww.size();i++)
	if(ww[i]-'0'==wd){ww.erase(i,1);ww.insert(0,1,(char)wd+'0');o=1;break;}
	if(!o)return NULL;
	Enabled=1;
	while(Enabled&&(pt.y<iat||pt.y>iab-fsy*4||pt.x<ial||pt.x>iar-fsx*4))Sleep(dl*2),GetCursorPos(&pt);
	goto A;
	while(Enabled)
	{
		sprf();
		Sleep(dl-cpst);cpst=0;
		GetWindowRect(hwnd,&rect);
		if(ial!=rect.left||iar!=rect.right||iat!=rect.top||iab!=rect.bottom)
		{
			ial=rect.left;
			iar=rect.right;
			iat=rect.top;
			iab=rect.bottom;
			wl=ial/fsx,wr=iar/fsx-1,wt=iat/fsy,wb=iab/fsy-1;
		}
		GetCursorPos(&pt);
		pt.y-=max(0,3-fsx)*fsy;
		pt.x-=max(0,5-fsy)*fsx;
		while(pt.y<iat||pt.y>iab-fsy*4||pt.x<ial||pt.x>iar-fsx*4)Sleep(dl*2),GetCursorPos(&pt);
		if(cz_sys[bs][dqy][dqx]==-1)dqx--,pt.x-=fsx;//	gotoxy(dqx+1,dqy+1);cout<<pt.y/fsy-2-wt<<"?"<<dqy;
		if(cm_sys[wd][dqy][dqx]!=""&&(pt.x/fsx-2-wl==dqx||pt.x/fsx-2-wl==dqx+1)&&pt.y/fsy-2-wt==dqy)
		{
			TKmoved=KEY_DOWN(MOUSE_MOVED);
			while((pt.x/fsx-2-wl==dqx||pt.x/fsx-2-wl==dqx+1)&&pt.y/fsy-2-wt==dqy&&KEY_DOWN(MOUSE_MOVED)==TKmoved)
			{
				GetCursorPos(&pt);
				pt.y-=max(0,3-fsx)*fsy;
				pt.x-=max(0,5-fsy)*fsx;
				if(cmdl==cmdl_sys[wd][dqy][dqx]/dl)
				{
					Sleep(cmdl_sys[wd][dqy][dqx]%dl);
					cpst=cmdl_sys[wd][dqy][dqx]%dl;
//					dqx=max(pt.x/fsx-2-wl,(long)0);
//					dqy=max(pt.y/fsy-2-wt,(long)0);
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
		pt.y-=max(0,3-fsx)*fsy;
		pt.x-=max(0,5-fsy)*fsx;
		dqx=max(pt.x/fsx-2-wl,(long)0);
		dqy=max(pt.y/fsy-2-wt,(long)0);
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
			
			if(cz_sys[wd][pt.y/fsy-2-wt][pt.x/fsx-2-wl]==0&&dqy>4)
			{
				//涂鸦时没有返回值 
				if(COLOR==-1)cw(1,dqy,dqx," ",0,"",0,0,0,0,0,wOldColorAttrs);
				else cw(1,dqy,dqx,hs,0,"",0,0,0,0,0,COLOR);
			}
			if(cz_sys[wd][pt.y/fsy-2-wt][pt.x/fsx-2-wl]>0)
			{
				while(KEY_DOWN(MOUSE_MOVED))Sleep(dl);
				clr(cml_sys[wd][dqy][dqx],cmt_sys[wd][dqy][dqx],cml_sys[wd][dqy][dqx]+mxh,cmt_sys[wd][dqy][dqx]+mxl,wd);
				gotoxy(dqx,dqy);
				cout<<c_sys[wd][dqy][dqx];
				GetCursorPos(&pt);
//				pt.y-=fsx;
				pt.y-=max(0,7-fsx)*fsy;
				pt.x-=max(0,7-fsy)*fsx;
				if(cz_sys[wd][pt.y/fsy-2-wt][pt.x/fsx-2-wl]==-1)pt.x-=fsx;
				if(cz_sys[wd][pt.y/fsy-2-wt][pt.x/fsx-2-wl]<=0)continue;
				SetConsoleTextAttribute(OPhandle,wOldColorAttrs);
				chv[++chv[0]]=cz_sys[wd][pt.y/fsy-2-wt][pt.x/fsx-2-wl];
				if(!ls){Enabled=0;system("cls");return NULL;}
			}
			
			if(cz_sys[bs][pt.y/fsy-2-wt][pt.x/fsx-2-wl]==-2&&movable_sys[bs]==0)
			{
				while(KEY_DOWN(MOUSE_MOVED))
				{
					tdqx=max(pt.x/fsx-2-wl,(long)0);
					tdqy=max(pt.y/fsy-2-wt,(long)0);
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
			/*if(cz_sys[bs][pt.y/fsy-2-wt][pt.x/fsx-2-wl]==-3)
			{
				if(ww.size()==1)continue;
				for(int i=0;i<ww.size();i++)
				if(ww[i]-'0'==bs){ww.erase(i,1);break;}//cout<<ww;char cc=getch();
				SetConsoleTextAttribute(OPhandle,wOldColorAttrs);system("cls");
				for(int i=0;i<ww.size();i++)spclr(ww[i]-'0');
				bs=wd=ww[0];
			}
			if(cz_sys[bs][pt.y/fsy-2-wt][pt.x/fsx-2-wl]==-4)
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
		ccv=cz_sys[bs][dqy][dqx];

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
//				gotoxy(dqx+1,dqy+1);cout<<dqx<<" "<<dqy;
//				gotoxy(dqx+1,dqy+2);printf("WInfo.l%d t%d r%d b%d",ial,iat,iar,iab);
//				Sleep(305);
//				gotoxy(dqx,dqy);printf("  ");
//				gotoxy(dqx+1,dqy+1);printf("       ");
//				char cc=getch();
//				gotoxy(dqx+1,dqy+2);printf("                             ");
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


void unprintf(int x,int y,string s)
{
	gotoxy(x,y);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='}')gotoxy(++x,y);
		else puts((const char*)" ");
	}
	return;
}
int main()
{//cout<<(0x10|0x20|0x40|0x80);return 0;
	system("mode con cols=151 lines=40");
	cwd(1,1,"天下第一蒟蒻涂鸦板",0,0,150,33);
	cw(1,1,1,"使用说明:使用鼠标选取颜色和字符}在窗口内长按鼠标}然后尽情涂抹吧",0,"别看了，快去试试",-1,-1,1500,1,3,0x1|0x2|0x8);
	cw(1,1,78,"点击这里更改画笔字符串~",241,"",-1,-1,1500,1,3,0x2|0x8);
	cw(1,1,63,"预览："+hs,0,"",0,0,0,0,0,wOldColorAttrs);
	cw(1,2,63,"点此清空颜色",243,"",0,0,0,0,0,0x2|0x4|0x8);
	cw(1,3,63,"点此清空画板",244,"",0,0,0,0,0,0x2|0x4|0x8);
	cw(1,4,63,"橡皮擦",245,"",0,0,0,0,0,0x2|0x4|0x8);
	cw(1,3,77,"退出",242,"",-1,-1,1500,1,3,0x1|0x4|0x8);
//	cw(1,4,1,"★ 收到了一封信--致老姐",0,"致老姐:}    这就是我送给你的十八岁生日礼物。虽然说时间不怎么充裕（一下午。。。）,bug也没调，但也略表心意}当初也没想好怎么说送这个礼物的缘由，于是随便说是为了让你保持the sense of curious and creative}但是另一方面也不得不说，十八岁意味着责任：各方面的责任。在这一点上听听老爸的倒是没错}也希望你以后能多为他人考虑，稍微细心一些，尽力处理好身边的人的关系。}                                                                             你弟\t2019.7.31",-1,-1,100,2,3,0x2|0x8);
	//color
	cw(1,1,33,"点击方块切换前景（文字）颜色",0,"",0,0,0,0,0,wOldColorAttrs);
	cw(1,2,33,"▲",9,"",0,0,0,0,0,0x1|0x8);
	cw(1,2,35,"▲",10,"",0,0,0,0,0,0x2|0x8);
	cw(1,2,37,"▲",12,"",0,0,0,0,0,0x4|0x8);
	cw(1,2,39,"▲",11,"",0,0,0,0,0,0x1|0x2|0x8);
	cw(1,2,41,"▲",13,"",0,0,0,0,0,0x1|0x4|0x8);
	cw(1,2,43,"▲",14,"",0,0,0,0,0,0x2|0x4|0x8);
	cw(1,2,45,"▲",15,"",0,0,0,0,0,0x1|0x2|0x4|0x8);
	cw(1,2,47,"▲",1,"",0,0,0,0,0,0x1);
	cw(1,2,49,"▲",2,"",0,0,0,0,0,0x2);
	cw(1,2,51,"▲",4,"",0,0,0,0,0,0x4);
	cw(1,2,53,"▲",3,"",0,0,0,0,0,0x1|0x2);
	cw(1,2,55,"▲",5,"",0,0,0,0,0,0x1|0x4);
	cw(1,2,57,"▲",6,"",0,0,0,0,0,0x2|0x4);
	cw(1,2,59,"▲",7,"",0,0,0,0,0,0x1|0x2|0x4);
	cw(1,3,33,"点击方块切换底色（背景）颜色",0,"",0,0,0,0,0,wOldColorAttrs);
	cw(1,4,33,"■",144,"",0,0,0,0,0,0x10|0x80);
	cw(1,4,35,"■",160,"",0,0,0,0,0,0x20|0x80);
	cw(1,4,37,"■",192,"",0,0,0,0,0,0x40|0x80);
	cw(1,4,39,"■",176,"",0,0,0,0,0,0x10|0x20|0x80);
	cw(1,4,41,"■",208,"",0,0,0,0,0,0x10|0x40|0x80);
	cw(1,4,43,"■",224,"",0,0,0,0,0,0x20|0x40|0x80);
	cw(1,4,45,"■",240,"",0,0,0,0,0,0x10|0x20|0x40|0x80);
	cw(1,4,47,"■",16,"",0,0,0,0,0,0x10);
	cw(1,4,49,"■",32,"",0,0,0,0,0,0x20);
	cw(1,4,51,"■",64,"",0,0,0,0,0,0x40);
	cw(1,4,53,"■",48,"",0,0,0,0,0,0x10|0x20);
	cw(1,4,55,"■",80,"",0,0,0,0,0,0x10|0x40);
	cw(1,4,57,"■",96,"",0,0,0,0,0,0x20|0x40);
	cw(1,4,59,"■",102,"",0,0,0,0,0,0x10|0x20|0x40);
	int ans=0;
	lock(1);
	ent(50,1,1,0);
	while(ans!=242)
	{
		while(chv[0]==0)Sleep(50);
		ans=chv[chv[0]--];
			Sleep(75);
			Enabled=0;
			Sleep(275);
		if(ans==241)
		{
			gotoxy(0,35);
			printf("请在此输入你想要用于涂鸦的字符串（对你没看错，中文英文都可以）\n");
			getline(cin,hs);
			unprintf(0,35,"请在此输入你想要用于涂鸦的字符串（对你没看错，中文英文都可以）}                                ");
			spclr(1);
			ent(50,1,1,0);
		}
		if(ans==242)
		{
			gotoxy(0,35);
			printf("这么急着退出呀。。\n不用保存吗？，快截个图吧，按键盘上面的PrtScr截屏~\n");
			printf("任意键退出...");
			cc=getch();
			unprintf(0,35,"这么急着退出呀。。}不用保存吗？，快截个图吧，按键盘上面的PrtScr截屏~}任意键退出...");
			system("start mspaint");
		}
		if(ans<241)
		{
			cw(1,1,69,"          ",0,"",0,0,0,0,0,wOldColorAttrs);
			COLOR|=ans;
			if(COLOR==15&&ans!=15)COLOR=ans;
			cw(1,1,69,hs,0,"",0,0,0,0,0,COLOR);
			ent(50,1,1,0);
		}
		if(ans==243)
		{
			COLOR=0;
			cw(1,1,69,"     ",0,"",0,0,0,0,0,wOldColorAttrs);
			cw(1,1,69,hs,0,"",0,0,0,0,0,COLOR);
			ent(50,1,1,0);
		}
		if(ans==245)
		{
			COLOR=-1;
			cw(1,1,69,"(橡皮)",0,"",0,0,0,0,0,wOldColorAttrs);
			ent(50,1,1,0);
		}
		if(ans==244)
		{
			DD();
			for(int i=5;i<=32;i++)
			cw(1,i,1,"                                                                                                                                                     ",0,"",0,0,0,0,0,wOldColorAttrs);
			
			ent(50,1,1,0);
		}
//		clr(0,35,50,39,1);
	}
	
	
//	cw(1,2,5,"老姐生日快乐~~~")
 return 0;
}
