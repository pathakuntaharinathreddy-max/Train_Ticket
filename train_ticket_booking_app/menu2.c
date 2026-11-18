#include "train.h"

void menu2(TRAIN **head)
{
    char choice;

    while (1)
    {
        printf("\n------ MENU 2 ------\n");
        printf("T/t : Display trains\n");
        printf("R/r : Reserve ticket\n");
        printf("C/c : Cancel ticket\n");
        printf("B/b : Booking details\n");
        printf("A/a : Add train (Admin)\n");
        printf("Q/q : Quit\n");
        printf("Enter choice: ");

        scanf(" %c", &choice);

        switch (choice)
        {
            case 'T':
            case 't':
                display_trains(*head);
                break;

            case 'R':
            case 'r':
                reserve_ticket(*head);
                break;

            case 'C':
            case 'c':
                cancel_ticket();
                break;

            case 'B':
            case 'b':
                booking_details();
                break;

            case 'A':
            case 'a':
                add_train(head);
                break;

            case 'Q':
            case 'q':
                save_train(*head);
                return;

            default:
                printf("Invalid option!\n");
        }
    }
}