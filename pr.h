#include <stdio.h>

typedef struct{
    char name[100];
    int student_num;
    int room_num;
} Student;

//세영담당- (원래는 세영 담당인데 이번주 팀별과제가 검색, 파일 저장, 로딩을 제외해서 다시 적절하게 분배해야할 것 같애) 
int addStudent(Student *s);
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

//확인
