NAME	:=	exec.out
CC		:=	g++
CFLAGS	:=	-pedantic -Wall -Wextra

INCLUDE	:=	../../include/
OBJDIR	:=	obj/

SRC		:=	main.cpp
OBJ		:=	$(addprefix $(OBJDIR), $(SRC:%.cpp=%.o))
HPP		:=	$(addprefix $(INCLUDE), utils/BST.hpp)

all: $(NAME)

$(NAME): $(OBJ) $(SRC) $(HPP)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)%.o: %.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
