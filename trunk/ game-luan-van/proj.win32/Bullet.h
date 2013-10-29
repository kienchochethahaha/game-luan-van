#pragma once
#ifndef __Bullet_H__
#define __Bullet_H__

#include "cocos2d.h"

#include "CCGL.h"
#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include <stdio.h>     
#include <math.h>      
#include "Character.h"
using namespace cocos2d;
class Bullet : public MyObject
{
public:
	float m_Time_Count;
	CCPoint m_Start_Pos;
    float m_maxTimeLive;
	float m_timeLive;
	bool m_istarget;
	bool m_Col ;
	bool m_Active;
	CCPoint m_pos;
	CCPoint staringpoint;
	CCLayer* layer;
	CCSprite* m_bullet;
	CCPoint m_V;

	void setTarget(CCPoint);
	void update(float dt);
	void Collision(MyObject*,float  );
	void removeBullet ();
	Bullet(CCLayer*, CCPoint, float, float);
	~Bullet(void);

	virtual CCRect getRect();

};

#endif 

