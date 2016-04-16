#include "world.h"

int main(){
	bool quit = false;
	World my_world;
	my_world.createworld();
	while (quit != true){
		quit = my_world.loop();
	}
	return 0;
}