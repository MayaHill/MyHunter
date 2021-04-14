/*
** EPITECH PROJECT, 2020
** B-PSU-100-MPL-1-1-myprintf-maya.hill
** File description:
** my_printf_basicflags.c
*/

#include <stdarg.h>
#include "../../include/my.h"
#include "../../include/my_printf.h"
#include <stdlib.h>

void print_char(va_list ap, format_t format)
{
    char c = va_arg(ap, int);

    format.nb--;
    format_spaces(&format);
    my_putchar(c);
    format_minus(&format);
}

void print_str(va_list ap, format_t format)
{
    char *str = va_arg(ap, char *);
    int len = my_strlen(str);

    format.nb = format.nb - len;
    if (format.c == '0')
        format.c = ' ';
    format_spaces(&format);
    my_putstr(str);
    format_minus(&format);
}

void print_nbr(va_list ap, format_t format)
{
    int nbr = va_arg(ap, int);
    char *str = to_str(nbr);
    int len = my_strlen(str);

    if (nbr > 0 && format.special == ' ') {
        my_putchar(' ');
        len++;
    }
    if (nbr < 0 && format.c == '0') {
        my_putchar('-');
        nbr = -nbr;
    } else if (nbr > 0 && format.special == '+') {
        my_putchar(format.special);
        len++;
    }
    format.nb = format.nb - len;
    format_spaces(&format);
    my_put_nbr(nbr);
    format_minus(&format);
}

void print_unsigned_nbr(va_list ap, format_t format)
{
    unsigned int nbr = va_arg(ap, unsigned int);
    int size = 0;

    for (unsigned int i = nbr; i > 0; i = i / 10, size++);
    format.nb = format.nb - size;
    format_spaces(&format);
    my_putnbr_base(nbr, "0123456789");
    format_minus(&format);
}