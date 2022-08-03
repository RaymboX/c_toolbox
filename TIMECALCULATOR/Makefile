

all: record show

compile:
	gcc -g schooltime.c utilities.c

record:
	date >> record.txt
	./a.out >> record.txt

show:
	cat record.txt