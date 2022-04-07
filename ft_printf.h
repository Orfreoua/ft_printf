#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct  s_data
{
	va_list	list;
	int		count_write;
}  	t_data;

int		ft_printf(const char *str, ...);
int		find_index(char c, char *index_tab);
void	ft_putchar_printf(t_data *data, char c);
void	ft_putstr_printf(t_data *data, char *s);
void	ft_putnbr_printf(t_data *data, int n);
void	ft_putnbr_unsigned_printf(t_data *data, unsigned int n);
void	ft_putnbr_base_printf(t_data *data, long int nbr, char *base);
void		ft_putnbr_unsigned_base_printf(t_data *data, unsigned long nbr, char *base);
# endif