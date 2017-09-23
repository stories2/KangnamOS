#include "DeathWing.h"

void SpawnNozdormu(int damageScale) {
	SayMalygos("Nozdormu", "SpawnNozdormu", "Just in time", LOG_LEVEL_VERBOSE);

	char buffer[MAXIMUM_BUFFER_SCALE];
	sprintf(buffer, "Set damageScale: %d", damageScale);
	SayMalygos("Nozdormu", "SpawnNozdormu", buffer, LOG_LEVEL_INFO);
}