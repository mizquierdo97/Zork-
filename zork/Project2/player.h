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
	void go(int, const World*);
	void look(int, const World*)const;
	void open(int, const World*);
	void close(int, const World*);
	World* world;
};
#endif