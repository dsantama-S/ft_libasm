#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define VERDE_T        "\x1b[32m"
#define ROJO_T     "\x1b[31m"
#define RESET_COLOR    "\x1b[0m"
int ft_strlen(const char *);
char *ft_strcpy(char *, const char *);
int ft_strcmp(const char *, const char *);
ssize_t ft_write(int, const void *, size_t);
ssize_t ft_read(int, void *, size_t);
char *ft_strdup(const char *);

static int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && \
	(((unsigned char *)s1)[i] != '\0' || ((unsigned char *)s2)[i] != '\0'))
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

int main()
{
	int i;
	int fd;
	int n;
	char s1[9];
	char s2[9];
	char *s3;
	char *s4;
	char c;

	i = 0;
	n = 0;
	printf("\n*****Tests*****\n\n");
	printf("TEST FT_STRLEN:\n");
	i = strlen("1234");
	n = ft_strlen("1234");
	if (i == n)
		printf(VERDE_T "[TEST OK]" RESET_COLOR "\n");
	else
		printf(ROJO_T "[TEST FAILED]" RESET_COLOR "\n");
	printf("\nTEST FT_STRCPY:\n");
	strcpy(s1, "adios");
	ft_strcpy(s2, "adios");
	if (ft_strncmp(s1, s2, 5) == 0)
		printf(VERDE_T "[TEST OK]" RESET_COLOR "\n");
	else
		printf(ROJO_T "[TEST FAILED]" RESET_COLOR "\n");
	printf("\nTEST FT_STRCMP:\n");
	i = strcmp("hola", "hiasdkan");
	n = ft_strcmp("hola", "hiasdkan");
	if (i == n)
		printf(VERDE_T "[TEST OK]" RESET_COLOR "\n");
	else
		printf(ROJO_T "[TEST FAILED]" RESET_COLOR "\n");
	printf("\nTEST FT_WRITE:\n");
	i = write(1, "*(test)*\n", 9);
	n = ft_write(1, "*(test)*\n", 9);
	if (i == n)
		printf(VERDE_T "[TEST OK]" RESET_COLOR "\n");
	else
		printf(ROJO_T "[TEST FAILED]" RESET_COLOR "\n");
	printf("\nTEST FT_READ:\n");
	i = 0;
	n = 0;
	fd = open("hola", O_RDONLY);
	while (read(fd, &c, sizeof(c) != 0))
		i++;
	close(fd);
	fd = open("hola", O_RDONLY);
	while (read(fd, &c, sizeof(c) != 0))
		n++;
	close(fd);
	if (i == n)
		printf(VERDE_T "[TEST OK]" RESET_COLOR "\n");
	else
		printf(ROJO_T "[TEST FAILED]" RESET_COLOR "\n");
	printf("\nTEST FT_STRDUP:\n");
	s3 = "hola";
	s4 = "hola";
	strdup(s3);
	ft_strdup(s4);
	if (ft_strncmp(s3, s4, 4) == 0)
		printf(VERDE_T "[TEST OK]" RESET_COLOR "\n");
	else
		printf(ROJO_T "[TEST FAILED]" RESET_COLOR "\n");
}
