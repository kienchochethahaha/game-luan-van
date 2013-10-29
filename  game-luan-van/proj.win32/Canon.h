#pragma once
#ifndef __Canon_H__
#define __Canon_H__
#include "cocos2d.h"

#include "CCGL.h"
#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include <stdio.h>     
#include <math.h>      
#include "Character.h"
#include "Boom.h"
#include "BoomManager.h"
#include "MyObject.h"
#include "Global.h"

using namespace cocos2d;
class Canon : public MyObject
{
protected:
	MyObject* m_choosedEnemy; //target to shoot
public:

	CCSprite* m_circle;
	BoomManager* m_BoomManager;
	CCSprite* m_SCanon;
	CCLayer* layer;
	float m_range;

	void shoot(MyObject*,float);
	virtual void Collision(MyObject*, float );
	virtual void update (float dt);

	virtual void draw();
	virtual void isTouch(CCPoint);

	Canon();
	Canon(CCLayer*,CCPoint);
	~Canon(void);

	virtual CCRect getRect();

};
#endif

