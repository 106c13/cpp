CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
NAME = ex02

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
