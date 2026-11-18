#include "train.h"

int main(void)
{
    TRAIN *head = NULL;
    int choice;

    head = load_trains();

    while (1)
    {
        printf("\n------ MENU 1 ------\n");
        printf("1. Sign Up\n");
        printf("2. Sign In\n");
        printf("3. Exit\n");
        printf("Enter choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                signup();
                break;

            case 2:
                if (signin())
                {
                    printf("\nLogin Successful!\n");
                    menu2(&head);
                }
                break;

            case 3:
                save_train(head);
                printf("Thank you!\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}