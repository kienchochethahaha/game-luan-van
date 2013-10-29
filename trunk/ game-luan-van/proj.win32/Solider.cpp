#include "Solider.h"

Solider::Solider()
{

}
Solider::Solider (CCLayer* _layer, CCPoint _pos, CCPoint _target)
{
	m_stand = false;
	m_attack = false;
	m_move = false;
	isTarget = false; // co' doi' tuong. hay chua
	m_moveByFlag = false;

	m_countAttack= 0; // doi' tuong cua minh bi bao nhieu solider attack

	m_choosedEnemy = NULL;
	timeMove = 0;
	m_maxVelocity = 1; // speed of bullet
	m_layer = _layer;
	m_pos = _pos; // vi tri bat dau cua bullet
	m_velocity = CCPoint(0,0);
	m_targetPos =  _target;
	m_ID = MOVE;

	m_circleColision = CCSprite::create("circle1.png");
	m_circleColision->setPosition(m_pos);
	m_circleColision->setScale(0.5);
	m_circleColision->setOpacity(0);
	m_layer->addChild(m_circleColision);

	Init();
	
}

Solider::~Solider(void)
{
}

void Solider::Init()
{
	m_frameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
	m_frameCache->addSpriteFramesWithFile("Solider.plist");

	m_batchNode = CCSpriteBatchNode::create("Solider.png");
	m_Solider = CCSprite::createWithSpriteFrameName("attack_0.png");
	m_Solider->setPosition(m_pos);

	m_batchNode->addChild(m_Solider);

	m_layer->addChild(m_batchNode);


	m_arrayAction = CCArray ::createWithCapacity(3);
	m_arrayAction->retain();

	CCArray *idleAnimFrames = CCArray::createWithCapacity(2);
	idleAnimFrames->retain();
	for(int i = 0 ;i < 2 ;i++)
	{
		CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("stand_%d.png",i)->getCString());
		idleAnimFrames->addObject(frame);

	}
	CCAnimation *idleAnimation = CCAnimation ::createWithSpriteFrames(idleAnimFrames,float(1.0/5.0)) ;

	//move animation
	CCArray *moveAnimFrames = CCArray::createWithCapacity(10);
	moveAnimFrames->retain();
	for(int i = 0 ;i < 8 ;i++)
	{
		CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("move_%d.png",i)->getCString());
		moveAnimFrames->addObject(frame);

	}
	CCAnimation* moveAnimation = CCAnimation ::createWithSpriteFrames(moveAnimFrames,float(1.0/12.0)) ;

	//attack animation
	CCArray *attackAnimFrames = CCArray::createWithCapacity(10);
	attackAnimFrames->retain();
	for(int i = 0 ;i < 7 ;i++)
	{
		CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("attack_%d.png",i)->getCString());
		attackAnimFrames->addObject(frame);

	}
	CCAnimation* attackAnimation = CCAnimation ::createWithSpriteFrames(attackAnimFrames,float(1.0/12.0)) ;


	this->m_actionStand = CCRepeatForever::create(CCAnimate::create(idleAnimation));
	this->m_actionStand->retain();
	m_arrayAction->addObject(m_actionStand);


	this->m_actionMove =  CCRepeatForever::create(CCAnimate::create(moveAnimation));
	this->m_actionMove->retain();
	m_arrayAction->addObject(m_actionMove);

	this->m_actionAttack =  CCRepeatForever::create(CCAnimate::create(attackAnimation));
	this->m_actionAttack->retain();
	m_arrayAction->addObject(m_actionAttack);

	m_Solider->setScale(0.3);

	m_Solider->runAction(m_actionMove);

	timeFinishMove = ccpLength(ccpSub(m_targetPos, m_pos))/ m_maxVelocity/60;
	CCLOG("timefinishMove is : %f", timeFinishMove);
}
void Solider::update( float dt )
{
	///CCLog("m_coutAttack is :%d", m_countAttack);
	if( m_choosedEnemy!=NULL && m_choosedEnemy->m_Hp <=0 )
	{
		m_choosedEnemy=NULL;
		isTarget = false ;
	}
	if (m_ID == MOVE) // THAY DOI ANIMATION SANG MOVE
	{
		m_stand = false;
		if(m_move == false)
		{
			m_Solider->stopAllActions();
			m_Solider->runAction(m_actionMove);
			m_move = true;
		}
	}
    if (m_ID == STAND) // THAY DOI ANIMATION SANG DUNG' YEN
	{
		m_move = false;
		if(m_stand == false)
		{
			m_Solider->stopAction(m_actionMove);
			m_Solider->runAction(m_actionStand);
			m_stand = true;
		}
		
	}

	m_circleColision->setPosition(m_pos);
	if( m_targetPos.x - m_pos.x > 0)
	{
		m_Solider->setScaleX(-0.3);
	}
	else 
	{
		m_Solider->setScaleX(0.3);
	}

    Move( m_targetPos, timeFinishMove,dt);
}
void Solider::Move( CCPoint target, float _t, float dt)
{
	if(m_ID == MOVE)
	{
		timeMove +=dt;
		if(timeMove >= _t) // DI CHUYEN XONG
		{
			timeMove = 0;
			m_ID = STAND;
			m_moveByFlag = false; 
		}
		m_velocity = ccpNormalize( ccpSub(m_targetPos,m_pos) );
		m_velocity =  ccpMult(m_velocity,m_maxVelocity);
		m_pos = ccpAdd(m_pos,m_velocity);
		m_Solider->setPosition(m_pos);
	}
}
void Solider::setTarget(CCPoint _target)
{
	m_ID = MOVE;
	timeMove = 0;
	m_targetPos = _target;
	timeFinishMove = ccpLength(ccpSub(m_targetPos, m_pos))/ m_maxVelocity/60;
}
void Solider::Collision( MyObject* _enemy,float dt )// DA GIAI QUYET DC : T1 : TIM DC TARGET VA DANH T2: NEU MOVE THEO FLAG THI RELEASE ENEMY DO RA
{
	if( m_moveByFlag == true ) // KHI DANG DI CHUYEN BOI FLAG THI SE RELEASE ENEMY (neu co)
	{
		if( m_choosedEnemy !=NULL)
		{
	    	isTarget = false;
		    m_choosedEnemy->m_countAttack -=1;
		    m_choosedEnemy->m_ID = E_MOVE;
	    	m_choosedEnemy = NULL;
		}
	}
	if(this->getRect().intersectsRect(_enemy->getRect()) && m_moveByFlag ==false && m_countAttack >1 )// neu co doi tuong moi xuat hien va no chua co bi ai danh' ma doi' tuong hien tai bi 2 danh 1 thi 1 linh' se quay ra tieu diet ke thu
	{
		if(_enemy->m_countAttack ==0)
		{
			if( m_choosedEnemy!=NULL) 
			{
					m_choosedEnemy->m_countAttack -=1;
			}
			m_choosedEnemy = _enemy;
			m_choosedEnemy->m_ID = E_STAND;
			m_choosedEnemy->m_countAttack +=1;
			m_countAttack = m_choosedEnemy->m_countAttack;
			setTarget(CCPoint (m_choosedEnemy->m_pos.x + 30, m_choosedEnemy->m_pos.y));
			
		}
	}
	if( this->getRect().intersectsRect(_enemy->getRect()) && isTarget ==false && m_moveByFlag ==false) // khien' cho quai' dung' lai phai tiep' chien' voi linh :v
	{
		isTarget = true;

		m_choosedEnemy = _enemy;

		m_choosedEnemy->m_countAttack +=1;
		m_choosedEnemy->m_ID = E_STAND;

		m_countAttack = m_choosedEnemy->m_countAttack;
		setTarget(CCPoint (m_choosedEnemy->m_pos.x + 30, m_choosedEnemy->m_pos.y));
	}
}
cocos2d::CCRect Solider::getRect()
{
	return m_circleColision->boundingBox();
}
