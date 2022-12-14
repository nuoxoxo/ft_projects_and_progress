/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _                                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ____/__/__ __:__:__ by nuo               #+#    #+#             */
/*   Updated: ____/__/__ __:__:__ by nuo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "stdlib.h"
# include "unistd.h"

//		Check:	cspdiuxX %

int		ft_printf(const char *a, ...);
int		fmt(va_list aa, const char a);

int		route_str(char *a);			// route s
int		route_chr(int a);			// route c

int		route_dec(int a);			// route id
int		count_dec(int a);
char	*stos(char *a);
char	*itoa(int a);

int		route_uin(unsigned int a);		// route u
int		count_uin(unsigned int a);
char	*uitoa(unsigned int a);

int		route_hex(unsigned int aa, char *a);	// route xX
int		count_hex(unsigned int a);
void	print_hex(unsigned int aa, char *a);

int		route_ptr(uintptr_t a);			// route p
int		count_ptr(uintptr_t a);
void	print_ptr(uintptr_t a);

int		len(char *a);

#endif
