
#ifndef CLICK_RELEASE
using namespace std;
#endif

#ifndef CBufferSize
	#warning:DEFINE CBufferSize={x,y} as *COORD* to define buffer size,or it will be {80,25}.
COORD CBufferSize={80,25};//���Ĵ��ڴ�СӦ���ڴ˴� 
#endif

//CSYS NORMAL SYMBOL!--------------------------------

#ifndef WDD//���������������Լ����壬�˴������ο� 
const int WDD=5;//�������� 
#endif
#ifndef WDLMT
const int WDLMT=205;//���ڴ�С�����ߣ� 
#endif

#ifndef CLICK_RELEASE
#ifndef CLICK_SIMPLE
const int junior=5;
#endif
#endif

char Ch0[]="��",Ch1[]="��",En0[]="+",En1[]="*",Sp0[]="�p",Sp1[]="#";//�����ʽ (1����ǻ�ȫ���ַ�)
const string Version="ClickingVersionsV2.7\nCreated by Lz\n"
			,Licence="Licence:\n\nClicking_System()\nAbout{\nCreate:lz\nCoded:V1.0 to latest:lz,yyc\nDebug:V1.0 to latest:lz\nContributor/cooperation:yyc\nOther Attentions:\n//Run _example() to learn to use or ask the editor.\n//You can edit it as you like,but not in commercial usage.\n//I will be thankful if you discover any bug in it.\n\nPS:��û��װ�ƣ������Լ�����awa... \n\n--������(clicking.cpp;clicking.exe)�Լ��̳�(Note.txt��Tutor.txt)��lzԭ����\n\n����Ʒ����֪ʶ��������-����ҵ��ʹ��-��ͬ��ʽ���� 4.0 ��������Э��������ɡ�\nThis project is licensed under the Creative Commons Attribution BY - NC - SA 4.0 international license agreement.\nmore information ��https://creativecommons.org/licenses/by-nc-sa/4.0/\n����Խ��иı࣬���������Ϊ������;���������ˣ�����ע��ԭ���ߣ�����������ҵ��;����л��ϣ�\n*����Ʒָ�ļ����µ�����cpp,exe��txt�ļ�\n\n����ʵ��Ҳֻ�Ǳ����棬û��ı���������˼���⻹���Ա��������Ͽɣ����������Ա����������Ϊʲô���أ���\n��ϵ���ߣ�qq:1612162886(��֤��Ϣע������ͨ������ע�ҵ���)�����ID��43845����OIer����luogu����\n}\n";
#ifndef CLICK_SIMPLE
const string OptionsForge="[DoNOTModify]Identifier:ClickingVersionsV2.7-By LZ-\n[WindowPosition](left,width,top,heigh)\n4\n-1 -1 -1 -1 \n[Trans;wOldColorAttrs;CFontSizeX;CFontSizeY;FocusVisible]\n5\n1 7 8 16 2 \n[EOUT:EoutDelay,IDDTFP]\n2\n7 25\n[WindowVersion](<=Win7:0;>Win7:1)\n1\n0 \n[ProcessName](Format:*.exe)\n-1\nclicking!.exe\n[FontSize](Format:X1 Y1 X2 Y2...)\n12\n3 5 5 8 6 12 8 16 8 18 10 20\n[FontInfo](Format:x1 y1 x2 y2...)\n12\n2663 517 1600 325 1327 208 2000 426 1000 142 800 125\n[FontIndex](Format:n1 0 n2 0...)\n12\n0 0 2 0 7 0 1 0 13 0 15 0 \n\n\n"
/*������Ϣ*/,Note="Version:\n\nClickingVersionsV2.7\nCreated by Lz\n\n----------------------------------------------------------------\n\n\n**������**\n\nUpdate:\n \nV0.1/*�װ�*/\ncongratulation!Clicking()���������ˣ��޸�����������ʾ������Lz���һ����������ƶ���C++����Ŷ��\nV1.0/*2019�����ؼ�*/\n���������Ĳ������ȷ���ͼ�¼�˳�ʼ����λ�ú���ɫ��\nV1.1\nLz���������˴����ƶ����޸��˴󲿷�BUG�������㣨������͵���ˣ���׼������ע�Ͳ����\nV2.0/*2019�����ؼ�*/\nð�ű�*��Σ�գ��ɹ�����ע�Ͳ����ע�͹��ܶ��������߱���ʱˢ�¹��ܣ�����̽���ɣ�\nV2.1\nSetConsoleTextAttribute(COutputHandle,0x20|0x80)����������������ɫ�ı�ǩ����\nV2.2\n����˱�ǩ���޸��˳���©����Debug����Խ��Խ���˺Ǻǣ����������Ǹ���Ϣ��ʶ�֣����ģ�������\n��Ϊpsy���飬�����˷�ֹwin10��������Ļ���ֿ�������Ĳ����������win10�ȶ�ģʽ\nV2.3\n�����˴��ڹ��ܣ�������Ѫ��������֪��xy����õ�Σ���ˣ�qwqץ��һ���ڳ��棩������ץ��һ��������ע�;����ص�bug��������������������ˡ�������ʱһ�������񡣻������˺�����������\n����һ�����ȵط��֣�clicking�Ѿ���ը�ڴ��ˡ���119688kb��116.87890625MB���������õ��ԹܼҼ��ٺ�ʣ396kb������1MB�����������ĸо�\nV2.3��ʼ���Թ�����~AWA~����Ϊ¥���Ĺ����Ѿ�����ˣ�����Ҳûɶ�ô��ˣ�\nV2.4\nV2.3û�п���Trans��������Ƿ�����һ�����bug�������ٸ�һ������������Ҳ���˺ܶ࣬���Բ��ø����þ͸�������\n����2.3��2.4��Ϊ��bug�����Ը���Ϊ2.5�Ź���������������V2.5��׼�������̣߳��ٶ��ವģ�\nV2.5\n�ɹ����Ӷ��̣߳���Ȼ�����������˾޴��鷳�;޶�bug������ÿһ�ζ��кࣩܶ�����ǳɹ�Ϊ�����Ϸ����������������϶�ȡ�����ܺ��������ڣ��������϶������ܡ�\n���صظ���һ���̳̣�lj������\n��Ȼ��Щ����Ϊ����ͼ�ο���ô�������ø�java��VC������c++װ��EGE��Box2D�������ã���ʵ��Ҳ��ѧ����������ô˵�أ��и���������ڣ���awa���������Ƴ�����ͦ�д���İɡ�����\n�����ʱ��Ὣ��ת��Ϊͷ�ļ�������ʽ����V2.5[rep].rar\nV2.6\n������С��\n�ϴα����������������һ�·�������һ�õ��ķ�Ӧ���������ô�ð���(...)����������������Ϊ��������ʹ�����ϰ�����ü���׼��ť������ϲ������Ų��ȥ�����Խ�����һЩЩ�Ķ���������Ϊ������Ҫ�����Σ���ĺܲң���һ����������CFontSizeX��CFontSizeY(�ҹ����Ժ󲻻���������Щ���ĵĶ�����)���ֻ���һ���硣��������һЩСbug\n�����˾���棨��ʵ����ɾ�˼���ע�͡���������Ϊ��ʱ�����СһЩ��ʹ��û��ô���������Ǹ������ͷ����ˣ�\n����8.1�Ѿ������ˣ��������ž��ò��Ծ���8.18������ջ����͸ɣ������У׼�㶨�ˣ��Ҳ�����Ū���ˡ��������ġ����������������˶��ᴰ������\nV2.7(UNFINISHED,pre1) \n������һ�δ������ \n���ٶȽ����˸Ľ�����puts���ٶ�ʵ��̫�������ˣ� \n�������ܸ�ʽ֮��������������������������Ȼ�Թ��ܲ�û��ʲô�Ľ��� \n�����п������\n������һ����ֵ������õ����庯���������������������������clicking������Ӧ���ֵ���������\n��������ϵͳ���򿪳���ʱ��סTab���Խ��루��Ϊ�ж�ʱ��̣ܶ������֮ǰ�Ȱ�סTab��\n���ⷢ��һ��bug���Ұ����е�version���汾��д����verson������*INF��\nV2.7pre1��������2020.12.06\n\n\n\n\n#define �����ڴ�!  lz��͵����!\n\n"
			,Tutor="Help:[2019.7.19]ע��:����̳̽�ֻ������clickingV2.7pre1��V2.7��ʽ�潫�нϴ�Ķ�\n����������һ����DIY��ӵ�������ƹ��ܵĳ��������ͨ����������Ƴ��򣬸�����������������ʹ�ü���\n�̳�������(r��ng)��������£�\n\n�������ǽ̳̣�������������ߣ��뿴�٣��������ʹ���ߣ��뿴�ڡ�\n\n\n\n\n\n\n\n\n�٣�\n	\n	��Ҫ��һ�������Լ��������Ƴ����𣿣��Ͻ����¿��ɣ�\n	\n	���������������飺1.�˵�д������2.�˵�ִ�У�ѡ������3.����ѡ������\n	��Ȼ�������кܶ��ĸɻ������ǳ����߳��ȶ��ͱ����������ǣ������鵥�����á�\n	\n	�����ݹ�����\n	string MessageboxLeftBoard[]={'|','*','#','+','',' ','  ','��','��','��','��','��','��','�w','��','��','��','��','��','��','��','��','?','?','?'},MessageboxTopBoard[]={'-','*','#','+','',' ','  ','��','��','��','��','��','��','�w','��','��','��','�{','��','��','��','��','?','?','?'};\n	string WindowLeftBoard[]={'|','*','#','+',' ','!','?',''','.','+'},WindowTopBoard[]={'-','*','#','+',' ','!','?',''','.','='};\n	const char Ch0[]='��',Ch1[]='��',En0[]='+',En1[]='*',Sp0[]='�p',Sp1[]='#';//�����ʽ (1����ǻ�ȫ���ַ�)\n	\n	//��ɫ�ο� \n	FOREGROUND_BLUE 0x1 ��ɫ��\n	FOREGROUND_GREEN 0x2 ��ɫ��\n	FOREGROUND_RED 0x4 ��ɫ��\n	FOREGROUND_INTENSITY 0x8��������\n	BACKGROUND_BLUE 0x10 ��ɫ����\n	BACKGROUND_GREEN 0x20 ��ɫ����\n	BACKGROUND_RED 0x40 ��ɫ����\n	BACKGROUND_INTENSITY 0x80�������� \n	\n	\n	��������￪ʼ������α�һ�������Ƴ���Ĺ����ˣ����ſ���ȥ���㿴��\n	��Step1.\n	1.void cwd(int wd,int wdbds,string wdtp,int cwl,int cwt,int cwr,int cwb)//window writing system���ڴ���ϵͳ\n	2.void cw(int wd,int x,int y,string s,int ct,string cm,int cml,int cmt,int cmdl,int cmmd,int cmbds,int cl)//menu writing system�˵�д��ϵͳ*\n	\n	\n	�÷���cwd���ڴ������ڣ�cw����д����������ִ�еĲ˵���Ҳ��������Ļ�ϻ���ʾ�Ķ�����\n	��ע��Ҫ�ȴ�������д��\n	����:1:	wd����Ĵ��ڱ�ţ������ֻ��һ�����ڣ����д��1�������������\n	wdbds:��Ĵ��ڱ߿���ʽ�������������WindowLeftBoard��WindowTopBoardѡһ�ԣ�������һһ��Ӧ�ģ���д�����������еĵڼ�����\n	wdtp:��Ĵ��ڱ��⣨���õ��ģ������Ѿ������Զ������ˣ�����Ҫע�ⲻ�ܳ������ڿ��ȣ�\n	cwl:��Ĵ��������꣨��Ĵ�����ʾ����ʱ����߿�����꣩\n	cwt:��Ĵ��������꣨ȫ��ͬ�ϣ�\n	cwr:�����꣨ȫ��ͬ�ϣ�\n	cwb:�����꣨ȫ��ͬ�ϣ�\n	2:	wd:��Ĵ��ڱ�ţ��㴴���Ĵ��ڵı�ţ�\n	x,y:���ֵ���ʼ�����꣨�Ǿ��������������Դ���λ�����꣩\n	s:�����������\n	ct:����ֵ��������������ʱ�����᷵��һ��ʲôֵ�������Ҫ�������أ����ǵ���Ҳû��Ӧ������0����Ҫ�������Ϊ�����Ǳ���ֵ��\n	cm:����ע�ͣ�����������ͣ��������ʱ�ᵯ��һ��С������ʾ�ţ������Ҫ����''��Ȼ�������cml,cmt,cmdl,cmmd,cmbds��������0��\n	cml,cmt:ע�͵�λ�ã��������꣩�������������������-1��������Զ��������\n	cmdl:������ͣ�������������ʱ�����ʾע�ͣ���λms��\n	cmmd:ע����ʽ��0��Ĭ�ϣ�1:3D��2:������Ļ�������Լ����Կ�����\n	cmbds:ע�ͱ߿�ģʽ�����Դ�MessageboxLeftBoard��MessageboxTopBoard����ѡһ�ԣ��ʹ��ڱ߿���ʽ����һ����\n	cl:ע����ɫ����д��ʱ�������FOREGROUND_BLUE...Ҳ������0x1...�����Ҫ��ɫ�Ļ�����������֮��Ӹ�'|'��\n	��Step2.\n	1.void ent(int dl/*LEAST 50!*/,int wd,int ls,int wt)//menu choosing system starter�˵�ѡ��ϵͳ��������* \n	\n	�÷���ent������������ѡ��������\n	����:1:dl:ˢ�¼��ʱ�䣨������������÷�Ӧһ�Σ�������������λms�����鲻С��50ms��\n	wd:���ڱ��\n	ls:����ֵ�ɳ����ԣ�����������һ����Чѡ�񣨾���ǰ���ct>0���Ժ����ls=1����ô�˵��᷵��ֵ��������У��������᷵��ֵ���˳���\n	wt:�Ƿ������̣߳����wt=1��ô��Ҫ������˵���ֵ�����ˣ��˳��ˣ���ĳ�����ܼ������У����wt=0����ô��ĳ�����Լ������У���������Ϊ����һ���߳�������\n	\n	��Step3.\n	�˽����������÷�֮�󣬽��ܼ���������\n	1.CEnabled(bool)		���������ѡ���������ʱ���Ϊtrue(1),�˳�ʱ���Ϊfalse(0),���ǣ��������������ʱͨ������������������CEnabledΪ0��ֹͣ��\n			����Ϊ�˷�ֹ���룬����ĩβһ��Ҫ�ǵ�CEnabled=0�������������Ļ�Ͽ���һ���ַ����������صĻᵼ���ڴ�й©\n	2.CCurrentY,CCurrentX(short int)	��������ָ��ǰ������ڵ����꣨Ȼ������ûʲô�ã�\n	3.CWindowOrder(string)		����ַ���ָ���Ǵ��ڵ�����˳�����ϵ���ָ0~size()-1����������Ϊ��������ʱˢ�£����Խ���ֻ�Ƕ�ȡ����Ҫ����\n	��4.CChoseValue[](int[])	�ܶ�ͬѧ�����ʣ���Ȼ�Ƕ��̣߳�����ֵ����ô��ȡ�����Ҷ�Ϊ�����ȡ����ֵ�Ĳ���е����ģ��������ģ����صذ����з���ֵ��������������ȱ����˷������У��ֿ��Կ�������ֵ��\n			Ҫ��ȡ����ֵʱ��CChoseValue[0]���ܸ������������ֵ��0��ô����û�з���ֵ��,���������������:while(CChoseValue[0]==0)Sleep(100)����ִ�����Լ�����䣬����ѭ����дһ��xxx=CChoseValue[CChoseValue[0]--(һ��Ҫ�ǵ�--)]�������\n	��5.CCurrentValidValue(int)		���������ָ���ͣ���ڵ������ϵ�ֵ������û�е���ȥҲ��ȡ�õ�ֵ����������ѭ������if(CCurrentValidValue==...)ִ��\n			������������Ҫ��һ�������õ���;���������ֵ��ĳ�����ֵ�ֵ����ô������cw���Ա�дһ�仰����ʾ�ã���������ЧѸ�ٵط���\n	��6.CTasks_sys[](int[])	��Ϊ���߳����е�ʱ�������ĳ��������һ��ʲô�ͻᵼ�¹���λ�������뵽�˸��취\n		����Ҫ���ܼ���������\n		1.spclr(int wd)��������ʾ����,wd�Ǳ�ţ�\n		2.wcrr(int wd)������ɾ��һ�����ڣ�Ȼ��ɾ���Ĵ��ھͻ�������ʧ�����������´���д�룩\n			��Ϊ��ʱ�򻥶���Ҫ������Ҫ��ʾһ�����ڻ���ɾ��һ�����ڣ������������������\n			�����Ҫ��ʾһ������:CTasks_sys[++CTasks_sys[0]]=���ڱ��\n			�����Ҫɾ��һ������:CTasks_sys[++CTasks_sys[0]]=���ڱ�ŵ��෴�������ǼӸ����ţ�\n	7.CMovable_sys[](bool[])	��������ǿ����϶����ڵģ������е��������������Ҫ��ֹ��Ĵ��ڱ��ƶ�������Ե���lock(��Ĵ��ڱ��)����CMovable_sys[���]=1;Ҫ�����Ļ�ֻ���ٵ���һ��lock(���)��CMovable_sys[���]=0����\n 8.CFontSizeX,CFontSizeY	������������ָ����̨�������С������������λ���أ�������������-����-��С �鿴���������ޣ�û�������Զ�У׼ϵͳ�����Ҫ����Ҫ�ڳ������\n	������������Щ����������options.txt�޸ģ���ʾ��options.txt���Զ����֣��������ᣩ\n	8.CConsoleLeft,CConsoleRight,CConsoleTop,CConsoleBottom	���ĸ�������ָ���ڣ��ǿ���̨����������������̵Ĵ��ڣ����󡢿����ϡ��ߣ�ע��˳�򣩣�������������+1�����ĸ�-1����\n	9.Trans			(transparent ͸��)�����Trans=0����ô�㽫�޷������ǽ��㣨�����ں���ģ����ڡ����������ĵ������ؿ��٣����Խ����޸�Ϊ0��\n	10.wOldColorAttrs	(Window Old Color Attributes ����Ĭ����ɫ����)���鲻Ҫ�ģ�Ĭ��7���������뿴��һ����ɫ����ɫ����ɫΪ�����Ĵ��ڣ�\n	11.EoutDelay		��˵ע�������и�ģʽ��������Ļ��������������ǿ�������������ģ�Խ��Խ��������λms\n	12.IDDTFP		(��������д�����ұ�� ֹͣע��ƫ��)��������Ļ�������ʱ������㲻�뿴����ô�죿�ǲ���Ų����ꣿ�Եģ���ֻ��ҪŲ��IDDTFP���ؾͿ���ֹͣ�ˣ�������֪�����Ǹ�����˰ɣ�\n	13.WindowVerson		Win10�û�ע���ˣ�\n			��˵��Win10��ʼ��΢���ʳ������ģ�Ϊ�й��ͻ���Win10������������˸����һ��������Ϊ�˷�ֹ���������г����룩��\n			������Ͱ��ҵĳ����ɵ�ˣ�������Ļȫ��û��������û�ҵ���ȫ֮�ߡ�����ֻ���ټ�һ���������������Win10�û�������ĳ�1\n	�︽.\n	ǰ��������и�����������ѡ������������Ϊ��������Ҵ�V2���Ҿ��Ѿ�����ˣ�������û�Ĺ���������������ܡ�������Ȼ�е��ô���Ҳ����һ�¡�\n	void cost(int left,int top,int right,int down,int &px,int &py)//area selecting����ѡ��* \n	\n	�÷�����Ļ���ڣ�����Ҫ���������һ�£��ͻ���ʾʮ��׼�ǣ����ų���᷵����ѡ������ꡣ������������ѡ��\n	���ͣ�	left,top;right,down:ѡ������������������������ô���Ͳ�����ʾʮ��׼�ǣ�\n	px��py�����������������ڴ��صģ�����Ҫ�д���ֵ������ᱻ����\n	--��LZ��д \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n�ڣ�\n	Ҫʹ��һ�������Ƴ���ܼ򵥣���������Ҫ�õ����̣�������Ǳ�д��Ҳ�����㿴һ�£� \n	���ȣ���Ҫ���ݳ�����ʾ���ȵ��㿴������������һ��'+'ʱ���������������ˣ������д���Զ����˹�����������ۣ� \n	�����Ҫѡ��һ��ѡ���ֻ��Ҫ����Ǹ����ּ��ɡ�\n	�������֪��ĳ��ѡ��İ�����1.�����������ͣ��һ�ῴ�Ƿ�ᵯ��һ�����ڣ�ע�ͣ���\n	2.���������ͣ������ʱ�᲻�����Աߣ�������һ�����ڣ���ʾһ��ʲô \n	����������ò�������ʵȡ���ڱ�д�����ˣ������ճ������ʾ��\n	 --��LZ��д \n	 \n\n\n";
#else
const string Note_simple="**�����**\n����:[2019.8.18]\n˵���ˣ�������ô�þ���ô��\n\n���������һ���������ݵĳ��򣨽��˶��ѣ���\nʹ��ʱ�����׼�Ķ�׼���ֵ������ѡ��\n�������������ס�����֣������϶��߿����ƿ��������ִ��ڿ��ܲ�������\n\n\n����ֻ����ô�࣬����Ĳ��ÿ���\n\nV2.7-simple��������2020.12.06\n\n\n��ǰ�汾	V2.7-simple\n���ʱ��	2020.12.06\n\n\n#define �����ڴ�! ¥��lz��͵����!\n\n";
#endif

// - private
char CTitle[1005];//���򴰿ڱ���
		const char ChineseSymbol=''/*(char)1:USE IT if you need to recognize the next two char as a chinese*/,EndlSympol='}';
	string MessageboxLeftBoard[]={"|","*","#","+",""," ","  ","��","��","��","��","��","��","�w","��","��","��","��","��","��","��","��","?","?","?"}
		  ,MessageboxTopBoard[]={"-","*","#","+",""," ","  ","��","��","��","��","��","��","�w","��","��","��","�{","��","��","��","��","?","?","?"};
	string WindowLeftBoard[]={"|","*","#","+"," ","!","?","'",".","+"}
		  ,WindowTopBoard[]={"-","*","#","+"," ","!","?","'",".","="};
		  const int CAuthority[15]={67,79,68,69,68,32,66,89,58,76,105,110,90,101,46};


class ClickImplementation: public Click{
public:
	
	struct CWCN{int dl,wd,ls;}TempCWCN;/*�̴߳������� NEEDED*/ 
	int Options[525][135],Optionstot,Optionstringtot;//���ð��
	string Optionstring[105];/*options.txt<-VerVerify NEEDED*/ 
	string CWindowOrder="";//����˳��
	pthread_t CRecentTids;
	int CEnabled,CPause,Trans=1,CButton=2,CLatestNum,CClickable=1,FV=2,CTopCurrentWindow;//�߳��Ƿ�����,��ͣ������Ƴ����ڣ��ǽ��㴰�ڿɼ���  ��ť��Ч����  ��ǰ�����̱߳�� �Ƿ�����ѡ�� ��ǰ�����Ƿ��ö� 
	int CMessageXLine,CMessageXHeight;/*msgbox() NEEDED*/
	int CurrentFontSizeX,CurrentFontSizeY,CurrentFontIndex;//(current-)��ǰ�����С 
	char* COptionsFileName=const_cast<char*>("options.txt");
	


	//basic plugins������� 
	
	#ifndef CLICK_SIMPLE
	inline int INTSc(int linenum, int number)//�ļ��� 
	{
	#ifdef OLD_VERSION
		if (_VerVerify)//��ΪIntSc����Ϊ�˶�ȡ���ã���ΪVerVerify�Ѿ���ȡ���ˣ�����ֱ�ӵ��� 
		return Options[linenum][number];//From the Options[][];
	#endif
		ifstream in(COptionsFileName);
		int ans;string data;
		for (int i=1;i<linenum&&in.peek()!=EOF;i++)getline(in,data);
		for (int i=1;i<=number&&in.peek()!=EOF;i++)in>>ans;
		in.close();
		return ans;
	}
	inline bool LinePr(char* COptionsFileName, int linenum,string ot)//�ļ�д(��COptionsFileName�ļ���linenum��Ϊot)
	{
		if (COptionsFileName=="*A")
		{
			ofstream out (ClickImplementation::COptionsFileName,ios::out);
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
#endif
	
#ifndef CLICK_SIMPLE
	void CAreaSelect(int left,int top,int right,int down,int &px,int &py)//area selecting����ѡ��* 
	//����clicking�������ڰ汾��ԭ������ѡ��һ����Χ����Ϊ���ڵĴ�С��ֻ����ʱ����Ҫ�� 
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
		lr();cout<<"select area:"<<px<<"*"<<py<<endl;//px,py��ѡ��ķ�Χ 
		Sleep(1000);
		ChangeWindowPosition(CWindowRect.left,CWindowRect.top,CWindowRect.right-CWindowRect.left,CWindowRect.bottom-CWindowRect.top);//��ԭԭ���ڴ�С 
		return;
	}
#endif
	void CWriteWindow(int wd,int x,int y,string s,int ct,string cm,int cml,int cmt,int cmdl,int cmmd,int cmbds,int cl)//menu writing system�˵�д��ϵͳ*
	//explain:window:wd(it will be auto existed),boardstyle:wdbds(See WindowLeftBoard WindowTopBoard),start from (x,y), text:s, return value:ct, comment:cm, comment start from (cml,cmt) [-1 means auto]
	{
		int cmp=0,cxl,cxt;//cxl,cxt��ע����ʼλ�� cmp����Ƿ������� 
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='}')
			{
				x++;
				s=s.substr(i+1,s.size()-i);
				i=0;
			}
			if(s[i]==ChineseSymbol){cmp=1;s.erase(i,1);}//ChineseSymbol��Ǻ���������ַ���ȫ���ַ� 
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
			if(ChineseCheck(s[i],s[i+1])||cmp)//chck �ж��������ַ��Ƿ�������� 
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
	
	void CShowWindow(int wd)//��ʾ����k ,������CEnabled=0ʱ���� 
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
	void CHideWindow(int wd)//���ش���k ,������CEnabled=0ʱ����
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
	void CCreateWindow(int wd,int wdbds,string wdtp,int cwl,int cwt,int cwr,int cwb)//window writing system���ڴ���ϵͳ
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
		//���������ӣ���������û��д 
	//	cw(wd,cwt,cwr-6,"[ ][ ]",0,"",0,0,0,0,0,wOldColorAttrs);
	//	cw(wd,cwt,cwr-5,"-",-3,"",0,0,0,0,0,wOldColorAttrs|0x8|0x10|0x80);
	//	cw(wd,cwt,cwr-2,"X",-4,"",0,0,0,0,0,wOldColorAttrs|0x8|0x10|0x80);
		return;
	}
	void CDeleteWindow(int k)//ɾ������k 
	{
		CHideWindow(k);
		for(int i=0;i<WDLMT;i++)//ɾ���������� 
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
	void msgbox(int wd,int sx,int sy,int cl,string msg,int md,int bdstyle)//MessageBox��Ϣ�� 
	//explain:SHOWpos(sx,sy),MSG:msg,showing mod,BoardStyle[See MessageboxLeftBoard MessageboxTopBoard]
	{
		int cnt=0,xl=0,tpo=2,CMessageXHeight=0,CMessageXLine=0;//cnt:��ǰ��������cnt���ַ��� 
		string tmp="";
		string l=MessageboxLeftBoard[bdstyle],t=MessageboxTopBoard[bdstyle];//�߿��ַ� 
		int maxc=(CConsoleRight-CConsoleLeft)/CFontSizeX-2-sx,chc=1,cmp=0;//maxc���ÿ����Ŀ��ȣ������ڣ� 
		if(maxc<0)return;
		WORD TMPCL=cl;
		TMPCL&=~FOREGROUND_INTENSITY;//Ϊ�˲���ǿ��Ч�����Ȱѱ����е�INTENSITYȥ�� 
		SetConsoleTextAttribute(COutputHandle,TMPCL|FOREGROUND_INTENSITY);
		msg+=" ";//Ϊ���ڸ�������Ļ��һ���bug 
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
		
		for(;cnt<msg.size();CMessageXHeight++)//Ԥ��CMessageXLine:ͳ�Ʊ��ַ������һ���ж��ٸ��ַ� CMessageXHeight:���ж����� 
		{
			while(msg[cnt]!=EndlSympol&&cnt<msg.size())//char EndlSympol='}';���б�־
			{
				cnt++;xl++;//xl:ͳ�Ƶ�ǰ���ж��ٸ��ַ� 
			}
			CMessageXLine=max(CMessageXLine,xl);
			xl=0;cnt++;
		}
		
		//���µ�+..���ݶ��Ǿ�����β��Եõ���������ϸ���� 
		if(l.size()>1)tpo+=3;//����߿���ȫ���ַ�����ô��Ϣ����������ƫ��+3������ԭ����+2����+5 
		CMessageXLine+=tpo; //��λ�Ƽӵ���Ϣ����������
		if(CMessageXLine%2==0)CMessageXLine+=1;//Ϊ�˷�ֹl��ȫ���ַ�ʱ�߽�ͻ��������ַ���CMessageXLineҪ������ 
		ClickImplementation::CMessageXHeight=CMessageXHeight+5;ClickImplementation::CMessageXLine=CMessageXLine+5;//���ݵ�ȫ�ֱ�����������������Ϣ��
		cnt=xl=0;
		
		for(int i=1;i<=CMessageXHeight;i++)
		{
			gotoxy(sy+i,sx);//�����еĵ�һ���ַ� 
			cout<<l;//�������߿� 
			if(md!=2)//�������Ϣ������ mode2:������Ļ����Ϣ����������������
			{
				while(cnt<msg.size()&&msg[cnt]!=EndlSympol)//������� 
				{
					tmp+=msg[cnt];
					cnt++;xl++;
				}
				cout<<tmp;
				tmp="";
			}
			for(int j=1;j<=CMessageXLine-xl-max(tpo-4,0);j++)tmp+=" ";//��ȫ�ո�
			cout<<tmp<<l;//������ұ߿� 
			tmp="";
			xl=0;cnt++;
		}
		
		if(md==1)//��ӰЧ�� 
		{
			SetConsoleTextAttribute(COutputHandle,TMPCL);
			for(int i=1;i<=CMessageXHeight+max(tpo-3,1);i++)//�����Ӱ 
			{
				gotoxy(sy+i,CMessageXLine+sx+max(tpo-4,0)+2);
				cout<<l;
			}
			SetConsoleTextAttribute(COutputHandle,TMPCL|FOREGROUND_INTENSITY);
		}
		if(t.size()>1)CMessageXLine=CMessageXLine/2;//��������ײ��߿� ,��� t��ȫ���ַ�����ôҪ��һ�� 
		for(int i=1;i<=CMessageXLine+2&&i+sx+1<CConsoleRight-30;i++)tmp+=t;
		gotoxy(sy,sx);cout<<tmp;
		gotoxy(sy+CMessageXHeight+1,sx);cout<<tmp;//tmp��mode1���ܻ�Ҫ�ã��Ȳ���� 
		if(md==1)//����ײ���Ӱ 
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
	void COpenThread(int delay/*LEAST 50!*/,int window,int to_be_continued)//menu choosing system starter�˵�ѡ��ϵͳ��������_�߳�* 
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
	void COpenWindow(int delay/*LEAST 50!*/,int window,int to_be_continued)//menu choosing system starter�˵�ѡ��ϵͳ��������_�ȴ�* 
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
	CCreateWindow(3,2,"��ʾ",35,0,55,20);
	//system("mode con cols=80 lines=25");//Warn 
	 CWriteWindow(1,1,1,"-------------�˵�-------------",0,"���Ҹ���awa}��ֻ��һ������...",-1,-1,1000,1,3,0x2|0x8);
	 CWriteWindow(1,3,15,"��ʼplay",1,"�������ʼ��Ϸ}�ȵȣ�¥����û����Ϸ��qwq",-1,-1,0,1,0,0x4|0x1|0x8|0x80|0x20);
	 CWriteWindow(1,6,15,"�˳�exit",2,"�����˳�",-1,-1,0,0,0,wOldColorAttrs);
	 CWriteWindow(1,10,5,"����һ���µĴ���awa",3,"������}...}!",-1,-1,500,1,7,0x4);
	 CWriteWindow(1,11,5,"����\\��������",4,"",0,0,0,0,0,wOldColorAttrs);
	 CWriteWindow(1,7,1,"���ʾ��:�� �� +*�p #",15,"�ÿ���}����㲻���⣬����ͨ���������еġ������ʽ������}���ֶ�����ֻ���벻��û����������}",8,15,600,2,21,0x2|0x10|0x8|0x80);
	 CWriteWindow(3,2,36,"Ų��������~",5,"�Ҳ��ҵ���һ��",0,0,0,0,0,wOldColorAttrs|0x8);
	 CWriteWindow(3,18,36,"�ر�",6,"",0,0,0,0,0,wOldColorAttrs|0x8|0x4);
	 CWriteWindow(3,16,36,"�鿴����\\�汾��Ϣ",20,"",0,0,0,0,0,0x8);
	 CWriteWindow(3,10,36,"���",0,"�ı����̨���ɼ���",-1,-1,0,0,1,0x1|0x8);
	 CWriteWindow(3,10,41,"s",30,"",0,0,0,0,0,0x1|0x2|0x4);
	 CWriteWindow(3,10,43,"h",31,"",0,0,0,0,0,0x1|0x2|0x4);
	 CWriteWindow(3,11,36,"׼��",0,"�ı�CLICKINGϵͳ���ɼ���",-1,-1,0,0,1,0x1|0x8);
	 CWriteWindow(3,11,41,"0",32,"",0,0,0,0,0,0x1|0x2|0x4);
	 CWriteWindow(3,11,43,"1",33,"",0,0,0,0,0,0x1|0x2|0x4);
	 CWriteWindow(3,11,45,"2",34,"",0,0,0,0,0,0x1|0x2|0x4);
	 CWriteWindow(3,12,36,"͸��",0,"�ǽ��㴰�ڿɼ���",-1,-1,0,0,1,0x1|0x8);
	 CWriteWindow(3,12,41,"0",35,"",0,0,0,0,0,0x1|0x2|0x4);
	 CWriteWindow(3,12,43,"1",36,"",0,0,0,0,0,0x1|0x2|0x4);
	 CWriteWindow(3,13,36,"��ť",0,"�ı䰴ť��Ч",-1,-1,0,0,1,0x1|0x8);
	 CWriteWindow(3,13,41,"0",37,"",0,0,0,0,0,0x1|0x2|0x4);
	 CWriteWindow(3,13,43,"1",38,"",0,0,0,0,0,0x1|0x2|0x4);
	 CWriteWindow(3,13,45,"2",39,"",0,0,0,0,0,0x1|0x2|0x4);
	 
	 
	//�˴�������/*CTasks_sys[++CTasks_sys[0]]=3;*/����Ӧ����CShowWindow()��Ϊ�˲��봰��˳�� 
	 CLockWindow(3);
	 CShowWindow(3);
	 CShowWindow(1);
	 COpenThread(15,1,1);//COpenThread֮ǰ����Щ�������ǿ������ɵ��õģ�����CEnabled���� 
	 while(ans!=2&&CEnabled)
	 {
	 	while(!CChoseValue[0])
		 {
		 	Sleep(100);
		 	if(CCurrentValidValue==1)
		 	{
		 		CWriteWindow(3,5,36,"������������}����û����Ϸ}�����Լ�дѼ��",0,"",0,0,0,0,0,0x2|0x8);
		 		while((CCurrentValue==-1||CCurrentValue==1)&&!CChoseValue[0])Sleep(50);CCurrentValidValue=0;//ValidValueһ��Ҫ�ǵ���գ������п����ظ�ִ�� 
		 		CWriteWindow(3,5,36,"              }            }              ",0,"",0,0,0,0,0,wOldColorAttrs);
			 }
			if(CCurrentValidValue==6)
		 	{
		 		CWriteWindow(3,5,36,"����������˼}�ص��Ļ�}û����ʾ��Ŷ...",0,"",0,0,0,0,0,0x4|0x8);
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
			 	CWriteWindow(3,5,36,"��ϧ��}��ֻ���ڳ��������",0,"ûʲô�ÿ���",-1,-1,0,0,1,0x1|0x8|0x20|0x80);
		 		while((CCurrentValue==-1||CCurrentValue==15)&&!CChoseValue[0])Sleep(50);CCurrentValidValue=0;
		 		CWriteWindow(3,5,36,"      }                  ",0,"",0,0,0,0,0,wOldColorAttrs);
			 }
		 }
	 	ans=CChoseValue[CChoseValue[0]];CChoseValue[0]--;
	 	if(ans==3){
	 		CCreateWindow(2,1,"I AM THE ����",10,7,25,15);
	 		CWriteWindow(2,8,11,"�ص�",9,"��Ҫ��",-1,-1,0,0,0,wOldColorAttrs);
	 		CShowWindow(2);CTopCurrentWindow=2;
	 		while(!CChoseValue[0])Sleep(100);
	 		CTopCurrentWindow=0;
		 }
	 	if(ans==9)CHideWindow(2);//CDeleteWindow(2);��� 
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
		 	else if (ans<=36)Trans=ans-35,CTasks_sys[++CTasks_sys[0]]=0;//����һ��0����ȫ��ˢ�� 
		 	else if (ans<=39)CButton=ans-37;
		 }
	  //mains?[with both(a,b)]
	 }
	CCloseWindow();
	 lr();
	 
	}
	#endif
	
private:
	
	
	////Function declare
	//int INTSc(int linenum, int number);
	//bool LinePr(char* COptionsFileName, int linenum,string ot);
	//int GetSystemVersion();
	//void gotoxy(int x,int y);
	//bool Form_load();
	//bool VerVerify();
	
	
	char cc;//ȫ��getch() - private
	//API SYMBOL
	HWND CMainHwnd=GetForegroundWindow();//�����ھ�� 
	HWND CConsoleHwnd=GetConsoleWindow();//����̨��� 
	HANDLE COutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);//������ 
	CONSOLE_SCREEN_BUFFER_INFO CConsoleScreenBufferInfo;//���ڻ�������Ϣ 
	RECT CWindowRect,CTempRect;//����λ�ã�����WindowRect
	LONG CWindowOldLong=GetWindowLong(CMainHwnd, GWL_STYLE);//������ʽ���������ر��� 
	CONSOLE_CURSOR_INFO CCursorInfo;//�����Ϣ���������ع�� 
	
	//PRELOAD �������˳�� 
	
	ClickImplementation()// - private
	{
		return;
	}
	
	
	
	bool _VerVerify=VerVerify();// - private
	
	//���� 
	const int// - private
			EoutDelay=Options[3][1],IDDTFP=Options[3][2],//������Ļ��ʱ(!>5) ע����ֹƫ��  �����ۻ�������
			wOldColorAttrs=Options[2][2],//Ĭ�ϴ���������ɫ 
			CMD_MAXCHAR=512;//PipeCMD���������� 
	int		WinVer=GetSystemVersion(),//ϵͳ�汾�������޸�Win10����\b��˫���ظ� 
			CFontSizeX=Options[2][3],CFontSizeY=Options[2][4];//�����С ��*��pixel
	
	
	
	//��ϵͳ 
	short int 
	/*����*/			CValue_sys[WDD][WDLMT][WDLMT],CColor_sys[WDD][WDLMT][WDLMT],
	/*ע��ϵͳ*/		CCommentLeft_sys[WDD][WDLMT][WDLMT],CCommentTop_sys[WDD][WDLMT][WDLMT],CCommentMode_sys[WDD][WDLMT][WDLMT],CCommentDelay_sys[WDD][WDLMT][WDLMT],CCommentBoard_sys[WDD][WDLMT][WDLMT],
	/*�����̼߳�������*/CTasks_sys[WDD*3],
	/*��ǰλ���Ƿ����*/CIfRefresh_sys[WDD][WDLMT][WDLMT],
	/*�ô����Ƿ���ƶ�*/CMovable_sys[WDD],
	/*����ϵͳ����*/	CWindowLeft_sys[WDD],CWindowTop_sys[WDD],CWindowRight_sys[WDD],CWindowBottom_sys[WDD],
	/*����ֵ����*/		CChoseValue[WDLMT*WDLMT],
	/*Ԥ�����������*/	CCurrentValidValue,
	/*ɸȥ�ո�*/		CCurrentValue,
	/*��ǰ���λ��*/	CCurrentY,CCurrentX,
	/*��ǰ����*/		CCurrentWD,
	/*��ť��ɫϵͳ*/	CTempColor,ColoredValue,ColoredPositionX,ColoredPositionY,ColoredColor,
	/*�������λ��*/	CConsoleLeft=Options[1][1],CConsoleRight=Options[1][2],CConsoleTop=Options[1][3],CConsoleBottom=Options[1][4],
	/*�߿���ȱ������*/CConsoleBoard=8,CConsoleTopBoard=30;
	short int tCValue_sys[WDLMT][WDLMT],tCCommentLeft_sys[WDLMT][WDLMT],tCCommentTop_sys[WDLMT][WDLMT],tCCommentMode_sys[WDLMT][WDLMT],tCCommentDelay_sys[WDLMT][WDLMT],tCCommentBoard_sys[WDLMT][WDLMT],tCColor_sys[WDLMT][WDLMT];
					string tCChar_sys[WDLMT][WDLMT],tCComment_sys[WDLMT][WDLMT];//���ڰ��˴��ڣ���ʱ 
	
	string 
	/*�ַ���*/	CChar_sys[WDD][WDLMT][WDLMT],
	/*ע�Ϳ�*/	CComment_sys[WDD][WDLMT][WDLMT],
	/*���ڱ���*/CWindowTopic_sys[WDD];
	
	/*p rivate*/ bool _Form_load=Form_load();//ȫ��Ԥ���� 
	
	
	
	
	//basic plugins������� 
#ifndef CLICK_SIMPLE
	inline string HEXR(int k) //dec->hexʮ����תʮ������ 
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
#endif
	
	
	
	//advanced plugins�߼���� 
	inline void gotoxy(int x,int y)//cursor position setting���λ������ 
	{
		SetConsoleCursorPosition(COutputHandle,(COORD){y,x});
	}
	void lr()//fast cls��������,�������൱��system("cls")
	//����������https://blog.csdn.net/icy_ybk/article/details/79285245 ,�ر��лԭ����Icy_Ybk ,�иĶ� 
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
	#ifdef OLD_VERSION
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
		FILE* pipe = _popen(cmd, "r"); //�򿪹ܵ�ִ������
		if (!pipe)
		{
	#ifndef CLICK_RELEASE
			TextDeep();puts("E3.1:�޷�����PipeCMD");TextNormal();
	#endif
			return ;//����ʧ��
		}
		while (!feof(pipe))
		{
			if (fgets (buffer, CMD_MAXCHAR, pipe))//���ܵ������result��
			{
				strcat(result,buffer);
			}
		}
		_pclose(pipe);//�رչܵ�
		strcat(result,const_cast<char*>("\0"));
		return ;
	}
	struct CONSOLE_FONT//FontSizer needed
	{
		DWORD index; 
		COORD dim;
	};
	int FindFont(int CFontSizeX,int CFontSizeY)//FontSizer needed
	{
		for(int i=1;i<=Options[6][0];i+=2)
		if (Options[6][i]==CFontSizeX&&Options[6][i+1]==CFontSizeY)
		return i;
		TextDeepRed();
	#ifndef CLICK_RELEASE
		printf("[FindFont]Warning:%dx%d FontID NO FOUND\n",CFontSizeX,CFontSizeY);//�����Ҳ�������ı�� 
	#endif
		TextNormal();
		return -1;
	}
	void FontSizer()	//adjust font size���������С
	{ 
		HMODULE hKernel32 = GetModuleHandle("kernel32");
		typedef BOOL (WINAPI *PROCSETCONSOLEFONT)(HANDLE, DWORD);
		PROCSETCONSOLEFONT SetConsoleFont = (PROCSETCONSOLEFONT)GetProcAddress(hKernel32,"SetConsoleFont");
		//��Ϊ�����Ƿ���Ҫ����������Ϣ������Ҫ�������壬��˷ŵ�if�� 
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
		else if (tmp.find("0000") != string::npos)//Win10��������崢�淽ʽ 
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
			TextDeep();puts("E2:�޷���ȡ��ʶ���ע���������Ϣ");TextNormal();
	#endif
			if (MessageBox(CConsoleHwnd,"E2:�޷���ȡ��Ч��ע���������Ϣ\n��ȷ�����Ƿ�����˷���Ȩ��","Process Erruption",MB_RETRYCANCEL)==IDRETRY)goto Rst;
		}
		CurrentFontIndex=Options[8][FindFont(CurrentFontSizeX,CurrentFontSizeY)];
	#ifndef CLICK_RELEASE
		printf("Current Font Size:%d x %d\n",CurrentFontSizeX,CurrentFontSizeY);
	#endif
		
		//��ȡϵͳ�������С 
	#ifndef CLICK_SIMPLE
	#ifndef CLICK_RELEASE
		if (Options[8][0]==0)
		{
			TextDeep();puts("��⵽������Ϣδ����");TextNormal();
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
			printf("��ϵͳ��%d�������С\n",nNumFont);
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
						printf ("ID%d:ȷ��Ϊ%d x %d����\n",i,Options[6][j],Options[6][j+1]);
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
			puts ("---Restoring Local Font Info���");
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
		//�����Ǿɰ汾(�����ǵ���׹����Ҫ��ʱ���) 
		//��options�������CFontSizeX��CFontSizeY���Ըı䣬����Ҫ���������������ر���Ҫ�����˰�... 
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
			puts("\n�������޸�ע���������Ϊ��ʹ�����ʺϱ���������\n��Ҫ���ģ������options.txt�е�CFontSizeX��CFontSizeY");
			tmps="reg ADD HKCU\\Console /v FontSize /t REG_DWORD /f /d "+StCh(CFontSizeY*65536+CFontSizeX);
			system(tmps.c_str());
			tmps="if not exist \".\\"+Optionstring[1]+"\" echo �뽫������exe���ָĻأ�"+Optionstring[1]+"�������޷�����";
			system(tmps.c_str());//���� 
			tmps="start \""+Optionstring[1]+"\" \""+Optionstring[1]+"\"";
			system(tmps.c_str());//���� 
			exit(0);
		}
		system("reg ADD HKCU\\Console /v FontSize /t REG_DWORD /f /d 0x00100008");
		return;
	#endif
	}
	#ifndef CLICK_RELEASE
	#ifndef CLICK_SIMPLE
	const int senior[junior+1]={1,4,4,3,2,1};
	char menu[][15][55]={
		{"Set System"}
		,{"1.WindowPosition","(Current)","��ק���ڵ�����Ҫ��λ��Ȼ��Enter�����","����","�ָ�Ĭ��"}
		,{"2.FontSize","(Current)","�����ֺ�","��С�ֺ�","�ָ�Ĭ��"}
		,{"3.WindowVersion","(Current)","��Windows�汾��Win7������","��Windows�汾��Win7����"}
		,{"4.ProcessName","(Current)","����"}
		,{"5.���沢�˳�","��Enter����Backspace���沢�˳�"}
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
			TextNormal();lr();
			//digital refresh
			tmps="Ŀǰ����"+StCh(Options[1][1])+" "+StCh(Options[1][2])+" "+StCh(Options[1][3])+" "+StCh(Options[1][4]);
			strncpy(menu[1][1], tmps.c_str(), tmps.length() + 1);
			tmps="Ŀǰ���� ID"+StCh(CurrentFontIndex);
			strncpy(menu[2][1], tmps.c_str(), tmps.length() + 1);
			tmps="Ŀǰ����:";
			if(Options[4][1]==1)tmps=tmps+"Win7����";
			else tmps=tmps+"Win7������";
			strncpy(menu[3][1], tmps.c_str(), tmps.length() + 1);
			tmps="Ŀǰ����:"+Optionstring[1];
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
			TextDeepCyan();puts("���������л�\tEnterѡ��\tBackspace���沢����\tEsc�����淵��");TextNormal();
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
					HightLight();puts("�����뱾���������(*.exe)������˫����");TextNormal();
					getline(cin,tmps);
	//				���ź���c++û����¼libcomdlg32.a���ļ��������޷�ʵ���� 
	//				��Ȼ�����ֶ����ӣ�����Ϊ�˲��������ı༭�����鷳�������� 
	//				TCHAR szBuffer[MAX_PATH] = {0};   
	//				OPENFILENAME ofn= {0};   
	//				ofn.lStructSize = sizeof(ofn);   
	//				ofn.CMainHwndOwner = CConsoleHwnd;   
	//				ofn.lpstrFilter = _T("�������EXE�ļ�(*.exe)\0*.exe\0");//Ҫѡ����ļ���׺   
	//				ofn.lpstrInitCConsoleLeftDir = _T("%userprofile%\\desktop");//Ĭ�ϵ��ļ�·��   
	//				ofn.lpstrFile = szBuffer;//����ļ��Ļ�����   
	//				ofn.nMaxFile = sizeof(szBuffer)/sizeof(*szBuffer);   
	//				ofn.nFilterIndex = 0;   
	//				ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER ;//��־����Ƕ�ѡҪ����OFN_ALLOWMULTISELECT  
	//				BOOL bSel = GetOpenFileName(&ofn);  
	//				printf("·��:%s\n",szBuffer);
					Optionstring[1]=tmps;
				}
			}
		}
		if (cc==8)
		{
			gotoxy(23,0);
			HightLight();puts("����������...");TextNormal();
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
		TextDeepCyan();puts("Version Verify->Set System���");TextNormal();
		return 1;
	}
	#endif
	#endif
	bool VerVerify()//���ü���ȡ 
	{
	#ifndef CLICK_SIMPLE
		int Ln=2;
		int ans;
		char anss[128],ccc;
	#ifndef CLICK_RELEASE
		puts ("Version Verify");
		HightLight();
		puts("��������д����������ע�����");
		puts ("���в������෽���ԣ���������~\n");
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
			puts("��������δ��ʼ��");
			HightLight();
			cout<<"Please RESTART LATER\n���Ժ������ó���\n";
			TextNormal();
			cout<<"\nVERSION:"<<Version<<"\nReWriting...\n";
			Rst:;	//Reset Mark 
			if(!LinePr((char*)"*A",0,""))
			{
				TextDeepRed();
				if (MessageBox(CConsoleHwnd,"E1:��ʼ������\n����ϵlzѯ��ԭ��\n��������д����������ע�����\n���в������෽���ԣ���������~","Process Erruption",MB_RETRYCANCEL)==IDRETRY)
				goto Rst;
	#ifndef CLICK_RELEASE
				cout<<"Initialize faild\a\t[Any key to continue]\n";
	#endif
				char cc=getch();
				exit(0);
			}
	#ifndef CLICK_RELEASE
			TextDeepGreen();
			cout<<"InitCConsoleLeftize succeed\t[Any key to continue]\n[���������]\t\n\n";
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
		FV=Options[2][5];//Ϊ�˸�������˳�������޸ģ�ֻ�ܰ�Ԥ������������� 
		return 1;
	}
	bool Form_load()
	{
	#ifndef CLICK_RELEASE
		puts("Process Preload");
		//API�� 
		//��Щ���Ե�codepage���ԣ�������ʾ�������ģ����ǸĹ�һ���Ժ󶼲����� 
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
		FontSizer();//���������С���ɽ��� 
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
		ChangeWindowPosition(CConsoleLeft,CConsoleTop,CConsoleRight-CConsoleLeft,CConsoleBottom-CConsoleTop);//����options�еĴ���λ�ò���-1����ô�ƶ����ڵ�ָ��λ�� 
		//�Ƴ� ���ٱ༭ ���� ģʽ
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
		GetConsoleCursorInfo(COutputHandle, &CCursorInfo);//��ȡ����̨�����Ϣ
	//	CCursorInfo.bVisible=bvisible;//��Ϊ����̨����ȷ��ʲôʱ��Ҫ��ʾ��꣬�ʲ����� 
	//	SetConsoleCursorInfo(COutputHandle, &CCursorInfo);
	#ifndef CLICK_RELEASE
		puts("--Buffer Info");
	#endif
		GetConsoleScreenBufferInfo(COutputHandle,&CConsoleScreenBufferInfo);//��ȡ������Ϣ 
	#ifndef CLICK_RELEASE
		puts("--Window Title");
	#endif
		GetWindowText(CMainHwnd,CTitle,1000);//��ȡ���ڱ��� 
	#ifndef CLICK_RELEASE
		puts("API�����");
	#endif
		//CLICKING�� 
		for(int w=0;w<WDD;w++)//Ԥ�������� 
		for(int i=0;i<WDLMT;i++)
		for(int j=0;j<WDLMT;j++)
		{
			CColor_sys[w][i][j]=wOldColorAttrs;
			CChar_sys[w][i][j]=" ";
		}
	#ifndef CLICK_RELEASE
		puts("C�����\n");
		lr();
	#endif
		return 1;
	}
	
	//INITIALIZE COMPLETED----------------------------------------------------------------
	
	void eout(string s,int sx,int sy)//Thank YYC for this code--lighting subtitles!������Ļ 
	//����������yyc������ż�á���ԭ����¼��OIBox����ϧ����OIBox����c++���ˡ��иĶ� 
	{
		int i=0,m=0,p=EoutDelay;//���� (ms)
		POINT pt;//������ڼ������Ƿ��Ѿ��뿪��һ����Χ����ʱ�жϣ�
		bool TKmoved;//������ڼ������Ƿ�����ҲҪ��ʱ�жϣ� 
		char sds;
		sx++;//sx��sy������������Ϊ�����msgbox��ָ��λ����� ,����sx��1��λƫ�� 
		gotoxy(sy,sx);
		TKmoved=KEY_DOWN(MOUSE_MOVED);
		GetCursorPos(&pt);
		int nwpx=pt.x,nwpy=pt.y;
		while(i<s.size() 
		&& !( max(abs(pt.x-nwpx),abs(pt.y-nwpy))>IDDTFP || KEY_DOWN (MOUSE_MOVED)!=TKmoved))
		{
			if (s[i]==EndlSympol)
			{
				if (s[i-1]>0)
				cout<<' ';
				sy++;
				gotoxy(sy,sx);
			}
			if (s[i]!=EndlSympol)
			{
				cout<<'|';
				if (!kbhit())Sleep(p);
				cout<<"\b��";
				if (!kbhit())Sleep(p);
				if (WinVer)cout<<"\b ��";//Win10�ײ�\b һ������������Ҫ��һ��\b 
				else cout<<"\b\b ��";
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
	
	void CAreaRefresh(int sx,int sy,int ex,int ey)
	//explain:from(sx,sy)to(ex,ey)��sx,sy��ex,ey֮��Ŀռ仹ԭ��Ϊԭ���Ĵ������ݣ� 
	{
		int bs,ctextcolour=wOldColorAttrs,CTempWD=CCurrentWD,BeSwitched=0;
		string tmp="";
		//����CTempWD
		if (!Trans)bs=CWindowOrder[0]-'0';//��������"�����㴰�ڿɼ�"
		else
		for (int ii=0;ii<CWindowOrder.size();ii++)//������ҵ�ǰλ�������ĸ����� 
		if (sy>=CWindowLeft_sys[CWindowOrder[ii]-'0'] && sy<=CWindowRight_sys[CWindowOrder[ii]-'0'] && sx>=CWindowTop_sys[CWindowOrder[ii]-'0'] && sx<=CWindowBottom_sys[CWindowOrder[ii]-'0'])//�жϵ�ǰλ�����ڴ���
		{
			bs=CWindowOrder[ii]-'0';
			break;
		}
		for (int i=sx;i<=ex;i++)
		{
			for (int j=sy;j<=ey;j++)
			{
				ctextcolour=CColor_sys[bs][i][j];
				gotoxy(i,j);
				while (j<=ey)
				{
					//����CTempWD
					if (!Trans)CTempWD=CWindowOrder[0]-'0';//��������"�����㴰�ڿɼ�"
					else
					for (int ii=0;ii<CWindowOrder.size();ii++)//������ҵ�ǰλ�������ĸ����� 
					if (j>=CWindowLeft_sys[CWindowOrder[ii]-'0'] && j<=CWindowRight_sys[CWindowOrder[ii]-'0'] && i>=CWindowTop_sys[CWindowOrder[ii]-'0'] && i<=CWindowBottom_sys[CWindowOrder[ii]-'0'])//�жϵ�ǰλ�����ڴ���
					{
						CTempWD=CWindowOrder[ii]-'0';
						if (bs != CTempWD)
						{
							bs=CTempWD;
							j--;
							BeSwitched=1;//�����˴����л� 
						}
						break;
					}
					if (BeSwitched)
					{BeSwitched=0;break;}//���ܴ����л���Ϣ 
					CIfRefresh_sys[bs][i][j]=0;
					if (CValue_sys[bs][i][j]==-1)
					{
						if (j==sy)
						{
							ctextcolour=CColor_sys[bs][i][j-1];
							tmp=CChar_sys[bs][i][j-1];//������жϵ����� 
							gotoxy(i,j-1);//����һ�����ڲ������� 
						}
						j++;//(�����Ƿ�ض�)�����Ѿ�����ˣ����� 
					}
					if (CColor_sys[bs][i][j]==ctextcolour)
					{
						tmp=tmp+CChar_sys[bs][i][j];
					}
					else
					{
						j--;//��ɫ��ͬ����һ���ٴ������ѹ�����1
						break;//�˳�ѭ���ٴ������������� 
					}
					j++;
				}
				//��Ϊ�Ǿ��󣬱�Ȼ������� 
				SetConsoleTextAttribute (COutputHandle,ctextcolour);
				cout<<tmp;
				tmp="";
	#ifdef OLD_VERSION
	//�ɰ汾����ȫ�����벻�����ǣ�scanf��cin�죬��printfȴ��������һ��������puts��4������,��cout��ʮ������! 
				if (CValue_sys[bs][i][j]!=-1)
				{
					SetConsoleTextAttribute (COutputHandle,CColor_sys[bs][i][j]);
					printf ("%s",CChar_sys[bs][i][j].c_str());
					if (CChar_sys[bs][i][j].size()==2)j++;
				}
				else
				{
					SetConsoleTextAttribute (COutputHandle,CColor_sys[bs][i][j-1]);
					printf ("\b%s",CChar_sys[bs][i][j-1].c_str());
				}
	#endif
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
	void CSpeedRefresh(int Count,...)//����ˢ�£�ֻˢ�±����µĴ���λ�� ��ԭ����spclr�滻Ϊ������ 
	{
		int bs,ctextcolour=-1,*tmpnum=&Count,BeCovered=0,CTempWD=0,tasktmp;
		string tmp="";
		if (!Count)//��Count=0��ˢ��ȫ�֣�����ˢ��ָ���Ĵ��� 
		{
			//ִ��part (ִ��Show\Hide��ǵ�����)
			for(;CTasks_sys[0]>=1;CTasks_sys[0]--)
			{
				tasktmp=CTasks_sys[CTasks_sys[0]];
				if(tasktmp>0)//��ʾĳ������ 
				{
					CSpeedRefresh(1,tasktmp);
				}
				else if (tasktmp<0)
				{
					tasktmp=-tasktmp;
					CAreaRefresh(CWindowTop_sys[tasktmp],CWindowLeft_sys[tasktmp],CWindowBottom_sys[tasktmp],CWindowRight_sys[tasktmp]);//ˢ�´����ڵ�ȫ���ַ� 
					if (tasktmp==CCurrentWD)//��ֹ����ȥע�Ͳ��� 
					CAreaRefresh(CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY],CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY],CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXHeight,CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXLine);//���ע��
				}
				else//tasktmp==0
				{
					SetConsoleTextAttribute(COutputHandle,wOldColorAttrs);
					lr();//Ϊ���������Ҫ����ɫ 
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
						ctextcolour=CColor_sys[bs][i][j];
						gotoxy(i,j);
						while (j<=CWindowRight_sys[bs]&&CIfRefresh_sys[bs][i][j])
						{
							if (!Trans)CTempWD=CWindowOrder[0]-'0';//��������"�����㴰�ڿɼ�"
							else
							for (int ii=0;ii<CWindowOrder.size();ii++)//������ҵ�ǰλ�������ĸ����� 
							if (j>=CWindowLeft_sys[CWindowOrder[ii]-'0'] && j<=CWindowRight_sys[CWindowOrder[ii]-'0'] && i>=CWindowTop_sys[CWindowOrder[ii]-'0'] && i<=CWindowBottom_sys[CWindowOrder[ii]-'0'])//�жϵ�ǰλ�����ڴ���
							{
								CTempWD=CWindowOrder[ii]-'0';
								if (bs!=CTempWD)//ˢ�µ�λ�ñ��ڸ� 
								{
									j=CWindowRight_sys[CWindowOrder[ii]-'0']+1;
									BeCovered=1;
								}
								break;
							}
							if (CMessageXHeight&&CMessageXLine//������comment 
							&&i>=CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY]
							&&i<=CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXHeight
							
							&&j>=CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY]
							&&j<=CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXLine//����ˢ����msgbox��Χ�ͻ���ɸ�ЦЧ��
							)
							{
								j=CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXLine+1;//ֱ������msgbox 
								continue;
							}
							if (BeCovered)
							{BeCovered=0;continue;}//���ܱ����ǵ���Ϣ 
							
							CIfRefresh_sys[bs][i][j]=0;
							if (CValue_sys[bs][i][j]==-1)
							{
								if (CChar_sys[bs][i][j-1].size()<=1)//�����ĺ��鱻�п� 
								tmp=" ";
								j++;
							}
							if (CColor_sys[bs][i][j]==ctextcolour)
							{
								tmp=tmp+CChar_sys[bs][i][j];
							}
							else
							{
								j--;//��ɫ��ͬ����һ���ٴ������ѹ�����1
								break;//�˳�ѭ���ٴ������������� 
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
			for (int i=0;i<=(CConsoleBottom-CConsoleTop-CConsoleTopBoard-CConsoleBoard)/CFontSizeY;i++)//ˢ��Ұ����Ĺ�ꡢע��֮�� 
			{
				for (int j=0;j<=(CConsoleRight-CConsoleLeft-(CConsoleBoard<<1))/CFontSizeX;j++)
				if (CIfRefresh_sys[0][i][j])
				{
					ctextcolour=CColor_sys[0][i][j];
					gotoxy(i,j);
					while (j<=(CConsoleRight-CConsoleLeft-(CConsoleBoard<<1))/CFontSizeX&&CIfRefresh_sys[0][i][j])
					{
						if (CMessageXHeight&&CMessageXLine//������comment 
						&&i>=CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY]
						&&i<=CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXHeight
						
						&&j>=CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY]
						&&j<=CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXLine//����ˢ����msgbox��Χ�ͻ���ɸ�ЦЧ��
						)
						{
							j=CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXLine+1;//ֱ������msgbox 
							continue;
						}
						
						CIfRefresh_sys[0][i][j]=0;
						if (CValue_sys[0][i][j]==-1)
						{
							if (CChar_sys[0][i][j-1].size()<=1)//�����ĺ��鱻�п� 
							tmp=" ";
							j++;
						}
						if (CColor_sys[0][i][j]==ctextcolour)
						{
							tmp=tmp+CChar_sys[0][i][j];
						}
						else
						{
							j--;//��ɫ��ͬ����һ���ٴ������ѹ�����1
							break;//�˳�ѭ���ٴ������������� 
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
		for (int wd=1;wd<=Count;wd++)//�ô��滻spclr()���� ��ˢ��bs�ڵ�����(�����ո�)�ַ�
		{
			*tmpnum++;*tmpnum++;//��Ҳ��֪��ΪʲôҪ�����Σ����������������� 
			bs=*tmpnum;
			for (int i=CWindowTop_sys[bs];i<=CWindowBottom_sys[bs];i++)
			for (int j=CWindowLeft_sys[bs];j<=CWindowRight_sys[bs];j++)
			{
				gotoxy(i,j);
				ctextcolour=CColor_sys[bs][i][j];
				while (j<=CWindowRight_sys[bs])
				{
					CIfRefresh_sys[bs][i][j]=0;
					if (CValue_sys[bs][i][j]==-1)
					{
						if (CChar_sys[bs][i][j-1].size()<=1)//�����ĺ��鱻�п� 
						tmp=" ";
						j++;
					}
					if (CColor_sys[bs][i][j]==ctextcolour)
					{
						tmp=tmp+CChar_sys[bs][i][j];
					}
					else
					{
						j--;//��ɫ��ͬ����һ���ٴ������ѹ�����1
						break;//�˳�ѭ���ٴ������������� 
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
	void* CRunWindow(void* cwcn)//menu choosing system�˵�ѡ��ϵͳ* 
	//cwcn�������̵߳Ĵ��� 
	{
		CWCN* TempCWCN=(CWCN*)cwcn;
		int dl=TempCWCN->dl,ls=TempCWCN->ls,ThreadNum=CLatestNum;//CCurrentWD���㴰�ڣ�dlˢ��Ƶ�ʣ�ls�Ƿ��������  
		//ThreadNum���̱�ʶ������CLatestNum�������˳��̣߳�ͬʱ��CEnabledΪ0 
		CCurrentWD=TempCWCN->wd;
		//Ϊ���������Ч�ʣ�������dl��25��100֮�� 
		//���ͣ�FV=0����ȫ����ꣻ=1����δ�����ꣻ=2ȫ����ʾ
		//CButton=0��ʹ�ð�ť��Ч��=1 �������ַ�������=2������ť���� 
		if(Trans==0)
		{
			lr();
			CSpeedRefresh(1,CCurrentWD);
		}
		else CAllRefresh();
	
	 	POINT pt;
		int t=0,cpst=0,cmdl=0,tCCurrentY,tCCurrentX,bs=CCurrentWD;
		bool TKmoved=0;//�Ƿ�ı������� 
		CCurrentY=CCurrentX=1;
	
		while(CLatestNum==ThreadNum)
		{
			//����part 
			do
			{
				Sleep(dl);
				GetCursorPos(&pt);
				AutoAlign();
				CSpeedRefresh(0);
				if (pt.y<CConsoleTop||pt.y>CConsoleBottom-(CFontSizeY<<2)||pt.x<CConsoleLeft||pt.x>CConsoleRight-(CFontSizeX<<2))
				CPause=1;
				else CPause=0;//��ͣ` 
			}
			while(CPause);
			
			pt.x-=CConsoleLeft;
			pt.y-=CConsoleTop;
	//		gotoxy(23,0);
	//		cout<<pt.x/CFontSizeX<<" "<<pt.y/CFontSizeY<<endl<<CCurrentY<<" "<<CCurrentX<<"   ";
			cmdl=CMessageXHeight=CMessageXLine=0;
			while((pt.x)/CFontSizeX==CCurrentY
			&&(pt.y)/CFontSizeY==CCurrentX
			&&!KEY_DOWN(MOUSE_MOVED))//��갴��ʱ����������ע�� 
			{
				if((CTopCurrentWindow==0 || CTopCurrentWindow==CCurrentWD) && CComment_sys[CCurrentWD][CCurrentX][CCurrentY]!=""//����ע�� 
				&&cmdl==CCommentDelay_sys[CCurrentWD][CCurrentX][CCurrentY]/dl)//����ע��ʱ�� 
				{
					Sleep(CCommentDelay_sys[CCurrentWD][CCurrentX][CCurrentY]%dl);//�ȹ�cmdl�е�ms�� 
					cpst=CCommentDelay_sys[CCurrentWD][CCurrentX][CCurrentY]%dl;//���油�� 
					SetConsoleTextAttribute(COutputHandle,CColor_sys[CCurrentWD][CCurrentX][CCurrentY]);
					msgbox(CCurrentWD,CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY],CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY],ColoredColor,CComment_sys[CCurrentWD][CCurrentX][CCurrentY],CCommentMode_sys[CCurrentWD][CCurrentX][CCurrentY],CCommentBoard_sys[CCurrentWD][CCurrentX][CCurrentY]);
				}
				GetCursorPos(&pt);
				pt.x-=CConsoleLeft;
				pt.y-=CConsoleTop;
				Sleep(dl-cpst);cpst=0;//cpst��Ϊע�͵��µ���ʱ 
				CSpeedRefresh(0);
				cmdl++;
			}
			if(cmdl*dl>=CCommentDelay_sys[CCurrentWD][CCurrentX][CCurrentY]//ȷ�ϴ�����comment 
			&&CComment_sys[CCurrentWD][CCurrentX][CCurrentY]!="")
			CAreaRefresh(CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY],CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY],CCommentLeft_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXHeight,CCommentTop_sys[CCurrentWD][CCurrentX][CCurrentY]+CMessageXLine);//���ע��
			cmdl=CMessageXHeight=CMessageXLine=0;
			
			//���part
			if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1)//ʵ��û�취��������Ĳ��ø� 
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
				{//͵��һ��С��������Button=1��ʱ��������Ⱦɫ��Ϊ�˻�ԭColor2��������ôд�Ű� 
					while(ColoredPositionY>0
					&&(CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==ColoredValue||
					CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==-1)//��֤������ 
					&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==CTempColor)//��֤��ɫ������ 
						ColoredPositionY--;//�����ҵ������ 
					while((CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==ColoredValue||
					CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==-1)
					&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==CTempColor)
					{
						CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=ColoredColor;//��ԭ 
						CIfRefresh_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=1;
						ColoredPositionY++;//����Ⱦɫ
					}
					ColoredColor=0;//��ColoredColor�ж��Ƿ���Ҫ��ԭ 
				}
				//���sec
				CCurrentY=(pt.x)/CFontSizeX;//���浱ǰλ�����꣬Ϊ�˺���һ�̶Ա� 
				CCurrentX=(pt.y)/CFontSizeY;
				bs=0;
				if(Trans)//bs��ǰ���㴰�ڣ�CCurrentWDĬ�Ͻ��㴰�� 
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
				CSpeedRefresh(0);//����ˢ����ɫ����Ҫrefresh���������������Ҳ��Ҫ���ʷ��ڴ˴� 
				//��������˴��� sec
				if (CTopCurrentWindow && bs!=CTopCurrentWindow)
				{
					CCurrentWD=bs;
					continue;
				}
				//����л��˴��� sec
				if (bs!=CCurrentWD)
				{
					CCurrentWD=bs;
					if (bs)
					{
						CShowWindow(CCurrentWD);
						CSpeedRefresh(1,CCurrentWD);
					}
				}
				//���ͣ�� sec
				ColoredPositionX=CCurrentX,ColoredPositionY=CCurrentY;//λ�õ�tmp
				if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1)ColoredValue=CValue_sys[CCurrentWD][CCurrentX][CCurrentY-1];
				else ColoredValue=CValue_sys[CCurrentWD][CCurrentX][CCurrentY];//��ɫ�����ĸ���ť
				ColoredColor=//ԭ����ɶɫ 
				CTempColor=CColor_sys[CCurrentWD][CCurrentX][CCurrentY];//��ɶɫ
				if ((ColoredColor&(0x10|0x20|0x40|0x80))==0)//���û�б���
				{
					CTempColor|=0x1|0x2|0x4|0x8|0x10|0x20|0x40;//���ɫ����+����ɫ���� 
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
				//��ԭcolor sec
				CSpeedRefresh(0);//��ֹ���֣�������ˢ�� 
				if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]>0 || CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1 && CValue_sys[CCurrentWD][CCurrentX][CCurrentY-1]>0)
				//Button=2ʱ����=0�������ǣ�����ر�С���ж�����(һ����������) 
				//������ֵ ����ǰ�����ֵ 
				if (ColoredColor)
				{
					while(ColoredPositionY>0
					&&(CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==ColoredValue||
					CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==-1)//��֤������ 
					&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==CTempColor)//��֤��ɫ������ 
						ColoredPositionY--;//�����ҵ������ 
					while((CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==ColoredValue||
					CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==-1)
					&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==CTempColor)
					{
						CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=ColoredColor;//��ԭ 
						CIfRefresh_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=1;
						ColoredPositionY++;//����Ⱦɫ
					}
					ColoredColor=0;//��ColoredColor�ж��Ƿ���Ҫ��ԭ 
				}
				//��������sec ABpart��һ���� 
				//���sec
				CCurrentY=(pt.x)/CFontSizeX;//���浱ǰλ�����꣬Ϊ�˺���һ�̶Ա� 
				CCurrentX=(pt.y)/CFontSizeY;
				bs=0;
				if(Trans)//bs��ǰ���㴰�ڣ�CCurrentWDĬ�Ͻ��㴰�� 
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
				//��������˴��� sec
				if (CTopCurrentWindow && bs!=CTopCurrentWindow)
				{
					CCurrentWD=bs;
					CSpeedRefresh(0);
					continue;
				}
				//����л��˴��� sec
				if (bs!=CCurrentWD)
				{
					CCurrentWD=bs;
					if (bs)
					{
						CShowWindow(CCurrentWD);
						CSpeedRefresh(1,CCurrentWD);
					}
				}
				//���ͣ��sec
				ColoredColor=CColor_sys[CCurrentWD][CCurrentX][CCurrentY];//��ע����һ����· 
				if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]>0 || CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1 && CValue_sys[CCurrentWD][CCurrentX][CCurrentY-1]>0)
				{
					ColoredPositionX=CCurrentX,ColoredPositionY=CCurrentY;//λ�õ�tmp
					if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1)ColoredValue=CValue_sys[CCurrentWD][CCurrentX][CCurrentY-1];
					else ColoredValue=CValue_sys[CCurrentWD][CCurrentX][CCurrentY];//��ɫ�����ĸ���ť
					ColoredColor=//ԭ����ɶɫ 
					CTempColor=CColor_sys[CCurrentWD][CCurrentX][CCurrentY];//��ɶɫ
					if ((ColoredColor&(0x10|0x20|0x40|0x80))==0)//���û�б���
					{
						CTempColor|=0x1|0x2|0x4|0x8|0x10|0x20|0x40;//���ɫ����+����ɫ���� 
					}
					else CTempColor|=0x8| 0x80;//��ɫ����+��ɫ���� 
					while(ColoredPositionY>0
					&&(CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==ColoredValue||
					CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==-1)
					&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==ColoredColor)
						ColoredPositionY--;//�����ҵ������ 
					while((CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==ColoredValue||
					CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==-1)
					&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==ColoredColor)
					{
						CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=CTempColor;
						CIfRefresh_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=1;
						ColoredPositionY++;//����Ⱦɫ
					}
				}
			}
			else if (CButton==0)
			{
				if (ColoredColor)
				{//͵��һ��С��������Button=0��ʱ���������Ⱦɫ��Ϊ�˻�ԭColor2��������ôд�Ű� 
					while(ColoredPositionY>0
					&&(CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==ColoredValue||
					CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==-1)//��֤������ 
					&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==CTempColor)//��֤��ɫ������ 
						ColoredPositionY--;//�����ҵ������ 
					while((CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==ColoredValue||
					CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==-1)
					&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==CTempColor)
					{
						CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=ColoredColor;//��ԭ 
						CIfRefresh_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=1;
						ColoredPositionY++;//����Ⱦɫ
					}
					ColoredColor=0;//��ColoredColor�ж��Ƿ���Ҫ��ԭ 
				}
				//��������sec ABpart��һ���� 
				//���sec
				CCurrentY=(pt.x)/CFontSizeX;//���浱ǰλ�����꣬Ϊ�˺���һ�̶Ա� 
				CCurrentX=(pt.y)/CFontSizeY;
				bs=0;
				if(Trans)//bs��ǰ���㴰�ڣ�CCurrentWDĬ�Ͻ��㴰�� 
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
				//��������˴��� sec
				if (CTopCurrentWindow && bs!=CTopCurrentWindow)
				{
					CCurrentWD=bs;
					CSpeedRefresh(0);
					continue;
				}
				//����л��˴��� sec
				if (bs!=CCurrentWD)
				{
					CCurrentWD=bs;
					if (bs)
					{
						CShowWindow(CCurrentWD);
						CSpeedRefresh(1,CCurrentWD);
					}
				}
				ColoredColor=CColor_sys[CCurrentWD][CCurrentX][CCurrentY];//��ע����һ����· 
			}
			
			if(KEY_DOWN(MOUSE_MOVED) && CClickable)//CClickable=0ʱΪԤ��ģʽ 
			{
				if (CButton==2 && (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]>0 || CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1 && CValue_sys[CCurrentWD][CCurrentX][CCurrentY-1]>0))//����ɫwhen ��� 
				{
					t=CTempColor;
					CTempColor=ColoredColor;
					if ((ColoredColor&(0x10|0x20|0x40|0x80))==0)//û�б��� 
					{
						CTempColor|=0x80;//ȥ����ɫ����+���ɫ���� 
						CTempColor&=~(0x8);
					}
					else CTempColor&=~(0x80|0x8);//ȥ����ɫ�������� 
					
					while(ColoredPositionY>0
					&&(CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==ColoredValue||
					CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==-1)
					&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==t)
						ColoredPositionY--;//�����ҵ������ 
					while((CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==ColoredValue||
					CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==-1)
					&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==t)
					{
						CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=CTempColor;
						CIfRefresh_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=1;
						ColoredPositionY++;//����Ⱦɫ
					}
				}
				else if (CButton==1)
				{
					t=CTempColor;
					CTempColor=ColoredColor;
					if ((ColoredColor&(0x10|0x20|0x40|0x80))==0)//û�б��� 
					{
						CTempColor|=0x80;//ȥ����ɫ����+���ɫ���� 
						CTempColor&=~(0x8);
					}
					else CTempColor&=~(0x80|0x8);//ȥ����ɫ�������� 
					
					if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1)
					{
						CColor_sys[CCurrentWD][CCurrentX][CCurrentY-1]=CTempColor;
						CIfRefresh_sys[CCurrentWD][CCurrentX][CCurrentY-1]=1;
					}
					CColor_sys[CCurrentWD][CCurrentX][CCurrentY]=CTempColor;
					CIfRefresh_sys[CCurrentWD][CCurrentX][CCurrentY]=1;
				}
				
				//������ (�����)
				t=0;//t=0�������û�е����Чֵ 
				if (FV)//>0
				{
					if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1)//ʵ��û�취��������Ĳ��ø� 
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
				if((CValue_sys[CCurrentWD][CCurrentX][CCurrentY]>0//����ˡ�ѡ���˰�ť 
				||CValue_sys[CCurrentWD][CCurrentX][CCurrentY-1]>0)//ȫ���ַ��ĺ��� 
				&& CValue_sys[CCurrentWD][CCurrentX][CCurrentY-1]!=32767)//���϶����� 
				{
					CSpeedRefresh(0);
					while(KEY_DOWN(MOUSE_MOVED))Sleep(dl);//�ȴ���굯�� 
					if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1)//ȫ���ַ��ĺ��� 
					{
						gotoxy(CCurrentX,CCurrentY-1);//������Ǹ��ַ� 
						SetConsoleTextAttribute(COutputHandle,CColor_sys[CCurrentWD][CCurrentX][CCurrentY-1]);
						cout<<CChar_sys[CCurrentWD][CCurrentX][CCurrentY-1];
					}
					else
					{
						gotoxy(CCurrentX,CCurrentY);//������Ǹ��ַ� 
						SetConsoleTextAttribute(COutputHandle,CColor_sys[CCurrentWD][CCurrentX][CCurrentY]);
						cout<<CChar_sys[CCurrentWD][CCurrentX][CCurrentY];
					}
					
					t=0;
					GetCursorPos(&pt);//����ط�Ϊ��̽�����Ժ������ƿ���꣨ȡ�������� 
					pt.x-=CConsoleLeft;
					pt.y-=CConsoleTop;
					if(CValue_sys[CCurrentWD][(pt.y)/CFontSizeY][(pt.x)/CFontSizeX]==-1)pt.x-=CFontSizeX;//�������ȫ���ַ��ĺ��飬��ôת�� 
					if(CValue_sys[CCurrentWD][(pt.y)/CFontSizeY][(pt.x)/CFontSizeX]<=0)t=1;//����ƿ��� 
					if (!t)
					{
						CChoseValue[++CChoseValue[0]]=CValue_sys[CCurrentWD][(pt.y)/CFontSizeY][(pt.x)/CFontSizeX];//��ֵ���浽CChoseValue�� 
						if(!ls){OptionsDeep();CEnabled=0;lr();return NULL;}//ls�Ƿ��������ֵ 
					}
				}
				
				if(CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==32767
				&&CMovable_sys[CCurrentWD]==0)//�ƶ�����(����˱߿�)��CMovable_sys�ɷ��ƶ� 
				{
					if (ColoredColor)
					{//����͵��һ��С��
						while(ColoredPositionY>0
						&&(CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==ColoredValue||
						CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==-1)//��֤������ 
						&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==CTempColor)//��֤��ɫ������ 
							ColoredPositionY--;//�����ҵ������ 
						while((CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==ColoredValue||
						CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==-1)
						&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==CTempColor)
						{
							CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=ColoredColor;//��ԭ 
							CIfRefresh_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=1;
							ColoredPositionY++;//����Ⱦɫ
						}
						ColoredColor=0;//��ColoredColor�ж��Ƿ���Ҫ��ԭ 
					}
					tCCurrentX=tCCurrentY=1;
					while(KEY_DOWN(MOUSE_MOVED))//������Ҫ��ȥ�ĵط� 
					{
						GetCursorPos(&pt);
						if (pt.y<CConsoleTop||pt.y>CConsoleBottom-CConsoleBoard-CConsoleTopBoard-(CFontSizeY<<2)//�����߿� 
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
					for(int j=CWindowLeft_sys[CCurrentWD];j<=CWindowRight_sys[CCurrentWD];j++)//��� 
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
					if(CWindowLeft_sys[CCurrentWD]< -tmpy)tmpy= 0-CWindowLeft_sys[CCurrentWD];//������߿� 
					if(CWindowTop_sys[CCurrentWD]< -tmpx)tmpx= 0-CWindowTop_sys[CCurrentWD];//�����ϱ߿� 
					if(CWindowRight_sys[CCurrentWD]+tmpy>(CConsoleRight-CConsoleLeft-(CConsoleBoard<<1))/CFontSizeX-2)//�����ұ߿� 
					tmpy=(CConsoleRight-CConsoleLeft-(CConsoleBoard<<1))/CFontSizeX-2-CWindowRight_sys[CCurrentWD];
					if(CWindowBottom_sys[CCurrentWD]+tmpx>(CConsoleBottom-CConsoleTop-CConsoleTopBoard-CConsoleBoard)/CFontSizeY)//�����±߿� 
					tmpx=(CConsoleBottom-CConsoleTop-CConsoleTopBoard-CConsoleBoard)/CFontSizeY-CWindowBottom_sys[CCurrentWD];
					 
					CDeleteWindow(CCurrentWD);//Delete����hide 
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
					CTasks_sys[0]-=2;//ǰ����������Ҫͳһrefresh�ģ��������һ�θ㶨 
					CTasks_sys[++CTasks_sys[0]]=0;//���� 
					CSpeedRefresh(0);
				}
				//����ʹ��oldversion���񲻶Ծ�����Ϊ��ֻ�ǻ�û�����ö��� 
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
				
				//��ԭcolor 
				if (CButton==2)
				if (CValue_sys[CCurrentWD][CCurrentX][CCurrentY]>0 || CValue_sys[CCurrentWD][CCurrentX][CCurrentY]==-1 && CValue_sys[CCurrentWD][CCurrentX][CCurrentY-1]>0)
				{
					while(ColoredPositionY>0
					&&(CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==ColoredValue||
					CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==-1)
					&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY-1]==CTempColor)
						ColoredPositionY--;//�����ҵ������ 
					while((CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==ColoredValue||
					CValue_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==-1)
					&&CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]==CTempColor)
					{
						CColor_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=ColoredColor;//��ԭ 
						CIfRefresh_sys[CCurrentWD][ColoredPositionX][ColoredPositionY]=1;
						ColoredPositionY++;//����Ⱦɫ
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
			else if (FV>1)//��������ʱ��겻�ɼ�����ô���ԭ�ַ� ,����������0 
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
			if(CValue_sys[bs][CCurrentX][CCurrentY]>0)CCurrentValidValue=CValue_sys[bs][CCurrentX][CCurrentY];		//�������Чֵ
			if(CValue_sys[bs][CCurrentX][CCurrentY]==-1)CCurrentValidValue=CValue_sys[bs][CCurrentX][CCurrentY-1];
			CCurrentValue=CValue_sys[bs][CCurrentX][CCurrentY];	//��ʱֵ
			
			
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
}; 

#ifndef _CLICKING_//ͷ�ļ�������main 
int main(int argc,char* argv[])
{
//���ĺ���bug
//	_example();
//	return 0;
	cout<<"������������\n(��ǰ����)"<<CurrentFontSizeX<<" "<<CurrentFontSizeY<<endl;
	cout<<"��ø�������밴 H \n�ۿ�ʵ���밴 E \n";
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
		for(int i=1;i<=5;i++)CDeleteWindow(i);
#else
		puts("\n[Main]WARNING:_example() not found\nDisable CLICK_RELEASE to avoid");
		Sleep(500);
#endif
	}
 return 0;
}
#endif