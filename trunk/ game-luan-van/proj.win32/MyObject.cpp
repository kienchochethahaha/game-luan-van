#include "MyObject.h"


MyObject::MyObject(void)
{
    m_iLife = true;
	m_pos = CCPoint(0,0);
	m_Collision = false;
	m_targetPos = CCPoint(0,0);
}


MyObject::~MyObject(void)
{
}
void MyObject::isTouch(CCPoint)
{

}
void MyObject::release()
{

}