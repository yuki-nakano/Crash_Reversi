#include "common.h"

SoundManager* SoundManager::soundManager = nullptr;

SoundManager::SoundManager()
{
}

void SoundManager::CreateInstance()
{
	if (soundManager == nullptr)
	{
		soundManager = new SoundManager();
	}
}

void SoundManager::DeleteInstance()
{
	delete soundManager;
	soundManager = nullptr;
}

void SoundManager::LoadSceneSound(SceneID sceneid)
{
	switch (sceneid)
	{
	case SceneID_Title:

		Sound[title] = LoadSoundMem("res/Sound/タイトルからキャラ選択まで.mp3");
		Sound[Cursor] = LoadSoundMem("res/Sound/カーソル移動.mp3");
		Sound[Enter] = LoadSoundMem("res/Sound/決定.mp3");
		Sound[Cancel] = LoadSoundMem("res/Sound/キャンセル.mp3");
		Sound[ChangeScene] = LoadSoundMem("res/Sound/シーン切り替え.mp3");

		break;
	case SceneID_Description:

		Sound[Description] = LoadSoundMem("res/Sound/タイトルからキャラ選択まで.mp3");
		Sound[Cursor] = LoadSoundMem("res/Sound/カーソル移動.mp3");
		Sound[Enter] = LoadSoundMem("res/Sound/決定.mp3");
		Sound[Cancel] = LoadSoundMem("res/Sound/キャンセル.mp3");
		Sound[ChangeScene] = LoadSoundMem("res/Sound/シーン切り替え.mp3");

		break;
	case SceneID_SelectNumberOfPeople:

		Sound[SelectNumberOfPeople] = LoadSoundMem("res/Sound/タイトルからキャラ選択まで.mp3");
		Sound[Cursor] = LoadSoundMem("res/Sound/カーソル移動.mp3");
		Sound[Enter] = LoadSoundMem("res/Sound/決定.mp3");
		Sound[Cancel] = LoadSoundMem("res/Sound/キャンセル.mp3");
		Sound[ChangeScene] = LoadSoundMem("res/Sound/シーン切り替え.mp3");

		break;
	case SceneID_SelectCharacter:

		Sound[SelectCharacter] = LoadSoundMem("res/Sound/タイトルからキャラ選択まで.mp3");
		Sound[Cursor] = LoadSoundMem("res/Sound/カーソル移動.mp3");
		Sound[Enter] = LoadSoundMem("res/Sound/決定.mp3");
		Sound[Cancel] = LoadSoundMem("res/Sound/キャンセル.mp3");
		Sound[ChangeScene] = LoadSoundMem("res/Sound/シーン切り替え.mp3");

		break;
	case SceneID_Play:

		Sound[Play] = LoadSoundMem("res/Sound/メインゲーム画面.mp3");
		Sound[Play_Enter] = LoadSoundMem("res/Sound/方向、ゲージ決定.mp3");;
		Sound[Reflection] - LoadSoundMem("res/Sound/壁反射.mp3");;
		Sound[Reversible] = LoadSoundMem("res/Sound/コマをひっくり返したとき.mp3");;
		Sound[Skill] = LoadSoundMem("res/Sound/スキル発動.mp3");;
		Sound[Result] = LoadSoundMem("res/Sound/リザルト枚数表示.mp3");;
		Sound[Winner] = LoadSoundMem("res/Sound/1位の勝利.mp3");;

		break;
	default:
		break;
	}

	for (int i = 0; i < SoundMax; i++)
	{
		ChangeVolumeSoundMem(255 * SceneBase::VolumePer / 100, Sound[i]);
	}
}

void SoundManager::DeleteSceneSound(SceneID sceneid)
{
	for (int i = 0; i < SoundMax; i++)
	{
		if (i == title || i == Play)
		{
			continue;
		}

		DeleteSoundMem(Sound[i]);
	}
}

int SoundManager::GetSoundData(int num)
{
	return Sound[num];
}