CC := gcc
CFLAGS := -O -Wall -Werror -std=c99 -D_DEFAULT_SOURCE

all: render

render: render.o
	$(CC) -o render $^ -lm

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f render *.o *~

.PHONY: all clean submission
