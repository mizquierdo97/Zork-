#include "player.h"

/*
bool Player::Go(char *, int dir)
{
	
		int door = NULL;
		if (dir == 0) {
			for (int i = 0; i < 24; i++) {
				if (exits[i].origin== player[0].position && exits[i].direction == south) {
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

		else if (dir == 1) {
			for (int i = 0; i < 24; i++) {
				if (exits[i].origin == player[0].position && exits[i].direction == north) {
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

		else if (dir == 2) {
			for (int i = 0; i < 24; i++) {
				if (exits[i].origin == player[0].position && exits[i].direction == east) {
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

		else if (dir == 3) {
			for (int i = 0; i < 24; i++) {
				if (exits[i].origin == player[0].position && exits[i].direction == west) {
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
		else {
			printf("Wrong Way");
			return false;
		}

	}*/

