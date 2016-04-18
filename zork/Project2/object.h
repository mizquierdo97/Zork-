#ifndef _OBJECT
#define _OBJECT

#include"entity.h"

class Object :public Entity{
public:
	Object();

	Object(const char* name, const char* description, Room* position);
	Object(const char* name, const char* description);
	Room* position;
};


#endif