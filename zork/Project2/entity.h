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
private:
	type Type = ENTITY;
public:
	String name;
	String description;
	
	Vector <Entity*> entities;

	Entity(){};
	Entity(const char* name, const char* description, type TYPE);//////////////
	virtual ~Entity(){ };
	char* get_name()const;
	char* get_description()const;
	Vector <Entity*> Inventory;
};
#endif