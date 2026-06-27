//wap to create student record management system

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int roll_no;
    char name[50];
    float gpa;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("\nSystem database is full!\n");
        return;
    }
    
    Student s;
    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll_no);
    
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == s.roll_no) {
            printf("Error: Roll number already exists.\n");
            return;
        }
    }
    
    printf("Enter Name: ");
    scanf(" %[^\n]s", s.name);
    printf("Enter GPA: ");
    scanf("%f", &s.gpa);
    
    students[student_count++] = s;
    printf("Student record added successfully!\n");
}

void view_students() {
    if (student_count == 0) {
        printf("\nNo student records found.\n");
        return;
    }
    
    printf("\n---------------------------------------------\n");
    printf("%-10s %-25s %-5s\n", "Roll No", "Name", "GPA");
    printf("---------------------------------------------\n");
    for (int i = 0; i < student_count; i++) {
        printf("%-10d %-25s %-5.2f\n", students[i].roll_no, students[i].name, students[i].gpa);
    }
    printf("---------------------------------------------\n");
}

void search_student() {
    if (student_count == 0) {
        printf("\nNo student records found to search.\n");
        return;
    }
    
    int roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);
    
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll) {
            printf("\nRecord Found:\n");
            printf("Roll Number: %d\n", students[i].roll_no);
            printf("Name:        %s\n", students[i].name);
            printf("GPA:         %.2f\n", students[i].gpa);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll);
}

void delete_student() {
    if (student_count == 0) {
        printf("\nNo student records found to delete.\n");
        return;
    }
    
    int roll;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);
    
    int index = -1;
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Student with Roll Number %d not found.\n", roll);
        return;
    }
    
    for (int i = index; i < student_count - 1; i++) {
        students[i] = students[i + 1];
    }
    student_count--;
    printf("Student record deleted successfully!\n");
}

int main() {
    int choice;
    
    do {
        printf("\n=== Student Record Management System ===\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                view_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                delete_student();
                break;
            case 5:
                printf("\nExiting the system. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please select between 1 and 5.\n");
        }
    } while (choice != 5);
    
    return 0;
}
