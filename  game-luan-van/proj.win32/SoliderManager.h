#pragma once
#include "cocos2d.h"

#include "SimpleAudioEngine.h"
#include <stdio.h>     
#include <math.h>      
#include "MyObject.h"
#include "Global.h"
#include "Solider.h"
using namespace std;
using namespace cocos2d;
class SoliderManager
{

protected:
	int m_numberSolider; // number of solider exist now of a bartrack
	vector<Solider*> m_listSolider;
public:

	void update(float dt);
    void Collision( MyObject* ,float );

	void addSolider (Solider* bullet);
	void Move (CCPoint);
	virtual void setMoveByFlag();
	Solider* getSolider(int index)
	{
		return m_listSolider[index];

	}

	vector<Solider*> getListSolider()
	{
		return m_listSolider;

	}
	SoliderManager(void);
	~SoliderManager(void);
};

