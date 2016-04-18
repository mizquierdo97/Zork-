#include "object.h"


Object::Object(const char* name, const char* description, Room* position, bool take, bool put) : Entity(name, description, OBJECT), position(position), take(take), put(put){

}



Object::Object(const char* name, const char* description) : Entity(name, description, OBJECT){

}