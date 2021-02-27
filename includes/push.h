#ifndef PUSH_H
# define PUSH_H
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"

typedef struct	s_sd
{
	int			element_one;
	int			element_two;
	int			sdveg_a_up1;
	int			sdveg_a_down1;
	int			sdveg_a_up2;
	int			sdveg_a_down2;
	int			sdveg;
	int			sdveg_b_up1;
	int			sdveg_b_down1;
	int			sdveg_b_up2;
	int			sdveg_b_down2;
}				t_sd;

typedef struct	s_swap
{
	t_list		*stec_a;
	t_list		*stec_b;
	t_list		*rez;
	t_list		*stec_my;
	int			len_a;
	int			len_b;
	int			kol;
	int			kol_operations;
	int			variant;
	int			otcuda;
	int			scolko;
	int			flag;
	int			flag2;
	int			cheslo;
}				t_swap;

void			poradoc_b(t_swap *swap);
void			init_struct(t_swap *swap);
void			init_sd(t_sd *sd);
int				len_stec(t_list *stec);
int				zap1(char *str, t_swap *swap);
int				check_double(t_swap *swap);
void			sort_my(t_swap *swap);
void			sort_list_a3(t_swap *swap, int *k, int *kk, int *kkk);
t_list			*sort_list_a(t_swap *swap);
int				add_struct_b(t_swap *swap);
void			full_stec_a(t_swap *swap);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
int				max_list(t_list *stec);
int				min_list(t_list *stec);
t_list			*sdvig_vnis(t_list *stec);
t_list			*sdvig_vverh(t_list *stec);
void			pa(t_list **stec_one, t_list **stec_two);
void			sa(t_list **stec, int len);
void			sdvig_a_down(int kol, t_swap *swap, t_list **stec, int k);
void			sdvig_a_up(int kol, t_swap *swap, t_list **stec, int k);
void			sdvig_pb(t_list **stec_one, t_list **stec_two, t_swap *swap, \
		int k);
void			sdvig_sa(t_swap *swap, int k);
void			sdvig_sb(t_list **stec, t_swap *swap);
void			sdvig_ab_up(int a, int b, t_swap *swap);
void			sdvig_ab_down(int a, int b, t_swap *swap);
void			sdvig_ab_down1(int a, int b, t_swap *swap);
t_list			*sort_list_a(t_swap *swap);
void			newnew(t_swap *swap, t_sd *sd);
void			newnew2(t_swap *swap, t_sd *sd);
int				newnew3(t_swap *swap, t_sd *sd);
void			newnew4(t_swap *swap, t_sd *sd);
void			rabota(t_swap *swap, t_sd sd);
void			poradoc_a(t_swap *swap);
void			print_struct(t_list *stec);
void			print_rez(t_swap swap);
int				treatment_str(char *line, t_swap *swap);
int				sort_true(t_list *stec);
int				check_max_min(char *str, int one, int two);
void			free_swap(t_swap *swap);
void			print_screen(t_swap *swap, int oper);
void			print_rez1(int k);
#endif
