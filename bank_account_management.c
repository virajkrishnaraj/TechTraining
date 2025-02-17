#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_TRANSACTIONS 100

float balance = 1000.0;
int transactionCount = 0;
char transactionType[MAX_TRANSACTIONS][15];
float transactionAmount[MAX_TRANSACTIONS];
char transactionDate[MAX_TRANSACTIONS][20];

void deposit();
void withdraw();
void checkBalance();
void viewHistory();
void recordTransaction(const char* type, float amount);

int main() {
    int choice;
    printf("Welcome to the Bank Account Management System!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Deposit Money\n");
        printf("2. Withdraw Money\n");
        printf("3. Check Balance\n");
        printf("4. View Transaction History\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deposit();
                break;
            case 2:
                withdraw();
                break;
            case 3:
                checkBalance();
                break;
            case 4:
                viewHistory();
                break;
            case 5:
                printf("Thank you for using the Bank Account Management System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void deposit() {
    float amount;
    printf("\nEnter the amount to deposit: $");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount! Please enter a positive value.\n");
        return;
    }

    balance += amount;
    recordTransaction("Deposit", amount);
    printf("Amount deposited successfully!\n");
}

void withdraw() {
    float amount;
    printf("\nEnter the amount to withdraw: $");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount! Please enter a positive value.\n");
        return;
    }

    if (amount > balance) {
        printf("Insufficient balance! Current balance: $%.2f\n", balance);
        return;
    }

    balance -= amount;
    recordTransaction("Withdrawal", amount);
    printf("Amount withdrawn successfully!\n");
}

void checkBalance() {
    printf("\nCurrent Account Balance: $%.2f\n", balance);
}

void viewHistory() {
    printf("\nTransaction History:\n");
    if (transactionCount == 0) {
        printf("No transactions yet.\n");
        return;
    }

    for (int i = 0; i < transactionCount; i++) {
        printf("%d. %s of $%.2f on %s\n", i + 1, 
               transactionType[i], 
               transactionAmount[i], 
               transactionDate[i]);
    }
}

void recordTransaction(const char* type, float amount) {
    if (transactionCount < MAX_TRANSACTIONS) {
        strcpy(transactionType[transactionCount], type);
        transactionAmount[transactionCount] = amount;
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        strftime(transactionDate[transactionCount], sizeof(transactionDate[transactionCount]), "%Y-%m-%d %H:%M:%S", t);

        transactionCount++;
    } else {
        printf("Transaction history is full!\n");
    }
}
