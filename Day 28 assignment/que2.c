//wap to create bank account system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[50];
    double balance;
} Account;

Account bank[MAX_ACCOUNTS];
int totalAccounts = 0;

void createAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("\nSystem full. Cannot create more accounts.\n");
        return;
    }
    
    Account newAcc;
    printf("\nEnter Account Number: ");
    scanf("%d", &newAcc.accountNumber);
    
    for (int i = 0; i < totalAccounts; i++) {
        if (bank[i].accountNumber == newAcc.accountNumber) {
            printf("\nAccount number already exists!\n");
            return;
        }
    }
    
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]s", newAcc.name);
    printf("Enter Initial Deposit: ");
    scanf("%lf", &newAcc.balance);
    
    if (newAcc.balance < 0) {
        printf("\nInvalid initial deposit amount.\n");
        return;
    }
    
    bank[totalAccounts] = newAcc;
    totalAccounts++;
    printf("\nAccount created successfully!\n");
}

int findAccount(int accNum) {
    for (int i = 0; i < totalAccounts; i++) {
        if (bank[i].accountNumber == accNum) {
            return i;
        }
    }
    return -1;
}

void depositMoney() {
    int accNum;
    double amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);
    
    int idx = findAccount(accNum);
    if (idx == -1) {
        printf("\nAccount not found!\n");
        return;
    }
    
    printf("Enter Amount to Deposit: ");
    scanf("%lf", &amount);
    
    if (amount <= 0) {
        printf("\nInvalid amount.\n");
        return;
    }
    
    bank[idx].balance += amount;
    printf("\nSuccessfully deposited. New Balance: %.2f\n", bank[idx].balance);
}

void withdrawMoney() {
    int accNum;
    double amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);
    
    int idx = findAccount(accNum);
    if (idx == -1) {
        printf("\nAccount not found!\n");
        return;
    }
    
    printf("Enter Amount to Withdraw: ");
    scanf("%lf", &amount);
    
    if (amount <= 0) {
        printf("\nInvalid amount.\n");
        return;
    }
    
    if (bank[idx].balance < amount) {
        printf("\nInsufficient funds!\n");
        return;
    }
    
    bank[idx].balance -= amount;
    printf("\nSuccessfully withdrawn. New Balance: %.2f\n", bank[idx].balance);
}

void checkBalance() {
    int accNum;
    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);
    
    int idx = findAccount(accNum);
    if (idx == -1) {
        printf("\nAccount not found!\n");
        return;
    }
    
    printf("\n--- Account Details ---");
    printf("\nAccount Number: %d", bank[idx].accountNumber);
    printf("\nHolder Name   : %s", bank[idx].name);
    printf("\nCurrent Balance: %.2f\n", bank[idx].balance);
}

int main() {
    int choice;
    while (1) {
        printf("\n=== BANK MANAGEMENT SYSTEM ===");
        printf("\n1. Create Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Check Balance");
        printf("\n5. Exit");
        printf("\nEnter choice (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }
    return 0;
}
