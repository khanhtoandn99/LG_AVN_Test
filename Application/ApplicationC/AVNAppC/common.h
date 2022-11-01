#ifndef COMMON_H
#define COMMON_H

#include <QVariant>
#define EMPLOYEE_NAME_MAXSIZE 100

typedef struct
{
    QString name;
    double averageScore;
    bool isSelected;

} EMPLOYEE_LIST_ITEM_T;


typedef struct
{
    int id;
    char name[EMPLOYEE_NAME_MAXSIZE];
    int asmScore;
    int cppScore;
    int jsScore;
    int qmlScore;
    int openglScore;
    float average;
    bool isSelected;
} EMPLOYEE_DATA_T;

#endif // COMMON_H
