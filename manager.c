#include <stdio.h>
#include <string.h>
#include "pr.h"


int selectMenu(){
    int snum;
    printf("\n*** 한동대 늦은귀관 관리 ***\n\n0. 종료\n1. 늦은귀관 조회\n2. 늦은귀관 추가\n3. 늦은귀관 정보 수정\n4. 늦은귀관 정보 삭제\n");
    printf("\n=> 원하는 메뉴는? ");
    scanf("%d",&snum);
    return snum;
}

int addStudent(Student *s){
    printf("이름은? : ");
    scanf(" %[^\n]",s->name);
    printf("학번는? : ");
    scanf("%d",&s->student_num);
    printf("호실은? : ");
    scanf("%d",&s->room_num);
    printf("추가됨!!\n");
    return 1;
}

void readStudent(Student s){
    printf("%s %d %d\n",s.name,s.student_num,s.room_num);
}

void listStudent(Student* s, int count){
    printf("\nNo 이름 학번 호실\n");
    printf("*****************\n");
    for(int i=0; i<count; i++){
        if(s[i].student_num == -1) continue;
        printf("%d ",i+1);
        readStudent(s[i]);
    }
    printf("\n");
}

int selectDataNo(Student* s, int count){
    int no;
    listStudent(s, count);
    printf("번호는 (취소 : 0)? ");
    scanf("%d", &no);
    return no;
}

int updateStudent(Student *s){
    printf("새 이름은? : ");
    scanf(" %[^\n]",s->name);
    printf("새 학번는? : ");
    scanf("%d",&s->student_num);
    printf("새 호실은? : ");
    scanf("%d",&s->room_num);
    return 1;
}

int deleteStudent(Student *s){
    s->student_num = -1;
    return 1;
}

int main(void){
    Student plist[100];
    int index = 0;
    int count = 0;
    int snum; // selected number in Menu

    //count = loadData(plist);
    index = count;

    while(1){
        snum = selectMenu();
        if(snum == 0) break;
        if(snum == 1 || snum ==3 || snum == 4)
            if(count == 0) continue;
        if(snum == 1) {listStudent(plist,count);}
        else if(snum == 2){
            if(count>=1){
                printf("full !!\n");
                continue;
            }
            count += addStudent(&plist[index++]);
        }
        else if(snum == 3){
            int no = selectDataNo(plist, index);
            if(no == 0){
                printf("취소됨!\n");
                continue;
            }
            int isupd = updateStudent(&plist[no-1]);
            if(isupd == 1) printf("=> 수정성공!\n");
        }
        else if(snum == 4){
            int no = selectDataNo(plist, count);
            if (no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제 :1) ");
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(deleteStudent(&plist[no-1])) {
                    printf("=> 삭제됨!\n");
                }
            }
        }
    }
    printf("종료됨!\n");

    return 0;
}