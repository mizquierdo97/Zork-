#include <stdio.h>

class Player;
class Room;
class Exit;
class World;

class Exit{
public:
	char name[30];
	char description[200];

	Room* origin;
	Room* destination;
	bool open = false;
	int direction;  //0=North,1=South,2=East,3=West
};
