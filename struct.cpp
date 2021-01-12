#include <stdio.h> //buat library input dan output
#include <string.h>//strcpy
#include <stdlib.h>//dynamic memory allocation

struct Course{
    char ID[10];//10 bytes
    int score;//4 bytes
    //alasan dipisahkan karena bisa saja dosen, mahasiswa maupun lainnya punya course juga 
    //jadi banyak tipenya
};

struct Student{
    char name[255];//255 bytes
    double GPA;//8 bytes
    Course c;//object course
};

int plus(int a,int b){
    return a+b;
};
//tipe data yang di return : int
//nama function +
//parameter a dan b

//createstudent akan mereturn pointer yang mengarah ke Student
// const chare *name sama aja kayak char name[];
//kalau gapake * dia cuman return student aja
//constant menjamin parameter itu gaakan berubah isinya
Student *createStudent(const char*name, double gpa,const char *ID,int score){
 //alokasi memory
 Student *newStudent = (Student*)malloc(sizeof(Student));
 strcpy(newStudent->name,name);// strcpy ((*newStudent).name,name); -> untuk memperpendek
 
 //hasil = hasil + 3 sama aja dengan hasil +=3
 //(*newStudent).atributnya sama aja dengan newStudent -> atriburnya
 newStudent->GPA = gpa;
 strcpy(newStudent->c.ID,ID);
 newStudent -> c.score = score;
 return newStudent;
}
//tipe data yang direturn :Student*
//nama function createStudent
//parameter name,gpa, course (id dan course)

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
    //Student students[10]; -> static memory allocation
    Student *s1 = createStudent("Budi",3.90,"COMP6048",100);
    Student *s2 = createStudent("Cheryl",4.00,"COMP6048",100);
    printf("Before Remove\n");
    printStudent(s1);
    printStudent(s2);
    removeStudent(s1);
    removeStudent(s2);
    printf("After Remove\n");
    printStudent(s1);
    printStudent(s2);
    
    return 0;
}