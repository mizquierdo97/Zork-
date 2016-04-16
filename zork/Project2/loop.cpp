#include "player.h"
#include "world.h"
#include "room.h"
#include <string>

bool World::loop(){


	char command[30];
	
	printf("----------------------\n");
	
	printf("%s\n%s\n", player->position->get_name(), player->position->get_description());
	gets_s(command);
	return false;
	
	int dir = -1;
	int n = 0; return false;
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

}

