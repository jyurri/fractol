/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 07:55:28 by jyurrita          #+#    #+#             */
/*   Updated: 2022/10/13 10:18:31 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	"stdarg.h"
# include	"stdio.h"
# include	"unistd.h"
# include	"limits.h"

int		ft_printf(char const *text, ...);
int		print_arg(char c, va_list args);
int		print_char(int c);
int		print_string(char *s);
int		print_int(int n);
int		print_unsigned_int(int n);
int		print_hexa(unsigned int lnum);
int		print_hexa_mayus(unsigned int lnum);
int		print_pointer(void *p);
int		print_hexa_point(unsigned long long int lnum);
int		print_numb_digit(int num);

#endif