#include<stdio.h>
#include<string.h>
int main()
{
	char buf[102] = {};
	int i = 0;
	const char *bar = "|/-\\";
	for (; i < 101; i++)
	{
		if (i <= 20)
		{
			printf("[%d%%][%c][\033[40;31m%s\033[0m]\r", i, bar[i % 4], buf);
		}
		else if (i <= 40)
		{
			printf("[%d%%][%c][\033[40;32m%s\033[0m]\r", i, bar[i % 4], buf);
		}
		else if (i <= 60)
		{
			printf("[%d%%][%c][\033[40;33m%s\033[0m]\r", i, bar[i % 4], buf);
		}
		else if (i <= 80)
		{
			printf("[%d%%][%c][\033[40;34m%s\033[0m]\r", i, bar[i % 4], buf);
		}
		else if (i <= 80)
		{
			printf("[%d%%][%c][\033[40;35m%s\033[0m]\r", i, bar[i % 4], buf);
		}
		else
		{
			printf("[%d%%][%c][\033[40;37m%s\033[0m]\r]", i, bar[i % 4], buf);
		}
		buf[i] = '#';
		fflush(stdout);
		usleep(500 * 1000);
	}
	printf("\n");
	return 0;
}
