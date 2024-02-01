/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:54:06 by avialle-          #+#    #+#             */
/*   Updated: 2024/01/29 17:13:02 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

/*--------------------- LIBFT ---------------------*/
// FT_PRINTF
int		ft_printf(const char *str, ...);
void	ft_print_char(int c, size_t *len);
void	ft_print_str(char *str, size_t *len);
void	ft_print_ptr(unsigned long long addr, size_t *len);
void	ft_print_nbr(int nb, size_t *len);
void	ft_print_hexa(unsigned int nb, char *base, size_t *len);
void	ft_print_unsigned(unsigned int nb, size_t *len);
// FT_UTILS
int	ft_strlen(char *str);
void	ft_putstr_fd(char *str, int fd);
int		ft_isdigit(int c);
int		ft_atoi(char *str);

#endif