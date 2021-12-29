#include "head.h"


void showInterf() {
	int i; //메인페이지 창 40*20
	gotoxy(STA_X, STA_Y);
	printf("#");
	for (i = 1; i < INTERF_WIDTH + 1; i++) {
		printf("#");
	}
	printf("#");

	for (i = 1; i < INTERF_HEIGHT + 1; i++) {
		gotoxy(STA_X, STA_Y + i); printf("#");
	}
	gotoxy(STA_X, STA_Y + INTERF_HEIGHT + 1);
	printf("#");

	for (i = 1; i < INTERF_WIDTH + 1; i++) {
		printf("#");
	}
	printf("#");

	gotoxy(STA_X + INTERF_WIDTH, STA_Y);
	for (i = 1; i < INTERF_HEIGHT + 1; i++) {
		gotoxy(STA_X + INTERF_WIDTH + 1, STA_Y + i); printf("#");
	}

	gotoxy(STA_X + INTERF_WIDTH + 4, STA_Y); // 84, 2
	printf("LEVEL : ");
	gotoxy(STA_X + INTERF_WIDTH + 4, STA_Y+2); //84, 4
	printf("TIME : "); //94, 4
	gotoxy(STA_X + INTERF_WIDTH + 4, STA_Y + 4); //84, 6
	printf("ITEM : "); //94, 6
	gotoxy(STA_X + INTERF_WIDTH + 4, STA_Y + 6); //84, 8
	printf("STATE : "); //94, 8

}