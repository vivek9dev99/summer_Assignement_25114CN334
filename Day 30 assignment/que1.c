//wap to create student record system using array and strings
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int roll_no;
    char name[50];
    float marks;
};

void addStudent(struct Student s[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nSystem database is full!\n");
        return;
    }
    
    printf("\nEnter Roll Number: ");
    scanf("%d", &s[*count].roll_no);
    getchar();
    
    printf("Enter Name: ");
    fgets(s[*count].name, sizeof(s[*count].name), stdin);
    s[*count].name[strcspn(s[*count].name, "\n")] = '\0';
    
    printf("Enter Marks: ");
    scanf("%f", &s[*count].marks);
    
    (*count)++;
    printf("\nStudent record added successfully!\n");
}

void displayStudents(const struct Student s[], int count) {
    if (count == 0) {
        printf("\nNo student records found!\n");
        return;
    }
    
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll No: %d | Name: %s | Marks: %.2f\n", s[i].roll_no, s[i].name, s[i].marks);
    }
}

void searchStudent(const struct Student s[], int count) {
    if (count == 0) {
        printf("\nNo records available to search!\n");
        return;
    }
    
    int search_roll;
    int found = 0;
    
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &search_roll);
    
    for (int i = 0; i < count; i++) {
        if (s[i].roll_no == search_roll) {
            printf("\nStudent Found:\n");
            printf("Roll No: %d\nName: %s\nMarks: %.2f\n", s[i].roll_no, s[i].name, s[i].marks);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("\nStudent with Roll Number %d not found.\n", search_roll);
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;
    
    do {
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                printf("\nExiting system.\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}
