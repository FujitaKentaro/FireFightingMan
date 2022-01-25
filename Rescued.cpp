#include "Rescued.h"

//�R���X�g���N�^
Rescued::Rescued() {
	transform = {
		2300,
		300
	};
	r = 20;
	isRescued = false;
	graph_r = LoadGraph("resource/syoubousi_kyujo.png");
	player = new Player;
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
	//DrawBox(transform.x - r - scroll, transform.y - r, transform.x + r - scroll, transform.y + r, GetColor(0, 255, 255), true);7
	DrawRotaGraph(15+transform.x -2 - scroll, transform.y +5, 1.3, 0.0, graph_r, 1, 0, 0);
}

//���Z�b�g�֐�
void Rescued::Reset() {
	transform.x = 2300;
	transform.y = 300;
	isRescued = false;
}