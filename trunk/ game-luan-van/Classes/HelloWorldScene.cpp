#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::create();
        CC_BREAK_IF(! layer);
			CCLog("origin: %f ",CCDirector::sharedDirector()->getWinSize().width);
        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

        //////////////////////////////////////////////////////////////////////////
        // add your codes below...
        //////////////////////////////////////////////////////////////////////////

		this->scheduleUpdate();
     
		
		background = CCSprite::create("background1.png");
		background->setAnchorPoint(CCPoint(0,0));
		background->setPosition(CCPoint(0,0));
		this->addChild(background);

		//list enemy
		m_listEnemy = new vector<MyObject*>;
		ManagerObject::Instance()->setListEnemy(m_listEnemy);
		m_listEnemy = ManagerObject::Instance()->getListEnemy();

		//list tower - tam thoi la tinh cac danh xa
		m_listTower = new vector<MyObject*>;
		ManagerObject::Instance()->setListTower(m_listTower);
		m_listTower = ManagerObject::Instance()->getListTower();




	    firstPoint =  CCPoint(379,560);
		path = new Path();
		path->addNode(firstPoint);
		path->addNode(CCPoint(379,406));
		path->addNode(CCPoint(360,370));
 		path->addNode(CCPoint(310,350));
 		path->addNode(CCPoint(254,330));

		path->addNode(CCPoint(210,280));
		path->addNode(CCPoint(218,223));
		path->addNode(CCPoint(210,280));
		path->addNode(CCPoint(233,205));
		path->addNode(CCPoint(276,196));
		path->addNode(CCPoint(510,187));


		for (int i = 0; i< 3; i++ )
		{
			m_listEnemy->push_back(new Character(this,path, CCPoint(379 , 629 + i*50)));
		}

		m_listTower->push_back(new Tower(this, CCPoint(273,419)));
		m_listTower->push_back(new Tower (this, CCPoint(287,300)));
	
	    m_boom = new Boom (this, CCPoint(200,200));
	  

		this->setTouchEnabled(true);
        bRet = true;
    } while (0);

    return bRet;
}
void HelloWorld::update(float dt)
{ 
	//update enemy
	for (std::vector<MyObject*>::iterator i = m_listEnemy->begin();i!= m_listEnemy->end();i++)
	{
		
		(*i)->update(dt);
			
	}
	//collision tower enemy - find target to shoot
	for (std::vector<MyObject*>::iterator j = m_listTower->begin();j!= m_listTower->end(); j++)
	{
	  for (std::vector<MyObject*>::iterator i = m_listEnemy->begin();i!= m_listEnemy->end(); i++)
	  {
		  if( ( (*j)->m_Collision  ==true) ) // 
			  continue;
	           (*j)->Collision( (*i),dt);	
	  }
	}


	for (std::vector<MyObject*>::iterator i = m_listTower->begin();i!= m_listTower->end(); i++)
	{	
		(*i)->update(dt);
	}
}
void HelloWorld::draw()
{
	for (std::vector<MyObject*>::iterator j = m_listTower->begin();j!= m_listTower->end(); j++)
	{
		(*j)->draw();
	}
	  
	  // background->setVisible(false);
}

void HelloWorld ::ccTouchesEnded(CCSet *touches, CCEvent *pEvent)
{
	CCTouch* touch = (CCTouch*)( touches->anyObject() );
    CCPoint location = touch->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);

	
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}

