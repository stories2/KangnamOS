#include "main.h"

int main() {
	cout << "Hello, goorm!" << endl;
	
	char *argv[] ={"ls", "-al", NULL};
	
	execvp(argv[0], argv);
	
	return 0;
}