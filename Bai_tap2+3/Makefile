CC = gcc
CFLAGS = -Wall -g
TARGET = spws

SRCS = main.c sensor.c actuators.c buttons.c watering_logic.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

