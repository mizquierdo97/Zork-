#include "player.h"
#include "world.h"


Player::Player(const char* name, const char* description) : Entity(name, description, PLAYER)
{


}
Player::Player(const char* name, const char* description,Room* position) : Entity(name, description, PLAYER), position(position)
{

}


bool Player::go( int dir, const World* world ){
	int door = NULL;

	for (int n = 0; n < 4; n++){
		if (dir == n){
			
			
			for (int i = 0; i < world->exits.num_elements; i++){
				if (world->exits[i]->origin == this->position && world->exits[i]->direction == n){
					if (world->exits[i]->open == false) {
						printf("The door is closed\n");
						door++;
						return false;
					}
					else {
						door++;
						this->position = world->exits[i]->get_destination();
						return  true;
					}
				}
			}
			if (door == NULL) printf("There are no exits in this way\n");
			return false;
		}
	}
	
}

void Player::look(int dir,const World* world)const{
	int look = 0;
	for (int n = 0; n < 4; n++){
		if (dir == n) {
			for (int i = 0; i < world->rooms.num_elements ; i++) {
				if (world->exits[i]->origin == this->position && world->exits[i]->direction == dir) {
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

//Open Function
bool Player::open(int dir, const World* world) {
	bool door = false;
	for (int n = 0; n < 4; n++){
		if (dir%2 == 0) {
			for (int i = 0; i < world->exits.num_elements; i++) {
				if (world->exits[i]->origin == this->position && world->exits[i]->direction == dir) {
					if (world->exits[i]->open == false) {
						world->exits[i]->open = true;
						world->exits[i - 1]->open = true;
						printf("The door is now open\n");
						door = true;
						return true;
					}
					else printf("The door is open\n");
					door = true;
					return false;
				}
				
			}
			if (door == false && n==4){ printf("there are no exits in this way\n");
			return false; }
		}
		else{
			for (int i = 0; i < world->exits.num_elements; i++) {
				if (world->exits[i]->origin == this->position && world->exits[i]->direction == dir) {
					if (world->exits[i]->open == false) {
						world->exits[i]->open = true;
						world->exits[i + 1]->open = true;
						printf("The door is now open\n");
						door = true;
						return true;
					}
					else printf("The door is open\n");
					door = true;
					return false;
				}
				
			}
			if (door == false && n==4){
				printf("there are no exits in this way\n");
				return false;
			}
		}
	}
}

//Close Function
bool Player::close( int dir,const World* world) {
	bool door = false;
	for (int n = 0; n < 4; n++){
		if (dir % 2 == 0) {
			for (int i = 0; i < world->exits.num_elements; i++) {
				if (world->exits[i]->origin == this->position && world->exits[i]->direction == dir) {
					if (world->exits[i]->open == true) {
						world->exits[i]->open = false;
						world->exits[i - 1]->open = false;
						printf("The door is now closed\n");
						door = true;
						return true;
					}
					else printf("The door is closed\n");
					door = true;

				}

			}
			if (door == false && n==4){
				printf("there are no exits in this way\n");
				return false;
			}
		}
		else{
			for (int i = 0; i < world->exits.num_elements; i++) {
				if (world->exits[i]->origin == this->position && world->exits[i]->direction == dir) {
					if (world->exits[i]->open == true) {
						world->exits[i]->open = false;
						world->exits[i + 1]->open = false;
						printf("The door is now closed\n");
						door = true;
						return true;
					}
					else printf("The door is closed\n");
					door = true;
					return false;
				}
				
			}
			if (door == false&& n==4){
				printf("there are no exits in this way\n");
				return false;
			}
		}
	}
}

void Player::look_item(const char* name,const World* world)const{
	for (int i = 0; i < world->objects.num_elements; i++){
		char* name2;
		name2 = world->objects[i]->get_name();
		if (name == name2){
			printf("%s", world->objects[i]->get_description());
		}
	}
}