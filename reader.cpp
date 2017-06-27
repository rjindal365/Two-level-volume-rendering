#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
	if(argc < 5) {
		exit(-1);
	}
	char* filename = argv[1];
	int w,h,d;
	int i, r, c;
	w = atoi(argv[2]);
	h = atoi(argv[3]);
	d = atoi(argv[4]);
	
	//printf("d = %u \n",d);
	FILE *imageFile = fopen(filename, "rb");
	if(imageFile) {
		puts("File open: successfull.");
	} else {
		puts("File open: Failed.");
		puts("Exiting.");
		exit(1);
	}
	
	unsigned char color[10];
	int offset, count, id;
	//char ch = 'a';
	
	while(1) {
		//ch = getch();
		puts("Enter <img> <row> <col> <pixels>: [-1 for exit]");
		scanf("%d", &i);
		scanf("%d", &r);
		scanf("%d", &c);
		scanf("%d", &count);
		if(-1 == i) {
			puts("Exiting.");
			break;
		}
		offset =  (i*w*h) + ( r*w ) + c;
		fseek(imageFile, offset, 0);
		fread(color, 1, count, imageFile);
		printf("color = ");
		id = 0;
		while(count--) {
			printf("%u, ", color[id++]);
		}
		puts("");
	}

	
	
	
	fclose(imageFile);
}
