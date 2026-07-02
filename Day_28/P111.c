#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SEATS 20
#define TICKET_PRICE 150


struct Passenger {
    int seatNumber;
    char name[50];
    int age;
    int isBooked; 
};


struct Passenger seats[TOTAL_SEATS];


void initializeSystem();
void displaySeats();
void bookTicket();
void cancelTicket();
void viewBill();

int main() {
    int choice;
    initializeSystem();

    while(1) {
        printf("\n=================================");
        printf("\n    TICKET BOOKING SYSTEM        ");
        printf("\n=================================");
        printf("\n 1. View Seating Layout");
        printf("\n 2. Book a Ticket");
        printf("\n 3. Cancel a Ticket");
        printf("\n 4. Generate Billing Report");
        printf("\n 5. Exit");
        printf("\n=================================");
        printf("\nEnter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        switch(choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                viewBill();
                break;
            case 5:
                printf("\nThank you for using the Ticket Booking System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}


void initializeSystem() {
    for (int i = 0; i < TOTAL_SEATS; i++) {
        seats[i].seatNumber = i + 1;
        seats[i].isBooked = 0;
        strcpy(seats[i].name, "");
        seats[i].age = 0;
    }
}


void displaySeats() {
    printf("\n--- CURRENT SEATING LAYOUT ---\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i].isBooked == 0) {
            printf("[ Seat %02d : AVAILABLE ]   ", seats[i].seatNumber);
        } else {
            printf("[ Seat %02d : BOOKED    ]   ", seats[i].seatNumber);
        }
        
        if ((i + 1) % 2 == 0) {
            printf("\n");
        }
    }
}


void bookTicket() {
    int seatNum;
    displaySeats();
    
    printf("\nEnter preferred seat number (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNum);

    
    if (seatNum < 1 || seatNum > TOTAL_SEATS) {
        printf("\nError: Seat number does not exist!\n");
        return;
    }

    
    if (seats[seatNum - 1].isBooked == 1) {
        printf("\nError: Seat %d is already occupied!\n", seatNum);
        return;
    }

    
    seats[seatNum - 1].seatNumber = seatNum;
    printf("Enter Passenger Name: ");
    scanf(" %[^\n]s", seats[seatNum - 1].name); 
    printf("Enter Passenger Age: ");
    scanf("%d", &seats[seatNum - 1].age);
    
    seats[seatNum - 1].isBooked = 1;
    printf("\nSuccess! Ticket for Seat %d booked successfully.\n", seatNum);
}

 
void cancelTicket() {
    int seatNum;
    printf("\nEnter seat number to cancel booking: ");
    scanf("%d", &seatNum);

    if (seatNum < 1 || seatNum > TOTAL_SEATS) {
        printf("\nError: Invalid seat number!\n");
        return;
    }

    if (seats[seatNum - 1].isBooked == 0) {
        printf("\nError: This seat is not currently booked.\n");
        return;
    }

    
    seats[seatNum - 1].isBooked = 0;
    strcpy(seats[seatNum - 1].name, "");
    seats[seatNum - 1].age = 0;
    
    printf("\nSuccess! Booking for Seat %d has been canceled.\n", seatNum);
}


void viewBill() {
    int count = 0;
    printf("\n=================================");
    printf("\n         BILLING REPORT          ");
    printf("\n=================================");
    printf("\nSeat\tPassenger Name\tAge\tPrice");
    printf("\n---------------------------------");
    
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i].isBooked == 1) {
            printf("\n%d\t%s\t\t%d\t$%d", seats[i].seatNumber, seats[i].name, seats[i].age, TICKET_PRICE);
            count++;
        }
    }
    
    printf("\n---------------------------------");
    printf("\nTotal Tickets Booked : %d", count);
    printf("\nTotal Revenue Earned : $%d\n", count * TICKET_PRICE);
    printf("=================================\n");
}
