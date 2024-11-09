
#include <unistd.h>
#include <sys/types.h>
#include "mini_lib.h"
#define DEBUG
#ifdef DEBUG	
#include <stdio.h>
#include <stdlib.h>

#endif
int main() {
	int *v, *b;
	char *a;
	v=mini_calloc(sizeof(int), 100);
	for(int i=0;i<100;i++){
		v[i]=i;
		#ifdef DEBUG	
		#include <stdio.h>
		#include <stdlib.h>
		printf("%d ",v[i]);
		#endif
	}
	a=mini_calloc(sizeof(char), 20);
	for(int i=0;i<20;i++){
		a[i]='a'+i;
		#ifdef DEBUG	
		#include <stdio.h>
		#include <stdlib.h>
		printf("%c ",a[i]);
		#endif
	}
	mini_free(a);
	b=mini_calloc(sizeof(int), 5);
	for(int i=0;i<5;i++){
		b[i]=i;
		#ifdef DEBUG	
		#include <stdio.h>
		#include <stdlib.h>
		printf("%d ",b[i]);
		#endif
	}
	#ifdef DEBUG	
	#include <stdio.h>
	#include <stdlib.h>
	printf("\nv: %p\na: %p\nb: %p\nsize a:%ld\nsize b:%ld\n", v,a,b, 20*sizeof(char), 5*sizeof(int));
	#endif
	mini_printf("abcde");
	mini_exit();
}

