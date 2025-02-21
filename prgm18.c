#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 1000

typedef struct {
    int rollNo;          
    char name[50];     
    int maths, physics, chemistry, cs; 
    int totalMarks;     
    float percentage;    
    char grade;          
} Student;

void saveStudents(Student std[], int n) {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        perror("Cannot create file");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d %s %d %d %d %d\n", std[i].rollNo, 
        std[i].name,std[i].maths,std[i].physics,std[i].chemistry,std[i].cs);
    }
    fclose(file);
}

void readStudent(Student std[], int n) {
    printf("Enter the  details \n");
    for (int i = 0; i < n; i++) {
        printf("Enter the Student %d details:\n", i + 1);
        printf("ID: ");
        scanf("%d", &std[i].rollNo);
        printf("Name: ");
        scanf(" %s", std[i].name);
        printf("Enter the marks of subjects:\n");
                printf("Maths: ");
        scanf("%d", &std[i].maths);
                printf("\nphysics: ");
        scanf("%d", &std[i].physics);
                printf("\nchemistry: ");
        scanf("%d", &std[i].chemistry);
                printf("\nCs: ");
        scanf("%d", &std[i].cs);
    }
    for(int i = 0; i < n; i++) {
        std[i].totalMarks=std[i].maths+std[i].chemistry+std[i].physics+std[i].cs;
        std[i].percentage = (float)std[i].totalMarks / 4.0f;
        if(std[i].percentage>=80){
        std[i].grade='A';
    }
    else if(std[i].percentage>=60&&std[i].percentage<80){
        std[i].grade='B';
    }
    else if(std[i].percentage>=40&&std[i].percentage<60){
        std[i].grade='C';
    }
   else{
        std[i].grade='F';
   }
    }
    
}

void displayStudent(Student std[], int n) {
    printf("--------------------------------------------------------------------\n");
    printf("|%5s|%20s|%7s|%7s|%7s|%7s|%7s|%7s|%7s","Id","Name","Maths","Physics","Chemistry","cs","Total","Percent","grade");
    printf("\n-------------------------------------------------------------------\n");
    for(int i=0;i<n;i++){
    printf("|%5d|%20s|%7d|%7d|%7d|%7d|%7d|%7.2f|%7c",std[i].rollNo,std[i].name,std[i].maths,std[i].chemistry,std[i].physics,std[i].cs,std[i].totalMarks,std[i].percentage,std[i].grade);
}
}

int main() {
    int studentCount = 0;
    Student students[MAX_STUDENTS];

    printf("Enter the studentCount (or 0 to load from file): ");
    scanf("%d", &studentCount);

    if (studentCount > 0) {
        readStudent(students, studentCount);
        saveStudents(students,studentCount);
        displayStudent(students, studentCount) ;
    } else if (studentCount == 0) {
        
    } else {
      printf("Invalid input\n");
      return 1;
    }
    return 0;
}
