#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct monster { char *name; int atk; };

struct monster example() {

	srand(time(0));

	char* names[] = {"blue-eyes white dragon","dark magician","relinquished"};
	
	struct monster ex;

	ex.name = names[rand() % 3];	
	ex.atk = ((rand() % 3100) / 100) * 100;

	return ex;	
}

int print (struct monster mon) {

	printf("name:%s\natk:%d\n",mon.name,mon.atk);

	return 0;
}

int modify (struct monster *mon) {

	(*mon).name = "changed";
	(*mon).atk = 42;

	return 0;
}

int main() {

	struct monster mon = example();
	print(mon);

	modify(&mon);	
	print(mon);

	return 0;
}