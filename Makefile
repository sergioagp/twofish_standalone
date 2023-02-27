CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99 -Wno-type-limits
INCLUDES=-I.

SRCS=test.c twofish.c
OBJS=$(SRCS:.c=.o)

all: test.elf
	@echo "Done."

test.elf: $(OBJS)
	@echo "Linking object files to create test executable..."
	@$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Cleaning up..."
	rm -f test.elf $(OBJS)
	@echo "Done."