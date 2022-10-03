#include "v5.h"

char	*ft_strdup_protected(const char *src)
{
	char	*ptr;
	char	*des;
	int		len;

	len = slen((char *) src);
	des = malloc(sizeof(char) * (len + 1));
	if (!des)
		exit_error_alloc();
	ptr = des;
	while (*src)
		*des++ = *src++;
	*des = 0;
	return (ptr);
}

char	*ft_strndup_protected(const char *src, int n)
{
	char	*ptr;
	char	*des;
	int		size;
	int		i;

	size = slen((char *) src);
	if (size < n)
		des = malloc(sizeof(char) * (size + 1));
	else
		des = malloc(sizeof(char) * (n + 1));
	if (!des)
		exit_error_alloc();
	i = 0;
	ptr = des;
	while (*src && i < n)
	{
		*des++ = *src++;
		i++;
	}
	*des = 0;
	return (ptr);
}

char	*ft_strjoin_triple(char *s1, char *s2, char *s3)
{
	char	*temp;
	char	*r;

	temp = ft_strjoin_protected(s1, s2);
	if (!temp)
		exit_error_alloc();
	r = ft_strjoin_protected(temp, s3);
	if (!r)
		exit_error_alloc();
	free(temp);
	return (r);
}

// ft_strjoin_protected (with 2 helper function)

char		*cat(char *, char *);
char		*cpy(char *, char *);

char	*ft_strjoin_protected(char const *prefix, char const *suffix)
{
	int		size;
	char	*res;

	if (!prefix)
		return (0);
	if (!suffix)
		return ((char *) prefix);
	size = slen((char *) prefix) + slen((char *) suffix) + 1;
	res = (char *) malloc(sizeof(char) * size);
	if (!res)
		exit_error_alloc();
	cpy(res, (char *) prefix);
	cat(res, (char *) suffix);
	return (res);
}

char	*cat(char *des, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (des[i])
		i++;
	while (src[j])
	{
		des[i + j] = src[j];
		j++;
	}
	des[i + j] = 0;
	return (des);
}

char	*cpy(char *des, char *src)
{
	char	*tmp;

	tmp = des;
	while (*src)
		*tmp++ = *src++;
	*tmp = 0;
	return (des);
}
