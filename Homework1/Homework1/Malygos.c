#include "DeathWing.h"

void SayMalygos(char *cardName, char *actionName, char *message, int level) {

	char levelInfo = 'V';

	switch (level)
	{
	case LOG_LEVEL_VERBOSE:
		levelInfo = 'V';
		return;
		break;
	case LOG_LEVEL_INFO:
		levelInfo = 'I';
		break;
	case LOG_LEVEL_DEBUG:
		levelInfo = 'D';
		break;
	case LOG_LEVEL_WARN:
		levelInfo = 'W';
		break;
	case LOG_LEVEL_ERROR:
		levelInfo = 'E';
		break;
	default:
		levelInfo = 'V';
		break;
	}

	printf("%c : [%15s] {%15s} (%s)\n", levelInfo, cardName, actionName, message);
}