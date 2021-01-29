#include "../common.h"

TitleScene::TitleScene()
{
	TextureData::BackGround_BLUE = LoadGraph("res/setumeihaikei.png");
	TextureData::Description = LoadGraph("res/���[������.png");

	TextureData::Enter = LoadGraph("res/enter.png");
	TextureData::Esc = LoadGraph("res/esc.png");

	TextureData::DescFrame = LoadGraph("res/�����\���g.png");
	TextureData::DescLeft = LoadGraph("res/���_��.png");
	TextureData::DescRight = LoadGraph("res/���_�E.png");

	TextureData::Desc_Light = LoadGraph("res/���Z.png");
	TextureData::Desc_Dark = LoadGraph("res/�ÁZ.png");

	TextureData::Desc_tex1 = LoadGraph("res/�������_�P.png");
	TextureData::Desc_tex2 = LoadGraph("res/�������_2.png");
	TextureData::Desc_tex3 = LoadGraph("res/�������_3.png");
	TextureData::Desc_tex4 = LoadGraph("res/�������_4.png");
	TextureData::Desc_tex5 = LoadGraph("res/�������_�T.png");

	TextureData::Desc_txt1 = LoadGraph("res/�����e�L�X�g1.png");
	TextureData::Desc_txt2 = LoadGraph("res/�����e�L�X�g2.png");
	TextureData::Desc_txt3 = LoadGraph("res/�����e�L�X�g3.png");
	TextureData::Desc_txt4 = LoadGraph("res/�����e�L�X�g4.png");
	TextureData::Desc_txt5 = LoadGraph("res/�����e�L�X�g5.png");



	TextureData::Desc_Desc = LoadGraph("res/�e�L�X�g�{�b�N�X.png");

	TextureData::Character1 = LoadGraph("res/�C���r�W�u���V���b�g�����G.png");

	SceneBase::Choice_Min = 1;
	SceneBase::Choice_Max = 2;

	SceneBase::back_posx1 = 0.0f;
	SceneBase::back_posy1 = 0.0f;
	SceneBase::back_posx2 = 0.0f;
	SceneBase::back_posy2 = -720.0f;
	SceneBase::back_posx3 = 1280.0f;
	SceneBase::back_posy3 = -720.0f;
	SceneBase::back_posx4 = 1280.0f;
	SceneBase::back_posy4 = -1440.0f;
	SceneBase::back_posx5 = 0.0f;
	SceneBase::back_posy5 = 720.0f;
	SceneBase::back_posx6 = 1280.0f;
	SceneBase::back_posy6 = 0.0f;

	SceneBase::scroll_speedx = 8.0f;
	SceneBase::scroll_speedy = 4.5f;


	//�摜�̓ǂݍ���
	TextureData::Title = LoadGraph("res/�^�C�g�����S2.png");
	TextureData::BackGround_BLUE = LoadGraph("res/haikei_blue.png");
	TextureData::Button_Start = LoadGraph("res/�^�C�g���{�^��_�X�^�[�g.png");
	TextureData::Button_Rule = LoadGraph("res/�^�C�g���{�^��_���[��.png");

	SceneBase::Choice = 0;

	soundManager = SoundManager::GetInstance();
	soundManager->LoadSceneSound(SceneID_Title);
	soundManager->LoadSceneSound(SceneID_Description);
}
TitleScene::~TitleScene()
{
	TextureData::DeleteTex();
	soundManager->DeleteSceneSound(SceneID_Description);
	soundManager->DeleteSceneSound(SceneID_Title);
}
void TitleScene::Exec()
{
	if (description_scene)
	{
		back_posx1 -= scroll_speedx;
		back_posy1 += scroll_speedy;
		back_posx2 -= scroll_speedx;
		back_posy2 += scroll_speedy;
		back_posx3 -= scroll_speedx;
		back_posy3 += scroll_speedy;
		back_posx4 -= scroll_speedx;
		back_posy4 += scroll_speedy;
		back_posx5 -= scroll_speedx;
		back_posy5 += scroll_speedy;
		back_posx6 -= scroll_speedx;
		back_posy6 += scroll_speedy;

		if (back_posx1 <= -1280)
		{
			back_posx1 = 1280;
			back_posy1 = -720;
		}
		if (back_posx3 <= -1280)
		{
			back_posx3 = 1280;
			back_posy3 = -720;
		}
		if (back_posx2 <= -1280)
		{
			back_posx2 = 1280;
			back_posy2 = -1440;
		}
		if (back_posx4 <= -1280)
		{
			back_posx4 = 1280;
			back_posy4 = -1440;
		}
		if (back_posx5 <= -1280)
		{
			back_posx5 = 1280;
			back_posy5 = 0;
		}
		if (back_posx6 <= -1280)
		{
			back_posx6 = 1280;
			back_posy6 = 0;
		}

		if (IsKeyPushed(KEY_INPUT_RIGHT))
		{
			if (Choice == 5)
			{
				Choice = 1;
				PlaySoundMem(soundManager->GetSoundData(sound::Cursor), DX_PLAYTYPE_BACK, TRUE);
			}
			else if (Choice < Choice_Max)
			{
				Choice += 1;
				PlaySoundMem(soundManager->GetSoundData(sound::Cursor), DX_PLAYTYPE_BACK, TRUE);
			}
		}
		else if (IsKeyPushed(KEY_INPUT_LEFT))
		{
			if (Choice > Choice_Min)
			{
				Choice -= 1;
				PlaySoundMem(soundManager->GetSoundData(sound::Cursor), DX_PLAYTYPE_BACK, TRUE);
			}
			else if (Choice == 1)
			{
				Choice = 5;
				PlaySoundMem(soundManager->GetSoundData(sound::Cursor), DX_PLAYTYPE_BACK, TRUE);
			}
		}

		//if (IsKeyPushed(KEY_INPUT_RETURN))
		//{
		//	SceneManager::SetNextScene(SceneID_SelectNumberOfPeople);
		//}
		else if (IsKeyPushed(KEY_INPUT_ESCAPE))
		{
			//PlaySoundMem(soundManager->GetSoundData(sound::ChangeScene), DX_PLAYTYPE_BACK, TRUE);
			description_scene = false;
			SceneBase::Choice = 2;
			SceneBase::Choice_Min = 1;
			SceneBase::Choice_Max = 2;
		}


		return;
	}

	back_posx1 -= scroll_speedx;
	back_posy1 += scroll_speedy;
	back_posx2 -= scroll_speedx;
	back_posy2 += scroll_speedy;
	back_posx3 -= scroll_speedx;
	back_posy3 += scroll_speedy;
	back_posx4 -= scroll_speedx;
	back_posy4 += scroll_speedy;
	back_posx5 -= scroll_speedx;
	back_posy5 += scroll_speedy;
	back_posx6 -= scroll_speedx;
	back_posy6 += scroll_speedy;
	/*back_posx1 -= scroll_speed;
	back_posx4 -= scroll_speed;*/

	/*if (back_posx1 <= -1280)
	{
		back_posx1 = 1280;
	}
	if (back_posx4 <= -1280)
	{
		back_posx4 = 1280;
	}*/
	if (back_posx1 <= -1280)
	{
		back_posx1 = 1280;
		back_posy1 = -720;
	}
	if (back_posx3 <= -1280)
	{
		back_posx3 = 1280;
		back_posy3 = -720;
	}
	if (back_posx2 <= -1280)
	{
		back_posx2 = 1280;
		back_posy2 = -1440;
	}
	if (back_posx4 <= -1280)
	{
		back_posx4 = 1280;
		back_posy4 = -1440;
	}
	if (back_posx5 <= -1280)
	{
		back_posx5 = 1280;
		back_posy5 = 0;
	}
	if (back_posx6 <= -1280)
	{
		back_posx6 = 1280;
		back_posy6 = 0;
	}

	if (IsKeyPushed(KEY_INPUT_RIGHT))
	{
		if (Choice == 0)
		{
			Choice = 2;
			PlaySoundMem(soundManager->GetSoundData(sound::Cursor), DX_PLAYTYPE_BACK, TRUE);
		}
		else if (Choice < Choice_Max)
		{
			Choice += 1;
			PlaySoundMem(soundManager->GetSoundData(sound::Cursor), DX_PLAYTYPE_BACK, TRUE);
		}
	}
	else if (IsKeyPushed(KEY_INPUT_LEFT))
	{
		if (Choice > Choice_Min)
		{
			Choice -= 1;
			PlaySoundMem(soundManager->GetSoundData(sound::Cursor), DX_PLAYTYPE_BACK, TRUE);
		}
		else if (Choice == 0)
		{
			Choice = 1;
			PlaySoundMem(soundManager->GetSoundData(sound::Cursor), DX_PLAYTYPE_BACK, TRUE);
		}
	}

	if (Choice == 1 && IsKeyPushed(KEY_INPUT_RETURN))
	{
		PlaySoundMem(soundManager->GetSoundData(sound::ChangeScene), DX_PLAYTYPE_BACK, TRUE);
		SceneManager::SetNextScene(SceneID_SelectNumberOfPeople);
		nextScene = true;
	}
	else if (Choice == 2 && IsKeyPushed(KEY_INPUT_RETURN))
	{
		PlaySoundMem(soundManager->GetSoundData(sound::ChangeScene), DX_PLAYTYPE_BACK, TRUE);
		description_scene = true;
		SceneBase::Choice_Min = 1;
		SceneBase::Choice_Max = 5;
		SceneBase::Choice = 1;
	}
}

void TitleScene::Draw()
{
	if (description_scene)
	{
		DrawGraph(back_posx1, back_posy1, TextureData::BackGround_BLUE, false);
		DrawGraph(back_posx2, back_posy2, TextureData::BackGround_BLUE, false);
		DrawGraph(back_posx3, back_posy3, TextureData::BackGround_BLUE, false);
		DrawGraph(back_posx4, back_posy4, TextureData::BackGround_BLUE, false);
		DrawGraph(back_posx5, back_posy5, TextureData::BackGround_BLUE, false);
		DrawGraph(back_posx6, back_posy6, TextureData::BackGround_BLUE, false);

		//DrawGraph(20, 20, TextureData::Enter, true);
		DrawGraph(1104, 20, TextureData::Esc, true);

		DrawGraph(445, 0, TextureData::Description, true);

		DrawGraph(125, 124, TextureData::DescFrame, true);

		DrawGraph(507, 546, TextureData::Desc_Dark, true);
		DrawGraph(523, 546, TextureData::Desc_Dark, true);
		DrawGraph(539, 546, TextureData::Desc_Dark, true);
		DrawGraph(555, 546, TextureData::Desc_Dark, true);
		DrawGraph(571, 546, TextureData::Desc_Dark, true);

		DrawGraph(152, 564, TextureData::Desc_Desc, true);

		switch (Choice)
		{
		case 1:
			DrawGraph(125, 124, TextureData::Desc_tex1, true);
			DrawGraph(507, 546, TextureData::Desc_Light, true);
			DrawGraph(150, 560, TextureData::Desc_txt1, true);

			break;
		case 2:
			DrawGraph(125, 124, TextureData::Desc_tex2, true);
			DrawGraph(523, 546, TextureData::Desc_Light, true);
			DrawGraph(150, 560, TextureData::Desc_txt2, true);
			break;
		case 3:
			DrawGraph(125, 124, TextureData::Desc_tex3, true);
			DrawGraph(539, 546, TextureData::Desc_Light, true);
			DrawGraph(150, 560, TextureData::Desc_txt3, true);
			break;
		case 4:
			DrawGraph(125, 124, TextureData::Desc_tex4, true);
			DrawGraph(555, 546, TextureData::Desc_Light, true);
			DrawGraph(150, 560, TextureData::Desc_txt4, true);
			break;
		case 5:
			DrawGraph(125, 124, TextureData::Desc_tex5, true);
			DrawGraph(571, 546, TextureData::Desc_Light, true);
			DrawGraph(150, 560, TextureData::Desc_txt5, true);
			break;
		default:
			break;
		}

		DrawGraph(21, 232, TextureData::DescLeft, true);
		DrawGraph(940, 232, TextureData::DescRight, true);

		DrawGraph(999, 272, TextureData::Character1, true);




		return;
	}



	DrawGraph(back_posx1, back_posy1, TextureData::BackGround_BLUE, false);
	DrawGraph(back_posx2, back_posy2, TextureData::BackGround_BLUE, false);
	DrawGraph(back_posx3, back_posy3, TextureData::BackGround_BLUE, false);
	DrawGraph(back_posx4, back_posy4, TextureData::BackGround_BLUE, false);
	DrawGraph(back_posx5, back_posy5, TextureData::BackGround_BLUE, false);
	DrawGraph(back_posx6, back_posy6, TextureData::BackGround_BLUE, false);
	
	if (Choice == 0)
	{
		DrawGraph(250, 500, TextureData::Button_Start, true);
		DrawGraph(700, 500, TextureData::Button_Rule, true);
	}
	else if (Choice == 1)
	{
		DrawExtendGraph(240, 490, 590, 635, TextureData::Button_Start, true);
		DrawGraph(700, 500, TextureData::Button_Rule, true);
	}
	else if (Choice == 2)
	{
		DrawGraph(250, 500, TextureData::Button_Start, true);
		DrawExtendGraph(690, 490, 1040, 635, TextureData::Button_Rule, true);
	}

	DrawGraph(190, 30, TextureData::Title, true);
		//��ʍ���Ƀf�o�b�O�p�̕��������ŕ\������
	//DrawString(20, 20, "TitleScene", GetColor(0, 0, 0));
}

bool TitleScene::IsEnd() const
{
	//if (IsKeyPushed(KEY_INPUT_RETURN) && Choice == 1)
	//{
	//	TextureData::DeleteTex();
	//	return true;
	//}

	return 	nextScene;
}