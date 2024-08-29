CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -g3 -std=c++98 -I include/

NAME	=	diamondTrap

SRCS	=	src/ClapTrap.cpp src/ScavTrap.cpp src/FragTrap.cpp src/DiamondTrap.cpp src/main.cpp
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