CC = $(CROSS_COMPILE)gcc

CFLAGS = -g -Wall -O0

SRC = writer.c
TARGET = writer
OBJS = $(SRC:.c=.o)

$(TARGET): $(OBJS)
		$(CC) $(CFLAGS) -o $@ $<

clean:
		-rm -f *.o $(TARGET) *.elf *.map