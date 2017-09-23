#pragma once
#ifndef ONE_DEATH_WING

#define ONE_DEATH_WING 12
#define CARD_PID 0
#define ZERO 0
#define MAXIMUM_OF_DECK 3
#define CARD_YSERA 1
#define CARD_NOZDORMU 2
#define CARD_DEATH_WING 0

#define LOG_LEVEL_VERBOSE 0
#define LOG_LEVEL_INFO 1
#define LOG_LEVEL_DEBUG 2
#define LOG_LEVEL_WARN 3
#define LOG_LEVEL_ERROR 4

#include <cstdio>
#include <unistd.h>
#include <wait.h>

void AttackEnemy(int, int);
void SpawnYsera(int, int);
void SpawnNozdormu(int);

void SayMalygos(char *, char *, char *, int );

#endif // !ONE_DEATH_WING
