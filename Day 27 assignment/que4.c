//wap to create salary to create marksheet genration system
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    float marks[5];
    float total;
    float percentage;
    char division[20];
};

struct Employee {
    int id;
    char empName[50];
    float basic;
    float hra;
    float da;
    float pf;
    float gross;
    float net;
};

int main() {
    struct Student s;
    s.total = 0;
    
    printf("Enter Student Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0;
    
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);
    
    printf("Enter marks for 5 subjects:\n");
    for(int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &s.marks[i]);
        s.total += s.marks[i];
    }
    
    s.percentage = s.total / 5.0;
    
    if(s.percentage >= 80) strcpy(s.division, "First Class");
    else if(s.percentage >= 60) strcpy(s.division, "Second Class");
    else if(s.percentage >= 40) strcpy(s.division, "Pass");
    else strcpy(s.division, "Fail");

    printf("\n--- STUDENT MARKSHEET ---\n");
    printf("Name: %s\n", s.name);
    printf("Roll Number: %d\n", s.roll);
    printf("Total Marks: %.2f / 500\n", s.total);
    printf("Percentage: %.2f%%\n", s.percentage);
    printf("Division: %s\n", s.division);

    struct Employee e;
    printf("\n--- EMPLOYEE PAYROLL SETUP ---\n");
    printf("Enter Employee ID: ");
    scanf("%d", &e.id);
    getchar(); 
    
    printf("Enter Employee Name: ");
    fgets(e.empName, sizeof(e.empName), stdin);
    e.empName[strcspn(e.empName, "\n")] = 0;
    
    printf("Enter Basic Salary: ");
    scanf("%f", &e.basic);
    
    e.hra = 0.20 * e.basic;
    e.da = 0.50 * e.basic;
    e.pf = 0.12 * e.basic;
    e.gross = e.basic + e.hra + e.da;
    e.net = e.gross - e.pf;

    printf("\n--- SALARY SLIP ---\n");
    printf("Employee ID: %d\n", e.id);
    printf("Employee Name: %s\n", e.empName);
    printf("Basic Salary: %.2f\n", e.basic);
    printf("HRA: %.2f\n", e.hra);
    printf("DA: %.2f\n", e.da);
    printf("PF: %.2f\n", e.pf);
    printf("Gross Salary: %.2f\n", e.gross);
    printf("Net Salary: %.2f\n", e.net);

    return 0;
}
