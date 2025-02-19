#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    struct Student* s = malloc(n * sizeof(struct Student));
    
    for(int i = 0; i < n; i++) {
        printf("Enter Student %d Name: ", i+1);
        scanf("%s", s[i].name);
        printf("Enter Marks: ");
        scanf("%d", &s[i].marks);
    }
    
    printf("\nStudent Records:\n");
    for(int i = 0; i < n; i++) {
        printf("%s :- %d\n", s[i].name, s[i].marks);
    }
    
    free(s);
    return 0;
}
