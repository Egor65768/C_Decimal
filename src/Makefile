CC = gcc 
FLAGS = -Wextra -Werror -Wall
DECIMAL = *.c 
OBJECTS = *.o 
TEST_LIB = ./tests/*.c
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
LINK_FLAGS = -lcheck 
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux) 
	LINK_FLAGS += -lm -lsubunit
endif

all: clean s21_decimal.a test gcov_report

s21_decimal.a:
	$(CC) $(FLAGS) -c $(DECIMAL)
	ar rcs s21_decimal.a $(OBJECTS)

test: clean
	$(CC) $(FLAGS) $(LEAKS) $(DECIMAL) ${TEST_LIB} ${LINK_FLAGS} -o test
	./test

leaks: test
ifeq ($(UNAME_S), Linux) 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test
endif
ifeq ($(UNAME_S), Darwin) 
	leaks -quiet -atExit -- ./test
endif

clean: 
	rm -fr *.o *.a *.gch *.gcno *.gcda gcov_test s21_test.info ./report ./test

rebuild: clean test 

gcov_report: 
	$(CC) $(FLAGS) $(GCOV_FLAGS) ${TEST_LIB} ${DECIMAL} ${LINK_FLAGS} -o test
	./test
	lcov -t "stest" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open report/index.html	

style:
	clang-format -style=google -n tests/* ./*.c ./*.h

format:
	clang-format -style=google -i tests/* ./*.c ./*.h
