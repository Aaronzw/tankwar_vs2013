#pragma once
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code)&0x8000)?1:0)//���尴��
//���λ����ͬ����
#define OBJ_TYPE_WALL	0x10000000		//ǽ
#define OBJ_TYPE_TANK	0x20000000		//̹��
#define OBJ_TYPE_BULLET	0x40000000		//�ӵ�
//��һλ��ʾ�ϰ�Ϊǽ���ڶ���Ϊǽ��ID,��������ʾǽѪֵ
#define WALL_COB        0x10010001		//��ǽ��hp=1
#define WALL_STO        0x10020002		//ʯǽ��hp=2
#define WALL_IRO        0x10040003		//��ǽ��hp=3
#define WALL_DIA        0x10080000		//���ɴݻٵ�ǽ
#define WALL_BLOOD		0x0F			//ǽ��hp
//�������λ��ʾǽ������
#define WALL_ID_COB		0x00010000		//��ǽ
#define WALL_ID_STO		0x00020000		//ʯǽ
#define WALL_ID_IRO		0x00040000		//��ǽ
#define WALL_ID_DIA		0x00080000		//���ɴݻ�
//�����ӵ������������ԣ���һλ�����ӵ����ڶ�λ�����ӵ�����
#define BULLET_MINE		0x40010000		// ����ӵ� 
#define BULLET_ENEMY	0x40020000		// �з��ӵ�
#define BULLET_ID_MINE	0x00010000		// 1���ҷ��ӵ�
#define BULLET_ID_ENEMY	0x00020000		// 2���з��ӵ�
// ������ɫ
#define F_BLUE     FOREGROUND_BLUE      // ����
#define F_H_BLUE   0x0001|0x0008        // ����
#define F_GREEN    0x0002               // ����
#define F_H_GREEN  0x0002|0x0008        // ����
#define F_RED      0x0004               // ���
#define F_H_RED    0x0004|0x0008        // ����
#define F_YELLOW   0x0002|0x0004        // ���
#define F_H_YELLOW 0x0002|0x0004|0x0008 // ����
#define F_PURPLE   0x0001|0x0004        // ����
#define F_H_PURPLE 0x0001|0x0004|0x0008 // ����
#define F_CYAN     0x0002|0x0004        // ����
#define F_H_CYAN   0x0002|0x0004|0x0008 // ����
#define F_WHITE    0x0004|0x0002|0x0001
#define F_H_WHITE  0x0004|0x0002|0x0001|0x0008
#define F_TEST     0x0007|0x000b|0x0003
// ������ɫ
#define B_BLUE     BACKGROUND_BLUE      // ����
#define B_H_BLUE   0x0010|0x0080        // ����
#define B_GREEN    0x0020               // ����
#define B_H_GREEN  0x0020|0x0080        // ����
#define B_RED      0x0040               // ���
#define B_H_RED    0x0040|0x0080        // ����
#define B_YELLOW   0x0020|0x0040        // ���
#define B_H_YELLOW 0x0020|0x0040|0x0080 // ����
#define B_PURPLE   0x0010|0x0040        // ����
#define B_H_PURPLE 0x0010|0x0040|0x0080 // ����
#define B_CYAN     0x0020|0x0040        // ����
#define B_H_CYAN   0x0020|0x0040|0x0080 // ����
#define B_WHITE    0x0010|0x0020|0x0040
#define B_H_WHITE  0x0002|0x0002
//����
#define  UP			0
#define  DOWN		1
#define  LEFT		2
#define  RIGHT		3



