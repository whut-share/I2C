#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
int main(int argc, char *argv[])
{
	const char *modname = argv[1];
	int ret = -1;
	int maxtry = 10;
	while (maxtry-- > 0) {
		ret = delete_module(modname, O_NONBLOCK | O_EXCL);//系统调用sys_delete_module
	if (ret < 0 && errno == EAGAIN)
		usleep(500000);
	else
		break;
	}
	if (ret != 0)
	printf("Unable to unload driver module \"%s\": %s\n",
	modname, strerror(errno));

}