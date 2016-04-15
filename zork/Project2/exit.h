#include "entity.h"

class Exit :public Entity{
public:
	Exit();
	~Exit();
	Room* origen;
	Room* destination;

};