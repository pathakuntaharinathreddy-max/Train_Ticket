#include "train.h"

int valid_password(char *ptr)
{
    int upper = 0, lower = 0, digit = 0, special = 0;

    if (strlen(ptr) < 8)
        return 0;

    while (*ptr)
    {
        if (isupper(*ptr))
            upper = 1;
        else if (islower(*ptr))
            lower = 1;
        else if (isdigit(*ptr))
            digit = 1;
        else
            special = 1;

        ptr++;
    }

    return upper && lower && digit && special;
}

void signup(void)
{
    FILE *fp;
    char username[50], password[50];
    char u[50], p[50];
    int found, attempts;

    fp = fopen(LOGIN_FILE, "a+");

    if (fp == NULL)
    {
        printf("File error\n");
        return;
    }

    for (;;)
    {
        printf("Enter username\n");
        scanf("%49s", username);

        rewind(fp);
        found = 0;

        while (fscanf(fp, "%49s %49s", u, p) == 2)
        {
            if (strcmp(username, u) == 0)
            {
                found = 1;
                break;
            }
        }

        if (!found)
            break;

        printf("Username already exists. Try another.\n");
    }

    attempts = 0;

    while (attempts < 5)
    {
        printf("Enter password\n");
        scanf("%49s", password);

        if (valid_password(password))
            break;

        printf("Invalid password!\n");
        printf("Password must contain uppercase, lowercase, digit, special character and 8 characters.\n");

        attempts++;
    }

    if (attempts == 5)
    {
        printf("TIME OUT! Please sign up again.\n");
        fclose(fp);
        return;
    }

    fprintf(fp, "%s %s\n", username, password);

    printf("Sign-up successful!\n");

    fclose(fp);
}