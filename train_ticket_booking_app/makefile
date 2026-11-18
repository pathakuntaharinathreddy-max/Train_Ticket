
CC = gcc
CFLAGS = -Wall -Wextra

OBJ = main.o signup.o signin.o train.o file.o booking.o cancel.o booking_details.o menu2.o

myirctc: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o myirctc

%.o: %.c train.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o myirctc
