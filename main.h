#ifndef PRINTF_FUNCTION
#define PRINTF_FUNCTION
#include <unistd.h>
#include <stddef.h>

int _printf(const char *format, ...);

/* create a struct */
typedef struct print_op
{
	const char *key;
	int (*f)(va_list *list);
} print_op;

int  print_char(va_list *list);
int  print_str(va_list *list);
int print_int(va_list *list);
int (*get_function(char c))(va_list *);

#endif

