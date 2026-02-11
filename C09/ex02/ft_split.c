#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#define DA_INIT_CAP 5000

typedef struct s_str_da {
	char	**items;
	size_t	size;
	size_t	cap;
}	t_str_da;

void	str_da_append(t_str_da *da, char *str);
int		ft_strlen(char *str);
char	**ft_split(char *str, char *charset);
long	find_in_str(char *haystack, char *needle);
char	*strn_alloc_and_cpy(char *str, size_t until);

char	**ft_split(char *str, char *charset)
{
	size_t		i;
	size_t		pos;
	t_str_da	da;
	char		*new_str;

	da = (t_str_da){malloc(DA_INIT_CAP * sizeof(char**)), 0, DA_INIT_CAP};
	i = 0;
	while (find_in_str(&str[i], charset) != -1)
	{
		pos = find_in_str(&str[i], charset);
		new_str = strn_alloc_and_cpy(&str[i], pos);
		str_da_append(&da, new_str);
		i += pos + 1;
	}
	str_da_append(&da, NULL);
	return (da.items);
}

char	*strn_alloc_and_cpy(char *str, size_t until)
{
	size_t	i;
	char	*new_str;

	new_str = malloc(until + 1);
	i = 0;
	while (i < until)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[until] = '\0';
	return (new_str);
}

long	find_in_str(char *haystack, char *needle)
{
	long	i;
	long	j;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (needle[j] && haystack[i + j] && needle[j] == haystack[i + j])
			j++;
		if (j == ft_strlen(needle) - 1)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Having `free` would be nice
void	str_da_append(t_str_da *da, char *str)
{
	char	**new_ptr;
	size_t	i;

	if (da->cap <= da->size + 1)
	{
		da->cap *= 2;
		new_ptr = malloc(sizeof(char**) * da->cap);
		i = 0;
		while (i < da->size)
		{
			new_ptr[i] = da->items[i];
			i++;
		}
		da->items = new_ptr;
	}
	da->items[da->size++] = str;
}

int	main(void)
{
	char **splitstr = ft_split("Hello, I, am, a, Test,!", ",");
	printf("is done!\n");
	for (size_t i = 0; splitstr[i]; i++) {
		printf("%s\n", splitstr[i]);
	}
}
