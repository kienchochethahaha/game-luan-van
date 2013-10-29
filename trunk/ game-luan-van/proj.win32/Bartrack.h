#pragma once
#ifndef __Bartrack_H__
#define __Bartrack_H__
#include "cocos2d.h"

#include "CCGL.h"
#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include <stdio.h>     
#include <math.h>      
#include "Tower.h"
#include "SoliderManager.h"

using namespace cocos2d;

class Bartrack : public Tower
{
public:
	
	CCPoint m_PointRally;
	bool m_Move;
	SoliderManager* m_soliderManager;

	CCSprite* m_bartrack;
	CCSprite* m_circleUpgrade;
	CCSprite* m_circle;
	CCSprite* m_circleCollision;
	CCSprite* m_Flag;
	
	CCLayer* m_layer;


	 Bartrack();
     Bartrack (CCLayer*, CCPoint);
	~Bartrack(void);

	
	virtual void update( float dt );
	virtual void Collision( MyObject* ,float );
	virtual CCRect getRect();
	virtual void draw();
	virtual void isTouch(CCPoint);

};
#endif