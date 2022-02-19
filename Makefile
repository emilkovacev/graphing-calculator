CC := gcc
CFLAGS := -O -Wall -Werror -std=c99 -D_DEFAULT_SOURCE

all: render

render: render.o
	$(CC) -o render $^

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f rldecode *.o *~ rldecode.tar $(TESTS)

.PHONY: all clean submission
