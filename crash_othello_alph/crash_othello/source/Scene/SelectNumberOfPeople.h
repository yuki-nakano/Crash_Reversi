#ifndef SELECTNUMBEROFPEOPLE_H
#define SELECTNUMBEROFPEOPLE_H

#include "../common.h"

class SelectNumberOfPeopleScene : public SceneBase
{
public:
	SelectNumberOfPeopleScene();
	virtual ~SelectNumberOfPeopleScene();
public:
	void Exec();
	void Draw();

	virtual bool IsEnd() const; //シーンが終了したかどうかを返す

	SoundManager* soundManager = nullptr;
};

#endif // !SELECTNUMBEROFPEOPLE_H
