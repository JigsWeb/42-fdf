NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJSDIR = objects
SRCDIR = src
INCLUDESDIR = includes
LIBFTDIR = libft
MINILIBXDIR = minilibx
OBJS = $(addprefix $(OBJSDIR)/,main.o creators.o matrice.o parser.o utils.o)
SRCS = $(addprefix $(SRCDIR)/,main.c creators.c matrice.c parser.c utils.c)
FRAMEWORKS = $(addprefix -framework ,OpenGL AppKit)
LDFLAGS = $(addprefix -I ,/usr/local/include $(INCLUDESDIR) $(MINILIBXDIR))
LIBS = -L $(LIBFTDIR) -lft -L /usr/local/lib -lmlx

all: $(NAME)
	
clean:
	rm -rf $(OBJSDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

$(OBJS): | $(OBJSDIR)

$(OBJSDIR):
	mkdir $(OBJSDIR)

$(OBJSDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $(CFLAGS) $(LDFLAGS) -o $@ $<

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) $(LDFLAGS) $(CFLAGS) $(OBJS) $(LIBS) $(FRAMEWORKS) -o $(NAME)