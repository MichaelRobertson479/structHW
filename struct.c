#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct monster { int atk; char name[]; };

struct monster example() {

	char alph[26] = "abcdefghijklmnopqrstuvwxyz";
	
	struct monster ex;
	
	//int a = rand();
	//int b = rand();

	//printf("alph1:%s\n",alph[1]);
	ex.name="example";
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