@echo off
cd /d "E:\Git repository\Public-Project\"
git add .
Set str=
Set /p str=���ṩcommit
If not defined str (echo Ĭ�ϣ�LatestUpdate%date:~0,4%%date:~5,2%%date:~8,2%.%time:~0,2%%time:~3,2%
Set str=LatestUpdate%date:~0,4%%date:~5,2%%date:~8,2%.%time:~0,2%%time:~3,2%)else echo %str%

git commit -m %str%
git push --set-upstream PP master