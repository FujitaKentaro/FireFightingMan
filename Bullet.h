#pragma once
#include "Struct.h"
#include "Map.h"

class Bullet {
public:
	Bullet();
	~Bullet();
	
public:
	void BulletShot(Transform transform, int x, int y);
	void BulletMove(const int G,int x,int y);
	void GetBullet(int BLOCK_SIZE);
	void BlockCollision(int map[][50]);
	void DeleteBullet();

	void DrawBullet(int scroll);
public:
	static const int BULLET_CONST = 5000;

	BULLET bullet[BULLET_CONST];

	//���̍��E�ւ̍L����
	int randNum[BULLET_CONST];


	//����̍��W
	int leftTopX[ BULLET_CONST];
	int leftTopY[BULLET_CONST];
	//�����̍��W
	int leftBottomX[BULLET_CONST];
	int	leftBottomY[BULLET_CONST];
	//�E���̍��W
	int rightTopX[BULLET_CONST];
	int rightTopY[BULLET_CONST];
	//�E���̍��W
	int rightBottomX[BULLET_CONST];
	int rightBottomY[BULLET_CONST];

	//�������x
	int alpha[BULLET_CONST];
	int alphaTime[BULLET_CONST];

	//�}�b�v
	Map* map;
};