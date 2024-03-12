CC = gcc
CFLAGS = -O1 -g -Wall


OBJS := tree.o tree.o

all: tree

tree: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ -lm

%.o: %.c
	$(CC) -o $@ $(CFLAGS) -c -MMD -MF .$@.d $<

clean:
	rm -f $(OBJS)
	rm -f *.dSYM
	rm -f tree
	rm -f .*.o.d