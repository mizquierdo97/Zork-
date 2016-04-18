#include <stdio.h>

#include "world.h"
#include "room.h"
#include "player.h"


void World::createworld(){
	rooms.push_back(new Room("Jail", "A small and cold jail. It only have one closed door at south"));
	rooms.push_back(new Room("Hall", "A room which comunicates wit the other jails. There are two guards and many prisoners"));
	rooms.push_back(new Room("Entry", "The entry to the prison. It could be the only way to scape"));
	rooms.push_back(new Room("East Corridor","A corridor which comunicates with other instances" ));
	rooms.push_back(new Room("West Corridor", "A corridor which comunicates with other instances"));
	rooms.push_back(new Room("Warehouse", "In this room you can see differents objects like a brookstick, boxes and many prisoners clothes"));
	rooms.push_back(new Room("Bath", "The public bath of the prison. It smells fucking really bad"));
	rooms.push_back(new Room("Gym", "There are many prisoners doing exercise. Just one guard"));
	rooms.push_back(new Room("Courtyard", "The only instance where the prisoners can see the sunlight"));
	rooms.push_back(new Room("Dinner Room", "Totally empty apart from by a prisoner and a guard.There are some cutlery on the tables"));

	player =new Player("asd", "qwrwq", rooms[0]);

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
	
	/*
	exits[0]->origin = rooms[0]; exits[0]->destination = rooms[1]; exits[0]->open = false; exits[0]->direction = south;
	exits[1]->origin = rooms[1]; exits[1]->destination = rooms[0]; exits[1]->open = false; exits[1]->direction = north;
	exits[2]->origin = rooms[1]; exits[2]->destination = rooms[2]; exits[2]->open = false; exits[2]->direction = south;
	exits[3]->origin = rooms[2]; exits[3]->destination = rooms[1]; exits[3]->open = false; exits[3]->direction = north;
	exits[4]->origin = rooms[1]; exits[4]->destination = rooms[3]; exits[4]->open = false; exits[4]->direction = east;
	exits[5]->origin = rooms[3]; exits[5]->destination = rooms[1]; exits[5]->open = false; exits[5]->direction = west;
	exits[6]->origin = rooms[4]; exits[6]->destination = rooms[1]; exits[6]->open = false; exits[6]->direction = east;
	exits[7]->origin = rooms[1]; exits[7]->destination = rooms[4]; exits[7]->open = false; exits[7]->direction = west;
	exits[8]->origin = rooms[3]; exits[8]->destination = rooms[5]; exits[8]->open = true; exits[8]->direction = south;
	exits[9]->origin = rooms[5]; exits[9]->destination = rooms[3]; exits[9]->open = true; exits[9]->direction = north;
	exits[10]->origin = rooms[3]; exits[10]->destination = rooms[6]; exits[10]->open = true; exits[10]->direction = east;
	exits[11]->origin = rooms[6]; exits[11]->destination = rooms[3]; exits[11]->open = true; exits[11]->direction = west;
	exits[13]->origin = rooms[7]; exits[12]->destination = rooms[4]; exits[12]->open = true; exits[13]->direction = south;
	exits[12]->origin = rooms[4]; exits[13]->destination = rooms[7]; exits[13]->open = true; exits[12]->direction = north;
	exits[14]->origin = rooms[4]; exits[14]->destination = rooms[8]; exits[14]->open = true; exits[14]->direction = south;
	exits[15]->origin = rooms[8]; exits[15]->destination = rooms[4]; exits[15]->open = true; exits[15]->direction = north;
	exits[17]->origin = rooms[9]; exits[16]->destination = rooms[4]; exits[16]->open = true; exits[17]->direction = east;
	exits[16]->origin = rooms[4]; exits[17]->destination = rooms[9]; exits[17]->open = true; exits[16]->direction = west;*/
}