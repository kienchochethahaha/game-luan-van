#include "BoomManager.h"


BoomManager::BoomManager(void)
{
}


BoomManager::~BoomManager(void)
{
}
void BoomManager::addBoom(Boom* Boom)
{
	m_listBoom.push_back(Boom);

}
void BoomManager::update(float dt)
{
	for (int i =0; i < m_listBoom.size(); i++)
	{
		m_listBoom[i]->update(dt);
	}
}
void BoomManager ::Collision(MyObject* _enemy, float dt)
{
	for (int i =0; i < m_listBoom.size(); i++)
	{
		m_listBoom[i]->Collision(_enemy, dt);
		if( m_listBoom[i]->m_Col ==true)
		{
			m_listBoom[i]->removeBoom();
			m_listBoom.erase(m_listBoom.begin() + i);
		}
	}
}