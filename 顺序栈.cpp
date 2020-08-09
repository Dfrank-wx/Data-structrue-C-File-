#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#define MAXSIZE 100
 typedef int DataType;
 typedef struct{
 	DataType *data;
 	int top;
 }SeqStack;
 
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
	 printf("\n继续吗？【y/n]");
	 choice=getch();
	 if(choice=='Y'||choice=='y')
	 break;
	 else if(choice=='N'||choice=='n'){
	 	flag=0;
	 	break;
	 }
 }return(flag); 
 }
 /*
 初始化，构造一空顺序栈*/
 void Init_SeqStack(SeqStack *S,int n)
 {
 	S->data=(DataType *)malloc(n*sizeof(DataType));
 	if(S->data==NULL){
 		printf("\n内存分配失败.\n");
		 exit(1); 
	 }
	 S->top=-1;
  } 
  /*判断顺序栈是否为空*/
 int Empty_SeqStack(SeqStack *S)
 {
 	if(S->top==-1)
 		return (1);
 		else
 		return(0);
  } 
  /*判断顺序栈是否为满*/
  int Full_SeqStack(SeqStack *S)
  {
  	if(S->top==MAXSIZE-1)
  	return (1);
	  else
	  return(0); 
   } 
 /*入栈，插入元素e为新的栈顶元素*/
 int Push_SeqStack(SeqStack *S,DataType e)
 {
 	if(Full_SeqStack(S)==1){
 		printf("\n栈满，不能入栈.\n");
 		return(0);
 		
	 }
	 else{
	 	S->top++;
	 	S->data[S->top]=e;
	 	return(1);
	 	
	 }
  } 
  void Push(SeqStack *S)
 

 /*插入元素，在顺序表第i个位置之前插入元素x，即插入在第i个位置*/
/*int Insert_SeqList(SeqList*L,int i,DataType x) 
 {
 	int j;
 	if(L->last==MAXSIZE-1){
 		printf("\n表满。不能加入.\n");
 		return(-1);
 		
	 }
	 if(i<1||i>L->last+2){     /*插入位置错，不能插入
	 printf("\n插入位置错，不能插入\n");
	 return(0);
 }
 for(j=L->last;j>=i-1;j--)
 	L->data[j+1]==L->data[j];
	 L->data[i-1]=x;
	 L->last++;
	 return(1);
 }*/
  
 //void Insert(SeqList*L)
 {
 	DataType x;
 	int flag=1,push_flag;
 	
 	while(flag){
	 
 	printf("\n请输入要入栈的元素；");
	 scanf("%d",&x);
	
	 push_flag=Push_SeqStack(S,x);
	 if(push_flag==1)
	 	printf("\n入栈成功\n");
	 	else
	 		printf("\n入栈失败\n");
	 		flag=go_on();
	 	
	  }}
/*出栈，删除栈顶元素，并由*e返回其值*/
int Pop_SeqStack(SeqStack *S ,DataType *e)
{
	if(Empty_SeqStack(S)){
		printf("\n栈空，不能出栈.\n");
		return(0);
		
	}
	else {
		*e=S->data[S->top];
		S->top--;
		return(1);
	}
	  }	  
void Pop(SeqStack *S)
{
	DataType x;
	int flag=1,pop_flag;
	while(flag){
		pop_flag=Pop_SeqStack(S,&x);
		if(pop_flag==1)
		printf("\n出栈成功，出栈元素为：%d\n",x);
		else
		printf("\n出栈失败.\n");
		flag=go_on();
	}
	  }	  
/*取栈顶元素，由*e返回其值*/
int GetTop_SeqStack(SeqStack *S,DataType *e)
{
	if(Empty_SeqStack(S)){
		printf("\n栈空，不能取栈顶元素\n");
		return(0);
		
	}
	else
	{
		*e=S->data[S->top];
		return (1);
	}
	  }	  
void Display_Top(SeqStack *S)
{
	DataType e;
	if(Empty_SeqStack(S)==1)
	printf("\n栈空，没有元素.\n");
	else{
		GetTop_SeqStack(S,&e);
		printf("\n栈顶元素.\n");
		printf("%4d\n",e);
	}
	  }	  
	  
	 
 /*删除元素，将顺序表第i个位置元素删除*/ 
 /*int Delete_SeqList(SeqList*L ,int i )
 {
 	int j;
 	if(L->last==-1){	 
 	printf("\n表空，不能删除\n");
 	return(-1);
 	
 }
 
 if(i<1||i>L->last+1){
 	printf("\n删除位置错，不能删除\n");
 	return(0);
 	
 }
 for(j=i;j<=L->last;j++)
 	L->data[j-1]=L->data[j];
 	L->last--;
 	return (1);
}

void Delete(SeqList *L)
{
	int i,flag=1,delete_flag;
	while(flag){
		printf("\n请输入要删除元素的位置；");
		scanf("%d",&i);
		
		delete_flag=Delete_SeqList(L,i);
		
		if(delete_flag==1)
			printf("\n删除成功\n");
			else
			printf("\n删除失败\n");
			
			flag=go_on();
	}
}
 int Locate_SeqList(SeqList*L,DataType x)
 {
 	int i=0;
 	
 	while(i<=L->last&&L->data[i]!=x)
 	i++;
 	if(i>L->last)
		return(-1);
		else
			return(i+1);
 }
 void Locate(SeqList *L)
 {
 	DataType x;
 	int flag=1,locate_flag;
 	
 	while(flag)
 	{printf("\n请输入要查找元素；");
 	scanf("%d",&x);
 	
 	locate_flag=Locate_SeqList(L,x);
 	
 	if(locate_flag>0)
 		printf("\n查找成功，%d 是第%d个元素\n",x,locate_flag);
 		else
 		 printf("\n查找失败，没有元素%d.\n",x);
 		 
 		 flag=go_on();
	 }
 }*/
 
 void Display_SeqStack(SeqStack *S)
 {
 	int i;
 	if(Empty_SeqStack(S)==1)
 	
 	printf("\n栈空，没有元素\n");
 	else{
 		printf("\n栈全部元素.\n");
 		printf("\n栈底----------------栈顶.\n");
	 }
 	for(i=0;i<=S->top;i++)
 		printf("%4d",S->data[i]);
 		printf("\n");
 }
 main()
 { 
 	SeqStack S;
 	char choice;
 	int flag=1;
 	Init_SeqStack(&S,MAXSIZE);
 	do{
 		printf("\n");
 		printf("-----顺序栈（动态数据实现）----\n");
 		printf("     1........入栈\n");
 		printf("     2........出栈\n");
 		printf("     3........输出栈顶元素\n");
 		printf("     4........输出全部元素\n");
 		printf("     0........退出\n");
 		printf("-----------------------\n");
 		printf("请选择[1/2/3/4/0]：");
 		
 		choice=getche();
 		switch(choice){
 			case '1':Push(&S);break;
 			case '2':Pop(&S);break;
 			case '3':Display_Top(&S);break;
 			case '4':Display_SeqStack(&S);break;
 			case '0':flag=0;break;
		 }
	 wait();
	 }while(flag==1);
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
