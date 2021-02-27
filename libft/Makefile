NAME = libft.a
SRC = srcs
FAIL = ft_putchar ft_putstr ft_putnbr ft_strlen ft_memset ft_bzero ft_memcpy \
	   ft_memccpy ft_memmove ft_memchr ft_memcmp ft_strdup ft_strcpy \
	   ft_strncpy ft_strcat ft_strncat ft_strlcat ft_strchr ft_strrchr \
	   ft_strstr ft_strnstr ft_strncmp ft_strcmp ft_atoi  ft_isalpha \
	   ft_isdigit ft_isalnum  ft_isascii ft_isprint ft_toupper ft_tolower \
	   ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr ft_striter \
	   ft_striteri ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub \
	   ft_strjoin ft_strtrim ft_strsplit ft_slova ft_itoa ft_putendl \
	   ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_lstnew \
	   ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap get_next_line \
	   ft_lstadd_next my_printf trait ft_cheloedouble analysis forma_chesla \
	   int_number data_types1 data_types2 data_types3 check_types zapolne_f \
	   write_f okrug okrug_3s new_drob print_probel characters_int \
	   analysis_flag ft_putstr_check ft_sizenbr ft_llitoa ft_llsizenbr \
	   ft_itoa_base ft_putchar_check ft_putstr_n_check ft_putnbr_check
	    
OBJECT = $(addsuffix .o, $(FAIL))
SRCS = $(addsuffix .c, $(FAIL))
FL = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJECT)
	ar rc $@ $^
	ranlib $@ 	

%.o: %.c libft.h ft_printf.h
	gcc $(FL) -c $< -o $@

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: fclean re norme all clean
