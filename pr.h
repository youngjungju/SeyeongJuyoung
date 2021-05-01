#include <stdio.h>

typedef struct{
    char name[100];
    int student_num;
    int room_num;
} Student;


int addStudnet(Student *s);
void readStudent(Student s);
void listStudentStudent *s, int count);
int updateStudent(Student *s);
int deleteStudent(Student *s);
