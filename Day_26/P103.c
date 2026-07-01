#include <stdio.h>

int main() {
    int pin = 1234, enteredPin, attempts = 0;
    float balance = 50000.0;
    int choice;
    float amount;
    char trans = 'y';

    
    while (attempts < 3) {
        printf("Enter PIN: ");
        scanf("%d", &enteredPin);
        if (enteredPin == pin) break;
        printf("Wrong PIN. %d left.\n", 2 - attempts++);
        if (attempts == 3) return 0;
    }

    
    do {
        printf("\n1.Balance 2.Withdraw 3.Deposit 4.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Balance: %.2f\n", balance); break;
            case 2: printf("Amt: "); scanf("%f", &amount);
                if (amount > balance) printf("Insufficient!\n");
                else balance -= amount; break;
            case 3: printf("Amt: "); scanf("%f", &amount);
                balance += amount; break;
            case 4: return 0;
        }
        printf("Another? (y/n): ");
        scanf(" %c", &trans);
    } while (trans == 'y' || trans == 'Y');
    return 0;
}