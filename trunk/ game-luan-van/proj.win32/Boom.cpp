#include "Boom.h"

Boom::Boom(CCLayer* _layer, CCPoint _pos, float t, float max_V)
{
	m_Time_Count=0;
	m_Start_Pos=_pos;
	m_timeLive = 0;
	m_maxTimeLive = t; // thoi gian ton tai cua Boom cho den khi target
	m_istarget =false; // da co doi tuong hay chua
	m_Col = false;
	m_Active = false;
	m_maxVelocity = max_V; // speed of Boom
	layer = _layer;
	m_pos = _pos; // vi tri bat dau cua Boom
	m_V = CCPoint(0,0);
	m_target =  _pos;
	m_Boom = CCSprite::create("Bullet.png");
	m_Boom->setAnchorPoint(CCPoint(0.5,0.5));
	m_Boom->setPosition(m_pos);

	layer->addChild(m_Boom);
}




Boom::~Boom(void)
{
	this->removeAllChildrenWithCleanup(true);
}
void Boom:: setTarget(CCPoint _target)
{
	if (m_istarget ==false)
	{
		m_target = _target;
		m_istarget = true;
	}

}
void Boom::removeBoom()
{
	layer->removeChild(m_Boom);
}
void Boom ::Collision(MyObject*  _enemy, float dt)
{
	if (_enemy !=NULL)
		if( m_Boom->boundingBox().intersectsRect(_enemy->getRect()))
		{
			m_Col = true;
			CCLOG("trung roi nay ");
		}

}
void Boom ::update(float dt)
{
	if(m_Active ==true)
	{
		m_timeLive+=dt;
		if( m_timeLive >m_maxTimeLive)
		{
			m_Col = true;
		}
		m_Time_Count=m_timeLive*20;

		m_V = ccpNormalize( ccpSub(m_target,m_pos) );
		m_V =  ccpMult(m_V,m_maxVelocity);
		/*m_pos = ccpAdd(m_pos,m_V);*/
		float d=m_target.x-m_Start_Pos.x;
		float v=50;
		float  g=10;
		float asinanpha=float((d*g)/(v*v));
		double anpha=3.14/2- float(asin(asinanpha)/2);
		//anpha=3.14/2.1f;
		m_pos.x=m_Start_Pos.x+v*(float)cos(anpha)*m_Time_Count;
		m_pos.y=m_Start_Pos.y+v*sin(anpha)*m_Time_Count-g*m_Time_Count*m_Time_Count/2;
		m_Boom->setPosition(m_pos);
	}
}

cocos2d::CCRect Boom::getRect()
{
	throw std::exception("The method or operation is not implemented.");
}
