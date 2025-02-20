#include <stdio.h>
#include <string.h>

struct Employee_t {
    int id;
    char name[255];
    float salary;
    char department[50];
};

typedef struct Employee_t Employee;

void readEmployees(Employee emp[], int n);
void displayEmployees(Employee emp[], int n);
Employee findHighestSalary(Employee emp[], int n);

int main() {
    int employeeCount;
    printf("Enter the number of employees: ");
    scanf("%d", &employeeCount);
    Employee employees[1000];
    readEmployees(employees, employeeCount);
    displayEmployees(employees, employeeCount);
    Employee highestSalariedEmployee = findHighestSalary(employees, employeeCount);
    printf("Employee with the highest salary: %s, %.2f (%s)\n", highestSalariedEmployee.name, highestSalariedEmployee.salary, highestSalariedEmployee.department);
    return 0;
}

void readEmployees(Employee emp[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i + 1);
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

void displayEmployees(Employee emp[], int n) {
    printf("\nEmployee Details:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f, Department: %s\n", emp[i].id, emp[i].name, emp[i].salary, emp[i].department);
    }
}

Employee findHighestSalary(Employee emp[], int n) {
    Employee highest = emp[0];
    for (int i = 1; i < n; i++) {
        if (emp[i].salary > highest.salary) {
            highest = emp[i];
        }
    }
    return highest;
}
