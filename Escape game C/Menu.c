#include<stdio.h>

#define DEFAULT_TEXT_COLOR 15
#define DEFAULT_SELECTION_COLOR 240

#define MAIN_ITENS {{2,1, "Jogar"},\
				   {2,3, "Selecionar Mapa"},\
				   {2,5, "Sobre"},\
				   {2,7, "Fechar"}}; 
				   
#define MAP_ITENS {{2,1, "Mapa 1"},\
				   {2,3, "Mapa 2"},\
				   {2,5, "Mapa 3"},\
				   {2,7, "Voltar"}};

typedef struct MenuItem{
	int x, y;
	char text[25];
} MenuItem;

int selectedMenuItem = 0;

void selectMenuItem(MenuItem *items){
	gotoxy(items[selectedMenuItem].x, items[selectedMenuItem].y);
	
	printSelMenuItem(items, DEFAULT_SELECTION_COLOR);
	
	gotoxy(items[selectedMenuItem].x, items[selectedMenuItem].y);
}

void printSelMenuItem(MenuItem *items, int color){
	setColor(color);
	printf("%s", items[selectedMenuItem].text);
	setColor(DEFAULT_TEXT_COLOR);
}

void incrementSelectedMI(int k, MenuItem *items, int len){
	printSelMenuItem(items, DEFAULT_TEXT_COLOR);	

	if (k=='W'){
		if (selectedMenuItem != 0)
			selectedMenuItem--;
	}		
	else if (k=='S'){
		if (selectedMenuItem < len-1)
			selectedMenuItem++;
	}		
	else 
		return;
		
	setColor(DEFAULT_TEXT_COLOR);
	selectMenuItem(items);
}

void about(){
	CLEAR;
	printf("\n  Desenvolvido por Supreme Developer (ConradoPSA)\n");
	scanf("%*c");
}

#define loadMenu(MITEMS) 	CLEAR;\
	hidecursor();\
\
	MenuItem items[] = MITEMS;\
	\
	int i, len = sizeof(items) / sizeof(MenuItem);\
	\
	setColor(DEFAULT_TEXT_COLOR);\
	\
	for(i=0; i<len; i++){\
		gotoxy(items[i].x, items[i].y);\
		printf("%s\n", items[i].text);\
	}\
	\
	selectMenuItem(items);\
	\
	int k;\
	forever

#define changeItemMenu()	k = toupper(getch());\
							if(k=='W' || k=='S')\
					   			incrementSelectedMI(k, items, len);

void setMap(Map m[MAP_H][MAP_W]){
	int i;
	
	for (i=0; i<MAP_H; i++){
		memset(map[i], 0, sizeof(map[i]));
		strcpy(map[i], m[i]);
	}
}

void selectMap(){
	loadMenu(MAP_ITENS){
		
		changeItemMenu();
		
		//Enter
		if (k==13){
			if (selectedMenuItem == 0){				
				setMap(map_1);				
			}
			else if (selectedMenuItem == 1){
				setMap(map_2);
			}
			else if (selectedMenuItem == 2){
				setMap(map_3);
			}
				
			return;
		}
	}
}

void menu(){
	reloadMenu:
		
	loadMenu(MAIN_ITENS) {
					
		changeItemMenu();
		
		//Enter
		if (k==13){
			if (selectedMenuItem == 0){
				game(); 
				goto reloadMenu;
			}				
			else if (selectedMenuItem == 1){
				selectMap();
				goto reloadMenu;
			}
			else if (selectedMenuItem == 2){
				about();
				goto reloadMenu;
			}				
			else if (selectedMenuItem == 3)
				exit(0);
		}
			
	}
}

