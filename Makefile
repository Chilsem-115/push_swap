NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = inc
FT_PRINTF_INC = lib/ft_printf
INC = -I$(INC_DIR) -I$(FT_PRINTF_INC)

# Gather source files from src/ and its subdirectories
SRCS = $(wildcard src/*.c) $(wildcard src/operations/*.c) $(wildcard src/extra/*.c)
FT_PRINTF_SRCS = $(wildcard lib/ft_printf/*.c)

# Create object files paths in the "obj" directory, preserving directory structure
OBJS = $(SRCS:src/%.c=obj/%.o)
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:lib/ft_printf/%.c=obj/ft_printf/%.o)
OBJ = $(OBJS) $(FT_PRINTF_OBJS)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Compile source files from src/ (and subdirectories)
obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Compile source files from lib/ft_printf/
obj/ft_printf/%.o: lib/ft_printf/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
