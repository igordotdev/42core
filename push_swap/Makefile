CC = cc
CFLAGS = -g -Wall -Wextra -Werror
SRCS = src/push_swap.c src/actions.c src/utils.c src/input.c src/sort_utils.c src/small_sorts.c src/sort.c
EXEC = push_swap
SUBDIRS = lib/libft lib/ft_printf
LIBS = lib/libft/libft.a lib/ft_printf/libftprintf.a
OBJDIR = obj
OBJS = $(SRCS:src/%.c=obj/%.o)
INCLUDE = includes

all: $(EXEC)


$(EXEC): $(OBJS)
	@echo "$(BLUE)Building libraries...$(NC)"
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir bonus; \
	done
	@echo "$(GREEN)Linking executable...$(NC)"
	$(CC) $^ $(LIBS) -o $@
	@echo "$(YELLOW)Cleaning up libraries...$(NC)"
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	@echo "$(BLUE)Compiling $<...$(NC)"
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJDIR):
	mkdir -p $@

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)Removing executable...$(NC)"
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir fclean; \
	done
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re

# COLORS
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
NC = \033[0m # No Color