
/**----------------------------------------------------------------
Clicking_System()	**载体版**	*当心坠物* 
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

//下面是游戏信息 
About{
当心坠物：Coded By LZ
完成于2019.8.19 
 
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
#include<ctime>
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
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define CW_USEDEFAULT       ((int)0x80000000)
#define DD() (SetConsoleTextAttribute(OPhandle, wOldColorAttrs))
#define ChWp( Px, Py, Cx, Cy) (MoveWindow(hwnd,Px,Py,Cx,Cy,TRUE))
#define StWp( Px, Py) (SetWindowPos(hwnd, HWND_NOTOPMOST, Px, Py, 0, 0,SWP_NOSIZE))
#define DS() {RECT nowr;GetWindowRect(hwnd,&nowr);StWp(rect.left,rect.top+1);StWp(rect.left,rect.top);ChWp(rect.left,rect.top+50,rect.right-rect.left,rect.bottom-rect.top-50);ChWp(rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top);}
#define lInitial() {SetWindowLong(hwnd, GWL_STYLE, wOldLong);SetConsoleTitle(CTitle);DS();TOPBROAD=30;}
#define lFreeze() {SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_CAPTION);DS();TOPBROAD=8;}
#define chck( k1, k2) ((k1&0x80)&&(k2&0x80))

//CSYS NORMAL SYMBOL!--------------------------------
//!!!:请勿调换变量声明顺序，否则后果自负! 
struct CWCN{int dl,wd,ls;}tcwcn;

const char Cnp='',Endnp='}';
string Msbl[]={"|","*","#","+",""," ","  ","│","┃","┆","┇","┊","┋","╳","□","■","█","▌","○","●","☆","★","?","?","?"},Msbt[]={"-","*","#","+",""," ","  ","─","━","┄","┅","┈","┉","╳","□","■","█","▄","○","●","☆","★","?","?","?"};
string Wdbdsl[]={"|","*","#","+"," ","!","?","'",".","+"},Wdbdst[]={"-","*","#","+"," ","!","?","'",".","="};
const char Ch0[]="┼",Ch1[]="╋",En0[]="+",En1[]="*",Sp0[]="╬",Sp1[]="#";//光标形式 (1个半角或全角字符)
const string Verson="ClickingVersonsV2.6\nCreated by Lz\n",Licenses=" 帮助:[2019.8.18]\n 说白了，电脑怎么用就怎么用\n \n 这个程序是一个用鼠标操纵的程序（仅此而已）。\n 使用时将光标准心对准文字点击就能选择。\n 如果其他窗口遮住了文字，可以拖动边框来移开，但部分窗口可能不允许。\n \n \n 帮助只有那么多，后面的不用看了\n \n 完成时间: \n";
const int Ath[15]={67,79,68,69,68,32,66,89,58,76,105,110,90,101,46};

int Enabled;//输入数据，总数，Windows版本，线程是否启动，返回数据
int mxl,mxh;/*msgbox() NEEDED*/
string ww=""/*当前窗口顺序*/;
char cc;//调试getch()用 

//Function declare
int INTSc(char* fileName,int linenum, int number);
bool Form_load();
bool Pr(char* fileName, int linenum,string ot);
void gotoxy(int x,int y);


//API SYMBOL
const HWND hwnd=GetForegroundWindow();
const HANDLE OPhandle = GetStdHandle(STD_OUTPUT_HANDLE);
RECT rect;
LONG wOldLong=GetWindowLong(hwnd, GWL_STYLE);
CONSOLE_CURSOR_INFO CursorInfo;


const int EoutDelay=7,IDDTFP=25,WDD=15,WDLMT=205,Trans=1,wOldColorAttrs=7,WinVer=0;//闪电字幕延时(!>5) 注释终止偏移  窗口累积最大个数 窗口数组大小  非焦点窗口可见性  默认窗口文字颜色 

short int cz_sys[WDD][WDLMT][WDLMT],cml_sys[WDD][WDLMT][WDLMT],cmt_sys[WDD][WDLMT][WDLMT],cmmd_sys[WDD][WDLMT][WDLMT],cmdl_sys[WDD][WDLMT][WDLMT],cmbds_sys[WDD][WDLMT][WDLMT],cl_sys[WDD][WDLMT][WDLMT],tasks_sys[WDD*3],crif_sys[WDLMT][WDLMT],movable_sys[WDD];
short int wdl_sys[WDD],wdt_sys[WDD],wdr_sys[WDD],wdb_sys[WDD],chv[WDLMT*WDLMT],ccv,ccvn,dqx,dqy;
string c_sys[WDD][WDLMT][WDLMT],cm_sys[WDD][WDLMT][WDLMT],wdtp_sys[WDD];
int ial=-1,iar=-1,iat=-1,iab=-1,BROAD=8,TOPBROAD=30,fsx=10,fsy=20;
char CTitle[1005];
const int lm=sqrt(sizeof(c_sys)/8/WDD)-5;
bool _Form_load=Form_load();



//LOADING AREA-------------------------------------

inline int INTSc(char* fileName,int linenum, int number)
{
	ifstream in(fileName);
	int ans;string data;
	for(int i=1;i<linenum;i++)getline(in,data);
	for(int i=1;i<=number;i++)in>>ans;
	in.close();
	return ans;
}
inline bool Pr(char* fileName, int linenum,string ot)
{
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
		//Debuging
		/*
		int tmp=i;
		string tmps="",ans="";
		while(tmp)
		{
			tmps+=tmp%10+'0';
			tmp/=10;
		}
		for(int s=tmps.size()-1;s>=0;s--)
		ans+=tmps[s];ans+='}';
		tmp=j;tmps="";
		while(tmp)
		{
			tmps+=tmp%10+'0';
			tmp/=10;
		}
		for(int s=tmps.size()-1;s>=0;s--)
		ans+=tmps[s];
		cm_sys[w][i][j]=ans;
//		*/
	}
	
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(OPhandle,&csbi);
	COORD size={255,255};
	SetConsoleScreenBufferSize(OPhandle,size);
	GetWindowRect(hwnd,&rect);
	if(ial==-1) ial=rect.left;
	if(iar==-1) iar=rect.right;
	if(iat==-1) iat=rect.top;
	if(iab==-1) iab=rect.bottom;
	ChWp(ial,iat,iar-ial,iab-iat);
	GetWindowText(hwnd, CTitle, 1000);
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
	GetCursorPos(&pt);
	GetWindowRect(hwnd,&rect);
	ial=rect.left+BROAD;
	iar=rect.right;
	iat=rect.top+TOPBROAD;
	iab=rect.bottom;
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
		while(pt.y<iat||pt.y>iab-fsy*4||pt.x<ial||pt.x>iar-fsx*4)
		{
			Sleep(dl*2),GetCursorPos(&pt);
			GetWindowRect(hwnd,&rect);
			if(rect.left!=-32000) 
			{
				ial=rect.left+BROAD;
				iar=rect.right;
				iat=rect.top+TOPBROAD;
				iab=rect.bottom;
			}
		} 
		GetWindowRect(hwnd,&rect);
		if(rect.left!=-32000) 
		{
			ial=rect.left+BROAD;
			iar=rect.right;
			iat=rect.top+TOPBROAD;
			iab=rect.bottom;
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
//				while(KEY_DOWN(MOUSE_MOVED))Sleep(dl);
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
		if(cz_sys[bs][dqy][dqx]>0)ccv=cz_sys[bs][dqy][dqx];
		if(cz_sys[bs][dqy][dqx]!=-1)ccvn=cz_sys[bs][dqy][dqx];

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
//DECLARE your symbol here!


string ch(int k)
{
	string ans="";
	while(k)
	{
		ans=char((k%10)+'0')+ans;
		k/=10;
	}
	return ans;
}
void pmain()
{
	lFreeze();
	system("mode con cols=68 lines=38");
	cwd(1,2,"菜单",0,0,50,24);
	ent(30,1,1,0);lock(1);lock(3);lock(4);
	int ans=0,MAXSCORE[3],lto=0;
	for(int i=0;i<3;i++)MAXSCORE[i]=0;
	while(ans!=16)
	{
		cwd(1,2,"菜单",0,0,50,24);
		cw(1,4,19,">:当心坠物:)",0,"",0,0,0,0,0,0x1|0x2|0x8|0x10|0x80);
		cw(1,5,15,"用鼠标点击文字来继续！",0,"",0,0,0,0,0,wOldColorAttrs|0x8);
		cw(1,8,21,"开始游戏",1,"准备好你的键盘和鼠标哦~",-1,-1,0,1,10,0x1|0x2|0x8);
		cw(1,10,21,"使用帮助",2,"",-1,-1,100,2,15,0x1|0x4|0x8);
		cw(1,15,23,"退出",16,"走的那么急啊qwq",-1,-1,50,0,3,0x2|0x8|0x20);
		cw(1,23,41,"移动窗口",3,"点击后可以拖动窗口",-1,-1,0,0,1,wOldColorAttrs);
		cw(1,24,5,"By LZ",0,"",0,0,0,0,0,wOldColorAttrs);
		cw(1,17,17,"最高纪录：简单："+ch(MAXSCORE[0])+"}中等："+ch(MAXSCORE[1])+"}困难："+ch(MAXSCORE[2]),0,"",-1,-1,50,0,3,0x2|0x4|0x8);
		
		
		while(chv[0]==0)Sleep(50);
		ans=chv[chv[0]--];
		if(ans==2)
		{
			ofstream ou("帮助.txt");
			ou<<Licenses;
			ou.close();
			system("start 帮助.txt");
			Sleep(1500);chv[0]=0;
		} 
		if(ans==3)
		{
			lInitial();
			Sleep(2500);
			lFreeze();
			system("mode con cols=68 lines=38");
		}
//		if(ans==32)tasks_sys[++tasks_sys[0]]=-2;
		if(ans==1)
		{
			system("cls");
			int GRD;
			tasks_sys[++tasks_sys[0]]=-1;
			cwd(5,2,"选择难度",10,5,38,20);
			cw(5,7,21,"简单",11,"只用鼠标操控",-1,-1,0,0,9,0x2|0x8);
			cw(5,9,21,"中等",12,"鼠标+键盘",-1,-1,0,0,9,0x1|0x2|0x8);
			cw(5,12,15,"莫名其妙（困难）",13,"",-1,-1,0,0,9,0x1|0x4|0x8);
			cw(5,16,12,"三个等级都是不同的模式！}一定都要看哦~}困难关有几率打出不死局哦",0,"",0,0,0,0,0,wOldColorAttrs);
			tasks_sys[++tasks_sys[0]]=5;
			chv[0]=0;
			while(chv[0]==0)Sleep(50);
			GRD=chv[chv[0]--];
			tasks_sys[++tasks_sys[0]]=-5;
			
			int HARD=24,SLEEP=500,MS=0,PMS=1,tROUND=0,invROUND=0,SCORE=0,pSCORE=0,INV=0,BROAD=50,pROUND=0,LIVE=3,lt[35],livv=0;
			for(int i=0;i<35;i++)lt[i]=2147483647;lt[26]=0;
			char tmp='a'+26;
			string tmps="";
			cwd(3,9,"当心坠物！",0,0,34,25);
			for(int e=1;e<25;e++)
			{
				cw(3,e,1,"　　　　　　　　　　　　　　　　",20,"",0,0,0,0,0,wOldColorAttrs);
				cw(3,e,2,"　　　　　　　　　　　　　　　",20,"",0,0,0,0,0,wOldColorAttrs);
			}
			
			cwd(4,0,"提示",35,0,58,25);
			cw(4,1,37,"状态：请看规则",0,"",-1,-1,0,0,3,wOldColorAttrs);//1,43 
			cw(4,4,37,"得分：0",0,"得分}会随时间增加",-1,-1,0,0,3,wOldColorAttrs);
			cw(4,6,37,"附加属性",0,"如果你碰到了}三种方块}它的属性会显示",-1,-1,0,0,3,0x2|0x4|0x8);
			cw(4,11,37,"3!",0,"",-1,-1,0,0,3,0x1|0x2|0x8);
			cw(4,12,37,"移动鼠标来开始}将鼠标移到'提示'}上即可暂停~}小提示：}可以通过暂停观察情况",0,"",-1,-1,0,0,3,0x2|0x8);
			cw(4,17,37,"退出",4,"点击直接退出",-1,-1,0,0,1,wOldColorAttrs);
			
			cwd(2,3,"游戏规则",10,5,40,32);
			cw(2,6,11,"点击开始后，你的鼠标下会出现}一个可以自由移动的'┼'}接着你要移动鼠标使'┼'避开}不断从顶端掉下的 ■}如果你被砸中,你会失去一点生命}生命为0时游戏结束}但是有三种方块是可以碰的}1.  可以使掉落速度变慢}2.  可以使掉落速度变快}3.  可以使你一段时间无敌}将鼠标移到游戏窗口外可暂停}快去试试吧！",0,"",0,0,0,0,0,0x2|0x4|0x8);
			if(GRD>11)cw(2,19,11,"另外顶端还会掉下一些小写字母}你也要在键盘上打出来}否则也会减少生命",0,"",0,0,0,0,0,0x2|0x4|0x8),BROAD=0,LIVE=5;
			if(GRD>12)cw(2,23,11,"之所以要叫莫名其妙，是因为这}里面加入了一些早期版本}存在的可怕的bug,每15秒多一个}因此你有15条命，祝你好运}希望你喜欢(嘿嘿)！",0,"",0,0,0,0,0,0x2|0x4|0x8),LIVE=15,BROAD=-100;
			cw(4,3,37,"速度："+ch(SLEEP)+" ms",0,"这是掉落速度}注意它会变快",-1,-1,0,0,3,wOldColorAttrs);
			cw(4,5,37,"生命："+ch(LIVE),0,"注意你的生命值",-1,-1,0,0,3,wOldColorAttrs);
			cw(2,28,20,"[OK]",32,"隐藏帮助",-1,-1,0,0,1,wOldColorAttrs|0x8);
			cw(2,13,13,"■",0,"注意我是蓝色的",-1,-1,0,0,1,0x1|0x2|0x8) ;
			cw(2,14,13,"■",0,"注意我是红色的",-1,-1,0,0,1,0x1|0x4|0x8) ;
			cw(2,15,13,"▲",0,"注意我是绿色的",-1,-1,0,0,1,0x2|0x8) ;

			Sleep(400);
			tasks_sys[++tasks_sys[0]]=2;
//			tasks_sys[++tasks_sys[0]]=3;
//			tasks_sys[++tasks_sys[0]]=4;
			
			
			
			chv[0]=0;
			while(chv[0]==0)Sleep(50);
			tasks_sys[++tasks_sys[0]]=-2;
			ans=chv[chv[0]--];
			cw(4,1,37,"状态：就绪    ",0,"这是游戏状态",-1,-1,0,0,3,wOldColorAttrs);//1,43 
			
			Sleep(1000);
			cw(4,11,37,"2!",0,"",-1,-1,0,0,3,0x1|0x2|0x8);
			Sleep(1000);
			cw(4,11,37,"1!",0,"",-1,-1,0,0,3,0x1|0x2|0x8);
			Sleep(1000);
			cw(4,11,37,"GO!",0,"",-1,-1,0,0,3,0x1|0x2|0x8);
			Sleep(500);
			cw(4,11,37,"   ",0,"",-1,-1,0,0,3,wOldColorAttrs);
			cw(4,1,43,"开始",0,"",0,0,0,0,0,wOldColorAttrs);
			ccv=20;
			while(1)
			{
				for(int i=1;i<33;i+=2)
				{
					srand(time(NULL)*rand());
					if(1+(rand())%HARD==1)
					{
						if(GRD>11&&1+(rand())%(HARD)==1&&!(GRD==13&&SCORE>300))
						{
							tmp='a'+rand()%26;
							while(lt[tmp-'a']!=2147483647)
							{
								tmp='a'+rand()%26;
							}
							lt[tmp-'a']=pSCORE;
							tmps="";
							tmps+=tmp;
							if(GRD>12&&SCORE>150)tmps+=" ",cout<<tmps;
							cw(3,1,i,tmps,20,"",-1,-1,0,0,3,0x4|0x2|0x8);
							if(lto==0)
							{
								lto=1;
								Sleep(200);Enabled=0;Sleep(300);
								msgbox(3,i+2,1,0x1|0x2|0x8,"看！这就是字母}现在在键盘上打出它}注意是小写",0,3);
								tmp=getch();
								while(tmp!=tmps[0])
								{
									tmp=getch();
								}
								spclr(3);
								spclr(4);
								msgbox(3,i+2,1,0x1|0x2|0x8,"干得漂亮！}记得要在它掉到底之前打出来哦",0,1);
								Sleep(1500);
								spclr(3);
								spclr(4);
								SCORE+=5,lt[tmp-'a']=2147483647;
								for(int e=1;e<=25;e++)
								for(int i=1;i<33;i+=2)
								if(c_sys[3][e][i]==tmps)
								c_sys[3][e][i]="　",cl_sys[3][e][i]=wOldColorAttrs,cz_sys[3][e][i]=20;
								ccv=ccvn=20;
								ent(30,3,1,0);
							}
						}
						else cw(3,1,i,"■",21,"",-1,-1,0,0,3,wOldColorAttrs);
					}
					else if(tROUND==0&&1+(rand())%(HARD*6)==1)cw(3,1,i,"■",22,"",-1,-1,0,0,3,0x1|0x2|0x8);
					else if(pROUND==0&&1+(rand())%(HARD*6)==1)cw(3,1,i,"■",23,"",-1,-1,0,0,3,0x1|0x4|0x8);
					else if(invROUND==0&&1+(rand())%(HARD*18)==1)cw(3,1,i,"▲",24,"",-1,-1,0,0,3,0x2|0x8);
				}
				if(GRD<13||(GRD==13&&SCORE>600))
				{
					if(GRD==13&&SCORE>600)
					{
						cw(4,18,37,"恭喜你到达了终极bug}（前面的很好玩对吧）}你可以试试去碰障碍}你会发现自己不会死}这就是while嵌套for}直接用break结束的后果",0,"",0,0,0,0,0,0x2|0x4|0x8);
					}
					cw(3,24,1,"　　　　　　　　　　　　　　　　",20,"",0,0,0,0,0,wOldColorAttrs);
					cw(3,24,2,"　　　　　　　　　　　　　　　",20,"",0,0,0,0,0,wOldColorAttrs);
					for(int i=25;i>1;i--)
					for(int j=1;j<33;j++)
					if(c_sys[3][i-1][j]!="　")
					{
						cw(3,i,j,c_sys[3][i-1][j],cz_sys[3][i-1][j],"",0,0,0,0,0,cl_sys[3][i-1][j]);
						cw(3,i-1,j,"　",20,"",0,0,0,0,0,wOldColorAttrs);
					}
					if(rand()%7==0)cw(3,1,dqx,"■",21,"",-1,-1,0,0,3,wOldColorAttrs);
				}
				else
				{
					if(SCORE<40)
					{
						cw(3,24,1,"　　　　　　　　　　　　　　　　　",20,"",0,0,0,0,0,wOldColorAttrs);
						cw(3,24,2,"　　　　　　　　　　　　　　　　",20,"",0,0,0,0,0,wOldColorAttrs);
					for(int i=25;i>1;i--)
					for(int j=1;j<34;j++)
						if(c_sys[3][i-1][j]!="　")
						{
							cw(3,i,j,c_sys[3][i-1][j],cz_sys[3][i-1][j],"",0,0,0,0,0,cl_sys[3][i-1][j]);
							cw(3,i-1,j,"　",20,"",0,0,0,0,0,wOldColorAttrs);
						}
						cw(3,1,dqx,"■",21,"",-1,-1,0,0,3,wOldColorAttrs);
					}
					else if(SCORE<80)
					{
						cw(3,24,1,"　　　　　　　　　　　　　　　　　",20,"",0,0,0,0,0,wOldColorAttrs);
						cw(3,24,2,"　　　　　　　　　　　　　　　　",20,"",0,0,0,0,0,wOldColorAttrs);
					for(int i=25;i>1;i--)
					for(int j=1;j<34;j++)
//						if(c_sys[3][i-1][j]!="　")
						{
							cw(3,i,j,c_sys[3][i-1][j],cz_sys[3][i-1][j],"",0,0,0,0,0,cl_sys[3][i-1][j]);
//							cw(3,i-1,j,"　",20,"",0,0,0,0,0,wOldColorAttrs);
						}
//						if(rand()%7==0)cw(3,1,dqx,"■",21,"",-1,-1,0,0,3,wOldColorAttrs);
					}
					else if(SCORE<140)
					{
						for(int i=1;i<34;i+=2)
							{
								srand(time(NULL)*rand());
								if(1+(rand())%HARD*3==1)cw(3,1,i,"　",20,"",-1,-1,0,0,3,wOldColorAttrs);
							}
					for(int i=25;i>1;i--)
					for(int j=1;j<34;j++)
						{
							cw(3,i,j,c_sys[3][i-1][j],cz_sys[3][i-1][j],"",0,0,0,0,0,cl_sys[3][i-1][j]);
						}
//						if(rand()%7==0)cw(3,1,dqx,"■",21,"",-1,-1,0,0,3,wOldColorAttrs);
					}
					else if(SCORE<250)
					{
							for(int i=1;i<34;i+=2)
							{
								srand(time(NULL)*rand());
								if(1+(rand())%HARD*3==1)cw(3,1,i,"　",20,"",-1,-1,0,0,3,wOldColorAttrs);
							}
					for(int i=25;i>1;i--)
					for(int j=1;j<34;j++)
						{
							cw(3,i,j,c_sys[3][i-1][j],cz_sys[3][i-1][j],"",0,0,0,0,0,cl_sys[3][i-1][j]);
						}
//						cw(3,1,dqx,"■",21,"",-1,-1,0,0,3,wOldColorAttrs);
//						if(SCORE%5==0)cw(3,0,1,"■■■■■■■■■■■■■■■■■",21,"",0,0,0,0,0,wOldColorAttrs);
					}
					else if(SCORE<300)
					{
							for(int i=1;i<34;i+=2)
							{
								srand(time(NULL)*rand());
								if(1+(rand())%HARD*3==1)cw(3,1,i,"　",20,"",-1,-1,0,0,3,wOldColorAttrs);
							}
					for(int i=32;i>1;i--)
					for(int j=1;j<58;j++)
						{
							cw(3,i,j,c_sys[3][i-1][j],cz_sys[3][i-1][j],"",0,0,0,0,0,cl_sys[3][i-1][j]);
						}
//						cw(3,1,dqx,"■",21,"",-1,-1,0,0,3,wOldColorAttrs);
//						if(SCORE%2==0)cw(3,0,1,"■■■■■■■■■■■■■■■■■",21,"",0,0,0,0,0,wOldColorAttrs);
					}
					else if(SCORE<400)
					{
							for(int i=1;i<34;i+=2)
							{
								srand(time(NULL)*rand());
								if(1+(rand())%HARD*3==1)cw(3,1,i,"■",21,"",-1,-1,0,0,3,wOldColorAttrs);
								else if(tROUND==0&&1+(rand())%(HARD*3)==1)cw(3,1,i,"■",22,"",-1,-1,0,0,3,0x1|0x2|0x8);
								else if(pROUND==0&&1+(rand())%(HARD*3)==1)cw(3,1,i,"■",23,"",-1,-1,0,0,3,0x1|0x4|0x8);
								else if(invROUND==0&&1+(rand())%(HARD*3)==1)cw(3,1,i,"▲",24,"",-1,-1,0,0,3,0x2|0x8);
								else cw(3,1,i,"　",20,"",-1,-1,0,0,3,wOldColorAttrs);
							}
						for(int i=2;i<=32;i++)
						for(int j=1;j<58;j++)
						{
							cw(3,i,j,c_sys[3][i-1][j],cz_sys[3][i-1][j],"",0,0,0,0,0,cl_sys[3][i-1][j]);
						}
//						cw(3,1,dqx,"■",21,"",-1,-1,0,0,3,wOldColorAttrs);
					}
					else if(SCORE<600)
					{
							for(int i=1;i<34;i+=2)
							{
								srand(time(NULL)*rand());
								if(1+(rand())%HARD*3==1)cw(3,1,i,"■",21,"",-1,-1,0,0,3,wOldColorAttrs);
								else if(tROUND==0&&1+(rand())%(HARD*3)==1)cw(3,1,i,"■",22,"",-1,-1,0,0,3,0x1|0x2|0x8);
								else if(pROUND==0&&1+(rand())%(HARD*3)==1)cw(3,1,i,"■",23,"",-1,-1,0,0,3,0x1|0x4|0x8);
								else if(invROUND==0&&1+(rand())%(HARD*3)==1)cw(3,1,i,"▲",24,"",-1,-1,0,0,3,0x2|0x8);
								else cw(3,1,i,"　",20,"",-1,-1,0,0,3,wOldColorAttrs);
							}
						for(int i=2;i<=32;i++)
						for(int j=1;j<58;j++)
						if(c_sys[3][i-1][j]!="　")
						{
							cw(3,i,j,c_sys[3][i-1][j],cz_sys[3][i-1][j],"",0,0,0,0,0,cl_sys[3][i-1][j]);
						}
//						cw(3,1,dqx,"■",21,"",-1,-1,0,0,3,wOldColorAttrs);
					}
				}
				for(int i=0;i<26;i++)
				if(pSCORE-lt[i]>23)
				{
					lt[i]=2147483647;
					if(LIVE==1)break;
					LIVE--;
					cw(4,5,43,ch(LIVE)+' ',0,"",0,0,0,0,0,0x4|0x8);
				}
				if(SCORE>BROAD)
				{
					if(BROAD%700==0)LIVE++;
					if(GRD>11&&BROAD%450==0)LIVE++;
					if(GRD>12&&BROAD%200==0)LIVE++;
					SLEEP=SLEEP/2+100;
					HARD=HARD/2+4;
					BROAD+=100;
					cw(4,3,43,ch(SLEEP),0,"",0,0,0,0,0,wOldColorAttrs);
				}
				if(INV&&pSCORE-invROUND>15)
				{
					INV=0;
					cw(4,9,37,"       ",0,"",0,0,0,0,0,wOldColorAttrs);
					invROUND=0;
					ccv=ccvn=20;
				}
				if(MS&&pSCORE-tROUND>10)
				{
					MS=0;
					cw(4,7,37,"       ",0,"",0,0,0,0,0,wOldColorAttrs);
					tROUND=0;
				}
				if(PMS>1&&pSCORE-pROUND>20)
				{
					PMS=1;
					cw(4,8,37,"       ",0,"",0,0,0,0,0,wOldColorAttrs);
					pROUND=0;
				}
				
				for(int t=1;t<=15;t++)
				{
					if(chv[0]&&chv[chv[0]--]==4){ans=4;goto C;}
					if(kbhit())
					{
						tmp=getch();
						if(tmp==27)
						{
							msgbox(3,10,10,0x4|0x2|0x8,"请问你是要退出吗？}ESC退出，其他继续",2,wOldColorAttrs);
							tmp=getch();
							if(tmp==27){ans=4;goto C;}
						}
						if(lt[tmp-'a']!=2147483647)SCORE+=5,lt[tmp-'a']=2147483647;
						tmps="";
						tmps+=tmp;
						for(int e=1;e<=25;e++)
						for(int i=1;i<34;i+=2)
						if(c_sys[3][e][i]==tmps)
						cw(3,e,i,"　",20,"",0,0,0,0,0,wOldColorAttrs);
					}
					if((ccv==21||ccvn==21)&&!INV)
					{
						if(LIVE==1)
						{
							if(GRD>12&&SCORE>500)break;
							//终极BUG~ 
							//如果你打到600分，就不会再死了（也是个早期的bug） 
							else goto C;
						}
						livv=1;
						ccv=ccvn=20;
					}
					if(ccv==22)
					{
						MS=500;
						cw(4,7,37,"冻结*10",0,"",0,0,0,0,0,0x1|0x2|0x8);
						SCORE+=10;
						tROUND=pSCORE;
						ccv=20;
						for(int e=1;e<=25;e++)
						for(int i=1;i<34;i+=2)
						if(c_sys[3][e][i]=="■"&&cl_sys[3][e][i]==11)
						cw(3,e,i,"　",20,"",0,0,0,0,0,wOldColorAttrs);
//						c_sys[3][e][i]="　",cl_sys[3][e][i]=wOldColorAttrs,cz_sys[3][e][i]=20;
					}
					if(ccv==23)
					{
						PMS=2;
						cw(4,8,37,"加速*10",0,"",0,0,0,0,0,0x1|0x4|0x8);
						SCORE+=10;
						pROUND=pSCORE;
						ccv=20;
						for(int e=1;e<=25;e++)
						for(int i=1;i<34;i+=2)
						if(c_sys[3][e][i]=="■"&&cl_sys[3][e][i]==13)
						cw(3,e,i,"　",20,"",0,0,0,0,0,wOldColorAttrs);
//						c_sys[3][e][i]="　",cl_sys[3][e][i]=wOldColorAttrs,cz_sys[3][e][i]=20;
					}
					if(ccv==24)
					{
						cw(4,9,37,"无敌*10",0,"",0,0,0,0,0,0x2|0x8);
						SCORE+=15;
						invROUND=pSCORE;
						INV=1;
						ccv=20;
						for(int e=1;e<=25;e++)
						for(int i=1;i<34;i+=2)
						if(c_sys[3][e][i]=="▲"&&cl_sys[3][e][i]==10)
						cw(3,e,i,"　",20,"",0,0,0,0,0,wOldColorAttrs);
//						c_sys[3][e][i]="　",cl_sys[3][e][i]=wOldColorAttrs,cz_sys[3][e][i]=20;
					}
					if(ccvn<20)
					{
						cw(4,1,43,"暂停",0,"",0,0,0,0,0,wOldColorAttrs);
						while(ccvn<20)
						{
							Sleep(10);
						}
						cw(4,1,43,"开始",0,"",0,0,0,0,0,wOldColorAttrs);
						INV=1;invROUND=pSCORE-5;
					}
					Sleep((SLEEP+MS)/PMS/15);
				}
				SCORE++;pSCORE++;
				cw(4,4,43,ch(SCORE)+" 时间："+ch(pSCORE),0,"",0,0,0,0,0,wOldColorAttrs);
				if(livv==1)LIVE--,livv=0,cw(4,5,43,ch(LIVE)+' ',0,"",0,0,0,0,0,0x4|0x8);
			}
			C:;
			cw(4,1,43,"结束",0,"",0,0,0,0,0,wOldColorAttrs);
			if(ans!=4)cw(4,5,43,"0",0,"",0,0,0,0,0,0x4|0x8);
			Sleep(250);Enabled=0;Sleep(250);
			if(ans!=4)msgbox(3,10,10,wOldColorAttrs,"Game Over",2,1);
			Sleep(1000);
			if(SCORE>MAXSCORE[GRD-11])
			{
				msgbox(3,3,18,0x1|0x2|0x8|0x20|0x40,"恭喜你创造了新纪录——"+ch(SCORE),1,21);
				MAXSCORE[GRD-11]=SCORE;
			}
			msgbox(3,10,13,wOldColorAttrs,"                    ",0,0);
			gotoxy(11,14);
			system("pause");
			ans=0;chv[0]=0;
//			system("cls");
			tasks_sys[++tasks_sys[0]]=-3;
			tasks_sys[++tasks_sys[0]]=-4;
			tasks_sys[++tasks_sys[0]]=-2;
			tasks_sys[++tasks_sys[0]]=-5;
//			tasks_sys[++tasks_sys[0]]=1;system("pause");
			ent(30,1,1,0);//stem("pause");
		}
	}
	Enabled=0;
	return;
}
int main()
{
	Pr((char*)"a.bat",1,"@echo off\nreg QUERY HKCU\\Console /v FontSize >que.txt");
	system("a.bat");
	ifstream in("que.txt",ios::in);
	char tmp[155];
	string data;
	int o=0;
	while(!in.eof() )
	{
		in.getline(tmp,128);
		data=tmp;//cout<<data<<" "<<data.find("0x14000a")<<"\n";system("pause");
		if(data.find("0x14000a")!=string::npos)
		{
			o=1;
			break;
		}
	}
	in.close();
	if(o==0)
	{
		cout<<"请允许修改注册表，这是为了使字体更大、更清晰\n不用担心，稍后会还原原来的设置\n";
		system("reg ADD HKCU\\Console /v FontSize /t REG_DWORD /f /d 0x0014000a");
//		Pr((char*)"a.bat",1,"reg QUERY HKCU\\Console /v FontSize >que.txt");
		DD();
		system("if not exist \".\\当心坠物.exe\" echo 请不要改动exe的名字！请将其改回：当心坠物.exe，否则无法启动");
		system("start 当心坠物.exe");
		system("del a.bat");
		system("del que.txt");
		return 0;
	}
	system("del a.bat");
	system("del que.txt");
	system("reg ADD HKCU\\Console /v FontSize /t REG_DWORD /f /d 0x00100008");
	pmain();
	return 0;
}
