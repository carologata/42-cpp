CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98 

NAME	=	reference

SRCS	=	src/main.cpp
OBJ		=	./obj
OBJS	=	$(addprefix $(OBJ)/, $(notdir $(SRCS:.cpp=.o)))

all: $(OBJ) $(NAME)

$(NAME): $(OBJS)
	@echo [$(NAME) executable created successfully.]
	@$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: src/%.cpp
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