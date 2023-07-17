#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char *pathname = "./hello.txt";
	int mode = R_OK | W_OK;
	if( access( pathname, mode ) == 0 ){
		printf("읽고 쓸 수 있습니다.");
	}
	else{
		// errno 변수값에 에러명 설정
		// strerror(errno);
		printf("권한이 없거나 존재하지 않습니다.");
	}
	return (0);
}
