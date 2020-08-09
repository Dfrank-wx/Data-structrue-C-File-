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
 	printf("\n�밴�����...\n");
 	getch();
 	
 }
 int go_on()
 {
 	int flag=1;
 	char choice;
 	while(1){
	 printf("\n�����𣿡�y/n]");
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
 ��ʼ��������һ��˳��ջ*/
 void Init_SeqStack(SeqStack *S,int n)
 {
 	S->data=(DataType *)malloc(n*sizeof(DataType));
 	if(S->data==NULL){
 		printf("\n�ڴ����ʧ��.\n");
		 exit(1); 
	 }
	 S->top=-1;
  } 
  /*�ж�˳��ջ�Ƿ�Ϊ��*/
 int Empty_SeqStack(SeqStack *S)
 {
 	if(S->top==-1)
 		return (1);
 		else
 		return(0);
  } 
  /*�ж�˳��ջ�Ƿ�Ϊ��*/
  int Full_SeqStack(SeqStack *S)
  {
  	if(S->top==MAXSIZE-1)
  	return (1);
	  else
	  return(0); 
   } 
 /*��ջ������Ԫ��eΪ�µ�ջ��Ԫ��*/
 int Push_SeqStack(SeqStack *S,DataType e)
 {
 	if(Full_SeqStack(S)==1){
 		printf("\nջ����������ջ.\n");
 		return(0);
 		
	 }
	 else{
	 	S->top++;
	 	S->data[S->top]=e;
	 	return(1);
	 	
	 }
  } 
  void Push(SeqStack *S)
 

 /*����Ԫ�أ���˳����i��λ��֮ǰ����Ԫ��x���������ڵ�i��λ��*/
/*int Insert_SeqList(SeqList*L,int i,DataType x) 
 {
 	int j;
 	if(L->last==MAXSIZE-1){
 		printf("\n���������ܼ���.\n");
 		return(-1);
 		
	 }
	 if(i<1||i>L->last+2){     /*����λ�ô����ܲ���
	 printf("\n����λ�ô����ܲ���\n");
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
	 
 	printf("\n������Ҫ��ջ��Ԫ�أ�");
	 scanf("%d",&x);
	
	 push_flag=Push_SeqStack(S,x);
	 if(push_flag==1)
	 	printf("\n��ջ�ɹ�\n");
	 	else
	 		printf("\n��ջʧ��\n");
	 		flag=go_on();
	 	
	  }}
/*��ջ��ɾ��ջ��Ԫ�أ�����*e������ֵ*/
int Pop_SeqStack(SeqStack *S ,DataType *e)
{
	if(Empty_SeqStack(S)){
		printf("\nջ�գ����ܳ�ջ.\n");
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
		printf("\n��ջ�ɹ�����ջԪ��Ϊ��%d\n",x);
		else
		printf("\n��ջʧ��.\n");
		flag=go_on();
	}
	  }	  
/*ȡջ��Ԫ�أ���*e������ֵ*/
int GetTop_SeqStack(SeqStack *S,DataType *e)
{
	if(Empty_SeqStack(S)){
		printf("\nջ�գ�����ȡջ��Ԫ��\n");
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
	printf("\nջ�գ�û��Ԫ��.\n");
	else{
		GetTop_SeqStack(S,&e);
		printf("\nջ��Ԫ��.\n");
		printf("%4d\n",e);
	}
	  }	  
	  
	 
 /*ɾ��Ԫ�أ���˳����i��λ��Ԫ��ɾ��*/ 
 /*int Delete_SeqList(SeqList*L ,int i )
 {
 	int j;
 	if(L->last==-1){	 
 	printf("\n��գ�����ɾ��\n");
 	return(-1);
 	
 }
 
 if(i<1||i>L->last+1){
 	printf("\nɾ��λ�ô�����ɾ��\n");
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
		printf("\n������Ҫɾ��Ԫ�ص�λ�ã�");
		scanf("%d",&i);
		
		delete_flag=Delete_SeqList(L,i);
		
		if(delete_flag==1)
			printf("\nɾ���ɹ�\n");
			else
			printf("\nɾ��ʧ��\n");
			
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
 	{printf("\n������Ҫ����Ԫ�أ�");
 	scanf("%d",&x);
 	
 	locate_flag=Locate_SeqList(L,x);
 	
 	if(locate_flag>0)
 		printf("\n���ҳɹ���%d �ǵ�%d��Ԫ��\n",x,locate_flag);
 		else
 		 printf("\n����ʧ�ܣ�û��Ԫ��%d.\n",x);
 		 
 		 flag=go_on();
	 }
 }*/
 
 void Display_SeqStack(SeqStack *S)
 {
 	int i;
 	if(Empty_SeqStack(S)==1)
 	
 	printf("\nջ�գ�û��Ԫ��\n");
 	else{
 		printf("\nջȫ��Ԫ��.\n");
 		printf("\nջ��----------------ջ��.\n");
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
 		printf("-----˳��ջ����̬����ʵ�֣�----\n");
 		printf("     1........��ջ\n");
 		printf("     2........��ջ\n");
 		printf("     3........���ջ��Ԫ��\n");
 		printf("     4........���ȫ��Ԫ��\n");
 		printf("     0........�˳�\n");
 		printf("-----------------------\n");
 		printf("��ѡ��[1/2/3/4/0]��");
 		
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
