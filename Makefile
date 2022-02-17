NAME	=	containers
CC		=	g++
FILES	=	main
OBJ 	=	$(FILES:%=obj/%.o)
SRC		=	$(FILES:%=%.cpp)
CFLAGS	=	-I . -std=c++98 -pedantic -Wall -Wextra# -Werror

all: $(NAME)

stack: main_stack.cpp obj/main_stack.o Stack.hpp
	$(CC) $(CFLAGS) Stack.hpp obj/main_stack.o

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

obj/%.o: %.cpp Vector.hpp iterator_traits.hpp reverse_iterator.hpp
	@mkdir -p obj/
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj/

fclean: clean
	rm -f $(NAME)

re: fclean all
