#include "linked_lists.h"

void	*ft_memdup(void *data, size_t data_size)
{
	size_t			i;
	unsigned char	*dup;
	unsigned char	*tpd;

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
	return (dup);
}
