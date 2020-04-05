#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

int main() {
	long int a = syscall(335);
	printf("Now you know whether you make it or not\n");
	return 0;
}