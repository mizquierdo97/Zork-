#include "world.h"
#include <string.h>

World::World(){
	rooms = new Room[10];
	exits = new Exit[24];
	player = new Player[1];

	

}

void World::createworld(){
	// Rooms Names and Descriptions
	strcpy_s(rooms[0].name, "Jail"); strcpy_s(rooms[0].description, "A small and cold jail. It only have one closed door at south");
	strcpy_s(rooms[1].name, "Hall"); strcpy_s(rooms[0].description, "A room which comunicates wit the other jails. There are two guards and many prisoners");
	strcpy_s(rooms[2].name, "Entry"); strcpy_s(rooms[0].description, "The entry to the prison. It could be the only way to scape");
	strcpy_s(rooms[3].name, "East Corridor"); strcpy_s(rooms[0].description, "A corridor which comunicates with other instances");
	strcpy_s(rooms[4].name, "West Corridor"); strcpy_s(rooms[0].description, "A corridor which comunicates with other instances");
	strcpy_s(rooms[5].name, "Warehouse"); strcpy_s(rooms[0].description, "In this room you can see differents objects like a brookstick, boxes and many prisoners clothes");
	strcpy_s(rooms[6].name, "Bath"); strcpy_s(rooms[0].description, "The public bath of the prison. It smells fucking really bad");
	strcpy_s(rooms[7].name, "Gym"); strcpy_s(rooms[0].description, "There are many prisoners doing exercise. Just one guard");
	strcpy_s(rooms[8].name, "Courtyard"); strcpy_s(rooms[0].description, "The only instance where the prisoners can see the sunlight");
	strcpy_s(rooms[9].name, "Dinner Room"); strcpy_s(rooms[0].description, "Totally empty apart from by a prisoner and a guard.There are some cutlery on the tables");
	
	//Exits Names, Descriprions and Logic
	strcpy_s(exits[0].name, "Hall"); strcpy_s(exits[0].description, "");
	strcpy_s(exits[1].name, "Jail"); strcpy_s(exits[1].description, "");
	strcpy_s(exits[2].name, "Entry"); strcpy_s(exits[2].description, "");
	strcpy_s(exits[3].name, "Hall"); strcpy_s(exits[3].description, "");
	strcpy_s(exits[4].name, "East Corridor"); strcpy_s(exits[4].description, "");
	strcpy_s(exits[5].name, "Hall"); strcpy_s(exits[5].description, "");
	strcpy_s(exits[6].name, "West Corridor"); strcpy_s(exits[6].description, "");
	strcpy_s(exits[7].name, "Hall"); strcpy_s(exits[7].description, "");
	strcpy_s(exits[8].name, "Warehouse"); strcpy_s(exits[8].description, "");
	strcpy_s(exits[9].name, "East Corridor"); strcpy_s(exits[9].description, "");
	strcpy_s(exits[10].name, "Bath"); strcpy_s(exits[10].description, "");
	strcpy_s(exits[11].name, "East Corridor"); strcpy_s(exits[11].description, "");
	strcpy_s(exits[12].name, "Gym"); strcpy_s(exits[12].description, "");
	strcpy_s(exits[13].name, "West Corridor"); strcpy_s(exits[13].description, "");
	strcpy_s(exits[14].name, "Courtyard"); strcpy_s(exits[14].description, "");
	strcpy_s(exits[15].name, "West Corridor"); strcpy_s(exits[15].description, "");
	strcpy_s(exits[16].name, "Dinner Room"); strcpy_s(exits[16].description, "");
	strcpy_s(exits[17].name, "West Corridor"); strcpy_s(exits[17].description, "");
	strcpy_s(exits[18].name, "Bath"); strcpy_s(exits[18].description, "");
	strcpy_s(exits[19].name, "Warehouse"); strcpy_s(exits[19].description, "");
	strcpy_s(exits[20].name, "Dinner Room"); strcpy_s(exits[20].description, "");
	strcpy_s(exits[21].name, "Gym"); strcpy_s(exits[21].description, "");
	strcpy_s(exits[22].name, "Dinner Room"); strcpy_s(exits[22].description, "");
	strcpy_s(exits[23].name, "Courtyard"); strcpy_s(exits[23].description, "");

	exits[0].origin = rooms + 0; exits[0].destination = rooms + 1; exits[0].open = false;
	exits[1].origin = rooms + 1; exits[1].destination = rooms + 0; exits[1].open = false;
	exits[2].origin = rooms + 1; exits[2].destination = rooms + 2; exits[2].open = false;
	exits[3].origin = rooms + 2; exits[3].destination = rooms + 1; exits[3].open = false;
	exits[4].origin = rooms + 1; exits[4].destination = rooms + 3; exits[4].open = true;
	exits[5].origin = rooms + 3; exits[5].destination = rooms + 1; exits[5].open = true;
	exits[6].origin = rooms + 1; exits[6].destination = rooms + 4; exits[6].open = true;
	exits[7].origin = rooms + 4; exits[7].destination = rooms + 1; exits[7].open = true;
	exits[8].origin = rooms + 3; exits[8].destination = rooms + 5; exits[8].open = true;
	exits[9].origin = rooms + 5; exits[9].destination = rooms + 3; exits[9].open = true;
	exits[10].origin = rooms + 3; exits[10].destination = rooms + 6; exits[10].open = true;
	exits[11].origin = rooms + 6; exits[11].destination = rooms + 3; exits[11].open = true;
	exits[12].origin = rooms + 4; exits[12].destination = rooms + 7; exits[12].open = true;
	exits[13].origin = rooms + 7; exits[13].destination = rooms + 4; exits[13].open = true;
	exits[14].origin = rooms + 4; exits[14].destination = rooms + 8; exits[14].open = true;
	exits[15].origin = rooms + 8; exits[15].destination = rooms + 4; exits[15].open = true;
	exits[16].origin = rooms + 4; exits[16].destination = rooms + 9; exits[16].open = true;
	exits[17].origin = rooms + 9; exits[17].destination = rooms + 4; exits[17].open = true;
	exits[18].origin = rooms + 5; exits[18].destination = rooms + 6; exits[18].open = true;
	exits[19].origin = rooms + 6; exits[19].destination = rooms + 5; exits[19].open = true;
	exits[20].origin = rooms + 7; exits[20].destination = rooms + 9; exits[20].open = true;
	exits[21].origin = rooms + 9; exits[21].destination = rooms + 7; exits[21].open = true;
	exits[22].origin = rooms + 8; exits[22].destination = rooms + 9; exits[22].open = true;
	exits[23].origin = rooms + 9; exits[23].destination = rooms + 8; exits[23].open = true;

	// Player position
	player[0].position = &rooms[0];

	printf("%i   %i\n", exits[23].origin, &rooms[9]);
	printf("%i   %i", &rooms[0], player[0].position);
	

}