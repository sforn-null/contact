#include<stdio.h>
#include<string.h>
//���͵�����+����������
//
#define MAX 1000
#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_ADDR 100
#define MAX_QQ 15
#define MAX_SEX 5
typedef struct Peoinfo
{
	char name[MAX_NAME];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	char qq[MAX_QQ];
	char sex[MAX_SEX];
	short age;
}Peoinfo;

typedef struct contact
{
	Peoinfo data[MAX];
	int sz;//��¼ͨѶ¼������Ч�˵���Ϣ
}contact;

//���һָ������ϵ����Ϣ
void add_contact(contact* c);

//��ʾͨѶ¼�е���Ϣ
void show_contact(contact* c);

//ɾ��ָ������ϵ����Ϣ
void del_contact(contact* c);

//����ָ������ϵ����Ϣ
void search_contact(contact* c);

//�޸�ָ������ϵ����Ϣ
void modify_contact(contact* c);

//����ͨѶ¼������
void sort_contact(contact* c);