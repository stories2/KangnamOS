#include "DeathWing.h"

void SpawnYsera(int damageScale, int attackTimes) {
	SayMalygos("Ysera", "SpawnYsera", "If i dream and the world trembles", LOG_LEVEL_VERBOSE);

	char buffer[200];
	sprintf(buffer, "Set damage Scale: %d attack time: %d", damageScale, attackTimes);
	SayMalygos("Ysera", "SpawnYsera", buffer, LOG_LEVEL_INFO);
}