#ifndef STUDENT_HEADER
#define STUDENT_HEADER


typedef struct {
    int rollNo;
    char name[50];
    int maths, physics, chemistry, cs;
    int totalMarks;
    float percentage;
    char grade;
} Student;

#endif