#include "world.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



World::World(){
	rooms = new Room[10];
	exits = new Exit[24];
	player = new Player[1];

	

}

void World::createworld(){


	// Rooms Names and Descriptions
	strcpy_s(rooms[0].name, "Jail"); strcpy_s(rooms[0].description, "A small and cold jail. It only have one closed door at south");
	strcpy_s(rooms[1].name, "Hall"); strcpy_s(rooms[1].description, "A room which comunicates wit the other jails. There are two guards and many prisoners");
	strcpy_s(rooms[2].name, "Entry"); strcpy_s(rooms[2].description, "The entry to the prison. It could be the only way to scape");
	strcpy_s(rooms[3].name, "East Corridor"); strcpy_s(rooms[3].description, "A corridor which comunicates with other instances");
	strcpy_s(rooms[4].name, "West Corridor"); strcpy_s(rooms[4].description, "A corridor which comunicates with other instances");
	strcpy_s(rooms[5].name, "Warehouse"); strcpy_s(rooms[5].description, "In this room you can see differents objects like a brookstick, boxes and many prisoners clothes");
	strcpy_s(rooms[6].name, "Bath"); strcpy_s(rooms[6].description, "The public bath of the prison. It smells fucking really bad");
	strcpy_s(rooms[7].name, "Gym"); strcpy_s(rooms[7].description, "There are many prisoners doing exercise. Just one guard");
	strcpy_s(rooms[8].name, "Courtyard"); strcpy_s(rooms[8].description, "The only instance where the prisoners can see the sunlight");
	strcpy_s(rooms[9].name, "Dinner Room"); strcpy_s(rooms[9].description, "Totally empty apart from by a prisoner and a guard.There are some cutlery on the tables");
	
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

	exits[0].origin = rooms + 0; exits[0].destination = rooms + 1; exits[0].open = false; exits[0].direction = south;
	exits[1].origin = rooms + 1; exits[1].destination = rooms + 0; exits[1].open = false; exits[1].direction = north;
	exits[2].origin = rooms + 1; exits[2].destination = rooms + 2; exits[2].open = false; exits[2].direction = south;
	exits[3].origin = rooms + 2; exits[3].destination = rooms + 1; exits[3].open = false; exits[3].direction = north;
	exits[4].origin = rooms + 1; exits[4].destination = rooms + 3; exits[4].open = false; exits[4].direction = east;
	exits[5].origin = rooms + 3; exits[5].destination = rooms + 1; exits[5].open = false; exits[5].direction = west;
	exits[6].origin = rooms + 4; exits[6].destination = rooms + 1; exits[6].open = false; exits[6].direction = east;
	exits[7].origin = rooms + 1; exits[7].destination = rooms + 4; exits[7].open = false; exits[7].direction = west;	
	exits[8].origin = rooms + 3; exits[8].destination = rooms + 5; exits[8].open = true; exits[8].direction = south;
	exits[9].origin = rooms + 5; exits[9].destination = rooms + 3; exits[9].open = true; exits[9].direction = north;
	exits[10].origin = rooms + 3; exits[10].destination = rooms + 6; exits[10].open = true; exits[10].direction = east;
	exits[11].origin = rooms + 6; exits[11].destination = rooms + 3; exits[11].open = true; exits[11].direction = west;
	exits[13].origin = rooms + 7; exits[12].destination = rooms + 4; exits[12].open = true; exits[13].direction = south;
	exits[12].origin = rooms + 4; exits[13].destination = rooms + 7; exits[13].open = true; exits[12].direction = north;	
	exits[14].origin = rooms + 4; exits[14].destination = rooms + 8; exits[14].open = true; exits[14].direction = south;
	exits[15].origin = rooms + 8; exits[15].destination = rooms + 4; exits[15].open = true; exits[15].direction = north;
	exits[17].origin = rooms + 9; exits[16].destination = rooms + 4; exits[16].open = true; exits[17].direction = east;
	exits[16].origin = rooms + 4; exits[17].destination = rooms + 9; exits[17].open = true; exits[16].direction = west;	
	exits[18].origin = rooms + 5; exits[18].destination = rooms + 6; exits[18].open = true;
	exits[19].origin = rooms + 6; exits[19].destination = rooms + 5; exits[19].open = true;
	exits[20].origin = rooms + 7; exits[20].destination = rooms + 9; exits[20].open = true;
	exits[21].origin = rooms + 9; exits[21].destination = rooms + 7; exits[21].open = true;
	exits[22].origin = rooms + 8; exits[22].destination = rooms + 9; exits[22].open = true;
	exits[23].origin = rooms + 9; exits[23].destination = rooms + 8; exits[23].open = true;

	// Player position
	player[0].position = &rooms[0];


	

}


bool World::loop(){
	char direct;

	char command[30];
	printf("----------------------\n");
	printf("%s\n%s\n", player[0].position->name, player[0].position->description);
	gets_s(command);

	int dir = -1;
	int n = 0;
	for (int i = 0; command[i]; i++)
		command[i] = tolower(command[i]);
	char* pch;
	char* pch1;
	char* pch2 = 0;
	pch = strtok(command, " ,.-");
	pch1 = pch;
	//pch2 = nullptr;
	while (pch != NULL)
	{
		pch2 = pch;
		pch = strtok(NULL, " ,.-");
		n++;
	}


	switch (n){
	case 1:   // 1 argument

		// Go 
		if (strcmp(pch1, "south") == 0 || strcmp(pch1, "s") == 0){
			dir = 0;
			Go(pch1, dir);
		}
		else if (strcmp(pch1, "north") == 0 || strcmp(pch1, "n") == 0){
			dir = 1;
			Go(pch1, dir);
		}
		else if (strcmp(pch1, "east") == 0 || strcmp(pch1, "e") == 0){
			dir = 2;
			Go(pch1, dir);
		}
		else if (strcmp(pch1, "west") == 0 || strcmp(pch1, "w") == 0){
			dir = 3;
			Go(pch1, dir);
		}

		//Quit
		else if(strcmp(pch1, "quit") == 0 || strcmp(pch1, "q") == 0){
			return true;
		}
		//Help

		else if(strcmp(pch1, "help") == 0 || strcmp(pch1, "h") == 0) {
			printf("You can move with the commands north/south/east/west or n/s/e/w. Also you can use commands look/open/close/quit/go.\n");
		}
		else if (strcmp(pch1, "look") == 0 || strcmp(pch1, "l") == 0) {
			printf("You are in %s. %s\n", player[0].position->name, player[0].position->description);
		}
		else printf("Invalid command");
		break;



	case 2:   // 2 arguments
		if (strcmp(pch1, "go") == 0 || strcmp(pch1, "g") == 0){
			if (strcmp(pch2, "south") == 0 || strcmp(pch2, "s") == 0){
				dir = 0;
			}
			else if (strcmp(pch2, "north") == 0 || strcmp(pch2, "n") == 0){
				dir = 1;
			}
			else if (strcmp(pch2, "east") == 0 || strcmp(pch2, "e") == 0){
				dir = 2;
			}
			else if (strcmp(pch2, "west") == 0 || strcmp(pch2, "w") == 0){
				dir = 3;
			}
			Go(pch2, dir);
		}
		if (strcmp(pch1, "open") == 0 || strcmp(pch1, "o")==0) {
			if (strcmp(pch2, "south") == 0 || strcmp(pch2, "s") == 0) {
				dir = 0;
			}
			else if (strcmp(pch2, "north") == 0 || strcmp(pch2, "n") == 0) {
				dir = 1;
			}
			else if (strcmp(pch2, "east") == 0 || strcmp(pch2, "e") == 0) {
				dir = 2;
			}
			else if (strcmp(pch2, "west") == 0 || strcmp(pch2, "w") == 0) {
				dir = 3;
			}
			open(pch2, dir);

		}

		if (strcmp(pch1, "close") == 0 || strcmp(pch1, "c") == 0) {
			if (strcmp(pch2, "south") == 0 || strcmp(pch2, "s") == 0) {
				dir = 0;
			}
			else if (strcmp(pch2, "north") == 0 || strcmp(pch2, "n") == 0) {
				dir = 1;
			}
			else if (strcmp(pch2, "east") == 0 || strcmp(pch2, "e") == 0) {
				dir = 2;
			}
			else if (strcmp(pch2, "west") == 0 || strcmp(pch2, "w") == 0) {
				dir = 3;
			}
			close(pch2, dir);

		}
		break;

	}
	return false;
}


bool World::Go(char* inst, int dir){
	int door = NULL;
	if (dir == 0){
		for (int i = 0; i < 24; i++){
			if (exits[i].origin == player[0].position && exits[i].direction == south ){
				if (exits[i].open == false) {
					printf("The door is closed\n");
					door++;
				}
				else {
					door++;
					player[0].position = exits[i].destination;
					return true;
				}
			}
		}
		if (door == NULL) printf("There are no exits in this way\n");
	}

	else if (dir == 1){
		for (int i = 0; i < 24; i++){
			if (exits[i].origin == player[0].position && exits[i].direction == north){
				if (exits[i].open == false) {
					printf("The door is closed\n");
					door++;
				}
				else {
					door++;
					player[0].position = exits[i].destination;
					return true;
				}
			}
		}
		if (door == NULL) printf("There are no exits in this way\n");
	}

	else if (dir == 2){
		for (int i = 0; i < 24; i++){
			if (exits[i].origin == player[0].position && exits[i].direction == east){
				if (exits[i].open == false) {
					printf("The door is closed\n");
					door++;
				}
				else {
					door++;
					player[0].position = exits[i].destination;
					return true;
				}
			}
		}
		if (door == NULL) printf("There are no exits in this way\n");
	}

	else if (dir == 3){
		for (int i = 0; i < 24; i++){
			if (exits[i].origin == player[0].position && exits[i].direction == west){
				if (exits[i].open == false) {
					printf("The door is closed\n");
					door++;
				}
				else {
					door++;
					player[0].position = exits[i].destination;
					return true;
				}
			}
		}
		if (door == NULL) printf("There are no exits in this way\n");
	}
	else{
		printf("Wrong Way");
		return false;
	}

}
void World::open(char* inst, int dir) {
	if (dir == 0) {
		for (int i = 0; i < 24; i++) {
			if (exits[i].origin == player[0].position && exits[i].direction == south) {
				if (exits[i].open == false) {
					exits[i].open = true;
					exits[i+1].open = true;
					printf("The door is now open\n");
				}
				else printf("The door is open\n");
			}
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < 24; i++) {
			if (exits[i].origin == player[0].position && exits[i].direction == north) {
				if (exits[i].open == false) {
					exits[i].open = true;
					exits[i - 1].open = true;
					printf("The door is now open\n");
				}
				else printf("The door is open\n");
			}
		}
	}
	else if (dir == 2) {
		for (int i = 0; i < 24; i++) {
			if (exits[i].origin == player[0].position && exits[i].direction == east) {
				if (exits[i].open == false) {
					exits[i].open = true;
					exits[i + 1].open = true;
					printf("The door is now open\n");
				}
				else printf("The door is open\n");
			}
		}
	}
	if (dir == 3) {
		for (int i = 0; i < 24; i++) {
			if (exits[i].origin == player[0].position && exits[i].direction == west) {
				if (exits[i].open == false) {
					exits[i].open = true;
					exits[i - 1].open = true;
					printf("The door is now open\n");
				}
				else printf("The door is open\n");
			}
		}
	}
	
}

void World::close(char* inst, int dir) {
	if (dir == 0) {
		for (int i = 0; i < 24; i++) {
			if (exits[i].origin == player[0].position && exits[i].direction == south) {
				if (exits[i].open == true) {
					exits[i].open = false;
					exits[i + 1].open = false;
					printf("The door is now closed\n");
				}
				else printf("The door is closed\n");
			}
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < 24; i++) {
			if (exits[i].origin == player[0].position && exits[i].direction == north) {
				if (exits[i].open == true) {
					exits[i].open = false;
					exits[i - 1].open = false;
					printf("The door is now closed\n");
				}
				else printf("The door is closed\n");
			}
		}
	}
	else if (dir == 2) {
		for (int i = 0; i < 24; i++) {
			if (exits[i].origin == player[0].position && exits[i].direction == east) {
				if (exits[i].open == true) {
					exits[i].open = false;
					exits[i + 1].open = false;
					printf("The door is now closed\n");
				}
				else printf("The door is closed\n");
			}
		}
	}
	if (dir == 3) {
		for (int i = 0; i < 24; i++) {
			if (exits[i].origin == player[0].position && exits[i].direction == west) {
				if (exits[i].open == true) {
					exits[i].open = false;
					exits[i - 1].open = false;
					printf("The door is now closed\n");
				}
				else printf("The door is closed\n");
			}
		}
	}
	
}



	

