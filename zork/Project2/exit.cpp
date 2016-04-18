#include "exit.h"

Exit::Exit(const char* name, const char* description, Room* origin, Room* destination, bool open, int dir) : Entity(name, description, EXIT), origin(origin), destination(destination), open(open), direction(dir)
{


}

Room* Exit::get_destination()const{
	return destination;
}