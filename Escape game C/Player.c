typedef struct Player{
	char chr;
	int x, y;
} Player;

Player createPlayer(char chr, int x, int y){
	Player p;
	p.chr = chr;
	p.x = x;
	p.y = y;
	
	return p;
}

void drawPlayer(Player p){
	waitConsole();
	occupyConsole();
	
	gotoxy(p.x, p.y);			
	printf("%c", p.chr);
	
	freeConsole();
}

int allowMove(Player p, char move){
	//move: 'W'(up), 'S'(down), 'A'(left), 'D'(right)
	move = toupper(move);
	
	if(move == 'D' && map[p.y][p.x+1] == ' ')
		return 1;		
	else if(move == 'W' && map[p.y-1][p.x] == ' ')
		return 1;		
	else if(move == 'A' && map[p.y][p.x-1] == ' ')
		return 1;		
	else if(move == 'S' && map[p.y+1][p.x] == ' ')
		return 1;
	
	return 0;
}

int movePlayer(Player *p, char k){
	//k: 'W'(up), 'S'(down), 'A'(left), 'D'(right)
	
	if (k=='D' && allowMove(*p, k) && p->x++)
		return 1;
	else if (k=='W' && allowMove(*p, k) && p->y--)
		return 1;
	else if (k=='A' && allowMove(*p, k) && p->x--)
		return 1;
	else if (k=='S' && allowMove(*p, k) && p->y++)
		return 1;
	
	return 0;
}

char findWay(Player p, Player e){
	/*//return: 'W'(up), 'S'(down), 'A'(left), 'D'(right)
	
	char moves[500], i=0;
	
	//Invisible copy of player main
	while(e.x != p.x || e.y != p.y){
		if (movePlayer(&e, 'W'))
			moves[i++] = 'W';
		else if (movePlayer(&e, 'D')
			moves[i++] = 'D';
		else if (movePlayer(&e, 'S')
			moves[i++] = 'S';
		else if (movePlayer(&e, 'A')
			moves[i++] = 'A';
	}
			
	return moves[0];	*/
	return 'A';
}
