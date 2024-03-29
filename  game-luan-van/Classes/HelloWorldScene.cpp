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
     
		CCSize winSize = CCDirector::sharedDirector()->getWinSize(); //tam thoi lay kich thuoc chuan la  800x600
		m_wTileSet  = winSize.width / G_TileSets_W;
		m_hTileSet = winSize.height / G_TileSets_H;

		 srand (time(NULL));
		m_terrain = new int* [G_TileSets_H]; //rows
		for (int i =0 ; i< G_TileSets_H ; i++) // init matrix
		{
			m_terrain[i] = new int [G_TileSets_W]; //column
		}

		for (int i =0 ; i< G_TileSets_H ; i++)
		{
			for (int j =0 ; j < G_TileSets_W ; j++)
			{
				int random = rand() %2; //random tu 0 ->1
				m_terrain[i][j] = random;
			}
		}

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

		m_listCanon = new vector<MyObject*>;
		ManagerObject::Instance()->setListCanon(m_listCanon);
		m_listCanon = ManagerObject::Instance()->getListCanon();

		m_listBartrack = new vector<MyObject*>;
		ManagerObject::Instance()->setListBartrack(m_listBartrack);
		m_listBartrack = ManagerObject::Instance()->getListBartrack();

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


		
		for (int i = 0; i< 15; i++ )
		{
			m_listEnemy->push_back(new Character(this,path, CCPoint(379 , 629 + i*100)));
		}

		m_listTower->push_back(new Tower(this, CCPoint(350,485)));
		m_listCanon->push_back(new Canon (this, CCPoint(266,461)));
		m_listBartrack->push_back(new Bartrack(this, CCPoint(484,276)));
	
		

		this->setTouchEnabled(true);
        bRet = true;
    
	} while(0);
    return bRet;
}
void HelloWorld::update(float dt)
{ 
	////////////*************** UPDATE *****************/////////

	// Update tower
	for (std::vector<MyObject*>::iterator i = m_listTower->begin();i!= m_listTower->end(); i++)
	{	
		(*i)->update(dt);
	}
	// Update canon
	for (std::vector<MyObject*>::iterator i = m_listCanon->begin();i!= m_listCanon->end(); i++)
	{	
		(*i)->update(dt);
	}
	//update bartrack
	for (std::vector<MyObject*>::iterator i = m_listBartrack->begin();i!= m_listBartrack->end();i++)
	{
		(*i)->update(dt);
	}


	//update enemy
	for (std::vector<MyObject*>::iterator i = m_listEnemy->begin();i!= m_listEnemy->end();)
	{
		
		(*i)->update(dt);
		if ( (*i)->m_Hp <=0 )
		{
				(*i)->release();
				i = m_listEnemy->erase(i);
				continue;
		}
		i++;
	}
	

	////////////*************** COLLISION *****************/////////

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

	//collision canon enemy - find target to shoot
	for (std::vector<MyObject*>::iterator j = m_listCanon->begin();j!= m_listCanon->end(); j++)
	{
		for (std::vector<MyObject*>::iterator i = m_listEnemy->begin();i!= m_listEnemy->end(); i++)
		{
			if( ( (*j)->m_Collision  ==true) ) // 
				continue;
			(*j)->Collision( (*i),dt);	
		}
	}

	//collision bartracks - enemy
	for (std::vector<MyObject*>::iterator i = m_listBartrack->begin();i!= m_listBartrack->end();i++)
	{
		for (std::vector<MyObject*>::iterator j = m_listEnemy->begin();j!= m_listEnemy->end(); j++)
		{
			(*i)->Collision( (*j),dt );
		}
	}

	
}
void HelloWorld::draw()
{
	for (std::vector<MyObject*>::iterator j = m_listTower->begin();j!= m_listTower->end(); j++)
	{
		(*j)->draw();
	}
	for (std::vector<MyObject*>::iterator j = m_listCanon->begin();j!= m_listCanon->end(); j++)
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
    
	for (std::vector<MyObject*>::iterator j = m_listTower->begin();j!= m_listTower->end(); j++)
	{
		(*j)->isTouch(location);
	}
	for (std::vector<MyObject*>::iterator j = m_listCanon->begin();j!= m_listCanon->end(); j++)
	{
		(*j)->isTouch(location);
	}
	for (std::vector<MyObject*>::iterator j = m_listBartrack->begin();j!= m_listBartrack->end(); j++)
	{
		(*j)->isTouch(location);
	}
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}

