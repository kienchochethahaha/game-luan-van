#include "Boom.h"


Boom::Boom(CCLayer* _layer, CCPoint _pos)
{
	 m_t0 = 0;
	 m_t1 = 17;

	layer = _layer;
	m_V = CCPoint(0,0);
	m_maxV = 50;
	m_target = CCPoint(600,200);
	m_pos = _pos; //200 200
	m_start = _pos;
	m_bullet = CCSprite::create("bullet.png");
	m_bullet->setAnchorPoint(CCPoint(0.5,0.5));
	m_bullet->setPosition(m_pos);
	m_bullet->setScale(2);
	layer->addChild(m_bullet);

	 x = m_target.x - m_start.x;
	

	 y = m_target.y - m_start.y;

    distance = sqrt (x*x + y*y);
	
	float tu = (m_maxV* m_maxV) + sqrt( m_maxV*m_maxV*m_maxV*m_maxV + GRAVITY* (GRAVITY* (x*x) + 2*y* (m_maxV*m_maxV) ) );
	
	float mau = GRAVITY*x ;
	float kq = tu/mau;

	angle = atan(kq); //in radians
	angle = CC_RADIANS_TO_DEGREES(angle);
	CCLog("angle is %f",sin(angle));

	m_bullet->runAction(CCJumpTo::create(1,m_target, 200,1));
	

// 	m_V.x = x / m_t1;
// 	m_V.y = (y - 1/2 * GRAVITY* m_t1 *m_t1)/ m_t1;
}
Boom::Boom(void)
{
}


Boom::~Boom(void)
{
}
void Boom::update(float dt)
{
// 	m_t0 +=0.0001;
// 	m_pos.x =  m_pos.x + m_maxV* -cos(angle) * m_t0;
// 
// 	//CCLog("cos is %f", cos(angle));
// 	m_pos.y = m_pos.y + (m_maxV*sin(angle)*m_t0) - (GRAVITY*m_t0*m_t0)/2;
// 
// 	m_bullet->setPosition(m_pos);
// 	
// 
// 	CCLog("(%f, %f)", m_pos.x, m_pos.y );

// 	if (m_t0 <= m_t1)
// 	{
// 		m_t0 +=dt;
// 		m_pos.x = m_pos.x + m_V.x * m_t0;
// 		m_pos.y = 1/2 * GRAVITY* m_t0* m_t0 + m_V.y* m_t0 + m_pos.y ;
// 
// 		m_bullet->setPosition(m_pos);
// 
// 	}

}
