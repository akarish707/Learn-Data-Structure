#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Course{
    char ID[10];
    int score;
};

struct Student{
    char name[255];
    double GPA;
    Course c;
};

int plus(int a,int b){
    return a+b;
};

//createstudent akan mereturn pointer yang mengarah ke Student
// const chare *name sama aja kayak char name[]
Student *createStudent(const char*name, double gpa,const char *ID,int score){
 //alokasi memory
 Student *newStudent = (Student*)malloc(sizeof(Student));
 strcpy(newStudent->name,name);
 
 //hasil = hasil + 3 sama aja dengan hasil +=3
 //(*newStudent).atributnya sama aja dengan newStudent -> atriburnya
 newStudent->GPA = gpa;
 strcpy(newStudent->c.ID,ID);
 newStudent -> c.score = score;
 return newStudent;
}

void removeStudent(Student *s){
    free(s);
    s=NULL;
}

void printStudent(Student *s){
    printf("Name : %s\n", s->name);
    printf("GPA: %lf\n",s->GPA);
    printf("Course ID : %s\n",s->c.ID);
    printf("score : %d\n",s->c.score);
}

int main(){
    //printf("%lu\n",sizeof(Student));
    //s1 mengarah ke student yang direturn oleh createStudent
    Student *s1 = createStudent("Budi",3.90,"COMP6048",100);
    Student *s2 = createStudent("Cheryl",4.00,"COMP6048",100);
    printf("Before Remove\n");
    printStudent(s1);
    printStudent(s2);
    
    return 0;
}