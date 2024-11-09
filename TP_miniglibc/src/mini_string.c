#include "mini_lib.h"
#include <unistd.h>
#include <sys/types.h>
char* buffer;
int ind =-1;
void mini_printf(char* s){
	if (ind ==-1) {
		buffer = mini_calloc(sizeof(char),BUF_SIZE);
		ind=0;
	}
	
	int i=0;
	while(s[i] != '\0'){
		buffer[ind]= s[i];
		if (ind >= BUF_SIZE || s[i]== '\n'){
			write(2, buffer, BUF_SIZE);
			buffer = mini_calloc(sizeof(char),BUF_SIZE);
			ind=0;
		}
		ind++;i++;
	}
}
