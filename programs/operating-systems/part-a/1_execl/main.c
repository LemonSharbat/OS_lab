#include <stdio.h>
#include <unistd.h>

int main() {
	char script_name[20];

	printf("Enter script name: ");
	scanf("%s", script_name);

	if (execl("/bin/sh", "sh", script_name, NULL) == -1) {
		perror("Error, program not found!\n");
		return 1;
	}

	return 0;
}
