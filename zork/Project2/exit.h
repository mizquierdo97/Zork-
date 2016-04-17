#ifndef _EXIT
#define _EXIT
#include "entity.h"

class Exit :public Entity{
public:
	Exit();
	Exit(const char* name, const char* description);
	~Exit();
	Room* origin;
	Room* destination;
	bool open;
	int direction;
	Room* get_destination()const;

};
#endif