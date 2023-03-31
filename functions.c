#include "main.h"

/**
 * print_char - Prints a single character
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Field width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_char(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - Prints a string
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Field width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_string(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	if (str == NULL)
		str = "(null)";
	length = precision >= 0 ? strnlen(str, precision) : strlen(str);
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			handle_write_string(str, length, buffer, flags, 0);
			handle_write_padding(width - length, ' ', buffer);
		}
		else
		{
			handle_write_padding(width - length, (flags & F_ZERO) ? '0' : ' ', buffer);
			handle_write_string(str, length, buffer, flags, 0);
		}
		return (width);
	}
	handle_write_string(str, length, buffer, flags, 0);
	return (length);
}

/**
 * print_percent - Prints a percent sign
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Field width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_percent(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(precision);
	UNUSED(size);
	handle_write_char('%', buffer, flags, width, 0, 0);
	return (1);
}

/**
 * print_int - Prints an integer
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Field width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_int(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	unsigned long int num = convert_signed_number(types, size, &is_negative);

	if (num == 0)
		buffer[i--] = '0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - Prints a binary number
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Field width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */

