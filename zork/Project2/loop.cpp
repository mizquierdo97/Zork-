#include "player.h"
#include "world.h"
#include "room.h"
#include "string.h"
#include <string.h>
#include <string>
bool World::loop(){

	char command[50];

	printf("----------------------\n");
	
	printf("%s\n%s\n", player->position->get_name(), player->position->get_description());
	gets_s(command);

	int dir = -1;
	int n = 0;
	for (int i = 0; command[i]; i++)
		command[i] = tolower(command[i]);
	
	char* pch;
	char* pch1[4];
	char* pch2 = 0;
	pch = strtok(command, " ,.-");
	pch1[0] = pch;
	int num = 1;
	while (pch != NULL)
	{

		pch = strtok(NULL, " ,.-");
		pch1[num] = pch;
		n++;
		num++;
	}
	switch (n){
	case 1:   // 1 argument

		// Go 
		if (strcmp(pch1[0], "north") == 0 || strcmp(pch1[0], "n") == 0){
			dir = 0;
			player->go(dir, this);
		}
		else if (strcmp(pch1[0], "south") == 0 || strcmp(pch1[0], "s") == 0){
			dir = 1;
			player->go(dir, this);
		}
		else if (strcmp(pch1[0], "east") == 0 || strcmp(pch1[0], "e") == 0){
			dir = 2;
			player->go(dir, this);
		}
		else if (strcmp(pch1[0], "west") == 0 || strcmp(pch1[0], "w") == 0){
			dir = 3;
			player->go(dir, this);
		}

		//Quit
		else if (strcmp(pch1[0], "quit") == 0 || strcmp(pch1[0], "q") == 0){
			return true;
		}
		//Help

		else if (strcmp(pch1[0], "help") == 0 || strcmp(pch1[0], "h") == 0) {
			printf("You can move with the commands north/south/east/west or n/s/e/w. Also you can use commands look/open/close/quit/go.\n");
		}
		//Look
		else if (strcmp(pch1[0], "look") == 0 || strcmp(pch1[0], "l") == 0) {
			printf("You are in %s. %s\n", player[0].position->name, player[0].position->description);
		}
		else if (strcmp(pch1[0], "inventory") == 0 || strcmp(pch1[0], "inv") == 0 || strcmp(pch1[0], "i") == 0) {
			player->look_inventory(this);
		}
		else printf("Invalid command\n");
		break;


		

	case 2:   // 2 arguments
	//Go --
	if (strcmp(pch1[0], "go") == 0 || strcmp(pch1[0], "g") == 0){
	if (strcmp(pch1[1], "north") == 0 || strcmp(pch1[1], "n") == 0){
	dir = 0;
	}
	else if (strcmp(pch1[1], "south") == 0 || strcmp(pch1[1], "s") == 0){
	dir = 1;
	}
	else if (strcmp(pch1[1], "east") == 0 || strcmp(pch1[1], "e") == 0){
	dir = 2;
	}
	else if (strcmp(pch1[1], "west") == 0 || strcmp(pch1[1], "w") == 0){
	dir = 3;
	}
	player->go(dir, this);
	}
	//Open --
	else if (strcmp(pch1[0], "open") == 0 || strcmp(pch1[0], "o") == 0) {
	if (strcmp(pch1[1], "north") == 0 || strcmp(pch1[1], "n") == 0) {
	dir = 0;
	}
	else if (strcmp(pch1[1], "south") == 0 || strcmp(pch1[1], "s") == 0) {
	dir = 1;
	}
	else if (strcmp(pch1[1], "east") == 0 || strcmp(pch1[1], "e") == 0) {
	dir = 2;
	}
	else if (strcmp(pch1[1], "west") == 0 || strcmp(pch1[1], "w") == 0) {
	dir = 3;
	}
	player->open(dir,this);

	}
	//Close --
	else if (strcmp(pch1[0], "close") == 0 || strcmp(pch1[0], "c") == 0) {
	if (strcmp(pch1[1], "north") == 0 || strcmp(pch1[1], "n") == 0) {
	dir = 0;
	}
	else if (strcmp(pch1[1], "south") == 0 || strcmp(pch1[1], "s") == 0) {
	dir = 1;
	}
	else if (strcmp(pch1[1], "east") == 0 || strcmp(pch1[1], "e") == 0) {
	dir = 2;
	}
	else if (strcmp(pch1[1], "west") == 0 || strcmp(pch1[1], "w") == 0) {
	dir = 3;
	}
	player->close(dir, this);

	}
	else if (strcmp(pch1[0], "look") == 0 || strcmp(pch1[0], "l") == 0) {
	if (strcmp(pch1[1], "north") == 0 || strcmp(pch1[1], "n") == 0) {
	dir = 0;
	}
	else if (strcmp(pch1[1], "south") == 0 || strcmp(pch1[1], "s") == 0) {
	dir = 1;
	}
	else if (strcmp(pch1[1], "east") == 0 || strcmp(pch1[1], "e") == 0) {
	dir = 2;
	}
	else if (strcmp(pch1[1], "west") == 0 || strcmp(pch1[1], "w") == 0) {
	dir = 3;
	}
	else if (strcmp(pch1[1], "me") == 0 || strcmp(pch1[1], "m") == 0 || strcmp(pch1[1], "yourself") == 0 || strcmp(pch1[1], "y") == 0){
	dir = 4;
	}
	else{
		player->look_item(pch1[1], this);
	}
	player->look(dir, this);
	}

	else if (strcmp(pch1[0], "pick") == 0 || strcmp(pch1[0], "p") == 0) {
		player->pick(pch1[1], this);
	}

	else if (strcmp(pch1[0], "drop") == 0 || strcmp(pch1[0], "drop") == 0) {
		player->drop(pch1[1], this);
	}

	
	break;

	}
	return false;
	}



	
