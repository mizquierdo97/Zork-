#include "exit.h"

Exit::Exit(const char* name, const char* description) : Entity(name, description, EXIT)
{


}

Room* Exit::get_destination()const{
	return destination;
}