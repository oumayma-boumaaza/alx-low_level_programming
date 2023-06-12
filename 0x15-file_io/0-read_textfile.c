#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: actual number of bytes read and printed (w)
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t file_descriptor;
	ssize_t bytes_read;
	ssize_t total_bytes_read;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	total_bytes_read = read(file_descriptor, buf, letters);
	bytes_read = write(STDOUT_FILENO, buf, total_bytes_read);

	free(buf);
	close(file_descriptor);
	return (bytes_read);
}

