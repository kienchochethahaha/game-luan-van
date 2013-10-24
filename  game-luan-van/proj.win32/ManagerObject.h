#pragma once

#include "cocos2d.h"
#include <vector>
#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include <stdio.h>     
#include <math.h>       
#include "Path.h"
#include "Character.h"

#include "Bullet.h"
#include "Tower.h"
#include "MyObject.h"
using namespace cocos2d;
using namespace std;
class ManagerObject
{
private:
	vector<MyObject*> *m_listEnemy;
	vector<MyObject*> *m_listTower;
	vector<MyObject*> *m_listBartrack;

	ManagerObject(void);
	static ManagerObject* m_Instance;
public:


	static ManagerObject* Instance()
	{
		if (m_Instance==NULL)
		{
			m_Instance = new ManagerObject();
		}
		return m_Instance;
	}	
	vector<MyObject*>*getListEnemy()
	{

		return m_listEnemy;
	}
	vector<MyObject*>* getListTower()
	{
		return m_listTower;

	}
	vector<MyObject*>* getListBartrack()
	{
		return m_listBartrack;

	}
	void setListEnemy (vector<MyObject*>* _list)
	{
		m_listEnemy = _list;
	}
	void setListTower ( vector<MyObject*>* _tower)
	{
		m_listTower = _tower;
	}
	void setListBartrack ( vector<MyObject*>* _bartrack)
	{
		m_listBartrack = _bartrack;
	}
	~ManagerObject(void);
};

