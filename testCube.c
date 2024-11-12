#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <>

int width = 20;
int height = 20;
char buffer[(20)*(20)];
char luminosity[] = {' ', '`', '-', '*', '+', '?', 432, '@', 219};



void bufferCube(){
	for(int i = 5; i < height - 5; i++){
		for(int j = 5; j < width - 5; j++){
			buffer[(i * width) + j] = luminosity[5];
		}
	}
}


int drawCube(){
	int i;
	//draw frame here
	printf("\x1b[2J"); //clear screen

	while(1){
	
		printf("\x1b[H"); //move cursor to top of screen
		
		memset(buffer, 32, width * height);

		bufferCube();

		//write to buffers with memset. dont bother clearing every time becuase you will just overwrite with blank characters

		for(i = 0; i < width * height; i++){
			if((i % width) != 0){
				putchar(buffer[i]);
			}else{
				putchar(10); //line feed
			}
		}
		usleep(100000);
	}
	printf("cube!\n");
	return 0;
}

int main(){
	return drawCube();
}
