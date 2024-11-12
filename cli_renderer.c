#include <stdio.h>
#include <unistd.h>
#include <string.h>

int width = 20;
int height = 20;
char buffer[(20)*(20)];
char luminosity[] = {' ', '`', '-', '*', '+', '?', 432, '@', 219};


//takes a file*
//returns a tri array
float** loadObject(char* fileName){
	FILE* fp;
	char buff[1024];
	fp = fopen((const char*) fileName, "r");	

	while(fgets(buff, 1024, fp) != NULL){
		printf("linebuff: %s\n", buff);		 	
	}

	fclose(fp);
}


int main(){
	printf("cli-renderer.c main\n");
	printf("test mode:\n");


	char* file = "cube.obj";
	loadObject(file);


	return 0;
}
