#pragma once
#ifndef ONE_DEATH_WING

#define ONE_DEATH_WING 12
#define CARD_PID 0
#define ZERO 0
#define MAXIMUM_OF_DECK 2
#define CARD_YSERA 1
#define CARD_NOZDORMU 2
#define CARD_DEATH_WING 0
#define DIGIT_TEN 10
#define MAXIMUM_BUFFER_SCALE 200
#define CARD_CRASH -1

#define PROCESS_TYPE_REVERSE "reverse"

#define LOG_LEVEL_VERBOSE 0
#define LOG_LEVEL_INFO 1
#define LOG_LEVEL_DEBUG 2
#define LOG_LEVEL_WARN 3
#define LOG_LEVEL_ERROR 4

#include <cstdio>
#include <unistd.h>
#include <wait.h>
#include <string.h>
#include <stdlib.h>

void AttackEnemy(int, int);

void SpawnYsera(int, int);
int RecursiveYsera(int, int, int);

void SpawnNozdormu(int);
int ReverseNozdormu(int );

void SayMalygos(char *, char *, char *, int );

#endif // !ONE_DEATH_WING
