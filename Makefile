NAME = push_swap
NAME2 = checker
FLAG = -Werror -Wall -Wextra
DIR = srcs/
LIB = libft/
LIB_FT = ./libft/libft.a
INCLUDES = -I includes/ -I libft/ -I.

SRC = add_struct.c \
add_struct_b.c \
check.c \
check_sort.c \
full_stec_a.c \
init_struct.c \
max_min_list.c \
newnew.c \
newnew1.c \
poradoc.c \
print.c \
rabota.c \
sdvig.c \
sdvig2.c \
sdvig3.c \
sort_list_a2.c \
sort_my.c \
check_max_min.c \
print_screen.c

SRC1 = push_swap.c

SRC2 = checker.c \
treatment_str.c \

OBJS = $(SRCS:.c=.o)
SRCS = $(addprefix $(DIR), $(SRC))

OBJS1 = $(SRCS1:.c=.o)
SRCS1 = $(addprefix $(DIR), $(SRC1))

OBJS2 = $(SRCS2:.c=.o)
SRCS2 = $(addprefix $(DIR), $(SRC2))

all: obhee $(NAME) $(NAME2)

obhee : my_lib $(OBJS)

$(NAME):  $(OBJS1) $(OBJS)
	gcc -g $(FLAG) -o $@ $(OBJS1) $(OBJS) -L./libft -lft	

$(NAME2): $(OBJS2) $(OBJS)
	gcc -g $(FLAG) -o $@ $(OBJS2) $(OBJS) -L./libft -lft

my_lib:
	@make -C $(LIB)

%.o: %.c ./includes/push.h
	gcc -g $(FLAG) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS2)
	@rm -f $(OBJS1)
	@make clean -C $(LIB)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@rm -f $(LIB_FT)

re: fclean all

.PHONY: fclean re all clean my_lib obhee