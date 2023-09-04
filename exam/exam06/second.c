#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

#define FATAL_ERROR "Fatal error"
#define ERROR -1
#define BACK_LOG 128
#define BUFFER_SIZE 4096

typedef struct s_node {
	int fd;
	int id;
	struct s_node *next;
} t_node;

typedef struct s_list {
	int count;
	int last_id;
	t_node *head;
} t_list;

void    ft_exit_error(char *msg)
{
    if (msg == NULL)
    {
        exit(EXIT_FAILURE);
    }
    exit(EXIT_FAILURE);
}

void *ft_malloc(int size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		ft_exit_error(FATAL_ERROR);
	}
	return (ptr);
}

void init_list(t_list *list)
{
	list->count = 0;
	list->last_id = 0;
	list->head = NULL;
}

t_node *get_last(t_list *list)
{
	t_node *curr;

	curr = list->head;
	while (curr != NULL)
	{
		if (curr->next == NULL)
		{
			break;
		}
		curr = curr->next;
	}
	return (curr);
}

t_node *lstadd_back(t_list *list, int fd)
{
	t_node *last;
	t_node *new_node;

	new_node = ft_malloc(sizeof(t_node));
	new_node->fd = fd;
	new_node->id = list->last_id;
	new_node->next = NULL;

	if (list->count == 0)
	{
		list->head = new_node;
	}
	else
	{
		last = get_last(list);
		last->next = new_node;
	}
	list->count += 1;
	list->last_id += 1;

	return (new_node);
}

void send_entrance_to_all(t_list *list, int id)
{
	char buf[100];
	t_node *curr;
	size_t len;

	curr = list->head;
	bzero(buf, 100);
	len = sprintf(buf, "server: client %d just arrived\n", id);
	while (curr != NULL)
	{
		if (curr->id != id)
		{
			send(curr->fd, buf, len, 0);
		}
		curr = curr->next;
	}
}

void send_leave_to_all(t_list *list, int id)
{
	char buf[100];
	t_node *curr;
	size_t len;

	curr = list->head;
	bzero(buf, 100);
	len = sprintf(buf, "server: client %d just left\n", id);
	while (curr != NULL)
	{
		if (curr->id != id)
		{
			send(curr->fd, buf, len, 0);
		}
		curr = curr->next;
	}
}

int get_client_fd(t_list *list, fd_set *read)
{
	t_node *curr;

	curr = list->head;
	while (curr != NULL)
	{
		if (FD_ISSET(curr->fd, read))
		{
			return (curr->fd);
		}
	}
	return (ERROR);
}

t_node *lst_pop(t_list *list, int fd)
{
	t_node *prev;
	t_node *curr;

	curr = list->head;
	while (curr != NULL)
	{
		prev = curr;
		if (curr->fd == fd)
		{
			if (list->count == 1)
			{
				list->head = NULL;
			}
			else
			{
				prev->next = curr->next;
			}
			list->count -= 1;
			if (list->last_id == curr->id && list->last_id > 0)
			{
				list->last_id -= 1;
			}
			break ;
		}
		curr = curr->next;
	}
	return (curr);
}

void send_to_all(t_list *list, char *buf, t_node *node)
{
	char send_buf[BUFFER_SIZE + 10];
	t_node *curr;
	size_t len;

	curr = list->head;
	len = sprintf(send_buf, "client %d: %s", node->id, buf);
	while (curr != NULL)
	{
		if (curr->fd != node->fd)
		{
			send(curr->fd, send_buf, len, 0);
		}
		curr = curr->next;
	}

}

t_node *get_node(t_list *list, int fd)
{
	t_node *curr;

	curr = list->head;
	while (curr != NULL)
	{
		if (curr->fd == fd)
		{
			break;
		}
		curr = curr->next;
	}
	return (curr);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_exit_error("Wrong number of arguments");
    }

    int port;
    int server_fd, conn_fd;
	socklen_t len;
	struct sockaddr_in servaddr, cli;

    port = atoi(argv[1]);
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == ERROR)
    {
		ft_exit_error(FATAL_ERROR);
	}
	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port);

	if ((bind(server_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) == ERROR)
    {
		ft_exit_error(FATAL_ERROR);
	}
	if (listen(server_fd, BACK_LOG) == ERROR)
	{
		ft_exit_error(FATAL_ERROR);
	}

	int max_fd;
	int events, client_fd;
	char buf[BUFFER_SIZE];
	ssize_t recv_size;
	t_node *node;
	fd_set read_origin, read_copy;
	t_list client_list, remove_list;

	max_fd = server_fd;
	FD_ZERO(&read_origin);
	FD_SET(server_fd, &read_origin);
	read_copy = read_origin;
	init_list(&client_list);
	init_list(&remove_list);

	while (42)
	{
		events = select(max_fd + 1, &read_origin, NULL, NULL, NULL);

		if (events == ERROR)
		{
			ft_exit_error(FATAL_ERROR);
		}
		else if (events == 0)
		{
			continue;
		}

		for (int idx = 0; idx < events; ++idx)
		{
			if (FD_ISSET(server_fd, &read_origin))
			{
				conn_fd = accept(server_fd, (struct sockaddr *)&cli, &len);
				if (conn_fd == ERROR)
				{
					ft_exit_error(FATAL_ERROR);
				}
				max_fd = conn_fd;
				node = lstadd_back(&client_list, conn_fd);
				send_entrance_to_all(&client_list, node->id);
				FD_SET(conn_fd, &read_copy);
			}
			else
			{
				client_fd = get_client_fd(&client_list, &read_origin);
				bzero(buf, BUFFER_SIZE);
				recv_size = recv(client_fd, buf, BUFFER_SIZE, 0);
				if (recv_size == 0)
				{
					node = lst_pop(&client_list, client_fd);
					lstadd_back(&remove_list, client_fd);
					send_leave_to_all(&client_list, node->id);
					FD_CLR(client_fd, &read_copy);
					free(node);
				}
				else
				{
					node = get_node(&client_list, client_fd);
					send_to_all(&client_list, buf, node);
				}
			}
		}
		read_origin = read_copy;
	}
}