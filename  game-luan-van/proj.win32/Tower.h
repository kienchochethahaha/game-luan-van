#pragma once
#ifndef __Tower_H__
#define __Tower_H__
#include "cocos2d.h"

#include "CCGL.h"
#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include <stdio.h>     
#include <math.h>      
#include "Character.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "MyObject.h"
#include "Global.h"

using namespace cocos2d;
class Tower : public MyObject
{
protected:
	MyObject* m_choosedEnemy; //target to shoot
public:

	CCSprite* m_circle;
	BulletManager* m_bulletManager;
	CCSprite* m_Stower;
    CCLayer* layer;
	float m_range;
	
	void shoot(MyObject*,float);
	virtual void Collision(MyObject*, float );
	virtual void update (float dt);
	
    virtual void draw();
	virtual void isTouch(CCPoint);

	Tower();
	Tower(CCLayer*,CCPoint);
	~Tower(void);

	virtual CCRect getRect();
	bool TestCollisionelip(MyObject* m_enemy);
};
#endif

