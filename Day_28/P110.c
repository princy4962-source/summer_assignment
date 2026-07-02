#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int acc_number;
    char name[50];
    float balance;
};

void create_account();
void deposit_money();
void withdraw_money();
void check_balance();

int main() {
    int choice;

    while (1) {
        printf("\n==================================\n");
        printf("    WELCOME TO THE BANKING SYSTEM   \n");
        printf("==================================\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit_money();
                break;
            case 3:
                withdraw_money();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                printf("\nThank you for banking with us. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}

void create_account() {
    struct Account acc;
    FILE *fp;

    printf("\n--- Create New Account ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc.acc_number);
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]s", acc.name); 
    printf("Enter Initial Deposit Amount: ");
    scanf("%f", &acc.balance);

    fp = fopen("accounts.dat", "ab"); 
    if (fp == NULL) {
        printf("Error opening file to save data!\n");
        return;
    }

    fwrite(&acc, sizeof(struct Account), 1, fp);
    fclose(fp);

    printf("\nAccount created successfully for %s!\n", acc.name);
}

void deposit_money() {
    int acc_number;
    float amount;
    int found = 0;
    FILE *fp, *temp;

    printf("\n--- Deposit Money ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc_number);
    printf("Enter Amount to Deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Deposit amount must be greater than zero!\n");
        return;
    }

    fp = fopen("accounts.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL) {
        printf("No accounts found!\n");
        return;
    }

    struct Account acc;
    while (fread(&acc, sizeof(struct Account), 1, fp)) {
        if (acc.acc_number == acc_number) {
            acc.balance += amount;
            found = 1;
            printf("\nDeposit successful! New balance: $%.2f\n", acc.balance);
        }
        fwrite(&acc, sizeof(struct Account), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("accounts.dat");
    rename("temp.dat", "accounts.dat");

    if (!found) {
        printf("Account number not found!\n");
    }
}

void withdraw_money() {
    int acc_number;
    float amount;
    int found = 0;
    FILE *fp, *temp;

    printf("\n--- Withdraw Money ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc_number);
    printf("Enter Amount to Withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Withdrawal amount must be greater than zero!\n");
        return;
    }

    fp = fopen("accounts.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL) {
        printf("No accounts found!\n");
        return;
    }

    struct Account acc;
    while (fread(&acc, sizeof(struct Account), 1, fp)) {
        if (acc.acc_number == acc_number) {
            found = 1;
            if (acc.balance >= amount) {
                acc.balance -= amount;
                printf("\nWithdrawal successful! New balance: $%.2f\n", acc.balance);
            } else {
                printf("\nInsufficient balance! Your current balance is $%.2f\n", acc.balance);
            }
        }
        fwrite(&acc, sizeof(struct Account), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("accounts.dat");
    rename("temp.dat", "accounts.dat");

    if (!found) {
        printf("Account number not found!\n");
    }
}

void check_balance() {
    int acc_number;
    int found = 0;
    FILE *fp;

    printf("\n--- Check Balance ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc_number);

    fp = fopen("accounts.dat", "rb");
    if (fp == NULL) {
        printf("No accounts found!\n");
        return;
    }

    struct Account acc;
    while (fread(&acc, sizeof(struct Account), 1, fp)) {
        if (acc.acc_number == acc_number) {
            found = 1;
            printf("\nAccount Holder: %s\n", acc.name);
            printf("Current Balance: $%.2f\n", acc.balance);
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("Account number not found!\n");
    }
}
