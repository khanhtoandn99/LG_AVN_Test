#ifndef COMMON_H_
#define COMMON_H_

#define EMPLOYEE_NAME_MAXSIZE 100
#define EMPLOYEE_IN_LIST_MODEL_MAX 10 // 10 employee data support

#define EMPLOYEE_DATA_MODEL_FILE_PATH "/home/avn/Desktop/LG_AVN_TEST/Framework/AVNService/empdatamodel.txt"

enum E_GET_SCORE_DATA_RESULT : int
{
    E_GET_SCORE_DATA_RESULLT_FAILED = 0,
    E_GET_SCORE_DATA_RESULLT_OK,
    E_GET_SCORE_DATA_RESULLT_NAME_NOT_FOUND
};

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