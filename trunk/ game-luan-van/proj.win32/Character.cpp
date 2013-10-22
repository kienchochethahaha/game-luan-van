#include "Character.h"


Character::Character(CCLayer* _layer, Path* _path, CCPoint _pos)
{

	path = _path;
	currentNode = 0;
	nodes = path->getNodes(); //get path
	m_pos = _pos;

	m_velocity = CCPoint(-1,-1);
	m_desiredV = CCPoint (0,0);
	m_steeringV = CCPoint (0,0);
	m_targetPosition = nodes->at(currentNode); //get target
	
	
	m_maxVelocity = 0.85;
	max_force = m_maxVelocity*3;
	mass = 0.05;
	layer = _layer;

	coin = CCSprite::create("coint.png");
	coin->setPosition(ccp(m_pos.x,m_pos.y));
	coin->setScale(0.4);
	coin->setTag(1);
	
	layer->addChild(coin);
	
}


Character::~Character(void)
{
	this->removeAllChildrenWithCleanup(true);
}
void Character::update(float dt)
{
	  ///	m_steeringV = seek(m_targetPosition);

	    m_steeringV = pathFollowing();
	  	m_steeringV = truncate(m_steeringV,max_force);
	  	m_steeringV =  ccpMult(m_steeringV, mass);
	 
	 	m_velocity = ccpAdd(m_velocity,m_steeringV);
	 	m_velocity = truncate(m_velocity,m_maxVelocity); //vector velocity of character -> target of tower

	    m_pos.x = m_pos.x + m_velocity.x;
		m_pos.y = m_pos.y + m_velocity.y;

	 	coin->setPosition(m_pos);
}
CCPoint Character::pathFollowing()
{
	if(path!=NULL)
	{
		m_targetPosition = nodes->at(currentNode);  
		if(Distance(this->coin,m_targetPosition) <= path->getRadisPath())
		{
			currentNode +=1;
			if(currentNode >=nodes->size() ){
				
				currentNode = nodes->size() -1;
			}
		}
	
	}
		return seek(m_targetPosition) ;
}
float Character::Distance(CCSprite* a, CCPoint b)
{
	return sqrt((a->getPositionX() - b.x) * (a->getPositionX() - b.x)  + (a->getPositionY() - b.y) * (a->getPositionY() - b.y));
}

CCPoint Character::seek(CCPoint target) //return steering vecto
{
	m_desiredV = ccpSub(m_targetPosition, coin->getPosition());
	m_desiredV = ccpNormalize(m_desiredV);
	m_desiredV = ccpMult(m_desiredV,m_maxVelocity);
	return ccpSub(m_desiredV, m_velocity);
}
CCPoint Character::truncate(CCPoint vector, float max)
{
	float i = ccpLength(vector)/ max ;
	i = i<1.0 ? 1.0 :1/i;
	return ccpMult(vector,i);
}

CCRect Character:: getRect ()
{
	return coin->boundingBox() ;
}

void Character::Collision( MyObject* ,float )
{
	
}
