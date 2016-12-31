CC              =   gcc
CFLAGS          =   -g
RM              =   rm -f

default: all 

all: write_pipe read_pipe

write_pipe: write_pipe.c
	$(CC) $(CFLAGS) -o write_pipe write_pipe.c

read_pipe: read_pipe.c
	$(CC) $(CFLAGS) -o read_pipe read_pipe.c

clean veryclean:
	$(RM) write_pipe read_pipe
