#include <stdio.h>
#include <iostream>

#ifndef _CLASSES
#define _CLASSES

class Player{
public:
	char* name;
	Player(){
		name = new char[20];
	}
	~Player(){
		delete[] name;
	}
	
	
};

class Room{
public:
	char name[30];
	char description[200];
};

class Exit{
public:
	char name[30];
	char description[200];
	Exit();
	~Exit();
	Room* origen;
	Room* desti;
	bool open = false;
};


class World{
public:
	int x = 0;
	Room* rooms= nullptr;
	//Exit* exits = nullptr;
	World() {
		rooms = new Room[13];
		//exits = new Exit[20];
	}
	~World();
	void createworld();
	
	/*Room* room = nullptr;
	Player* player = nullptr;
	Exit* exit = nullptr;*/
};


#endif  // Classes




