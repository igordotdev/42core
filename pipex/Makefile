CC = clang-12
CFLAGS = -Wall -Wextra -Werror
SRC = src/pipex.c
LIBFT = libft
LIBS = libft/libft.a
OBJDIR = obj
OBJ = $(SRC:src/%.c=obj/%.o)
INCLUDE = includes
EXEC = pipex

all: $(EXEC)

$(EXEC): $(OBJ)
	$(MAKE) -C $(LIBFT) bonus;
	$(CC) $^ $(LIBS) -o $@
	$(MAKE) -C $(LIBFT) clean;

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@


$(OBJDIR):
	mkdir -p $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re