#include <stdio.h>

#include "world.h"



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

	

	getchar();
	
}