//wapto create library management system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[50];
    char author[50];
    int is_issued;
};

struct Book library[MAX_BOOKS];
int book_count = 0;

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("\nLibrary capacity reached.\n");
        return;
    }
    struct Book b;
    printf("\nEnter Book ID: ");
    scanf("%d", &b.id);
    getchar();
    printf("Enter Title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = 0;
    printf("Enter Author: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = 0;
    b.is_issued = 0;
    library[book_count] = b;
    book_count++;
    printf("Book added successfully.\n");
}

void display_books() {
    if (book_count == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }
    printf("\nID\tTitle\t\tAuthor\t\tStatus\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d\t%s\t\t%s\t\t%s\n", library[i].id, library[i].title, library[i].author, library[i].is_issued ? "Issued" : "Available");
    }
}

void search_book() {
    int id, found = 0;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            printf("\nBook Found:\nID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n", library[i].id, library[i].title, library[i].author, library[i].is_issued ? "Issued" : "Available");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
}

void issue_book() {
    int id, found = 0;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            found = 1;
            if (library[i].is_issued) {
                printf("Book is already issued.\n");
            } else {
                library[i].is_issued = 1;
                printf("Book issued successfully.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
}

void return_book() {
    int id, found = 0;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            found = 1;
            if (!library[i].is_issued) {
                printf("Book was not issued.\n");
            } else {
                library[i].is_issued = 0;
                printf("Book returned successfully.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n*** Library Management System ***\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                search_book();
                break;
            case 4:
                issue_book();
                break;
            case 5:
                return_book();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
