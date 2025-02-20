#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 1000

typedef struct {
    int id;
    char name[255];
    float salary;
    char department[50];
} Employee;

void readEmployee(Employee emp[], int n) {
    printf("Enter the employee details \n");
    for (int i = 0; i < n; i++) {
        printf("Enter the employee %d details:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf(" %s", emp[i].name);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
        printf("Department: ");
        scanf(" %s", emp[i].department);
    }
}

void displayEmployee(Employee emp[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Employee %d data:\n ID: %d\n Name: %s \n Salary: %f \n Department: %s\n", i + 1,
               emp[i].id, emp[i].name, emp[i].salary, emp[i].department);
    }
}

void saveEmployees(Employee emp[], int n) {
    FILE *file = fopen("employees.txt", "w");
    if (file == NULL) {
        perror("Cannot create file");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d %s %f %s\n", emp[i].id, emp[i].name, emp[i].salary, emp[i].department);
    }
    fclose(file);
}

void loadEmployees(Employee emp[], int *n) {
    FILE *file = fopen("employees.txt", "r");
    if (file == NULL) {
        perror("Cannot read file");
        return;
    }
    *n = 0;
    while (fscanf(file, "%d %s %f %s", &emp[*n].id, emp[*n].name, &emp[*n].salary, emp[*n].department) == 4 && *n < MAX_EMPLOYEES) {
        (*n)++;
    }
    fclose(file);
}

Employee findHighestSalary(Employee emp[], int n) {
    if (n == 0) {
        Employee emptyEmployee = {0, "", 0.0, ""};
        return emptyEmployee;
    }

    Employee highestSalariedPerson = emp[0];

    for (int i = 1; i < n; i++) {
        if (emp[i].salary > highestSalariedPerson.salary) {
            highestSalariedPerson = emp[i];
        }
    }
    return highestSalariedPerson;
}

int main() {
    int employeeCount = 0;
    Employee employees[MAX_EMPLOYEES];

    printf("Enter the employeeCount (or 0 to load from file): ");
    scanf("%d", &employeeCount);

    if (employeeCount > 0) {
        readEmployee(employees, employeeCount);
        displayEmployee(employees, employeeCount);
        saveEmployees(employees, employeeCount);
    } else if (employeeCount == 0) {
        loadEmployees(employees, &employeeCount);
        if (employeeCount > 0) {
          printf("Employees loaded from file:\n");
          displayEmployee(employees, employeeCount);
        }
    } else {
      printf("Invalid input\n");
      return 1;
    }

    Employee highestSalariedEmployee = findHighestSalary(employees, employeeCount);

    if (employeeCount > 0) {
      printf("Employee with Highest salary:\n ID: %d \n Name: %s \n Salary: %f \n Department: %s\n",
             highestSalariedEmployee.id, highestSalariedEmployee.name,
             highestSalariedEmployee.salary, highestSalariedEmployee.department);
    }

    return 0;
}
