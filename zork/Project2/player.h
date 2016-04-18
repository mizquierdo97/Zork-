#ifndef _PLAYER
#define _PLAYER


#include "entity.h"
#include "object.h"

class World;

class Player : public Entity{
public:
	Room* position;
	Player(const char* name, const char* description);
	Player(const char* name, const char* description,  Room* room);
	~Player(){};
	bool go(int, const World*);
	void look(int, const World*)const;
	bool open(int, const World*);
	bool close(int, const World*);
	bool pick();
	bool drop();
	void inventory();
	bool equip();
	bool unequip();
	bool put();
	bool get();
	void look_item(const char*, const World*)const;
	World* world;
	Vector <Object*> Inventory;
};
#endif