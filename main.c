#include <stdio.h>
#include <string.h>
char * ft_strcpy(char *dest, char *src);
// size_t	ft_strlen(const char *s);
// void		test_ft_strlen()
// {
// 	printf("\x1b[32mft_strlen :\x1b[0m\n");
// 	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
// 	printf("		\x1b[33m<string.h>\x1b[0m  %lu\n", strlen(""));
// 	printf("		\x1b[33m<libasm.h>\x1b[0m  %zu\n", ft_strlen(""));
// 	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'    '\x1b[0m\n");
// 	printf("		\x1b[33m<string.h>\x1b[0m  %lu\n", strlen("    "));
// 	printf("		\x1b[33m<libasm.h>\x1b[0m  %zu\n", ft_strlen("    "));
// 	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
// 	printf("		\x1b[33m<string.h>\x1b[0m  %zu\n", strlen("0123456789"));
// 	printf("		\x1b[33m<libasm.h>\x1b[0m  %zu\n", ft_strlen("0123456789"));
// 	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
// 	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
// 	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
// 	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
// 	printf("		\x1b[33m<string.h>\x1b[0m  %zu\n", strlen("0123456789012345678901234567890123456789012345678901234567890123456789"));
// 	printf("		\x1b[33m<libasm.h>\x1b[0m  %zu\n", ft_strlen("0123456789012345678901234567890123456789012345678901234567890123456789"));
// 	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
// 	printf("		\x1b[33m<string.h>\x1b[0m  %zu\n", strlen("01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789"));
// 	printf("		\x1b[33m<libasm.h>\x1b[0m  %zu\n", ft_strlen("01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789"));
// 	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
// 	printf("		\x1b[33m<string.h>\x1b[0m  %zu\n", strlen("0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789"));
// 	printf("		\x1b[33m<libasm.h>\x1b[0m  %zu\n", ft_strlen("0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789"));

// }
void		test_ft_strcpy()
{
	char	dst[100];

	printf("\x1b[32mft_strcpy :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  '%s'\n", strcpy(dst, ""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%s'\n", ft_strcpy(dst, ""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  '%s'\n", strcpy(dst, "toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%s'\n", ft_strcpy(dst, "toto"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  '%s'\n", strcpy(dst, "0123456789"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%s'\n", ft_strcpy(dst, "0123456789"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  '%s'\n", "SEGMENTATION FAULT");
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%s'\n", ft_strcpy(dst, NULL));
}
int main (void)
{
    
	// test_ft_strlen();
	test_ft_strcpy();
    return (0);
}