#pragma once
#include "Struct.h"
#include "Bullet.h"
#include "Map.h"

class Player {
public:
	Player();
	~Player();
public:
	PLAYER player;
	OldPlayer oldPlayer;

	//�̗�
	int hp;
	int isDamage;
	int isDamageTimer;

	//���^���N
	static const int WATER_CONST = 350;
	int water;

	//�v���C���[�̃X�s�[�h�Ǘ�
	float speed;

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
	const int G = 10;

	//�X�N���[��
	int scroll;

	//�V�[���Ǘ�
	int scene;

	//�O���t
	int graph_h;
	int graph_h2;
	int waterTank;

	//�`���[�g���A���p
	int isShow;

	//�e
	Bullet* bullet;
	//�}�b�v
	Map* map;

	//SE
	int damageSE;
	int waterSE;
	int walkSE;
	int startSE;
	int jumpSE;
	int dashSE;

public:
	void Spawn(int mapChip[][50]);

	void SaveOldPlayer();
	void GetPlayerBottom(int BLOCK_SIZE);

	void Dash(int pad, int isRescued, int inputX, int inputY);
	void PlayerMove(int LInputX, int RInputX, int RInputY, int isRescued);
	void PlayerJump(int pad, int isRescued, int map[][50]);
	void PlayerShot(int InputX, int InputY, int isRescued);
	void PlayerDamage(int fireX, int fireY, int fireR, int isFire, int isRescued, int select);
	void DamageCount();
	void GetPlayer(int BLOCK_SIZE);
	void GetOldPlayer(int BLOCK_SIZE);
	void GetScroll();
	void BlockCollision(int map[][50]);
	void DownPlayer(int map[][50], int BLOCK_SIZE);
	void CheckStick(int InputY, int isRescued);

	void DrawPlayer(int isRescued);
	void DrawHp();
	void DrawWater();
};