#ifndef MINI_LIB_H
#define MINI_LIB_H
//partie 1
void* mini_calloc(int size_element, int number_element);
void mini_free(void* ptr);
void mini_exit();
struct malloc_element{
	void * zone;
	int taille;
	struct malloc_element * next_malloc;
	int status;
	};
//partie 2
#define BUF_SIZE 1024
void mini_printf(char*);
#endif

