#pragma once
//����ģʽ����
#define LEVEL_GRID_SIZE		64			//����ģʽ���ӵĴ�С
#define LEVEL_ROW			6			//����ģʽ����
#define LEVEL_COLUMN		6			//����ģʽ����
#define INIT_LEVEL_TIME		33			//�ʼ�ĵ�һ�ص���Ϸʱ��
#define LEVEL_PX			36			//����ģʽ�������Ͻ�x����
#define LEVEL_PY			0			//����ģʽ�������Ͻ�y����
#define INITo_IMAGE_NUMBER	6			//����ģʽ��һ�ص�ͼƬ������
#define MAX_LEVEL			13			//����ģʽ���ؿ���
//����ģʽ����
#define INFI_TIME			110			//����ģʽ��ʱ��
#define INFI_GRID_SIZE		58			//����ģʽ���ӵĴ�С
#define INFI_ROW			10			//����ģʽ����
#define INFI_COLUMN			 8			//����ģʽ����
#define INFI_PX				36			//����ģʽ�������Ͻ�x����
#define INFI_PY				-21			//����ģʽ�������Ͻ�y����
#define INFI_IMAGE_NUMBER	16			//����ģʽͼƬ������
class Game
{
public:
	Game() :WINDOW_WIDE(1000), WINDOW_HEIGTH(540),levelTime(INIT_LEVEL_TIME), lastMoment(levelTime),
		gameTimePlus(3),PAUSE_PX(850), PAUSE_PY(400), PAUSE_SIZE(60), EXIT_PX(915), EXIT_PY(415), 
		EXIT_SIZE(45), PASS_LEFT_PX(450), PASS_LEFT_PY(200), PASS_RIGHT_PX(550),PASS_RIGHT_PY(290),
		countPassB(0),PASS_BOTTOM_SIZE(50),MODE_PY(359),INFINITE_PX(325),LEVEL_MODE_PX(530),MODE_LENGTH(180),
		MODE_WIDE(41),score(0),scorePlus(10){};
	//�Զ���Ĭ�Ϲ��캯��
	~Game();

	void controller();									//������Ϸѭ��
	void window();										//����һ��ͼ�񴰿ڲ���ע�Լ�������
	bool judgeStart(MOUSEMSG mouse);					//�ж��Ƿ�������Ϸ��ʼ��ť
	void gameHelp(MOUSEMSG mouse);						//�ж��Ƿ�������Ϸ������ť�ͽ�����Ϸ��������
	void gameTime();									//�ж���Ϸʱ��
	void gameVictory(int level);						//��Ϸʤ��ʱ��������ͨ�أ��ļ���
	void gameDefeat();									//��Ϸʧ��ʱ�ļ���
	void levelWord(int level);							//��Ϸ��ǰ�ؿ��֣�
	bool judgePause(MOUSEMSG mouse);					//�ж��Ƿ�������Ϸ��ͣ��ť
	bool judgeExit(MOUSEMSG mouse);						//�ж��Ƿ�������Ϸ���¿�ʼ��ť
	void startPassMode(MOUSEMSG mouse);					//�ж��Ƿ�����ͨ�ذ�ť������ͨ�ذ�ť��
	bool judgePassBottom(MOUSEMSG mouse);				//�ж��Ƿ�����ͨ�ذ�ť��
	bool judgeMode(MOUSEMSG mouse);						//�жϵ����ģʽ��falseΪ����ģʽ��trueΪ����ģʽ��
	void modeBottom();									//Ȧ��ѡ�е�ģʽ��ť
	void scoreWord();									//��������ģʽ��Ϸ����
protected:

	const int WINDOW_WIDE;								//��ʾ��Ļ�Ŀ��
	const int WINDOW_HEIGTH;							//��ʾ��Ļ�ĳ���
	const int PAUSE_PX;									//��ͣ��ť���Ͻǵ�x����
	const int PAUSE_PY;									//��ͣ��ť���Ͻǵ�y����
	const int PAUSE_SIZE;								//��ͣ��ť�ĳ��ȣ�
	const int EXIT_PX;									//�˳���ʼ����Ϸ��ť���Ͻǵ�x����
	const int EXIT_PY;									//�˳���ʼ����Ϸ��ť���Ͻǵ�y����
	const int EXIT_SIZE;								//�˳���ʼ����Ϸ��ť�ĳ��ȣ�
	const int PASS_BOTTOM_SIZE;							//ͨ�ذ�ť�Ĵ�С��
	const int INFINITE_PX;								//����ģʽ��ť���Ͻ�x����
	const int MODE_PY;									//ģʽ��ť��y����
	const int LEVEL_MODE_PX;							//����ģʽ��ť���Ͻ�x���ꣻ
	const int MODE_LENGTH;								//ģʽ��ť�ĳ��ȣ�
	const int MODE_WIDE;								//ģʽ��ť�Ŀ�ȣ�

	static MOUSEMSG mouse;								//����һ����̬�ļ�¼���ı�����
	static	bool infiniteMode; 							//��¼�Ƿ���������ģʽ��
private:
	int second;											//������¼startTime��stopTime֮��ļ����
	int levelTime;										//������¼ÿһ�ص���Ϸʱ��
	int lastMoment;										//���ʱ�̣�������¼��ʣ�����ʱ��
	 int gameTimePlus;									//�ؿ�ģʽÿͨ��һ�أ���������ģʽ����һ��ͼƬ�����ӵ�ʱ�䣻
	bool judgeP=false;									//�ж��Ƿ�������ͣ��trueΪ��Ϸ��ͣ��falseΪ��Ϸ������
	bool judgeE=false;									//�ж��Ƿ�����exit��ť��
	const int PASS_LEFT_PX;								//����ͨ�ذ�ť���Ͻǵ�x����
	const int PASS_LEFT_PY;								//����ͨ�ذ�ť���Ͻǵ�y����
	const int PASS_RIGHT_PX;							//����ͨ�ذ�ť���½ǵ�x����
	const int PASS_RIGHT_PY;							//����ͨ�ذ�ť���½ǵ�y����
	bool judgePassB=false;								//��¼�Ƿ�����ͨ�ذ�ť��
	int countPassB;										//��¼�������ͨ�ذ�ť�Ĵ�����
	bool judgePb=false;									//�Ƿ�����ͨ�ذ�ť��
	bool judgeS=false;									//��¼�Ƿ����˿�ʼ��ť��
	bool judgeH = false;								//��¼�Ƿ����˰�����ť��
	int score;											//��¼�õ��ķ���
	const int scorePlus;								//����һ�����ӵ�ʱ��
};

