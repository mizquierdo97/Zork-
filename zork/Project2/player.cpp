#include "player.h"
#include "world.h"


Player::Player(const char* name, const char* description) : Entity(name, description, PLAYER)
{


}
Player::Player(const char* name, const char* description,Room* position) : Entity(name, description, PLAYER), position(position)
{

}


void Player::go( int dir, const World* world ){
	int door = NULL;

	for (int n = 0; n < 4; n++){
		if (dir == n){
			
			
			for (int i = 0; i < 20; i++){
				if (world->exits[i]->origin == this->position && world->exits[i]->direction == n){
					if (world->exits[i]->open == false) {
						printf("The door is closed\n");
						door++;
					}
					else {
						door++;
						this->position = world->exits[i]->destination;
						
					}
				}
			}
			if (door == NULL) printf("There are no exits in this way\n");
		}
	}
	
}

void Player::look(int dir,const World* world)const{
	int look = 0;
	for (int n = 0; n < 4; n++){
		if (dir == n) {
			for (int i = 0; i < world->rooms.num_elements ; i++) {
				if (world->exits[i]->origin == this->position && world->exits[i]->direction == n) {
					printf("%s\n", world->exits[i]->description);
					look++;
				}

			}

			if (look < 1){ printf("You are watching a wall. GJ!\n"); }
		}

	}
	if (dir == 4)
	{
		printf("%s\n", this->description); look++;
	}
}
