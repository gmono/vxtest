//copyright (c) 2017 L.W.C.<lwc@li.cm>

#include "vxin_Trie.h"

int fun(_rbtree_node *A,_rbtree_node *B){
	return ((trie_node *)A)->c-((trie_node *)B)->c;
}

trie_node* _creat(){
	trie_node *r;
	r=(trie_node*)vxin_malloc(sizeof(trie_node));
	r->rbnode.color=0;
	r->rbnode.left=0;
	r->rbnode.right=0;
	r->rbnode.parent=0;
	return r;
}

vxin_trie* TRIE_New(){
	trie_node *t;
	vxin_trie *r;
	t=_creat();
	t->c=93;
	t->ptr=0;
	r=(vxin_trie*)vxin_malloc(sizeof(vxin_trie));
	r->root=&t->rbnode;
	return r;
}

vxin_trie* TRIE_Iterator_Next(vxin_trie* trie,char c){
	trie_node cmp;
	trie_node *r;
	cmp.c=c;
	r=(trie_node*)RBT_Search(trie->root,&cmp.rbnode,&fun);
	if(!r)return 0;
	return (vxin_trie*)(r->ptr);
}

void TRIE_Insert(vxin_trie* trie,char c,void* ptr,char isReset){
	trie_node *add;
	trie_node *r;
	if(c)ptr=(void*)TRIE_New();
	add=_creat();
	add->c=c;
	add->ptr=ptr;
	r=(trie_node*)RBT_Insert(&(trie->root),&(add->rbnode),&fun);
	if(r&&isReset){
		r->ptr=ptr;
		vxin_free((void*)add);
	}
}