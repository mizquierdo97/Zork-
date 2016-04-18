#include "player.h"
#include "world.h"


Player::Player(const char* name, const char* description) : Entity(name, description, PLAYER)
{


}
Player::Player(const char* name, const char* description,Room* position) : Entity(name, description, PLAYER), position(position)
{

}

//Go method
bool Player::go( int dir, const World* world ){
	int door = NULL;

	for (int n = 0; n < 4; n++){
		if (dir == n){			
			for (int i = 0; i < world->exits.num_elements; i++){
				if (world->exits[i]->origin == this->position && world->exits[i]->direction == dir){
					if (world->exits[i]->open == false) {
						printf("\nThe door is closed\n");
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
			if (door == NULL) printf("\nThere are no exits in this way\n");
			return false;
		}
	}
	
}

//Look Method
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

			if (look < 1){ printf("\nYou are watching a wall. GJ!\n"); }
		}

	}
	if (dir == 4)
	{
		printf("\n%s\n", this->description); look++;
	}
}

//Open Method
bool Player::open(int dir, const World* world) {
	bool door = false;
	for (int n = 0; n < 4; n++){
		if (dir%2 == 0) {
			for (int i = 0; i < world->exits.num_elements; i++) {
				if (world->exits[i]->origin == this->position && world->exits[i]->direction == dir) {
					if (world->exits[i]->open == false) {
						world->exits[i]->open = true;
						world->exits[i - 1]->open = true;
						printf("\nThe door is now open\n");
						door = true;
						return true;
					}
					else printf("\nThe door is open\n");
					door = true;
					return false;
				}
				
			}
			if (door == false && n==4){ printf("\nThere are no exits in this way\n");
			return false; }
		}
		else{
			for (int i = 0; i < world->exits.num_elements; i++) {
				if (world->exits[i]->origin == this->position && world->exits[i]->direction == dir) {
					if (world->exits[i]->open == false) {
						world->exits[i]->open = true;
						world->exits[i + 1]->open = true;
						printf("\nThe door is now open\n");
						door = true;
						return true;
					}
					else printf("\nThe door is open\n");
					door = true;
					return false;
				}
				
			}
			if (door == false && n==4){
				printf("\nThere are no exits in this way\n");
				return false;
			}
		}
	}
}

//Close Method
bool Player::close( int dir,const World* world) {
	bool door = false;
	for (int n = 0; n < 4; n++){
		if (dir % 2 == 0) {
			for (int i = 0; i < world->exits.num_elements; i++) {
				if (world->exits[i]->origin == this->position && world->exits[i]->direction == dir) {
					if (world->exits[i]->open == true) {
						world->exits[i]->open = false;
						world->exits[i - 1]->open = false;
						printf("\nThe door is now closed\n");
						door = true;
						return true;
					}
					else printf("\nThe door is closed\n");
					door = true;

				}

			}
			if (door == false && n==4){
				printf("\nThere are no exits in this way\n");
				return false;
			}
		}
		else{
			for (int i = 0; i < world->exits.num_elements; i++) {
				if (world->exits[i]->origin == this->position && world->exits[i]->direction == dir) {
					if (world->exits[i]->open == true) {
						world->exits[i]->open = false;
						world->exits[i + 1]->open = false;
						printf("\nThe door is now closed\n");
						door = true;
						return true;
					}
					else printf("\nThe door is closed\n");
					door = true;
					return false;
				}
				
			}
			if (door == false&& n==4){
				printf("\nThere are no exits in this way\n");
				return false;
			}
		}
	}
}
//Look item method
void Player::look_item(const String& name,const World* world)const{
	for (int i = 0; i < world->objects.num_elements; i++){
		if (world->objects[i]->position == this->position){
		String name2;
		name2 = world->objects[i]->get_name();
		if (name == name2){
			printf("\n%s\n", world->objects[i]->get_description());
		}
		}
	}
}
//pick method
bool Player::pick(const String& name, const World* world){
	for (int i = 0; i < world->objects.num_elements; i++){
		if (world->objects[i]->take == false){
			printf("\nYou can't pick this object\n");
		}
		else if (world->objects[i]->position == this->position ){
			String name2;
			name2 = world->objects[i]->get_name();
			if (name == name2){
				Inventory.push_back(new Object(world->objects[i]->get_name(), world->objects[i]->get_description()));
				world->objects[i]->position = nullptr;
				printf("You pick %s\n", world->objects[i]->get_name());
				return true;
			}
		}
		printf("\nThere's nothing in the room called %s\n", name);
		return false;
	}
}

//drop method
bool Player::drop(const String& name, const World* world){
	for (int i = 0; i < world->objects.num_elements; i++){
		String name2;
		name2 = world->objects[i]->get_name();
		if (name == name2){
			world->objects[i]->position = this->position;
			Inventory.remove(i);
			return true;
		}
		printf("\nThere's nothing in your inventory called %s\n", name);
		return false;
	}
}

//inventory method
void Player::look_inventory(const World* world)const{
	if (this->Inventory.num_elements== 0){
		printf("\nYou have nothing in your inventory\n");
	}
	else{
		for (int i = 0; i < this->Inventory.num_elements; i++){
			printf("\n%s\t%s\n", world->player->Inventory[i]->get_name(), world->player->Inventory[i]->get_description());
		}
	}

}
 //put method
bool Player::put(const String& name, const String& name2, const World* world){
	String o_name;//object name
	String c_name;//chest name
	if (this->Inventory.num_elements == 0){
		printf("\nYou have nothing in your inventory\n");
	}
	else{
		for (int i = 0; i < this->Inventory.num_elements; i++){

			o_name = this->Inventory[i]->get_name();
			if (name == o_name){
				for (int n = 0; n < world->objects.num_elements; n++){
					c_name = world->objects[n]->get_name();
					if (name2 == c_name && this->position == world->objects[n]->position){

						world->objects[n]->Inventory.push_back(new Object(this->Inventory[i]->get_name(), this->Inventory[i]->get_description()));
						printf("\nYou put %s into %s\n", this->Inventory[i]->get_name(), world->objects[n]->get_name());
						Inventory.remove(i);
						return true;

					}
					
				}
				printf("\nThere's nothing in the room called %s\n", name2);
				return false;
			}
			
		}
		printf("\nYou have nothing called %s\n", name);
		return false;
	}
}

//take method
bool Player::take(const String& name, const String& name2, const World* world){
	String o_name;//object name
	String c_name;//chest name
	for (int n = 0; n < world->objects.num_elements; n++){
		c_name = world->objects[n]->get_name();
		if (name2 == c_name && this->position == world->objects[n]->position){
			for (int i = 0; i < world->objects[n]->Inventory.num_elements; i++){
				o_name = world->objects[n]->Inventory[i]->get_name();
				if (name == o_name){
					this->Inventory.push_back(new Object(world->objects[n]->Inventory[i]->get_name(), world->objects[n]->Inventory[i]->get_description()));
					printf("\nYou take %s from %s\n", world->objects[n]->Inventory[i]->get_name(), world->objects[n]->get_name());
					world->objects[n]->Inventory.remove(i);
					
					return true;
				}
			}
			printf("\nThere's nothing called %s into ", name); printf("%s\n", name2);
			return false;
		}
	}
}

//look into method
void Player::look_into(const String& name, const World* world)const{
	for (int i = 0; i < world->objects.num_elements; i++){
		if (world->objects[i]->position == this->position){
			String name2;
			name2 = world->objects[i]->get_name();
			if (name == name2){
				printf("\nName\t Description\n----\t-----------\n");
				for (int n = 0; n < world->objects[i]->Inventory.num_elements; n++){
					printf("%s\t", world->objects[i]->Inventory[n]->get_name());
					printf("%s\n", world->objects[i]->Inventory[n]->get_description());
				}
			}
		}
	}
}


