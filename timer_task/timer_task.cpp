#include<iostream>
#include<cstdio>
#include<ctime>
#include<windows.h>
#include<conio.h>
//#include <process.h>
using namespace std;


extern "C"
{
    int WINAPI MessageBoxTimeoutA(IN HWND hWnd, IN LPCSTR lpText, IN LPCSTR lpCaption, IN UINT uType, IN WORD wLanguageId, IN DWORD dwMilliseconds);
    int WINAPI MessageBoxTimeoutW(IN HWND hWnd, IN LPCWSTR lpText, IN LPCWSTR lpCaption, IN UINT uType, IN WORD wLanguageId, IN DWORD dwMilliseconds);
};
//#ifdef UNICODE
//#define MessageBoxTimeout MessageBoxTimeoutW
//#else
//#define MessageBoxTimeout MessageBoxTimeoutA
//#endif


string fold[1005];
int cd (string s)
{
	int ans=0;
	while(s.size()&&s[0]>='0'&&s[0]<='9')
	{
		ans*=10;
		ans+=s[0]-'0';
		s.erase(0,1);
	}
	return ans;
}
void clock_()
{
time_t t = time(0);
char tmp[128];
int n;
system("cls");
	system("mode con cols=30 lines=5");
	printf("在若干秒后提醒我并停止：(输入-1则不提醒) ");
	if (fold[2][0]=='-') n=-1;
	else if (fold[2]!="") n=cd (fold[2]),printf("%d",n);
	else scanf("%d",&n);
	
	while(n)
	{
		t = time(0);
	    strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A \n本年第%j天 %z",localtime(&t) );
		system("cls");
		puts( tmp );
		Sleep(930);n--;
	}
	printf("\n时辰已到！(任意键停止)\a");
	while(!kbhit()){printf("\a\a\a");Sleep(2000);}
	getch();
	Sleep(1000);
	return;
}
void lr()
{
    HANDLE OPhandle;
    CONSOLE_SCREEN_BUFFER_INFO bufInfo;
    SMALL_RECT scroll;
    COORD newCursorPointer;
    CHAR_INFO ciFill;

    OPhandle = GetStdHandle(STD_OUTPUT_HANDLE);
    if(!GetConsoleScreenBufferInfo(OPhandle, &bufInfo))
        return;

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
    return;
}
void timer()
{
int s=0,tt=0,tp[1005],tpms[1005],tans=0,i,o=0;
system("cls");
int start=0,end=0,line=3;
	system("mode con cols=50 lines=25");
	printf("准备就绪\n任意键开始，开始后任意键计次，ESC停止\n");
	char cc;
	if(fold[2]!="start_now")cc=getch();
	start=clock();
	cout<<"\a\n";
	end=clock();
	HANDLE OPHANDLE=GetStdHandle(STD_OUTPUT_HANDLE);
	for(i=1;!o;i++)
	{
		tt=0;
		if(line>20)  system("cls"),line=0;
		if(i%60==0)
		{
			puts("A minute!");
			line++;
			s++;
		}
		printf("texting:%d′%d″%03d ",s,i%60,(end-start)%1000);
		while((end-start)<(1000*i))
		{
			if(kbhit())
			{
				cc=getch();
				if(cc==27){o=1;break;}
				if(cc==9)
				{
					puts("已暂停");
					end=clock();
					printf("现在时间\n共计时%d分%d秒%d\n计次%d次\n",i/60,i%60,(end-start)%1000,tans);
					system("pause") ;
					start+=clock()-end;
					system ("cls") ;
					line=0;
					printf("texting:%d′%d″%03d ",s,i%60,(end-start)%1000);
					continue;
				}
				if(tans>1000){puts("\n错误：堆栈已满！"),line+=2;continue;}
				else if(tans>800)puts("\n警告：堆栈将满！请合理计次"),line+=2;
				tp[++tans]=i;
				tpms[tans]=(end-start)%1000;
				SetConsoleCursorPosition(OPHANDLE,(COORD){0,line});
				printf("\a计次：%d :%d′%d″%d\t(%d s)\n",tans,s,i%60,(end-start)%1000,i);
				line++;
				printf("texting:%d′%d″%03d ",s,i%60,(end-start)%1000);
			}
			end=clock();
//	1.1;	putchar('\b');putchar('\b');putchar('\b');putchar('\b');
	1.2;	printf("\b\b\b\b");
//	2;		lr();
//	3;		SetConsoleCursorPosition(OPHANDLE,(COORD){0,line});
			printf("%03d ",(end-start)%1000);
			Sleep(10);
//		cout<<"texting:"<<s<<"′"<<i%60<<"″";
		}
		SetConsoleCursorPosition(OPHANDLE,(COORD){0,line});printf("texting:%d′%d″000\n",s,i%60);
		line++;
	}
	Sleep(200);
	system("cls");
	if(kbhit())cc=getch();
	printf("计时结束\n共计时%d分%d秒%d\n计次%d次：\n",i/60,i%60,(end-start)%1000,tans);
	for(int i=1;i<=tans/20+(tans%20>0);i++)
	{
		for(int j=(i-1)*20+1;j<=i*20&&j<=tans;j++)
		printf("计次%d:%d′%d″%d(%d s)\n",j,tp[j]/60,tp[j]%60,tpms[j],tp[j]);
		printf("任意键下一页");
		char cc=getch();
		system("cls");
	}
	return;
}
//void getall()
//{
////	 #include <Windows.h>
//// #include <stdio.h>
//// #include <tchar.h>
//// #include <string.h>
//// #include <iostream.h>
// 
//// int main()
//// {    
//     HWND hd=GetDesktopWindow();        //得到桌面窗口
//     hd=GetWindow(hd,GW_CHILD);        //得到屏幕上第一个子窗口
//     char s[200]={0};
//     int num=1;
//     while(hd!=NULL)                    //循环得到所有的子窗口
//     {
//         memset(s,0,200);
//         GetWindowText(hd,s,200);
//         cout<<num++<<": "<<s<<endl;
//         hd=GetNextWindow(hd,GW_HWNDNEXT);
//     }
//     getchar();
////     return 0;
//// }
//}
bool sleeping_test()
{
	return true;
}
void timer_task()
{
string st[1005];
int cnt=0,o=0;
system("cls");
	cout<<"请输入执行命令\nEOF结束\n";
	int rf=1,UNAC=0;
	while(fold[++rf]!="EOF"&&fold[rf]!="")
	{
		cout<<fold[rf]<<endl;
		st[++cnt]=fold[rf];
	}
	if(fold[rf]=="EOF")cnt++;
	if(rf==2)
	while(st[cnt]!="EOF")
	{
		getline(cin,st[++cnt]);
		if (st[cnt]=="/unac"||st[cnt]=="-unac"||st[cnt]==".unac"||st[cnt]=="unac"||st[cnt]=="UNAC") puts("UNAC=1"),UNAC=1;
		
	}
	int _getpid( void );
	time_t t = time(0);
    char tmp[128],cc;
    strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A \n本年第%j天 %z",localtime(&t) );
	puts( tmp );
	int h,m,s;
	cout<<"目标启动时间(hh:mm:ss)?\nWarning:只限当天内,至少2min\n";
	if(fold[++rf]!="")h=cd (fold[rf]);
	else printf("h参数读取错误\n"),o=1;
	if(fold[++rf]!="")m=cd (fold[rf]);
	else printf("m参数读取错误\n"),o=1;
	if(fold[++rf]!="")s=cd (fold[rf]);
	else printf("s参数读取错误\n"),o=1;
	if(!o) printf("%d:%d:%d",h,m,s),Sleep(1000);
	if (o)scanf("%d:%d:%d",&h,&m,&s);
	if(((h-((tmp[11]-'0')*10+tmp[12]-'0'))*3600+(m-((tmp[14]-'0')*10+tmp[15]-'0'))*60+(s-((tmp[17]-'0')*10+tmp[18]-'0')))*1000<0)
	{
//		if (1) continue;
		cout<<"时间无效！\n将重新启动程序\n";
		if(o==1)
		{
			system("pause");
			return;
		}
		else
		{
			Sleep(500);
			printf("Exit when command exists\n");
			Sleep(100);
			exit(1);
		}
	}
	system("cls");
	system("mode con cols=30 lines=10");
	cout<<"开始计时...\n连按两次ESC:可立即执行\nTAB:暂停\n["<<max(0,((h-((tmp[11]-'0')*10+tmp[12]-'0'))*3600+(m-((tmp[14]-'0')*10+tmp[15]-'0'))*60+(s-((tmp[17]-'0')*10+tmp[18]-'0'))-120))<<"s(+120s)]\n";
	for(int i=1;i<=max(0,((h-((tmp[11]-'0')*10+tmp[12]-'0'))*3600+(m-((tmp[14]-'0')*10+tmp[15]-'0'))*60+(s-((tmp[17]-'0')*10+tmp[18]-'0'))));i++)
	{
		Sleep(1000);
		if(kbhit())
		{
			cc=getch();
			if(cc==27)
			{
				cout<<"立即执行？\n";
				cc=getch();
				if(cc==27)break;
				else cout<<"将继续等待["<<max(0,((h-((tmp[11]-'0')*10+tmp[12]-'0'))*3600+(m-((tmp[14]-'0')*10+tmp[15]-'0'))*60+(s-((tmp[17]-'0')*10+tmp[18]-'0'))))-i<<"]秒\n";
			}
			else if(cc==9&&!UNAC)
			{
				cout<<"暂停...\n";
				cc=getch();
				Sleep(500);
				for(int w=1;cc==9&&kbhit();w++)
				{
					i-=60;
					cout<<"增加minutes:"<<w<<endl;
					Sleep(900);
					while(kbhit())cc=getch();
					Sleep(100);
				}
				cout<<"将继续等待["<<max(0,((h-((tmp[11]-'0')*10+tmp[12]-'0'))*3600+(m-((tmp[14]-'0')*10+tmp[15]-'0'))*60+(s-((tmp[17]-'0')*10+tmp[18]-'0'))))-i<<"]秒\n";
			}
			else cout<<"将继续等待["<<max(0,((h-((tmp[11]-'0')*10+tmp[12]-'0'))*3600+(m-((tmp[14]-'0')*10+tmp[15]-'0'))*60+(s-((tmp[17]-'0')*10+tmp[18]-'0'))))-i<<"]秒\n";
		}
		if(max(0,((h-((tmp[11]-'0')*10+tmp[12]-'0'))*3600+(m-((tmp[14]-'0')*10+tmp[15]-'0'))*60+(s-((tmp[17]-'0')*10+tmp[18]-'0'))))-i==120)
		{
			char szWindowTitle[105];
			GetWindowTextA(GetConsoleWindow(), szWindowTitle, sizeof(szWindowTitle));//!!! 
			string inf=szWindowTitle;
			inf+=" 的任务即将执行!\n按否来推迟";
			printf("2min内即将执行\n\a") ;
			int result = UNAC?MessageBoxTimeoutA (GetForegroundWindow(),inf.c_str(),"提示",MB_OK,0,7500):MessageBoxTimeoutA (GetForegroundWindow(),inf.c_str(),"提示",MB_YESNO,0,7500);
			if (result == 7) i-=150;
			else i+=5;
		}
		if (sleeping_test()) ;
	}
//	cout<<"即将执行(2min)\a\n["<<min(120,((h-((tmp[11]-'0')*10+tmp[12]-'0'))*3600+(m-((tmp[14]-'0')*10+tmp[15]-'0'))*60+(s-((tmp[17]-'0')*10+tmp[18]-'0'))))<<"s]\n";
//	Sleep(min(120*1000,((h-((tmp[11]-'0')*10+tmp[12]-'0'))*3600+(m-((tmp[14]-'0')*10+tmp[15]-'0'))*60+(s-((tmp[17]-'0')*10+tmp[18]-'0')))*1000));
	cout<<"开始执行tasklist\n\n";
	//task list??
	{
		for(int i=1;i<cnt;i++)
		if(st[i].find("echo")==string::npos)system(st[i].c_str());
		else if (st[i]!="echo") 
		{
			string mes=st[i].substr(st[i].find("echo")+5,st[i].size()-st[i].find("echo")-5);
			MessageBox(GetForegroundWindow(),mes.c_str(),"通知！",MB_OK);
			
		}
	}
	cout<<"\n执行完毕\n";
	if(rf<5)getch();
	return ;
}
void ep()
{
int k,kl,p,o;
char cc;
bool tl;
int rf=1;
system("mode con cols=40 lines=8");
	cout<<"自动休息提醒器\n输入你想自动休息的间隔时间：(分钟)";
	o=0;
	if (fold[++rf]!="")k=cd (fold[rf]),o=1,cout<<k<<endl;
	else printf("\n未检测到参数\n");
	if(!o)scanf("%d",&k);k=max(1,k);
//	while(k<3){printf("输入不合法!\n");scanf("%d",&k);}
	
	cout<<"输入你想休息的时间：(分钟)";
	o=0;
	if (fold[++rf]!="")kl=cd (fold[rf]),o=1,cout<<kl<<endl;
	else printf("\n未检测到参数\n");
	if(!o)scanf("%d",&kl);
	
	o=0;
	cout<<"你想循环多少次？(-1为无限循环)";
	if (fold[++rf]!="")
	{
		if (fold[rf][0]=='-')p=-1,o=1,cout<<p<<endl;
		else p=cd (fold[rf]),o=1,cout<<p<<endl;
	}
	else printf("\n未检测到参数\n");
	if(!o) scanf("%d",&p);
	
	o=0;
	cout<<"我怎么提醒你呢？(1锁定电脑\\0不动作)";
	if (fold[++rf]!="")tl=cd (fold[rf]),o=1,cout<<tl<<endl;
	else printf("\n未检测到参数\n");
	if(!o) cin>>tl;
	cout<<"任意键开始!\n";
	
	char szWindowTitle[105];
	GetWindowTextA(GetConsoleWindow(), szWindowTitle, sizeof(szWindowTitle));
	string tmp=szWindowTitle;
	tmp+="提醒您";//提示窗口标题 
	if(fold[++rf]!="start_now")cc=getch();
	else Sleep(1000);
	system("cls");
	while(p!=0)
	{
		printf("开始吧！\a\a\a\n");
		p--;
		for(int i=k*60;i>0;i--)
		{
			if (i==240&&k*60>1000)
			{
//				眼保健操(4min 以内)
				printf("\a");
				MessageBox(GetForegroundWindow(),"要加油啊蒟蒻",&tmp[0],MB_OK);
				MessageBox(GetForegroundWindow(),"休息时间\n记得先进入下一节课哦",&tmp[0],MB_OK);
				system("start .\\眼保健操.mp4") ;
//				system(".\\混合版眼保健操.mp4") ;
			}
			if(i==25)
			printf("是时候准备休息啦！\n(30s后开始休息)\n\a");
			if (i<25&&i>22)
			printf("\a");
			if(i==5)
			printf("休息时间\n\a\a");
			if(i==1&&tl)
			system("rundll32.exe user32.dll,LockWorkStation");
			Sleep(1000);
			if(kbhit())
			{
				cc=getch();
				{
					system("cls");
					printf("暂停中...\n离下一次休息还有%d分钟...\n",i/60+(i%60>0));
					system("pause");
					system("cls");
					printf("开始工作吧！\n");
				}
			}
		}
		Sleep(max(kl*60*1000,0));
		system("cls");
	}
	printf("\a工作结束！\n");
	MessageBox(GetForegroundWindow(),"工作结束",&tmp[0],MB_OK);
	if(rf<5)getch();
	return;
}
int main(int argc,char* argv[])
{
char cc=27;
int fun;
	if(argc>1)
	{
		puts("参数提示：timer_task.exe [1\\2\\3\\4] [argument1:item;item...] [argument2:...] [start_now]");
		string f=argv[1];
		if(f[0]<'1'||f[0]>'4')
		{
			puts("invalid command!");
			system("pause");
		}
		else fun=f[0];
		printf("argument 1:%s\n",argv[1]);
		for(int i=2;i<argc;i++)
		{
			printf("argument %d:%s\n",i,argv[i]);
			fold[i]=argv[i];
		}
		switch(fun)
		{
			case '1':
				timer();
			break;
			case '2':
				timer_task();
			break;
			case '3':
				clock_();
			break;
			case '4':
				ep();
			break;
			case '#':
				puts("命令行参数：timer_task.exe [1\\2\\3\\4] [argument1:item;item...] [argument2:...] [start_now]");
			break;
			default:
				return 0;
			break;
		}
		//system("pause");
		return 0;
	}
	while(cc==27)
	{
		system("mode con cols=80 lines=25");
		cout<<"AUTO TIMER\n";
		printf("1:chrono   \t秒表\n2:timer_task\t定时任务执行器\n3:clock   \t倒计时时钟\n4:eyesprotecter\t休息提醒器\n#命令行\ndefault:EXIT\n\n");
		cc=getch();
		switch(cc)
		{
			case '1':
				timer();
			break;
			case '2':
				timer_task();
			break;
			case '3':
				clock_();
			break;
			case '4':
				ep();
			break;
			case '#':
				puts("命令行参数：timer_task.exe [1\\2\\3\\4] [argument1:item;item...] [argument2:...] [start_now]");
			break;
			default:
				return 0;
			break;
		}
		cout<<"ESC返回，其他退出\n";
		cc=getch();
	}system("mode con cols=80 lines=25");
	return 0;
}
	
