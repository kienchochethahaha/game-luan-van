#include "BulletManager.h"


BulletManager::BulletManager(void)
{
}


BulletManager::~BulletManager(void)
{
}
void BulletManager::addBullet(Bullet* bullet)
{
	m_listBullet.push_back(bullet);

}
void BulletManager::update(float dt)
{
	for (int i =0; i < m_listBullet.size(); i++)
	{
		m_listBullet[i]->update(dt);
	}
}
void BulletManager ::Collision(MyObject* _enemy, float dt)
{
	for (int i =0; i < m_listBullet.size(); i++)
	{
		m_listBullet[i]->Collision(_enemy, dt);
		if( m_listBullet[i]->m_Col ==true)
		{
			m_listBullet[i]->removeBullet();
			m_listBullet.erase(m_listBullet.begin() + i);
		}
	}
}