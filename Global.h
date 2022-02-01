#pragma once
#include "DxLib.h"

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "�~�ρI�q�P�V�[�}��";

// �E�B���h�E����
const int WIN_WIDTH = 1280;

// �E�B���h�E�c��
const int WIN_HEIGHT = 960;

const float PI = 3.141592f;

//�}�b�v
enum MapInfo {
	NONE,			//0
	BLOCK,			//1
	FLAME,			//2
	FLAMEENEMY,		//3
	PLAYER_SPAWN,	//4
	WOMAN_SPAWN		//5
};

enum SceneInfo {
	MAIN_TITLE,			//0
	MAIN_GAME,			//1
	STAGE_SELECT,		//2
	GAMEOVER,			//3
	CLEAR,				//4
	PAUSE,				//5
	TEXT				//6
};

enum SelectInfo {
	TUTORIAL,	//0
	STAGE1,		//1
	STAGE2,     //2
	STAGE3		//3
};