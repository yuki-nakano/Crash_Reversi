#ifndef DEFINITION_H
#define DEFINITION_H

const int Widht = 1280;
const int Height = 720;

const int MaxPiece = 64;

const int row = 8;
const int col = 8;

enum Color
{
	kRed,
	kBlue,
	kBlack,
	kWhite,
	kBlank,
};

enum SceneID
{
	//! タイトルシーン
	SceneID_Title,
	//! 説明シーン
	SceneID_Description,
	//! 人数選択シーン
	SceneID_SelectNumberOfPeople,
	//! キャラクター選択シーン
	SceneID_SelectCharacter,
	//!	ステージ選択シーン
	SceneID_SelectStage,
	//! プレイシーン
	SceneID_Play,

	
	SceneID_Max,
	SceneID_Invalid,	//無効値
};

#endif // !DEFINITION_H
