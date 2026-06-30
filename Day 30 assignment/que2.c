//wap to create mini library system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
    int is_issued;
};

void addBook(struct Book books[], int *count) {
    printf("\nEnter Book ID: ");
    scanf("%d", &books[*count].id);
    getchar();
    printf("Enter Book Title: ");
    fgets(books[*count].title, sizeof(books[*count].title), stdin);
    books[*count].title[strcspn(books[*count].title, "\n")] = '\0';
    printf("Enter Author Name: ");
    fgets(books[*count].author, sizeof(books[*count].author), stdin);
    books[*count].author[strcspn(books[*count].author, "\n")] = '\0';
    books[*count].is_issued = 0;
    (*count)++;
    printf("Book added successfully!\n");
}

void displayBooks(struct Book books[], int count) {
    if (count == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }
    printf("\n%-10s %-30s %-30s %-10s\n", "ID", "Title", "Author", "Status");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-30s %-10s\n", 
               books[i].id, 
               books[i].title, 
               books[i].author, 
               books[i].is_issued ? "Issued" : "Available");
    }
}

void searchBook(struct Book books[], int count) {
    if (count == 0) {
        printf("\nLibrary is empty.\n");
        return;
    }
    char query[100];
    int found = 0;
    getchar();
    printf("\nEnter Book Title to Search: ");
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcasecmp(books[i].title, query) == 0) {
            printf("\nBook Found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n", 
                   books[i].id, books[i].title, books[i].author, 
                   books[i].is_issued ? "Issued" : "Available");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nBook not found.\n");
    }
}

void issueBook(struct Book books[], int count) {
    int id, found = 0;
    printf("\nEnter Book ID to Issue: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            found = 1;
            if (books[i].is_issued) {
                printf("Book is already issued.\n");
            } else {
                books[i].is_issued = 1;
                printf("Book issued successfully!\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Book ID not found.\n");
    }
}

void returnBook(struct Book books[], int count) {
    int id, found = 0;
    printf("\nEnter Book ID to Return: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            found = 1;
            if (!books[i].is_issued) {
                printf("Book was not issued.\n");
            } else {
                books[i].is_issued = 0;
                printf("Book returned successfully!\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Book ID not found.\n");
    }
}

int main() {
    struct Book library[1000];
    int bookCount = 0;
    int choice;

    while (1) {
        printf("\n=== MINI LIBRARY SYSTEM ===\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                searchBook(library, bookCount);
                break;
            case 4:
                issueBook(library, bookCount);
                break;
            case 5:
                returnBook(library, bookCount);
                break;
            case 6:
                printf("\nExiting system.\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
