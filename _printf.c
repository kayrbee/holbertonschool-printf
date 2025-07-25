#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
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
 * @list: a pointer to a list containing the substring
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
 * print_int - prints integers to stdout
 * @list: a pointer to a lst containing the substring
 * Return: number of characters
 */
int print_int(va_list *list)
{
	int count = 0;
	int i = 0; int j = 0;
	unsigned absolute_number;

	int original_number = va_arg(*list, int);
	char temp[12];

	if (original_number < 0)
	{
		count += write(1, "-", 1);
		absolute_number = -original_number;
	}
	else
	{
		absolute_number = original_number;
	}
	/* Convert number to character in reverse order */
	if (absolute_number == 0)
	{
		temp[i] = '0';
	}
	else
	{
		while (absolute_number > 0)
		{
			temp[i] = (absolute_number % 10) + '0';
			absolute_number = absolute_number / 10;
		}
	}
	/* Write the number in correct order */
	j = i - 1;
	while (j >= 0)
	{
		count += write(1, &temp[j], 1);
		j--;
	}
}
/**
 * get_function - returns a pointer to correct print_ function based on a specifier
 * @c: format specifier ('c', 's'c 'd', 'i')
 * Return: pointer to the corresponding function
 */
int (*get_function(char c))(va_list *)
{
	print_op op[] = {
		{"c", print_char},
		{"s", print_str},
		{"i", print_int},
		{"d", print_int},
	};
	int l = 0;
	while (op[l].key != NULL)
	{
		if(op[l].key[0] == 'c')
			return (op[l].f);
		l++;
	}
	return (NULL);
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
	va_start(list, format);
	if (format == NULL)
		exit(98);
	while (format[i] != '\0')
	{
		j = 0, flag = 0;
		if (format[i] == '%' && format[i + 1] == '\0')
			exit(99);
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
	va_end(list);
	return (printed);
}

