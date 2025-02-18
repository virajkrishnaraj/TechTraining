#include <stdio.h> 
#include <string.h> 
#include <math.h> 
#include <time.h> 
#define MAX_BUSES 10 
 
typedef struct { 
    char busNumber[10]; 
    double latitude; 
    double longitude; 
    time_t timestamp; 
} BusLocation; 
 
BusLocation buses[MAX_BUSES]; 
int busCount = 0; 
 
double calculateETA(double lat1, double lon1, double lat2, double lon2) { 
    double distance = sqrt(pow(lat2 - lat1, 2) + pow(lon2 - lon1, 2)); 
    double speed = 50.0; // Average speed in km/h 
    return (distance / speed) * 60; // Return ETA in minutes 
} 
 
void updateBusLocation() { 
    if (busCount >= MAX_BUSES) { 
        printf("Max buses reached!\n"); 
        return; 
    } 
     
    BusLocation b; 
    printf("Enter Bus Number: "); 
    scanf("%s", b.busNumber); 
    printf("Enter Latitude: "); 
    scanf("%lf", &b.latitude); 
    printf("Enter Longitude: "); 
    scanf("%lf", &b.longitude); 
    b.timestamp = time(NULL); 
     
    buses[busCount++] = b; 
    printf("Bus location updated successfully!\n"); 
} 
 
void displayBusLocations() { 
    if (busCount == 0) { 
        printf("No bus locations available!\n"); 
        return; 
    } 
     
    for (int i = 0; i < busCount; i++) { 
        printf("Bus %s - Latitude: %.6f, Longitude: %.6f, Last Update: %s",  
               buses[i].busNumber, buses[i].latitude, buses[i].longitude, 
ctime(&buses[i].timestamp)); 
    } 
} 
 
void estimateArrivalTime() { 
    if (busCount == 0) { 
        printf("No buses available for tracking!\n"); 
        return; 
    } 
     
    char busNum[10]; 
    double destLat, destLon; 
    printf("Enter Bus Number: "); 
    scanf("%s", busNum); 
    printf("Enter Destination Latitude: "); 
    scanf("%lf", &destLat); 
    printf("Enter Destination Longitude: "); 
    scanf("%lf", &destLon); 
     
    for (int i = 0; i < busCount; i++) { 
        if (strcmp(buses[i].busNumber, busNum) == 0) { 
            double eta = calculateETA(buses[i].latitude, buses[i].longitude, destLat, destLon); 
            printf("Estimated Arrival Time for Bus %s: %.2f minutes\n", busNum, eta); 
            return; 
        } 
    } 
     
    printf("Bus not found!\n"); 
} 
 
int main() { 
    int choice; 
     
    do { 
        printf("\n1. Update Bus Location\n2. Display Bus Locations\n3. Estimate Arrival 
Time\n4. Exit\nEnter choice: "); 
        scanf("%d", &choice); 
         
        switch (choice) { 
            case 1: 
                updateBusLocation(); 
                break; 
            case 2: 
                displayBusLocations(); 
                break; 
            case 3: 
                estimateArrivalTime(); 
                break; 
            case 4: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice!\n"); 
        } 
    } while (choice != 4); 
     
    return 0; 
}
