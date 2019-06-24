#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>
#include <string.h>

#include "Console.c"
#include "Maps.c"

Map map[MAP_H][MAP_W];

#define CLEAR system("cls")
#define PAUSE system("pause")
#define forever while(1)

#include "Player.c"
#include "Menu.c"

#define PLAYER_START_POINT 3, 1
#define ENEMY_START_POINT 32, 14

int enemy_th_close;
void *enemy(void *arg){
	enemy_th_close = 0;
	
	//Player main
	Player * p = (Player *)arg;
	
	//Player Enemy
	Player e = createPlayer('@', ENEMY_START_POINT);
	drawPlayer(e);
		
	while(1){
		
		if (enemy_th_close)
			return;	
				
		redrawMap(map, e.x, e.y);
		
		movePlayer(&e, findWay(*p, e));	

		drawPlayer(e);
		
		delay(400);
	}
}


void game(){
	CLEAR;
	hidecursor();
	
	printMap(map, MAP_H, MAP_W);
	
	//Player Main
	Player p = createPlayer('A', PLAYER_START_POINT);
	drawPlayer(p);
		
	//New thread for Player Enemy
	pthread_t th;	
	pthread_create(&th, NULL, enemy, (void *)&p);
	
	//Fixing bug
	gotoxy(0,0);
	
	char k; //Key pressed
	forever {
		//Waiting Key
		k = toupper(getch());	
		
		redrawMap(map, p.x, p.y);
		
		//Keys pressed to movement
		if ((k=='D' || k=='W' || k=='A' || k=='S'))
		   movePlayer(&p, k);
		   
		//Menu (Esc)
		if (k==27){
			enemy_th_close = 1;
			return;
		}
		
		drawPlayer(p);
		
	}
}

int main(){
	//Default Value
	setMap(map_1);
		
	menu();
}
