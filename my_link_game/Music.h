#pragma once
class Music
{
public:
	Music();
	~Music();

	void clearMusic();				//���ͼƬ�����֣�
	void bgm();						//��Ϸ��ʼǰ���ر���ͼƬ������
	void victoryMusic();			//ʤ�����֣�
	void defeatMusic();				//ʧ�����֣�
	// ��ȡָ��ģ���е���Դ�ļ�;��������easyx��վ��
	bool extractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName);			
};

