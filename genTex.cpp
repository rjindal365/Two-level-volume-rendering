#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if(argc < 5) {
		exit(-1);
	}
	char* filename = argv[1];
	int r,g,b;
	int a, i;

	r = atoi(argv[2]);
	g = atoi(argv[3]);
	b = atoi(argv[4]);
	char str[200] = "";
	strcat(str,filename);
	strcat(str, ".raw");
	//printf("d = %u \n",d);
	FILE *imageFile = fopen(str, "wb");
	if(imageFile) {
		puts("File open: successfull.");
	} else {
		puts("File open: Failed.");
		puts("Exiting.");
		exit(1);
	}
	char data[1024];

	for(i=0; i<256; i++) {
		a = (i<<2);
		data[a]   = (i*r); //r ? i:0;
		data[a+1] = (i*g);
		data[a+2] = (i*b);

		data[a+3] = (i<128)? 5 : 64;
	}
	fwrite(data, 1, 1024, imageFile);
	fclose(imageFile);
	return 0;
}
