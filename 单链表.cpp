                                                                                                                                                                                                                                                                                                                                                                  
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                                                                                                                                                 
 typedef int DataType;								/*单链表数据类型*/ 
 typedef struct node{
 	DataType data;								/*单链表元素*/ 
 	struct node*next;
 }LNode,*LinkList;
 
 void wait()
 {
 	printf("\n请按任意键...\n");
 	getch();
 	
 }
 int go_on()
 {
 	int flag=1;
 	char choice;
 	while(1){
	 printf("\n继续吗？[y/n]");
	 choice=getch();
	 if(choice=='Y'||choice=='y')
	 break;
	 else if(choice=='N'||choice=='n'){
	 	flag=0;
	 	break;
	 }
 }return(flag); 
 }
 /*初始化，构造一个空顺序表*/
 void Init_LinkList(LinkList *L)
 { 	
 	*L=(LNode*)malloc(sizeof(LNode));
 	if(*L==NULL){
 		printf("\n内存分配失败.\n");
 		exit(-1);
	 }
 	(*L)->next=NULL;	
 }
 /*判断带头结点单链表是否为空*/ 
int Empty_LinkList(LinkList L)
 {
 	if(L->next==NULL)
 		return(1);
 		else
 		return(0);
	 }
	 /*求带头结点单链表长度*/
	 int Length_LinkList(LinkList L)
	 {
	 	LNode *p=L->next;
	 	int k;
	 	k=0;
	 	while(p!=NULL){
	 		k++;
	 		p=p->next;
		 }
		 return(k);
	  } 
void Length(LinkList L)
{
	int k;
	k=Length_LinkList(L);
	printf("\n表长:%d\n",k);	
	  }  
LNode *Locatei_LinkList (LinkList L,int i)
{
	LNode *p=L;
	int j=0;
	while(p->next!=NULL&&j<i){
		j++;
		p=p->next;
	}
	if(j==i)
	return(p);
	else
	return(NULL);
}
  /*按值查找元素，在带头结点链表中查找元素值为x的第1个元素，查找成功，返回值向x所在结点的指针，*k返回其位置序号，*/
LNode *Locatex_LinkList (LinkList L,int x,int *k)
{
	LNode *p=L->next;
	int j=1;
	while(p!=NULL&&p->data!=x){
		j++;
		p=p->next;
	}	
	*k=j;
	return (p);
 } 
 void Locatei(LinkList L)
 {
 	LNode*p;
 	int flag=1,i;
 	
 	while(flag){
	 
 	printf("\n请输入要查找的元素的位置；");
	 scanf("%d",&i);
	p=Locatei_LinkList(L,i);
	 if(p!=NULL&&i!=0)
	 	printf("\n查找成功，第%d个元素是%d.\n",i,p->data);
	 	else
	 		printf("\n查找失败，没有第%d个元素.\n",i);
	 		flag=go_on();
	 		  }
	  }
void Locatex(LinkList L)
{
	LNode *p;
	DataType x;
	int flag=1,k;
	while(flag){
		printf("\n请输入要查找的元素；");
	 scanf("%d",&x);
	p=Locatex_LinkList(L,x,&k);
	 if(p!=NULL)
	 	printf("\n查找成功，第%d个元素是%d.\n",p->data,k);
	 	else
	 		printf("\n查找失败，没有第%d个元素.\n",x);
	 		flag=go_on();
	}
	  }	  
/*插入元素，在带头结点单链表中第i个位置之前插入元素x，即插入在第i个位置*/	
int Insert_LinkList(LinkList L,int i,DataType x)
{
	LNode *p,*s;
	int len;
	len=Length_LinkList(L);
	if(i<1||i>len+1){
		printf("\n插入位置错，不能插入.\n");
		return(0);
	}
	p=Locatei_LinkList(L,i-1);
	s=(LNode *)malloc(sizeof(LNode));
	if(s==NULL){
		printf("\n内存分配失败.\n");
		exit(-1); 
	}
	s->data=x;
	s->next=p->next;
	p->next=s;
	return(1);
  }  
	  
void Insert(LinkList L)
{
	DataType x;
	int i,flag=1,insert_flag;
	while(flag){
		printf("\n请输入要插入元素的位置；");
	 scanf("%d",&i);
	 printf("请输入要插入元素；");
	 scanf("%d",&x);
	insert_flag=Insert_LinkList(L,i,x);
	 if(insert_flag==1)
	 	printf("\n插入成功\n");
	 	else
	 		printf("\n插入失败.\n");
	 		flag=go_on();
	}
}
 /*删除元素，将顺序表第i个位置元素删除*/ 
 int Delete_LinkList(LinkList L,int i )
 {
 	LNode *p,*s;
 	int len;
 	if(Empty_LinkList(L)){	 
 	printf("\n表空，不能删除\n");
 	return(0);
 	
 }
 len=Length_LinkList(L);
 if(i<1||i>len){
 	printf("\n删除位置错，不能删除\n");
 	return(0);
 	
 }
 	p=Locatei_LinkList(L,i-1);
 	s=p->next;
 	p->next=s->next;
 	free(s);
 	return (1);
}
void Delete(LinkList L)
{
	int i,flag=1,delete_flag;
	while(flag){
		printf("\n请输入要删除元素的位置；");
		scanf("%d",&i);
		delete_flag=Delete_LinkList(L,i);
		if(delete_flag==1)
			printf("\n删除成功\n");
			else
			printf("\n删除失败\n");
			
			flag=go_on();
	}
}
 void Display_LinkList(LinkList L)
 {
 	LNode *p=L;
 	if(Empty_LinkList(L)==1)
 		printf("\n表空，无元素.\n");
		 else{
		 	printf("\n链表所有元素\n");
		 	while(p->next!=NULL){
		 		p=p->next;
		 		printf("%4d\n",p->data);
			 }
		 } 
	 
 	
 }
 main()
 { 
 	LinkList L;
 	char choice;
 	int flag=1;
 	Init_LinkList(&L);
 	do{
 		printf("\n");
 		printf("-------------------------单链表（带头结点）------------------------------\n");
 		printf("     1.......................插入元素.........................\n");
 		printf("     2.......................删除元素.........................\n");
 		printf("     3.......................查找元素.........................\n");
 		printf("     4......................,按值查找元素.....................\n");
 		printf("     5.......................输出表长.........................\n");
 		printf("     6.......................输出元素.........................\n");
 		printf("     0.......................退出.............................\n");
 		printf("--------------------------------------------------------------------------\n");
 		printf("------------------------请选择[1/2/3/4/5/6/0]-----------------------------");
 		
 		choice=getche();
 		switch(choice){
 			case '1':Insert(L);break;
 			case '2':Delete(L);break;
 			case '3':Locatei(L);break;
 			case '4':Locatex(L);break;
			 case '5':Length(L);break;
 			case '6':Display_LinkList(L);break;
 			case '0':flag=0;break;
		 }
	 wait();
	 }while(flag==1);
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
   
