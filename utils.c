#include "linked_lists.h"

void	*ft_memdup(const void *data, size_t data_size)
{
	size_t          i;
	unsigned char   *dup;
	unsigned char   *tpd;

	if (!data || !data_size)
		return (NULL);
	dup = malloc(data_size);
	if (!dup)
		return (NULL);
	i = 0;
	tpd = (unsigned char *)data;
	while (i < data_size)
	{
		dup[i] = tpd[i];
		i++;
	}
	return ((void *)dup);
}

void	ft_memcpy(void *dest, const void *source, size_t data_size)
{
	size_t          index;
	unsigned char   *dst;
	unsigned char   *src;

	if (!source || !data_size || !dest)
		return ;
	index = 0;
	dst = (unsigned char *)dest;
	src = (unsigned char *)source;
	while (index < data_size)
	{
		dst[index] = src[index];
		index++;
	}
}