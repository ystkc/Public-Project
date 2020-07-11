#include<iostream>
#include<ctime>
#include<windows.h>
using namespace std;
string st[1005];
int cnt;
int main()
{
	cout<<"AUTO TIMER(STARTUP)\n";
	
	cout<<"请输入执行命令\nEOF结束\n";
	while(st[cnt]!="EOF")
	{
		getline(cin,st[++cnt]);
	}
	
	time_t t = time(0);
    char tmp[64];
    strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A \n本年第%j天 %z",localtime(&t) );
	puts( tmp );
	int h,m,s;
	cout<<"目标启动时间(hh:mm:ss)?\nWarning:只限当天内,至少2min\n";
	scanf("%d:%d:%d",&h,&m,&s);
	system("cls");
	cout<<"开始计时...\n["<<max(0,((h-((tmp[11]-'0')*10+tmp[12]-'0'))*3600+(m-((tmp[14]-'0')*10+tmp[15]-'0'))*60+(s-((tmp[17]-'0')*10+tmp[18]-'0'))-120))<<"s(+120s)]\n";
	Sleep(max(0,((h-((tmp[11]-'0')*10+tmp[12]-'0'))*3600+(m-((tmp[14]-'0')*10+tmp[15]-'0'))*60+(s-((tmp[17]-'0')*10+tmp[18]-'0'))-120)*1000));
	cout<<"即将执行(2min)\a\n["<<min(120,((h-((tmp[11]-'0')*10+tmp[12]-'0'))*3600+(m-((tmp[14]-'0')*10+tmp[15]-'0'))*60+(s-((tmp[17]-'0')*10+tmp[18]-'0'))))<<"s]\n";
	Sleep(min(120*1000,((h-((tmp[11]-'0')*10+tmp[12]-'0'))*3600+(m-((tmp[14]-'0')*10+tmp[15]-'0'))*60+(s-((tmp[17]-'0')*10+tmp[18]-'0')))*1000));
	cout<<"开始执行tasklist\n\n\a";
	//task list??
	{
//		system("taskkill /pid java.exe /f");
//		system("shutdown -s -t 60 -c !!!");
		for(int i=1;i<cnt;i++)
		system(st[i].c_str());
	}
	cout<<"\n执行完毕\n";
	system("pause");
	return 0;
}
