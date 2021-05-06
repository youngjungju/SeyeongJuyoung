#include <stdio.h>

typedef struct{
    char name[100];
    int student_num;
    int room_num;
} Student;

//세영담당
int addStudnet(Student *s);
void readStudent(Student s);
void listStudent(Student *s, int count);
int updateStudent(Student *s);
int deleteStudent(Student *s);
//주영담당
void saveData(Student *s, int count); //데이터 저장 
int loadData(Student *s); //데이터 불러오기 
void serchName(Student *s, int count); //이름 검색
void serchnumber(Student *s, int count); //학번 검색
void serchho(Student *s, int count); //호실 검색 

