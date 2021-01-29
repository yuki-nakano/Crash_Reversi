#include "SceneBase.h"

int Player::Character1;
int Player::Character2;
int Player::Character3;
int Player::Character4;

int SceneBase::VolumePer;

int SceneBase::Choice_Min;
int SceneBase::Choice_Max;
int SceneBase::Choice;

int SceneBase::People_Max;

int SceneBase::Stage;

int SceneBase::back_posx1;
int SceneBase::back_posy1;
int SceneBase::back_posx2;
int SceneBase::back_posy2;
int SceneBase::back_posx3;
int SceneBase::back_posy3;
int SceneBase::back_posx4;
int SceneBase::back_posy4;
int SceneBase::back_posx5;
int SceneBase::back_posy5;
int SceneBase::back_posx6;
int SceneBase::back_posy6;

int SceneBase::scroll_speedx;
int SceneBase::scroll_speedy;

SceneBase::SceneBase()
	: m_Step(0)
{
	VolumePer = 50;
}

SceneBase::~SceneBase()
{
	
}
