#include "train.h"

void save_train(TRAIN *head)
{
    FILE *fp;

    fp = fopen(TRAIN_FILE, "w");

    if (fp == NULL)
        return;

    while (head != NULL)
    {
        fprintf(fp, "%d %s %s %s %d %d\n", head->train_number,head->train_name,head->source,
                head->destination,head->total_seats,head->available_seats);

        head = head->next;
    }

    fclose(fp);
}

/* Sync the linked-list data to the file */
void sync_train(TRAIN *head)
{
    save_train(head);
}

void save_passenger(PASSENGER *p)
{
    FILE *fp;

    fp = fopen(PASS_FILE, "a");

    if (fp == NULL)
        return;

    fprintf(fp, "%d %s %d %s %d %s\n",p->train_number,p->journey_date,
            p->seat_number,p->name,p->age,p->gender);

    fclose(fp);
}