CFLAGS += -g -Wall -Wextra -MMD -fsanitize=address

LDFLAGS += -lm

PROGRAM = main

$(PROGRAM): main.o
	gcc $^ -o $@ $(CFLAGS) $(LDFLAGS)

clean:
	rm -f *.o *.d $(PROGRAM)

-include *.d
