CC = cc
CFLAGS = -Wall -Wextra -Werror -Wpedantic -W -Wconversion -Wshadow \
	-Wpointer-arith -Wcast-align -Wcast-qual
LDFLAGS = -lm
SRC = main.c

.DEFAULT_GOAL = acorn

acorn:
	$(CC) $(CFLAGS) $(SRC) -o $(@) $(LDFLAGS)

clean:
	rm -f acorn

.PHONY: clean
