#include <stdio.h>
#include <string.h>

#define VERDE_T        "\x1b[32m"
#define ROJO_T     "\x1b[31m"
#define RESET_COLOR    "\x1b[0m"
int ft_strlen(const char *);
char *ft_strcpy(char *, const char *);
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
	int n;
	char s1[9];
	char s2[9];


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


}