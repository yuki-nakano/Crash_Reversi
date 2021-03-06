﻿#ifndef SCENEBASE_H
#define SCENEBASE_H

struct Player
{
public:
	int Character;
	//得点の保存にも使う予定

private:

};

//シーン基底クラス
class SceneBase
{
public:
	int m_Step = 0;
	static int VolumePer;

	static int Choice_Min;
	static int Choice_Max;
	static int Choice;

	static int People_Max;

	static int Stage;

	static float back_posx1;
	static float back_posy1;
	static float back_posx2;
	static float back_posy2;
	static float back_posx3;
	static float back_posy3;
	static float back_posx4;
	static float back_posy4;
	static float back_posx5;
	static float back_posy5;
	static float back_posx6;
	static float back_posy6;

	static float scroll_speedx;
	static float scroll_speedy;

	Player P1;
	Player P2;
	Player P3;
	Player P4;

	SceneBase();
	virtual ~SceneBase();

	//処理内容は派生クラス毎に違うので、
	//純粋仮想関数として宣言しておく
	virtual void Exec() = 0;	//処理を行う
	virtual void Draw() = 0;	//描画を行う

	virtual bool IsEnd() const = 0; //シーンが終了したかどうかを返す
};

//static Player P1;
//static Player P2;
//static Player P3;
//static Player P4;

#endif // !SCENEBASE_H
