#include "train.h"

void booking_details(void)
{
    FILE *fp;
    PASSENGER p;
    int train_no, seat, found = 0;
    char date[15];

    printf("Train number: ");
    scanf("%d", &train_no);

    printf("Journey date: ");
    scanf("%14s", date);

    printf("Seat number to view: ");
    scanf("%d", &seat);

    fp = fopen(PASS_FILE, "r");

    if (fp == NULL)
    {
        printf("No bookings available.\n");
        return;
    }

    while (fscanf(fp, "%d %14s %d %49s %d %9s",&p.train_number,p.journey_date,
           &p.seat_number,p.name,&p.age,p.gender) == 6)
    {
        if (p.train_number == train_no &&strcmp(p.journey_date, date) == 0 &&
            p.seat_number == seat)
        {
            printf("\n--- Passenger Details ---\n");
            printf("Train Number : %d\n", p.train_number);
            printf("Journey Date : %s\n", p.journey_date);
            printf("Seat Number  : %d\n", p.seat_number);
            printf("Name         : %s\n", p.name);
            printf("Age          : %d\n", p.age);
            printf("Gender       : %s\n", p.gender);

            found = 1;
        }
    }

    if (!found)
        printf("Booking not found.\n");

    fclose(fp);
}