#include "DeathWing.h"

void SpawnYsera(int damageScale, int attackTimes) {
	SayMalygos("Ysera", "SpawnYsera", "If i dream and the world trembles", LOG_LEVEL_VERBOSE);

	char buffer[MAXIMUM_BUFFER_SCALE];
	int castedDamageScale = ZERO;

	sprintf(buffer, "Set damage Scale: %d attack time: %d", damageScale, attackTimes);
	SayMalygos("Ysera", "SpawnYsera", buffer, LOG_LEVEL_INFO);

	castedDamageScale = RecursiveYsera(damageScale, attackTimes, 1);

	sprintf(buffer, "Cast damage Scale: %d", castedDamageScale);

	SayMalygos("Ysera", "SpawnYsera", buffer, LOG_LEVEL_INFO);
}

int RecursiveYsera(int damageScale, int attackTimes, int depths) {
	if (damageScale <= ZERO) {
		return ZERO;
	}

	int lastDamageNumber = damageScale % DIGIT_TEN;
	damageScale = damageScale / DIGIT_TEN;

	return depths * lastDamageNumber + RecursiveYsera(damageScale, attackTimes, depths * attackTimes);
}