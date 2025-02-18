#include <stdio.h> 
#include <limits.h> 
#define MAX_STOPS 10 
 
typedef struct { 
    char source[50]; 
    char destination[50]; 
    char stops[MAX_STOPS][50]; 
    int distances[MAX_STOPS][MAX_STOPS]; 
    int numStops; 
} Route; 
 
void addRoute(Route *route) { 
    printf("Enter Source: "); 
    scanf(" %s", route->source); 
    printf("Enter Destination: "); 
    scanf(" %s", route->destination); 
    printf("Enter Number of Intermediate Stops: "); 
    scanf("%d", &route->numStops); 
     
    for (int i = 0; i < route->numStops; i++) { 
        printf("Enter Stop %d: ", i + 1); 
        scanf(" %s", route->stops[i]); 
    } 
     
    printf("Enter Distance Matrix:\n"); 
    for (int i = 0; i <= route->numStops; i++) { 
        for (int j = 0; j <= route->numStops; j++) { 
            scanf("%d", &route->distances[i][j]); 
        } 
    } 
    printf("Route added successfully!\n"); 
} 
 
void floydWarshall(int graph[MAX_STOPS][MAX_STOPS], int numStops) { 
    int dist[MAX_STOPS][MAX_STOPS]; 
     
    for (int i = 0; i < numStops; i++) { 
        for (int j = 0; j < numStops; j++) { 
            dist[i][j] = graph[i][j]; 
        } 
    } 
     
    for (int k = 0; k < numStops; k++) { 
        for (int i = 0; i < numStops; i++) { 
            for (int j = 0; j < numStops; j++) { 
                if (dist[i][k] + dist[k][j] < dist[i][j]) { 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
                } 
            } 
        } 
    } 
     
    printf("Optimized Distance Matrix:\n"); 
    for (int i = 0; i < numStops; i++) { 
        for (int j = 0; j < numStops; j++) { 
            printf("%d ", dist[i][j]); 
        } 
        printf("\n"); 
    } 
} 
 
void displayRoute(Route route) { 
    printf("Source: %s\n", route.source); 
    printf("Destination: %s\n", route.destination); 
    printf("Intermediate Stops: "); 
    for (int i = 0; i < route.numStops; i++) { 
        printf("%s ", route.stops[i]); 
    } 
    printf("\n"); 
    floydWarshall(route.distances, route.numStops + 1); 
} 
 
int main() { 
    Route route; 
    int choice; 
     
    while (1) { 
        printf("\nMenu:\n"); 
        printf("1. Add Route\n"); 
        printf("2. Display Route\n"); 
        printf("3. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
         
        switch(choice) { 
            case 1: 
                addRoute(&route); 
                break; 
            case 2: 
                displayRoute(route); 
                break; 
            case 3: 
                printf("Exiting...\n"); 
                return 0; 
            default: 
                printf("Invalid choice. Please try again.\n"); 
        } 
    } 
 
    return 0; 
}
