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
bool MyObject::TestCollisionelip(MyObject* m_enemy, CCSprite* m_circle)
{
	float a;
	float b;
	float c;// x=c, phuong trinh canh doc cua enemy
	float d;//y=d, phuong trinh canh ngang cua enemy
	float Y;//giao diem y
	float X;//giao diem x
	float Y1_enemy_after;//y dinh? duoi sau khi dich toa do theo tower cua enemy
	float Y2_enemy_after;//y dinh? tren sau khi dich toa do theo tower cua enemy
	float X1_enemy_after;//x dinh? trai sau khi dich toa do theo tower cua enemy
	float X2_enemy_after;//x dinh? phai sau khi dich toa do theo tower cua enemy
	float A;

	a=m_circle->boundingBox().size.width/2;
	b=m_circle->boundingBox().size.height/2;
	////canh doc trong cung
	c= m_enemy->m_pos.x-m_enemy->getRect().size.width/2-this->m_pos.x;
	Y=0;//giao diem
	Y1_enemy_after=m_enemy->m_pos.y-m_enemy->getRect().size.height/2-this->m_pos.y;//y duoi
	Y2_enemy_after=m_enemy->m_pos.y+m_enemy->getRect().size.height/2-this->m_pos.y;//y tren
	A=(1-(c*c)/(a*a))*b*b;

	if(  A >=0 )
	{

		Y=sqrt(A);
		if((Y<Y2_enemy_after&&Y>Y1_enemy_after)||(-Y<Y2_enemy_after&&-Y>Y1_enemy_after)||(Y1_enemy_after>-Y&&Y2_enemy_after<Y))
			return true;
	}

	//canh doc ngoai cung
	c= m_enemy->m_pos.x+m_enemy->getRect().size.width/2-this->m_pos.x;
	Y=0;//giao diem
	Y1_enemy_after=m_enemy->m_pos.y-m_enemy->getRect().size.height/2-this->m_pos.y;//y duoi
	Y2_enemy_after=m_enemy->m_pos.y+m_enemy->getRect().size.height/2-this->m_pos.y;//y tren
	A=(1-(c*c)/(a*a))*b*b;

	if(  A >=0 )
	{

		Y=sqrt(A);
		if((Y<Y2_enemy_after&&Y>Y1_enemy_after)||(-Y<Y2_enemy_after&&-Y>Y1_enemy_after)||(Y1_enemy_after>-Y&&Y2_enemy_after<Y))
			return true;
	}
	// canh ngang tren
	d= m_enemy->m_pos.y+m_enemy->getRect().size.height/2-this->m_pos.y;
	X=0;//giao diem
	X1_enemy_after=m_enemy->m_pos.x-m_enemy->getRect().size.width/2-this->m_pos.x;//x trai
	X2_enemy_after=m_enemy->m_pos.x+m_enemy->getRect().size.width/2-this->m_pos.x;//x phai
	A=(1-(d*d)/(b*b))*a*a;

	if(  A >=0 )
	{

		X=sqrt(A);
		if((X<X2_enemy_after&&X>X1_enemy_after)||(-X<X2_enemy_after&&-X>X1_enemy_after)||(X1_enemy_after>-X&&X2_enemy_after<X))
			return true;
	}
	// canh ngang duoi
	d= m_enemy->m_pos.y-m_enemy->getRect().size.height/2-this->m_pos.y;
	X=0;//giao diem
	X1_enemy_after=m_enemy->m_pos.x-m_enemy->getRect().size.width/2-this->m_pos.x;//x trai
	X2_enemy_after=m_enemy->m_pos.x+m_enemy->getRect().size.width/2-this->m_pos.x;//x phai
	A=(1-(d*d)/(b*b))*a*a;

	if(  A >=0 )
	{

		X=sqrt(A);
		if((X<X2_enemy_after&&X>X1_enemy_after)||-X<X2_enemy_after&&-X>X1_enemy_after||(X1_enemy_after>-X&&X2_enemy_after<X))
			return true;
	}
	return false;
}