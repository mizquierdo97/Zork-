#ifndef _ENTITY
#define _ENTITY
#include "vector.h"
#include "string.h"
#include <stdio.h>
//#include "world.h"
#define NULL 0

class Room;
class Player;
//class Vector <class TYPE>;

enum type{ 
	ENTITY,
	PLAYER,
	ROOM, 
	EXIT,
	OBJECT
};

class Entity{
public:
	String name;
	String description;
	type Type;
	Vector <Entity*> entities;

	Entity(){};
	Entity(const char* name, const char* description, type TYPE);//////////////
	char* get_name()const;
	char* get_description()const;
};
#endif