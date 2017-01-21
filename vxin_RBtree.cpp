//copyright (c) 2017 L.W.C.<lwc@li.cm>

#include "vxin_RBtree.h"


void _insert_fix_0(_rbtree_node *node,_rbtree_node **root);

_rbtree_node* RBT_Search(_rbtree_node *root,_rbtree_node* ptr,\
								int (*fun)(_rbtree_node* ptr,_rbtree_node *cmp) \
							){
	int r;
	while(root){
		r=fun(ptr,root);
		if(r>0)
			root=root->right;
		else if(r<0)
			root=root->left;
		else return root;
	}
	return 0;
}

_rbtree_node* RBT_Insert(_rbtree_node **root,_rbtree_node *node,\
							int (*fun)(_rbtree_node *cmpA,_rbtree_node *cmpB)\
						){
	_rbtree_node *ior;
	_rbtree_node *ret=0;
	int r;
	ior=*root;
	node->color=RBT_COLOR_RED;
	if(ior){
		do{
			r=fun(node,ior);
			if(r>0){
				if(!(ior->right)){
					ior->right=node;
					node->parent=ior;
					break;
				}
				else
				{
					ior=ior->right;
					continue;
				}
			}
			else if(r<0){
				if(!(ior->left)){
					ior->left=node;
					node->parent=ior;
					break;
				}
				else
				{
					ior=ior->left;
					continue;
				}
			}
			else 
			{
				return ior;
			}
		}while(ior);
	}
	else
		*root=node;
	_insert_fix_0(node,root);
	return ret;
}

void _left_rotate(_rbtree_node *node,_rbtree_node **root){
	_rbtree_node *y;
	y=node->right;
	node->right=y->left;
	if(y->left)y->left->parent=node;
	y->parent=node->parent;
	if(!node->parent){
		*root=y;}
	else if (node==node->parent->left)
		node->parent->left=y;
	else
		node->parent->right=y;
	y->left=node;
	node->parent=y;
}

void _right_rotate(_rbtree_node *node,_rbtree_node **root){
	_rbtree_node *y;
	y=node->left;
	node->left=y->right;
	if(y->right)y->right->parent=node;
	y->parent=node->parent;
	if(!node->parent)
		*root=y;
	else if (node==node->parent->left)
		node->parent->left=y;
	else
		node->parent->right=y;
	y->right=node;
	node->parent=y;
}

//加了叔叔为空，防蹦
char uncle_color(_rbtree_node *node,_rbtree_node **root){
	_rbtree_node *tmp;
	if(node==node->parent->left)
		if(node->parent->parent){
			if(tmp=node->parent->parent->right)
				return tmp->color;
			else
				return RBT_COLOR_BLACK;
		}
		else
		{
			if(tmp=(*root)->right)
				return tmp->color;
			else
				return RBT_COLOR_BLACK;
		}
	else
		if(node->parent->parent){
			if(tmp=node->parent->parent->left)
				return tmp->color;
			else
				return RBT_COLOR_BLACK;
		}
		else
		{
			if(tmp=(*root)->left)
				return tmp->color;
			else
				return RBT_COLOR_BLACK;
		}
}

void _insert_fix_3(_rbtree_node *node,_rbtree_node **root){
	//情况3.当前节点的父节点是红色,叔叔节点是黑色，当前节点是其父节点的左子
	
	//父节点变为黑色，祖父节点变为红色，在祖父节点为支点右旋
	
	node->parent->color=RBT_COLOR_BLACK;
	node->parent->parent->color=RBT_COLOR_RED;
	
	_right_rotate(node->parent->parent,root);
	
}

void _insert_fix_2(_rbtree_node *node,_rbtree_node **root){
	//情况2.当前节点的父节点是红色,叔叔节点是黑色，当前节点是其父节点的右子
	if(node==node->parent->right)
		
		//当前节点的父节点做为新的当前节点，以新当前节点为支点左旋。
		
		_left_rotate(node->parent,root);
		
	else
		_insert_fix_3(node,root);
}

void _insert_fix_1(_rbtree_node *node,_rbtree_node **root){

		/*
		情况1.当前结点的父结点是红色
		且祖父结点的另一个子结点（叔叔结点）是红色
		*/
	if(node->parent->color==RBT_COLOR_RED){
		if(uncle_color(node,root)==RBT_COLOR_RED){
		
			/*
			将当前节点的父节点和叔叔节点涂黑，祖父结
			点涂红，把当前结点指向祖父节点，从新的当
			前节点重新开始算法
			*/
			
			node->parent->color=RBT_COLOR_BLACK;
			if(node==node->parent->left)
				node->parent->parent->right->color=RBT_COLOR_BLACK;
			else
				node->parent->parent->left->color=RBT_COLOR_BLACK;
			_insert_fix_0(node->parent->parent,root);
		}
		else
			_insert_fix_2(node,root);
	}
}

void _insert_fix_0(_rbtree_node *node,_rbtree_node **root){
	if(node->parent==0)//插入的是根结点
		node->color=RBT_COLOR_BLACK; //直接把此结点涂为黑色
	else
		_insert_fix_1(node,root);
}