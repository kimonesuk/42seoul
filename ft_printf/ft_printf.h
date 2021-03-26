/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:51:09 by okim              #+#    #+#             */
/*   Updated: 2021/03/27 08:44:02 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <wchar.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_format_inf
{
	int				zero;
	int				minus;
	int				number;
	int				space;
	int				plus;
	int				width;
	int				precision;
	long long int	rtn;
	char			length_char;
	char			specifier;
}				t_format;

int					ft_printf(const char *format, ...);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
void				*ft_memset(void *b, int c, size_t len);
int					ft_isdigit(int c);
int					print_saved(char *format, int len);
int					new_structs(t_format *structs);
int					format_parser(char **format, t_format *str, va_list *arg);
int					print_format(t_format *structs, va_list *arg);
int					print_n(char c, int len);
int					int_print(t_format *structs, va_list *arg);
int					base_print(t_format *structs, va_list *arg);
int					str_print(t_format *structs, va_list *arg);
int					etc_print(t_format *structs, va_list *arg);
int					base_len(long long nmb, int base);
int					unsigned_base_len(unsigned long long nmb, int base);
long long int		signed_length_chk(t_format *structs, va_list *arg);
unsigned long long	unsigned_length_chk(t_format *structs, va_list *arg);
int					conv_z(long long nmb, char**z);
int					unsigned_conv_z(unsigned long long nmb, char **z);
int					conv_hex_H(unsigned long long nmb, char **hex);
int					conv_hex_h(unsigned long long nmb, char **hex);
int					conv_oct(unsigned long long nmb, char **oct);

#endif