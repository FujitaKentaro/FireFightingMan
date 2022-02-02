#include "Tutorial.h"

Tutorial::Tutorial() {
	timer = 0;
	step = 0;
	isEx = 0;
	isPush = 0;
	for (int i = 0; i < 6; i++) {
		isCom[i] = 0;
	}
	for (int i = 0; i < 4; i++) {
		exNum[i] = 0;
	}
	lostNum = 0;
	textNum = 0;

	//LoadDivGraph("resource/tutorial1.png", 4, 4, 1, 149, 149, tutorial1);
	//LoadDivGraph("resource/tutorial2.png", 4, 4, 1, 149, 149, tutorial2);
	//LoadDivGraph("resource/tutorial3.png", 4, 4, 1, 149, 149, tutorial3);
	//LoadDivGraph("resource/tutorial4.png", 4, 4, 1, 149, 149, tutorial4);
	//LoadDivGraph("resource/help.png", 2, 2, 1, 128, 64, help);
	//tutorial5 = LoadGraph("resource/tutorial5.png");
	//tutorial6 = LoadGraph("resource/tutorial6.png");
	//tutorial7 = LoadGraph("resource/tutorial7.png");

	textSE = LoadSoundMem("sound/text.mp3");

	ChangeVolumeSoundMem(140, textSE);
}

Tutorial::~Tutorial() {}



void Tutorial::DrawTutorial(int serect, int scroll, int isRescued,int isShow) {
	SetFontSize(64);
	DrawFormatString(525, 80, GetColor(255, 255, 255), "������");
	SetFontSize(32);
	if (serect == 0) {
		DrawRotaGraph2(2100 - scroll, 120, 0, 0, 1.8, 0, help[isRescued], true);
		SetFontSize(32);
		if (isShow == 1) {
			for (int i = 0; i < 2; i++) {
				DrawBox(100 - (1 + i), 375 - (1 + i), 500 + (1 + i), 480 + (1 + i), GetColor(255, 255, 255), false);
			}
			DrawBox(100, 375, 500, 480, GetColor(0,0,8), true);
			if (lostNum == 0) {
				DrawFormatString(130, 400, GetColor(255, 255, 255), "�����Ȃ��Ȃ��Ă��܂���");
			}
			else {
				DrawFormatString(130, 400, GetColor(255, 255, 255), "�O�{�^������\n���Z�b�g���悤");
			}
		}
		else {
			switch (textNum) {
				case 1:
					for (int i = 0; i < 2; i++) {
						DrawBox(100 - (1 + i), 375 - (1 + i), 500 + (1 + i), 480 + (1 + i), GetColor(255, 255, 255), false);
					}
					DrawBox(100, 375, 500, 480, GetColor(0,0,8), true);
					DrawFormatString(130, 400, GetColor(255, 255, 255), "B + R�X�e�B�b�N��\n�_�b�V�����悤");
					break;
				case 2:
					for (int i = 0; i < 2; i++) {
						DrawBox(100 - (1 + i), 375 - (1 + i), 500 + (1 + i), 480 + (1 + i), GetColor(255, 255, 255), false);
					}
					DrawBox(100, 375, 500, 480, GetColor(0,0,8), true);
					DrawFormatString(130, 400, GetColor(255, 255, 255), "L�{�^����\n�W�����v���悤");
					break;
				case 3:
					for (int i = 0; i < 2; i++) {
						DrawBox(100 - (1 + i), 375 - (1 + i), 500 + (1 + i), 480 + (1 + i), GetColor(255, 255, 255), false);
					}
					DrawBox(100, 375, 500, 480, GetColor(0,0,8), true);
					if (exNum[0] == 0) {
						DrawFormatString(130, 400, GetColor(255, 255, 255), "�^���N�̐���������\n���ǂ����ł���");
					}
					else if (exNum[0] == 1) {
						DrawFormatString(130, 400, GetColor(255, 255, 255), "R�X�e�B�b�N��\n�������ɏo����");
					}
					break;
				case 4:
					for (int i = 0; i < 2; i++) {
						DrawBox(100 - (1 + i), 375 - (1 + i), 500 + (1 + i), 480 + (1 + i), GetColor(255, 255, 255), false);
					}
					DrawBox(100, 375, 500, 480, GetColor(0,0,8), true);
					if (exNum[1] == 0) {
						DrawFormatString(130, 400, GetColor(255, 255, 255), "�΂ɂԂ����\n�^���N�̐����ւ�");
					}
					else if (exNum[1] == 1) {
						DrawFormatString(130, 400, GetColor(255, 255, 255), "����������\n�΂�3������");
					}
					break;
				case 5:
					for (int i = 0; i < 2; i++) {
						DrawBox(100 - (1 + i), 375 - (1 + i), 500 + (1 + i), 480 + (1 + i), GetColor(255, 255, 255), false);
					}
					DrawBox(100, 375, 500, 480, GetColor(0,0,8), true);
					if (exNum[2] == 0) {
						DrawFormatString(130, 400, GetColor(255, 255, 255), "�΂�������\n�P�V�Y�~�ɂȂ�");
					}
					else if (exNum[2] == 1) {
						DrawFormatString(130, 400, GetColor(255, 255, 255), "�P�V�Y�~�͂����ǂ���\n�̂邱�Ƃ��ł���");
					}
					break;
				case 6:
					for (int i = 0; i < 2; i++) {
						DrawBox(100 - (1 + i), 375 - (1 + i), 500 + (1 + i), 480 + (1 + i), GetColor(255, 255, 255), false);
					}
					DrawBox(100, 375, 500, 480, GetColor(0,0,8), true);
					if (exNum[3] == 0) {
						DrawFormatString(130, 400, GetColor(255, 255, 255), "��Ў҂̂ق��ɐ���");
					}
					else if (exNum[3] == 1) {
						DrawFormatString(130, 400, GetColor(255, 255, 255), "�ق��������Ƃ�\n�����o���Ȃ��Ȃ�");
					}
					else if (exNum[3] == 2) {
						DrawFormatString(130, 400, GetColor(255, 255, 255), "�����݂������ǂ�\n����������悤");
					}
					break;
			}
		}
		DrawFormatString(120, 345, GetColor(255, 255, 255), "Info");
		SetFontSize(16);
		DrawFormatString(425, 455, GetColor(255, 255, 255), "B:����");
	}
}