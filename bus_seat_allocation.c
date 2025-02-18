#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
#define MAX_SEATS 40 
#define MAX_PASSENGERS 100 
 
typedef struct { 
    char name[50]; 
    int age; 
    char contact[15]; 
    int seatNumber; 
} Passenger; 
 
typedef struct { 
    int busNumber; 
    char route[100]; 
    char departureTime[10]; 
    int totalSeats; 
    int availableSeats; 
    Passenger passengers[MAX_SEATS]; 
} Bus; 
 
Bus bus; 
 
void addBusDetails() { 
    printf("Enter Bus Number: "); 
    scanf("%d", &bus.busNumber); 
    getchar(); 
    printf("Enter Route: "); 
    fgets(bus.route, sizeof(bus.route), stdin); 
    bus.route[strcspn(bus.route, "\n")] = 0; 
    printf("Enter Departure Time: "); 
    scanf("%s", bus.departureTime); 
    printf("Enter Total Number of Seats: "); 
    scanf("%d", &bus.totalSeats); 
    bus.availableSeats = bus.totalSeats; 
    printf("Bus details added successfully!\n"); 
} 
 
void allocateSeat() { 
    if (bus.availableSeats == 0) { 
        printf("No seats available!\n"); 
        return; 
    } 
    int seatIndex = bus.totalSeats - bus.availableSeats; 
    printf("Enter Passenger Name: "); 
    getchar(); 
    fgets(bus.passengers[seatIndex].name, sizeof(bus.passengers[seatIndex].name), stdin); 
    bus.passengers[seatIndex].name[strcspn(bus.passengers[seatIndex].name, "\n")] = 0; 
    printf("Enter Age: "); 
    scanf("%d", &bus.passengers[seatIndex].age); 
    printf("Enter Contact Number: "); 
    scanf("%s", bus.passengers[seatIndex].contact); 
    bus.passengers[seatIndex].seatNumber = seatIndex + 1; 
    bus.availableSeats--; 
    printf("Seat allocated! Seat Number: %d\n", bus.passengers[seatIndex].seatNumber); 
} 
 
void displayAllocatedSeats() { 
    if (bus.availableSeats == bus.totalSeats) { 
        printf("No seats allocated yet!\n"); 
        return; 
    } 
    printf("Allocated Seats:\n"); 
    for (int i = 0; i < bus.totalSeats - bus.availableSeats; i++) { 
        printf("Seat %d: %s, Age: %d, Contact: %s\n",  
               bus.passengers[i].seatNumber,  
               bus.passengers[i].name,  
               bus.passengers[i].age,  
               bus.passengers[i].contact); 
    } 
} 
 
void cancelSeat() { 
    int seatNum; 
    printf("Enter seat number to cancel: "); 
    scanf("%d", &seatNum); 
    if (seatNum < 1 || seatNum > (bus.totalSeats - bus.availableSeats)) { 
        printf("Invalid seat number!\n"); 
        return; 
    } 
    for (int i = seatNum - 1; i < bus.totalSeats - bus.availableSeats - 1; i++) { 
        bus.passengers[i] = bus.passengers[i + 1]; 
        bus.passengers[i].seatNumber = i + 1; 
    } 
    bus.availableSeats++; 
    printf("Seat %d canceled successfully!\n", seatNum); 
} 
 
int main() { 
    int choice; 
    do { 
        printf("\nBus Seat Allocation System\n"); 
        printf("1. Add Bus Details\n"); 
        printf("2. Allocate Seat\n"); 
        printf("3. Display Allocated Seats\n"); 
        printf("4. Cancel Seat\n"); 
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: addBusDetails(); break; 
            case 2: allocateSeat(); break; 
            case 3: displayAllocatedSeats(); break; 
            case 4: cancelSeat(); break; 
            case 5: printf("Exiting...\n"); break; 
            default: printf("Invalid choice! Try again.\n"); 
        } 
    } while (choice != 5); 
 
    return 0; 
}
