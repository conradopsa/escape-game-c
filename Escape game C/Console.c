#include <windows.h>
#include <time.h>

int consoleOccupied = 0;

void waitConsole(){
	while(consoleOccupied);
}

void occupyConsole(){
	consoleOccupied = 1;
}

void freeConsole(){
	consoleOccupied = 0;
}

void delay(int mili){
	clock_t startTime = clock();
	
	while(clock() < startTime + mili);
}

void setColor(int k){	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hidecursor(){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

