NASM = nasm
NFLAGS = -felf64
SRCS = $(wildcard libasm/*.S)
OBJS = $(SRCS:.S=.o)
CC = gcc
MAIN = my_libasm

.PHONY = all clean fclean re

all: $(MAIN)

$(MAIN): $(OBJS)
	$(CC) -o $@ $^ main.c

%.o : %.S
	$(NASM) $(NFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(MAIN)

re: fclean all