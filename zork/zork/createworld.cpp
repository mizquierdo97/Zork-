#include "world.h"
#include <string.h>

void World::createworld(){
	//exits[0].origen = rooms + 0;
	strcpy_s(rooms[0].name, "Room 1");
	printf("%s", rooms[0]);

}