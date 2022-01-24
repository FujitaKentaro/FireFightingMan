#include "Rescued.h"

//�R���X�g���N�^
Rescued::Rescued() {
	transform = {
		2300,
		300
	};
	r = 20;
	isRescued = false;
	player = new Player;
	cx = 0;
	for (int i = 0; i < 2; i++) {
		cy[i] = 0;
	}
	cr = 36;
	time = 0;
	alpha = 255;
	catchGraph = LoadGraph("resource/catch.png");
}

//�f�X�g���N�^
Rescued::~Rescued() {
	delete player;
}

///-----�N���X�֐�-----///

//�����蔻��
void Rescued::RescuedCollision(Player* player,int &hp,int scene) {
	if (isRescued == false) {
		if (transform.x + r > player->player.transform.x - player->player.r && player->player.transform.x + player->player.r > transform.x - r) {
			if (transform.y + r > player->player.transform.y - player->player.r && player->player.transform.y + player->player.r > transform.y - r) {
				isRescued = true;
				hp = 1;
				cx = player->player.transform.x;
				for (int i = 0; i < 2; i++) {
					cy[i] = player->player.transform.y;
				}
				if (scene == TUTORIAL) {
					hp = 3;
				}
			}
		}
	}
}

//�ړ��֐�
void Rescued::Move(Player* player) {
	if (isRescued == true) {
		transform.x = player->player.transform.x;
		transform.y = player->player.transform.y - 25;
	}
}

//�`��֐�
void Rescued::Draw(int scroll) {
	DrawBox(transform.x - r - scroll, transform.y - r, transform.x + r - scroll, transform.y + r, GetColor(0, 255, 255), true);
	if (isRescued == true) {
		SetDrawBlendMode(DX_BLENDMODE_ADD, 200);
		if (cr > 0) {
			for (int i = 0; i < 15; i++) {
				DrawCircle(cx - scroll, cy[0], cr + (i * 1), GetColor(192, 192, 32), false);
			}
		}
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		DrawGraph(cx -scroll - 128, cy[1], catchGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
}

//���Z�b�g�֐�
void Rescued::Reset() {
	transform.x = 2300;
	transform.y = 300;
	cr = 36;
	time = 0;
	alpha = 255;
	isRescued = false;
}

void Rescued::CatchRescued() {
	if (isRescued == true) {
		time++;
		if (time < 6) {
			cr -= 4;
			cy[1] -= 30 * 0.6;
		}
		else {
			cr -= 2;
			if (alpha > 0) {
				alpha -= 16;
				cy[1] -= 1;
			}
		}
	}
}