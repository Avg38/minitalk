/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:15:07 by avialle-          #+#    #+#             */
/*   Updated: 2024/02/02 14:15:07 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

/**ft_Printf**/
void	ft_print_char(int c, size_t *len);
void	ft_print_str(char *str, size_t *len);
void	ft_print_ptr(unsigned long long addr, size_t *len);
void	ft_print_nbr(int nb, size_t *len);
void	ft_print_hexa(unsigned int nb, char *base, size_t *len);
void	ft_print_unsigned(unsigned int nb, size_t *len);
int		ft_printf(const char *str, ...);
/**ft_Utils**/
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *nptr);
int		ft_strlen(char *str);
int		ft_isdigit(int c);
char	*ft_strjoin_char(char *str, unsigned long long *len, char c);

#endif
