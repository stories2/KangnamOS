#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "student.h"
#define START_ID 1201001

/* 학생 정보를 입력받아 데이터베이스 파일에 저장한다. */
int main(int argc, char *argv[])
{
    int fd;
    struct student record;

//    if (argc < 2) {
//        fprintf(stderr,  "사용법 : %s file\n", argv[0]);
//        exit(1);
//    }

    if ((fd = open("/Users/stories2/Desktop/student.txt",O_WRONLY |O_CREAT|O_EXCL, 0640))==-1) {
        perror("/Users/stories2/Desktop/student.txt");
        exit(2);
    }

    printf("%7s %6s %4s\n", "학번",  "이름",  "점수"); 
    while (scanf("%d %s %d", &record.id, record.name, &record.score) ==  3) {//ctr d
        printf("%d %s %d\n", record.id, record.name, record.score);
        lseek(fd, (record.id - START_ID) * sizeof(record), SEEK_SET);
        write(fd, (char *) &record, sizeof(record) );
    }

    close(fd);
    exit(0);
}

