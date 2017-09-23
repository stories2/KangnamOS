#include "DeathWing.h"

int main()
{
	int cardId, cardDrawNum = ZERO, draw;

	for (draw = ZERO; draw < MAXIMUM_OF_DECK; draw += 1) {
		cardDrawNum += 1;
		cardId = fork();
		if (cardId == CARD_PID) {
			break;
		}
	}

	if (cardId > ZERO) {
		cardDrawNum = CARD_DEATH_WING;
	}

	switch (cardDrawNum)
	{
	case CARD_YSERA:
		SpawnYsera();
		break;
	case CARD_NOZDORMU:
		SpawnNozdormu();
		break;
	case CARD_DEATH_WING:
		wait(NULL);
		printf("I am deathwing the destroyer the end of all things\n");
		break;
	default:
		break;
	}
    return 0;
}