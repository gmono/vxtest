#include <stdio.h>
#include <time.h>
#include "vxin_Trie.h"

typedef struct fanyi{
	long start;
	long end;
} fanyi;

void printFanyi(fanyi *fy,FILE *f){
	fseek(f,fy->start,SEEK_SET);
	while(ftell(f)<=fy->end){
		printf("%c",fgetc(f));
	}
}

int main(){
	vxin_trie *trie;
	vxin_trie *i_trie;
	vxin_trie *r;
	FILE *f;
	int ch;
	char in_flag=0;
	fanyi* save;
	clock_t c;
	
	printf("Loading...\n");
	c=clock();
	i_trie=trie=TRIE_New();
	f=fopen("cd.txt","rt");
	
	save=(fanyi*)malloc(sizeof(save));
	
	
	
	while(!feof(f)){
		ch=fgetc(f);
		//printf("%c",(char)ch);
		if((char)ch=='='){
			save->start=ftell(f);
			in_flag=1;
			continue;
		}
		if((char)ch=='\n'){
		//printf("[换行]\n");
			in_flag=0;
			save->end=ftell(f)-1;
			TRIE_Insert(i_trie,0,(void*)save,1);
			i_trie=trie;
			save=(fanyi*)malloc(sizeof(save));
			continue;
		}
		if(in_flag)continue;
		r=TRIE_Iterator_Next(i_trie,ch);
		if(!r){
			TRIE_Insert(i_trie,ch,0,1);
			r=TRIE_Iterator_Next(i_trie,ch);
		}
		i_trie=r;
		
	}
	c=clock()-c;
	printf("time:%d\n",c);
	
	while(1){
		printf("\n请输入要查询的单词>");
		fflush(stdin);
		i_trie=trie;//归位迭代器
		ch=getchar();
		c=clock();
		do{
			r=TRIE_Iterator_Next(i_trie,ch);
			if(!r){
				printf("未找到= =\n");
				break;
			}
			i_trie=r;
		}while((ch=getchar())!='\n');
		if(r){
			r=TRIE_Iterator_Next(i_trie,0);
			//printf("[3=%p]",r);
			if(!r){
				printf("未找到= =\n");
				continue;
			}
			c=clock()-c;
			printf("\ntime:%d\n",c);
			printf("\n");
			printFanyi((fanyi*)r,f);
		}
	}
}