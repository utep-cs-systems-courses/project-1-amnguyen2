all: tokenizer

history.o: history.h
tokenizer.o: tokenizer.h history.h

tokenizer: history.o tokenizer.o
	gcc history.c tokenizer.c -o lab1

clean:
	rm lab1 *.o
