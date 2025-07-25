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
 * _printf - produces output according to a format specifier
 * @format: the string to print, with or without format specifiers
 * Return: number of characters printed
*/
int _printf(const char *format, ...)
{
	int i = 0, j, flag = 0, substr_len = 0, printed = 0;
	va_list list;
	print_op op[] = {
		{"c", print_char},
		{"s", print_str},
	};

	va_start(list, format);
	if (format == NULL)
		return (0);
	if (format != NULL)
	{
		while (format[i] != '\0')
		{
			j = 0, flag = 0;
			if (format[i] == '%' && format[i + 1] == '%')
			{
				flag = 1;
				printed += write(1, "%", 1);
			}
			while (j < 2)
			{
				if (format[i] == '%' && *op[j].key == format[i + 1])
				{
					flag = 1;
					substr_len = op[j].f(&list);
					printed += substr_len;
				}
				j++;
			}
			if (flag != 1)
			{
				printed += write(1, &format[i], 1);
				i++;
			}
			else
				i = i + 2;
		}
	}
	va_end(list);
	return (printed);
}
