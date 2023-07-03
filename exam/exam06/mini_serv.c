#include <unistd.h>
#include <stdbool.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define BUF_SIZE 4096
#define BACK_LOG 128

typedef struct s_client
{
    struct s_client *next;
    int client_id;
    int client_socket_fd;
} t_client;

typedef struct s_list
{
    t_client *head;
    t_client *tail;
    size_t node_count;
} t_list;

typedef enum
{
    CLIENT,
    SERVER
} e_sock_type;

void ft_error_exit(char *msg)
{
    write(STDERR_FILENO, msg, strlen(msg));
    write(STDERR_FILENO, "\n", 1);
    exit(EXIT_FAILURE);
}

void *ft_malloc(size_t size)
{
    void *ptr;

    ptr = malloc(size);
    if (ptr == NULL)
    {
        ft_error_exit("Fatal error");
    }
    return (ptr);
}

void setting_for_server_socket(struct sockaddr_in *serv_addr, char *port)
{
    serv_addr->sin_family = AF_INET;
    serv_addr->sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    serv_addr->sin_port = htons(atoi(port));
}

t_client *get_client_node(int fd, t_list client_list)
{
    t_client *curr_node;

    curr_node = client_list.head;
    while (curr_node != NULL)
    {
        if (curr_node->client_socket_fd == fd)
        {
            return (curr_node);
        }
        curr_node = curr_node->next;
    }
    return (NULL);
}

void add_node_to_list(t_client *node, t_list *list)
{
    if (list->node_count == 0)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }
    node->next = NULL;
    list->node_count += 1;
}

void remove_node_from_list(t_client *node, t_list *list)
{
    t_client *prev_node;
    t_client *curr_node;

    prev_node = NULL;
    curr_node = list->head;
    while (curr_node != NULL)
    {
        if (curr_node->client_id == node->client_id)
        {
            if (prev_node != NULL)
            {
                prev_node->next = curr_node->next;
                if (prev_node->next == NULL)
                {
                    list->tail = prev_node;
                }
            }
            else
            {
                list->head = curr_node->next;
            }
            list->node_count -= 1;
            return;
        }
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
}

void send_message_to_all_clients(int send_client_id, char *message, int recv_size, t_list *client_list, t_list *remove_list, e_sock_type type)
{
    char buf[20];
    ssize_t send_bytes;
    size_t buf_len;
    size_t msg_len;
    t_client *curr_node;

    curr_node = client_list->head;
    if (type == CLIENT)
    {
        sprintf(buf, "client %d: ", send_client_id);
        buf_len = strlen(buf);
        write(STDOUT_FILENO, buf, buf_len);
    }
    if (recv_size == -1)
    {
        msg_len = strlen(message);
        write(STDOUT_FILENO, message, msg_len);
    }
    else
    {
        write(STDOUT_FILENO, message, recv_size + 1);
    }
    while (curr_node != NULL)
    {
        if (type == CLIENT)
        {
            send_bytes = send(curr_node->client_socket_fd, buf, buf_len, 0);
            if (send_bytes == -1)
            {
                remove_node_from_list(curr_node, client_list);
                add_node_to_list(curr_node, remove_list);
                curr_node = curr_node->next;
                continue;
            }
        }

        if (recv_size == -1)
        {
            msg_len = strlen(message);
            send_bytes = send(curr_node->client_socket_fd, message, msg_len, 0);
        }
        else
        {
            send_bytes = send(curr_node->client_socket_fd, message, recv_size + 1, 0);
        }
        if (send_bytes == -1)
        {
            remove_node_from_list(curr_node, client_list);
            add_node_to_list(curr_node, remove_list);
        }
        curr_node = curr_node->next;
    }
}

void clear_client_node(t_list *remove_list)
{
    t_client *curr_node;
    t_client *next_node;

    curr_node = remove_list->head;
    next_node = NULL;
    while (curr_node != NULL)
    {
        next_node = curr_node->next;
        close(curr_node->client_socket_fd);
        free(curr_node);
        curr_node = next_node;
    }
    remove_list->head = NULL;
    remove_list->tail = NULL;
    remove_list->node_count = 0;
}

char *ft_strlcpy(char *dest, char *src, size_t dest_size)
{
    size_t idx;

    idx = 0;
    while (idx < dest_size)
    {
        dest[idx] = src[idx];
        idx += 1;
    }
    dest[idx] = '\0';
    return (dest);
}

char *extract_client_message(char *buf, ssize_t recv_size)
{
    char *ptr;

    ptr = malloc(sizeof(char) * (recv_size + 1));
    if (ptr == NULL)
    {
        ft_error_exit("Fatal error");
    }
    ft_strlcpy(ptr, buf, recv_size);
    return (ptr);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_error_exit("Wrong number of arguments");
    }

    int opt;
    int server_fd;
    struct sockaddr_in serv_addr, client_addr;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        ft_error_exit("Fatal error");
    }

    fcntl(server_fd, F_SETFL, O_NONBLOCK);
    opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
    {
        ft_error_exit("Fatal error");
    }

    bzero(&serv_addr, sizeof(serv_addr));
    setting_for_server_socket(&serv_addr, argv[1]);
    if (bind(server_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        ft_error_exit("Fatal error");
    }

    if (listen(server_fd, BACK_LOG) == -1)
    {
        ft_error_exit("Fatal error");
    }

    int max_fd;
    fd_set read_set, read_copy;
    int event_counts;
    int client_socket;
    t_client *client_node;
    t_list client_list;
    t_list remove_list;
    ssize_t recv_size;
    char *client_message;
    char buf[BUF_SIZE];
    unsigned int client_addr_size;

    FD_ZERO(&read_set);
    FD_SET(server_fd, &read_set);
    max_fd = server_fd;

    client_list.head = NULL;
    client_list.tail = NULL;
    client_list.node_count = 0;
    remove_list.head = NULL;
    remove_list.tail = NULL;
    remove_list.node_count = 0;

    while (true)
    {
        read_copy = read_set;

        event_counts = select(max_fd + 1, &read_copy, NULL, NULL, NULL);
        if (event_counts == -1)
        {
            ft_error_exit("Fatal error");
        }
        else if (event_counts == 0)
        {
            continue;
        }

        for (int idx = 0; idx < max_fd + 1; idx += 1)
        {
            if (FD_ISSET(idx, &read_copy))
            {
                // Client tries to establish TCP connection
                if (idx == server_fd)
                {
                    client_addr_size = sizeof(client_addr);
                    client_socket = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_size);

                    if (client_socket == -1)
                    {
                        ft_error_exit("Fatal error");
                    }
                    if (client_socket > max_fd)
                    {
                        max_fd = client_socket;
                    }
                    FD_SET(client_socket, &read_set);
                    fcntl(client_socket, F_SETFL, O_NONBLOCK);
                    client_node = ft_malloc(sizeof(t_client));
                    if (client_list.node_count == 0)
                    {
                        client_node->client_id = 0;
                    }
                    else
                    {
                        client_node->client_id = client_list.tail->client_id + 1;
                    }
                    client_node->client_socket_fd = client_socket;
                    add_node_to_list(client_node, &client_list);
                    sprintf(buf, "server: client %d just arrived\n", client_node->client_id);
                    send_message_to_all_clients(client_node->client_id, buf, -1, &client_list, &remove_list, SERVER);
                }
                // Client sends message
                else
                {
                    client_node = get_client_node(idx, client_list);
                    recv_size = recv(idx, buf, BUF_SIZE, 0);
                    if (recv_size == 0)
                    {
                        sprintf(buf, "server: client %d just left\n", client_node->client_id);
                        send_message_to_all_clients(client_node->client_id, buf, -1, &client_list, &remove_list, SERVER);
                        remove_node_from_list(client_node, &client_list);
                        add_node_to_list(client_node, &remove_list);
                        FD_CLR(idx, &read_set);
                        continue;
                    }
                    client_message = extract_client_message(buf, recv_size);
                    send_message_to_all_clients(client_node->client_id, client_message, recv_size, &client_list, &remove_list, CLIENT);
                    free(client_message);
                }
            }
        }

        if (remove_list.node_count > 0)
        {
            clear_client_node(&remove_list);
        }
    }
}