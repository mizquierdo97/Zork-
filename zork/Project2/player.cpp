#include "player.h"


Player::Player(const char* name, const char* description, Room* position) : Entity(name, description, PLAYER), position(position)
{

}

/*
void Player::go(char* inst, int dir, World* world ){
	int door = NULL;

	for (int n = 0; n < 4; n++){
		if (dir == n){
			
			
			for (int i = 0; i < 20; i++){
				if (world.exits.origin == player.position && exits[i].direction == n){
					if (exits[i].open == false) {
						printf("The door is closed\n");
						door++;
					}
					else {
						door++;
						player[0].position = exits[i].destination;
						
					}
				}
			}
			if (door == NULL) printf("There are no exits in this way\n");
		}
	}
	
}*/