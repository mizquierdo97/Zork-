#include "entity.h"

class Room : public Entity{
public:
	Room();
	Room(const char* name, const char* description);
	~Room();
};