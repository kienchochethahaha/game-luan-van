#include "Tower.h"

Tower ::Tower()
{

}
Tower::Tower(CCLayer* _layer, CCPoint _m_pos)
{

	m_ID = ARCHER;
	m_choosedEnemy = NULL;
	m_maxVelocity = 3;
	layer = _layer;
	m_pos = _m_pos;
	m_Stower = CCSprite::create("tower.png");
	
	m_Stower->setAnchorPoint(CCPoint(0.5,0.5));
	m_Stower->setPosition(m_pos);
	layer->addChild(m_Stower);
	m_range = 80;
	m_coolDown = 1.5f;
	m_bulletManager = new BulletManager();
	

	m_circle = CCSprite::create("circle1.png");
	m_circle->setAnchorPoint(CCPoint(0.5,0.5));
	m_circle->setPosition(m_pos);
	layer->addChild(m_circle);
	m_circle->setOpacity(100);
	m_circle->setScale(1.5);
	//m_circle->setVisible(false);
	

	
}

Tower::~Tower(void)
{
	this->removeAllChildrenWithCleanup(true);
}
void Tower ::draw()
{
	glLineWidth(1);
	ccDrawColor4B(255, 255, 255, 255);
	cocos2d::ccDrawCircle( m_Stower->getPosition(), m_range, CC_DEGREES_TO_RADIANS(90), 50, false);	
}
void Tower ::shoot(MyObject* m_enemy, float dt)
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
	CCPoint bulletPath = ccpSub (aimSpot , m_pos );
	float timeToImpact = ccpLength(bulletPath) / m_maxVelocity/60; //speed must be in units per second
	

	m_bulletManager->addBullet(new Bullet(layer, m_pos,timeToImpact,m_maxVelocity));

	for (int i =0; i < m_bulletManager->getListBullet().size(); i++)
	{
		m_bulletManager->getBullet(i)->setTarget(aimSpot);
		m_bulletManager->getBullet(i)->m_Active = true;
	}
	  
}

void Tower ::update(float dt)
{
	m_bulletManager->update(dt);

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
	if(m_bulletManager->getListBullet().size() >0)
	{
		m_bulletManager->Collision(m_choosedEnemy,dt);
	}
}

void Tower ::Collision(MyObject* m_enemy, float dt) //character = monster
{


	if( m_circle->boundingBox().intersectsRect( m_enemy->getRect() ) ) //enemy collision tower
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

cocos2d::CCRect Tower::getRect()
{
	return m_circle->boundingBox();
}
void Tower::isTouch(CCPoint _touch)
{
	if (this->getRect().containsPoint(_touch)==true)
	{
		m_circle->setVisible(true);
	}
	else{
		m_circle->setVisible(false);
	}
}

