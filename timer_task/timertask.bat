@echo off

::���������·��
cd /d "F:\Dotoro's private document\����\#DEV-C++\timer_task"

::���԰����е�timeoutע�͵������������ٶ�

start "�����Ͽ���" timer_task.exe "3" "0"

::������������ʾ
echo timer_task���ѣ�
copy C:\Users\dotoro\Desktop\����NOTICE\temp.txt con

echo.
pause

echo.
echo.
echo Ϊ���������У���׼ʱ��7:25��������
echo ֹͣ�����ڿ�ǰ10��������
echo.
echo ����ʱ�䣺
time /t
echo.
echo.

echo timer_task���ѣ��ҽ�ֹͣ�������е�timer_task����

timeout 5

taskkill -f -im "timer_task.exe"
cls

::����5��Ҫ�ǵ�ע�͵�
echo timer_task���ѣ�������֪���Լ�����ʲô������������n
if exist ".\timer_task.exe" ( erase .\timer_task.exe /p )
if not exist ".\timer_task.exe" (echo ���ڱ������)
if not exist ".\timer_task.exe" (start /wait E:\Dev-C++\Dev-Cpp\MinGW64\bin\g++.exe timer_task.cpp)
if exist ".\a.exe" (rename a.exe timer_task.exe)

if not exist ".\timer_task.exe" (echo ���󣺱������)
if not exist ".\timer_task.exe" (pause)
if not exist ".\timer_task.exe" (exit)
timeout 2 /nobreak
cls

echo timer_task���ѣ�Ϊ���������У���������ĵ�Դ����
::powercfg -h off
powercfg -change -standby-timeout-dc 0
powercfg -change -standby-timeout-ac 0
powercfg -change -disk-timeout-dc 0
powercfg -change -disk-timeout-ac 0
echo.
echo 1.18:10shutdown ����
start /min "��ʱ�ػ�����" timer_task.exe "2" "shutdown -s -t 15" "EOF" "18" "15" "10"
echo 2.7:25�����ʾ ����
start /min "�����ʾ" timer_task.exe "2" "echo �����׼ʱ~~׼���������" "EOF" "7" "26" "10"
echo 3.10:35�����۱����� ����
::start /min "������۱�����" timer_task.exe "2" "EOF" "10" "35" "10"
echo 4.16:05�����۱����� ����
::start /min "������۱�����" timer_task.exe "2" "EOF" "16" "05" "10"
echo 5.14:20����γ������� ����
start /min "����Ŀγ�������" timer_task.exe "2" "start \"����Ŀγ�������\" ./timer_task.exe "4" "54" "6" "3" "1" "start_now" " "echo ׼����������飬��ҵ���ǵò鿴��һ�ε���ҵ����" "EOF" "14" "26" "10"
echo 6.7:50����γ������� ����
start /min "����Ŀγ�������" timer_task.exe "2" "start \"����Ŀγ�������\" ./timer_task.exe "4" "54" "6" "3" "1" "start_now" " "echo ׼�������ϵ��飬��ҵ���ǵò鿴��һ�ε���ҵ����" "echo Ҫ�������ҵ��" "echo ����ѧ�����Ǽ�" "echo ���󣬵�����" "EOF" "7" "55" "10"
echo 7.QQPCmgr
if not exist "E:\QQPCMgr\13.5.20525.234" (echo δ��⵽���Թܼ�) else (start /min "��������" timer_task.exe "2" "start qmgc" "echo �ǵÿ�����ҵ������ֽ��" "echo ������·�����¼" "EOF" "18" "08" "10")


timeout 2 /nobreak
cls

echo 8.΢��
if not exist "E:\Program Files\WeChat\WeChat.exe" ( echo δ��⵽wechat ) else ( start "" "E:\Program Files\WeChat\WeChat.exe" )
echo 9.QQ
if not exist "E:\Program Files\Tencent\QQ\Bin\QQ.exe" ( echo δ��⵽qq ) else ( start "" "E:\Program Files\Tencent\QQ\Bin\QQ.exe" )
echo 10.��Ѷ����
if not exist "E:\TXEDU\1.5.4.25\bin\TXEDU.exe" ( echo δ��⵽TXEDU ) else ( start "" "E:\TXEDU\1.5.4.25\bin\TXEDU.exe" )

timeout 2 /nobreak
cls

echo 11.record\sound try
if not exist "E:\coolpro2\coolpro2.exe" ( echo δ��⵽coolpro ) else (start E:\coolpro2\coolpro2.exe)
echo 12.¼��
if not exist E:\BandiCam\bdcam.exe ( echo δ��⵽bandicam ) else ( start E:\BandiCam\bdcam.exe /nosplash)
echo 13.�γ̱�
if not exist "���ογ̱�.xlsx" ( echo δ��⵽�γ̱� ) else ( start "" "���ογ̱�.xlsx")

echo ���
time /t
exit