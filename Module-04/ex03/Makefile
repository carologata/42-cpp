CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98 -g3 -I include/

NAME	=	materia

SRCS	=	src/AMateria.cpp src/Cure.cpp src/Ice.cpp src/MateriaSource.cpp src/Character.cpp src/main.cpp
OBJ		=	./obj
OBJS	=	$(addprefix $(OBJ)/, $(notdir $(SRCS:.cpp=.o)))
INC		=	$(wildcard include/*.hpp)

all: $(OBJ) $(NAME)

$(NAME): $(OBJS)
	@echo [$(NAME) executable created successfully.]
	@$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: src/%.cpp $(INC)
	@echo [Compiling]$(notdir $(<))...
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ):
	@mkdir -p $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re

DEFAULT_GOAL: all