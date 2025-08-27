CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp replace.cpp
NAME = ex04

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

test:
	echo "123" > test1
	./ex04 test1 1 a
	echo "Hello world" > test2
	./ex04 test2 l ll
	echo "123456789" > test3
	./ex04 test3 2 a


clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
.PHONY: all clean fclean re
