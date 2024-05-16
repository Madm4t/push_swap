NAME	= push_swap

LIBFT		= ./lib/libft/libft.a
LIBFT_DIR	= ./lib/libft/

SRC_COMMANDS = ./src/commands/
SRC_PUSH_SWAP = ./src/push_swap/

SRC	=	$(SRC_COMMANDS)push.c \
		$(SRC_COMMANDS)reverse_rotate.c \
		$(SRC_COMMANDS)rotate.c \
		$(SRC_COMMANDS)swap.c \
		$(SRC_PUSH_SWAP)big_sort_utils.c \
		$(SRC_PUSH_SWAP)big_sort.c \
		$(SRC_PUSH_SWAP)error.c \
		$(SRC_PUSH_SWAP)init_stack.c \
		$(SRC_PUSH_SWAP)is_sorted.c \
		$(SRC_PUSH_SWAP)push_swap.c \
		$(SRC_PUSH_SWAP)small_sort.c \
		$(SRC_PUSH_SWAP)smallest_num.c \
		$(SRC_PUSH_SWAP)stack_utils.c

OBJ	= $(SRC:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
DFLAGS	= -g

all : $(LIBFT) $(NAME)

$(NAME) : $(OBJ) push_swap.h
	 $(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT)
	@printf "push_swap ready. \n"

$(LIBFT) :
	 $(MAKE) -C $(LIBFT_DIR)
	 $(MAKE) bonus -C $(LIBFT_DIR)

%.o : %.c
	 $(CC) $(CFLAGS) -c $< -o $@

clean :
	 $(MAKE) clean -C $(LIBFT_DIR)
	 rm -rf $(OBJ)
	@ printf "object files removed.\n"

fclean : clean
	 $(MAKE) fclean -C $(LIBFT_DIR)
	 rm -rf $(NAME)
	 rm -rf deb
	@printf "client removed.\n"

re	: fclean
	$(MAKE) all

deb : CFLAGS += $(DFLAGS)
deb : $(OBJ) push_swap.h
	$(MAKE) all
	$(CC) $(CFLAGS) -o deb $(OBJ) $(LIBFT)
	@printf "debug version ready.\n"

.PHONY: all clean fclean re deb