@echo off

::在这里更改路径
cd /d "F:\Dotoro's private document\程序\#DEV-C++\timer_task"

::可以把所有的timeout注释掉以提升运行速度

start "快来上课啦" timer_task.exe "3" "0"

::在这里输入提示
echo timer_task提醒：
copy C:\Users\dotoro\Desktop\提醒NOTICE\temp.txt con

echo.
pause

echo.
echo.
echo 为了正常运行，请准时于7:25启动程序
echo 停止后建议在课前10分钟启动
echo.
echo 现在时间：
time /t
echo.
echo.

echo timer_task提醒：我将停止正在运行的timer_task任务！

timeout 5

taskkill -f -im "timer_task.exe"
cls

::下面5行要记得注释掉
echo timer_task提醒：除非你知道自己在做什么，否则请输入n
if exist ".\timer_task.exe" ( erase .\timer_task.exe /p )
if not exist ".\timer_task.exe" (echo 正在编译程序)
if not exist ".\timer_task.exe" (start /wait E:\Dev-C++\Dev-Cpp\MinGW64\bin\g++.exe timer_task.cpp)
if exist ".\a.exe" (rename a.exe timer_task.exe)

if not exist ".\timer_task.exe" (echo 错误：编译错误)
if not exist ".\timer_task.exe" (pause)
if not exist ".\timer_task.exe" (exit)
timeout 2 /nobreak
cls

echo timer_task提醒：为了正常运行，请允许更改电源设置
::powercfg -h off
powercfg -change -standby-timeout-dc 0
powercfg -change -standby-timeout-ac 0
powercfg -change -disk-timeout-dc 0
powercfg -change -disk-timeout-ac 0
echo.
echo 1.18:10shutdown 命令
start /min "定时关机命令" timer_task.exe "2" "shutdown -s -t 15" "EOF" "18" "15" "10"
echo 2.7:25早读提示 命令
start /min "早读提示" timer_task.exe "2" "echo 今天很准时~~准备早读啦！" "EOF" "7" "26" "10"
echo 3.10:35上午眼保健操 命令
::start /min "上午的眼保健操" timer_task.exe "2" "EOF" "10" "35" "10"
echo 4.16:05下午眼保健操 命令
::start /min "下午的眼保健操" timer_task.exe "2" "EOF" "16" "05" "10"
echo 5.14:20下午课程提醒器 命令
start /min "下午的课程提醒器" timer_task.exe "2" "start \"下午的课程提醒器\" ./timer_task.exe "4" "54" "6" "3" "1" "start_now" " "echo 准备好下午的书，作业，记得查看上一次的作业批改" "EOF" "14" "26" "10"
echo 6.7:50上午课程提醒器 命令
start /min "上午的课程提醒器" timer_task.exe "2" "start \"上午的课程提醒器\" ./timer_task.exe "4" "54" "6" "3" "1" "start_now" " "echo 准备好早上的书，作业，记得查看上一次的作业批改" "echo 要交早读作业！" "echo 做开学健康登记" "echo 调麦，调音箱" "EOF" "7" "55" "10"
echo 7.QQPCmgr
if not exist "E:\QQPCMgr\13.5.20525.234" (echo 未检测到电脑管家) else (start /min "垃圾清理" timer_task.exe "2" "start qmgc" "echo 记得看看作业，抄到纸上" "echo 另外更新分数记录" "EOF" "18" "08" "10")


timeout 2 /nobreak
cls

echo 8.微信
if not exist "E:\Program Files\WeChat\WeChat.exe" ( echo 未检测到wechat ) else ( start "" "E:\Program Files\WeChat\WeChat.exe" )
echo 9.QQ
if not exist "E:\Program Files\Tencent\QQ\Bin\QQ.exe" ( echo 未检测到qq ) else ( start "" "E:\Program Files\Tencent\QQ\Bin\QQ.exe" )
echo 10.腾讯课堂
if not exist "E:\TXEDU\1.5.4.25\bin\TXEDU.exe" ( echo 未检测到TXEDU ) else ( start "" "E:\TXEDU\1.5.4.25\bin\TXEDU.exe" )

timeout 2 /nobreak
cls

echo 11.record\sound try
if not exist "E:\coolpro2\coolpro2.exe" ( echo 未检测到coolpro ) else (start E:\coolpro2\coolpro2.exe)
echo 12.录屏
if not exist E:\BandiCam\bdcam.exe ( echo 未检测到bandicam ) else ( start E:\BandiCam\bdcam.exe /nosplash)
echo 13.课程表
if not exist "网课课程表.xlsx" ( echo 未检测到课程表 ) else ( start "" "网课课程表.xlsx")

echo 完毕
time /t
exit