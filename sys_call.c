#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* Write to the terminal */
    char buf[100];
    strncpy(buf, "Hello World!!\n", 99);
    write(1, buf, strlen(buf));

    /* Open file using sys_call */
	int fd = open("file1.txt", O_RDWR | O_CREAT, S_IRWXU | S_IRWXG  | S_IROTH);
	if (fd == -1) {
		printf("There was a problem with opening the file - error: %d\n", errno);
		perror("Error:");
	}
	else
	{
		printf("\n File opened Successfully! with fd: %d\n", fd);
	}
    return 0;
}
