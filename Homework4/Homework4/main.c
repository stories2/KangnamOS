//
//  main.c
//  Homework4
//
//  Created by 김현우 on 2017. 12. 16..
//  Copyright © 2017년 김현우. All rights reserved.
//

#include "main.h"

int main() {
    CreateDB();
//    PrintAllDataFromDB();
//    AddNewStudent(201501180, "kim", 80);
//    ModifyStudent(201501180, 201501180, "kim", 20);
//    DeleteStudent(201501180);
//    PrintAllDataFromDB();
    while(1) {
        int orderType = NOT_AVAILABLE;
        printf("============Select order============\n1: Print all data\n2: Add new data\n3: Modify data\n4: Delete data\n");
        scanf("%d", &orderType);
        if(orderType == ORDER_PRINT_ALL) {
            PrintAllDataFromDB();
        }
        else if(orderType == ORDER_ADD_DATA) {
            int studentId, score;
            char studentName[MAX] = {'\0', };
            printf("Please input student id, name, score: ");
            scanf("%d %s %d", &studentId, studentName, &score);
            AddNewStudent(studentId, studentName, score);
        }
        else if(orderType == ORDER_MODIFY_DATA) {
            int targetStudentId, studentId, score;
            char studentName[MAX] = {'\0', };
            printf("Please input target student id: ");
            scanf("%d", &targetStudentId);
            printf("Please input updated student id, name, score: ");
            scanf("%d %s %d", &studentId, studentName, &score);
            ModifyStudent(targetStudentId, studentId, studentName, score);
        }
        else if(orderType == ORDER_DELETE_DATA) {
            int targetStudentId;
            printf("Please input target student id: ");
            scanf("%d", &targetStudentId);
            DeleteStudent(targetStudentId);
        }
    }
    return 0;
}

void DeleteStudent(int targetStudentID) {
    int fileManager, indexNumber;
    struct student studentIndex;
    indexNumber = SearchStudent(targetStudentID);
    
    if(indexNumber == NOT_AVAILABLE) {
        return;
    }
    OpenDB(OPEN_ONLY_READ, &fileManager);
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = GetDataPosition(indexNumber);
    lock.l_len = sizeof(studentIndex);
    
    if (fcntl(fileManager,F_SETLKW, &lock) == -1) {   /* 읽기 잠금 */
        printf("PrintAllDataFromDB file locked: %d\n", indexNumber);
        perror(FILE_PATH);
        exit(3);
    }
    lseek(fileManager, GetDataPosition(indexNumber), SEEK_SET);
    if ((read(fileManager, (char *) &studentIndex, sizeof(studentIndex)) > 0) &&
        (studentIndex.id != 0)) {
        printf("DeleteStudent data found id: %d name: %s score: %d\n", studentIndex.id, studentIndex.name, studentIndex.score);
        studentIndex.name[0] = '$';
    }
    else {
        printf("DeleteStudent data empty: %d\n", indexNumber);
    }
    lock.l_type = F_UNLCK;
    fcntl(fileManager,F_SETLK, &lock);    /* 잠금 해제 */
    CloseDB(&fileManager);
    
    if(studentIndex.name[0] == '$') {
        ModifyStudent(targetStudentID, studentIndex.id, studentIndex.name, studentIndex.score);
    }
}

void ModifyStudent(int targetStudentID, int studentID, char studentName[MAX], int score) {
    int fileManager, indexNumber;
    struct student studentIndex;
    indexNumber = SearchStudent(targetStudentID);
    
    if(indexNumber == NOT_AVAILABLE) {
        return;
    }
    
    studentIndex.id = studentID;
    strcpy(studentIndex.name,studentName);
    studentIndex.score = score;
    
    OpenDB(OPEN_ONLY_WRITE, &fileManager);
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = GetDataPosition(indexNumber);
    lock.l_len = sizeof(studentIndex);
    
    if (fcntl(fileManager,F_SETLKW, &lock) == -1) {  /* 쓰기 잠금 */
        printf("ModifyStudent write locked: %d\n", indexNumber);
        perror(FILE_PATH);
        exit(3);
    }
    lseek(fileManager,  GetDataPosition(indexNumber), SEEK_SET);
    write(fileManager, (char *) &studentIndex, sizeof(studentIndex));
    
    lock.l_type = F_UNLCK;
    fcntl(fileManager, F_SETLK, &lock);  /* 잠금 해제 */
    
    CloseDB(&fileManager);
}

int SearchStudent(int studentID) {
    int fileManager, indexNumber = 0, studentSavedIndexNumber = NOT_AVAILABLE;
    struct student studentIndex;
    OpenDB(OPEN_ONLY_READ, &fileManager);
    while(1) {
        lock.l_type = F_RDLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = GetDataPosition(indexNumber);
        lock.l_len = sizeof(studentIndex);
        
        if (fcntl(fileManager,F_SETLKW, &lock) == -1) {   /* 읽기 잠금 */
            printf("PrintAllDataFromDB file locked: %d\n", indexNumber);
            perror(FILE_PATH);
            exit(3);
        }
        lseek(fileManager, GetDataPosition(indexNumber), SEEK_SET);
        
        if ((read(fileManager, (char *) &studentIndex, sizeof(studentIndex)) > 0) &&
            (studentIndex.id != 0)) {
            if(studentID == studentIndex.id) {
                studentSavedIndexNumber = indexNumber;
                break;
            }
        }
        else {
            break;
        }
        
        lock.l_type = F_UNLCK;
        fcntl(fileManager,F_SETLK, &lock);    /* 잠금 해제 */
        indexNumber += 1;
    }
    CloseDB(&fileManager);
    return studentSavedIndexNumber;
}

void PrintAllDataFromDB() {
    int fileManager, indexNumber = 0;
    struct student studentIndex;
    OpenDB(OPEN_ONLY_READ, &fileManager);
    while(1) {
        lock.l_type = F_RDLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = GetDataPosition(indexNumber);
        lock.l_len = sizeof(studentIndex);
        
        if (fcntl(fileManager,F_SETLKW, &lock) == -1) {   /* 읽기 잠금 */
            printf("PrintAllDataFromDB file locked: %d\n", indexNumber);
            perror(FILE_PATH);
            exit(3);
        }
        lseek(fileManager, GetDataPosition(indexNumber), SEEK_SET);
        
        if ((read(fileManager, (char *) &studentIndex, sizeof(studentIndex)) > 0) &&
            (studentIndex.id != 0)) {
            if(studentIndex.name[0] != '$') {
                printf("PrintAllDataFromDB id: %d name: %s score: %d\n", studentIndex.id, studentIndex.name, studentIndex.score);
            }
        }
        else {
            printf("PrintAllDataFromDB data empty: %d\n", indexNumber);
            break;
        }
        
        lock.l_type = F_UNLCK;
        fcntl(fileManager,F_SETLK, &lock);    /* 잠금 해제 */
        indexNumber += 1;
    }
    CloseDB(&fileManager);
}

int GetLastIndexNumber() {
    int fileManager, indexNumber = 0;
    struct student studentIndex;
    OpenDB(OPEN_ONLY_READ, &fileManager);
    while(1) {
        lock.l_type = F_RDLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = GetDataPosition(indexNumber);
        lock.l_len = sizeof(studentIndex);
        
        if (fcntl(fileManager,F_SETLKW, &lock) == -1) {   /* 읽기 잠금 */
            printf("PrintAllDataFromDB file locked: %d\n", indexNumber);
            perror(FILE_PATH);
            exit(3);
        }
        lseek(fileManager, GetDataPosition(indexNumber), SEEK_SET);
        
        if ((read(fileManager, (char *) &studentIndex, sizeof(studentIndex)) > 0) &&
            (studentIndex.id != 0)) {
        }
        else {
            break;
        }
        
        lock.l_type = F_UNLCK;
        fcntl(fileManager,F_SETLK, &lock);    /* 잠금 해제 */
        indexNumber += 1;
    }
    CloseDB(&fileManager);
    return indexNumber;
}

void AddNewStudent(int studentID, char studentName[MAX], int score) {
    int fileManager, indexNumber = 0;
    struct student studentIndex;
    
    indexNumber = GetLastIndexNumber();
    
    studentIndex.id = studentID;
    strcpy(studentIndex.name, studentName);
    studentIndex.score = score;
    
    OpenDB(OPEN_ONLY_WRITE, &fileManager);
    
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = GetDataPosition(indexNumber);
    lock.l_len = sizeof(studentIndex);
    
    if (fcntl(fileManager,F_SETLKW, &lock) == -1) {  /* 쓰기 잠금 */
        printf("AddNewStudent write locked: %d\n", indexNumber);
        perror(FILE_PATH);
        exit(3);
    }
    lseek(fileManager,  GetDataPosition(indexNumber), SEEK_SET);
    write(fileManager, (char *) &studentIndex, sizeof(studentIndex));
    
    lock.l_type = F_UNLCK;
    fcntl(fileManager, F_SETLK, &lock);  /* 잠금 해제 */
    
    CloseDB(&fileManager);
}

long GetDataPosition(int index) {
    struct student studentIndex;
    return (HEAD_START + index) * sizeof(studentIndex);
}

//long GetHeadPosition(int index) {
//    struct index dataIndex;
//    return (HEAD_START + index)*sizeof(dataIndex);
//}

void CloseDB(int *fileManager) {
    close(*fileManager);
}

void OpenDB(int openType, int *fileManager) {
    if(openType == OPEN_ONLY_READ) {
        if ((*fileManager = open(FILE_PATH, O_RDONLY)) == -1) {
            perror(FILE_PATH);
            exit(2);
        }
        else {
            printf("file opened successfully type read\n");
        }
    }
    else {
        if ((*fileManager = open(FILE_PATH, O_RDWR)) == -1) {
            perror(FILE_PATH);
            exit(2);
        }
        else {
            printf("file opened successfully type write\n");
        }
    }
}

void LockDB(int fileManager) {
    int result;
    
    lock.l_type = F_WRLCK;
    lock.l_start = 0;
    lock.l_whence = SEEK_SET;
    lock.l_len = 0;
    lock.l_pid = getpid();
    result = fcntl(fileManager, F_SETLKW, &lock);
    
    if(result == 0) {
        printf("file locked\n");
    }
    else {
        printf("something wrong with file lock\n");
    }
}

void CreateDB() {
    int fileManager;
    if ((fileManager = open(FILE_PATH,O_WRONLY |O_CREAT|O_EXCL, 0640))==-1) {
        perror(FILE_PATH);
    }
    LockDB(fileManager);
    close(fileManager);
}
