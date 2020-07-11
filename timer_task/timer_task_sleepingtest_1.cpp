#include<iostream>
#include<cstdio>
#include<windows.h>
#include<tchar.h>
#include<string>
#include<ctime>
#include<cstring>
using namespace std;
const int TIMER1=1000;
const int TIMER1_INTERVAL=10000;
const int TIMER2=1001;
const int TIMER2_INTERVAL=1000;
int m_dwCnts,m_nTimeout,m_bAPMSUSPEND,m_bAPMRESUMESUSPEND,m_bResult;
void OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nIDEvent)
	{
		
	case TIMER1:
		{
			m_dwCnts++;
			cout<<_T("m_dwCnts=")+m_dwCnts<<"\nIDC_STATIC_TIMER: "<<m_nTimeout-m_dwCnts<<endl;;
//			string strSeconds=;
//			strSeconds.Format(_T("%ds"));
			//strSeconds.Format(_T("%ds"), 40);
//			GetDlgItem(IDC_STATIC_TIMER)->SetWindowText(strSeconds);
			
			//3���Ӻ�ִ��
			//if (m_dwCnts==3)
			//{
			//	system("shutdown -h");
			//	//SetSystemPowerState(false, false);
			//	//Sleep(1000*6);
			//}
		
			string  strTemp;
			CFile  mFile;
			DWORD dwAttr = GetFileAttributes(_T("C://test"));
			//���ļ��в����ڣ������ļ���
 
			if (dwAttr == 0xFFFFFFFF){
				CreateDirectory(_T("C://test"), NULL);
			}
//			else{
				mFile.Open(_T("C://test//log.txt "), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
//			}
						
			WORD unicode = 0xFEFF; //�����Ҫ
			mFile.SeekToBegin();
			mFile.Write(&unicode, 2); //�����Ҫ    
 
//			ctime time = CTime::GetCurrentTime(); ///����CTime����
//			string m_strTime = time.Format("%Y-%m-%d %H:%M:%S");
			
		
			if (m_bAPMSUSPEND && m_bAPMRESUMESUSPEND)
			{
				SetTimer(GetConsoleWindow(),TIMER2,TIMER2_INTERVAL,NULL);
				m_bResult = TRUE;
				KillTimer(GetConsoleWindow(),TIMER1);
				mFile.SeekToEnd();
				mFile.Write(_T("\r\n"), sizeof(_T("\r\n")));
				strTemp = _T("TestTime:")  + _T(" result��pass ");
				mFile.Write(strTemp, wcslen(strTemp)*sizeof(wchar_t));
				GetDlgItem(IDC_STATIC_INFO)->SetWindowText(_T("����ͨ��!"));
				
 
			}
			else if(m_dwCnts >= static_cast<DWORD>(m_nTimeout))
			{
				SetTimer(GetConsoleWindow(),TIMER2,TIMER2_INTERVAL,NULL);
				m_bResult = FALSE;
				KillTimer(GetConsoleWindow(),TIMER1);
				mFile.SeekToEnd();
				mFile.Write(_T("\r\n"), sizeof(_T("\r\n")));
				strTemp = ("TestTime:")  + (" result��fail ");
				mFile.Write(strTemp, wcslen(strTemp)*sizeof(wchar_t));
				GetDlgItem(IDC_STATIC_INFO)->SetWindowText(_T("����ʧ��!"));
				
			}
			mFile.Flush();
			mFile.Close();
		}
		break;
	case TIMER2:
		{
			KillTimer(TIMER2);
			if (m_bResult)
			{
				exit(0);
			}
			else
			{
				exit(1);
			}
		}
	default:
		break;
	}
	OnTimer(nIDEvent);
}

LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: �ڴ����ר�ô����/����û���
	//TRACE(_T("%04x\r\n"),message);
	switch (message)
	{
		
 
	case WM_POWERBROADCAST:
		{
			TRACE(_T("%04x\r\n"),wParam);
			//ϵͳ˯����
			if(wParam == PBT_APMSUSPEND)
			{
				m_bAPMSUSPEND = TRUE;
			}
			//ϵͳ������
			else if (wParam == PBT_APMRESUMESUSPEND)
			{
				m_bAPMRESUMESUSPEND = TRUE;
			}
		}
		break;
	default:
		break;
	}
//	return CDialogEx::WindowProc(message, wParam, lParam);
	return 
}
int main()
{
	string strCommandLine = GetCommandLine();
	strCommandLine.TrimLeft().TrimRight();
	string strTimeout;
	int idx = strCommandLine.Find(_T(" "));
	if (idx != -1)
	{
		strTimeout = strCommandLine.Mid(idx+1);
		strTimeout.TrimLeft().TrimRight();
				
		//m_nTimeout = _ttoi(strTimeout);
		//======================================================//
		m_nTimeout = 50;
	}
//	TRACE(_T("m_nTimeout = %d\r\n"),m_nTimeout);
	SetTimer(TIMER1,TIMER1_INTERVAL,NULL);
}
