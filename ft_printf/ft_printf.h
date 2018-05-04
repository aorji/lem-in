/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:37:33 by aorji             #+#    #+#             */
/*   Updated: 2018/01/25 18:37:50 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <inttypes.h>
# include <wchar.h>
# define CYAN "\x1b[0;36m"
# define RESET "\x1b[0m"

int g_i;

typedef	struct		s_prntf
{
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				j;
	int				z;
	int				pluse;
	int				space;
	int				sharp;
	int				width;
	int				minus;
	int				zero;
	int				precision;
	int				point;
	int				up;
	int				down;
}					t_prntf;

int					ft_printf(const char *format, ...);
char				*ft_itoa_base(uintmax_t value, unsigned int base);
char				*ft_itoa_base_up(uintmax_t value, unsigned int base);
int					ft_len(uintmax_t n, unsigned int b);
int					ft_digitsize_d(intmax_t n);
char				*ft_itoa_d(intmax_t n);
void				ft_putnstr(char *s, int n);
void				ft_x(t_prntf flags, va_list arg);
void				ft_x_up(t_prntf flags, va_list arg);
void				ft_di(t_prntf flags, va_list arg);
void				ft_d_up(t_prntf flags, va_list arg);
void				ft_o(t_prntf flags, va_list arg);
void				ft_u(t_prntf flags, va_list arg);
void				ft_c(t_prntf flags, va_list arg, char *buf);
void				ft_s(t_prntf flags, va_list arg, char *buf);
void				ft_o_up(t_prntf flags, va_list arg);
void				ft_c_up(t_prntf flags, va_list arg, char *buf);
void				ft_s_up(t_prntf flags, va_list arg, char *buf);
void				ft_u_up(t_prntf flags, va_list arg);
void				ft_proc(t_prntf flags);
void				ft_p(t_prntf flags, va_list arg);
void				ft_print(va_list arg, char *buf, t_prntf flags, char kod);
int					ft_sc(va_list arg, char *buf, t_prntf flags, char kod);
int					ft_check_minus(t_prntf flags);
void				ft_print_spaces(int minus, int len, char *s, char c);
void				ft_print_spaces_srting(int minus, int len, char c);
void				ft_print_width(int minus, int len, char c);
int					ft_count_bytes(wchar_t value);
int					ft_unilen(wchar_t *s);
int					ft_unicode(wchar_t value);
int					ft_unicode_s(wchar_t *value, int unilen);
int					ft_char_coincide(char c);
t_prntf				ft_fillflags(char *flags);
char				*ft_use_precision(int prec, char *s);
void				ft_zero_precision(int minus, char c);
void				ft_zero_precision_s(int minus, char c, char *buf);
void				ft_x(t_prntf flags, va_list arg);
char				*ft_pluse_space(char *s, t_prntf flags);
int					ft_check_printable(wchar_t *t, int len);
int					ft_len_with_precision(wchar_t *value, int unilen);
void				ft_zu(t_prntf flags, va_list arg);
void				ft_a(void);
void				ft_n(va_list arg);
int					ft_buf(const char **format, char **buf);
int					ft_check_midle(char *s);
int					ft_proc_position(const char *format);
char				*ft_full_input(t_prntf flags, char *s);
char				*ft_print_full(t_prntf flags, char *c, char *s);
int					ft_pos_kod(const char *s);
int					ft_not_flag(char c);
int					ft_add_buf(int a, int j, char **buf, const char **format);
int					ft_positon(int *a, int *j, const char **format);
int					ft_return(char **buf);
void				ft_b(t_prntf flags);
void				ft_ul_case(void **string, t_prntf flags);
#endif
