/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:51:09 by okim              #+#    #+#             */
/*   Updated: 2021/03/26 09:08:30 by okim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <wchar.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef	struct	s_format_inf
{
	int	zero;
	int	minus;
	int	number;
	int	space;
	int	plus;
	int	width;
	int	precision;
	int	rtn; // 꼭 필요한가?
	char	length_char;
	char	specifier;
}				t_format;


int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *b, int c, size_t len);
int		ft_isdigit(int c);
int		print_saved(char *format, int len);
int		new_structs(t_format *structs);
int		format_parser(char **format, t_format *structs, va_list *arg);
int		print_format(t_format *structs, va_list *arg);
int		print_n(char c, int len);
int 	int_print(t_format *structs, va_list *arg);
int		str_print(t_format *structs, va_list *arg);
int		etc_print(t_format *structs, va_list *arg);
int		base_len(long long nmb, int base);
long long int	signed_length_chk(t_format *structs, va_list *arg);
long long int	unsigned_length_chk(t_format *structs, va_list *arg);
int		conv_z(long long nmb, char**z);
int		conv_hex_H(long long nmb, char **hex);
int		conv_hex_h(long long nmb, char **hex);
int		conv_oct(long long nmb, char **oct);

#endif