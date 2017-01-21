//copyright (c) 2017 L.W.C.<lwc@li.cm>
#ifndef VXIN_MAIN
	#define VXIN_MAIN 1
	
		#include <malloc.h>
	
		//ȷ����ǰ��Ա����,�ڽṹ����ƫ�����ĺ�
		#define offsetof(type, member) ((size_t) &((type*)0)->member)

		//���ݳ�Ա����,�Ұ������Ľṹ��ָ��
		#define container_of(ptr, type, member) \
		({const typeof( ((type *)0)->member ) *__mptr = (ptr); \
		(type *)( (char *)__mptr - offsetof(type,member) );})
		
		#define vxin_malloc(x) malloc(x)
		#define vxin_free(x) free(x)
		#define vxin_realloc(x,y) realloc(x,y)
		
#endif