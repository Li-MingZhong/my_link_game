#pragma once
#include "Game.h"
#include <graphics.h>
#define GRID_MAX_ROW	12				//���ڸı��ܵĸ�������GRID_MAX_ROW*GRID_MAX_ROW��;�����˱߽����Ȧ
#define GRID_MAX_COLUMN	10				//���ɸ���������������������ά����ĵڶ���������±꣩
#define MAP_MAX_NUMBER	40				//����ģʽ����ܼ��ص�ͼƬ���� 
#define MAX_LEVEL		13				//����ģʽ������еı���ͼƬ����

class Image:public Game				//����Image��Game������
{
public:
	//Ĭ�ϵĹ��캯����
	Image() : countImage(0), markCount(0), pass(false), gridSize(LEVEL_GRID_SIZE),
		positionX(LEVEL_PX),positionY(LEVEL_PY),level(1)
		 { 	
		//���캯�������鸳ֵΪ0
		for (int i = 0; i < GRID_MAX_ROW; i++) {
			for (int j = 0; j < GRID_MAX_COLUMN; j++) {
				gridAttribute[i][j] = 0;
			}
		}
		//���ü�¼��ͼƬ������Ϊ0
		for (int i = 0; i < MAP_MAX_NUMBER; i++) {
			for (int j = 0; j < 2; j++) {
				imageAttribute[i][j] = 0;
				imageNumber[i][j] = NULL;
			}
		}
	}
	//���صĹ��캯��
	Image( int positionX, int positionY,int gridSize, int row, int column,int maxImageNumber)
		: countImage(0), markCount(0), pass(false),level(1) {
		this->positionX = positionX;
		this->positionY = positionY;
		this->gridSize = gridSize;
		this->mapRow = row;
		this->mapColumn = column;
		this->maxImageNumber = maxImageNumber;
		//���캯�������鸳ֵΪ0
		for (int i = 0; i < GRID_MAX_ROW; i++) {
			for (int j = 0; j < GRID_MAX_COLUMN; j++) {
				gridAttribute[i][j] = 0;
			}
		}
		//���ü�¼��ͼƬ������Ϊ0
		for (int i = 0; i < MAP_MAX_NUMBER; i++) {
			for (int j = 0; j < 2; j++) {
				imageAttribute[i][j] = 0;
				imageNumber[i][j] = NULL;
			}
		}
	}
	~Image();
	//����ͼ��غ���
	void drawMap();							//�������ĸ���ͼ��
	void swapImage();						//����ͼƬ�������ԣ���ֵ��¼����
	bool judgePass();						//�ж��Ƿ��������һ�أ�

	//������غ���
	void gridJudgement(MOUSEMSG mouse);		//����ͼƬ	

	void clearLine();						//������ߵĺ�����
	//�����ж���غ���
	bool judgeClear();						//�ж��Ƿ��ܹ�����ͼƬ��
	void comparePosition();					//�Ƚ������С
	bool oneLine();							//�ж�һ��ֱ�ߣ�0�ۣ��Ƿ����;������л�һ������ֱ��
	bool twoLine();							//�ж�����ֱ�ߣ�1�ۣ��Ƿ����;������л���������ֱ��
	bool thereLine();						//�ж�����ֱ�ߣ�2�ۣ��Ƿ����
	void thereLineLeft(bool & there);		//�ж�����ֱ�ߵ�x��ȣ�ͬ�У�ʱ������ж�
	void thereLineRight(bool & there);		//�ж�����ֱ�ߵ�x��ȣ�ͬ�У�ʱ���ҵ��ж�
	void thereLineUp(bool & there);			//�ж�����ֱ�ߵ�y��ȣ�ͬ�У�ʱ���ϵ��ж�
	void thereLineDown(bool & there);		//�ж�����ֱ�ߵ�y��ȣ�ͬ�У�ʱ���µ��ж�

	//����������ͼƬ����
	void numberImage(int number);			//��ÿһ�����ص�ͼƬһ�����֣��������ѡ��

	void imageVictory();					//ʤ����ͼƬ
	void imageDefeat();						//ʧ�ܵ�ͼƬ��
	void gameStartImage();					//��Ϸ��ʼ���棻
	void finalVictoryImage();				//��Ϸͨ�غ��ͼƬ��
	//���ر���ͼƬ����
	void backGroundImage(int number);		//������ͼһ������
	//���ذ���ͼƬ��
	void imagePause();
	void imageContinue();
	void imageExit();
	void passBottom();									//ͨ�ذ�ť
	void levelBttom();									//����ģʽ��ť
	void infiniteBttom();								//����ģʽ��ť
	bool getClearOne();									//�õ���¼��������Ϣ
	int getLevel();										//�õ���ǰ�ؿ���
	void initMaxImageNumber();							//���ͼƬ������
	void maxImageNumberPlus();							//���ͼƬ����һ
	void levelPlus();									//�ؿ�������
	void initLevel();									//���ùؿ���
private:
	int level;											//��ǰ�ؿ���
	bool clearOne;										//��¼������һ��ͼƬ��
	int maxImageNumber;									//ÿһ�ص����ͼƬ�Ķ���;
	IMAGE imageNumber[MAP_MAX_NUMBER][2];				//ȷ�������ͼƬΪż����
	int countImage;										//��¼�����˶��ٶ�ͼƬ��
	int imageAttribute[MAP_MAX_NUMBER][2];				//��¼���ص�ͼƬ���ԣ�����¼��ͬͼƬ==��ͬ����ֵ��	
	int clickAttribute[2];								//��¼�����ͼƬ������
	//��¼��Ǵ�������Ǵ���=markCount+1���������Ǵ���Ϊ2����ʱmark==1��ʱ���ж�	
	int markCount;							
	bool pass;											//��¼�Ƿ�ͨ���ؿ�
	IMAGE bgImage[MAX_LEVEL];							//��¼ÿһ�صı���ͼ��
	int positionX;										//���ӱ߽����Ͻ�x���ꡣ
	int positionY;										//���ӱ߽����Ͻ�y���ꡣ
	int gridSize;										//���ӣ�����ͼƬ���Ĵ�С
	int mapRow;											//������ͼ������
	int mapColumn;										//������ͼ������

	//��¼����״̬��0��GRID_MAX_ROW��ʾ�߽磬1��GRID_MAX_ROW��ʾͼƬ״̬��
	//��¼ͼƬ���������±�Ϊgrid����Ϊ�����1��ʼ��¼��0��ʾ�߽�λ�ã�
	//gridMaxҲ��ʾ�߽磬�ж�ʱҪ�жϱ߽磻
	int gridAttribute[GRID_MAX_ROW][GRID_MAX_COLUMN];
	int clickX[2];										//��¼���ͼƬ��x����(gridAttribute[6][6])
	int clickY[2];										//��¼���ͼƬ��y����(gridAttribute[6][6])
	int minClickX;										//��¼�����������x�Ľ�Сֵ
	int minClickY;										//��¼�����������y�Ľ�Сֵ
	int maxClickX;										//��¼�����������x�Ľϴ�ֵ
	int maxClickY;										//��¼�����������y�Ľϴ�ֵ	
};

