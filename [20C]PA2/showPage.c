#include "head.h"

char* backspace = "<Press backspace to go back>";


int loadPage(void) {
	RemoveCursor();
	char selection; //메인 페이지에서 사용자 입력
	int isMainPageOn = 0, isLevelPageOn = 0, isGameGuideOn = 0, isStoryPageOn = 0, level = 0; //각각 메인페이지, 레벨선택페이지, 게임방법페이지가 화면에 나타났는지 의미하는 진리값/각각 초급모드, 중급모드, 고급모드가 실행되었는지 의미하는 진리값
	showMain();
	isMainPageOn = 1;
	do {
		if (_kbhit() == 1) { //키보드 입력 감지

			selection = _getch();

			if (selection == 27) { //esc
				break;
			}
			else if (isMainPageOn) {
				if (selection == '1') { //게임 시작 버튼을 누를 경우
					isMainPageOn = 0;
					isLevelPageOn = 1;
					system("cls");
					showLevelPage();
				}
				else if (selection == '2') { //게임 방법 버튼을 누를 경우
					isMainPageOn = 0;
					isGameGuideOn = 1;
					system("cls");
					showGameGuide();
				}
			
				else if (selection == '3') { //시놉시스 버튼을 누를 경우
					isMainPageOn = 0;
					isStoryPageOn = 1;
					system("cls");
					printOpening();
				}
				else if (selection == '4') { //종료 키를 누를 경우
					level = 0; //게임 종료
					break;
				}
			}
			else if (isLevelPageOn) {
				/*
				selection 입력값:
				'1' => 초급
				'2' => 중급
				'3' => 고급
				 8  => 백스페이스의 아스키 코드
				 */
				if (selection == '1') {
					isLevelPageOn = 0;
					level = 1; //초급
					system("cls");
					break;
				}
				else if (selection == '2') {
					isLevelPageOn = 0;
					level = 2; //중급
					system("cls");
					break;
				}
				else if (selection == '3') {
					isLevelPageOn = 0;
					level = 3; //고급
					system("cls");
					break;
				}
				else if (selection == 8) { //백스페이스
					isLevelPageOn = 0;
					isMainPageOn = 1;
					system("cls");
					showMain();
				}
			}
			else if (isGameGuideOn) {
				if (selection == 8) { 
					isGameGuideOn = 0;
					isMainPageOn = 1;
					system("cls");
					showMain();
				}
			}
			else if (isStoryPageOn) {
				if (selection == 8) { 
					isStoryPageOn = 0;
					isMainPageOn = 1;
					system("cls");
					showMain();
				}
			}
		}
	} while (1);

	system("cls");

	return level;
}

void showBorder() {
	int i; //메인페이지 창 40*20
	gotoxy(20, 2);
	printf("■");
	for (i = 1; i < INTERF_WIDTH/2; i++) {
		printf("■");
	}
	printf("■");

	for (i = 1; i < INTERF_HEIGHT; i++) {
		gotoxy(20, 2 + i); printf("■");
	}
	gotoxy(20, 2 + INTERF_HEIGHT);
	printf("■");

	for (i = 1; i < INTERF_WIDTH/2; i++) {
		printf("■");
	}
	printf("■");

	gotoxy(20 + INTERF_WIDTH, 2);
	for (i = 1; i < INTERF_HEIGHT; i++) {
		gotoxy(20 + INTERF_WIDTH, 2 + i); printf("■");
	}

}

void showMain() {
	showBorder();

	gotoxy(30, 7);
	printf("╋-------------------╋");
	gotoxy(30, 9);
	printf("╋-------------------╋");

	gotoxy(35, 8);
	Sleep(100);
	printf("T");
	Sleep(100);
	printf("I");
	Sleep(100);
	printf("M");
	Sleep(100);
	printf("E ");

	Sleep(100);
	printf("I");
	Sleep(100);
	printf("S ");

	Sleep(100);
	printf("G");
	Sleep(100);
	printf("O");
	Sleep(100);
	printf("L");
	Sleep(100);
	printf("D");
	

	int textPositionY = MID_Y;//텍스트의 y좌표
	char* textMainPage[5] = { "1. Game start","2. How to play", "3. Synopsys", "4. Exit", "<Press number on keyboard>" };

	Sleep(300);
	textPositionY -= 1;
	showString(textMainPage[0], textPositionY);

	Sleep(300);
	textPositionY += 2;
	showString(textMainPage[1], textPositionY);

	Sleep(300);
	textPositionY += 2;
	showString(textMainPage[2], textPositionY);

	Sleep(300);
	textPositionY += 2;
	showString(textMainPage[3], textPositionY);

	Sleep(300);
	textPositionY += 3;
	showString(textMainPage[4], textPositionY);
}


void showGameGuide() { 

	showBorder();

	char* guideLines[3] = { "◇ →,←,↑,↓ : Move",
				"◇ SPACE BAR : Open flag",
				"◇ Esc : Quit" }; //게임 방법 문자열
	char textPositionY = MID_Y; //문자열 Y좌표
	int count; //라인별 문자열 출력 개수

	textPositionY -= 2;
	for (count = 0; count < 3; count++) {
		showString(guideLines[count], textPositionY);
		textPositionY += 1;
	}
	textPositionY += 6;
	showString(backspace, textPositionY);
}


void showLevelPage(void) { //레벨선택페이지 로드

	showBorder();

	int textPositionY = MID_Y; //문자열 Y좌표
	char* textLevelPage[] = { "Choose a level", "1. Beginner", "2. Intermediate", "3. Advanced" };

	textPositionY -= 2;
	showString(textLevelPage[0], textPositionY);

	textPositionY += 2;
	showString(textLevelPage[1], textPositionY);

	textPositionY += 2;
	showString(textLevelPage[2], textPositionY);

	textPositionY += 2;
	showString(textLevelPage[3], textPositionY);

	textPositionY += 2;
	showString(backspace, textPositionY);
}

void showClear() {
	showBorder();
	gotoxy(MID_X-4, MID_Y);
	printf("Clear!");
	gotoxy(MID_X - 15, MID_Y+1);
	system("pause");
}

void showLoading() {
	showBorder();
	gotoxy(MID_X-4, MID_Y);
	printf("Loading . . .");
}
void showFail() {
	showBorder();
	gotoxy(MID_X-4, MID_Y-1);
	printf("Fail . . .");
}

void showReturnMain() {
	showBorder();
	gotoxy(MID_X - 9, MID_Y - 1);
	printf("Back to main . . .");
}

void askReplay() {
	showBorder();
	gotoxy(MID_X-10, MID_Y +2);
	printf("If you want to replay");
	gotoxy(MID_X - 7, MID_Y + 3);
	printf("Please press 'y'");
}

void printOpening() {
	showBorder();
	char* startScenario[] = { "\"노력은 하기싫고요!\"",
				"\"그냥 놀고싶습니다!\"",
				"돈많은 백수가 꿈인 탕자(22,여)",
				"어느날 뒷산에 엄청난 양의",
				"황금이 묻혀있다는 소문이 들려오고..",
				"일획천금의 주인공이 되기위해",
				"탕자는 산으로 간다.",
				"탕자는 꿈을 이룰수 있을까?"
	};
	
	gotoxy(MID_X - 8, MID_Y -6);
	printf("%s", startScenario[0]);
	Sleep(1000);
	gotoxy(MID_X - 8, MID_Y - 5);
	printf("%s", startScenario[1]);
	Sleep(1000);


	gotoxy(MID_X - 13, MID_Y - 3);
	printf("%s", startScenario[2]);
	Sleep(1000);
	gotoxy(MID_X - 10, MID_Y - 2);
	printf("%s", startScenario[3]);
	Sleep(1000);
	gotoxy(MID_X - 16, MID_Y - 1);
	printf("%s", startScenario[4]);
	Sleep(1000);

	gotoxy(MID_X -13, MID_Y +1);
	printf("%s", startScenario[5]);
	Sleep(1000);
	gotoxy(MID_X - 8, MID_Y + 2);
	printf("%s", startScenario[6]);
	Sleep(1000);

	gotoxy(MID_X - 11, MID_Y + 4);
	printf("%s", startScenario[7]);
	Sleep(1000);

	gotoxy(MID_X - 13, MID_Y + 6);
	printf("%s", backspace);
	
}

void printEnding() {
	char* endScenario[] = { "탕자는 마침내 보물을 찾아냈다.",
				"눈앞이 황금으로 가득찰때까지",
				"지금껏 앞이 안보일때도 있었고",
				"때로는 어디로 가야할지 갈팡질팡했었다.",
				"시간이 없어서 놓쳤던 많은 것들을 떠올리며",
				"비로소 탕자는 시간을 금이라고 여기게 된다.",
				"우리는 얼마나 많은 금을 놓쳤을까?",
				"내가 그 탕자는 아니였을까?"
	};

	for (int i = 0; i < sizeof(endScenario) / sizeof(endScenario[0]); i++) {
		gotoxy(STA_X + 44, STA_Y+(i*2));
		printf("%s", endScenario[i]);
		Sleep(1500);
	}

}

void showEnding() {
	int i = 1;
	printEnding();
	while (1) {

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		showBorder();

		gotoxy(STA_X + 2, STA_Y + 12);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GOLD);
		printf("$$$$$$$$$$$$$$$$$");
		gotoxy(STA_X + 19, STA_Y + 11);
		printf("$");
		gotoxy(STA_X + 20, STA_Y + 10);
		printf("$");
		gotoxy(STA_X + 21, STA_Y + 9);
		printf("$");
		gotoxy(STA_X + 22, STA_Y + 8);
		printf("$");
		gotoxy(STA_X + 23, STA_Y + 8);
		printf("$");
		gotoxy(STA_X + 24, STA_Y + 9);
		printf("$");
		gotoxy(STA_X + 25, STA_Y + 10);
		printf("$");
		gotoxy(STA_X + 26, STA_Y + 11);
		printf("$");
		gotoxy(STA_X + 27, STA_Y + 12);
		printf("$");
		gotoxy(STA_X + 28, STA_Y + 12);
		printf("$$$$$$$$$$$$");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		gotoxy(STA_X + 2, STA_Y + 11);
		printf("◆"); //시작

		Sleep(100);
		gotoxy(STA_X + 2, STA_Y + 11);
		printf("  ");
		gotoxy(STA_X + 6, STA_Y + 11);
		printf("◆");

		Sleep(100);
		gotoxy(STA_X + 6, STA_Y + 11);
		printf("  ");
		gotoxy(STA_X + 10, STA_Y + 11);
		printf("◆");

		Sleep(100);
		gotoxy(STA_X + 10, STA_Y + 11);
		printf("  ");
		gotoxy(STA_X + 13, STA_Y + 11);
		printf("◆");

		Sleep(100);
		gotoxy(STA_X + 13, STA_Y + 11);
		printf("  ");
		gotoxy(STA_X + 15, STA_Y + 11);
		printf("◆");

		Sleep(100);
		gotoxy(STA_X + 15, STA_Y + 11);
		printf("  ");
		gotoxy(STA_X + 17, STA_Y + 9);
		printf("◆");

		Sleep(100);
		gotoxy(STA_X + 17, STA_Y + 9);
		printf("  ");
		gotoxy(STA_X + 18, STA_Y + 8);
		printf("◆");


		Sleep(100);
		gotoxy(STA_X + 18, STA_Y + 8);
		printf("  ");
		gotoxy(STA_X + 19, STA_Y + 7);
		printf("◆");


		Sleep(100);
		gotoxy(STA_X + 19, STA_Y + 7);
		printf("  ");
		gotoxy(STA_X + 19, STA_Y + 6);
		printf("◆");

		Sleep(100);
		gotoxy(STA_X + 19, STA_Y + 6);
		printf("  ");
		gotoxy(STA_X + 19, STA_Y + 7);
		printf("◆");

		gotoxy(STA_X + 19, STA_Y + 7);
		printf("  ");

		Sleep(100);
		if (i > 15)
			i = 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		i++;
		gotoxy(STA_X + 14, STA_Y + 5);
		printf("TIme is gold !");
		
	}
}


void showString(char string[], int positionY) { //페이지에 들어가는 문자열이 가로로 가운데에 오게 출력
	int strMiddle = strlen(string) / 2;
	int positionX = MID_X - strMiddle;
	gotoxy(positionX, positionY);
	puts(string);
}
