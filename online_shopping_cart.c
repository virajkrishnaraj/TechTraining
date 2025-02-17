#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

char cartItems[MAX_ITEMS][20]; 
float cartPrices[MAX_ITEMS];    
int cartQuantities[MAX_ITEMS];  
int itemCount = 0;              


void displayMenu();
void addItem();
void removeItem();
void updateItem();
void displayCart();
float calculateTotal();

int main() {
    int choice;

    printf("Welcome to the Online Shopping Cart System!\n");

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                displayCart();
                break;
            case 5:
                printf("Checkout completed. Thank you for shopping!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add Item to Cart\n");
    printf("2. Remove Item from Cart\n");
    printf("3. Update Item Quantity\n");
    printf("4. View Cart\n");
    printf("5. Checkout and Exit\n");
}


void addItem() {
    int choice, quantity;
    if (itemCount >= MAX_ITEMS) {
        printf("Cart is full! Cannot add more items.\n");
        return;
    }

    printf("\nAvailable Products:\n");
    printf("1. Shirt - $15\n");
    printf("2. Pants - $20\n");
    printf("3. Shoes - $30\n");
    printf("Select the product to add (1-3): ");
    scanf("%d", &choice);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    switch (choice) {
        case 1:
            strcpy(cartItems[itemCount], "Shirt");
            cartPrices[itemCount] = 15;
            break;
        case 2:
            strcpy(cartItems[itemCount], "Pants");
            cartPrices[itemCount] = 20;
            break;
        case 3:
            strcpy(cartItems[itemCount], "Shoes");
            cartPrices[itemCount] = 30;
            break;
        default:
            printf("Invalid product choice!\n");
            return;
    }

    cartQuantities[itemCount] = quantity;
    itemCount++;
    printf("Item added to cart!\n");
}

void removeItem() {
    int index, i;
    displayCart();

    if (itemCount == 0) return;

    printf("Enter the item number to remove: ");
    scanf("%d", &index);

    if (index < 1 || index > itemCount) {
        printf("Invalid item number!\n");
        return;
    }

    for (i = index - 1; i < itemCount - 1; i++) {
        strcpy(cartItems[i], cartItems[i + 1]);
        cartPrices[i] = cartPrices[i + 1];
        cartQuantities[i] = cartQuantities[i + 1];
    }

    itemCount--;
    printf("Item removed from cart!\n");
}


void updateItem() {
    int index, quantity;
    displayCart();

    if (itemCount == 0) return;

    printf("Enter the item number to update: ");
    scanf("%d", &index);

    if (index < 1 || index > itemCount) {
        printf("Invalid item number!\n");
        return;
    }

    printf("Enter the new quantity: ");
    scanf("%d", &quantity);

    cartQuantities[index - 1] = quantity;
    printf("Item quantity updated!\n");
}


void displayCart() {
    int i;
    float total;

    if (itemCount == 0) {
        printf("\nYour cart is empty!\n");
        return;
    }

    printf("\nCart Contents:\n");
    for (i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f x %d\n", i + 1, cartItems[i], cartPrices[i], cartQuantities[i]);
    }

    total = calculateTotal();
    printf("Total Cost: $%.2f\n", total);
}

float calculateTotal() {
    int i;
    float total = 0;

    for (i = 0; i < itemCount; i++) {
        total += cartPrices[i] * cartQuantities[i];
    }

    return total;
}
