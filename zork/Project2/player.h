#ifndef _PLAYER
#define _PLAYER


#include "entity.h"

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
	World* world;
};
#endif