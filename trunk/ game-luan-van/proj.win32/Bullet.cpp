#include "Bullet.h"

Bullet::Bullet(CCLayer* _layer, CCPoint _pos, float t, float max_V)
{
	m_timeLive = 0;
	m_maxTimeLive = t; // thoi gian ton tai cua bullet cho den khi target
	m_istarget =false; // da co doi tuong hay chua
	m_Col = false;
	m_Active = false;
	m_maxVelocity = max_V; // speed of bullet
	layer = _layer;
	m_pos = _pos; // vi tri bat dau cua bullet
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
void Bullet ::Collision(MyObject*  _enemy, float dt)
{
	if (_enemy !=NULL)
	if( m_bullet->boundingBox().intersectsRect(_enemy->getRect()))
	{
		m_Col = true;
		CCLOG("trung roi nay ");
	}
	
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
		m_V =  ccpMult(m_V,m_maxVelocity);
		m_pos = ccpAdd(m_pos,m_V);
		m_bullet->setPosition(m_pos);
	}
}

cocos2d::CCRect Bullet::getRect()
{
	throw std::exception("The method or operation is not implemented.");
}
