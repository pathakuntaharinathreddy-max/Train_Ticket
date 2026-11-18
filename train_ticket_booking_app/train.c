#include "train.h"

TRAIN *load_trains(void)
{
    FILE *fp;
    TRAIN *head = NULL, *temp, *newnode;

    fp = fopen(TRAIN_FILE, "r");

    if (fp == NULL)
        return NULL;

    while (1)
    {
        newnode = malloc(sizeof(TRAIN));

        if (newnode == NULL)
            break;

        if (fscanf(fp, "%d %49s %49s %49s %d %d",&newnode->train_number,newnode->train_name,newnode->source, 
            newnode->destination,&newnode->total_seats,&newnode->available_seats) != 6)
        {
            free(newnode);
            break;
        }

        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }

    fclose(fp);
    return head;
}

void display_trains(TRAIN *head)
{
    printf("\n%-10s %-20s %-15s %-15s %-10s %-10s\n","Number", "Name", "Source", 
            "Destination","Total", "Available");

    while (head != NULL)
    {
        printf("%-10d %-20s %-15s %-15s %-10d %-10d\n",head->train_number,head->train_name,
                head->source,head->destination,head->total_seats,head->available_seats);

        head = head->next;
    }
}

void add_train(TRAIN **head)
{
    TRAIN *newnode, *temp;

    newnode = malloc(sizeof(TRAIN));

    if (newnode == NULL)
        return;

    printf("Train number: ");
    scanf("%d", &newnode->train_number);

    printf("Train name: ");
    scanf("%49s", newnode->train_name);

    printf("Source: ");
    scanf("%49s", newnode->source);

    printf("Destination: ");
    scanf("%49s", newnode->destination);

    printf("Total seats: ");
    scanf("%d", &newnode->total_seats);

    if (newnode->total_seats <= 0)
    {
        printf("Invalid seat count.\n");
        free(newnode);
        return;
    }

    newnode->available_seats = newnode->total_seats;
    newnode->next = NULL;

    /* Check duplicate train number and name */
    temp = *head;

    while (temp != NULL)
    {
        if (temp->train_number == newnode->train_number ||
            strcmp(temp->train_name, newnode->train_name) == 0)
        {
            printf("Duplicate train not allowed!\n");
            free(newnode);
            return;
        }

        temp = temp->next;
    }

    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        temp = *head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    save_train(*head);
    printf("Train added successfully.\n");
}