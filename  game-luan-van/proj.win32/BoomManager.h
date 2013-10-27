#pragma once
#include "cocos2d.h"
#include <vector>
#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include <stdio.h>     
#include <math.h>       
#include "Path.h"
#include "Character.h"

#include "Boom.h"
using namespace cocos2d;
using namespace std;
class BoomManager
{

protected:
	vector<Boom*> m_listBoom;

public:
	BoomManager(void);
	~BoomManager(void);

	void update(float dt);
	void Collision(MyObject* _enemy, float dt);
	void addBoom (Boom* Boom);

	Boom* getBoom(int index)
	{
		return m_listBoom[index];

	}
	vector<Boom*> getListBoom()
	{
		return m_listBoom;

	}
};

