#include "train.h"

void cancel_ticket(void)
{
    FILE *fp, *temp;
    PASSENGER p;
    int train_no, seat, found = 0;
    char date[15];

    printf("Train number\n");
    scanf("%d", &train_no);

    printf("Journey date\n");
    scanf("%14s", date);

    printf("Seat number to cancel\n");
    scanf("%d", &seat);

    fp = fopen(PASS_FILE, "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL)
    {
        printf("File error.\n");

        if (fp)
            fclose(fp);

        if (temp)
            fclose(temp);

        return;
    }

    while (fscanf(fp, "%d %14s %d %49s %d %9s", &p.train_number,p.journey_date,
            &p.seat_number,p.name,&p.age,p.gender) == 6)
    {
        if (p.train_number == train_no &&strcmp(p.journey_date, date) == 0 &&
            p.seat_number == seat)
        {
            found = 1;
            printf("Ticket cancelled for %s\n", p.name);
            continue;
        }

        fprintf(temp, "%d %s %d %s %d %s\n",p.train_number,p.journey_date,
                p.seat_number,p.name,p.age,p.gender);
    }

    fclose(fp);
    fclose(temp);

    remove(PASS_FILE);
    rename("temp.txt", PASS_FILE);

    if (!found)
        printf("Ticket not found.\n");
    else
        printf("Cancellation successful.\n");
}