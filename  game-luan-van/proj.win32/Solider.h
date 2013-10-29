#pragma once
#ifndef __Solider_H__
#define __Solider_H__
#include "cocos2d.h"


#include "SimpleAudioEngine.h"
#include <stdio.h>     
#include <math.h>      
#include "MyObject.h"
#include "Global.h"

using namespace cocos2d;
class Solider : public MyObject
{

private:

	//su dung cho viec thay doi animation - k co gi nua het'
	bool m_stand;
	bool m_attack;
	bool m_move;


	MyObject* m_choosedEnemy;
public:

	bool m_moveByFlag; // di chuyen su dung rally point (flag) khi di chuyen = cai nay thi k xet va cham vs quai' va tha cho doi tuong dang danh luon
	bool isTarget;
	float timeMove;
	float timeFinishMove;
    //animation, sprite layer...
	CCSpriteBatchNode* m_batchNode;
    CCSpriteFrameCache* m_frameCache;
	CCLayer* m_layer;
	CCSprite* m_Solider;
	CCSprite* m_circleColision;

	//actions
	CCAction* m_actionStand;
	CCAction* m_actionMove;
	CCAction* m_actionAttack;
	CCArray* m_arrayAction;


	Solider (CCLayer*, CCPoint, CCPoint);
	Solider(void);
	~Solider(void);

	void Init();
	void setTarget (CCPoint);
	void Move( CCPoint, float, float);
	virtual void update( float dt );

	virtual void Collision( MyObject* ,float );

	virtual CCRect getRect();



};

#endif

