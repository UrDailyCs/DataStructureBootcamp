#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Course{

    char id[10];
    double score;

};
struct Student
{
    char name[50];
    int age;
    double GPA;
    Course C;
};

Student *createStudent(const char *name, int age,double GPA, const char *id, double score ){
    Student *newStudent=(Student*)malloc(sizeof(Student));
    strcpy(newStudent->name,name);
    newStudent->age=age;
    newStudent->GPA=GPA;
    strcpy(newStudent->C.id,id);
    newStudent->C.score=score;

    return newStudent;
}

void print(Student *s){
    printf("Name: %s\n",s->name);
    printf("Age : %d\n",s->age);
    printf("GPA : %.2lf\n",s->GPA);
    printf("Class: %s\n",s->C.id);
    printf("Score: %.2lf\n\n",s->C.score);
}

void removeStudent(Student *s) {
     free(s); 
    s = NULL; 
}

int main (){

    Student *s1=createStudent("Nico",18,3.67,"COMP4044",98);
    Student *s2=createStudent("Mic",20,4.00,"COMP301",99.1);

    print(s1);print(s2);

    removeStudent(s1);
    print(s1);print(s2);

    return 0;
}