#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "./includes/libasm.h"

#define FT_STRCPY_BUF_SIZE (1 << 12)

void		test_ft_strlen()
{
	printf("\x1b[32m\nft_strlen :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %lu\n", strlen(""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zu\n", ft_strlen(""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'    '\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %lu\n", strlen("    "));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zu\n", ft_strlen("    "));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %zu\n", strlen("0123456789"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zu\n", ft_strlen("0123456789"));
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
}

void		test_ft_strcpy()
{
	char	dst[100];
	char buf[FT_STRCPY_BUF_SIZE] = {0};
	printf("\x1b[32m\nft_strcpy :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  '%s'\n", strcpy(dst, ""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%s'\n", ft_strcpy(dst, ""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  '%s'\n", strcpy(dst, "toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%s'\n", ft_strcpy(dst, "toto"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  '%s'\n", strcpy(dst, "0123456789"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%s'\n", ft_strcpy(dst, "0123456789"));
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  '%s'\n", "SEGMENTATION FAULT");
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%s'\n",  "SEGMENTATION FAULT");
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'the\\0hidden'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  '%s'\n", strcpy(dst, "the\0hidden"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%s'\n", ft_strcpy(dst, "the\0hidden"));
	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'\"Être ange c’est étrange\" de \
Jacques PRÉVERT, recueil : \"Fatras\".\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  '%s'\n", strcpy(buf, "Être Ange C’est Étrange Dit l’Ange. \
Être Âne C’est étrâne Dit l’Âne. Cela ne veut rien dire Dit l’Ange \
en haussant les ailes Pourtant Si étrange veut dire quelque chose \
étrâne est plus étrange qu’étrange dit l’Âne Étrange est ! \
Dit l’Ange en tapant du pied Étranger vous-même Dit l’Âne Et il s’envole."));
printf("		\x1b[33m<libasm.h>\x1b[0m  '%s'\n", ft_strcpy(buf, "Être Ange C’est Étrange Dit l’Ange. \
Être Âne C’est étrâne Dit l’Âne. Cela ne veut rien dire Dit l’Ange \
en haussant les ailes Pourtant Si étrange veut dire quelque chose \
étrâne est plus étrange qu’étrange dit l’Âne Étrange est ! \
Dit l’Ange en tapant du pied Étranger vous-même Dit l’Âne Et il s’envole."));
}

void		test_ft_strcmp()
{
	// char	dst[100];

	printf("\x1b[32m\nft_strcmp :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  '%d'\n", strcmp("", ""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%d'\n", ft_strcmp("", ""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'tota/toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  '%d'\n", strcmp("tota", "toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%d'\n", ft_strcmp("tota", "toto"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'toto/tota'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  '%d'\n", strcmp("toto", "tota"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%d'\n", ft_strcmp("toto", "tota"));
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'0123456789/0123456789'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  '%d'\n", strcmp("0123456789", "0123456789"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%d'\n", ft_strcmp("0123456789", "0123456789"));
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  '%s'\n", "SEGMENTATION FAULT");
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%s'\n", "SEGMENTATION FAULT");
	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'\\xfe\\xff/\\xfe'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  '%d'\n", strcmp("\xfe\xff", "\xfe"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%d'\n", ft_strcmp("\xfe\xff", "\xfe"));
	printf("	\x1b[34m[7]\x1b[0m \x1b[36m'\\xfe/\\xfe\\xff'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  '%d'\n", strcmp("\xfe", "\xfe\xff"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%d'\n", ft_strcmp("\xfe", "\xfe\xff"));
	printf("	\x1b[34m[8]\x1b[0m \x1b[36m'tot/tota'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  '%d'\n", strcmp("tot", "tota"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%d'\n", ft_strcmp("tot", "tota"));
	printf("	\x1b[34m[9]\x1b[0m \x1b[36m'tota/tot'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  '%d'\n", strcmp("tota", "tot"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%d'\n", ft_strcmp("tota", "tot"));
}
void		test_ft_write()
{
	int			fd;
	char		buffer[100];

	printf("\x1b[32mft_write :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'1' '' '0'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "", 0));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "", 0));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'1' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "toto", 4));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'1' 'toto' '2'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "toto", 2));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "toto", 2));
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'1' 'toto' '40'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "toto", 40));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "toto", 40));
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'1' 'NULL' '6'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - errno = %d\n", write(1, NULL, 6), errno);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - errno = %d\n", ft_write(1, NULL, 6), errno);
	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'0' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(0, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(0, "toto", 4));
	printf("	\x1b[34m[7]\x1b[0m \x1b[36m'1' 'the\\0hidden' '10'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  '%zd'\n", write(1, "the\0hidden", 10));
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%zd'\n", ft_write(1, "the\0hidden", 10));
	printf("	\x1b[34m[9]\x1b[0m \x1b[36m'1' 'the\\0hidden' '3'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  '%zd'\n", write(1, "the\0hidden", 3));
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%zd'\n", ft_write(1, "the\0hidden", 3));
	printf("	\x1b[34m[10]\x1b[0m \x1b[36m'1' 'the\\0hidden' '5'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  '%zd'\n", write(1, "the\0hidden", 5));
	printf("		\x1b[33m<libasm.h>\x1b[0m  '%zd'\n", ft_write(1, "the\0hidden", 5));
	printf("	\x1b[34m[11]\x1b[0m \x1b[36m'42' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - errno = %d\n", write(42, "toto", 4), errno);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - errno = %d\n", ft_write(42, "toto", 4), errno);
	printf("	\x1b[34m[12]\x1b[0m \x1b[36m'-1' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - errno = %d\n", write(-1, "toto", 4), errno);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - errno = %d\n", ft_write(-1, "toto", 4), errno);
	fd = open("ft_write_test", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	printf("	\x1b[34m[13]\x1b[0m \x1b[36m'open(\"ft_write_test\", O_WRONLY | O_TRUNC | O_CREAT)' '<whichlib.h> toto' '15'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(fd, "<unistd.h> toto", 15));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(fd, "<libasm.h> toto", 15));
	close(fd);
	fd = open("ft_write_test", O_RDONLY);
	read(fd, buffer, 15);
	printf("		\x1b[33m<unistd.h>\x1b[0m buffer = %s\n", buffer);
	read(fd, buffer, 15);
	printf("		\x1b[33m<libasm.h>\x1b[0m buffer = %s\n", buffer);
	close(fd);
	remove("ft_write_test");
}

void		test_ft_read()
{
	int			fd;
	char		buffer[100];
	char		show[100];
	ssize_t		ret;
	
	printf("\x1b[32mft_read:\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'open(\"main.c\", O_RDONLY)' '' '0'\x1b[0m\n");
	fd = open("main.c", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	fd = open("main.c", O_RDONLY);
	ret = ft_read(fd, buffer, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'open(\"Makefile\", O_RDONLY)' '' '50'\x1b[0m\n");
	fd = open("Makefile", O_RDONLY);
	ret = read(fd, buffer, 50);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 50));
	close(fd);
	fd = open("Makefile", O_RDONLY);
	ret = ft_read(fd, buffer, 50);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 50));
	close(fd);
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'open(\"dontexist\", O_RDONLY)' '' '10'\x1b[0m\n");
	fd = open("dontexist", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - errno = %d - %s\n", ret, errno, strncpy(show, buffer, 10));
	close(fd);
	fd = open("dontexist", O_RDONLY);
	ret = ft_read(fd, buffer, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - errno = %d - %s\n", ret, errno, strncpy(show, buffer, 10));
	close(fd);
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'open(\"main.c\", O_RDONLY)' 'NULL' '10'\x1b[0m\n");
	fd = open("main.c", O_RDONLY);
	ret = read(fd, NULL, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd errno = %d\n", ret, errno);
	close(fd);
	fd = open("main.c", O_RDONLY);
	ret = ft_read(fd, NULL, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd errno = %d\n", ret, errno);
	close(fd);
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'42' '' '10'\x1b[0m\n");
	ret = read(42, buffer, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - errno = %d - %s \n", ret, errno, strncpy(show, buffer, 10));
	ret = ft_read(42, buffer, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - errno = %d - %s\n", ret, errno, strncpy(show, buffer, 10));
	close(fd);
	fd = open("empty_file", O_RDONLY | O_TRUNC | O_CREAT, 0777);
	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'open(\"empty_file\", O_RDONLY | O_TRUNC | O_CREAT, 0777)' '' '10'\x1b[0m\n");
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	ret = ft_read(fd, buffer, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	remove("empty_file");
}

void		test_ft_strdup()
{
	char *dest;
	char *dest2;

	printf("\x1b[32mft_strdup :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", dest = strdup(""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", dest2 = ft_strdup(""));
	free(dest);
	free(dest2);
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", dest = strdup("toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", dest2 = ft_strdup("toto"));
	free(dest);
	free(dest2);
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", dest = strdup("0123456789"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", dest2 = ft_strdup("0123456789"));
	free(dest);
	free(dest2);
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", "SEGMENTATION FAULT strdup(NULL)");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", "SEGMENTATION FAULT ft_strdup(NULL)");
}


int main (void)
{
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_strcmp();
    test_ft_write();
	test_ft_read();
	test_ft_strdup();
	return (0);
}