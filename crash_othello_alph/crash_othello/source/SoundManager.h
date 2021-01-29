#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

//#include"common.h"
#include"Definition.h"

enum sound
{
	//タイトルシーン
	title,

	//説明シーン
	Description,

	//人数選択シーン
	SelectNumberOfPeople,

	//キャラクター選択シーン
	SelectCharacter,

	//ステージ選択シーン
	SelectStage,

	//プレイシーン
	Play,

	//カーソル移動
	Cursor,

	//キャンセル
	Cancel,

	//決定
	Enter,

	//シーン切り替え
	ChangeScene,

	//方向、ゲージ決定
	Play_Enter,

	//壁反射
	Reflection,

	//駒をひっくり返した時
	Reversible,

	//スキル発動
	Skill,

	//リザルト枚数表示
	Result,

	//勝者発表
	Winner,

	SoundMax
};

class SoundManager
{
private:
	SoundManager();
	static SoundManager* soundManager;

public:
	static void CreateInstance();
	static void DeleteInstance();

	static SoundManager* GetInstance() { return soundManager; };

	void LoadSceneSound(SceneID sceneid);

	void DeleteSceneSound(SceneID sceneid);

	int GetSoundData(int num);

	int Sound[SoundMax];

};

#endif // !SOUNDMANAGER_H
