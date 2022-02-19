CC := gcc
CFLAGS := -O -Wall -Werror -std=c99 -D_DEFAULT_SOURCE -ggdb

all: render

render: render.o
	$(CC) -o render $^ -lm

%.o: %.c
	$(CC) -c $< $(CFLAGS)

run: render
	./render > output.pmb

clean:
	rm -f render *.o *~

.PHONY: all clean submission
