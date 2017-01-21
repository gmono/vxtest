//copyright (c) 2017 L.W.C.<lwc@li.cm>
#ifndef VXIN_MAIN
	#define VXIN_MAIN 1
	
		#include <malloc.h>
	
		//确定当前成员变量,在结构体中偏移量的宏
		#define offsetof(type, member) ((size_t) &((type*)0)->member)

		//根据成员变量,找包含他的结构体指针
		#define container_of(ptr, type, member) \
		({const typeof( ((type *)0)->member ) *__mptr = (ptr); \
		(type *)( (char *)__mptr - offsetof(type,member) );})
		
		#define vxin_malloc(x) malloc(x)
		#define vxin_free(x) free(x)
		#define vxin_realloc(x,y) realloc(x,y)
		
#endif