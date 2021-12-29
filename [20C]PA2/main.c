#include "head.h"

int main() {
	srand((unsigned)time(NULL));

	int level = loadPage();
	while (level != 0) { 
		int isClear = playGame(level);
		if (isClear) {
			level++;
			system("cls");
			showLoading();
			Sleep(3000);
		}
		else {
			system("cls");
			showFail();
			askReplay();
			if (_getch() == 121) { // y, replay
				continue;
			}
			else {
				system("cls");
				showReturnMain();
				Sleep(3000);
				system("cls");
				level = loadPage();
			}
		}
		//ending
		if (level > 3) {
			system("cls");
			showEnding();
		}
	}
	return 0; // 완전 종료
}
