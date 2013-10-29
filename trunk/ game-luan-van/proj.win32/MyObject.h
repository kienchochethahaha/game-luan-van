#pragma once
#ifndef __MyObject_H__
#define __MyObject_H__

#include "cocos2d.h"
using namespace cocos2d;
using namespace std;


class MyObject  : public cocos2d::CCNode
{
public:
	// define life of object
	bool m_iLife;

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
	CCPoint m_targetPos;

	//cooldown - shoot tower, respawn time
	float m_coolDown;

	//number solider is attacking this enemy
	int m_countAttack;

	bool getLife()
	{
		return m_iLife ;
	}
	virtual bool TestCollisionelip(MyObject* m_enemy, CCSprite* circle);
	virtual void Collision (MyObject* ,float) = 0 ;
	virtual void update(float dt) =0;
	virtual CCRect getRect()=0;
	virtual void release();
	virtual void isTouch(CCPoint);


	MyObject(void);
	~MyObject(void);
};
#endif

