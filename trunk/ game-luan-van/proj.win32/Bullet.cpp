#include "Bullet.h"

Bullet::Bullet(CCLayer* _layer, CCPoint _pos, float t)
{
	m_timeLive = 0;
	m_maxTimeLive = t;
	m_istarget =false;
	m_Col = false;
	m_Active = false;
	m_maxV = 3;
	layer = _layer;
	m_pos = _pos;
	m_V = CCPoint(0,0);
	m_target =  _pos;
	m_bullet = CCSprite::create("bullet.png");
	m_bullet->setAnchorPoint(CCPoint(0.5,0.5));
	m_bullet->setPosition(m_pos);
	
	layer->addChild(m_bullet);
}




Bullet::~Bullet(void)
{
	this->removeAllChildrenWithCleanup(true);
}
void Bullet:: setTarget(CCPoint _target)
{
	if (m_istarget ==false)
	{
		m_target = _target;
		m_istarget = true;
	}
	
}
void Bullet::removeBullet()
{
	layer->removeChild(m_bullet);
}
void Bullet ::Collision(MyObject*  _enemy)
{
// 	if( m_bullet->boundingBox().intersectsRect(_enemy->coin->boundingBox()))
// 	{
// 		m_Col = true;
// 		CCLOG("trung roi nay ");
// 	}
	
}
void Bullet ::update(float dt)
{
	
	if(m_Active ==true)
	{
		m_timeLive+=dt;
		if( m_timeLive >m_maxTimeLive)
		{
			m_Col = true;
		}

		m_V = ccpNormalize( ccpSub(m_target,m_pos) );
		m_V =  ccpMult(m_V,m_maxV);
		m_pos = ccpAdd(m_pos,m_V);
		m_bullet->setPosition(m_pos);


	}
	
}
