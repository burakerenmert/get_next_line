#include "get_next_line.h"

int main()
{
	int fd;
	fd = open("text.txt", O_RDONLY | O_CREAT, 0777);
	printf("%s", get_next_line(fd));
}
