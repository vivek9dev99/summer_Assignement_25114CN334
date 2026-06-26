//wap to create atm simulation
#include <stdio.h>

int main() {
    int pin = 1234, input_pin, choice, attempts = 0;
    float balance = 15000.0, amount;
    char trans = 'y';

    while (attempts < 3) {
        printf("Enter PIN: ");
        scanf("%d", &input_pin);
        if (input_pin == pin) break;
        printf("Incorrect. Attempts left: %d\n", 2 - attempts++);
    }
    if (attempts == 3) return printf("Card blocked.\n"), 0;

    do {
        printf("\n1.Balance 2.Withdraw 3.Deposit 4.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Balance: %.2f\n", balance); break;
            case 2:
                printf("Amount: "); scanf("%f", &amount);
                if (amount > balance) printf("Insufficient.\n");
                else printf("Collect cash. New balance: %.2f\n", balance -= amount);
                break;
            case 3:
                printf("Deposit: "); scanf("%f", &amount);
                printf("New balance: %.2f\n", balance += amount);
                break;
            case 4: return 0;
        }
        printf("Another? (y/n): "); scanf(" %c", &trans);
    } while (trans == 'y' || trans == 'Y');
    return 0;
}
