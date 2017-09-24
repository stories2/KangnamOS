#include "DeathWing.h"

int main()
{
	SayMalygos("main", "main", "I am deathwing the destroyer the end of all things", LOG_LEVEL_VERBOSE);
	
	while (1) {
		SayMalygos("main", "main", "Select type of process: ", LOG_LEVEL_INFO);
		char cardProcessType[MAXIMUM_BUFFER_SCALE];
		scanf(" %s", cardProcessType);

		if (strcmp(cardProcessType, PROCESS_TYPE_REVERSE) == ZERO) {

			SayMalygos("main", "main", "Type damageScale and attackTimes: ", LOG_LEVEL_INFO);

			int damageScale, attackTimes, cardId;
			scanf(" %d %d", &damageScale, &attackTimes);

			AttackEnemy(damageScale, attackTimes);
		}
	}
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
		sprintf(buffer, "My cardId: %d", cardId);
		SayMalygos("main", "AttackEnemy", buffer, LOG_LEVEL_INFO);
		if (cardId == CARD_PID) {
			break;
		}
		else if (cardId == CARD_CRASH) {
			SayMalygos("main", "AttackEnemy", "The card not available", LOG_LEVEL_ERROR);
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
		draw = MAXIMUM_OF_DECK;
		while (draw > ZERO) {
			int status;
			cardId = wait(&status);

			sprintf(buffer, "End of game: %d status: %d", cardId, status);
			SayMalygos("main", "AttackEnemy", buffer, LOG_LEVEL_INFO);

			draw -= 1;
		}
		SayMalygos("main", "AttackEnemy", "All the game is ended", LOG_LEVEL_INFO);
		break;
	default:
		break;
	}
}
