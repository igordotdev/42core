CC = cc # i hope clang is used
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = \
			ft_printf.c \
			./parse/ft_parse_handlers.c ./parse/ft_parse_helpers.c ./parse/ft_vdprintf.c \
			./utils/ft_bzero.c ./utils/ft_calloc.c ./utils/ft_freereturnint.c ./utils/ft_isdigit.c ./utils/ft_itoa_base.c ./utils/ft_itoa.c ./utils/ft_memcpy.c ./utils/ft_memset.c ./utils/ft_realloc.c ./utils/ft_strchr.c ./utils/ft_strdup.c ./utils/ft_strjoin.c ./utils/ft_strlen.c \
			./parse/subfunctions/subfunctions1.c ./parse/subfunctions/subfunctions2.c ./parse/subfunctions/subfunctions3.c ./parse/subfunctions/subfunctions4.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean:
	rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re