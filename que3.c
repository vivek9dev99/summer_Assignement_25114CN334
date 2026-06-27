//wap to create salary management system 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float basic_salary;
    float allowance;
    float deduction;
    float net_salary;
};

void addEmployee(struct Employee emp[], int *count) {
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp[*count].id);
    printf("Enter Name: ");
    scanf(" %[^\n]s", emp[*count].name);
    printf("Enter Basic Salary: ");
    scanf("%f", &emp[*count].basic_salary);
    printf("Enter Allowance: ");
    scanf("%f", &emp[*count].allowance);
    printf("Enter Deduction: ");
    scanf("%f", &emp[*count].deduction);

    emp[*count].net_salary = emp[*count].basic_salary + emp[*count].allowance - emp[*count].deduction;
    (*count)++;
    printf("\nEmployee added successfully!\n");
}

void displayEmployees(struct Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo employee records found.\n");
        return;
    }
    printf("\n%-5s %-20s %-12s %-10s %-10s %-12s\n", "ID", "Name", "Basic", "Allow.", "Deduct.", "Net Salary");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-12.2f %-10.2f %-10.2f %-12.2f\n", 
               emp[i].id, emp[i].name, emp[i].basic_salary, emp[i].allowance, emp[i].deduction, emp[i].net_salary);
    }
}

void searchEmployee(struct Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo employee records found.\n");
        return;
    }
    int searchId;
    int found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == searchId) {
            printf("\nEmployee Found:\n");
            printf("ID: %d\nName: %s\nBasic: %.2f\nAllowance: %.2f\nDeduction: %.2f\nNet Salary: %.2f\n",
                   emp[i].id, emp[i].name, emp[i].basic_salary, emp[i].allowance, emp[i].deduction, emp[i].net_salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
}

int main() {
    struct Employee emp[100];
    int count = 0;
    int choice;

    while (1) {
        printf("\n*** Salary Management System ***\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(emp, &count);
                break;
            case 2:
                displayEmployees(emp, count);
                break;
            case 3:
                searchEmployee(emp, count);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
