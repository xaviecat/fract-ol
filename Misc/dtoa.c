#include <stdio.h>
#include <stdlib.h>
#include <float.h>

static size_t	get_len(double n, long num, size_t len, size_t precision)
{

	if (num == 0)
		len = 1;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	len += precision + 1;
	if (n < 0)
		len++;
	return (len);
}

static size_t	get_int_part(char *str, double n, long num, size_t i)
{
	long	tmp;
	size_t	ret;

	num = (long)n;
	tmp = num;
	ret = 0;
	while (tmp)
	{
		tmp /= 10;
		ret++;
	}
	while (num != 0)
	{
		str[ret] = (num % 10) + '0';
		num /= 10;
		ret--;
		i++;
	}
	if (n < 1 && n > -1)
		str[i++] = '0';
	return (i);
}

static void	get_dec_part(char *str, double dec, long num, size_t len)
{
	size_t	i;

	i = 0;
	str[i] = '.';
	i++;
	while (i < len)
	{
		dec *= 10;
		num = (long)dec;
		str[i] = (num % 10) + '0';
		dec -= (double)num;
		i++;
	}
	str[i] = '\0';
}

/* Precision 15 */
char	*ft_dtoa(double n, size_t precision)
{
	char	*str;
	size_t	i;
	size_t	len;
	double	dec;
	long	num;

	len = 0;
	num = (long)n;
	len = get_len(n, num, len, precision);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
		n = -n;
	}
	i = get_int_part(str, n, num, i);
	dec = n - (double)num;
	len -= i;
	get_dec_part(&str[i], dec, num, len);
	return (str);
}

// char	*ft_dtoa(double n, int precision)
// {
// 	char	*str;
// 	int		i;
// 	int		len;
// 	double	dec;
// 	long	num;
// 	int		digits[100];
// 	int		dig_count;
//
// 	len = 0;
// 	num = (long)n;
// 	if (num == 0)
// 		len = 1;
// 	dig_count = 0;
// 	while (num != 0)
// 	{
// 		digits[dig_count] = num % 10;
// 		dig_count++;
// 		num /= 10;
// 	}
// 	len += dig_count + precision + 1;
// 	if (n < 0)
// 		len++;
// 	str = malloc(sizeof(char) * (len + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	i = 0;
// 	if (n < 0)
// 	{
// 		str[i] = '-';
// 		i++;
// 		n = -n;
// 	}
// 	while (dig_count > 0)
// 	{
// 		str[i] = digits[dig_count - 1] + '0';
// 		dig_count--;
// 		i++;
// 	}
// 	if (i == 0)
// 		str[i] = '0';
// 	str[i] = '.';
// 	i++;
// 	while (i < len)
// 	{
// 		dec *= 10;
// 		num = (long)dec;
// 		str[i] = (num % 10) + '0';
// 		dec -= (double)num;
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

int	main(void)
{
	double		nbr;
	long long	nbr2;
	long long	nbr3;
	long long	nbr4;
	long long	nbr5;
	char		*str;

	nbr = -2.999999999921474836482147483648;
	nbr2 = 99999999992147;
	nbr3 = 483648214748364;
	str = ft_dtoa(nbr, 31);
	printf("%.31f\n%s\n-2.%lld%lld", nbr, str, nbr2, nbr3);
	free(str);
	nbr = -2147483648.21474836482147483648;
	nbr2 = 2147483648;
	nbr3 = 2147483648;
	nbr4 = 2147483648;
	nbr5 = 2147483648;
	str = ft_dtoa(nbr, 31);
	printf("\n\n%.31f\n%s\n-%lld.%lld%lld%lld", nbr, str, nbr2, nbr3, nbr4, nbr5);
	free(str);
	return (0);
}

