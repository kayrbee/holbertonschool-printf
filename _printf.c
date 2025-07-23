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
 * Current state: prints a string without new line
 * 		  also prints literal %s - needs to be fixed
 * 		  handle case of %x (ie unknown specifiers)
 * 		  handle other errors
 * 		  fix betty documentation
 * 		  handle "%" literal print
 */

int _printf(const char *format, ...)
{
	int i = 0, j, k = 0;
	print_op op[] = {
		{"c", print_char},
		{"s", print_str},
	};
	va_list list;

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
					op[k].f(&list);
				}
				k++;
			}
			write(1, &format[i], 1);  //check strlen necessity here, check later
			i++;
		}
	}
	va_end(list);
	return (-1);
}

int main(void)
{
	char *a = "variable a";

//	_printf("hello!");
	_printf("string %s b", a);
	
	return (0);
}
