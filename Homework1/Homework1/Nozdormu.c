#include "DeathWing.h"

void SpawnNozdormu(int damageScale) {
	SayMalygos("Nozdormu", "SpawnNozdormu", "Just in time", LOG_LEVEL_VERBOSE);

	char buffer[MAXIMUM_BUFFER_SCALE];
	int reverseDamage = ZERO;

	sprintf(buffer, "Set damageScale: %d", damageScale);
	SayMalygos("Nozdormu", "SpawnNozdormu", buffer, LOG_LEVEL_INFO);

	reverseDamage = ReverseNozdormu(damageScale);
	sprintf(buffer, "Reverse damageScale: %d", reverseDamage);
	SayMalygos("Nozdormu", "SpawnNozdormu", buffer, LOG_LEVEL_INFO);

	exit(0);
}

int ReverseNozdormu(int damageScale) {
	if (damageScale <= ZERO) {
		return damageScale;
	}

	int buffer[MAXIMUM_BUFFER_SCALE] = { '\0', };
	int indexOfDamage = ZERO, damageDigitSize = ZERO, result = ZERO, indexOfTenGap = 1;

	while (damageScale != ZERO) {
		buffer[indexOfDamage] = damageScale % DIGIT_TEN;
		damageScale = damageScale / DIGIT_TEN;

		indexOfDamage += 1;
	}

	damageDigitSize = indexOfDamage;

	for (indexOfDamage = damageDigitSize - 1; indexOfDamage >= ZERO; indexOfDamage -= 1) {
		result = result + buffer[indexOfDamage] * indexOfTenGap;

		indexOfTenGap = indexOfTenGap * DIGIT_TEN;
	}

	return result;
}