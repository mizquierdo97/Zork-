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
	/*
	String pch;
	String pch1[5];
	//String pch2[1] = { "south" };
	pch = strtok(command, " ,.-");
	pch1[0] = pch;
	int num = 1;
	while (pch != NULL)
	{

	pch = strtok(NULL, " ,.-");
	pch1[num] = pch;
	n++;
	num++;
	}*/
	String s_command(command);
	Vector<String*> v_command;
	v_command = s_command.tokenize();
	n = v_command.num_elements;

	switch (n){
	case 1:   // 1 argument

		// Go 
		if (v_command[0]->s_str() == "north" || v_command[0]->s_str() == "n"){
			dir = 0;
			player->go(dir, this);
		}
		else if (v_command[0]->s_str() == "south" || v_command[0]->s_str() == "s"){
			dir = 1;
			player->go(dir, this);
		}
		else if (v_command[0]->s_str() == "east" || v_command[0]->s_str() == "e"){
			dir = 2;
			player->go(dir, this);
		}
		else if (v_command[0]->s_str() == "west" || v_command[0]->s_str() == "w"){
			dir = 3;
			player->go(dir, this);
		}

		//Quit
		else if (v_command[0]->s_str() == "quit" || v_command[0]->s_str() == "q"){
			for (int i = 0; i < this->rooms.num_elements; i++){
				delete rooms[i];
			}
			for (int i = 0; i < this->exits.num_elements; i++){
				delete exits[i];
			}
			for (int i = 0; i < this->objects.num_elements; i++){
				delete objects[i];
			}
			delete player;

			return true;
		}
		//Help

		else if (v_command[0]->s_str() == "help" || v_command[0]->s_str() == "h") {
			printf("\nCOMMANDS:\n");
			printf("\nMove: north, south, east, west   OR  go + direction\n");
			printf("Open and close: Open/close  +  direction\n");
			printf("Objects: Pick/Drop + object name\n");
			printf("         Put/Take <object name> into/from <chest name>\n");
			printf("         Look + object name\n");
		}
		//Look
		else if (v_command[0]->s_str() == "look" || v_command[0]->s_str() == "l") {
			printf("You are in %s. %s\n", player[0].position->name, player[0].position->description);
		}
		else if (v_command[0]->s_str() == "inventory" || v_command[0]->s_str() == "inv" || v_command[0]->s_str() == "i") {
			player->look_inventory(this);
		}
		else printf("Invalid command\n");
		break;




	case 2:   // 2 arguments
		//Go --
		if (v_command[0]->s_str() == "go" || v_command[0]->s_str() == "g"){
			if (v_command[1]->s_str() == "north" || v_command[1]->s_str() == "n"){
				dir = 0;
			}
			else if (v_command[1]->s_str() == "south" || v_command[1]->s_str() == "s"){
				dir = 1;
			}
			else if (v_command[1]->s_str() == "east" || v_command[1]->s_str() == "e"){
				dir = 2;
			}
			else if (v_command[1]->s_str() == "west" || v_command[1]->s_str() == "w"){
				dir = 3;
			}
			player->go(dir, this);
		}
		//Open --
		else if (v_command[0]->s_str() == "open" || v_command[0]->s_str() == "o") {
			if (v_command[1]->s_str() == "north" || v_command[1]->s_str() == "n") {
				dir = 0;
			}
			else if (v_command[1]->s_str() == "south" || v_command[1]->s_str() == "s") {
				dir = 1;
			}
			else if (v_command[1]->s_str() == "east" || v_command[1]->s_str() == "e") {
				dir = 2;
			}
			else if (v_command[1]->s_str() == "west" || v_command[1]->s_str() == "w") {
				dir = 3;
			}
			player->open(dir, this);

		}
		//Close --
		else if (v_command[0]->s_str() == "close" || v_command[0]->s_str() == "c") {
			if (v_command[1]->s_str() == "north" || v_command[1]->s_str() == "n") {
				dir = 0;
			}
			else if (v_command[1]->s_str() == "south" || v_command[1]->s_str() == "s") {
				dir = 1;
			}
			else if (v_command[1]->s_str() == "east" || v_command[1]->s_str() == "e") {
				dir = 2;
			}
			else if (v_command[1]->s_str() == "west" || v_command[1]->s_str() == "w") {
				dir = 3;
			}
			player->close(dir, this);

		}
		else if (v_command[0]->s_str() == "look" || v_command[0]->s_str() == "l") {
			if (v_command[1]->s_str() == "north" || v_command[0]->s_str() == "n"){
				dir = 0;
			}
			else if (v_command[1]->s_str() == "south" || v_command[1]->s_str() == "s"){
				dir = 1;
			}
			else if (v_command[1]->s_str() == "east" || v_command[1]->s_str() == "e") {
				dir = 2;
			}
			else if (v_command[1]->s_str() == "west" || v_command[1]->s_str() == "w") {
				dir = 3;
			}
			else if (v_command[1]->s_str() == "me" || v_command[1]->s_str() == "m" || v_command[1]->s_str() == "yourself" || v_command[1]->s_str() == "y"){
				dir = 4;
			}
	else{
	player->look_item(v_command[1]->s_str(), this);
	}
	player->look(dir, this);
	}
		
		else if (v_command[0]->s_str() == "pick" || v_command[0]->s_str() == "p") {
			player->pick(v_command[1]->s_str(), this);
	}

		else if (v_command[0]->s_str() == "drop" || v_command[0]->s_str() == "drop") {
			player->drop(v_command[1]->s_str(), this);
	}


	break;
	case 3: 	if (v_command[0]->s_str() == "look" || v_command[0]->s_str() == "l"){
			player->look_into(v_command[2]->s_str(), this);
	}break;
	case 4:
		if (v_command[0]->s_str() == "put"){
			player->put(v_command[1]->s_str(), v_command[3]->s_str(), this);
	}
		else if (v_command[0]->s_str() == "take"){
			player->take(v_command[1]->s_str(), v_command[3]->s_str(), this);
	}
	break;
	

	}
			return false;
		}
	

	



	
