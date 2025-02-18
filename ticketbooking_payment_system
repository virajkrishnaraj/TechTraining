#include <stdio.h> 
#include <string.h> 
#define MAX_PASSENGERS 50 
 
typedef struct { 
    char name[50]; 
    int age; 
    char contact[15]; 
    char travelDate[15]; 
    char busType[20]; 
    float price; 
} Ticket; 
 
typedef struct { 
    char method[20]; 
    float amount; 
    char transactionID[20]; 
} Payment; 
 
Ticket tickets[MAX_PASSENGERS]; 
int ticketCount = 0; 
 
float calculatePrice(char *busType, char *travelDate) { 
    float basePrice = 500.0; 
    if (strcmp(busType, "AC") == 0) basePrice += 200; 
    return basePrice; 
} 
 
void bookTicket() { 
    if (ticketCount >= MAX_PASSENGERS) { 
        printf("No more tickets available!\n"); 
        return; 
    } 
     
    Ticket t; 
    printf("Enter Passenger Name: "); 
    scanf(" %[^"]s", t.name); 
    printf("Enter Age: "); 
    scanf("%d", &t.age); 
    printf("Enter Contact Number: "); 
    scanf("%s", t.contact); 
    printf("Enter Travel Date: "); 
    scanf("%s", t.travelDate); 
    printf("Enter Bus Type (AC/Non-AC): "); 
    scanf("%s", t.busType); 
     
    t.price = calculatePrice(t.busType, t.travelDate); 
    tickets[ticketCount++] = t; 
    printf("Ticket booked! Price: %.2f\n", t.price); 
} 
 
void processPayment() { 
    Payment p; 
    printf("Enter Payment Method (Card/UPI/Cash): "); 
    scanf("%s", p.method); 
    printf("Enter Transaction ID: "); 
    scanf("%s", p.transactionID); 
    p.amount = tickets[ticketCount - 1].price; 
     
    printf("Payment Successful! Amount Paid: %.2f\n", p.amount); 
} 
 
void cancelTicket() { 
    if (ticketCount == 0) { 
        printf("No tickets to cancel!\n"); 
        return; 
    } 
     
    printf("Ticket cancelled for %s, refund issued.\n", tickets[ticketCount - 1].name); 
    ticketCount--; 
} 
 
void displayTickets() { 
    if (ticketCount == 0) { 
        printf("No tickets booked yet!\n"); 
        return; 
    } 
     
    for (int i = 0; i < ticketCount; i++) { 
        printf("Ticket %d: %s, Age: %d, Contact: %s, Travel Date: %s, Bus Type: %s, Price: 
%.2f\n",  
               i + 1, tickets[i].name, tickets[i].age, tickets[i].contact, tickets[i].travelDate, 
tickets[i].busType, tickets[i].price); 
    } 
} 
 
int main() { 
    int choice; 
     
    do { 
        printf("\n1. Book Ticket\n2. Process Payment\n3. Cancel Ticket\n4. Display Tickets\n5. 
Exit\nEnter choice: "); 
        scanf("%d", &choice); 
         
        switch (choice) { 
            case 1: 
                bookTicket(); 
                break; 
            case 2: 
                processPayment(); 
                break; 
            case 3: 
                cancelTicket(); 
                break; 
            case 4: 
                displayTickets(); 
                break; 
            case 5: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice!\n"); 
        } 
    } while (choice != 5); 
     
    return 0; 
}
