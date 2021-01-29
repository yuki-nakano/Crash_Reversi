﻿#include "../common.h"

SelectNumberOfPeopleScene::SelectNumberOfPeopleScene()
{
 	SceneBase::Choice_Min = 1;
	SceneBase::Choice_Max = 2;
	SceneBase::Choice = 0;

	SceneBase::back_posx1 = -1280;
	SceneBase::back_posy1 = 0;
	SceneBase::back_posx2 = 0;
	SceneBase::back_posy2 = 0;
	SceneBase::back_posx3 = 1280;
	SceneBase::back_posy3 = 0;
	SceneBase::back_posx4 = 0;
	SceneBase::back_posy4 = -1280;
	SceneBase::back_posx5 = 1280;
	SceneBase::back_posy5 = -1280;
	SceneBase::back_posx6 = 2560;
	SceneBase::back_posy6 = -1280;

	SceneBase::scroll_speedx = 2;
	SceneBase::scroll_speedy = 2;

	TextureData::BackGround_BLUE = LoadGraph("res/haikei.png");

	TextureData::Enter = LoadGraph("res/enter.png");
	TextureData::Esc = LoadGraph("res/esc.png");

	TextureData::NumberOfPeople = LoadGraph("res/プレイ人数選択.png");

	TextureData::Player2 = LoadGraph("res/2人であそぶ.png");
	TextureData::Player4 = LoadGraph("res/4人であそぶ.png");

	soundManager = SoundManager::GetInstance();
	//soundManager->LoadSceneSound(SceneID_SelectNumberOfPeople);

	StopSoundMem(soundManager->GetSoundData(sound::title));
	PlaySoundMem(soundManager->GetSoundData(sound::title), DX_PLAYTYPE_LOOP, FALSE);
}

SelectNumberOfPeopleScene::~SelectNumberOfPeopleScene()
{
	TextureData::DeleteTex();
	//soundManager->DeleteSceneSound(SceneID_Title);
}

void SelectNumberOfPeopleScene::Exec()
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

	if (back_posy1 >= 1280)
	{
		back_posx1 = 0;
		back_posy1 = -1280;
	}
	if (back_posy2 >= 1280)
	{
		back_posx2 = 1280;
		back_posy2 = -1280;
	}
	if (back_posy3 >= 1280)
	{
		back_posx3 = 2560;
		back_posy3 = -1280;
	}
	if (back_posy4 >= 1280)
	{
		back_posx4 = 0;
		back_posy4 = -1280;
	}
	if (back_posy5 >= 1280)
	{
		back_posx5 = 1280;
		back_posy5 = -1280;
	}
	if (back_posy6 >= 1280)
	{
		back_posx6 = 2560;
		back_posy6 = -1280;
	}

	if (IsKeyPushed(KEY_INPUT_RIGHT))
	{
		if (Choice == 0)
		{
			Choice = 2;
			PlaySoundMem(soundManager->GetSoundData(sound::Cursor), DX_PLAYTYPE_NORMAL, TRUE);
		}
		else if (Choice < Choice_Max)
		{
			Choice += 1;
			PlaySoundMem(soundManager->GetSoundData(sound::Cursor), DX_PLAYTYPE_NORMAL, TRUE);
		}
	}
	else if (IsKeyPushed(KEY_INPUT_LEFT))
	{
		if (Choice > Choice_Min)
		{
			Choice -= 1;
			PlaySoundMem(soundManager->GetSoundData(sound::Cursor), DX_PLAYTYPE_NORMAL, TRUE);
		}
		else if (Choice == 0)
		{
			Choice = 1;
			PlaySoundMem(soundManager->GetSoundData(sound::Cursor), DX_PLAYTYPE_NORMAL, TRUE);
		}
	}

	if (Choice == 1 && IsKeyPushed(KEY_INPUT_RETURN))
	{
		SceneBase::People_Max = 2;
		PlaySoundMem(soundManager->GetSoundData(sound::ChangeScene), DX_PLAYTYPE_NORMAL, TRUE);
		SceneManager::SetNextScene(SceneID_SelectCharacter);
	}
	else if (Choice == 2 && IsKeyPushed(KEY_INPUT_RETURN))
	{
		SceneBase::People_Max = 4;
		PlaySoundMem(soundManager->GetSoundData(sound::ChangeScene), DX_PLAYTYPE_NORMAL, TRUE);
		SceneManager::SetNextScene(SceneID_SelectCharacter);
	}
	/*else if (IsKeyPushed(KEY_INPUT_ESCAPE))
	{
		PlaySoundMem(soundManager->GetSoundData(sound::ChangeScene), DX_PLAYTYPE_NORMAL, TRUE);
		SceneManager::SetNextScene(SceneID_Title);
	}*/
}

void SelectNumberOfPeopleScene::Draw()
{
	DrawGraph(back_posx1, back_posy1, TextureData::BackGround_BLUE, false);
	DrawGraph(back_posx2, back_posy2, TextureData::BackGround_BLUE, false);
	DrawGraph(back_posx3, back_posy3, TextureData::BackGround_BLUE, false);
	DrawGraph(back_posx4, back_posy4, TextureData::BackGround_BLUE, false);
	DrawGraph(back_posx5, back_posy5, TextureData::BackGround_BLUE, false);
	DrawGraph(back_posx6, back_posy6, TextureData::BackGround_BLUE, false);

	DrawGraph(20, 20, TextureData::Enter, true);
	//DrawGraph(1104, 20, TextureData::Esc, true);

	DrawGraph(375, 0, TextureData::NumberOfPeople, true);

	if (Choice == 0)
	{
		DrawExtendGraph(275, 120, 630, 640, TextureData::Player2, false);
		DrawExtendGraph(650, 120, 1005, 640, TextureData::Player4, false);
	}
	else if (Choice == 1)
	{
		//DrawExtendGraph();
		DrawExtendGraph(265, 110, 640, 650, TextureData::Player2, false);
		DrawExtendGraph(650, 120, 1005, 640, TextureData::Player4, false);
	}
	else if (Choice == 2)
	{
		DrawExtendGraph(275, 120, 630, 640, TextureData::Player2, false);
		DrawExtendGraph(640, 110, 1015, 650, TextureData::Player4, false);
		//DrawExtendGraph();
	}

		//画面左上にデバッグ用の文字を黒で表示する
	//DrawString(20, 20, "NumberOfPeople", GetColor(0, 0, 0));
}

bool SelectNumberOfPeopleScene::IsEnd() const
{
		return ((IsKeyPushed(KEY_INPUT_RETURN) && Choice != 0) || (IsKeyPushed(KEY_INPUT_ESCAPE)));
}