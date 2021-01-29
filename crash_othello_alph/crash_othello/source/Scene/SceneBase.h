#ifndef SCENEBASE_H
#define SCENEBASE_H

struct Player
{
public:
	static int Character1;
	static int Character2;
	static int Character3;
	static int Character4;

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

	static int back_posx1;
	static int back_posy1;
	static int back_posx2;
	static int back_posy2;
	static int back_posx3;
	static int back_posy3;
	static int back_posx4;
	static int back_posy4;
	static int back_posx5;
	static int back_posy5;
	static int back_posx6;
	static int back_posy6;

	static int scroll_speedx;
	static int scroll_speedy;

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
