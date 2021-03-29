#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//���͵�����+����������
//
#define DEFAULT_SZ 3
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

//Ĭ�Ͽ��Դ������˵���Ϣ
typedef struct contact
{
	Peoinfo *data;//����
	int sz;//��¼ͨѶ¼������Ч�˵���Ϣ
	int capacity;//ͨѶ¼��ǰ������
}contact;

//��ʼ��ͨѶ¼
void InitContact(contact* c);

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

//����ͨѶ¼
void DestroyContact(contact* c);

//����ͨѶ¼���ļ�
void save_contact(contact* c);

//��ȡ�ļ�����
void load_contact(contact* c);

//����Ƿ�Ҫ����,��������
void check_capacity(contact* c);