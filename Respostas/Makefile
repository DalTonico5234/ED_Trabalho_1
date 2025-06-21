all: 

compile:
	gcc *.c -c -Wall -Wextra -Werror
	gcc *.o -o main

clean:
	rm *.o

run0:
	./main ../Casos/test0/

run1:
	./main ../Casos/test1/

run2:
	./main ../Casos/test2/

run3:
	./main ../Casos/test3/

debug_run0:
	valgrind --leak-check=full -s ./main ../Casos/test0/ >saida.txt

debug_run1:
	valgrind --leak-check=full -s ./main ../Casos/test1/ >saida.txt

debug_run2:
	valgrind --leak-check=full -s ./main ../Casos/test2/ >saida.txt

debug_run3:
	valgrind --leak-check=full -s ./main ../Casos/test3/ >saida.txt

diff0:
	diff ../Casos/test0/saida.txt saida.txt

diff1:
	diff ../Casos/test1/saida.txt saida.txt

diff2:
	diff ../Casos/test2/saida.txt saida.txt

diff3:
	diff ../Casos/test3/saida.txt saida.txt

test0: compile clean debug_run0

test1: compile clean debug_run1

test2: compile clean debug_run2

test3: compile clean debug_run3

full0: test0 diff0

full1: test1 diff1

full2: test2 diff2

full3: test3 diff3

full: full0 full1 full2 full3
	
	
