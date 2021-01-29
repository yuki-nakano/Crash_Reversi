#include "../common.h"

//デバッグ用
//#define DEBUG

TitleScene::TitleScene()
{

	SceneBase::Choice_Min = 1;
	SceneBase::Choice_Max = 2;

	//	  4, 5, 6
	// 1, 2, 3
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

	//画像の読み込み
	TextureData::Title = LoadGraph("res/タイトルロゴ2.png");
	TextureData::BackGround_BLUE = LoadGraph("res/haikei.png");
	TextureData::Button_Start = LoadGraph("res/タイトルボタン_スタート.png");
	TextureData::Button_Rule = LoadGraph("res/タイトルボタン_ルール.png");

	SceneBase::Choice = 0;

	soundManager = SoundManager::GetInstance();
	soundManager->LoadSceneSound(SceneID_Title);

	StopSoundMem(soundManager->GetSoundData(sound::title));
	PlaySoundMem(soundManager->GetSoundData(sound::title), DX_PLAYTYPE_LOOP, FALSE);
}

TitleScene::~TitleScene()
{
	TextureData::DeleteTex();
	//soundManager->DeleteSceneSound(SceneID_Title);
}

void TitleScene::Exec()
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
#ifdef DEBUG
	if (Choice == 1 && IsKeyPushed(KEY_INPUT_RETURN))
	{
		PlaySoundMem(soundManager->GetSoundData(sound::ChangeScene), DX_PLAYTYPE_NORMAL, TRUE);
		SceneManager::SetNextScene(SceneID_Play);
	}
	else if (Choice == 2 && IsKeyPushed(KEY_INPUT_RETURN))
	{
		PlaySoundMem(soundManager->GetSoundData(sound::ChangeScene), DX_PLAYTYPE_NORMAL, TRUE);
		SceneManager::SetNextScene(SceneID_Description);
	}
#else
	if (Choice == 1 && IsKeyPushed(KEY_INPUT_RETURN))
	{
		PlaySoundMem(soundManager->GetSoundData(sound::ChangeScene), DX_PLAYTYPE_NORMAL, TRUE);
		SceneManager::SetNextScene(SceneID_SelectNumberOfPeople);
	}
	else if (Choice == 2 && IsKeyPushed(KEY_INPUT_RETURN))
	{
		PlaySoundMem(soundManager->GetSoundData(sound::ChangeScene), DX_PLAYTYPE_NORMAL, TRUE);
		SceneManager::SetNextScene(SceneID_Description);
	}
#endif
	
}

void TitleScene::Draw()
{
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
		//画面左上にデバッグ用の文字を黒で表示する
	//DrawString(20, 20, "TitleScene", GetColor(0, 0, 0));
}

bool TitleScene::IsEnd() const
{
		return (IsKeyPushed(KEY_INPUT_RETURN) && Choice != 0);
}