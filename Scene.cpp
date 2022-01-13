#include "Scene.h"

//�R���X�g���N�^
Scene::Scene() {
	player = new Player;
	bullet = new Bullet;
	rescued = new Rescued;
	map = new Map;
	fire = new Fire;
	goal = new Goal;
	ene = new Enemy;
}

//�R���X�g���N�^
Scene::~Scene() {
	delete player;
	delete bullet;
	delete rescued;
	delete map;
	delete fire;
	delete goal;
	delete ene;
}


///-----�֐�-----///
void Scene::Update(char* keys, char* oldkeys) {

	//��O����
	if (keys == nullptr || oldkeys == nullptr) {
		return;
	}

	GetHitKeyStateAll(keys);
	ClearDrawScreen();

	GetJoypadDirectInputState(DX_INPUT_PAD1, &padInput);
	pad = GetJoypadInputState(DX_INPUT_PAD1);

	//�}�b�v�I��
	map->SelectMap1();

	switch (player->scene) {
		//�^�C�g��
		case 0:
			if (pad & PAD_INPUT_2) {
				player->scene = 1;
			}
			break;

			//�Q�[��
		case 1:

			//�΂̐ݒu
			if (keys[KEY_INPUT_F] == 1) {
				fire->SetFire(map->map);
			}

			//�v���C���[�ʒu�̕ۑ�
			player->SaveOldPlayer();

			//�v���C���[�̃W�����v�̉�
			player->GetPlayerBottom(map->BLOCK_SIZE);
			player->ResetIsJump(map->map);

			//�v���C���[�̈ړ�
			player->PlayerMove(padInput.X, padInput.Rx, padInput.Ry);
			player->PlayerJump(pad);
			rescued->Move(player);

			//�e�̔���
			player->PlayerShot(padInput.Rx, padInput.Ry);

			//�e�̋���
			player->bullet->BulletMove(player->G);

			//����
			fire->FireFighting(player->bullet->bullet);

			//�}�b�v�`�b�v��̍��W�ʒu�̎擾
			player->GetOldPlayer(map->BLOCK_SIZE);
			player->GetPlayer(map->BLOCK_SIZE);
			player->bullet->GetBullet(map->BLOCK_SIZE);

			//�����蔻��
			player->BlockCollision(map->map);
			player->bullet->BlockCollision(map->map);
			rescued->RescuedCollision(player);
			goal->GetGoal(player, rescued);

			//�v���C���[���n�ʂŕ����Ȃ��悤��
			player->GetPlayerBottom(map->BLOCK_SIZE);
			player->DownPlayer(map->map, map->BLOCK_SIZE);

			//�G�̏o��
			ene->Update(player->bullet->bullet);

			//�X�N���[��
			player->GetScroll();
			break;
	}
}

void Scene::Draw() {

	switch (player->scene) {
		case 0:
			DrawFormatString(640, 450, GetColor(255, 255, 255), "B to Start");
			break;

		case 1:
			// �`�揈��
			goal->Draw(rescued, player->scroll);
			fire->DrawFire(player->scroll);
			map->DrawMap(map->map, player->scroll);
			rescued->Draw(player->scroll);
			player->bullet->DrawBullet(player->scroll);
			player->DrawPlayer();
			ene->Draw(player->scroll);

			//�f�o�b�O
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
			DrawBox(0, 0, 500, 100, GetColor(255, 255, 255), true);
			DrawFormatString(0, 0, GetColor(50, 50, 50), "X:%d Y:%d Z:%d",
				padInput.X, padInput.Y, padInput.Z);
			DrawFormatString(0, 16, GetColor(50, 50, 50), "Rx:%d Ry:%d Rz:%d",
				padInput.Rx, padInput.Ry, padInput.Rz);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			break;
	}
}