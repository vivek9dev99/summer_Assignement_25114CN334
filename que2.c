//wap to create menu driven array operations system 
#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int arr[], int *size, int capacity) {
    if (*size >= capacity) {
        printf("Array overflow. Cannot insert.\n");
        return;
    }
    int element, position;
    printf("Enter element to insert: ");
    scanf("%d", &element);
    printf("Enter position (0 to %d): ", *size);
    scanf("%d", &position);

    if (position < 0 || position > *size) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
    printf("Element inserted successfully.\n");
}

void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("Array underflow. Cannot delete.\n");
        return;
    }
    int position;
    printf("Enter position to delete (0 to %d): ", *size - 1);
    scanf("%d", &position);

    if (position < 0 || position >= *size) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element deleted successfully.\n");
}

void search(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    int target, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &target);

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element found at index %d.\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element not found.\n");
    }
}

int main() {
    int capacity = 100;
    int arr[100];
    int size = 0;
    int choice;

    while (1) {
        printf("\n--- ARRAY OPERATIONS MENU ---\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search Element\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(arr, &size, capacity);
                break;
            case 2:
                deleteElement(arr, &size);
                break;
            case 3:
                search(arr, size);
                break;
            case 4:
                display(arr, size);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
