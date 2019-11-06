#include "pch.h"
#include "Game.h"
// ���� Windows Multimedia API
#pragma comment(lib,"Winmm.lib")
#include  "Image.h"
#include "Music.h"
#include <conio.h>
#include <thread>


bool Game::infiniteMode = false;

Game::~Game()
{
}

//����һ��ȫ�ֵ�Image����󣻱��ڰ�ť���жϣ�
Image image;

void Game::controller()
{
	Music music;		
	music.bgm();
	window();

	Image infiniteImage(INFI_PX, INFI_PY, INFI_GRID_SIZE, INFI_ROW, INFI_COLUMN, INFI_IMAGE_NUMBER);
	Image levelImage(LEVEL_PX, LEVEL_COLUMN, LEVEL_GRID_SIZE, LEVEL_ROW, LEVEL_COLUMN, INITo_IMAGE_NUMBER);

	//����һ�������Ϣ�����ж�
	MOUSEMSG mouse;
	//����һ��boolʹ�ò���ѭ����ִֻ��һ��
	bool newStart = true;
	//��¼�ؿ������Ա�ָ�

	while (1)
	{
		//newStart���ж�ʹ���ж��ڵ����ֻ��ѭ����ִ��һ�Σ�
		if (newStart == true) {
			newStart = false;
			//�������ͼƬ��exit����Ϸ��ʼ����ģ�
			cleardevice();
			//��ʼ��Ϸ�ı���ͼ
			image.gameStartImage();
			//����һ��Ȧ��ģʽ�Ķ��߳�
			std::thread modeB(&Game::modeBottom, this);
			modeB.detach();
		}
		//������µ������Ϣ��
		if (MouseHit()) {
			//ÿ��ѭ����Ҫ�õ������Ϣ
			mouse = GetMouseMsg();
		
			gameHelp(mouse);

			judgeMode(mouse);
			startPassMode(mouse);

			if (judgeStart(mouse)) {
				if (infiniteMode == true) {
				//���½�������ģʽ�ĸ���
					levelTime = INFI_TIME;
					gameTimePlus = 2;
					//���¿�ʼ���Ʒ�Ϊ0
					score = 0;
					//�����ǰ��Ļ�ϵ����ݣ�
					cleardevice();
					//��һ�ο�ʼ��һ������ģʽ�����ĸ��ӵ�ͼ
					infiniteImage.drawMap();
				}
				else {
					//���½��봳��ģʽ�ĸ���
					gameTimePlus = 3;
					//��ֹexit�ص���Ϸ���棬ʱ��Ϊ��һ�ص�ֵ
					levelTime = INIT_LEVEL_TIME+(levelImage.getLevel()-1)*gameTimePlus;
					//�����ǰ��Ļ�ϵ����ݣ�
					cleardevice();
					//��һ�ο�ʼ��һ������ģʽ�����ĸ��ӵ�ͼ
					levelImage.drawMap();
				}
				//����һ����ʱ�Ķ��߳�
				std::thread gameT(&Game::gameTime, this);
				gameT.detach();
				//���֮��ֵfalse����ֹ��һ��exit�ж���Ϊ�棻
				//���ܷ���exit�ж��ֻ�ܷ��ڿ�ʼ����Ϊ��ʱgameTime��judgeE==false�Ų���ʱ��
				judgeE = false;
				//��ֹ�����ͣ���ٵ��exit���ú���Ϸ��Ϊ��ͣ��
				judgeP = false;
				//��ʼ��ʱ,���¸�lastMomentֵ����ֹ��exit�˳����½��룻
				lastMoment = levelTime;
				if (infiniteMode == false) {
					//��һ������ʾ
					levelWord(levelImage.getLevel());
				}
				else {
					scoreWord();
				}
				if (judgePassB) {
					//��ʾͨ�ذ�ťͼƬ����ΪdrawMap֮�������֮ǰ��ͼƬ��
					image.passBottom();
				}
				//��Ϸ��ʼ֮���ѭ��
				while (1)
				{
					//������µ������Ϣ
					if (MouseHit()) {
						mouse = GetMouseMsg(); //ÿ��ѭ����Ҫ�õ������Ϣ
					//�������ͣ�Ϳ�ʼ����
						if (judgePause(mouse)) {
							//ȡ�����ı��¼״̬��
							judgeP = !judgeP;
							//�������ͣ��ť����Ϸ��ͣ
							if (judgeP == true) {
								//��ͣ��ť���ɿ�ʼ��ť����Ϸ��ͣ
								image.imageContinue();
							}
							else {//����˿�ʼ��ť��
								//��ʼ��ť������ͣ��ť����Ϸ��ʼ
								image.imagePause();
							}
						}
						//������˳���ť
						if (judgeExit(mouse) == true) {
							//�ص���Ϸ��ʼ���棻judgeSΪfalse����ȻȦ��ģʽ���̼߳�ⲻ����
							judgeS = false;
							//����newStart
							newStart = true;
							break;
						}
						//��Ϸʧ��;
						if (lastMoment == 0) {
							lastMoment = -1;
							while (1) {
								//����һ����ѭ����ֹ��������ִ�в��裨����ͼƬ����
							}
						}
						judgePassBottom(mouse);
						//�ؿ�ģʽ�ж�
						if (infiniteMode == false) {
							//��Ϸͨ�أ������ǿ�����ͨ��ģʽ�������ͨ�ذ�ť��
							if (levelImage.judgePass() == true || (judgePb  && judgePassB)) {
								//����ǰ���ͨ�ذ�ť��������Ϊfalse
								judgePb = false;
								
								//������Ϸʱ��,=-1�ü�ʱ���߳̽�����
								lastMoment = -1;
								//��ֹʹ��ͨ�ذ�ťʱ������ͣ��ť;������Ϊ����ͣ������ʼ����
								judgeP = false;
								//��Ϸʤ��
								gameVictory(levelImage.getLevel());
								//���ͨ���ˣ�
								//�ؿ����ͼƬ����һ
								levelImage.maxImageNumberPlus();
								if (levelImage.getLevel() == MAX_LEVEL) {
									//�ص���Ϸ��ʼ���棻judgeSΪfalse����ȻȦ��ģʽ���̼߳�ⲻ����
									judgeS = false;
									//���ùؿ���
									levelImage.initLevel();
									//���ùؿ�ͼƬ��
									levelImage.initMaxImageNumber();
									//������Ϸʱ��
									levelTime = INIT_LEVEL_TIME;
									//�ص���Ϸ��ʼ���棻
									//����newStart
									newStart = true;
									break;
								}
								//�ؿ�+1������ڲ�ʵ�ֻᵼ��ͨ�ذ�ťʧ��
								levelImage.levelPlus();
								// ������һ��;
								levelImage.drawMap() ;
								//�����ؿ�������ʾ
								levelWord(levelImage.getLevel());
								//��һ�ؿ�ʼ������ʱ�䣬��ȻӰ���жϣ�
								//��¼ÿһ�ص��޶�ʱ�䣻�����ü�ʱ����lastMoment=0��
								levelTime += gameTimePlus;
								lastMoment = levelTime;
								//���¿�ʼ����һ����ʱ�Ķ��߳�
								std::thread gameT(&Game::gameTime, this);
								gameT.detach();
								if (judgePassB) {
									//��ʾͨ�ذ�ťͼƬ����ΪdrawMap֮�������֮ǰ��ͼƬ��
									image.passBottom();
								}
								//�����껺���ֹ�ظ����ͨ�ذ�ť���ж�Ϊͨ��
								FlushMouseMsgBuffer();
							}
						}//����ģʽ�ж�
						else {
							
							if (infiniteImage.getClearOne() == true) {
								//����ͼƬ����ʱ��
								lastMoment += gameTimePlus;
								//���Ӽ�¼����
								score += scorePlus;
								scoreWord();
							}
							//�������ϷͼƬ�������ǿ�����ͨ��ģʽ�������ͨ�ذ�ť��
							if (infiniteImage.judgePass() == true || (judgePb && judgePassB)) {
								//��ֹʹ��ͨ�ذ�ťʱ������ͣ��ť;������Ϊ����ͣ������ʼ����
								judgeP = false;
								//�ؿ�����1�����±���ͼ
								infiniteImage.levelPlus();
								//���ùؿ�����
								if (infiniteImage.getLevel() == MAX_LEVEL+1) {
									infiniteImage.initLevel();
								}
								//����ǰ���ͨ�ذ�ť��������Ϊfalse
								judgePb = false;
								//������һ�ε�ͼƬ
								infiniteImage.drawMap();
								//���ط���
								scoreWord();
								//�����껺���ֹ�ظ����ͨ�ذ�ť���ж�Ϊͨ��
								FlushMouseMsgBuffer();
							}
							if (judgePassB) {
								//��ʾͨ�ذ�ťͼƬ����ΪdrawMap֮�������֮ǰ��ͼƬ��
								image.passBottom();
							}
							
						}
						//��Ϸû����ͣ�����ܽ����жϣ�
						if (judgeP == false) {
							//�ж�����
							if (infiniteMode==false) {
								levelImage.gridJudgement(mouse);
							}
							else {
								infiniteImage.gridJudgement(mouse);
							}

						}
					}
					
				}
			}
		}
	}
}

//����һ��ͼ�񴰿ڲ���ע�Լ�������
void Game::window()
{	
	//������ͼ���ڣ���СΪ WINDOW_WIDE��WINDOW_HEIGTH ����
	initgraph(WINDOW_WIDE, WINDOW_HEIGTH);

	// ��ȡ���ھ��
	HWND hwnd = GetHWnd();
	// ���ô��ڱ�������;����
	SetWindowText(hwnd, _T("������ҫ������       ���ߣ�������"));
}

//�ж��Ƿ�������Ϸ��ʼ��ť
bool Game::judgeStart(MOUSEMSG mouse)
{	 //ÿ�ν�����Ҫ����Ϊfalse	
	judgeS = false;
	if (mouse.mkLButton) {
		if (mouse.x >= 375 && mouse.x <= 624 && mouse.y >= 415 && mouse.y <= 470) {
			judgeS = true;
		}
	}
	
	return judgeS;
}

//�ж��Ƿ�������Ϸ������ť��
void Game::gameHelp(MOUSEMSG mouse)
{
	//ÿ�ν�������Ϊfalse��
	judgeH = false;
	if (mouse.mkLButton) {
		//�԰���ԲȦ����С�����δ��棻Բ�ģ�962, 81�� �뾶�� 24��
		if (mouse.x >= 938 && mouse.x <= 986 && mouse.y >= 67 && mouse.y <= 105) {
			// ���ÿ���̨ API�����֮ǰ�������ڵ����а������жϷ�ֹ֮ǰ���˼��̣���ǰ������
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			//��¼����İ�����ť
			judgeH = true;
			cleardevice();//����

			int textPx;//�����������Ͻǵ�x����
			int textPy;//�����������Ͻǵ�y����
			int textInterval;//��������֮������ļ��
			textPx = 50;
			textPy = 50;
			textInterval = 60;
			//�����Ϸ˵��
			setcolor(RGB(255, 255, 255));
			settextstyle(35, 0, _T("������κ"));
			setcolor(RGB(85, 255, 255));//��ɫ

			outtextxy(textPx, textPy, _T("����Ϸ��Ϊ���޺ʹ�������ģʽ��"));
			outtextxy(textPx, textPy + textInterval, _T("����ģʽ��ÿ����һ��ͼ��������ʱ����2s������ʱ����2s��"));
			outtextxy(textPx, textPy + textInterval * 2, _T("����ģʽ��ÿͨ��һ�أ�ͼƬ��������1�֣�����ʱ����3s��"));
			outtextxy(textPx, textPy + textInterval * 3, _T("���Ͱɣ����꣡ף�����Ŷ��"));
			outtextxy(textPx, textPy + textInterval * 4, _T("��Ϸ������ť"));
			outtextxy(textPx, textPy + textInterval * 5, _T("��Ϸ��ͣ��ť"));
			outtextxy(textPx, textPy + textInterval * 6, _T("��Ϸ���¿�ʼ��ť"));

			IMAGE img1;
			loadimage(&img1, _T("PNG"), _T("start"), 40, 40);
			putimage(textPx + textInterval * 4, textPy + textInterval * 4, &img1);

			IMAGE img2;
			loadimage(&img2, _T("PNG"), _T("pause"), 40, 40);
			putimage(textPx + textInterval * 4, textPy + textInterval * 5, &img2);

			IMAGE img3;
			loadimage(&img3, _T("PNG"), _T("exit"), 40, 40);
			putimage(textPx + textInterval * 5, textPy + textInterval * 6, &img3);
			// ʵ����˸�ġ��������������
			int c = 255;
			while (!_kbhit())
			{
				setcolor(RGB(c, 0, 0));
				outtextxy(700, 470, _T("�������������Ϸ"));
				c -= 4;
				if (c < 0) {
					c = 255;
				}
				Sleep(20);
			}
			setcolor(RGB(255, 255, 255));//��ɫ

			// ���ÿ���̨ API�����֮ǰ�������ڵ����а�����
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			//����
			cleardevice();
			//����֮��ᵽ������
			image.gameStartImage();
		}
	}

}

void Game::gameTime()
{
	//��¼��Ϸ��ʼʱ��;DWORDȫ��Double Word,unsigned long int��
	DWORD startTime=::GetTickCount();;
	//������¼������ʱ��
	DWORD stopTime= ::GetTickCount();;
	//����Ϸʱ��Ϊ0ʱ������Ϸʧ��ʱ���ͻص���Ϸ����ʱ����ʱ��
	while (lastMoment > 0 && judgeS == true) {
		//ÿ�����½����ʱ��Ҫ���¼�¼�ʼ��ʱ��ʱ��
		if (judgeP == false && lastMoment > 0 && judgeE == false && judgeS == true) {
			startTime = ::GetTickCount();
		}
		//��Ϸû�е���ͣ���ܼ�ʱ��lastMoent=-1ʱ��Ϸ����ʤ����ʧ��ҳ�棻
		//����exit�ص������治�ü�ʱ;��false���ܼ�ʱ
		//������Ϸ��ʼ��ť���ܼ�ʱ
		//�жϱ���д��while�����while��ֻ��while�����ж��˳���
		while (judgeP == false && lastMoment > 0 && judgeE == false && judgeS==true ) {

			//��¼��һ�ε�ʱ��
			stopTime = ::GetTickCount();
			//GettickCount��λΪ���룬�ʳ���1000Ϊsecond��
			second = (stopTime - startTime) / 1000;

			//�������ͣ��ť

			if (second == 1) {
				startTime = stopTime;
				lastMoment--;

				TCHAR s[5];
				settextcolor(RED);
				settextstyle(60, 50, _T("����"));
				//������ת���TCHAR���ͣ�
				swprintf_s(s, _T("%d"), lastMoment);
				if (lastMoment > 99) {
					outtextxy(750, 50, s);
					outtextxy(900, 50, _T("s"));
				}//��lastMomentֻ��ʮλʱ����ʾ�ֵ�λ��û�иı�
				else if (lastMoment > 9) {
					outtextxy(750, 50, _T("0"));
					outtextxy(800, 50, s);
					outtextxy(900, 50, _T("s"));
				}
				else {
					outtextxy(750, 50, _T("00"));
					outtextxy(850, 50, s);
					outtextxy(900, 50, _T("s"));
				}
			}
		}
	}
	// ���ÿ���̨ API�����֮ǰ�������ڵ����а������жϷ�ֹ֮ǰ���˼��̣���ǰ������
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	//��Ϸʧ�ܣ�������жϷ�ֹ��겻�ƶ����������ж�
	if (lastMoment == 0) {
		gameDefeat();
	}
	
	//�ر��̣߳�
	ExitThread(0);				
}

//��Ϸʤ��ʱ��������ͨ�أ��ļ���
void Game::gameVictory(int level)
{
	Music musicV;
	//����ʤ�����֣�
	//����һ���̣߳�thread���������Ա����Ҫ��ĺ����Ͷ���
	std::thread t(&Music::victoryMusic, &musicV);
	t.detach();

	Image allImageV;

	// ���ÿ���̨ API�����֮ǰ�������ڵ����а������жϷ�ֹ֮ǰ���˼��̣���ǰ������
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	if (level ==MAX_LEVEL) {
		allImageV.finalVictoryImage();
		//���������С����ɫ
		settextstyle(35, 0, _T("������κ"));
		setcolor(RED);//��ɫ
		outtextxy(300, 430, _T("��ϲ��ͨ�������еĹؿ�"));
		int c = 255;
		while (!_kbhit())
		{
			setcolor(RGB(c, 0, 0));
			outtextxy(300, 465, _T("���������ɷ���������"));
			c -= 4;
			if (c < 0) {
				c = 255;
			}
			Sleep(20);
		}
	}
	else {
		//����ʤ��ͼƬ��
		allImageV.imageVictory();
 		while (!_kbhit()) {
			//û�м����������ѭ����ס
		}
	}
	//_kbhit()ÿ�μ�¼�Ỻ�浽�ڴ��Ҫ��_getch()֮��ĵõ���¼�İ�����
	//��Ȼ��¼һ��֮��ÿ��ѭ����kbhit�������������жϵ������Ϊ�档
	// ���ÿ���̨ API�����֮ǰ�������ڵ����а�����
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

}

//��Ϸʧ��ʱ�ļ���
void Game::gameDefeat()
{
	Music musicD;
	//����ʧ�����֣�
	//����һ���̣߳�thread���������Ա����Ҫ��ĺ����Ͷ���
	std::thread tD(&Music::defeatMusic, &musicD);
	tD.detach();

	image.imageDefeat();
	//����ģʽ������ʾ��ֵ��
	if (infiniteMode == true) {
		//��������
		settextstyle(35, 0, _T("������κ"));
		setcolor(RED);//��ɫ
		outtextxy(350, 410, _T("��ϲ������"));
		TCHAR s[10];
		swprintf_s(s, _T("%d"), score);
		outtextxy(560, 410, s);
		outtextxy(650, 410, _T("��"));
	}
	
	//_getch������
	_getch();
	//�����˳�����
	exit(0);
}



void Game::levelWord(int level)
{

	TCHAR s[5];
	//setcolor(RGB(255, 255, 255));
	settextstyle(35, 0, _T("������κ"));
	setcolor(RGB(85, 255, 255));//��ɫ
	//������ת���TCHAR���ͣ�
	swprintf_s(s, _T("%d"), level);
	outtextxy(750, 150, _T("��ǰ�ؿ���"));
	setcolor(RGB(255, 255, 0));
	outtextxy(900, 200, s);
}


//�ж��Ƿ�������Ϸ��ͣ��ť
bool Game::judgePause(MOUSEMSG mouse)
{
	bool judge = false;
	if (mouse.mkLButton) {
		if (mouse.x >= PAUSE_PX && mouse.x <= PAUSE_PX+PAUSE_SIZE && 
			mouse.y >= PAUSE_PY && mouse.y <= PAUSE_PY+PAUSE_SIZE) {
			judge = true;
		}
	}
	return judge;
}

//�ж��Ƿ�������Ϸ���¿�ʼ��ť
bool Game::judgeExit(MOUSEMSG mouse)
{
	if (mouse.mkLButton) {
		if (mouse.x >= EXIT_PX && mouse.x <= EXIT_PX+EXIT_SIZE &&
			mouse.y >= EXIT_PY && mouse.y <= EXIT_PY+EXIT_SIZE) {
			judgeE = true;
		}
	}

	return judgeE;
}

//�ж��Ƿ�����ͨ�ذ�ť��
void Game::startPassMode(MOUSEMSG mouse)
{

	if ( mouse.mkRButton) {
		if (mouse.x >= PASS_LEFT_PX && mouse.x <= PASS_RIGHT_PX && mouse.y >> PASS_LEFT_PY && mouse.y << PASS_RIGHT_PY) {
				countPassB++;
		}
	}
	//���������ϲ��ܿ���ͨ�ذ�ť����ֹ�󴥣�
	if (countPassB >= 5) {
		//��ʾͨ�ذ�ťͼƬ����ʾ��ʼͨ�ذ�ť
		image.passBottom();
		judgePassB = true;
	}
	
}

//�ж��Ƿ�����ͨ�ذ�ť��
bool Game::judgePassBottom(MOUSEMSG mouse)
{

	if (mouse.mkRButton) {
		if (mouse.x >= WINDOW_WIDE - PASS_BOTTOM_SIZE && mouse.x <= WINDOW_WIDE &&
			mouse.y >= WINDOW_HEIGTH - PASS_BOTTOM_SIZE && mouse.y <= WINDOW_HEIGTH) {
			judgePb = true;
		}
	}
	return judgePb;
}

//�жϵ����ģʽ��
bool Game::judgeMode(MOUSEMSG mouse)
{
	if (mouse.mkLButton) {
		if (mouse.x >= INFINITE_PX && mouse.x <= INFINITE_PX + MODE_LENGTH && 
			mouse.y >= MODE_PY && mouse.y <= MODE_PY + MODE_WIDE) {
			infiniteMode = true;
		}
		else if(mouse.x>=LEVEL_MODE_PX && mouse.x<=LEVEL_MODE_PX+MODE_LENGTH && 
			mouse.y>=MODE_PY && mouse.y<=MODE_PY+MODE_WIDE ){
			infiniteMode = false;		
		}
	}
	return infiniteMode;
}

void Game::modeBottom()
{
	setlinestyle(PS_SOLID, 5);
	int c = 225;
	//ֻҪû�㿪ʼ���̾Ͳ�������
	while (judgeS == false) {
		if (infiniteMode == true) {
			if (judgeH == false) {
				//����Ȧ�еĴ���ģʽ
				image.levelBttom();
				c = 225;
			}			
			//Ȧ������ģʽ��ť;
			//û�н�����Ϸ�����û�н�����Ϸ����������ܼ���
			//����д��while�ж����Ϊ������while��ֻ����while�ж��˳���
			while (infiniteMode == true && judgeS == false && judgeH==false)
			{
				setcolor(RGB(c, 0, 0));
				rectangle(INFINITE_PX + 1, MODE_PY + 1, INFINITE_PX + MODE_LENGTH - 2, MODE_PY + MODE_WIDE - 2);
				c -= 4;
				if (c < 0) {
					c = 255;
				}
				Sleep(20);
			}
		}
		else {
			if (judgeH == false) {
				//����Ȧ�е�����ģʽ
				image.infiniteBttom();
				//������ɫ
				c = 225;
			}
			//Ȧ�д���ģʽ��ť
			//û�н�����Ϸ�����û�н�����Ϸ����������ܼ���
			//����д��while�ж����Ϊ������while��ֻ����while�ж��˳���
			while (infiniteMode == false && judgeS == false && judgeH == false)
			{
				setcolor(RGB(c, 0, 0));
				rectangle(LEVEL_MODE_PX + 1, MODE_PY + 1, LEVEL_MODE_PX + MODE_LENGTH - 2, MODE_PY + MODE_WIDE - 2);
				c -= 4;
				if (c < 0) {
					c = 255;
				}
				Sleep(20);
			}
		}
	}
	

	ExitThread(0);			//�ر��̣߳�	
}

void Game::scoreWord()
{
	TCHAR s[10];
	//setcolor(RGB(255, 255, 255));
	settextstyle(35, 0, _T("������κ"));
	setcolor(RGB(85, 255, 255));//��ɫ
	//������ת���TCHAR���ͣ�
	swprintf_s(s, _T("%d"), score);
	outtextxy(750, 150, _T("��ǰ������"));
	setcolor(RGB(255,255,0));
	outtextxy(850, 200, s);
}















