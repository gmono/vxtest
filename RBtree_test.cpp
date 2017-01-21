#include <stdio.h>
#include <time.h>
#include "vxin_RBtree.h"

typedef struct CharBRTree{
	_rbtree_node node;
    unsigned int c;
	int date;
}CharBRTree;

CharBRTree* New(){
	CharBRTree* r;
	r=(CharBRTree*)vxin_malloc(sizeof(CharBRTree));
	r->node.parent=0;
	r->node.left=0;
	r->node.right=0;
	r->node.color=0;
	return r;
}


int fun(_rbtree_node *A,_rbtree_node *B){
	return (((CharBRTree*)A)->c)-(((CharBRTree*)B)->c);
}
#include <map>
#include <unordered_map>
using std::map;
using std::pair;
using std::unordered_map;
#define mymap map
mymap<unsigned int,int> testmap;

int main(){
	CharBRTree *root;
	CharBRTree cmp;
	CharBRTree *insert;
	_rbtree_node *rootnode;
	_rbtree_node *r;
	clock_t cloc;
    unsigned int i;
	root=New();
	root->c=1;
	root->node.color=RBT_COLOR_BLACK;
	rootnode=&root->node;
	srand(time(0));
    //随机数池生成法
    //双池
    unsigned int *rand1=(unsigned int *)malloc(sizeof(int)*65536);
    unsigned int *rand2=(unsigned int *)malloc(sizeof(int)*65536);
    for(i=0;i<65536;++i)
    {
        rand1[i]=((unsigned int)rand())%65537;//0-65536
    }
    for(i=0;i<65536;++i)
    {
        rand2[i]=((unsigned int)rand())%65537;//0-65536
    }
    int pr=0;//移位值
    int ptr=0;//基础值  rptr=(ptr+pr)%65536  rand1[ptr]*rand2[rptr]-1 =randnum
    //stl测试
	cloc=clock();
    for(i=1;i<=10000000;i++){
        auto rptr=(ptr+pr)%65536;
        auto num=rand1[ptr]*rand2[rptr]-1;
        ptr++;
        if(ptr==65536) {ptr=0;pr++;}
        testmap.insert(pair<unsigned int,int>(num,(int)num));
//        insert=New();
//        insert->node;
//        insert->c=num;
//        insert->date=(int)(insert->c);
//        r=RBT_Insert(&rootnode,&insert->node,&fun);
//        if(r){
//            free(insert);
//            ((CharBRTree *)r)->c=insert->c;
//            ((CharBRTree *)r)->date=insert->date;
//        }

	}
	printf("time:%d\n",clock()-cloc);
	while(1){
        int a,b;
        scanf("%d %d",&a,&b);
        i=rand1[a]*rand2[b]-1;
        cmp.c=i;
        auto cnum=i;//stl测试用的数值

        bool isok=false;
        int tnum=0;
		cloc=clock();
		for(i=1;i<=100000000;i++){
//            r=RBT_Search(rootnode,&cmp.node,&fun);
            auto ptr=testmap.find(cnum);
            if(ptr!=testmap.end())
            {
                tnum=ptr->second;
                isok=true;
            }

		}
        printf("time:%d\n",clock()-cloc);
        if(!isok){
            printf("未找到\n");
            continue;
        }
        printf("data:%d",tnum);
/*        if(!r){
            printf("未找到\n");
            continue;
        }
        printf("date:%d\n",((CharBRTree *)r)->date)*/;

	}
}
