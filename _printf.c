#include "holberton.h"
#include <stdarg.h>
#define STDOUT 1
/**
* _printf - prints a string like output according to a format.
* @format: Is a character string, it is composed of zero or more directives.
*
* Description: _printf writes the output to stdout.
* Return: The number of characters printed, avoiding the end null byte.
*/
int _printf(const char *format, ...)
{
	va_list list;

	int counter = 0;
	int buff_cou = 0;
	char new_pointer[1024];
	int i;
	char *value = NULL;

	va_start(list, format);

	for (counter = 0; format[counter] != '\0'; counter++)
	{
	if (format[counter] == '%')
	{
		counter++;
			if (format[counter] == 's')
			{
				value = va_arg(list, char *);
				for (i = 0; value[i]; i++, buff_cou++)
				new_pointer[buff_cou] = value[i];
			}
			if (format[counter] == 'c')
			{
				new_pointer[buff_cou] = va_arg(list, int); /*Cambiando % por char_p */
				buff_cou++;
			}
		}
		else
		{
			new_pointer[buff_cou] = format[counter];
			buff_cou++;
		}
	}
	new_pointer[buff_cou] = '\0';		/* setting end character */
	write(STDOUT, new_pointer, strlen(new_pointer));/* salida del buffer */
	va_end(list);
	return (0);
}
