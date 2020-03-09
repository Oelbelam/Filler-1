/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:01:34 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/08/07 13:23:50 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"
# define MABS(x) ((x < 0) ? -x : x)

typedef	struct		s_ldata
{
	unsigned long	m:63;
	unsigned int	num:1;
	unsigned int	exp:15;
	unsigned int	signe:1;
}					t_ldata;

union				u_ldata
{
	long double lf;
	t_ldata		ldata;
};

typedef struct		s_flags
{
	int flg_p;
	int flg_n;
	int flg_sp;
	int flg_0;
	int flag;
	int	wd;
	int pr;
	int	dot;
	int hsh;
}					t_flags;

typedef struct		s_ro
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*to_del;
	int		r;
	int		temp;
	int		i;
}					t_ro;

typedef struct		s_flag
{
	int fzero;
	int fp;
	int fm;
	int fh;
	int fhh;
	int fl;
	int fll;
	int fsp;
	int fw;
	int fpr;
	int fdiez;
}					t_flag;

typedef	struct		s_var
{
	char	*tt;
	int		isn;
	int		len;
	int		nz;
	int		nsc1;
	int		nsc2;
	int		is0;
}					t_var;

typedef struct		s_flags_struct
{
	char	flag[11];
	void	(*flg_ft[11])(const char *frm, int *i, va_list ap, int *ret);
}					t_flags_struct;

char				*atoi_base(unsigned long long nbr, int base);
int					ft_putstr_s(const char *s, int pr);
t_flags				init_flags(void);
void				m_chk_f(t_flags flg, char *res, int *ret, int signe);
int					check_zeros(char *str);
int					len_point(char *res);
int					p_m_chk_f(t_flags *flg, int signe);
void				ft_nan_inf(char *res, int *ret, t_flags flags);
char				*dbl_num_sub(long double lf, int *signe);
char				*dbl_num(long double lf, int *signe);
void				f_chk(t_flags flg, int *ret, char *res, int signe);
void				plus_inf(t_flags flags, int *ret);
void				neg_inf(t_flags flags, int *ret);
void				ft_nan(t_flags flags, int *ret);
void				f_conv(const char *frm, int *i, va_list ap, int *ret);
void				get_final_man(char *man1, char *man2);
char				*ft_manipulate_str(char *man2, int exp);
char				*ft_new_frac(char *fract, int i);
char				*ft_manipulate_lexp(int res_bias, int *point);
char				*man_man_exp_sign(t_ldata ldata, int *point);
char				*ft_bzero_0(char *s, size_t n);
void				ft_swap(char *s1, char *s2);
char				*ft_sub_add(char *s1, char *s2, size_t size);
char				*ft_add_str(char *s1, char *s2);
void				ft_strrev(char *s);
void				ft_add_0(char *s, size_t size);
void				ft_sub_mult(char *s1, char *s2, char *res, int len1);
char				*ft_ten_mult(char *s1);
char				*ft_mult_str(char *s1, char *s2, int flag);
char				*ft_pow_str(int pow, char *num);
int					check_h_l_f(const char *frm, int *i);
t_flags				chck_flags_f(const char *frm, int *i);
void				wdth_prc_f(const char *frm, int *i, t_flags *flags);
char				*ft_delet_zeros(char *str);
char				*strnew_point(char *str, size_t size, int point);
void				manipulat_dot(t_flags flg, char *res,
					int *ret_temp, int *ret);
void				manipulat_flgn(t_flags flg, int signe, char *res, int *ret);
void				manipulat_flg0(t_flags flg, int si, char *res, int *ret);
int					print_float(char *res, int prec, int dot, int hsh);
char				*ro(char *str, int pr, int dot);
size_t				lens(char *str);
int					ft_strlen_dot(char *str);
char				*asp(char *str, size_t size, int point);
void				init_ro(t_ro *ro);
char				*ron1(t_ro *ro);
char				*pg_5(t_ro *ro, int pr);
char				*pp_5(t_ro *ro, int pr, char *str);
char				*e_5_c_2(t_ro *ro, int pr);
char				*e_5_c(t_ro *ro, int pr, char *str);
char				*e_5(t_ro *ro, int pr, char *str);
int					ft_putstr_p(char *str);
void				p_format(t_flags flg, unsigned long p, int *ret);
void				p_conv(const char *frm, int *i, va_list ap, int *ret);
void				u_conv(const char *frm, int *i, va_list ap, int *ret);
int					ft_nbln_u(unsigned long long u, t_flags flg);
int					post_flag_u(unsigned long long u, t_flags flg);
void				m_chk_u(t_flags flg, unsigned long long u, int *ret);
int					ft_printf(const char *format, ...);
void				det_flag(const char *format, int *i, va_list ap, int *ret);
void				c_conv(const char *frm, int *i, va_list ap, int *ret);
void				s_conv(const char *frm, int *i, va_list ap, int *ret);
int					print_spaces(int width);
int					print_zero(int width);
void				perc_conv(const char *frm, int *i, va_list ap, int *ret);
void				s_conv(const char *frm, int *i, va_list ap, int *ret);
void				init_var(t_var *v);
void				o_conv(const char *frm, int *i, va_list ap, int *ret);
void				o_conv_s1(t_flag *p, unsigned long long d, int *ret);
void				o_conv_2_m(t_flag *p, t_var *v);
void				o_conv_2_m2(t_flag *p, t_var *v);
void				o_conv_1(t_flag *p, t_var *v);
void				o_conv_0(t_flag *p, t_var *v, int *ret);
unsigned long long	assign_o(t_flag *p, va_list ap);
void				x_c_conv(const char *frm, int *i, va_list ap, int *ret);
unsigned long long	assign_x_c(t_flag *p, va_list ap);
unsigned long long	ft_pow_x_c(int nb, unsigned long long pow);
char				*ft_itoa_base_x_c(unsigned long long value, int base);
void				x_c_conv_0(t_flag *p, t_var *v, int *ret);
void				x_c_conv_1(t_flag *p, t_var *v);
void				x_c_conv_2_m2(t_flag *p, t_var *v);
void				x_c_conv_2_m(t_flag *p, t_var *v);
void				x_c_conv_s1(t_flag *p, unsigned long long d, int *ret);
void				x_conv(const char *frm, int *i, va_list ap, int *ret);
unsigned long long	assign_x(t_flag *p, va_list ap);
void				x_conv_0(t_flag *p, t_var *v, int *ret);
void				x_conv_1(t_flag *p, t_var *v);
void				x_conv_2_m2(t_flag *p, t_var *v);
void				x_conv_2_m(t_flag *p, t_var *v);
void				x_conv_s1(t_flag *p, unsigned long long d, int *ret);
void				d_conv(const char *frm, int *i, va_list ap, int *ret);
long long int		assign_d(t_flag *p, va_list ap);
int					ft_nbrlen(long long int nbr);
int					isnegative(long long int n);
int					getlen_w_o_p(long long int nn, long long int n);
char				*ft_itoa_w_o_p(long long int n, t_var *v);
void				checkpm(t_flag *p, t_var *v);
int					checkpmr(t_flag *p, t_var *v);
void				d_conv_s1_m(t_flag *p, t_var *v);
void				d_conv_s1_p(t_flag *p, t_var *v);
void				d_conv_s1(t_flag *p, long long int d, int *ret);
void				d_conv_s2(t_flag *p, t_var *v);
void				flag_h_hh(const char *frm, int i, t_flag *p);
void				flag_l_ll(const char *frm, int i, t_flag *p);
void				flag_z(const char *frm, int i, t_flag *p);
void				flag_m(const char *frm, int i, t_flag *p);
void				flag_p(const char *frm, int i, t_flag *p);
void				flag_space(const char *frm, int i, t_flag *p);
void				flag_diez(const char *frm, int i, t_flag *p);
void				flag_w_p(const char *frm, int i, t_flag *p);
void				stock_flag(const char *frm, int j, t_flag *p);

#endif
