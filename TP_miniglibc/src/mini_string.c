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

int mini_scanf(char* buffer, int size_buffer){
	int count = read(STDIN_FILENO, buffer, size_buffer - 1);
	buffer[count]= '\0';
	return count;
}

int mini_strlen(char* s){
	int i=0;
	while(s[i++] != '\0');
	return i;
}

int mini_strcpy(char* s, char *d){
	if (s == NULL || d == NULL)
		return -1;
	int i=0;
	while(s[i] != '\0'){
		d[i]=s[i];
		i++;
	}
	return i;
}

int mini_strncpy(char* s, char *d, int n){
	if (s == NULL || d == NULL || n<=0)
		return -1;
	int i=0;
	while(s[i] != '\0' && i<n){
		d[i]=s[i];
		i++;
	}
	d[i]='\0';
	return i;
}

int mini_strcmp(char* s1, char* s2){
	if (s1 == NULL || s2 == NULL)
		mini_exit();
	if (*(s1)==*(s2))
		return (*s1 == '\0' && *s2 == '\0') ? 0 : mini_strcmp(s1+1,s2+1);
	return  (*(s1)<*(s2))? -1 : 1;
}














