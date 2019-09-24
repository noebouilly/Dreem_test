CC=gcc
CFLAGS=-Wall
LDFLAGS=-pthread

SOURCES=$(wildcard *.c )
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=dreem_test
FILES=egg_sensor_acquisition.bin

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

clean:
	rm $(EXECUTABLE) $(OBJECTS) $(FILES)