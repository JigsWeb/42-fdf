NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJSDIR = ./objects
OBJS = $(addprefix $(OBJSDIR)/,ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o ft_strlen.o ft_strdup.o ft_memchr.o ft_memcmp.o ft_strcpy.o ft_strncpy.o ft_strcat.o ft_strncat.o ft_strchr.o ft_strrchr.o ft_strcmp.o ft_strncmp.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_tolower.o ft_toupper.o ft_atoi.o ft_strstr.o ft_strnstr.o ft_strclr.o ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o ft_strtrim.o ft_strsplit.o ft_putchar.o ft_putstr.o ft_putendl.o ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_itoa.o ft_strlcat.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_str_is_numeric.o ft_str_is_alpha.o ft_islower.o ft_isupper.o ft_str_is_lowercase.o ft_itoa_base.o get_next_line.o)
LDFLAGS = -I .

all: $(NAME)
	
clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f libft.a

re: fclean all

$(OBJS): | $(OBJSDIR)

$(OBJSDIR):
	mkdir $(OBJSDIR)

$(OBJSDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(LDFLAGS)

$(NAME): $(OBJS)
	ar rcs $(NAME) $^