#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
/**
 * print_char - prints a character to standard output
 * @list: a pointer a list containing the substring
 * Return: number of characters 
 */
int  print_char(va_list *list)
{
	char ch;
	int result = 0;

	ch = va_arg(*list, int);
        result = write(1, &ch, 1);
	return (result);
}
/**
 * print_str - prints a string to standard output
 * @list: a pointer a list containing the substring
 * Return: number of characters 
 */
int  print_str(va_list *list)
{
	char *str;
	int result = 0;

	str = va_arg(*list, char *);
	if (str == NULL)
	{
		result = write(1, "(null)", 6);
	}
	else
	{
		result = write(1, str, strlen(str));
	}
	return (result);
}
/**
 * _printf - produces output according to a format
 * @list: a pointer a list containing the substring
 * Return: number of characters 
*/
int _printf(const char *format, ...)
{
	int i = 0, j, k = 0;
	print_op op[] = {
		{"c", print_char},
		{"s", print_str},
	};
	va_list list;
	int flag = 0;
	int len = 0, substr_len = 0, total_len = 0, counter = 0;

	va_start(list, format);
	if (format != NULL)
	{
		while (format[i] != '\0')
		{
			j = i + 1;
			k = 0;
			while (k < 2)
			{
				if (format[i] == '%' && *op[k].key == format[j])
				{
					flag = 1;
					counter++;
					substr_len = op[k].f(&list);
					len = len + substr_len;
				}

				if (format[i] == '%' && format[j] == '%')
				{
					flag = 1;
					write(1, &format[i], 1);
				}
				k++;
			}
			if (flag != 1)
				write(1, &format[i], 1);
			else
				i = i + 1;
			i++;
			flag = 0;
		}
	}
	va_end(list);
	total_len = (i + len) - (counter * 2);
	return (total_len);
}

