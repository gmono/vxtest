//copyright (c) 2017 L.W.C.<lwc@li.cm>

#ifndef VXIN_Trie
	#define VXIN_Trie 1
	
	#include "vxin.h"
	#include "vxin_RBtree.h"
	
	typedef struct trie_node{
		_rbtree_node rbnode;
		char c;
		void *ptr;
	}trie_node;
	
	typedef struct vxin_trie{
		_rbtree_node *root;
	}vxin_trie;
	
	vxin_trie* TRIE_New();
	vxin_trie* TRIE_Iterator_Next(vxin_trie* trie,char c);
	void TRIE_Insert(vxin_trie* trie,char c,void* ptr,char isReset);
	
#endif