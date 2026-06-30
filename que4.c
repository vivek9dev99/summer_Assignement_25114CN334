// wap to develope complete mini project using arrays, string, functions 
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

void displayMenu();
void addStudent(int rollNumbers[], char names[][NAME_LENGTH], float gpas[], int *count);
void displayStudents(const int rollNumbers[], const char names[][NAME_LENGTH], const float gpas[], int count);
void searchStudent(const int rollNumbers[], const char names[][NAME_LENGTH], const float gpas[], int count);
void updateGPA(int rollNumbers[], float gpas[], int count);
void deleteStudent(int rollNumbers[], char names[][NAME_LENGTH], float gpas[], int *count);

int main() {
    int rollNumbers[MAX_STUDENTS];
    char names[MAX_STUDENTS][NAME_LENGTH];
    float gpas[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input type!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(rollNumbers, names, gpas, &count);
                break;
            case 2:
                displayStudents(rollNumbers, names, gpas, count);
                break;
            case 3:
                searchStudent(rollNumbers, names, gpas, count);
                break;
            case 4:
                updateGPA(rollNumbers, gpas, count);
                break;
            case 5:
                deleteStudent(rollNumbers, names, gpas, &count);
                break;
            case 6:
                printf("\nExiting system. Goodbye!\n");
                break;
            default:
                printf("Invalid selection! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n=== STUDENT DATABASE SYSTEM ===\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student by Roll Number\n");
    printf("4. Update Student GPA\n");
    printf("5. Delete Student\n");
    printf("6. Exit\n");
    printf("================================\n");
}

void addStudent(int rollNumbers[], char names[][NAME_LENGTH], float gpas[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nDatabase is full! Cannot add more students.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number: ");
    scanf("%d", &roll);

    for (int i = 0; i < *count; i++) {
        if (rollNumbers[i] == roll) {
            printf("Error: A student with Roll Number %d already exists!\n", roll);
            return;
        }
    }

    rollNumbers[*count] = roll;
    printf("Enter Student Name: ");
    while (getchar() != '\n');
    fgets(names[*count], NAME_LENGTH, stdin);
    names[*count][strcspn(names[*count], "\n")] = '\0';

    printf("Enter GPA: ");
    scanf("%f", &gpas[*count]);

    (*count)++;
    printf("Student added successfully!\n");
}

void displayStudents(const int rollNumbers[], const char names[][NAME_LENGTH], const float gpas[], int count) {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n%-10s %-30s %-5s\n", "Roll No", "Name", "GPA");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-5.2f\n", rollNumbers[i], names[i], gpas[i]);
    }
}

void searchStudent(const int rollNumbers[], const char names[][NAME_LENGTH], const float gpas[], int count) {
    if (count == 0) {
        printf("\nDatabase empty.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (rollNumbers[i] == roll) {
            printf("\nStudent Found:\n");
            printf("Roll Number: %d\n", rollNumbers[i]);
            printf("Name:        %s\n", names[i]);
            printf("GPA:         %.2f\n", gpas[i]);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll);
}

void updateGPA(int rollNumbers[], float gpas[], int count) {
    if (count == 0) {
        printf("\nDatabase empty.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to update GPA: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (rollNumbers[i] == roll) {
            printf("Current GPA: %.2f\n", gpas[i]);
            printf("Enter New GPA: ");
            scanf("%f", &gpas[i]);
            printf("GPA updated successfully!\n");
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll);
}

void deleteStudent(int rollNumbers[], char names[][NAME_LENGTH], float gpas[], int *count) {
    if (*count == 0) {
        printf("\nDatabase empty.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < *count; i++) {
        if (rollNumbers[i] == roll) {
            for (int j = i; j < *count - 1; j++) {
                rollNumbers[j] = rollNumbers[j + 1];
                strcpy(names[j], names[j + 1]);
                gpas[j] = gpas[j + 1];
            }
            (*count)--;
            printf("Student record deleted successfully!\n");
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll);
}
