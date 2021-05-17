#include <stdio.h>
#include <string.h>
#include "pr.h"

//늦은귀관 목록
int selectMenu(){
    int snum;
    printf("\n*** 한동대 늦은귀관 관리 ***\n\n0. 종료\n1. 늦은귀관 조회\n2. 늦은귀관 추가\n3. 늦은귀관 정보 수정\n4. 늦은귀관 정보 삭제\n5. 늦은귀관 정보저장\n6. 늦은귀관 정보 검색\n");
    printf("\n=> 원하는 메뉴는? ");
    scanf("%d",&snum);
    return snum;
}

//학생추가 
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

//학생 읽기
void readStudent(Student s){
    printf("%s %d %d\n",s.name,s.student_num,s.room_num);
}

//학생 목록   0개면 읽을 수 없다 추가하기 
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

//번호 선택
int selectDataNo(Student* s, int count){
    int no;
    listStudent(s, count);
    printf("번호는 (취소 : 0)? ");
    scanf("%d", &no);
    return no;
}

//학생 수정
int updateStudent(Student *s){
    printf("새 이름은? : ");
    scanf(" %[^\n]",s->name);
    printf("새 학번는? : ");
    scanf("%d",&s->student_num);
    printf("새 호실은? : ");
    scanf("%d",&s->room_num);
    return 1;
}

//학생 삭제
int deleteStudent(Student *s){
    s->student_num = -1;
    return 1;

}

//데이터 저장 
void saveData(Student *s, int count){
   FILE *fp;
   int i;
 
   fp=fopen("latecome.txt","wt");
   for(i=0;i<count;i++){
       if(s[i].student_num==-1) continue;
       fprintf(fp,"%s %d %d\n",s[i].name,s[i].student_num,s[i].room_num);
   }
   fclose(fp);
   printf("=>저장됨!\n");
}


//데이터 불러오기 
int loadData(Student *s){
    FILE *fp;
    int i;

    fp=fopen("latecome.txt","rt");
    
    if(fp==NULL){
        printf("파일이 없습니다.");
        return 0;
    }
    for(i=0;i<100;i++){
        fscanf(fp,"%s %d %d",s[i].name,&s[i].student_num,&s[i].room_num);
        if(feof(fp)) break;
    }
    fclose(fp);
    if(i>0) printf("로딩성공!\n");
    else printf("파일 없음");

    return i;

}
//이름 검색
void serchName(Student *s, int count){
    int i;
    char na[100];
    printf("검색할 이름이 무엇인가요?");
    scanf("%s",na);
    int n = 0;
    for(i=0;i<count;i++){
        if (s[i].student_num==-1) continue;
        if(strstr(s[i].name,na)){
            printf("%2d ",i+1);
            readStudent(s[i]);
            n++;
        }
    }
    if(n==0) printf("검색된 데이터 없음\n");
}

//학번 검색
void serchnumber(Student *s, int count){
    int i;
    int ns;
    printf("검색할 학번이 무엇인가요?");
    scanf("%d",&ns);
    int n = 0;
    for(i=0;i<count;i++){
        if (s[i].student_num==-1) continue;
        if(s[i].student_num==ns){
            printf("%2d ",i+1);
            readStudent(s[i]);
            n++;
        }
    }
    if(n==0) printf("검색된 데이터 없음\n");
    
}

//호실 검색 
void serchho(Student *s, int count){
    int i;
    int nr;
    printf("검색할 방번호는 무엇인가요?");
    scanf("%d",&nr);
    int n = 0;
    for(i=0;i<count;i++){
        if (s[i].room_num==-1) continue;
        if(s[i].room_num==nr){
            printf("%2d ",i+1);
            readStudent(s[i]);
            n++;
        }
    }
    if(n==0) printf("검색된 데이터 없음\n");
    
}


//
int main(void){
    Student plist[100];
    int index = 0;
    int count = 0;
    int snum; // selected number in Menu

    count = loadData(plist);
    index = count;

    while(1){
        snum = selectMenu();
        if(snum == 0) break;
        if(snum == 1 || snum ==3 || snum == 4)
            if(count == 0) continue;
        if(snum == 1) {listStudent(plist,count);}
        else if(snum == 2){
            if(count>=100){//여기 1이어서 100으로 바꿨어         
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
	else if (snum==5){
       saveData(plist,count);
 
	   }
    else if(snum==6){
        int search_num;
        printf("무엇으로 검색하실 건가요? (1:이름,2:학번,3:방호수):");
        scanf("%d",&search_num);
        if(search_num==1) serchName(plist,index);
        else if(search_num==2) serchnumber(plist,index);
        else if (search_num==3) serchho(plist,index);
    }

    }
    
    printf("종료됨!\n");

    return 0;
}
