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

using namespace cocos2d;

class Bartrack : public Tower
{
public:
	
	CCSprite* m_bartrack;
	CCSprite* m_circleUpgrade;
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