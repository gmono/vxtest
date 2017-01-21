//copyright (c) 2017 L.W.C.<lwc@li.cm>

#ifndef VXIN_REtree
	#define VXIN_REtree 1
	
	#include "vxin.h"
	
	typedef struct _rbtree_node{
		struct _rbtree_node *parent;
		struct _rbtree_node *left;
		struct _rbtree_node *right;
		char color;
	} _rbtree_node;
	
	#define RBT_COLOR_RED 1
	#define RBT_COLOR_BLACK 0
	
	_rbtree_node* RBT_Search(_rbtree_node *root,_rbtree_node* ptr,\
								int (*fun)(_rbtree_node* ptr,_rbtree_node *cmp) \
							);
	_rbtree_node* RBT_Insert(_rbtree_node **root,_rbtree_node *node,\
							int (*fun)(_rbtree_node *cmpA,_rbtree_node *cmpB)\
						);
	
#endif