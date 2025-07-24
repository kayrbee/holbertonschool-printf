#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
/**
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
 */
int  print_str(va_list *list)
{
	char *str;
	int result = 0;

	str = va_arg(*list, char *);
        result = write(1, str, strlen(str));
	return (result);
}
/**
 * Current state: prints a string 
 * 		  handle case of %x (ie unknown specifiers)
 * 		  handle other errors
 * 		  fix betty documentation
 */

int _printf(const char *format, ...)
{
	int i = 0, j, k = 0;
	print_op op[] = {
		{"c", print_char},
		{"s", print_str},
	};
	va_list list;
	int counter = 0;

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
					counter = counter + op[k].f(&list);
					i = i + 2;
					counter = counter - 2;
				}

				if (format[i] == '%' && format[j] == '%')
				{
					counter = counter + write(1, &format[i], 1);
					i = i + 2;
					counter = counter - 2;
				}
				k++;
			}
			write(1, &format[i], 1);
			i++;
		}
	}
	va_end(list);
	counter = counter + (i - 1);
	printf("%d\n", counter);
	return (i);
}

int main(void)
{
	char a = 'a';
	char *str = "Hello!";

	_printf("%c\n", a);
	_printf("%s\n", str);
	return (0);
}
