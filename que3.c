//wap to create ticket booking system

#include <stdio.h>
#include <string.h>

#define TOTAL_SEATS 50

struct Ticket {
    int id;
    char name[50];
    int booked;
};

struct Ticket system[TOTAL_SEATS];

void init() {
    for (int i = 0; i < TOTAL_SEATS; i++) {
        system[i].id = i + 1;
        system[i].booked = 0;
        strcpy(system[i].name, "");
    }
}

void display() {
    printf("\n--- Seat Status ---\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        printf("[%02d:%s] ", system[i].id, system[i].booked ? "B" : "A");
        if ((i + 1) % 5 == 0) printf("\n");
    }
}

void book() {
    int id;
    printf("\nEnter seat number (1-%d): ", TOTAL_SEATS);
    scanf("%d", &id);
    
    if (id < 1 || id > TOTAL_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }
    if (system[id - 1].booked) {
        printf("Seat already booked.\n");
        return;
    }
    
    printf("Enter passenger name: ");
    scanf("%s", system[id - 1].name);
    system[id - 1].booked = 1;
    printf("Seat %d booked successfully.\n", id);
}

void cancel() {
    int id;
    printf("\nEnter seat number to cancel: ", TOTAL_SEATS);
    scanf("%d", &id);
    
    if (id < 1 || id > TOTAL_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }
    if (!system[id - 1].booked) {
        printf("Seat is not booked yet.\n");
        return;
    }
    
    system[id - 1].booked = 0;
    strcpy(system[id - 1].name, "");
    printf("Booking for seat %d canceled.\n", id);
}

int main() {
    int choice;
    init();
    
    while (1) {
        printf("\n1. View Seats\n2. Book Ticket\n3. Cancel Ticket\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: display(); break;
            case 2: book(); break;
            case 3: cancel(); break;
            case 4: return 0;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
