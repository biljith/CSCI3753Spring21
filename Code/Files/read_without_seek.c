#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#define BUFFER_SIZE 20

void _read(int file) {
	char *user_buffer = (char *)malloc(BUFFER_SIZE);

	int readbytes = read(file, user_buffer, 6);
	printf("Read %d bytes: %s\n", readbytes, user_buffer);

	readbytes = read(file, user_buffer, 8);
	printf("Read %d bytes: %s\n", readbytes, user_buffer);

	free(user_buffer);
}

int main() {
	int file = open("file.txt", O_RDWR);
	_read(file);
}