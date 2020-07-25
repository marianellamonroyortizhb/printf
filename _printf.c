#include "holberton.h"

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
	char new_pointer[2048];
	va_list list;

	va_start(list, format);

	if (format == NULL)
		return (-1);
	for (counter = 0; format != NULL && format[counter] != '\0'; counter++)
	{
		if (format[counter] == '%')
		{
			counter++;
			switch (format[counter])
			{
			case 's':
				buff_cou = subs(new_pointer, list, buff_cou);
				break;
			case 'c':
				buff_cou = subc(new_pointer, list, buff_cou);
				break;
			case '%':
				new_pointer[buff_cou] = '%', buff_cou++;
				break;
			case '\0':
				return (-1);
			default:
				counter--;
				new_pointer[buff_cou] = '%';
				new_pointer[buff_cou] = format[counter], buff_cou++;
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
	return (buff_cou);
}
/**
* subc - substitute %c by the list element
* @new_pointer: string to change
* @list: va_list char to change
* @buff_cou: index of dst where the c of %c is
* Return: New index
*/
int subc(char *new_pointer, va_list list, int buff_cou)
{
	int z_c;

	z_c = va_arg(list, int);
	new_pointer[buff_cou] = z_c;
	buff_cou++;
	return (buff_cou);
}
/**
* subs - prints a character.
* @new_pointer: Is a character string,
* it is composed of zero or more directives.
* @list: string list of arguments.
* @buff_cou: index of dst where the c of %c is
* Description: _subs writes a character.
* Return: The number of characters printed, avoiding the end null byte.
*/
int subs(char *new_pointer, va_list list, int buff_cou)
{
	char *value;
	int i;

	value = va_arg(list, char *);
	if (value == NULL)
		value = "(null)";
	for (i = 0; value[i]; i++, buff_cou++)
	new_pointer[buff_cou] = value[i];
	return (buff_cou);
}
