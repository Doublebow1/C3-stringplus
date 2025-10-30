CC = gcc
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra -std=c11
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
TEST_LIBS = -lcheck -lm -lpthread -lrt -lsubunit

SRC = s21_string.c s21_sprintf.c s21_sscanf.c

OBJ = $(SRC:.c=.o)
TEST_SRC = s21_string_test.c

LIB_NAME = s21_string.a
TEST_EXEC = s21_string_test

.PHONY: all clean test gcov_report

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	$(AR) $(LIB_NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(LIB_NAME)
	$(CC) $(CFLAGS) $(TEST_SRC) $(LIB_NAME) -o $(TEST_EXEC) $(TEST_LIBS)
	./$(TEST_EXEC)

gcov_report:
	
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(SRC) $(TEST_SRC) -o $(TEST_EXEC) $(TEST_LIBS)
	
	./$(TEST_EXEC)
	
	lcov -t "$(TEST_EXEC)" -o $(TEST_EXEC).info -c -d .
	genhtml -o coverage_report $(TEST_EXEC).info
	
	open ./coverage_report/index.html

clean:
	rm -f $(OBJ) $(TEST_EXEC) $(LIB_NAME)
	rm -f *.gcda *.gcno *.info
	rm -rf coverage_report