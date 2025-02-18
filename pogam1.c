#include <stdio.h>
#include <string.h>
int main()
{
int id;
char name[100];
float salary;
int attendance;
//read employee details 
printf("Enter id:");
scanf("%d",&id);

printf("Enter name:");
scanf("%s",name);

printf("Enter salary:");
scanf("%f",&salary);

printf("Enter number of days the employee has worked:");
scanf("%d",&attendance);

//payroll processing
float bonus = 0.0f;
float gross_salary=0.0f;
char category[50] = "Good";

//caluculate the salary bonus
if (attendance>25)
{
    bonus= (bonus / 100.0f)*5;
}
else if(attendance<10)
{
    bonus = (-1.0f*((bonus/100.0f)*50.0f));
}
//final salary
gross_salary= (salary + bonus);
//categorize employee
if(attendance > 25)
{
    strcpy(category,"Excellent");
}
else if(15 < attendance < 25)
{
    strcpy(category,"Good");
}
if(attendance < 15)
{
    strcpy(category,"Needs Improvement");
}
//display the payroll details
printf("ID:%d",id);
printf("Name:%s",name);
printf("Basic salary:%.2f",salary);
if(bonus>0)
{
    printf("Bonus : %.2f\n",bonus);
}
printf("Final salary:%.2f\n",gross_salary);
printf("Employee Preformance : %s",category);
return 0;
}
