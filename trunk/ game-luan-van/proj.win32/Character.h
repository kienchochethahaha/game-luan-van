#pragma once

#ifndef __Character_H__
#define __Character_H__
#include "cocos2d.h"

#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include <stdio.h>     
#include <math.h>      
#include "Path.h"
#include "MyObject.h"

using namespace cocos2d;
class Character : public MyObject
{
public:

	CCLayer* layer;
	CCSprite* coin;

	Path* path;
	std::vector<CCPoint>* nodes;

	// Node dang huong' toi'
	int currentNode ;

	// position and target postion
	CCPoint m_targetPosition;

	//velocity
	CCPoint m_desiredV;
	CCPoint m_steeringV;

	//force
	float max_force;

	//max velocity of character
	float maxVelocity;
	float mass;

	CCPoint pathFollowing();
	CCPoint seek (CCPoint );
	CCPoint truncate(CCPoint, float);
	CCPoint getAngle(CCPoint vector);

	float Distance (CCSprite*, CCPoint);

	

    virtual CCRect getRect ();


	Character(CCLayer*, Path*, CCPoint );
	~Character(void);

	virtual void Collision( MyObject* ,float );

	virtual void update( float dt );

};

#endif  // __Path_H__
