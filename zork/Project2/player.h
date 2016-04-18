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
	
	bool go(int, const World*);
	void look(int, const World*)const;
	bool open(int, const World*);
	bool close(int, const World*);
	bool pick(const String&, const World*);
	bool drop(const String&, const World*);
	void look_inventory(const World*)const;
	bool equip();
	bool unequip();
	bool put();
	bool get();
	void look_item(const String&, const World*)const;
	World* world;
	Vector <Object*> Inventory;
};
#endif