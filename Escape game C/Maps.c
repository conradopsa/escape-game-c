#define Map char

#define MAP_H 100
#define MAP_W 100

				
Map map_1[MAP_H][MAP_W] = {"######################################",
						   "###                            #   ###",
						   "### ########### ############## ### ###",
						   "############### ############## ### ###",
						   "############### ##### ######## ### ###",
						   "###############           #### ### ###",
						   "################# ####### #### ### ###",
						   "##           #### ####### #### ### ###",
						   "## ### ##### #### ####### #### ### ###",
						   "## ### #####      ####### #### ### ###",
						   "## ### ################## ####      ##",
						   "## ### ################## #### #### ##",
						   "## ###################### #### #### ##",
						   "## ########################### #### ##",
						   "##                                  ##",
						   "######################################"};
						   
Map map_2[MAP_H][MAP_W] = {"###################################",
						   "##                               ##",
						   "## #### #### #### #### #### #### ##",
						   "## #### #### #### #### #### #### ##",
						   "## #### #### #### #### #### #### ##",
						   "## #### #### #### #### #### #### ##",
						   "## #### #### #### #### #### #### ##",
						   "##                               ##",
						   "## #### #### #### #### #### #### ##",
						   "## #### #### #### #### #### #### ##",
						   "## #### #### #### #### #### #### ##",
						   "## #### #### #### #### #### #### ##",
						   "## #### #### #### #### #### #### ##",
						   "##                               ##",
						   "###################################"};
						   
Map map_3[MAP_H][MAP_W] = {"#################################################################",
						   "##                                                             ##",
						   "##                                                             ##",
						   "##                                                             ##",
						   "##                                                             ##",
						   "##                                                             ##",
						   "##                                                             ##",
						   "##                                                             ##",
						   "##                                                             ##",
						   "##                                                             ##",
						   "##                                                             ##",
						   "##                                                             ##",
						   "##                                                             ##",
						   "##                                                             ##",
						   "##                                                             ##",
						   "##                                                             ##",
						   "##                                                             ##",
						   "##                                                             ##",
						   "#################################################################"};
				
void printMap(Map map[MAP_H][MAP_W], int a, int l){
	waitConsole();
	occupyConsole();
	
	int i, j;
	for (i=0; i<a; i++){
		for (j=0; j<l; j++){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	
	freeConsole();
}

void redrawMap(Map map[MAP_H][MAP_W], int x, int y){
	waitConsole();
	occupyConsole();
	
	//Refresh partial map;
	gotoxy(x, y);
	printf("%c", map[y][x]);
	
	freeConsole();
}

void refreshMap(Map map[MAP_H][MAP_W]){
	waitConsole();
	occupyConsole();
	
	//Refresh all map
	system("cls");
	printMap(map, MAP_H, MAP_W);
	
	freeConsole();
}

