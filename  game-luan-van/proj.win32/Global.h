#pragma  once
#define GRAVITY 9.8
#define G_TileSets_W 80 // number column tile sets
#define G_TileSets_H 60 //number rows tile sets


enum ID_TOWER
{
	BARTRACK,
	ARCHER,
	CANNON,
	CAVALRYMAN

};
enum SOLIDER
{
	STAND, 
	MOVE, 
	ATTACK
};
enum ENEMY
{
	E_MOVE,
	E_ATTACKED, 
	E_STAND
};