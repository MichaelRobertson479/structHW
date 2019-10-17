#include <stdlib.h>
#include <stdio.h>

struct monster { char *name; int atk; };

struct monster example() {

	char *alph = "abcdefghijklmnopqrstuvwxyz";
	
	struct monster ex;
	
	ex.name = alph[rand()] + alph[rand()];
	ex.atk = rand();

	return ex;	
}

int print (struct monster mon) {

	printf("name:%s\natk:%d\n",mon.name,mon.atk);

	return 0;
}

int main() {
	
	print(example());

	return 0;
}