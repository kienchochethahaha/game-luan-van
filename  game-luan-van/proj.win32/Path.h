#pragma once
#ifndef __Path_H__
#define __Path_H__

#include "cocos2d.h"

#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include <stdlib.h>

using namespace cocos2d;
using namespace std;
class Path : public   cocos2d::CCNode
{
private:
	 float m_radiusPath ;
	 std::vector <CCPoint>* nodes;
public:
	Path();

	
	void addNode(CCPoint node);
	vector<CCPoint>* getNodes()
	{
		return nodes;
	}
	float getRadisPath()
	{

		return m_radiusPath;
	}


};

#endif  // __Path_H__