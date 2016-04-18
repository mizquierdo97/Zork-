#ifndef _OBJECT
#define _OBJECT

#include"entity.h"

class Object :public Entity{
public:
	Object();

	Object(const char* name, const char* description, Room* position, bool take, bool put);
	
	Object(const char* name, const char* description);
	Room* position;
	//Vector <Entity*> inventory;
	bool take;
	bool put;
};


#endif