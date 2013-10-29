#include "SoliderManager.h"


SoliderManager::SoliderManager(void)
{
	m_numberSolider = 1;
}


SoliderManager::~SoliderManager(void)
{
}
void SoliderManager::addSolider(Solider* solider)
{
	m_listSolider.push_back(solider);

}
void SoliderManager::update(float dt)
{
	for (int i =0; i < m_listSolider.size(); i++)
	{
		m_listSolider[i]->update(dt);
	}
}
void SoliderManager::Collision( MyObject* _enemy,float dt )
{
	for (int i =0; i < m_listSolider.size(); i++)
	{
		m_listSolider[i]->Collision(_enemy, dt);
	}
}
void SoliderManager::setMoveByFlag()
{
	for (int i =0; i < m_listSolider.size(); i++)
	{
		m_listSolider[i]->m_moveByFlag = true;
	}
}
void SoliderManager::Move(CCPoint _target)
{
	for (int i =0; i < m_listSolider.size(); i++)
	{
		CCLOG("i :%d",i);
		if( m_listSolider.size() > 1)
		{

		 if(i == 0 )
		 {
			_target.x = _target.x + 30;
		 }
	     if(i == 1)
		 {
			_target.x = _target.x - 60;
		 }
		if(i == 2)
		  {
			_target.x = _target.x + 32;
			_target.y = _target.y - 30;
		 }
		}

		m_listSolider[i]->setTarget(_target);
	}
}