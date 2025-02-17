#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define TAX_RATE 0.10 // 10% tax
#define TIP_RATE 0.15 // 15% tip


char orderItems[MAX_ITEMS][20];  
float orderPrices[MAX_ITEMS];   
int orderQuantities[MAX_ITEMS]; 
int itemCount = 0;              


void displayMenu();
void addItem();
void displayBill();
float calculateSubtotal();
float calculateTax(float subtotal);
float calculateTip(float subtotal);
float calculateTotal(float subtotal, float tax, float tip);

int main() {
    int choice;

    printf("Welcome to the Restaurant Billing System!\n");

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayBill();
                break;
            case 3:
                printf("Thank you for dining with us! Have a great day!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add Item to Order\n");
    printf("2. View Bill\n");
    printf("3. Exit\n");
}


void addItem() {
    int choice, quantity;
    if (itemCount >= MAX_ITEMS) {
        printf("Order list is full! Cannot add more items.\n");
        return;
    }

    printf("\nAvailable Menu Items:\n");
    printf("1. Burger - $10\n");
    printf("2. Fries - $5\n");
    printf("3. Drink - $3\n");
    printf("Select the item to add (1-3): ");
    scanf("%d", &choice);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    switch (choice) {
        case 1:
            strcpy(orderItems[itemCount], "Burger");
            orderPrices[itemCount] = 10;
            break;
        case 2:
            strcpy(orderItems[itemCount], "Fries");
            orderPrices[itemCount] = 5;
            break;
        case 3:
            strcpy(orderItems[itemCount], "Drink");
            orderPrices[itemCount] = 3;
            break;
        default:
            printf("Invalid item choice!\n");
            return;
    }

    orderQuantities[itemCount] = quantity;
    itemCount++;
    printf("Item added to order!\n");
}

void displayBill() {
    int i;
    float subtotal, tax, tip, total;

    if (itemCount == 0) {
        printf("\nYour order is empty!\n");
        return;
    }

    printf("\nOrder Details:\n");
    for (i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f x %d = $%.2f\n", 
               i + 1, 
               orderItems[i], 
               orderPrices[i], 
               orderQuantities[i], 
               orderPrices[i] * orderQuantities[i]);
    }

    subtotal = calculateSubtotal();
    tax = calculateTax(subtotal);
    tip = calculateTip(subtotal);
    total = calculateTotal(subtotal, tax, tip);

    printf("\nSubtotal: $%.2f\n", subtotal);
    printf("Tax (10%%): $%.2f\n", tax);
    printf("Tip (15%%): $%.2f\n", tip);
    printf("Total Bill: $%.2f\n", total);
}


float calculateSubtotal() {
    int i;
    float subtotal = 0;

    for (i = 0; i < itemCount; i++) {
        subtotal += orderPrices[i] * orderQuantities[i];
    }

    return subtotal;
}


float calculateTax(float subtotal) {
    return subtotal * TAX_RATE;
}


float calculateTip(float subtotal) {
    return subtotal * TIP_RATE;
}

float calculateTotal(float subtotal, float tax, float tip) {
    return subtotal + tax + tip;
}
