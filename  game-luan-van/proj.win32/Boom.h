#pragma once
#ifndef __Boom_H__
#define __Boom_H__
#include "cocos2d.h"

#include "CCGL.h"
#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include <stdio.h>     
#include <math.h>      
#include "Character.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "Global.h"
using namespace cocos2d;
class Boom : public cocos2d ::CCNode
{
public:
	float m_t0 ;
	float m_t1 ;


	CCLayer* layer;
	CCSprite* m_bullet;
	float m_maxV;
	CCPoint m_target;
	CCPoint m_pos;
	CCPoint m_V;
	CCPoint m_start;
	float angle;
	float distance;
	float x;
	float y;

	Boom(CCLayer*, CCPoint);
	Boom(void);
	~Boom(void);
	CCPoint canculateFiringSolution();
	void update(float dt);
};
#endif
