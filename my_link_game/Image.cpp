#include "pch.h"
#include "Image.h"
#include <time.h>
#pragma comment(lib,"Winmm.lib")
#include <thread>
#include <iostream>
#include "Music.h"


Image::~Image()
{
}

void Image::drawMap()
{
	//���ü�¼
	markCount = 0;
	//ÿ�ο�ʼʱcoutImageҪ���¸�ֵΪ0����Ȼ������Խ��
	countImage = 0;

	//�������ͼƬ����������ǰͼƬ����
	/*if (infiniteMode == false) {
		maxImageNumber = INITo_IMAGE_NUMBER + level - 1;
	}
	else {
		maxImageNumber = INFI_IMAGE_NUMBER;
	}*/
	
	backGroundImage(level);
	putimage(0, 0, &bgImage[level-1]);
			

	srand((unsigned)time(NULL));	//�õ�ǰʱ�������������

	BeginBatchDraw();	//��ʼ������ͼģʽ��
	int m=0;
	for (int n = 1; n <= mapRow * mapColumn/2; n++) {	
		//��n��m����ֹ���������ʱnһֱ��[1,maxImageNumber]֮�䣬�Ӷ�������ѭ����
		m = n;
		//���ÿ��ͼƬ���ظ�2�μ������ϣ��ͱ����ظ����Σ�
		if ( m>maxImageNumber && m<=maxImageNumber*2) {
			m %= maxImageNumber;
			//��mȡ��==0��ʵ��Ӧ����maxImageNumer��
			if (m == 0) {
				m = maxImageNumber;
			}
		}
		else if (m > maxImageNumber * 2) {
			m = rand() % maxImageNumber + 1;//����1��maxImageNumber���������
		}
		Image::numberImage(m);
	}
	
	swapImage();		//����λ�ã��γ�������ã�
	
	m = 0;
	int n = -1;
	for (int i = 1; i <= mapRow; i++) {
		for (int j = 1; j <= mapColumn; j++) {
			if (m %2==0) {
				m = 0;
				n++;
			} else {
				m = 1;
			}
			putimage(positionX + i * gridSize, positionY + j * gridSize, &imageNumber[n][m]);
			gridAttribute[i][j] = imageAttribute[n][m];
			m++;
		}
	}
	
	//������ͣ���˳���ť��
	imagePause();
	imageExit();

	FlushBatchDraw(); 
	EndBatchDraw();// �����������ƣ���ִ��δ��ɵĻ�������;������batchDraw������Ļ�ͼ��������ִ��	

}

void Image::numberImage(int number)
{
	switch (number)
	{
	case 1: {
		//��������ͼƬ��ͼƬ����ֵΪ1;
		for (int i = 0; i < 2; i++) {
			loadimage(&imageNumber[countImage][i], _T("PNG"), _T("����"), gridSize, gridSize);
			imageAttribute[countImage][i] = 1;
		}
		countImage++;
		break;
	}
	case 2: {
		//����槼���ͼƬ��ͼƬ����ֵΪ2��
		for (int i = 0; i < 2; i++) {
			loadimage(&imageNumber[countImage][i], _T("PNG"), _T("槼�"), gridSize, gridSize);
			imageAttribute[countImage][i] = 2;
		}
		countImage++;
		break;
	}
	case 3: {
		//���뺫�ŵ�ͼƬ��ͼƬ����ֵΪ3��
		for (int i = 0; i < 2; i++) {
			loadimage(&imageNumber[countImage][i], _T("IMAGE"), _T("����"), gridSize, gridSize);
			imageAttribute[countImage][i] = 3;
		}
		countImage++;
		break;
	}
	case 4: {
		//���밲������ͼƬ��ͼƬ����ֵΪ4��
		for (int i = 0; i < 2; i++) {
			loadimage(&imageNumber[countImage][i], _T("PNG"), _T("������"), gridSize, gridSize);
			imageAttribute[countImage][i] = 4;
		}
		countImage++;
		break;
	}
	case 5: {
		//���뿭��ͼƬ��ͼƬ����ֵΪ5��
		for (int i = 0; i < 2; i++) {
			loadimage(&imageNumber[countImage][i], _T("IMAGE"), _T("��"), gridSize, gridSize);
			imageAttribute[countImage][i] = 5;
		}
		countImage++;
		break;
	}
	case 6: {
		//�������Ѿ���ͼƬ��ͼƬ����ֵΪ6
		for (int i = 0; i < 2; i++) {
			loadimage(&imageNumber[countImage][i], _T("IMAGE"), _T("���Ѿ�"), gridSize, gridSize);
			imageAttribute[countImage][i] = 6;
		}
		countImage++;
		break;
	}
	case 7: {
		//������ɪ��ͼƬ��ͼƬ����ֵΪ7��
		for (int i = 0; i < 2; i++) {
			loadimage(&imageNumber[countImage][i], _T("IMAGE"), _T("��ɪ"), gridSize, gridSize);
			imageAttribute[countImage][i] = 7;
		}
		countImage++;
		break;
	}
	case 8: {
		//����������ͼƬ��ͼƬ����ֵΪ8��
		for (int i = 0; i < 2; i++) {
			loadimage(&imageNumber[countImage][i], _T("PNG"), _T("����"), gridSize, gridSize);
			imageAttribute[countImage][i] = 8;
		}
		countImage++;
		break;
	}
	case 9: {
		//������׵�ͼƬ��ͼƬ����ֵΪ9��
		for (int i = 0; i < 2; i++) {
			loadimage(&imageNumber[countImage][i], _T("PNG"), _T("���"), gridSize, gridSize);
			imageAttribute[countImage][i] = 9;
		}
		countImage++;
		break;
	}
	case 10: {
		//���뻨ľ����ͼƬ��ͼƬ����ֵΪ10;
		for (int i = 0; i < 2; i++) {
			loadimage(&imageNumber[countImage][i], _T("IMAGE"), _T("��ľ��"), gridSize, gridSize);
			imageAttribute[countImage][i] = 10;
			//��ľ��ͼƬΪjpg������png��ע��ͼƬ��ʽ��
		}
		countImage++;
		break;
	}
	case 11: {
		//������ʽܵ�ͼƬ��ͼƬ����ֵΪ11��
		for (int i = 0; i < 2; i++) {
			loadimage(&imageNumber[countImage][i], _T("PNG"), _T("���ʽ�"), gridSize, gridSize);
			imageAttribute[countImage][i] = 11;
		}
		countImage++;
		break;
	}
	case 12: {
		//���밢���ͼƬ��ͼƬ����ֵΪ12��
		for (int i = 0; i < 2; i++) {
			loadimage(&imageNumber[countImage][i], _T("IMAGE"), _T("����"), gridSize, gridSize);
			imageAttribute[countImage][i] = 12;
		}
		countImage++;
		break;
	}
	case 13: {
		//����Ĺ������ͼƬ��ͼƬ����ֵΪ13��
		for (int i = 0; i < 2; i++) {
			loadimage(&imageNumber[countImage][i], _T("PNG"), _T("�������"), gridSize, gridSize);
			imageAttribute[countImage][i] = 13;
		}
		countImage++;
		break;
	}
	case 14: {
		//�����С��ͼƬ��ͼƬ����ֵΪ14��
		for (int i = 0; i < 2; i++) {
			loadimage(&imageNumber[countImage][i], _T("PNG"), _T("С��"), gridSize, gridSize);
			imageAttribute[countImage][i] = 14;
		}
		countImage++;
		break;
	}
	case 15: {
		//���������ͼƬ��ͼƬ����ֵΪ15��
		for (int i = 0; i < 2; i++) {
			loadimage(&imageNumber[countImage][i], _T("PNG"), _T("����"), gridSize, gridSize);
			imageAttribute[countImage][i] = 15;
		}
		countImage++;
		break;
	}
	case 16: {
		//����Ĳ��ļ�ͼƬ��ͼƬ����ֵΪ16��
		for (int i = 0; i < 2; i++) {
			loadimage(&imageNumber[countImage][i], _T("PNG"), _T("���ļ�"), gridSize, gridSize);
			imageAttribute[countImage][i] = 16;
		}
		countImage++;
		break;
	}
	case 17: {
		//���������ͼƬ��ͼƬ����ֵΪ17��
		for (int i = 0; i < 2; i++) {
			loadimage(&imageNumber[countImage][i], _T("PNG"), _T("����"), gridSize, gridSize);
			imageAttribute[countImage][i] = 17;
		}
		countImage++;
		break;
	}
	case 18: {
		//������ŵ���ͼƬ��ͼƬ����ֵΪ18��
			//�ŵ���ͼƬ��ʽ����ΪIMAGE�ˣ�����PNG��
		for (int i = 0; i < 2; i++) {
			loadimage(&imageNumber[countImage][i], _T("IMAGE"), _T("�ŵ���"), gridSize, gridSize);
			imageAttribute[countImage][i] = 18;
		}
		countImage++;
		break;
	}
	}
}

void Image::swapImage()
{
	int  x;
	int  t;
	IMAGE img;

	//��0��mapRow * mapColumn/4-1��mapRow * mapColumn/2-mapRow * mapColumn/4-1��ͼƬ�ཻ��ʵ����󻯽���
	for (int j = 0; j < mapRow*mapColumn / 2; j++) {
		//x��Ҫ��һ��ӦΪ�����0��ʼ����������±�Ӧ��ΪmapRow * mapColumn /2-1
		x = mapRow * mapColumn / 2 - j-1;
		img = imageNumber[j][0];
		imageNumber[j][0] = imageNumber[x][0];
		imageNumber[x][0] = img;
		t = imageAttribute[j][0];
		imageAttribute[j][0] = imageAttribute[x][0];
		imageAttribute[x][0] = t;
	}

	//�������Σ�
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {//imageNumber[j][i]��0,1������һ��	 
			//��0��mapRow*mapColumn-1�����������ͼƬ�ཻ��ʵ����󻯽���
			for (int k = 0; k < mapRow*mapColumn / 2; k++) {
				//x����[0,mapRow*mapColumn-1]
				x = rand() % (mapRow*mapColumn / 2);
				img = imageNumber[k][j];
				imageNumber[k][j] = imageNumber[x][j];
				imageNumber[x][j] = img;
				t = imageAttribute[k][j];
				imageAttribute[k][j] = imageAttribute[x][j];
				imageAttribute[x][j] = t;
			}
		}
	}
}

//������ߵĺ�����
void Image::clearLine()
{
//	backGroundImage(level);//����Ҫ����һ�Σ���Ȼ��û����������
	for (int x = 0; x < mapRow + 2; x++) {
		for (int y = 0; y < mapColumn + 2; y++) {
			if ((gridAttribute[x][y] == 0)) {
				putimage(positionX + gridSize * x, positionY + gridSize * y,
					gridSize, gridSize, &bgImage[level - 1], positionX + gridSize * x,
					positionY + gridSize * y);
			}
		}
	}
}

bool Image::judgeClear()
{
	//����������ɫ�ʹ�ϸ
	setlinecolor(RGB(255, 128, 0));
	setlinestyle(PS_SOLID, 5);
	//�Ƚϴ�С�����ж�
	comparePosition();

	bool judge = false;
	judge = oneLine();
	if (judge == false) {
		judge = twoLine();
		if (judge == false) {
			judge = thereLine();
		}
	}
	return judge;
}

void Image::comparePosition()
{
	if (Image::clickX[0] > Image::clickX[1]) {//�ж�x�����С
		minClickX = Image::clickX[1];
		maxClickX = Image::clickX[0];
	}
	else {//���������
		minClickX = Image::clickX[0];
		maxClickX = Image::clickX[1];
	}
	if (Image::clickY[0] > Image::clickY[1]) {//�ж�y�����С
		minClickY = Image::clickY[1];
		maxClickY = Image::clickY[0];
	}
	else {//���������
		minClickY = Image::clickY[0];
		maxClickY = Image::clickY[1];
	}
}

bool Image::oneLine()
{
	bool one = false;
	if (clickX[0] == clickX[1]) {
		one = true;
		if (maxClickY - minClickY > 1) {//�త�ŵ�ֱ��Ϊ��
			for (int y = minClickY + 1; maxClickY > y; y++) {
				//����һ�������ĳ�ʼֵҪ�����ʹ�ã�������ѭ���ڶ���һ��ѭ��������֮��ȣ�
				//���ٻָ���ʼֵ�Ĳ��裻
				if (gridAttribute[minClickX][y] != 0) {//��=0��ʾ֮����ͼƬ���
					one = false;
					break;
				}
			}
		}
		if (one == true) {//����������
			line(positionX + clickX[0] * gridSize + gridSize / 2, positionY + minClickY * gridSize + gridSize / 2,
				positionX + clickX[0] * gridSize + gridSize / 2, positionY + maxClickY * gridSize + gridSize / 2);
		}
	}

	if (clickY[0] == clickY[1]) {
		one = true;
		if (maxClickX - minClickX > 1) {
			for (int x = minClickX + 1; maxClickX > x; x++) {
				if (gridAttribute[x][minClickY] != 0) {
					one = false;
					break;
				}
			}
		}
		if (one) {//����������;�жϷ�������ִ�У������һ���жϳɹ�Ҳ��ִ��
			line(positionX + minClickX * gridSize + gridSize / 2, positionY + clickY[0] * gridSize + gridSize / 2,
				positionX + maxClickX * gridSize + gridSize / 2, positionY + clickY[0] * gridSize + gridSize / 2);

		}
	}
	return one;
}

bool Image::twoLine()
{
	bool two = false;//��ʼΪ�٣������жϿ�ʼΪ�棻��ֹ�������ж�������Ĭ��Ϊ��

	if ((clickX[0] > clickX[1] && clickY[0] > clickY[1]) || (clickX[0] < clickX[1] && clickY[0] < clickY[1])) {
		//��һ�����ݺ͵ڶ������鹹�����ϡ����µĹ�ϵ��
		two = true;
		for (int x = minClickX + 1; x <= maxClickX; x++) {//��һ���жϣ������Ͻǿ�ʼ���к���
			//+1��ֹ�жϱ���
			if (gridAttribute[x][minClickY] != 0) {
				two = false;
				break;
			}
		}
		if (two == true) {//Ϊ���ִ�У���ֹ©����һ�ε��жϣ�
			for (int y = minClickY + 1; y < maxClickY; y++) {
				//+1����ѭ��������
				if (gridAttribute[maxClickX][y] != 0) {
					two = false;
					break;
				}
			}
		}
		if (two == true) {
			//����
			line(positionX + minClickX * gridSize + gridSize / 2, positionY + minClickY * gridSize + gridSize / 2,
				positionX + maxClickX * gridSize + gridSize / 2, positionY + minClickY * gridSize + gridSize / 2);
			//����
			line(positionX + maxClickX * gridSize + gridSize / 2, positionY + minClickY * gridSize + gridSize / 2,
				positionX + maxClickX * gridSize + gridSize / 2, positionY + maxClickY * gridSize + gridSize / 2);

		}
		else {//��һ�β��ɹ������ߵڶ����жϣ������жϻ��������ߣ�����ֻҪ�ڶ������ɹ����ж�false
			two = true;
			for (int y = minClickY + 1; y <= maxClickY; y++) {//�ڶ����жϣ������Ͻǿ�ʼ���к���
				if (gridAttribute[minClickX][y] != 0) {
					two = false;
					break;
				}
			}
			if (two == true) {
				for (int x = minClickX + 1; x < maxClickX; x++) {
					if (gridAttribute[x][maxClickY] != 0) {
						two = false;
						break;
					}
				}
			}
			if (two == true) {
				//����
				line(positionX + minClickX * gridSize + gridSize / 2, positionY + maxClickY * gridSize + gridSize / 2,
					positionX + maxClickX * gridSize + gridSize / 2, positionY + maxClickY * gridSize + gridSize / 2);
				//����
				line(positionX + minClickX * gridSize + gridSize / 2, positionY + minClickY * gridSize + gridSize / 2,
					positionX + minClickX * gridSize + gridSize / 2, positionY + maxClickY * gridSize + gridSize / 2);

			}
		}
	}
	if ((clickX[0]<clickX[1] && clickY[0]>clickY[1]) || (clickX[0] > clickX[1] && clickY[0] < clickY[1])) {
		//��һ��͵ڶ��鹹�����¡����ϵĹ�ϵ��true
		two = true;
		for (int x = minClickX + 1; x <= maxClickX; x++) {//��һ���жϣ������½ǿ�ʼ���к���
			//+1��ֹ�жϱ���
			if (gridAttribute[x][maxClickY] != 0) {
				two = false;
				break;
			}
		}
		if (two == true) {
			for (int y = maxClickY - 1; y > minClickY; y--) {
				//-1����ѭ��������
				if (gridAttribute[maxClickX][y] != 0) {
					two = false;
					break;
				}
			}
		}
		if (two == true) {
			//����
			line(positionX + minClickX * gridSize + gridSize / 2, positionY + maxClickY * gridSize + gridSize / 2,
				positionX + maxClickX * gridSize + gridSize / 2, positionY + maxClickY * gridSize + gridSize / 2);
			//����
			line(positionX + maxClickX * gridSize + gridSize / 2, positionY + maxClickY * gridSize + gridSize / 2,
				positionX + maxClickX * gridSize + gridSize / 2, positionY + minClickY * gridSize + gridSize / 2);

		}
		else {//��һ�β��ɹ������ߵڶ����жϣ������жϻ��������ߣ�����ֻҪ�ڶ������ɹ����ж�false	
			two = true;//���棬��ʼ�жϣ�
			for (int y = maxClickY - 1; y >= minClickY; y--) {//�ڶ����жϣ������½ǿ�ʼ���к���
				if (gridAttribute[minClickX][y] != 0) {
					two = false;
					break;
				}
			}
			if (two == true) {
				for (int x = minClickX + 1; x < maxClickX; x++) {
					if (gridAttribute[x][minClickY] != 0) {
						two = false;
						break;
					}
				}
			}
			if (two == true) {//��Щһ��=�Ű���������ע�Ⱑ���ж����Ϊ==�������ȺŰ�!!)
				//����
				line(positionX + minClickX * gridSize + gridSize / 2, positionY + maxClickY * gridSize + gridSize / 2,
					positionX + minClickX * gridSize + gridSize / 2, positionY + minClickY * gridSize + gridSize / 2);
				//����
				line(positionX + minClickX * gridSize + gridSize / 2, positionY + minClickY * gridSize + gridSize / 2,
					positionX + maxClickX * gridSize + gridSize / 2, positionY + minClickY * gridSize + gridSize / 2);
			}

		}
	}
	return two;
}

bool Image::thereLine()
{
	bool there = false;
	if (clickX[0] == clickX[1]) {//ͬ��λ��;�ж�Ҫ==����ע��
		thereLineLeft(there);//������,"["��״	
		if (there == false) {
			thereLineRight(there);//������;"]"��״
		}
	}
	if (clickY[0] == clickY[1]) {//ͬ��
		thereLineUp(there);//������;"��"��״
		if (there == false) {
			thereLineDown(there);//������;"��"��״
		}
	}
	if ((clickX[0] > clickX[1] && clickY[0] > clickY[1]) || (clickX[0] < clickX[1] && clickY[0] < clickY[1])) {
		//��һ�����ݺ͵ڶ������鹹�����ϡ����µĹ�ϵ��

		//�ȿ�ʼ�������ڽ����ж�
		//���Ͻ��ȴ������������� "����__"��
		for (int x = minClickX + 1; x < maxClickX; x++) {//����
			//���ð�������X����ΪtwoLine�����Ѿ��жϹ���
			there = true;//ÿ��ѭ����ʼ��ҪΪ��
			if (gridAttribute[x][minClickY] != 0) {
				there = false;
				break;
			}
			for (int y = minClickY + 1; y <= maxClickY; y++) {//����
				if (gridAttribute[x][y] != 0) {
					there = false;
					break;
				}
			}
			if (there == true) {//Ϊ��ſ�ʼ����֤��ȷ
				for (int x1 = x; x1 < maxClickX; x1++) {//���У�������x���꿪ʼ�ж�;
					//�㷨�Ĵ���ʵ�֣���Ȼ������������ƣ�����ͬ�Ļ�����û����Լ��ִ����
					//����ճ������һЩ�ط�û�Ĺ�������������д�����ʱ�仹Ҫ��
					//����+1���ٲ��裻��һ�м�ֻ����һ����GG��
					if (gridAttribute[x1][maxClickY] != 0) {
						there = false;
						break;
					}
				}
			}
			if (there == true) {
				//����
				line(positionX + minClickX * gridSize + gridSize / 2, positionY + minClickY * gridSize + gridSize / 2,
					positionX + x * gridSize + gridSize / 2, positionY + minClickY * gridSize + gridSize / 2);
				line(positionX + x * gridSize + gridSize / 2, positionY + minClickY * gridSize + gridSize / 2,
					positionX + x * gridSize + gridSize / 2, positionY + maxClickY * gridSize + gridSize / 2);
				line(positionX + x * gridSize + gridSize / 2, positionY + maxClickY * gridSize + gridSize / 2,
					positionX + maxClickX * gridSize + gridSize / 2, positionY + maxClickY * gridSize + gridSize / 2);
				//��¼

				break;//һ�γɹ�������
			}
		}
		if (there == false) {//���Ͻ��ȴ������������� "����"��
			for (int y = minClickY + 1; y < maxClickY; y++) {//����
				there = true;//ÿ��ѭ����ʼ��ҪΪ��
				if (gridAttribute[minClickX][y] != 0) {
					there = false;
					break;
				}
				for (int x = minClickX + 1; x <= maxClickX; x++) {//����
					if (gridAttribute[x][y] != 0) {
						there = false;
						break;
					}
				}
				if (there == true) {//Ϊ��ſ�ʼ����֤��ȷ
					for (int y1 = y; y1 < maxClickY; y1++) {//���У�������y���꿪ʼ�ж�
						if (gridAttribute[maxClickX][y1] != 0) {
							there = false;
							break;
						}
					}
				}
				if (there == true) {
					//����
					line(positionX + minClickX * gridSize + gridSize / 2, positionY + minClickY * gridSize + gridSize / 2,
						positionX + minClickX * gridSize + gridSize / 2, positionY + y * gridSize + gridSize / 2);
					line(positionX + minClickX * gridSize + gridSize / 2, positionY + y * gridSize + gridSize / 2,
						positionX + maxClickX * gridSize + gridSize / 2, positionY + y * gridSize + gridSize / 2);
					line(positionX + maxClickX * gridSize + gridSize / 2, positionY + y * gridSize + gridSize / 2,
						positionX + maxClickX * gridSize + gridSize / 2, positionY + maxClickY * gridSize + gridSize / 2);
					//��¼

					break;//һ�γɹ�������
				}
			}
		}
		//��ʼ������������жϣ�
		if (there == false) {
			there = true;
			for (int x = maxClickX - 1; x >= minClickX; x--) {//���½������ߵ�ͬ��
				//�ж�x�������x��С֮���Ƿ��ǿյ�
				if (gridAttribute[x][maxClickY] != 0) {
					there = false;
					break;//��ͼ�Ͳ���
				}
			}
			if (there == true) {//��������һ��=������==���жϣ���������������
				thereLineLeft(there);//ͬ�м���������,"["��״
			}
		}

		if (there == false) {
			there = true;
			for (int x = minClickX + 1; x <= maxClickX; x++) {//���Ͻ������ߵ�ͬ��
			//�ж�x�������x��С֮���Ƿ��ǿյ�
				if (gridAttribute[x][minClickY] != 0) {
					there = false;
					break;//��ͼ�Ͳ���
				}
			}
			if (there == true) {
				thereLineRight(there);//ͬ�м���������;"]"��״
			}
		}

		if (there == false) {
			there = true;//�������ˣ�ÿ�ν����ж�Ҫ��ֵΪtrue!!!!!!
			for (int y = maxClickY - 1; y >= minClickY; y--) {//���½������ߵ�ͬ��
				if (gridAttribute[maxClickX][y] != 0) {
					there = false;
					break;
				}
			}
			if (there == true) {
				thereLineUp(there);//ͬ�м���������;"��"��״
			}
		}

		if (there == false) {//���Ͻ������ߵ�ͬ��
			there = true;//�������ˣ�ÿ�ν����ж�Ҫ��ֵΪtrue!!!!!!
			for (int y = minClickY + 1; y <= maxClickY; y++) {
				if (gridAttribute[minClickX][y] != 0) {
					there = false;
					break;
				}
			}
			if (there == true) {
				thereLineDown(there);//������;"��"��״
			}
		}
	}
	if ((clickX[0]<clickX[1] && clickY[0]>clickY[1]) || (clickX[0] > clickX[1] && clickY[0] < clickY[1])) {
		//��һ��͵ڶ��鹹�����¡����ϵĹ�ϵ��

		//��ʼ�������ڽ����ж�
		//���½��ȴ������������� "__����"��
		for (int x = minClickX + 1; x < maxClickX; x++) {//����
			there = true;//ÿ��ѭ����ʼ��ҪΪ��
			if (gridAttribute[x][maxClickY] != 0) {
				there = false;
				break;
			}
			for (int y = maxClickY - 1; y >= minClickY; y--) {//����
				if (gridAttribute[x][y] != 0) {
					there = false;
					break;
				}
			}
			if (there == true) {//Ϊ��ſ�ʼ����֤��ȷ
				for (int x1 = x; x1 < maxClickX; x1++) {//���У�������x���꿪ʼ�ж�
					if (gridAttribute[x1][minClickY] != 0) {
						there = false;
						break;
					}
				}
			}
			if (there == true) {
				//����
				line(positionX + minClickX * gridSize + gridSize / 2, positionY + maxClickY * gridSize + gridSize / 2,
					positionX + x * gridSize + gridSize / 2, positionY + maxClickY * gridSize + gridSize / 2);
				line(positionX + x * gridSize + gridSize / 2, positionY + maxClickY * gridSize + gridSize / 2,
					positionX + x * gridSize + gridSize / 2, positionY + minClickY * gridSize + gridSize / 2);
				line(positionX + x * gridSize + gridSize / 2, positionY + minClickY * gridSize + gridSize / 2,
					positionX + maxClickX * gridSize + gridSize / 2, positionY + minClickY * gridSize + gridSize / 2);
				//��¼

				break;//һ�γɹ�������
			}
		}
		if (there == false) {//���½��ȴ������������У�"����"��
			for (int y = maxClickY - 1; y > minClickY; y--) {//����,twoLine�ж�ʧ�ܣ����νǿ϶����ܹ�
				there = true;//ÿ��ѭ����ʼ��ҪΪ��
				if (gridAttribute[minClickX][y] != 0) {
					there = false;
					break;
				}
				for (int x = minClickX + 1; x <= maxClickX; x++) {//����
					if (gridAttribute[x][y] != 0) {
						there = false;
						break;
					}
				}
				if (there == true) {//Ϊ��ſ�ʼ����֤��ȷ
					for (int y1 = y; y1 > minClickY; y1--) {//���У�������y���꿪ʼ�ж�
						if (gridAttribute[maxClickX][y1] != 0) {
							there = false;
							break;
						}
					}
				}
				if (there == true) {
					//����
					line(positionX + minClickX * gridSize + gridSize / 2, positionY + maxClickY * gridSize + gridSize / 2,
						positionX + minClickX * gridSize + gridSize / 2, positionY + y * gridSize + gridSize / 2);
					line(positionX + minClickX * gridSize + gridSize / 2, positionY + y * gridSize + gridSize / 2,
						positionX + maxClickX * gridSize + gridSize / 2, positionY + y * gridSize + gridSize / 2);
					line(positionX + maxClickX * gridSize + gridSize / 2, positionY + y * gridSize + gridSize / 2,
						positionX + maxClickX * gridSize + gridSize / 2, positionY + minClickY * gridSize + gridSize / 2);
					//��¼

					break;//һ�γɹ�������
				}
			}

		}

		//��ʼ������������жϣ�
		if (there == false) {
			there = true;
			for (int x = maxClickX - 1; x >= minClickX; x--) {//���Ͻ������ߵ�ͬ��
				if (gridAttribute[x][minClickY] != 0) {
					there = false;
					break;
				}
			}
			if (there == true) {
				thereLineLeft(there);//ͬ�м���������,"["��״
			}
		}
		if (there == false) {
			there = true;//�������ˣ�ÿ�ν����ж�Ҫ��ֵΪtrue!!!!!!
			for (int x = minClickX + 1; x <= maxClickX; x++) {//�����ߵ�ͬ��
				if (gridAttribute[x][maxClickY] != 0) {
					there = false;
					break;
				}
			}
			if (there == true) {
				thereLineRight(there);//ͬ�м���������;"]"��״
			}
		}
		if (there == false) {
			there = true;//�������ˣ�ÿ�ν����ж�Ҫ��ֵΪtrue!!!!!!
			for (int y = maxClickY - 1; y >= minClickY; y--) {//�����ߵ�ͬ��
				if (gridAttribute[minClickX][y] != 0) {
					there = false;
					break;
				}
			}
			if (there == true) {
				thereLineUp(there);//ͬ�м���������;"��"��״
			}
		}
		if (there == false) {
			there = true;//�������ˣ�ÿ�ν����ж�Ҫ��ֵΪtrue!!!!!!
			for (int y = minClickY + 1; y <= maxClickY; y++) {//�����ߵ�ͬ��
				if (gridAttribute[maxClickX][y] != 0) {
					there = false;
					break;
				}
			}
			if (there == true) {
				thereLineDown(there);//������;"��"��״
			}
		}
	}
	return there;
}

void Image::thereLineLeft(bool & there)
{
	for (int x = minClickX - 1; x >= 0; x--) {//������,"["��״
		there = true;
		if (gridAttribute[x][minClickY] != 0 || gridAttribute[x][maxClickY] != 0) {
			//����ֻҪ��һ����ͼ����Ϊfalse��������������&&
			there = false;
			break;//����Ĳ��У��ؾ�֮·��������Ŀ϶�����
		}
		for (int y = minClickY + 1; y < maxClickY; y++) {
			if (gridAttribute[x][y] != 0) {
				there = false;
				break;
			}
		}
		if (there == true) {//������һ��ͨ·����,�ɹ�����ͨ·������Ϊx
			//���ߣ��̶�һ���click���굽x�������ߺ�x��ͨ·������
			line(positionX + clickX[0] * gridSize + gridSize / 2, positionY + gridSize * clickY[0] + gridSize / 2,
				positionX + x * gridSize + gridSize / 2, positionY + gridSize * clickY[0] + gridSize / 2);
			line(positionX + x * gridSize + gridSize / 2, positionY + gridSize * clickY[0] + gridSize / 2,
				positionX + x * gridSize + gridSize / 2, positionY + gridSize * clickY[1] + gridSize / 2);
			line(positionX + x * gridSize + gridSize / 2, positionY + gridSize * clickY[1] + gridSize / 2,
				positionX + clickX[1] * gridSize + gridSize / 2, positionY + gridSize * clickY[1] + gridSize / 2);


			break;
		}
	}
}



void Image::thereLineRight(bool &there)
{
	for (int x = maxClickX + 1; x < mapRow + 2; x++) {//������;"]"��״��0��mapRow+1������mapRow+2��
		there = true;
		if (gridAttribute[x][minClickY] != 0 || gridAttribute[x][maxClickY] != 0) {
			there = false;
			break;
		}
		for (int y = minClickY + 1; y < maxClickY; y++) {
			if (gridAttribute[x][y] != 0) {
				there = false;
				break;
			}
		}
		if (there == true) {//������һ��ͨ·����
			//���ߣ��̶�һ���click���굽x�������ߺ�x��ͨ·������
			line(positionX + clickX[0] * gridSize + gridSize / 2, positionY + gridSize * clickY[0] + gridSize / 2,
				positionX + x * gridSize + gridSize / 2, positionY + gridSize * clickY[0] + gridSize / 2);
			line(positionX + x * gridSize + gridSize / 2, positionY + gridSize * clickY[0] + gridSize / 2,
				positionX + x * gridSize + gridSize / 2, positionY + gridSize * clickY[1] + gridSize / 2);
			line(positionX + x * gridSize + gridSize / 2, positionY + gridSize * clickY[1] + gridSize / 2,
				positionX + clickX[1] * gridSize + gridSize / 2, positionY + gridSize * clickY[1] + gridSize / 2);

			break;
		}
	}
}

void Image::thereLineUp(bool & there)
{
	for (int y = minClickY - 1; y >= 0; y--) {//������;"��"��״
		there = true;//ÿ��ѭ��Ҫ�ָ�Ϊ��
		if (gridAttribute[minClickX][y] != 0 || gridAttribute[maxClickX][y] != 0) {
			there = false;
			break;
		}
		for (int x = minClickX; x < maxClickX; x++) {
			if (gridAttribute[x][y] != 0) {
				there = false;
				break;
			}
		}
		if (there == true) {//������һ��ͨ·����
			//���ߣ��̶�һ���click���굽y�������ߺ�y��ͨ·������
			line(positionX + clickX[0] * gridSize + gridSize / 2, positionY + gridSize * clickY[0] + gridSize / 2,
				positionX + clickX[0] * gridSize + gridSize / 2, positionY + gridSize * y + gridSize / 2);
			line(positionX + clickX[0] * gridSize + gridSize / 2, positionY + gridSize * y + gridSize / 2,
				positionX + clickX[1] * gridSize + gridSize / 2, positionY + gridSize * y + gridSize / 2);
			line(positionX + clickX[1] * gridSize + gridSize / 2, positionY + gridSize * y + gridSize / 2,
				positionX + clickX[1] * gridSize + gridSize / 2, positionY + gridSize * clickY[1] + gridSize / 2);
			//��¼

			break;
		}
	}
}

void Image::thereLineDown(bool & there)
{
	for (int y = maxClickY + 1; y < mapColumn + 2; y++) {//������;"��"��״
		there = true;//ÿ��ѭ��Ҫ�ָ�Ϊ��
		if (gridAttribute[minClickX][y] != 0 || gridAttribute[maxClickX][y] != 0) {
			there = false;
			break;
		}
		for (int x = minClickX + 1; x < maxClickX; x++) {
			if (gridAttribute[x][y] != 0) {
				there = false;
				break;
			}
		}
		if (there == true) {//������һ��ͨ·����
			//���ߣ��̶�һ���click���굽y�������ߺ�y��ͨ·������
			line(positionX + clickX[0] * gridSize + gridSize / 2, positionY + gridSize * clickY[0] + gridSize / 2,
				positionX + clickX[0] * gridSize + gridSize / 2, positionY + gridSize * y + gridSize / 2);
			line(positionX + clickX[0] * gridSize + gridSize / 2, positionY + gridSize * y + gridSize / 2,
				positionX + clickX[1] * gridSize + gridSize / 2, positionY + gridSize * y + gridSize / 2);
			line(positionX + clickX[1] * gridSize + gridSize / 2, positionY + gridSize * y + gridSize / 2,
				positionX + clickX[1] * gridSize + gridSize / 2, positionY + gridSize * clickY[1] + gridSize / 2);
			//��¼

			break;
		}
	}
}

//�ж�ͼƬ�Ƿ�ȫ���������ܷ��������һ�أ�
bool Image::judgePass()
{
	pass = false;
	int allGrid = 0;
	for (int x = 1; x <= mapRow; x++) {
		for (int y = 1; y <= mapColumn; y++) {
			allGrid = gridAttribute[x][y];
			if (allGrid != 0) {//����ִ�д���
				break;
			}
		}
		if (allGrid != 0) {//����ִ�д���
			break;
		}
	}
	if (allGrid == 0) {
		pass = true;
		
	}
	return pass;
}


void Image::gridJudgement(MOUSEMSG mouse) 
{	
	//ÿ���жϿ�ʼǰ������Ϊfalse
	clearOne = false;
	if (mouse.mkLButton) {// �������Ƿ���
		if ((mouse.x >= positionX+gridSize && mouse.x <= positionX + gridSize * (mapRow+1))&&
			(mouse.y >= positionY+gridSize && mouse.y <= positionY + gridSize * (mapColumn+1))) {
			//�ж�����Ƿ��������ĵ�ͼ�ڣ��������߽磩
			int x = (int)((mouse.x - positionX)/gridSize);
			//�������ڸ��ӵ�x����,ԭ��Ϊ��0,0��,image�ӣ�1,1����ʼ
			int y = (int)((mouse.y - positionY) / gridSize);//�������ڸ��ӵ�y����
			if (gridAttribute[x][y]!= 0) {//���Ϊ�ո���

				clickAttribute[markCount] = gridAttribute[x][y];
				clickX[markCount] = x;
				clickY[markCount] = y;
				//������ɫ
				setcolor(RGB(85, 255, 255));
				setlinestyle(PS_SOLID, 3);
				//ѡ�еı��
				rectangle(positionX + gridSize * clickX[markCount]+2, 
					positionY + gridSize * clickY[markCount]+2,
				positionX + gridSize * clickX[markCount] + gridSize-2, 
					positionY + gridSize * clickY[markCount] + gridSize-2);
	
				if (markCount == 1) {
					//������ε����λ��Ϊͬһ��
					if (clickX[0] == clickX[1] && clickY[0] == clickY[1]) {
						//markCountÿ��Ҫ��1����ֵ-1ʹClickX��Y�����0��ʼ;
						markCount =-1;
						//���ѡ������ѡ���൱��ȡ��
						//imageNumber[i][j]��x��y�Ĺ�ϵΪ
						//(x-1)*mapColumn+y-1=i*2+j;
						putimage(positionX + clickX[0] * gridSize, positionY + clickY[0] * gridSize,
							&imageNumber[((clickX[0]-1)*mapColumn+clickY[0]-1)/2]
							[((clickX[0] - 1)*mapColumn+clickY[0]-1)%2]);

					} //���λ�ò�ͬ�Ҽ�¼��ͼƬ���
					else if (clickAttribute[0] == clickAttribute[1]) {

						if (judgeClear() == true) {
							//����һ���̣߳�thread���������Ա����Ҫ��Ͷ���ĺ���
							Music music1;
							std::thread t(&Music::clearMusic, &music1);
							t.detach();				//����������֣�

							clearOne = true;

							backGroundImage(level);//����Ҫ����һ�Σ���Ȼ��û����������

							//ֹͣһ�£���ֹ�������̫�죻���۹۲첻��
							Sleep(150);
							//������һ�ż�¼ͼƬ
							putimage(positionX + gridSize * clickX[0], positionY + gridSize * clickY[0],
							gridSize, gridSize, &bgImage[level-1], positionX + gridSize * clickX[0], 
								positionY + gridSize * clickY[0]);
							
							//�����ڶ��ż�¼ͼƬ
							putimage(positionX + gridSize * clickX[1], positionY + gridSize * clickY[1],
							gridSize, gridSize, &bgImage[level-1], positionX + gridSize * clickX[1], 
								positionY + gridSize * clickY[1]);
							

							//�������ӵ�ֱ��
							clearLine();
							//����ͼƬҪ�����������ԣ���ֹ������������ĸ��Ӽ�¼��Ϣ�������ִ���
							gridAttribute[clickX[0]][clickY[0]] = 0;
							gridAttribute[clickX[1]][clickY[1]] = 0;
							//markCountÿ��Ҫ��1����ΪʹcountClick[]=0����ֵΪ-1��
							markCount = -1;							
						}//��¼��ͼƬ��������
						else {
							//markCountÿ��Ҫ��1����ΪʹcountClick==0����ֵΪ-1��
							markCount = -1;
							//���ѡ��
							for (int i = 0; i < 2; i++) {
								putimage(positionX + clickX[i] * gridSize, positionY + clickY[i] * gridSize,
									&imageNumber[((clickX[i] - 1)*mapColumn + clickY[i] - 1) / 2]
									[((clickX[i] - 1)*mapColumn + clickY[i] - 1) % 2]);
							}

						}
					} else {//��Ϊ����ͼƬ��¼��Ϊͬһ������markCount==1ʱ�жϣ�
						//��Ҫ��ֵ����һ���¼(��markCount==0ʱ��

						//���ѡ��
						for (int i = 0; i < 2; i++) {
							putimage(positionX + clickX[i] * gridSize, positionY + clickY[i] * gridSize,
								&imageNumber[((clickX[i] - 1)*mapColumn + clickY[i] - 1) / 2]
								[((clickX[i] - 1)*mapColumn + clickY[i] - 1) % 2]);
						}
						//��¼����Ϊ0��
						markCount = -1;	
					}
				}
				markCount++;
			}
		}
	}
	
}




void Image::imageVictory()					//ʤ����ͼƬ
{
	IMAGE victoryImage;
	loadimage(&victoryImage, _T("PNG"), _T("VICTORY"), WINDOW_WIDE, WINDOW_HEIGTH);
	putimage(0, 0, &victoryImage);
}

void Image::imageDefeat()
{
	IMAGE defeatImage;
	loadimage(&defeatImage, _T("PNG"), _T("DEFEAT"), WINDOW_WIDE, WINDOW_HEIGTH);
	putimage(0, 0, &defeatImage);

}

void Image::backGroundImage(int number)
{
	switch (number)
	{
	case 1: {
		loadimage(&bgImage[0], _T("IMAGE"), _T("�ǿ�����-³���ߺ�"),
			WINDOW_WIDE, WINDOW_HEIGTH);

		break;
	}
	case 2: {
		loadimage(&bgImage[1], _T("IMAGE"), _T("�����޶�Ƥ����ֽ-�������"),
			WINDOW_WIDE, WINDOW_HEIGTH);

		break;
	}
	case 3: {
		loadimage(&bgImage[2], _T("IMAGE"), _T("����Ů��-�ŵ���"),
			WINDOW_WIDE, WINDOW_HEIGTH);

		break;
	}
	case 4: {
		loadimage(&bgImage[3], _T("IMAGE"), _T("�ĺ-�˷�����"),
			WINDOW_WIDE, WINDOW_HEIGTH);

		break;
	}
	case 5: {
		loadimage(&bgImage[4], _T("IMAGE"), _T("��ľ��-�ഺ������"),
			WINDOW_WIDE, WINDOW_HEIGTH);

		break;
	}
	case 6: {
		loadimage(&bgImage[5], _T("IMAGE"), _T("��ҧ�𡪹������"),
			WINDOW_WIDE, WINDOW_HEIGTH);

		break;
	}
	case 7: {
		loadimage(&bgImage[6], _T("IMAGE"), _T("�缧-��԰����"),
			WINDOW_WIDE, WINDOW_HEIGTH);

		break;
	}
	case 8: {
		loadimage(&bgImage[7], _T("IMAGE"), _T("�����-����"),
			WINDOW_WIDE, WINDOW_HEIGTH);

		break;
	}
	case 9: {
		loadimage(&bgImage[8], _T("IMAGE"), _T("٤�ޡ�������Ů"),
			WINDOW_WIDE, WINDOW_HEIGTH);

		break;
	}
	case 10: {
		loadimage(&bgImage[9], _T("IMAGE"), _T("����-������"),
			WINDOW_WIDE, WINDOW_HEIGTH);

		break;
	}
	case 11: {
		loadimage(&bgImage[10], _T("IMAGE"), _T("����-�ƽ�������"),
			WINDOW_WIDE, WINDOW_HEIGTH);

		break;
	}
	case 12: {
		loadimage(&bgImage[11], _T("IMAGE"), _T("���-�����"),
			WINDOW_WIDE, WINDOW_HEIGTH);

		break;
	}
	case 13: {
		loadimage(&bgImage[12], _T("IMAGE"), _T("�����ɾ�-�����"),
			WINDOW_WIDE, WINDOW_HEIGTH);

		break;
	}
	}
}

//��0�أ�����Ϸ��ʼ���棻
void Image::gameStartImage()
{
	IMAGE imgBegin;//���뿪ʼ�ı���ͼƬ
	loadimage(&imgBegin, _T("PNG") ,_T("���߿�ʼ��Ϸ����"), 1000, 540);
	//û�ҵ�ʲô�õ�ͼƬ�����õ��Լ����ֻ���ͼ
	putimage(0, 0, &imgBegin);
	//Ȧ����Ϸ������
	setlinecolor(RED);
	setlinestyle(PS_SOLID, 3);
	circle(962, 81, 24);
	
	infiniteBttom();
	levelBttom();
}

void Image::finalVictoryImage()
{
	IMAGE finalVictory;
	loadimage(&finalVictory, _T("IMAGE"), _T("����-�ִ�����"), WINDOW_WIDE, WINDOW_HEIGTH);
	putimage(0, 0, &finalVictory);

}


void Image::imagePause()
{
	IMAGE imgP;
	loadimage(&imgP, _T("PNG"),_T("pause"), PAUSE_SIZE, PAUSE_SIZE);

	putimage(PAUSE_PX, PAUSE_PY, &imgP);
}
//��Ϸ��ʼ���棻
void Image::imageContinue()
{
	IMAGE imgS;
	loadimage(&imgS, _T("PNG"), _T("start"), PAUSE_SIZE, PAUSE_SIZE);

	putimage(PAUSE_PX, PAUSE_PY, &imgS);
}

void Image::imageExit()
{

	IMAGE imgE;
	loadimage(&imgE, _T("PNG"), _T("exit"), EXIT_SIZE, EXIT_SIZE);

	putimage(EXIT_PX, EXIT_PY, &imgE);

}

//ͨ�ذ�ť
void Image::passBottom()
{
	IMAGE passBottom;
	loadimage(&passBottom, _T("IMAGE"), _T("����"), PASS_BOTTOM_SIZE, PASS_BOTTOM_SIZE);
	//��ͨ�ذ�ť�������½ǣ�
	putimage(WINDOW_WIDE-PASS_BOTTOM_SIZE, WINDOW_HEIGTH-PASS_BOTTOM_SIZE, &passBottom);
}

//����ģʽ��ť
void Image::levelBttom()
{
	IMAGE imgL;
	loadimage(&imgL, _T("PNG"), _T("����ģʽ"), MODE_LENGTH, MODE_WIDE);
	putimage(LEVEL_MODE_PX, MODE_PY, &imgL);
}

//����ģʽ��ť
void Image::infiniteBttom()
{
	IMAGE imgI;
	loadimage(&imgI, _T("PNG"), _T("����ģʽ"), MODE_LENGTH, MODE_WIDE);
	putimage(INFINITE_PX, MODE_PY, &imgI);
}

bool Image::getClearOne()
{
	return clearOne;
}

int Image::getLevel()
{
	return level;
}

void Image::initMaxImageNumber()
{
	maxImageNumber = INITo_IMAGE_NUMBER;
}

void Image::maxImageNumberPlus()
{
	maxImageNumber++;
}

void Image::levelPlus()
{
	//ͨ�أ��ؿ�����1��
	level++;

}

void Image::initLevel()
{
		level = 1;
}




