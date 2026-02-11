
void	ft_swap(int *a, int *b)
{
	int	a_copy;

	a_copy = *a;
	*a = *b;
	*b = a_copy;
}
