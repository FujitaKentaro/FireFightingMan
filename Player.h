#pragma once
#include "Struct.h"
#include "Bullet.h"
#include "Map.h"

class Player {
public:
	Player();
	~Player();

public:
	void SaveOldPlayer();
	void GetPlayerBottom(int BLOCK_SIZE);
	void ResetIsJump(int map[][50]);

	void PlayerMove(int LInputX, int RInputX, int RInputY, int isRescued);
	void PlayerJump(int pad, int isRescued);
	void PlayerShot(int InputX, int InputY, int isRescued);
	void PlayerDamage(int fireX,int fireY,int fireR,int isFire);
	void DamageCount();
	void GetPlayer(int BLOCK_SIZE);
	void GetOldPlayer(int BLOCK_SIZE);
	void GetScroll();
	void BlockCollision(int map[][50]);
	void DownPlayer(int map[][50], int BLOCK_SIZE);
	void CheckStick(int InputY);

	void DrawPlayer();
	void DrawHp();
public:
	PLAYER player;
	OldPlayer oldPlayer;

	//�̗�
	int hp;
	int isDamage;
	int isDamageTimer;

	//�v���C���[�̏㉺�ړ�����
	int inertia, inertiaSpeed;

	//�{�^���̒������΍�
	int isButton;

	//����̍��W
	int leftTopX, leftTopY;
	//�����̍��W
	int leftBottomX, leftBottomY;
	//�E���̍��W
	int rightTopX, rightTopY;
	//�E���̍��W
	int rightBottomX, rightBottomY;
	//1�t���[���O�̍���̍��W
	int oldLeftTopX, oldLeftTopY;
	//1�t���[���O�̉E��̍��W
	int oldRightTopX, oldRightTopY;
	//1�t���[���O�̍����̍��W
	int oldLeftBottomX, oldLeftBottomY;
	//1�t���[���O�̉E���̍��W
	int oldRightBottomX, oldRightBottomY;

	//�W�����v�Ǘ��p�̍��W
	int jumpLeftBottomX, jumpLeftBottomY;
	int jumpRightBottomX, jumpRightBottomY;

	//�d��
	const int G = 15;

	//�X�N���[��
	int scroll;

	//�V�[���Ǘ�
	int scene;

	//�e
	Bullet* bullet;
	//�}�b�v
	Map* map;
};