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

void print (struct monster mon) {

	printf("name:%s\natk:%d\n",mon.name,mon.atk);
}

void modify (struct monster *mon) {

	(*mon).name = "changed";
	(*mon).atk = 42;
}

int main() {

	printf("Creating + Printing Example Monster:\n");
	struct monster mon = example();
	print(mon);

	printf("Modifying + Printing Above Monster:\n");
	modify(&mon);	
	print(mon);

	return 0;
}