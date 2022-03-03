NAME		:=	vector_test.out
INCLUDE		:=	../../include/

CC			:=	g++
CFLAGS		:=	-Wall -Wextra -pedantic -I$(INCLUDE)
OBJDIR		:=	obj/


HPPS		:=	PascalTest.hpp\
				$(INCLUDE)Vector.hpp

OBJS		:=	$(addprefix $(OBJDIR),\
				VectorTestCases.o\
				GEN_main.o)

GENERATED	:=	GEN_VectorChecks.tpp\
				GEN_main.cpp

$(NAME): $(OBJS) $(OBJS:$(OBJDIR)%.o: %.cpp) $(HPPS) $(GENERATED)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)%.o: %.cpp $(HPPS) | generate
	$(CC) $(CFLAGS) -c $< -o $@

generate:
	python3 gen_vector_checks.py
	python3 gen_main_cases.py

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJS)
	rm -f $(GENERATED)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
