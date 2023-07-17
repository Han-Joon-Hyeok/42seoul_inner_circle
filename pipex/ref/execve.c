#include <unistd.h>
#include <stdio.h>

extern char **environ;

int	main(int argc, char *argv[])
{
	char	*new_argv[3];

	new_argv[0] = "/bin/ls";
	new_argv[1] = argv[1];
	new_argv[2] = NULL;
	printf("ls will be executed.\n");
	// int i = 0;
	// while (environ[i] != 0)
	// {
	// 	printf("%s\n",environ[i]);
	// 	i++;
	// }
	// execve("./print_hello", &argv[1], environ);
	execve("/bin/ls", new_argv, environ);
	printf("This is not executed.\n");

	return (0);
}

// #include <stdio.h>
// #include <unistd.h>

// int main()
// {
//    char *argv[]   = { "./show_envp", "HTTP", NULL};
//    char *envp[]   = { "HTTP=badayak.com", NULL};

//    execve( "./show_envp", argv, envp);

//    printf( "이 메시지가 보이면 지정된 프로그램이 \
// 없거나 어떤 문제로 실행되지 못한 것입니다.\n");
// }
