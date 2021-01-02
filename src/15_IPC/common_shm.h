/**
 * @file 共享存储公共头
 *
 * apue示例程序 - common_shm.h
 *
 * @author r00tk1t
 *
 */
#pragma once

#define SHM_ID 1234

typedef struct Student {
    int age;
    char name[10];
}Student;