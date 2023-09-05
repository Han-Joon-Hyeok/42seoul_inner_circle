#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

#define FATAL_ERROR "Fatal error\n"
#define WRONG_NUMBER_ARG "Wrong number of arguments\n"

#define ERROR -1
#define BUFFER_SIZE 300000

typedef struct s_node
{
    int fd;
    int id;
    struct s_node *next;
} t_node;

typedef struct s_list
{
    int last_id;
    t_node *head;
} t_list;

void fatal_error(void)
{
    write(STDERR_FILENO, FATAL_ERROR, strlen(FATAL_ERROR));
    exit(EXIT_FAILURE);
}

void wrong_arg_error(void)
{
    write(STDERR_FILENO, WRONG_NUMBER_ARG, strlen(WRONG_NUMBER_ARG));
    exit(EXIT_FAILURE);
}

void *ft_malloc(size_t size)
{
    void *ptr;

    ptr = malloc(size);
    if (ptr == NULL)
    {
        fatal_error();
    }
    return (ptr);
}

void init_list(t_list *list)
{
    list->last_id = 0;
    list->head = NULL;
}

t_node *get_last_node(t_list *list)
{
    t_node *node;

    node = list->head;
    while (node != NULL)
    {
        if (node->next == NULL)
        {
            break;
        }
        node = node->next;
    }
    return (node);
}

void lstadd_back(t_list *list, int fd)
{
    t_node *node;
    t_node *last;

    node = ft_malloc(sizeof(t_node));
    node->fd = fd;
    node->id = list->last_id;
    node->next = NULL;
    list->last_id += 1;

    if (list->head == NULL)
    {
        list->head = node;
    }
    else
    {
        last = get_last_node(list);
        last->next = node;
    }
}

void send_entrance(t_list *list)
{
    t_node *curr;
    size_t len;
    char buf[40];

    curr = list->head;
    len = sprintf(buf, "server: client %d just arrived\n", list->last_id);
    while (curr != NULL)
    {
        if (send(curr->fd, buf, len, 0) == ERROR)
        {
            fatal_error();
        }
        curr = curr->next;
    }
}

t_node *lst_remove(t_list *list, int fd)
{
    t_node *prev;
    t_node *curr;

    prev = NULL;
    curr = list->head;
    while (curr != NULL)
    {
        if (curr->fd == fd)
        {
            if (prev == NULL)
            {
                list->head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    return (curr);
}

void send_leave(t_list *list, int id)
{
    t_node *curr;
    char buf[40];
    size_t len;

    curr = list->head;
    len = sprintf(buf, "server: client %d just left\n", id);
    while (curr != NULL)
    {
        if (send(curr->fd, buf, len, 0) == ERROR)
        {
            fatal_error();
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

void send_message(t_list *list, char *buf, ssize_t recv_size, int id)
{
    int front;
    int back;
    int idx;
    size_t len;
    t_node *curr;
    char *temp_buf;
    char *send_buf;

    front = 0;
    back = 0;
    idx = 0;
    while (front < recv_size)
    {
        if (buf[front] == '\n')
        {
            temp_buf = ft_malloc(sizeof(char) * (front - back + 2));
            send_buf = ft_malloc(sizeof(char) * (front - back + 20));
            while (back <= front)
            {
                temp_buf[idx++] = buf[back++];
            }
            temp_buf[idx] = '\0';
            len = sprintf(send_buf, "client %d: %s", id, temp_buf);

            curr = list->head;
            while (curr != NULL)
            {
                if (curr->id != id)
                {
                    if (send(curr->fd, send_buf, len, 0) == ERROR)
                    {
                        fatal_error();
                    }
                }
                curr = curr->next;
            }

            free(temp_buf);
            free(send_buf);
            idx = 0;
        }
        front += 1;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        wrong_arg_error();
    }

    int port;

    port = atoi(argv[1]);

    int server_fd, conn_fd;
    socklen_t len;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == ERROR)
    {
        fatal_error();
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(2130706433);
    servaddr.sin_port = htons(port);

    if ((bind(server_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) == ERROR)
    {
        fatal_error();
    }

    if (listen(server_fd, 128) == ERROR)
    {
        fatal_error();
    }

    int max_fd;
    int events;
    char buf[BUFFER_SIZE];
    fd_set read_origin, read_copy;
    t_list client_list;
    t_node *node;
    ssize_t recv_size;

    max_fd = server_fd;
    FD_ZERO(&read_origin);
    FD_SET(server_fd, &read_origin);
    read_copy = read_origin;
    init_list(&client_list);
    len = sizeof(cli);

    while (42)
    {
        events = select(max_fd + 1, &read_origin, NULL, NULL, NULL);
        if (events == ERROR)
        {
            fatal_error();
        }
        else if (events == 0)
        {
            continue;
        }

        if (FD_ISSET(server_fd, &read_origin))
        {
            conn_fd = accept(server_fd, (struct sockaddr *)&cli, &len);
            if (conn_fd == ERROR)
            {
                fatal_error();
            }
            if (max_fd < conn_fd)
            {
                max_fd = conn_fd;
            }
            send_entrance(&client_list);
            lstadd_back(&client_list, conn_fd);
            FD_SET(conn_fd, &read_copy);
        }
        else
        {
            for (int fd = 3; fd <= max_fd; fd += 1)
            {
                if (FD_ISSET(fd, &read_origin))
                {
                    recv_size = recv(fd, buf, BUFFER_SIZE, 0);
                    if (recv_size == 0)
                    {
                        node = lst_remove(&client_list, fd);
                        send_leave(&client_list, node->id);
                        FD_CLR(fd, &read_copy);
                        free(node);
                        close(fd);
                    }
                    else
                    {
                        node = get_node(&client_list, fd);
                        send_message(&client_list, buf, recv_size, node->id);
                    }
                }
            }
        }
        read_origin = read_copy;
    }
}