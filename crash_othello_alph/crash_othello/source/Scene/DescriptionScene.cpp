﻿#include "../common.h"

DescriptionScene::DescriptionScene()
{
	SceneBase::Choice_Min = 1;
	SceneBase::Choice_Max = 5;
	SceneBase::Choice = 1;

	TextureData::BackGround_BLUE = LoadGraph("res/setumeihaikei.png");
	TextureData::Description = LoadGraph("res/ルール説明.png");

	TextureData::Enter = LoadGraph("res/enter.png");
	TextureData::Esc = LoadGraph("res/esc.png");

	TextureData::DescFrame = LoadGraph("res/説明表示枠.png");
	TextureData::DescLeft = LoadGraph("res/矢印_左.png");
	TextureData::DescRight = LoadGraph("res/矢印_右.png");

	TextureData::Desc_Light = LoadGraph("res/明〇.png");
	TextureData::Desc_Dark = LoadGraph("res/暗〇.png");

	TextureData::Desc_tex1 = LoadGraph("res/説明画面_１.png");
	TextureData::Desc_tex2 = LoadGraph("res/説明画面_2.png");
	TextureData::Desc_tex3 = LoadGraph("res/説明画面_3.png");
	TextureData::Desc_tex4 = LoadGraph("res/説明画面_4.png");
	TextureData::Desc_tex5 = LoadGraph("res/説明画面_５.png");

	TextureData::Desc_txt1 = LoadGraph("res/説明テキスト1.png");
	TextureData::Desc_txt2 = LoadGraph("res/説明テキスト2.png");
	TextureData::Desc_txt3 = LoadGraph("res/説明テキスト3.png");
	TextureData::Desc_txt4 = LoadGraph("res/説明テキスト4.png");
	TextureData::Desc_txt5 = LoadGraph("res/説明テキスト5.png");



	TextureData::Desc_Desc = LoadGraph("res/テキストボックス.png");

	TextureData::Character1 = LoadGraph("res/インビジブルショット立ち絵.png");

	soundManager = SoundManager::GetInstance();
	soundManager->LoadSceneSound(SceneID_Description);
}

DescriptionScene::~DescriptionScene()
{
	TextureData::DeleteTex();
	soundManager->DeleteSceneSound(SceneID_Description);
}

void DescriptionScene::Exec()
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
		SceneManager::SetNextScene(SceneID_Title);
	}
}

void DescriptionScene::Draw()
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

		//画面左上にデバッグ用の文字を黒で表示する
	//DrawString(20, 20, "DescriptionScene", GetColor(0, 0, 0));
}

bool DescriptionScene::IsEnd() const
{
	if (IsKeyPushed(KEY_INPUT_ESCAPE))
	{
		TextureData::DeleteTex();
		return true;
	}
}