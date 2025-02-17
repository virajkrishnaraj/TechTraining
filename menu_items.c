#include <stdio.h>

int main() {
    int choice, quantity;
    float subtotal = 0, tax, total, payment;
    char confirm;
    int orderPlaced = 0;

    printf("Welcome to the Restaurant!\n");
    printf("Menu:\n");
    printf("1. Pizza - $15\n");
    printf("2. Burger - $10\n");
    printf("3. Fries - $5\n");
    printf("4. Drink - $3\n");
    printf("5. Finish Order\n");

   
    while (1) {
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 5) {
            break;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        
        switch (choice) {
            case 1:
                subtotal += 15 * quantity;
                break;
            case 2:
                subtotal += 10 * quantity;
                break;
            case 3:
                subtotal += 5 * quantity;
                break;
            case 4:
                subtotal += 3 * quantity;
                break;
            default:
                printf("Invalid choice. Please select a valid menu item.\n");
        }
    }

 
    tax = subtotal * 0.1;  
    total = subtotal + tax;

    printf("\nOrder Summary:\n");
    printf("Subtotal: $%.2f\n", subtotal);
    printf("Tax (10%%): $%.2f\n", tax);
    printf("Total: $%.2f\n", total);

  
    printf("\nDo you want to confirm the order? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        printf("Enter payment amount: $");
        scanf("%f", &payment);

        if (payment >= total) {
            printf("Payment successful! Change: $%.2f\n", payment - total);
            orderPlaced = 1;
        } else {
            printf("Insufficient payment. Order not placed.\n");
        }
    } else {
        printf("Order canceled.\n");
    }

    
    if (orderPlaced) {
        printf("Order Status: Paid\n");
    } else {
        printf("Order Status: Not Paid\n");
    }

    printf("Thank you for visiting!\n");
    return 0;
}
