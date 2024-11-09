#include "mini_lib.h"
#include <unistd.h>
#include <sys/types.h>
struct malloc_element* malloc_list;
void* mini_calloc(int size_element, int number_element){
	  if (malloc_list== NULL)
	  	malloc_list= sbrk(sizeof(struct malloc_element));
	  struct malloc_element* p;
	  p = malloc_list;
	  if (malloc_list!= NULL){
		  while (p->next_malloc != NULL){
		  	p = p->next_malloc;
		  	if ( size_element*number_element <= p->taille && p->status==0){
		  		p->status=1;
		  		return p->zone;
		  	}
		  }
	  }
	  void *v;
	  v = sbrk(size_element*number_element);
	  char * tmp = (char *)v;
	  for (int i=0;i<size_element*number_element;i++) tmp[i]= '\0';
	  
	  struct malloc_element* m= sbrk(sizeof(struct malloc_element));
	  m->zone = v;
	  m->taille = size_element*number_element;
	  m->status = 1;
	  m->next_malloc = NULL; 
	  p->next_malloc = m;
	  return v;
}


void mini_free(void* ptr){
	  struct malloc_element* p;
	  p = malloc_list;
	  while (p->next_malloc != NULL && p->zone != ptr) p = p->next_malloc;
	  p->status=0;
}

void mini_exit(){
	extern char* buffer;
	extern int ind;
	write(2, buffer, BUF_SIZE);
	buffer = mini_calloc(sizeof(char),BUF_SIZE);
	ind=-1;
	_exit(0);
}













