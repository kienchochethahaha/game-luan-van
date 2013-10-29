#include "Canon.h"

Canon ::Canon()
{

}
Canon::Canon(CCLayer* _layer, CCPoint _m_pos)
{

	m_ID = ARCHER;
	m_choosedEnemy = NULL;
	m_maxVelocity = 3;
	layer = _layer;
	m_pos = _m_pos;
	m_SCanon = CCSprite::create("canon.png");

	m_SCanon->setAnchorPoint(CCPoint(0.5,0.5));
	m_SCanon->setPosition(m_pos);
	layer->addChild(m_SCanon);
	m_range = 80;
	m_coolDown = 1.5f;
	m_BoomManager = new BoomManager();


	m_circle = CCSprite::create("circle1.png");
	m_circle->setAnchorPoint(CCPoint(0.5,0.5));
	m_circle->setPosition(m_pos);
	layer->addChild(m_circle);
	m_circle->setOpacity(100);
	m_circle->setScale(1.5);
	//m_circle->setVisible(false);



}

Canon::~Canon(void)
{
	this->removeAllChildrenWithCleanup(true);
}
void Canon ::draw()
{
	glLineWidth(1);
	ccDrawColor4B(255, 255, 255, 255);
	cocos2d::ccDrawCircle( m_SCanon->getPosition(), m_range, CC_DEGREES_TO_RADIANS(90), 50, false);	
}
void Canon ::shoot(MyObject* m_enemy, float dt)
{
	CCPoint totarget =  ccpSub(m_enemy->m_pos, this->m_pos);
	float a = ccpDot(m_enemy->m_velocity,m_enemy->m_velocity) - (m_maxVelocity *m_maxVelocity);
	float b = 2 * ccpDot(m_enemy->m_velocity, totarget);
	float c = ccpDot(totarget,totarget);

	float p = -b / (2 * a);
	float q = (float)sqrt((b * b) - 4 * a * c) / (2 * a);

	float t1 = p - q;
	float t2 = p + q;
	float t;

	if (t1 > t2 && t2 > 0)
	{
		t = t2;
	}
	else
	{
		t = t1;
	}

	CCPoint aimSpot = ccpAdd(m_enemy->m_pos ,ccpMult(m_enemy->m_velocity,t)); //position of target in future after t seconds
	CCPoint BoomPath = ccpSub (aimSpot , m_pos );
	float timeToImpact = ccpLength(BoomPath) / m_maxVelocity/60; //speed must be in units per second


	m_BoomManager->addBoom(new Boom(layer, m_pos,timeToImpact,m_maxVelocity));

	for (int i =0; i < m_BoomManager->getListBoom().size(); i++)
	{
		m_BoomManager->getBoom(i)->setTarget(aimSpot);
		m_BoomManager->getBoom(i)->m_Active = true;
	}

}

void Canon ::update(float dt)
{
	m_BoomManager->update(dt);

	if( m_choosedEnemy!=NULL && m_choosedEnemy->m_Hp <=0 )
	{
		m_choosedEnemy=NULL;
		m_Collision =false;
	}

	if(m_choosedEnemy!=NULL && m_Collision  == true )
	{
		m_coolDown+=dt;

		if(m_coolDown >= 1.5 )
		{
			m_coolDown = 0;
			shoot(m_choosedEnemy,dt);
		}
	}

	if(m_choosedEnemy!=NULL && m_Collision  == true)
	{
		if(TestCollisionelip(m_choosedEnemy,m_circle)==false)
		{
			m_choosedEnemy = NULL;
			m_Collision = false;


		}
	}
	if(m_BoomManager->getListBoom().size() >0)
	{
		m_BoomManager->Collision(m_choosedEnemy,dt);
	}
}

void Canon ::Collision(MyObject* m_enemy, float dt) //character = monster
{


	if( m_circle->boundingBox().intersectsRect( m_enemy->getRect() ) ) //enemy collision Canon
	{
		if(TestCollisionelip(m_enemy,m_circle)==true)
		{
			if(m_choosedEnemy == NULL && m_Collision == false)
			{
				m_choosedEnemy =  m_enemy;
				m_Collision = true;
			}
		}

	}
}

cocos2d::CCRect Canon::getRect()
{
	return m_circle->boundingBox();
}
void Canon::isTouch(CCPoint _touch)
{
	if (this->getRect().containsPoint(_touch)==true)
	{
		m_circle->setVisible(true);
	}
	else{
		m_circle->setVisible(false);
	}
}

