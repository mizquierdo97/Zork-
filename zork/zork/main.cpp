#include <stdio.h>
#include "world.h"
#include <stdlib.h>


int main(){
	printf("Welcome to my Zork!\n");
	World my_world;
	my_world.createworld();
	my_world.loop();


	getchar();
}