#include "world.h"
#include <stdlib.h>

void World::loop(){
	char direct;
	printf("%s\n%s", rooms[0].name, rooms[0].description);
	scanf_s("%c", &direct);
	printf("\n%i   %i\n", player[0].position, exits[0].destination);
	switch (direct){
	case 's':
		for (int i = 0; i < 24; i++){
			if (exits[i].origin == player[0].position && exits[0].direction == south){
				
				player[0].position = exits[i].destination;
				
				
				break;
			}
			
			
		}
		printf("There're no exits at south\n");
		system("Pause");
		break;
	case 'n':
		for (int i = 0; i < 24; i++){
			if (exits[i].origin == player[0].position && exits[i].direction == north){

				player[0].position = exits[i].destination;
			
				break;
			}

		}
		printf("There're no exits at north\n");
	
		break;
	case 'e':
		for (int i = 0; i < 24; i++){
			if (exits[i].origin == player[0].position && exits[i].direction == east){

				player[0].position = exits[i].destination;
				
				break;
			}

		}
		printf("There're no exits at east\n");
		
		break;
	case 'w':
		for (int i = 0; i < 24; i++){
			if (exits[i].origin == player[0].position && exits[i].direction == west){

				player[0].position = exits[i].destination;
				
				break;
			}

		}
		printf("There're no exits at west\n");
		
		break;

	}
}