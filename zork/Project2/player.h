//#include "entity.h"
#include "room.h"

class World;

class Player : public Entity{
public:
	Room* position;

	Player(const char* name, const char* description, Room* room);
	~Player(){};
	void go(char* , int, World*);
	void look()const;
	void open();
	void close();
	World* world;
};