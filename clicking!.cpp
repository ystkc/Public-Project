
/**----------------------------------------------------------------
Clicking_System() **������**
About{
Create:lz
Coded:V1.0 to latest:lz
Debug:V1.0 to latest:lz
Other license:
//The first run will be interrupted because of the initialize of "options.txt".
//Run _example() to learn to use or ask the editor.
//You can edit it as you like,and you'd better tell lz about it.
//I will be thankful if you discover any bug in it.

PS:��û��װ�ƣ������Լ�����awa... 

--������(clicking)��linzeԭ������Ҫ�⴫��֪ͨ���ߣ���л��ϣ�
�������Ҫ������Ϊ������߽�����Ϊ������;�������ˣ���ֻ��ע��ԭ���߼��ɡ�
����ʵ��Ҳֻ�Ǳ����棬û��ı���������˼���⻹���Ա��������Ͽɣ�Ϊʲô���أ���
��ϵ���ߣ�qq:1612162886(��֤��Ϣע������ͨ������ע�ҵ���)�����ID��43845����OIer����luogu����
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
//��ɫ�ο� 
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
//!!!:���������������˳�򣬷������Ը�! 
//struct csysb{int k,wd;};
struct CWCN{int dl,wd,ls;}tcwcn;

const char Cnp=''/*(char)1:USE IT if you need to recognize the next two char as a chinese*/,Endnp='}';
string Msbl[]={"|","*","#","+",""," ","  ","��","��","��","��","��","��","�w","��","��","��","��","��","��","��","��","?","?","?"},Msbt[]={"-","*","#","+",""," ","  ","��","��","��","��","��","��","�w","��","��","��","�{","��","��","��","��","?","?","?"};
string Wdbdsl[]={"|","*","#","+"," ","!","?","'",".","+"},Wdbdst[]={"-","*","#","+"," ","!","?","'",".","="};
const char Ch0[]="��",Ch1[]="��",En0[]="+",En1[]="*",Sp0[]="�p",Sp1[]="#";//�����ʽ (1����ǻ�ȫ���ַ�)
const string OptionsForge="[DoNOTModify]Identifier:ClickingVersonsV2.6-By LZ-\n[WindowPosition](left,width,top,heigh)\n4\n-1 -1 -1 -1\n[Trans;wOldColorAttrs]\n4\n1 7 8 16\n[EOUT:EoutDelay,IDDTFP]\n2\n7 25\n[WindowVerson](<8:0;>7:1)\n1\n0\n[ProcessName](Format:*.exe)\n-1\nclicking!.exe\n"/*0 0 677 459*/,Verson="ClickingVersonsV2.6\nCreated by Lz\n",Licenses="License:\n \n ----------------------------------------------------------------\n Clicking_System()\n About{\n Create:lz\n Coded:V1.0 to latest:lz\n Debug:V1.0 to latest:lz\n Other license:\n //The first run will be interrupted because of the initialize of 'options.txt'.\n //Run _example() to learn to use or ask the editor.\n //You can edit it as you like,and you'd better tell lz about it.\n //I will be thankful if you discover any bug in it.\n \n PS:��û��װ�ƣ������Լ�����awa... \n \n --������(clicking)��linzeԭ������Ҫ�⴫��֪ͨ���ߣ���л��ϣ�\n �������Ҫ������Ϊ������߽�����Ϊ������;�������ˣ���ֻ��ע��ԭ���߼��ɡ�\n ����ʵ��Ҳֻ�Ǳ����棬û��ı���������˼���⻹���Ա��������Ͽɣ�Ϊʲô���أ���\n ��ϵ���ߣ�qq:1612162886(��֤��Ϣע������ͨ������ע�ҵ���)�����ID��43845����OIer����luogu����\n }\n \n **������**\n Help:[2019.7.19]\n ����������һ����DIY��ӵ�������ƹ��ܵĳ��������ͨ����������Ƴ��򣬸�����������������ʹ�ü���\n �̳�������(r��ng)��������£�\n \n �������ǽ̳̣�������������ߣ��뿴�٣��������ʹ���ߣ��뿴�ڡ�\n \n \n \n \n \n \n \n \n�٣�\n 	\n 	��Ҫ��һ�������Լ��������Ƴ����𣿣��Ͻ����¿��ɣ�\n 	\n 	���������������飺1.�˵�д������2.�˵�ִ�У�ѡ������3.����ѡ������\n 	��Ȼ�������кܶ��ĸɻ������ǳ����߳��ȶ��ͱ����������ǣ������鵥�����á�\n 	\n 	�����ݹ�����\n 	string Msbl[]={'|','*','#','+','',' ','  ','��','��','��','��','��','��','�w','��','��','��','��','��','��','��','��','?','?','?'},Msbt[]={'-','*','#','+','',' ','  ','��','��','��','��','��','��','�w','��','��','��','�{','��','��','��','��','?','?','?'};\n 	string Wdbdsl[]={'|','*','#','+',' ','!','?',''','.','+'},Wdbdst[]={'-','*','#','+',' ','!','?',''','.','='};\n 	const char Ch0[]='��',Ch1[]='��',En0[]='+',En1[]='*',Sp0[]='�p',Sp1[]='#';//�����ʽ (1����ǻ�ȫ���ַ�)\n 	\n 	//��ɫ�ο� \n 	FOREGROUND_BLUE 0x1 ��ɫ��\n 	FOREGROUND_GREEN 0x2 ��ɫ��\n 	FOREGROUND_RED 0x4 ��ɫ��\n 	FOREGROUND_INTENSITY 0x8��������\n 	BACKGROUND_BLUE 0x10 ��ɫ����\n 	BACKGROUND_GREEN 0x20 ��ɫ����\n 	BACKGROUND_RED 0x40 ��ɫ����\n 	BACKGROUND_INTENSITY 0x80�������� \n 	\n 	\n 	��������￪ʼ������α�һ�������Ƴ���Ĺ����ˣ����ſ���ȥ���㿴��\n 	��Step1.\n 	1.void cwd(int wd,int wdbds,string wdtp,int cwl,int cwt,int cwr,int cwb)//window writing system���ڴ���ϵͳ\n 	2.void cw(int wd,int x,int y,string s,int ct,string cm,int cml,int cmt,int cmdl,int cmmd,int cmbds,int cl)//menu writing system�˵�д��ϵͳ*\n 	\n 	\n 	�÷���cwd���ڴ������ڣ�cw����д����������ִ�еĲ˵���Ҳ��������Ļ�ϻ���ʾ�Ķ�����\n 	��ע��Ҫ�ȴ�������д��\n 	����:1:	wd����Ĵ��ڱ�ţ������ֻ��һ�����ڣ����д��1�������������\n 	wdbds:��Ĵ��ڱ߿���ʽ�������������Wdbdsl��Wdbdstѡһ�ԣ�������һһ��Ӧ�ģ���д�����������еĵڼ�����\n 	wdtp:��Ĵ��ڱ��⣨���õ��ģ������Ѿ������Զ������ˣ�����Ҫע�ⲻ�ܳ������ڿ�ȣ�\n 	cwl:��Ĵ��������꣨��Ĵ�����ʾ����ʱ����߿�����꣩\n 	cwt:��Ĵ��������꣨ȫ��ͬ�ϣ�\n 	cwr:�����꣨ȫ��ͬ�ϣ�\n 	cwb:�����꣨ȫ��ͬ�ϣ�\n 	2:	wd:��Ĵ��ڱ�ţ��㴴���Ĵ��ڵı�ţ�\n 	x,y:���ֵ���ʼ�����꣨�Ǿ��������������Դ���λ�����꣩\n 	s:�����������\n 	ct:����ֵ��������������ʱ�����᷵��һ��ʲôֵ�������Ҫ�������أ����ǵ���Ҳû��Ӧ������0����Ҫ�������Ϊ�����Ǳ���ֵ��\n 	cm:����ע�ͣ�����������ͣ��������ʱ�ᵯ��һ��С������ʾ�ţ������Ҫ����''��Ȼ�������cml,cmt,cmdl,cmmd,cmbds��������0��\n 	cml,cmt:ע�͵�λ�ã��������꣩�������������������-1��������Զ��������\n 	cmdl:������ͣ�������������ʱ�����ʾע�ͣ���λms��\n 	cmmd:ע����ʽ��0��Ĭ�ϣ�1:3D��2:������Ļ�������Լ����Կ�����\n 	cmbds:ע�ͱ߿�ģʽ�����Դ�Msbl��Msbt����ѡһ�ԣ��ʹ��ڱ߿���ʽ����һ����\n 	cl:ע����ɫ����д��ʱ�������FOREGROUND_BLUE...Ҳ������0x1...�����Ҫ��ɫ�Ļ�����������֮��Ӹ�'|'��\n 	��Step2.\n 	1.void ent(int dl/*LEAST 50!*/,int wd,int ls,int wt)//menu choosing system starter�˵�ѡ��ϵͳ��������* \n 	\n 	�÷���ent������������ѡ��������\n 	����:1:dl:ˢ�¼��ʱ�䣨������������÷�Ӧһ�Σ�������������λms�����鲻С��50ms��\n 	wd:���ڱ��\n 	ls:����ֵ�ɳ����ԣ�����������һ����Чѡ�񣨾���ǰ���ct>0���Ժ����ls=1����ô�˵��᷵��ֵ��������У��������᷵��ֵ���˳���\n 	wt:�Ƿ������̣߳����wt=1��ô��Ҫ������˵���ֵ�����ˣ��˳��ˣ���ĳ�����ܼ������У����wt=0����ô��ĳ�����Լ������У���������Ϊ����һ���߳�������\n 	\n 	��Step3.\n 	�˽����������÷�֮�󣬽��ܼ���������\n 	1.Enabled(bool)		���������ѡ���������ʱ���Ϊtrue(1),�˳�ʱ���Ϊfalse(0),���ǣ��������������ʱͨ������������������EnabledΪ0��ֹͣ��\n 			����Ϊ�˷�ֹ���룬����ĩβһ��Ҫ�ǵ�Enabled=0�������������Ļ�Ͽ���һ���ַ����������صĻᵼ���ڴ�й©\n 	2.dqx,dqy(short int)	��������ָ��ǰ������ڵ����꣨Ȼ������ûʲô�ã�\n 	3.ww(string)		����ַ���ָ���Ǵ��ڵ�����˳�����ϵ���ָ0~size()-1����������Ϊ��������ʱˢ�£����Խ���ֻ�Ƕ�ȡ����Ҫ����\n 	��4.chv[](int[])	�ܶ�ͬѧ�����ʣ���Ȼ�Ƕ��̣߳�����ֵ����ô��ȡ�����Ҷ�Ϊ�����ȡ����ֵ�Ĳ���е����ģ��������ģ����صذ����з���ֵ��������������ȱ����˷������У��ֿ��Կ�������ֵ��\n 			Ҫ��ȡ����ֵʱ��chv[0]���ܸ������������ֵ��0��ô����û�з���ֵ��,���������������:while(chv[0]==0)Sleep(100)����ִ�����Լ�����䣬����ѭ����дһ��xxx=chv[chv[0]--(һ��Ҫ�ǵ�--)]�������\n 	��5.ccv(int)		���������ָ���ͣ���ڵ������ϵ�ֵ������û�е���ȥҲ��ȡ�õ�ֵ����������ѭ������if(ccv==...)ִ��\n 			������������Ҫ��һ�������õ���;���������ֵ��ĳ�����ֵ�ֵ����ô������cw���Ա�дһ�仰����ʾ�ã���������ЧѸ�ٵط���\n 	��6.tasks_sys[](int[])	��Ϊ���߳����е�ʱ�������ĳ��������һ��ʲô�ͻᵼ�¹���λ�������뵽�˸��취\n 		����Ҫ���ܼ���������\n 		1.spclr(int wd)��������ʾ����,wd�Ǳ�ţ�\n 		2.wcrr(int wd)������ɾ��һ�����ڣ�Ȼ��ɾ���Ĵ��ھͻ�������ʧ�����������´���д�룩\n 			��Ϊ��ʱ�򻥶���Ҫ������Ҫ��ʾһ�����ڻ���ɾ��һ�����ڣ�����������������\n 			�����Ҫ��ʾһ������:tasks_sys[++tasks_sys[0]]=���ڱ��\n 			�����Ҫɾ��һ������:tasks_sys[++tasks_sys[0]]=���ڱ�ŵ��෴�������ǼӸ����ţ�\n 	7.movable_sys[](bool[])	��������ǿ����϶����ڵģ������е��������������Ҫ��ֹ��Ĵ��ڱ��ƶ�������Ե���lock(��Ĵ��ڱ��)����movable_sys[���]=1;Ҫ�����Ļ�ֻ���ٵ���һ��lock(���)��movable_sys[���]=0����\n  8.fsx,fsy	������������ָ����̨�������С����������λ���أ�������������-����-��С �鿴���������ޣ�û������Զ�У׼ϵͳ�����Ҫ����Ҫ�ڳ������\n 	������������Щ����������options.txt�޸ģ���ʾ��options.txt���Զ����֣�������ᣩ\n 	8.ial,iar,iat,iab	���ĸ�������ָ���ڣ��ǿ���̨����������������̵Ĵ��ڣ����󡢿��ϡ��ߣ�ע��˳�򣩣�������������+1�����ĸ�-1����\n 	9.Trans			(transparent ͸��)�����Trans=0����ô�㽫�޷������ǽ��㣨�����ں���ģ����ڡ����������ĵ������ؿ��٣����Խ����޸�Ϊ0��\n 	10.wOldColorAttrs	(Window Old Color Attributes ����Ĭ����ɫ����)���鲻Ҫ�ģ�Ĭ��7���������뿴��һ����ɫ����ɫ����ɫΪ�����Ĵ��ڣ�\n 	11.EoutDelay		��˵ע�������и�ģʽ��������Ļ��������������ǿ�������������ģ�Խ��Խ��������λms\n 	12.IDDTFP		(��������д�����ұ�� ֹͣע��ƫ��)��������Ļ�������ʱ������㲻�뿴����ô�죿�ǲ���Ų����ꣿ�Եģ���ֻ��ҪŲ��IDDTFP���ؾͿ���ֹͣ�ˣ�������֪�����Ǹ�����˰ɣ�\n 	13.WindowVerson		Win10�û�ע���ˣ�\n 			��˵��Win10��ʼ��΢��ʳ������ģ�Ϊ�й��ͻ���Win10������������˸����һ��������Ϊ�˷�ֹ���������г����룩��\n 			������Ͱ��ҵĳ����ɵ�ˣ�������Ļȫ��û��������û�ҵ���ȫ֮�ߡ�����ֻ���ټ�һ���������������Win10�û�������ĳ�1\n 	�︽.\n 	ǰ��������и�����������ѡ������������Ϊ��������Ҵ�V2���Ҿ��Ѿ�����ˣ�������û�Ĺ���������������ܡ�������Ȼ�е��ô���Ҳ����һ�¡�\n 	void cost(int left,int top,int right,int down,int &px,int &py)//area selecting����ѡ��* \n 	\n 	�÷�����Ļ���ڣ�����Ҫ���������һ�£��ͻ���ʾʮ��׼�ǣ����ų���᷵����ѡ������ꡣ������������ѡ��\n 	���ͣ�	left,top;right,down:ѡ������������������������ô���Ͳ�����ʾʮ��׼�ǣ�\n 	px��py�����������������ڴ��صģ�����Ҫ�д���ֵ������ᱻ����\n 	--��LZ��д \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n�ڣ�\n 	Ҫʹ��һ�������Ƴ���ܼ򵥣���������Ҫ�õ����̣�������Ǳ�д��Ҳ�����㿴һ�£� \n 	���ȣ���Ҫ���ݳ�����ʾ���ȵ��㿴������������һ��'+'ʱ���������������ˣ������д���Զ����˹���������ۣ� \n 	�����Ҫѡ��һ��ѡ���ֻ��Ҫ����Ǹ����ּ��ɡ�\n 	�������֪��ĳ��ѡ��İ�����1.�����������ͣ��һ�ῴ�Ƿ�ᵯ��һ�����ڣ�ע�ͣ���\n 	2.���������ͣ������ʱ�᲻�����Աߣ�������һ�����ڣ���ʾһ��ʲô \n 	����������ò�������ʵȡ���ڱ�д�����ˣ������ճ������ʾ��\n 	 --��LZ��д \n 	 \n \n \n \nUpdate:\n \n --������(clicking)��linzeԭ������Ҫ�⴫��֪ͨ���ߣ���л��ϣ�\n  \n V0.1/*�װ�*/\n congratulation!Clicking()���������ˣ��޸�����������ʾ������Lz���һ����������ƶ���C++����Ŷ��\n V1.0/*2019�����ؼ�*/\n ��������Ĳ������ȷ���ͼ�¼�˳�ʼ����λ�ú���ɫ��\n V1.1\n Lz���������˴����ƶ����޸��˴󲿷�BUG�������㣨������͵���ˣ���׼�����ע�Ͳ����\n V2.0/*2019�����ؼ�*/\n ð�ű�*��Σ�գ��ɹ����ע�Ͳ����ע�͹��ܶ��������߱���ʱˢ�¹��ܣ�����̽���ɣ�\n V2.1\n SetConsoleTextAttribute(OPhandle,0x20|0x80)����������������ɫ�ı�ǩ����\n V2.2\n ����˱�ǩ���޸��˳���©����Debug����Խ��Խ���˺Ǻǣ����������Ǹ���Ϣ��ʶ�֣����ģ�������\n ��Ϊpsy���飬����˷�ֹwin10��������Ļ���ֿ�������Ĳ���������win10�ȶ�ģʽ\n V2.3\n ����˴��ڹ��ܣ�������Ѫ��������֪��xy����õ�Σ���ˣ�qwqץ��һ���ڳ��棩������ץ��һ�������ע�;����ص�bug��������������������ˡ�������ʱһ�������񡣻������˺�����������\n ����һ�����ȵط��֣�clicking�Ѿ���ը�ڴ��ˡ���119688kb��116.87890625MB���������õ��ԹܼҼ��ٺ�ʣ396kb������1MB�����������ĸо�\n V2.3��ʼ���Թ�����~AWA~����Ϊ¥���Ĺ����Ѿ�����ˣ�����Ҳûɶ�ô��ˣ�\n V2.4\n V2.3û�п���Trans��������Ƿ�����һ�����bug�������ٸ�һ������������Ҳ���˺ܶ࣬���Բ��ø����þ͸�������\n ����2.3��2.4��Ϊ��bug�����Ը���Ϊ2.5�Ź���������������V2.5��׼������̣߳��ٶ��ವģ�\n V2.5\n �ɹ���Ӷ��̣߳���Ȼ�����������˾޴��鷳�;޶�bug������ÿһ�ζ��кࣩܶ�����ǳɹ�Ϊ�����Ϸ���������������϶�ȡ�����ܺ��������ڣ��������϶������ܡ�\n ���صظ���һ���̳̣�lj������\n ��Ȼ��Щ����Ϊ����ͼ�ο���ô�������ø�java��VC������c++װ��EGE��Box2D�������ã���ʵ��Ҳ��ѧ����������ô˵�أ��и���������ڣ���awa���������Ƴ�����ͦ�д���İɡ�����\n �����ʱ��Ὣ��ת��Ϊͷ�ļ�������ʽ����V2.5[rep].rar\n V2.6\n ������С��\n �ϴα����������������һ�·�������һ�õ��ķ�Ӧ���������ô�ð���(...)����������������Ϊ��������ʹ�����ϰ�����ü���׼��ť������ϲ������Ų��ȥ�����Խ�����һЩЩ�Ķ���������Ϊ������Ҫ�����Σ���ĺܲң���һ����������fsx��fsy(�ҹ����Ժ󲻻��������Щ���ĵĶ�����)���ֻ���һ���硣��������һЩСbug\n ����˾���棨��ʵ����ɾ�˼���ע�͡���������Ϊ��ʱ�����СһЩ��ʹ��û��ô���������Ǹ������ͷ����ˣ�\n ����8.1�Ѿ������ˣ��������ž��ò��Ծ���8.18������ջ����͸ɣ������У׼�㶨�ˣ��Ҳ�����Ū���ˡ��������ġ����������������˶��ᴰ������\n \n V2.6��������2019.8.18\n \n \n \n \n #define �����ڴ�! ¥��lz��͵����!\n \n";
const int Ath[15]={67,79,68,69,68,32,66,89,58,76,105,110,90,101,46};

int Options[525][135],Optionstot,Optionstringtot,WinVer,Enabled;//�������ݣ�������Windows�汾���߳��Ƿ���������������
string Optionstring[105];
int mxl,mxh;/*msgbox() NEEDED*/
string ww=""/*��ǰ����˳��*/;
char cc;//����getch()�� 

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
const int EoutDelay=INTSc(3,1),IDDTFP=INTSc(3,2),WDD=15,WDLMT=205,Trans=INTSc(2,1),wOldColorAttrs=INTSc(2,2);//������Ļ��ʱ(!>5) ע����ֹƫ��  �����ۻ������� ���������С  �ǽ��㴰�ڿɼ���  Ĭ�ϴ���������ɫ 

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
inline string StCh(int k)//ת������Ϊ�ַ��� 
{
	string ans="";
	while(k)
	{
		ans=char((k%10)+'0')+ans;
		k/=10;
	}
	return ans;
}
void FontSizer()	//���������С��������������� 
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
		cout<<"�������޸�ע�������Ϊ��ʹ�����ʺϱ���������\n��Ҫ���ģ������options.txt�е�fsx��fsy\n";
		tmps="reg ADD HKCU\\Console /v FontSize /t REG_DWORD /f /d "+StCh(fsy*65536+fsx);
		system(tmps.c_str());
//		Pr((char*)"a.bat",1,"reg QUERY HKCU\\Console /v FontSize >que.txt");
		DD();
		tmps="if not exist \".\\"+Optionstring[1]+"\" echo �벻Ҫ�Ķ�exe�����֣��뽫��Ļأ�"+Optionstring[1]+"�������޷�����";
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
		printf("The Options(options.txt) have not be initialize or it is broken!\a\n��������δ��ʼ��\n����Ҫ����������������������\n");
		TDCyan();
		printf("If you first get the progress,don't be afraid.Just RESTART.\n�������ʾ�ظ����֣�����ϵLz\n");
		Rst:;
		TRed();BDYellow();
		cout<<"Please RESTART LATER\n���Ժ������ó���\n";
		BGreen();TDPink();
		cout<<"\nVERSON:"<<Verson<<"\nReWriting...\n";
		if(!Pr((char*)"*A",0,""))
		{
			TDRed();
			MessageBox(hwnd,"E.1:��ʼ������","Process Erruption",MB_OK);
			cout<<"Initialize faild\a\t[Any key to continue]\nPlease contact the author\n�����»�ȡ";
			char cc=getch();
			in.close();
			exit(0);
			return 0;
		}
		TDGreen();
		cout<<"Initialize succeed\t[Any key to continue]\n[���������]\t";
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
	GetConsoleCursorInfo(OPhandle, &CursorInfo);//��ȡ����̨�����Ϣ
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
inline void gotoxy(int x,int y)//cursor position setting���λ������ 
{
	SetConsoleCursorPosition(OPhandle,(COORD){x,y});
}

//INITIALIZE COMPLETED----------------------------------------------------------------


void eout(string s,int sx,int sy)//Thank YYC for this code--lighting subtitles!������Ļ 
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
          cout<<"\b��";
          if (!kbhit())
           Sleep(p);
          if(WinVer)cout<<"\b ��";
          else cout<<"\b\b ��";
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
void cost(int left,int top,int right,int down,int &px,int &py)//area selecting����ѡ��* 
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
void msgbox(int wd,int sx,int sy,int cl,string msg,int md,int bdstyle)//MessageBox��Ϣ�� 
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
void cw(int wd,int x,int y,string s,int ct,string cm,int cml,int cmt,int cmdl,int cmmd,int cmbds,int cl)//menu writing system�˵�д��ϵͳ*
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
void cwd(int wd,int wdbds,string wdtp,int cwl,int cwt,int cwr,int cwb)//window writing system���ڴ���ϵͳ
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
void* chw(void* cwcn)//menu choosing system�˵�ѡ��ϵͳ* 
//cwcn�������̵߳Ĵ��� 
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
		if(cz_sys[bs][dqy][dqx]>0)ccv=cz_sys[bs][dqy][dqx];		//��Чֵ
		if(cz_sys[bs][dqy][dqx]!=-1)ccvn=cz_sys[bs][dqy][dqx];	//��ʱֵ

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
void ent(int dl/*LEAST 50!*/,int wd,int ls,int wt)//menu choosing system starter�˵�ѡ��ϵͳ��������* 
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
cwd(3,2,"��ʾ",35,0,55,20);
system("mode con cols=80 lines=25");
 cw(1,1,1,"-------------�˵�-------------",0,"���Ҹ���awa}��ֻ��һ������...",-1,-1,1000,1,3,0x2|0x8);
 cw(1,3,15,"��ʼplay",1,"�������ʼ��Ϸ}�ȵȣ�¥����û����Ϸ��qwq",-1,-1,0,1,0,0x4|0x1|0x8|0x80|0x20);
 cw(1,6,15,"�˳�exit",2,"�����˳�",-1,-1,0,0,0,wOldColorAttrs);
 cw(1,10,5,"����һ���µĴ���awa",3,"������}...}!",-1,-1,500,1,7,0x4);
 cw(1,11,5,"����\\��������",4,"",0,0,0,0,0,wOldColorAttrs);
 cw(1,7,1,"���ʾ��:���+*�p#",15,"�ÿ���}����㲻���⣬����ͨ���������еġ������ʽ������}���ֶ�����ֻ���벻��û����������}",8,15,600,2,21,0x2|0x10|0x8|0x80);
 cw(3,2,36,"Ų��������~",5,"�Ҳ��ҵ���һ��",0,0,0,0,0,wOldColorAttrs|0x8);
 cw(3,18,36,"�ر�",6,"",0,0,0,0,0,wOldColorAttrs|0x8|0x4);
 cw(3,16,36,"�鿴����\\�汾��Ϣ",20,"",0,0,0,0,0,0x8);
 tasks_sys[++tasks_sys[0]]=3;lock(3);
 gotoxy(0,0);ent(50,1,1,0);
 while(ans!=2&&Enabled)
 {
 	while(!chv[0])
	 {
	 	Sleep(100);
	 	if(ccv==1)
	 	{
	 		cw(3,5,36,"������������}����û����Ϸ}�����Լ�дѼ��",0,"",0,0,0,0,0,0x2|0x8);
	 		while(ccvn==1&&!chv[0])Sleep(50);
	 		cw(3,5,36,"              }            }              ",0,"",0,0,0,0,0,0);
		 }
		if(ccv==6)
	 	{
	 		cw(3,5,36,"����������˼}�ص��Ļ�}û����ʾ��Ŷ...",0,"",0,0,0,0,0,0x4|0x8);
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
		 	cw(3,5,36,"��ϧ��}��ֻ���ڳ��������",0,"ûʲô�ÿ���",-1,-1,0,0,1,0x1|0x8|0x20|0x80);
	 		while(ccvn==15&&!chv[0])Sleep(50);
	 		cw(3,5,36,"      }                  ",0,"",0,0,0,0,0,0);
		 }
	 }
 	ans=chv[chv[0]];chv[0]--;
 	if(ans==3){
 		cwd(2,1,"I AM THE ����",10,7,25,15);
 		cw(2,8,11,"�ص�",9,"�㰡}��ʵ�������ļ�Ҳ��ص�qwq",-1,-1,0,0,0,wOldColorAttrs);
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
	cout<<"������������\n(��ǰ����)"<<fsx<<" "<<fsy<<endl;
	cout<<"��ø�������밴 H \n�ۿ�ʵ���밴 E \n";
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
