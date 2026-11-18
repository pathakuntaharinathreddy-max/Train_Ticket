#ifndef TRAIN_H
#define TRAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LOGIN_FILE "usr_logins"
#define TRAIN_FILE "trains_info"
#define PASS_FILE  "passengers_info"

#define MAX_NAME 50
#define MAX_PASS 50
#define MAX_PASSENGERS 100

typedef struct train
{
    int train_number;
    char train_name[50];
    char source[50];
    char destination[50];
    int total_seats;
    int available_seats;
    struct train *next;
} TRAIN;

typedef struct passenger
{
    int train_number;
    char journey_date[15];
    int seat_number;
    char name[50];
    int age;
    char gender[10];
    struct passenger *next;
} PASSENGER;

typedef struct seats
{
    int total_seats;
    int waiting_list;
    int current_booking_seat_number;
} SEATS;

/* Login functions */
void signup(void);
int signin(void);
int valid_password(char *);

/* Train functions */
TRAIN *load_trains(void);
void display_trains(TRAIN *);
void add_train(TRAIN **);

/* Booking functions */
void reserve_ticket(TRAIN *);
void cancel_ticket(void);
void booking_details(void);

/* File functions */
void save_train(TRAIN *);
void sync_train(TRAIN *);
void save_passenger(PASSENGER *);
PASSENGER *load_passengers(void);

/* Menu */
void menu2(TRAIN **);

#endif