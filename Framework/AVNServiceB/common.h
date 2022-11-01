#ifndef COMMON_H_
#define COMMON_H_

#define EMPLOYEE_NAME_MAXSIZE 100

#define EMPLOYEE_DATA_MODEL_FILE_PATH "empdatamodel.txt"

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

#endif