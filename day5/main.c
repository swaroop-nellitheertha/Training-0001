#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
#include "stack.h"

#define MAX_STUDENTS 1000
#define MAX_STACK_SIZE 100


void StackInit(Stack* stk) {
    stk->_size = 0;
    stk->_top = -1;
}

Student StackTop(Stack* stk) {
    if (StackEmpty(stk)) {
        Student emptyStudent = {0};
        printf("Stack Empty\n");
        return emptyStudent;
    }
    return stk->elements[stk->_top];
}

int StackEmpty(Stack* stk) {
    return (stk->_top == -1);
}

int StackFull(Stack* stk) {
    return (stk->_top == MAX_STACK_SIZE - 1);
}

void StackPush(Stack* stk, Student element) {
    if (StackFull(stk)) {
        printf("Stack Full\n");
        return;
    }
    stk->_top++;
    stk->elements[stk->_top] = element;
    stk->_size++;
}

void StackPop(Stack* stk) {
    if (StackEmpty(stk)) {
        printf("Stack Empty\n");
        return;
    }
    stk->_top--;
    stk->_size--;
}

void readStudents(Student std[], int n) {
    printf("Enter the details \n");
    for (int i = 0; i < n; i++) {
        printf("Enter the Student %d details:\n", i + 1);
        printf("ID: ");
        scanf("%d", &std[i].rollNo);
        printf("Name: ");
        scanf(" %s", std[i].name);
        printf("Enter the marks of subjects:\n");
        printf("Maths: ");
        scanf("%d", &std[i].maths);
        printf("Physics: ");
        scanf("%d", &std[i].physics);
        printf("Chemistry: ");
        scanf("%d", &std[i].chemistry);
        printf("CS: ");
        scanf("%d", &std[i].cs);

        std[i].totalMarks = std[i].maths + std[i].chemistry + std[i].physics + std[i].cs;
        std[i].percentage = (float)std[i].totalMarks / 4.0f;

        if (std[i].percentage >= 80) {
            std[i].grade = 'A';
        } else if (std[i].percentage >= 60 && std[i].percentage < 80) {
            std[i].grade = 'B';
        } else if (std[i].percentage >= 40 && std[i].percentage < 60) {
            std[i].grade = 'C';
        } else {
            std[i].grade = 'F';
        }
        printf("\n");
    }
}

void displayStudents(Student std[], int n) {
    printf("--------------------------------------------------------------------\n");
    printf("%5s | %-20s | %7s | %7s | %7s | %7s | %7s | %7s | %7s |\n", "ID", "Name", "Maths", "Physics", "Chemistry", "CS", "Total", "Percent", "Grade");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%5d | %-20s | %7d | %7d | %7d | %7d | %7d | %7.2f | %7c |\n", std[i].rollNo, std[i].name, std[i].maths, std[i].physics, std[i].chemistry, std[i].cs, std[i].totalMarks, std[i].percentage, std[i].grade);
    }
    printf("--------------------------------------------------------------------\n");
}

void saveStudents(Student std[], int n) {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        perror("Cannot create file");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d %s %d %d %d %d\n", std[i].rollNo, std[i].name, std[i].maths, std[i].physics, std[i].chemistry, std[i].cs);
    }
    fclose(file);
}

int main() {
    int studentCount = 0;
    Student *students = NULL;
    Stack studentStack;

    StackInit(&studentStack);

    printf("Enter the number of students: ");
    scanf("%d", &studentCount);

    if (studentCount > 0) {
        students = (Student *)malloc(studentCount * sizeof(Student));
        if (students == NULL) {
            perror("Memory allocation failed");
            return 1;
        }

        readStudents(students, studentCount);

        for (int i = 0; i < studentCount; i++) {
            StackPush(&studentStack, students[i]);
        }

        saveStudents(students, studentCount);

        printf("\nStudent data (from Stack):\n");
        printf("--------------------------------------------------------------------\n");
        printf("%5s | %-20s | %7s | %7s | %7s | %7s | %7s | %7s | %7s |\n", "ID", "Name", "Maths", "Physics", "Chemistry", "CS", "Total", "Percent", "Grade");
        printf("--------------------------------------------------------------------\n");

        while (!StackEmpty(&studentStack)) {
            Student currentStudent = StackTop(&studentStack);
            printf("%5d | %-20s | %7d | %7d | %7d | %7d | %7d | %7.2f | %7c |\n", currentStudent.rollNo, currentStudent.name, currentStudent.maths, currentStudent.physics, currentStudent.chemistry, currentStudent.cs, currentStudent.totalMarks, currentStudent.percentage, currentStudent.grade);
            StackPop(&studentStack);
        }
         printf("--------------------------------------------------------------------\n");

        free(students);
    } else {
        printf("Invalid input\n");
        return 1;
    }

    return 0;
}
