#include "holberton.h"
#include <stdarg.h>
#define STDOUT 1

int subc(char *new_pointer, va_list list, int buff_cou);
int subs(char *new_pointer, va_list list, int buff_cou);
/**
* _printf - prints a string like output according to a format.
* @format: Is a character string, it is composed of zero or more directives.
*
* Description: _printf writes the output to stdout.
* Return: The number of characters printed, avoiding the end null byte.
*/
int _printf(const char *format, ...)
{
	int counter = 0, buff_cou = 0;
	char new_pointer[1024];
	va_list list;

	va_start(list, format);

	for (counter = 0; format != NULL && format[counter] != '\0'; counter++)
	{
	if (format[counter] == '%')
	{
		counter++;
			if (format[counter] == 's')
			{
				buff_cou = subs(new_pointer, list, buff_cou);
			}
			if (format[counter] == 'c')
			{
				buff_cou = subc(new_pointer, list, buff_cou);
			}
			if (format[counter] == '%')
			{
				new_pointer[buff_cou] = '%', buff_cou++;
			}
		}
		else
		{
			new_pointer[buff_cou] = format[counter], buff_cou++;
		}
	}
	new_pointer[buff_cou] = '\0';		/* setting end character */
	write(STDOUT, new_pointer, strlen(new_pointer));/* salida del buffer */
	va_end(list);
	return (strlen(new_pointer));
}

int subc(char *new_pointer, va_list list, int buff_cou)
{
	int z_c;

	z_c = va_arg(list, int);
	if (z_c != 0)
	new_pointer[buff_cou] = z_c, buff_cou++;/*Cambiando % por char_p */
	return (buff_cou++);
}

int subs(char *new_pointer, va_list list, int buff_cou)
{
	char *value;
	int i;

	value = va_arg(list, char *);
	for (i = 0; value != NULL && value[i]; i++, buff_cou++)
	new_pointer[buff_cou] = value[i];
	return (buff_cou);
}
