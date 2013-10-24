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

}

Bartrack::~Bartrack(void)
{
}

void Bartrack::update( float dt )
{
	
}

void Bartrack::Collision( MyObject* _object,float dt)
{
	
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
	if (this->getRect().containsPoint(_touch)==true)
	{
		m_circleUpgrade->setVisible(true);
	}
	else{
		m_circleUpgrade->setVisible(false);
	}
}

