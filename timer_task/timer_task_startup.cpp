#include<iostream>
#include<ctime>
#include<windows.h>
using namespace std;
string st[1005];
int cnt;
int main()
{
	cout<<"AUTO TIMER(STARTUP)\n";
	
	cout<<"������ִ������\nEOF����\n";
	while(st[cnt]!="EOF")
	{
		getline(cin,st[++cnt]);
	}
	
	time_t t = time(0);
    char tmp[64];
    strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A \n�����%j�� %z",localtime(&t) );
	puts( tmp );
	int h,m,s;
	cout<<"Ŀ������ʱ��(hh:mm:ss)?\nWarning:ֻ�޵�����,����2min\n";
	scanf("%d:%d:%d",&h,&m,&s);
	system("cls");
	cout<<"��ʼ��ʱ...\n["<<max(0,((h-((tmp[11]-'0')*10+tmp[12]-'0'))*3600+(m-((tmp[14]-'0')*10+tmp[15]-'0'))*60+(s-((tmp[17]-'0')*10+tmp[18]-'0'))-120))<<"s(+120s)]\n";
	Sleep(max(0,((h-((tmp[11]-'0')*10+tmp[12]-'0'))*3600+(m-((tmp[14]-'0')*10+tmp[15]-'0'))*60+(s-((tmp[17]-'0')*10+tmp[18]-'0'))-120)*1000));
	cout<<"����ִ��(2min)\a\n["<<min(120,((h-((tmp[11]-'0')*10+tmp[12]-'0'))*3600+(m-((tmp[14]-'0')*10+tmp[15]-'0'))*60+(s-((tmp[17]-'0')*10+tmp[18]-'0'))))<<"s]\n";
	Sleep(min(120*1000,((h-((tmp[11]-'0')*10+tmp[12]-'0'))*3600+(m-((tmp[14]-'0')*10+tmp[15]-'0'))*60+(s-((tmp[17]-'0')*10+tmp[18]-'0')))*1000));
	cout<<"��ʼִ��tasklist\n\n\a";
	//task list??
	{
//		system("taskkill /pid java.exe /f");
//		system("shutdown -s -t 60 -c !!!");
		for(int i=1;i<cnt;i++)
		system(st[i].c_str());
	}
	cout<<"\nִ�����\n";
	system("pause");
	return 0;
}
