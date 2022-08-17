#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

typedef struct	s_node
{
	char			c;
	struct s_node	*next;
}	t_node;

typedef struct	s_lst
{
	size_t	len;
	t_node	*head;
	t_node	*tail;
	int		exist_newline;
}	t_lst;

char	*get_next_line(int fd);
