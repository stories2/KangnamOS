//
//  main.h
//  Homework4
//
//  Created by 김현우 on 2017. 12. 16..
//  Copyright © 2017년 김현우. All rights reserved.
//

#ifndef main_h
#define main_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "student.h"

#define FILE_PATH "./student.txt"
#define OPEN_ONLY_READ 1
#define OPEN_ONLY_WRITE 2
#define DATA_START 5000
#define HEAD_START 0
#define NOT_AVAILABLE -1
#define ORDER_PRINT_ALL 1
#define ORDER_ADD_DATA 2
#define ORDER_MODIFY_DATA 3
#define ORDER_DELETE_DATA 4

#endif /* main_h */

static struct flock lock;

void CreateDB();
void AddNewStudent(int, char [MAX], int );
void OpenDB(int, int *);
void LockDB(int );
void CloseDB(int *);
void PrintAllDataFromDB();
long GetDataPosition(int);
//long GetHeadPosition(int );
int GetLastIndexNumber();
void ModifyStudent(int, int, char [MAX], int);
int SearchStudent(int );
void DeleteStudent(int );
