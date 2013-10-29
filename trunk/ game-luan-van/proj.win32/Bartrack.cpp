#include "Bartrack.h"

Bartrack :: Bartrack()
{

}
Bartrack::Bartrack(CCLayer* _layer, CCPoint _pos)
{
	m_layer = _layer;
	m_pos = _pos;
	m_ID = BARTRACK;

	m_bartrack = CCSprite::create("Bartrack.png");
	m_bartrack->setPosition(m_pos);
	m_layer->addChild(m_bartrack);

	m_circleUpgrade = CCSprite::create("circle_bartrack.png");
	m_circleUpgrade->setPosition(m_pos);
	m_layer->addChild(m_circleUpgrade);
	m_circleUpgrade->setVisible(false);

	m_circle = CCSprite::create("circle1.png");
	m_circle->setPosition(m_pos);
	m_circle->setOpacity(0); 
	m_layer->addChild(m_circle);

	m_circleCollision = CCSprite::create("circle1.png");
	m_circleCollision->setPosition(m_pos);
	m_circleCollision->setScale(1.5);
	m_circleCollision->setOpacity(0);
	m_layer->addChild(m_circleCollision);

	m_Flag = CCSprite::create("RallyPoint.png");
	m_Flag->setPosition(CCPoint (m_pos.x + 60, m_pos.y - 55 ));
	m_Flag->setOpacity(0);
	m_layer->addChild(m_Flag);

	
	m_soliderManager = new SoliderManager();
	m_soliderManager->addSolider(new Solider(m_layer,m_pos,CCPoint(m_pos.x + 30 , m_pos.y - 70) ));
 	m_soliderManager->addSolider(new Solider(m_layer,m_pos,CCPoint(m_pos.x  - 30, m_pos.y - 70) ));
// 	m_soliderManager->addSolider(new Solider(m_layer,m_pos,CCPoint(m_pos.x + 2 , m_pos.y - 100) ));
	m_Move = false;
	m_PointRally = CCPoint(0,0);

}

Bartrack::~Bartrack(void)
{
}

void Bartrack::update( float dt )
{
	m_soliderManager->update(dt);
	
}

void Bartrack::Collision( MyObject* _object,float dt)
{
	m_soliderManager->Collision(_object, dt);
}

CCRect Bartrack::getRect()
{
	return m_bartrack->boundingBox();
}

void Bartrack::draw()
{

}

void Bartrack::isTouch(CCPoint _touch)
{
	if(m_circle->getOpacity()==100)
	{
		m_soliderManager->setMoveByFlag();
		m_circle->setOpacity(0);
		m_soliderManager->Move(_touch);
	}
	if (this->getRect().containsPoint(_touch)==true && m_Flag->getOpacity()==0)
	{
		m_circleUpgrade->setVisible(true);
		m_Flag->setOpacity(255);
	}
	else if ( this->getRect().containsPoint(_touch)==true && m_Flag->getOpacity()==255)
	{
		m_circleUpgrade->setVisible(false);
		m_Flag->setOpacity(0);
	}

	else if (this->getRect().containsPoint(_touch) ==false ) 
	{

		m_circleUpgrade->setVisible(false);
	
		if(m_Flag->boundingBox().containsPoint(_touch) && m_Flag->getOpacity() ==255)
		{
			m_Flag->setOpacity(0);
			if(m_circle->getOpacity()==0)
			{
				m_circle->setOpacity(100);
			}
		}
		if(m_Flag->getOpacity() ==255) 
		{
				m_Flag->setOpacity(0);
		}
				
	}
}

