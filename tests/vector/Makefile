NAME		:=	vector_test.out
VEC_DIR		:=	../../vector/

CC			:=	g++
CFLAGS		:=	-Wall -Wextra -pedantic -I$(VEC_DIR)
OBJDIR		:=	obj/


HPPS		:=	PascalTest.hpp\
				$(VEC_DIR)Vector.hpp

OBJS		:=	$(addprefix $(OBJDIR),\
				VectorTestCases.o\
				GEN_main.o)

GENERATED	:=	GEN_VectorChecks.tpp\
				GEN_main.cpp

$(NAME): $(OBJS) $(OBJS:$(OBJDIR)%.o: %.cpp) $(HPPS)
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
