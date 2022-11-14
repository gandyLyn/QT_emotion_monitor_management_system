#ifndef DATA_DEFINE_H
#define DATA_DEFINE_H
#include <QString>

typedef struct teacher{
    int id;
    QString password;
    QString name;
    int age;
    char sex;
    QString phone;
}teacher;

typedef struct monitor{
    int id;
    QString password;
    QString name;
    int age;
    char sex;
    QString phone;
}monitor;

typedef struct student{
    int id;
    QString password;
    int sno;
    QString name;
    int age;
    char sex;
    QString phone;
    QString email;
    QString college;
    QString grade;
    QString myclass;
    QString profeesion;
}student;

#endif // DATA_DEFINE_H
