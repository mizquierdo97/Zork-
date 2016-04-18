#include "entity.h"

Entity::Entity(const char* name, const char* description, type TYPE) : name(name), description(description), Type(TYPE) {

}

char* Entity::get_description()const{
	return description.c_str();
}
char* Entity::get_name()const{
	return name.c_str();
}

//