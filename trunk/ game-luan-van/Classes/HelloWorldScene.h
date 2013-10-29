#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include <stdio.h>     
#include <math.h>       
#include "Path.h"
#include "Character.h"
#include "Tower.h"
#include "Bullet.h"
#include "ManagerObject.h"
#include "Boom.h"
#include "Bartrack.h"
#include "Solider.h"
#include "Canon.h"

using namespace cocos2d;
using namespace std;
class HelloWorld : public cocos2d::CCLayer
{
public:

	vector <MyObject*>* m_listEnemy;
	vector <MyObject*>* m_listTower;
	vector <MyObject*>* m_listCanon;
	vector <MyObject*>* m_listBartrack;
	vector <MyObject*>* m_listSolider;

	Boom* m_boom;
	int count ;
	CCSprite* background;
	CCPoint firstPoint ;
	Path* path ;
	Path* pathLeft;
	Path* pathRight;

	//terrain 
	int** m_terrain;
	int m_wTileSet;
	int m_hTileSet;
	int m_idRow_Terrain;
	int m_idCol_Terrain;

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    void update(float dt);
	CCPoint truncate(CCPoint, float);
	CCPoint seek (float dt);

    // a selector callback
    void menuCloseCallback(CCObject* pSender);

	//Input
// 	void ccTouchesBegan(CCSet *pTouches,CCEvent *pEvent);
// 	void ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);
 	void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	virtual void draw();
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);


};

#endif  // __HELLOWORLD_SCENE_H__