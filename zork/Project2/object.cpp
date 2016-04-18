#include "object.h"


Object::Object(const char* name, const char* description, Room* position) : Entity(name, description, OBJECT), position(position){

}

Object::Object(const char* name, const char* description) : Entity(name, description, OBJECT){

}