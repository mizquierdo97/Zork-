#include "world.h"
#include "MemoryLeaks.h"

int main(){
	
	ReportMemoryLeaks();
	bool quit = false;
	World my_world;
	my_world.createworld();
	printf("Welcome to my zork game: \"Scape the prison\"\n");
	//loop
	while (quit != true){
		quit = my_world.loop();
	}
	
	return 0;
}