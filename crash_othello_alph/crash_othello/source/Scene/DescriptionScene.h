#ifndef DESCRIPTIONSCENE_H
#define DESCRIPTIONSCENE_H

#include"../common.h"

class DescriptionScene : public SceneBase
{
public:
	DescriptionScene();
	~DescriptionScene();
public:
	void Exec();
	void Draw();

	virtual bool IsEnd() const; //シーンが終了したかどうかを返す

	SoundManager* soundManager = nullptr;
};

#endif // !DESCRIPTIONSCENE_H