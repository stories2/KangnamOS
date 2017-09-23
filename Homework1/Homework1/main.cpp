#include "DeathWing.h"

int main()
{
	SayMalygos("main", "main", "I am deathwing the destroyer the end of all things", LOG_LEVEL_VERBOSE);
	AttackEnemy(1734, 8);
    return 0;
}

void AttackEnemy(int damageScale, int attackTimes) {
	char buffer[200];
	sprintf(buffer, "Attacking enemy damageScale: %d attackTimes: %d", damageScale, attackTimes);
	SayMalygos("main", "AttackEnemy", buffer, LOG_LEVEL_INFO);

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
		SpawnYsera(damageScale, attackTimes);
		break;
	case CARD_NOZDORMU:
		SpawnNozdormu(damageScale);
		break;
	case CARD_DEATH_WING:
		wait(NULL);
		SayMalygos("main", "AttackEnemy", "The end of game", LOG_LEVEL_INFO);
		break;
	default:
		break;
	}
}