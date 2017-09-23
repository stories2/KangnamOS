#include "DeathWing.h"

int main()
{
	int cardId, cardDrawNum = ZERO, draw;
    printf("hello from Homework1!\n");
	for (draw = ZERO; draw < MAXIMUM_OF_DECK; draw += 1) {
		cardDrawNum += 1;
		cardId = fork();
		if (cardId == CARD_PID) {
			break;
		}
	}

	wait(NULL);
	printf("my pid: %d prog: %d\n", cardId, cardDrawNum);
    return 0;
}