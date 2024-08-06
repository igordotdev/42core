CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lm -lX11 -lXext
SRCS = src/main.c src/render.c src/utils.c src/inputs.c
EXEC = fractol
SUBDIRS = minilibx-linux
LIBS = minilibx-linux/libmlx.a
OBJDIR = obj
OBJS = $(SRCS:src/%.c=obj/%.o)
INCLUDE = includes

all: $(EXEC)


$(EXEC): $(OBJS)
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done
	$(CC) $^ $(LDFLAGS) $(LIBS) -o $@

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