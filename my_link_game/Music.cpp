#include "pch.h"
#include "Music.h"
#include "resource.h"
#pragma comment(lib,"Winmm.lib")

Music::Music()
{
}


Music::~Music()
{

}

//���ű�������
void Music::bgm()
{
	// ������ʱ�ļ����ļ���
	TCHAR tmpmp3[_MAX_PATH];
	::GetTempPath(_MAX_PATH, tmpmp3);
	_tcscat_s(tmpmp3, _T("testapp_background.mp3"));		// VC2008��VC2010 ���� _tcscat_s ����

	// �� MP3 ��Դ��ȡΪ��ʱ�ļ�
	extractResource(tmpmp3, _T("MP3"), _T("background.mp3"));
	// ע����� MP3 ��Դ�� ID Ϊ�� IDR_BACKGROUND����������
	// ExtractResource(tmpmp3, _T("MP3"), MAKEINTRESOURCE(IDR_BACKGROUND));

	// ������
	TCHAR mcicmd[300];
	_stprintf_s(mcicmd, _T("open \"%s\" alias mymusic"), tmpmp3);		// VC2008��VC2010 ���� _stprintf_s ����
	mciSendString(mcicmd, NULL, 0, NULL);

	// ��������
	mciSendString(_T("play mymusic repeat"), NULL, 0, NULL);//repeat�ظ�ѭ������

	////if(gameTime)
	//// ֹͣ���Ų��ر�����
	//mciSendString(_T("stop mymusic"), NULL, 0, NULL);
	//mciSendString(_T("close mymusic"), NULL, 0, NULL);

	//// ɾ����ʱ�ļ�
	//DeleteFile(tmpmp3);
}

void Music::victoryMusic()
{

	PlaySound(LPWSTR(IDR_WAVE3), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC );

	Sleep(2000);

	ExitThread(0);		//�˳������̣߳�
}

void Music::defeatMusic()
{
	PlaySound(LPWSTR(IDR_WAVE2), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);

	
	//�ȴ�����
	Sleep(2000);  
	ExitThread(0);		//�˳����̣߳�
}

//////////////////////////////////////////////////////////////////
// ��ȡָ��ģ���е���Դ�ļ�
// ������
//		strDstFile:		Ŀ���ļ�������ȡ����Դ�����������
//		strResType:		��Դ���ͣ�
//		strResName:		��Դ���ƣ�
// ����ֵ��
//		true: ִ�гɹ���
//		false: ִ��ʧ�ܡ�
bool Music::extractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName)
{
	// �����ļ�
	HANDLE hFile = ::CreateFile(strDstFile, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return false;

	// ������Դ�ļ��С�������Դ���ڴ桢�õ���Դ��С
	HRSRC	hRes = ::FindResource(NULL, strResName, strResType);
	HGLOBAL	hMem = ::LoadResource(NULL, hRes);
	DWORD	dwSize = ::SizeofResource(NULL, hRes);

	// д���ļ�
	DWORD dwWrite = 0;  	// ����д���ֽ�
	::WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);
	::CloseHandle(hFile);

	return true;
}

void Music::clearMusic()
{
	
	PlaySound(LPWSTR(IDR_WAVE4), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);

	ExitThread(0);		//�˳��̣߳�
}




