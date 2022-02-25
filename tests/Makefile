TESTER_HPP	:=	PascalTest.hpp
OBJDIR		:=	obj
CC			:=	g++
CFLAGS		:=	-Wall -Wextra -pedantic

# VECTOR FILES
VECTOR		:=	vector_test
VEC_GEN		:=	GeneratedVectorChecks.tpp
VEC_OBJ		:=	$(addprefix $(OBJDIR)/,\
				VectorTestCases.o)

# STACK FILES


# MAP FILES

$(VECTOR): $(VEC_OBJ)
	$(CC) $(CFLAGS) $(VEC_OBJ) -o $(VECTOR)

$(OBJDIR)/%.o: %.cpp $(VEC_GEN) $(TESTER_HPP)
	$(CC) $(CFLAGS) -c $< -o $@

$(VEC_GEN): VectorTest.hpp
	python3 gen_scripts/gen_vector_checks.py > $(VEC_GEN)

$(VEC_OBJ): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)
