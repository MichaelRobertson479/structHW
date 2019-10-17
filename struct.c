#include <stdlib.h>
#include <stdio.h>

struct monster { char *name; int atk; };

int main() {

	struct monster blue_eyes;
	blue_eyes.name = "blue eyes white dragon";
	blue_eyes.atk = 3000;

	printf("name:%s\natk:%d\n",blue_eyes.name,blue_eyes.atk);

	return 0;
}