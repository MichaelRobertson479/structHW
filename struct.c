#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct monster { char *name; int atk; };

struct monster example() {

	time_t t;
	srand((unsigned) time(&t));

	char* names[] = {"blue-eyes white dragon","dark magician","relinquished"};
	
	struct monster ex;

	ex.name = names[rand() % 3];	
	ex.atk = ((rand() % 3001) / 100) * 100;

	return ex;	
}

int print (struct monster mon) {

	printf("name:%s\natk:%d\n",mon.name,mon.atk);

	return 0;
}

int main() {

	struct monster mon = example();

	print(mon);

	return 0;
}