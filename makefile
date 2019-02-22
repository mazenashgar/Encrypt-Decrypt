Cipher: p2.o functions.o functions.h
	gcc p2.o functions.o -o Cipher

p2.o: functions.h functions.c p2.c
	gcc -c p2.c

functions.o: functions.h functions.c
	gcc -c functions.c

test: 
	./Cipher 1 textbook input.txt cipher.txt
	./Cipher 2 textbook cipher.txt output.txt
	diff -s input.txt output.txt

clean: 
	rm -f *.o Cipher	
