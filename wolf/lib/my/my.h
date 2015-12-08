/*
** libmy.h for libmy in /home/alies_a/rendu/Piscine_C_J07/lib
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Oct  6 13:13:21 2015 Arnaud Alies
** Last update Fri Dec  4 14:25:01 2015 Arnaud Alies
*/

#ifndef MY_H_
# define MY_H_

# define BASE "0123456789abcdefghijklmnopqrstuvwxyz"
# define BASE_U "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

#include <stdarg.h>

typedef int(*disp)(va_list*);

int	my_putchar(char c);
int	my_put_nbr(long long nb);
int	my_putstr(const char *str);
int	my_strlen(const char *str);
int	my_str_to_nbr(const char *str);
char	*my_nbr_to_str(int nb);
char	*my_strcpy(char *dest, const char *src);
char	*my_revstr(char *str);

int	my_strcmp(char *s1, char *s2);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
void    my_remove_dup(char *str, char c);

char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);

int	my_char_count(char *str, char c);
int	my_char_append(char *str, char c);
int	my_array_append(char **array, char *str);
int	my_array_size(int size, char **array);
int	my_array_len(char **array);
int	my_show_wordtab(char **tab);
char	**my_str_split(char *str, char d);
char	**my_str_to_wordtab(char *str);
char	*my_strdup(const char *src);
int	my_strfind(char *str, char *to_find);
char    *my_char_push(char **str, char c);
void    my_char_remove(char *str, int pos);
char	*my_char_add(char **s, char c);
char    *my_getbase(int nb, int base);
char    *my_getbase_offset(int nb, int base, int offset);
char    *my_getunsigned(unsigned long nb, int base, int upper);

int     my_printf(const char *str, ...);

int     show_pointer(va_list *ap);
int     show_unsigned(va_list *ap);
int     show_printable(va_list *ap);
int     show_hex(va_list *ap);
int     show_oct(va_list *ap);
int     show_bin(va_list *ap);
int     show_str(va_list *ap);
int     show_int(va_list *ap);
int     show_char(va_list *ap);
int     show_hex_up(va_list *ap);

int     is_printable(char c);

#endif
