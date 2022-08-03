
LOG_IN= "LOG_IN: "
LOG_OUT="LOG_OUT: "
PAUSE="PAUSE: "

all:
	

in:
	printf $(LOG_IN) >> logtime.txt
	date >> logtime.txt

out:
	printf $(LOG_OUT) >> logtime.txt
	date >> logtime.txt

42:
	printf $(PAUSE) >> logtime.txt
	date -v +42M  >> logtime.txt 

cancel:
	sed '$(shell grep -c ':' logtime.txt)d' logtime.txt > temp.txt
	rm -f logtime.txt
	mv temp.txt logtime.txt

show:
	cat logtime.txt


