#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
/**
 * TO DO: Fix counter (broke after %% fix)
 * 	  Handle error when string is "%"
 */

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
	int flag = 0;
	int substr_len = 0;
	int printed = 0;

	va_list list;

	print_op op[] = {
		{"c", print_char},
		{"s", print_str},
	};

	va_start(list, format);
	
	if (format != NULL)
	{
		while (format[i] != '\0')
		{
			j = i + 1;
			k = 0;

			if (format[i] == '%' && format[j] == '%')
			{
				printed += write(1, "%", 1);	//removed flag from this sec bc we need newline to print
				i += 2;
			}

			while (k < 2)
			{
				if (format[i] == '%' && *op[k].key == format[j])
				{
					flag = 1;
					substr_len = op[k].f(&list);
					printed += substr_len;
				}
				k++;
			}

			if (flag != 1)
				printed += write(1, &format[i], 1);
			
			if (flag == 1)
				flag = 0;
			
			i++;
		}
	}
	va_end(list);
	printf("count: %d\n", printed);
	return (printed);
}

int main(void)
{
	char *s;

	s = "test";

	_printf("%s\n", s);
	_printf("str %%\n");
	_printf("Applessten\n");
	return (0);
}
