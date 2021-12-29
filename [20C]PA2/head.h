#pragma once
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32

#define STA_X 20 // 테두리(네모박스) 시작 x
#define STA_Y 2 // 테두리 시작 y
#define MID_X 40 //화면 정중앙 x
#define MID_Y 12 //화면 정중앙 y

#define INTERF_WIDTH 40 //테두리 가로
#define INTERF_HEIGHT 20 //테두리 세로
#define WIDTH 20 // 맵 가로
#define HEIGHT 20 //맵 세로

//#define BLACK 0
#define BLUE 1
#define GREEN 2
#define OKK 3
#define RED 4
#define VIOLET 5
#define GOLD 6
#define WHITE 7 
#define GRAY 8
#define SKY 9
#define MINT 10
#define DOWNOKK 11
#define DOWNRED 12
#define DOWNVI 13
#define YELLOW 14
#define WWHITHE 15


//gotoxy.c / removeCursor.c
void gotoxy(int, int);
void RemoveCursor();

//play.c
int playGame(int);

//interface.c
void showInterf();

//showPage.c
int loadPage();
void showBorder();
void showMain();
void showGameGuide();
void showLevelPage();
void printOpening();
void showLoading();
void showFail();
void showClear();
void askReplay();
void showReturnMain();
void showEnding();
void printEnding();
void showString(char*, int);