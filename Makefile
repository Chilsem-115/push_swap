NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = inc
FT_PRINTF_DIR = lib/ft_printf
FT_PRINTF_INC = $(FT_PRINTF_DIR)
INC = -I$(INC_DIR) -I$(FT_PRINTF_INC)

SRCS = $(wildcard src/*.c) $(wildcard src/operations/*.c) $(wildcard src/extra/*.c)
FT_PRINTF_SRCS = $(wildcard $(FT_PRINTF_DIR)/*.c)

OBJS = $(SRCS:src/%.c=obj/%.o)
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:$(FT_PRINTF_DIR)/%.c=obj/ft_printf/%.o)
OBJ = $(OBJS) $(FT_PRINTF_OBJS)

FT_PRINTF_LIB = $(FT_PRINTF_DIR)/ft_printf.a

all: $(NAME)

$(NAME): $(FT_PRINTF_LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(FT_PRINTF_LIB)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

obj/ft_printf/%.o: lib/ft_printf/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf obj
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
