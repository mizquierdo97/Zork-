
#include "world.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

Player::Player(){
	for (int i = 0; i < 30; i++){
		inventory[i] = 0;
	}
}
/*
bool Player::go(char* inst, int dir){
	int door = NULL;
	World* w = nullptr;
	w =  new World();
	for (int n = 0; n < 4; n++){
		if (dir == n){
			for (int i = 0; i < 24; i++){
				if (w->exits[i].origin == w->player[0].position && w->exits[i].direction == n){
					if (w->exits[i].open == false) {
						printf("The door is closed\n");
						door++;
					}
					else {
						door++;
						w->player[0].position = w->exits[i].destination;
						return true;
					}
				}
			}
			if (door == NULL) printf("There are no exits in this way\n");
		}
	}
	return false;
}*/