#include "train.h"

int signin(void)
{
    FILE *fp;
    char username[50], password[50];
    char u[50], p[50];
    int attempts, found;

    fp = fopen(LOGIN_FILE, "r");

    if (fp == NULL)
    {
        printf("No accounts available. Please sign up.\n");
        return 0;
    }

    for (attempts = 0; attempts < 3; attempts++)
    {
        printf("Enter username\n");
        scanf("%49s", username);

        printf("Enter password\n");
        scanf("%49s", password);

        rewind(fp);
        found = 0;

        while (fscanf(fp, "%49s %49s", u, p) == 2)
        {
            if (strcmp(username, u) == 0 &&
                strcmp(password, p) == 0)
            {
                found = 1;
                break;
            }
        }

        if (found)
        {
            fclose(fp);
            return 1;
        }

        printf("Invalid login! Try again.\n");
    }

    printf("Maximum attempts reached.\n");
    printf("Please wait 5 minutes before trying again.\n");

    fclose(fp);
    return 0;
}