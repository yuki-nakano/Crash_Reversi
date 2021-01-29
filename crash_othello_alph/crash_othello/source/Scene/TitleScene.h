#ifndef TITLESCENE_H
#define TITLESCENE_H

#include "../common.h"

class TitleScene : public SceneBase
{
public:
	TitleScene();
	~TitleScene();
public:
	void Exec();
	void Draw();

	virtual bool IsEnd() const; //シーンが終了したかどうかを返す

private:
	bool description_scene = false;
	bool nextScene = false;

	SoundManager* soundManager = nullptr;
};

#endif // !TITLESCENE_H