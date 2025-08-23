CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Account.cpp tests.cpp 
NAME = banking 

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
.PHONY: all clean fclean re
