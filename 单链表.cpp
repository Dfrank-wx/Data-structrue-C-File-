                                                                                                                                                                                                                                                                                                                                                                  
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                                                                                                                                                 
 typedef int DataType;								/*��������������*/ 
 typedef struct node{
 	DataType data;								/*������Ԫ��*/ 
 	struct node*next;
 }LNode,*LinkList;
 
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
	 printf("\n������[y/n]");
	 choice=getch();
	 if(choice=='Y'||choice=='y')
	 break;
	 else if(choice=='N'||choice=='n'){
	 	flag=0;
	 	break;
	 }
 }return(flag); 
 }
 /*��ʼ��������һ����˳���*/
 void Init_LinkList(LinkList *L)
 { 	
 	*L=(LNode*)malloc(sizeof(LNode));
 	if(*L==NULL){
 		printf("\n�ڴ����ʧ��.\n");
 		exit(-1);
	 }
 	(*L)->next=NULL;	
 }
 /*�жϴ�ͷ��㵥�����Ƿ�Ϊ��*/ 
int Empty_LinkList(LinkList L)
 {
 	if(L->next==NULL)
 		return(1);
 		else
 		return(0);
	 }
	 /*���ͷ��㵥������*/
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
	printf("\n��:%d\n",k);	
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
  /*��ֵ����Ԫ�أ��ڴ�ͷ��������в���Ԫ��ֵΪx�ĵ�1��Ԫ�أ����ҳɹ�������ֵ��x���ڽ���ָ�룬*k������λ����ţ�*/
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
	 
 	printf("\n������Ҫ���ҵ�Ԫ�ص�λ�ã�");
	 scanf("%d",&i);
	p=Locatei_LinkList(L,i);
	 if(p!=NULL&&i!=0)
	 	printf("\n���ҳɹ�����%d��Ԫ����%d.\n",i,p->data);
	 	else
	 		printf("\n����ʧ�ܣ�û�е�%d��Ԫ��.\n",i);
	 		flag=go_on();
	 		  }
	  }
void Locatex(LinkList L)
{
	LNode *p;
	DataType x;
	int flag=1,k;
	while(flag){
		printf("\n������Ҫ���ҵ�Ԫ�أ�");
	 scanf("%d",&x);
	p=Locatex_LinkList(L,x,&k);
	 if(p!=NULL)
	 	printf("\n���ҳɹ�����%d��Ԫ����%d.\n",p->data,k);
	 	else
	 		printf("\n����ʧ�ܣ�û�е�%d��Ԫ��.\n",x);
	 		flag=go_on();
	}
	  }	  
/*����Ԫ�أ��ڴ�ͷ��㵥�����е�i��λ��֮ǰ����Ԫ��x���������ڵ�i��λ��*/	
int Insert_LinkList(LinkList L,int i,DataType x)
{
	LNode *p,*s;
	int len;
	len=Length_LinkList(L);
	if(i<1||i>len+1){
		printf("\n����λ�ô����ܲ���.\n");
		return(0);
	}
	p=Locatei_LinkList(L,i-1);
	s=(LNode *)malloc(sizeof(LNode));
	if(s==NULL){
		printf("\n�ڴ����ʧ��.\n");
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
		printf("\n������Ҫ����Ԫ�ص�λ�ã�");
	 scanf("%d",&i);
	 printf("������Ҫ����Ԫ�أ�");
	 scanf("%d",&x);
	insert_flag=Insert_LinkList(L,i,x);
	 if(insert_flag==1)
	 	printf("\n����ɹ�\n");
	 	else
	 		printf("\n����ʧ��.\n");
	 		flag=go_on();
	}
}
 /*ɾ��Ԫ�أ���˳����i��λ��Ԫ��ɾ��*/ 
 int Delete_LinkList(LinkList L,int i )
 {
 	LNode *p,*s;
 	int len;
 	if(Empty_LinkList(L)){	 
 	printf("\n��գ�����ɾ��\n");
 	return(0);
 	
 }
 len=Length_LinkList(L);
 if(i<1||i>len){
 	printf("\nɾ��λ�ô�����ɾ��\n");
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
		printf("\n������Ҫɾ��Ԫ�ص�λ�ã�");
		scanf("%d",&i);
		delete_flag=Delete_LinkList(L,i);
		if(delete_flag==1)
			printf("\nɾ���ɹ�\n");
			else
			printf("\nɾ��ʧ��\n");
			
			flag=go_on();
	}
}
 void Display_LinkList(LinkList L)
 {
 	LNode *p=L;
 	if(Empty_LinkList(L)==1)
 		printf("\n��գ���Ԫ��.\n");
		 else{
		 	printf("\n��������Ԫ��\n");
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
 		printf("-------------------------��������ͷ��㣩------------------------------\n");
 		printf("     1.......................����Ԫ��.........................\n");
 		printf("     2.......................ɾ��Ԫ��.........................\n");
 		printf("     3.......................����Ԫ��.........................\n");
 		printf("     4......................,��ֵ����Ԫ��.....................\n");
 		printf("     5.......................�����.........................\n");
 		printf("     6.......................���Ԫ��.........................\n");
 		printf("     0.......................�˳�.............................\n");
 		printf("--------------------------------------------------------------------------\n");
 		printf("------------------------��ѡ��[1/2/3/4/5/6/0]-----------------------------");
 		
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
   
