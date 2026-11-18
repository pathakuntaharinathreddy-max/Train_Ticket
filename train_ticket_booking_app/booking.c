#include "train.h"

void reserve_ticket(TRAIN *head)
{
    TRAIN *t;
    PASSENGER *p;
    int train_no, count, i;
    char date[15];

    printf("Enter train number\n");
    scanf("%d", &train_no);

    t = head;

    while (t != NULL && t->train_number != train_no)
        t = t->next;

    if (t == NULL)
    {
        printf("Train not found!\n");
        return;
    }

    printf("Enter journey date (DD-MM-YYYY)\n");
    scanf("%14s", date);

    /* For simple demonstration, date is collected here.Next-3-day validation can be added separately. */

    printf("Enter number of seats\n");
    scanf("%d", &count);

    if (count <= 0)
    {
        printf("Invalid number of seats.\n");
        return;
    }

    if (count > t->available_seats)
    {
        printf("Only %d seats available!\n", t->available_seats);
        count = t->available_seats;
        printf("Booking available seats only: %d\n", count);
    }

    for (i = 0; i < count; i++)
    {
        p = malloc(sizeof(PASSENGER));

        if (p == NULL)
        {
            printf("Memory allocation failed.\n");
            break;
        }

        p->train_number = train_no;
        strcpy(p->journey_date, date);

        printf("\nPassenger %d details\n", i + 1);

        printf("Name\n");
        scanf("%49s", p->name);

        printf("Age:\n");
        scanf("%d", &p->age);

        printf("Gender (Male/Female)\n");
        scanf("%9s", p->gender);

        /* Assign seat number */

        p->seat_number = t->total_seats - t->available_seats + 1;

        printf("Seat allocated: %d\n", p->seat_number);

        save_passenger(p);

        free(p);

        t->available_seats--;
    }

    sync_train(head);

    printf("\nBooking completed!\n");
}