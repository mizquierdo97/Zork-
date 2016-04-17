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

	exits.push_back(new Exit("Hall", "You can see the hall"));
	exits.push_back(new Exit("Jail", "You can see the jail"));
	exits.push_back(new Exit("Entry", "You can see the entry"));
	exits.push_back(new Exit("Hall", "You can see the hall"));
	exits.push_back(new Exit("Eastcorridor", "You can see the east corridor"));
	exits.push_back(new Exit("Hall", "You can see the hall"));
	exits.push_back(new Exit("West corridor" ,"You can see the west corridor"));
	exits.push_back(new Exit("Hall", "You can see the hall"));
	exits.push_back(new Exit("Warehoue" , "You can see the warehouse"));
	exits.push_back(new Exit("East corridor", "You can see the east crridor"));
	exits.push_back(new Exit("Bath" , "You can see the bath"));
	exits.push_back(new Exit("East corridor" , "You can see the east corridor"));
	exits.push_back(new Exit("Gym" , "You can see the gym"));
	exits.push_back(new Exit("West corridor" ,"You can see the west corridor"));
	exits.push_back(new Exit("Courtyard" , "You can see the courtyard"));
	exits.push_back(new Exit("West corridor" , "You can see the west corridor"));
	exits.push_back(new Exit("Dinner room" , "You can see the dinner room"));
	exits.push_back(new Exit("West Corridor" , "You can see the west corridor"));
	/*
	strcpy_s(exits[0].name, "Hall"); strcpy_s(exits[0].description, "You can see the Hall.");
	strcpy_s(exits[1].name, "Jail"); strcpy_s(exits[1].description, "You can see your jail");
	strcpy_s(exits[2].name, "Entry"); strcpy_s(exits[2].description, "You can see the Entry");
	strcpy_s(exits[3].name, "Hall"); strcpy_s(exits[3].description, "You can see the Hall");
	strcpy_s(exits[4].name, "East Corridor"); strcpy_s(exits[4].description, "You can see the East Corridor");
	strcpy_s(exits[5].name, "Hall"); strcpy_s(exits[5].description, "You can see the Hall");
	strcpy_s(exits[6].name, "West Corridor"); strcpy_s(exits[6].description, "You can see the West Corridor");
	strcpy_s(exits[7].name, "Hall"); strcpy_s(exits[7].description, "You can see the Hall");
	strcpy_s(exits[8].name, "Warehouse"); strcpy_s(exits[8].description, "You can see the Warehouse");
	strcpy_s(exits[9].name, "East Corridor"); strcpy_s(exits[9].description, "You can see the East Corridor");
	strcpy_s(exits[10].name, "Bath"); strcpy_s(exits[10].description, "You can see the Bath");
	strcpy_s(exits[11].name, "East Corridor"); strcpy_s(exits[11].description, "You can see the East corridor");
	strcpy_s(exits[12].name, "Gym"); strcpy_s(exits[12].description, "You can see the Gym");
	strcpy_s(exits[13].name, "West Corridor"); strcpy_s(exits[13].description, "You can see the West Corridor");
	strcpy_s(exits[14].name, "Courtyard"); strcpy_s(exits[14].description, "You can see the Courtyard");
	strcpy_s(exits[15].name, "West Corridor"); strcpy_s(exits[15].description, "You can see the West Corridor");
	strcpy_s(exits[16].name, "Dinner Room"); strcpy_s(exits[16].description, "You can see the Dinner Room");
	strcpy_s(exits[17].name, "West Corridor"); strcpy_s(exits[17].description, "You can see the West Corridor");*/



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
	exits[16]->origin = rooms[4]; exits[17]->destination = rooms[9]; exits[17]->open = true; exits[16]->direction = west;
}