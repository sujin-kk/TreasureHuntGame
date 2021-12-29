#include "head.h"

int map[HEIGHT][WIDTH]; //전역

int playGame(int level) {
	RemoveCursor();
	int item; //item 1.시간2초증가 2.시간2초감소 3.보물아닌플래그오픈 4.2초동안 방향키 반대로 //5 안보이기

	//맵 생성 
	int map[HEIGHT][WIDTH]; //20*20 이차원배열
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			map[i][j] = 0;
		}
	} //모두 0으로 초기화

	//플래그, 보물 생성
	int num = 0, flag = 0, time_limit = 0, isTre = 0;
	if (level == 1) {
		flag = 5;
		time_limit = 15;
	}
	else if (level == 2) {
		flag = 9;
		time_limit = 10;
	}
	else if (level == 3) {
		flag = 13;
		time_limit = 6;
	}

	while (num != flag) {
		int n = 0;
		int tx = rand() % WIDTH;
		int ty = rand() % HEIGHT;
		if (map[tx][ty] == 0) {
			map[tx][ty] = 1; // 플래그 저장
			if (!isTre) {
				map[tx][ty] = 3; // 보물 저장, 보물은 항상 1개
				isTre = 1;
			}
			num++;
		}
	}

	system("cls");
	showInterf();
	int mx = STA_X + 1; //21
	int my = STA_Y + 1; //3
	gotoxy(mx, my);
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			gotoxy(mx + 2 * j, my + i);
			if (map[i][j] == 0) {
				printf("  "); //미오픈
			}
			else if (map[i][j] == 1) {
				printf("▶"); //플래그
			}
			else if (map[i][j] == 2) {
				printf("▷"); //플래그 오픈
			}
			else {
				printf("▶"); //보물
			}
		}
		printf("\n");
	}


	int x = 21, y = 22; //커서 시작
	int sec = time_limit * 100;

	//100sec -> 1초
	//10sec -> 0.1초
	while (1) {
		gotoxy(74, 2);
		printf("%d", level); //level 출력

		Sleep(10); // 0.1초슬립
		if (sec % 100 == 0) { //2000, 1900, 1800,,,
			if (sec / 100 < 0) { // 0초 밑, fail
				system("cls");
				return 0;
			}
			gotoxy(74, 4);
			printf("%02d", sec / 100);
		}
		sec--; //time 출력

		gotoxy(x, y);
		printf("◆"); //커서
		if (_kbhit()) { //키입력감지
			int key = _getch(); // key 키보드 값
			int space = 0;

			switch (key) {
			case LEFT:
				if (x > 21)x -= 2;
				break;
			case RIGHT:
				if (x < 59)x += 2;
				break;
			case UP:
				if (y > 3)y--;
				break;
			case DOWN:
				if (y < 22)y++;
				break;
			case SPACE:
				space = 1;
				break;
			}

			if (x < 21)x = 21;
			else if (x > 59)x = 59;
			if (y < 3)y = 3;
			else if (y > 22)y = 22;

			printf("\b\b  ");
			gotoxy(x, y);
			printf("◆");

			if (space == 1) //선택하면
			{
				if (map[y - 3][(x - 21) / 2] == 1) { //일반 플래그 선택하면
					item = rand() % 6; // 0 1 2 3 4 5 

					map[y - 3][(x - 21) / 2] = 2; //플래그 오픈
					system("cls");

					if (item == 1) { //시간 4초추가
						gotoxy(74, 8);
						printf("+ 4초 증가");
						sec += 400;
					}

					else if (item == 2) { //시간 2초감소
						gotoxy(74, 8);
						printf("- 2초 감소");
						sec -= 200;
					}

					else if (item == 3) { //보물 아닌 플래그 오픈
						int isOpen = 0;
						gotoxy(74, 8);
						printf("다른 플래그 열림");

						for (int i = 0; i < HEIGHT; i++) {
							for (int j = 0; j < WIDTH; j++) {
								if (!isOpen) {
									if (map[j][i] == 1) {
										map[j][i] = 2;
										isOpen = 1;
									}
								}
							}
						}

						showInterf();
						gotoxy(mx, my);
						for (int i = 0; i < HEIGHT; i++) {
							for (int j = 0; j < WIDTH; j++) {
								gotoxy(mx + 2 * j, my + i);
								if (map[i][j] == 0) {
									printf("  "); //미오픈
								}
								else if (map[i][j] == 1) {
									printf("▶"); //플래그
								}
								else if (map[i][j] == 2) {
									printf("▷"); //플래그 오픈
								}
								else {
									printf("▶"); //보물
								}
							}
							printf("\n");
						}

					}

					else if (item == 4) { //방향키 반대로
						clock_t t1, t2;
						t1 = clock();
						gotoxy(74, 8);
						printf("2초동안 방향키 반대(좌↔우&상↔하)");

						do {
							gotoxy(x, y);
							printf("◆"); //커서
							if (_kbhit()) { //키입력감지
								int key = _getch(); // key 키보드 값
								int space = 0;

								switch (key) {
								case LEFT:
									if (x > 20)x += 2;
									break;
								case RIGHT:
									if (x < 60)x -= 2;
									break;
								case UP:
									if (y > 2)y++;
									break;
								case DOWN:
									if (y < 23)y--;
									break;
								case SPACE:
									space = 1;
									break;
								}

								if (x < 21)x = 21;
								else if (x > 59)x = 59;
								if (y < 3)y = 3;
								else if (y > 22)y = 22;

								printf("\b\b  ");
								gotoxy(x, y);
								printf("◆");
							}
							showInterf();
							gotoxy(mx, my);
							for (int i = 0; i < HEIGHT; i++) {
								for (int j = 0; j < WIDTH; j++) {
									gotoxy(mx + 2 * j, my + i);
									if (map[i][j] == 0) {
										printf("  "); //미오픈
									}
									else if (map[i][j] == 1) {
										printf("▶"); //플래그
									}
									else if (map[i][j] == 2) {
										printf("▷"); //플래그 오픈
									}
									else {
										printf("▶"); //보물
									}
								}
								printf("\n");
							}
							t2 = clock();
						} while ((t2 - t1) < (2 * CLOCKS_PER_SEC)); //2초동안

					}

					else if (item == 5) { //맵 상태 안보이게 함
						clock_t t1, t2;
						gotoxy(74, 8);
						printf("2초동안 상태 숨김");
						t1 = clock();
						do {
							gotoxy(74, 2);
							printf("%d", level); //level 출력

							gotoxy(x, y);
							printf("◆"); //커서
							if (_kbhit()) { //키입력감지
								int key = _getch(); // key 키보드 값
								int space = 0;

								switch (key) {
								case LEFT:
									if (x > 21)x -= 2;
									break;
								case RIGHT:
									if (x < 59)x += 2;
									break;
								case UP:
									if (y > 3)y--;
									break;
								case DOWN:
									if (y < 22)y++;
									break;
								case SPACE:
									space = 1;
									break;
								}

								if (x < 21)x = 21;
								else if (x > 59)x = 59;
								if (y < 3)y = 3;
								else if (y > 22)y = 22;

								printf("\b\b  ");
								gotoxy(x, y);
								printf("◆");
							}
							showInterf();
							gotoxy(mx, my);
							for (int i = 0; i < HEIGHT; i++) {
								for (int j = 0; j < WIDTH; j++) {
									gotoxy(mx + 2 * j, my + i);
									if (map[i][j] == 0) {
										printf("  ");
									}
									else if (map[i][j] == 1) {
										printf("  ");
									}
									else if (map[i][j] == 2) {
										printf("  ");
									}
									else {
										printf("  ");
									}
								}
								printf("\n");
							}
							t2 = clock();
						} while ((t2 - t1) < (2 * CLOCKS_PER_SEC));
					}

					else { // item발동X
						gotoxy(74, 8);
						printf("빈 아이템");
					}

					showInterf();
					gotoxy(mx, my);
					for (int i = 0; i < HEIGHT; i++) {
						for (int j = 0; j < WIDTH; j++) {
							gotoxy(mx + 2 * j, my + i);
							if (map[i][j] == 0) {
								printf("  "); //미오픈
							}
							else if (map[i][j] == 1) {
								printf("▶"); //플래그
							}
							else if (map[i][j] == 2) {
								printf("▷"); //플래그 오픈
							}
							else {
								printf("▶"); //보물
							}
						}
						printf("\n");
					}
				} //플래그 선택 끝

				else if (map[y - 3][(x - 21) / 2] == 3) { //보물선택
					system("cls");
					showInterf();
					int mx = STA_X + 1; //21
					int my = STA_Y + 1; //3
					gotoxy(mx, my);
					for (int i = 0; i < HEIGHT; i++) {
						for (int j = 0; j < WIDTH; j++) {
							gotoxy(mx + 2 * j, my + i);
							if (map[i][j] == 0) {
								printf("  "); //미오픈
							}
							else if (map[i][j] == 1) {
								printf("▶"); //플래그
							}
							else if (map[i][j] == 2) {
								printf("▷"); //플래그 오픈
							}
							else {
								printf("★"); //보물
							}
						}
						printf("\n");
					}
					gotoxy(74, 8);
					printf("보물 발견!\n");
					gotoxy(74, 9);
					system("pause");

					return 1;
				} //보물선택 끝

				else { //공백 선택하면
					system("cls");
					showInterf();
					gotoxy(mx, my);
					for (int i = 0; i < HEIGHT; i++) {
						for (int j = 0; j < WIDTH; j++) {
							gotoxy(mx + 2 * j, my + i);
							if (map[i][j] == 0) {
								printf("  "); //미오픈
							}
							else if (map[i][j] == 1) {
								printf("▶"); //플래그
							}
							else if (map[i][j] == 2) {
								printf("▷"); //플래그 오픈
							}
							else {
								printf("▶"); //보물
							}
						}
						printf("\n");
					}
				}

			}
		}
	} //while 끝
} //play함수 끝