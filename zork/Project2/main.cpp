#include "world.h"
#include "MemoryLeaks.h"

int main(){
	printf("Welcome to my zork game: \"Scape the prison\"\n");
	ReportMemoryLeaks();
	bool quit = false;
	World my_world;
	my_world.createworld();
	while (quit != true){
		quit = my_world.loop();
	}
	
	return 0;
}