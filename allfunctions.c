#include "main.h"
/**
  *_putchar - prints characters
  *@c: Character to be printed
  *Return: Always 0 (success)
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  *print_c - prints number of characters
  *@args: arguments
  *Return: character count
  */
int print_c(va_list args)
{
	char c = va_arg(args, int);
	int count_c = 0;

	count_c += _putchar(c);
	return (count_c);
}
/**
  *print_s - prints a string
  *@args: string arguments
  *Return: string count
  */
int print_s(va_list args)
{
	int j = 0, count_s = 0;
	char *s = va_arg(args, char *);

	if (s == NULL)
	{
		s = "(null)";
	}
	while (s[j] != '\0')
	{
		count_s += _putchar(s[j]);
		j++;
	}
	return (count_s);
}
/**
  *print_int - prints an integer
  *@args: arguments
  *Return: integer count
  */
int print_int(va_list args)
{
	unsigned int num, my_num, counter, count;
	int n;

	count = 0;
	n = va_arg(args, int);
	if (n < 0)
	{
		num = (n * -1);
		count += _putchar('-');
	}
	else
		num = n;
	my_num = num;
	counter = 1;
	while (my_num > 9)
	{
		my_num /= 10;
		counter *= 10;
	}
	while (counter >= 1)
	{
		count += _putchar(((num / counter) % 10) + '0');
		counter /= 10;
	}
	return (count);
}
/**
  *choice - function to switch
  *@s: character for switch
  *Return: 0 (Success)
  */
int (*choice(char s))(va_list)
{
	if (s == 'c')
	{
		return (print_c);
	}
	else if (s == 's')
	{
		return (print_s);
	}
	else if (s == 'i' || s == 'd')
	{
		return (print_int);
	}
	return (NULL);
}
