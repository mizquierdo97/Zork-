#include <stdio.h>

#include "world.h"
#include "room.h"
#include "player.h"


void World::createworld(){
	rooms.push_back(new Room("Jail", "A small and cold jail. It only have one closed door at south. In the room there's your personal chest"));//0
	rooms.push_back(new Room("Hall", "A room which comunicates wit the other jails. There are two guards and many prisoners"));//1
	rooms.push_back(new Room("Entry", "The entry to the prison. It could be the only way to scape"));//2
	rooms.push_back(new Room("East Corridor","A corridor which comunicates with other instances" ));//3
	rooms.push_back(new Room("West Corridor", "A corridor which comunicates with other instances"));//4
	rooms.push_back(new Room("Warehouse", "In this room you can see differents objects like a brookstick, boxes and many prisoners clothes"));//5
	rooms.push_back(new Room("Bath", "The public bath of the prison. It smells fucking really bad"));//6
	rooms.push_back(new Room("Gym", "There are many prisoners doing exercise. Just one guard"));//7
	rooms.push_back(new Room("Courtyard", "The only instance where the prisoners can see the sunlight. There's a shovel behind a tree"));//8
	rooms.push_back(new Room("Dinner Room", "Totally empty apart from by a prisoner and a guard.There are some cutlery on the tables"));//9

	player =new Player("Prisoner", "You are a prisoner", rooms[0]);

	exits.push_back(new Exit("Hall", "You can see the hall", rooms[0], rooms[1], false, south));//0
	exits.push_back(new Exit("Jail", "You can see the jail", rooms[1], rooms[0], false, north));//1
	exits.push_back(new Exit("Entry", "You can see the entry", rooms[1], rooms[2],true,south));//2
	exits.push_back(new Exit("Hall", "You can see the hall", rooms[2], rooms[1], true,north));//3
	exits.push_back(new Exit("Eastcorridor", "You can see the east corridor", rooms[1], rooms[3], true, east));//4
	exits.push_back(new Exit("Hall", "You can see the hall", rooms[3], rooms[1], true, west));//5
	exits.push_back(new Exit("West corridor", "You can see the west corridor", rooms[4], rooms[1], true, east));//6
	exits.push_back(new Exit("Hall", "You can see the hall", rooms[1], rooms[4], true,west));//7
	exits.push_back(new Exit("Warehoue", "You can see the warehouse", rooms[3], rooms[5], true,south));//8
	exits.push_back(new Exit("East corridor", "You can see the east crridor", rooms[5], rooms[3], true, north));//9
	exits.push_back(new Exit("Bath", "You can see the bath", rooms[3], rooms[6], true,east));//10
	exits.push_back(new Exit("East corridor", "You can see the east corridor", rooms[6], rooms[3], true,west));//11
	exits.push_back(new Exit("Gym", "You can see the gym", rooms[4], rooms[7], true, north));//12
	exits.push_back(new Exit("West corridor", "You can see the west corridor", rooms[7], rooms[4], true,south));//13
	exits.push_back(new Exit("Courtyard", "You can see the courtyard", rooms[4], rooms[8], true,south));//14
	exits.push_back(new Exit("West corridor", "You can see the west corridor", rooms[8], rooms[4], true, north));//15
	exits.push_back(new Exit("Dinner room", "You can see the dinner room", rooms[4], rooms[9], true,west));//16
	exits.push_back(new Exit("West Corridor", "You can see the west corridor", rooms[9], rooms[4], true,east));//17

	
	objects.push_back(new Object("chest", "There are things inside", rooms[0], false , true));
	objects.push_back(new Object("broomstick", "A broomstick", rooms[5], true, false));
	objects.push_back(new Object("box", "There are prisoner clothes inside", rooms[5], false, true));
	objects.push_back(new Object("clothes", "The only clothes that prisoners can dress", nullptr, true, false));
	objects.push_back(new Object("shovel", "A shovel", rooms[8], true, false));
	objects.push_back(new Object("knife", "A knife", rooms[9], true, false));

	objects[2]->Inventory.push_back(new Object("clothes", "The only clothes that prisoners can dress"));

	
	
}