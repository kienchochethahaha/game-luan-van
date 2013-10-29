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
#include "Canon.h"
using namespace cocos2d;
using namespace std;
class ManagerObject
{
private:
	vector<MyObject*> *m_listEnemy;
	vector<MyObject*> *m_listTower;
	vector <MyObject*>* m_listCanon;
	vector<MyObject*> *m_listBartrack;
	vector<MyObject*> *m_listSolider;

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
	vector<MyObject*>* getListCanon()
	{
		return m_listCanon;

	}
	vector<MyObject*>* getListBartrack()
	{
		return m_listBartrack;

	}
	vector<MyObject*>* getListSolider()
	{
		return m_listSolider;
	}
	void setListSolider (vector<MyObject*>* _listSolider)
	{
		m_listSolider = _listSolider;
	}
	void setListEnemy (vector<MyObject*>* _list)
	{
		m_listEnemy = _list;
	}
	void setListTower ( vector<MyObject*>* _tower)
	{
		m_listTower = _tower;
	}
	void setListCanon ( vector<MyObject*>* _canon)
	{
		m_listCanon = _canon;
	}
	void setListBartrack ( vector<MyObject*>* _bartrack)
	{
		m_listBartrack = _bartrack;
	}
	~ManagerObject(void);
};

