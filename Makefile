NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJSDIR = objects
SRCDIR = src
INCLUDESDIR = includes
LIBFTDIR = libft
MINILIBXDIR = minilibx
CREATORSDIR = creators
MATRIXESDIR = matrixes
OBJS = $(addprefix $(OBJSDIR)/,main.o parser.o utils.o drawer.o v2p.o $(CREATORSDIR)/camr.o $(CREATORSDIR)/vctr.o $(CREATORSDIR)/mat.o $(CREATORSDIR)/img.o $(CREATORSDIR)/params.o $(MATRIXESDIR)/rotate.o $(MATRIXESDIR)/scale.o $(MATRIXESDIR)/translate.o)
SRCS = $(addprefix $(SRCDIR)/,main.c parser.c utils.c drawer.c v2p.c $(CREATORSDIR)/camr.c $(CREATORSDIR)/vctr.c $(CREATORSDIR)/mat.c $(CREATORSDIR)/img.c $(CREATORSDIR)/params.c $(MATRIXESDIR)/rotate.c $(MATRIXESDIR)/scale.c $(MATRIXESDIR)/translate.c)
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
	mkdir $(OBJSDIR)/$(CREATORSDIR)
	mkdir $(OBJSDIR)/$(MATRIXESDIR)

$(OBJSDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $(CFLAGS) $(LDFLAGS) -o $@ $<

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) $(LDFLAGS) $(CFLAGS) $(OBJS) $(LIBS) $(FRAMEWORKS) -o $(NAME)