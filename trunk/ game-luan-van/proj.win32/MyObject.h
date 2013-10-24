#pragma once
#ifndef __MyObject_H__
#define __MyObject_H__

#include "cocos2d.h"
using namespace cocos2d;
using namespace std;


class MyObject  : public cocos2d::CCNode
{
public:

	//id of object
	int m_ID;

	//hp
	float m_Hp;
	// Damage
	float m_Damage;
	//armor
	float m_Armor;
	//speed of bullet and monster
	float m_maxVelocity; 
	
	//collision between tower and enemy
	bool m_Collision;

	// Direct move X
	float m_DirectX;

	CCSprite* m_Sprite;

	//velocity
	CCPoint m_velocity; 

	//position
	CCPoint m_pos;

	//cooldown - shoot tower, respawn time
	float m_coolDown;


	virtual void Collision (MyObject* ,float) = 0 ;
	virtual void update(float dt) =0;
	virtual CCRect getRect()=0;
	virtual void isTouch(CCPoint);


	MyObject(void);
	~MyObject(void);
};
#endif

