//wap to create inventory management system 
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Product inventory[MAX];
int product_count = 0;

void add_product() {
    if (product_count >= MAX) {
        printf("\nInventory is full!\n");
        return;
    }
    struct Product p;
    printf("\nEnter Product ID: ");
    scanf("%d", &p.id);
    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == p.id) {
            printf("Error: Product ID already exists!\n");
            return;
        }
    }
    printf("Enter Product Name: ");
    scanf("%s", p.name);
    printf("Enter Quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter Price: ");
    scanf("%f", &p.price);
    inventory[product_count++] = p;
    printf("Product added successfully!\n");
}

void view_inventory() {
    if (product_count == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    printf("\nID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < product_count; i++) {
        printf("%d\t%-15s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void search_product() {
    if (product_count == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    int id;
    printf("\nEnter Product ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == id) {
            printf("\nProduct Found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Product with ID %d not found.\n", id);
}

void update_stock() {
    if (product_count == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    int id, choice, amt;
    printf("\nEnter Product ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == id) {
            printf("1. Restock (Add)\n2. Sell (Subtract)\nChoice: ");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("Enter quantity to add: ");
                scanf("%d", &amt);
                inventory[i].quantity += amt;
                printf("Stock updated successfully!\n");
            } else if (choice == 2) {
                printf("Enter quantity to sell: ");
                scanf("%d", &amt);
                if (inventory[i].quantity >= amt) {
                    inventory[i].quantity -= amt;
                    printf("Sale successful! Stock updated.\n");
                } else {
                    printf("Error: Insufficient stock!\n");
                }
            } else {
                printf("Invalid choice!\n");
            }
            return;
        }
    }
    printf("Product with ID %d not found.\n", id);
}

void delete_product() {
    if (product_count == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    int id;
    printf("\nEnter Product ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < product_count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            product_count--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found.\n", id);
}

int main() {
    int choice;
    do {
        printf("\n=== INVENTORY MANAGEMENT SYSTEM ===\n");
        printf("1. Add Product\n");
        printf("2. View Inventory\n");
        printf("3. Search Product\n");
        printf("4. Update Stock (Buy/Sell)\n");
        printf("5. Delete Product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_product(); break;
            case 2: view_inventory(); break;
            case 3: search_product(); break;
            case 4: update_stock(); break;
            case 5: delete_product(); break;
            case 6: printf("\nExiting system.\n"); break;
            default: printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}
