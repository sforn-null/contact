#include<stdio.h>
#include<string.h>
//类型的声明+函数的声明
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
	int sz;//记录通讯录里面有效人的信息
}contact;

//添加一指定的联系人信息
void add_contact(contact* c);

//显示通讯录中的信息
void show_contact(contact* c);

//删除指定的联系人信息
void del_contact(contact* c);

//查找指定的联系人信息
void search_contact(contact* c);

//修改指定的联系人信息
void modify_contact(contact* c);

//排序通讯录的数据
void sort_contact(contact* c);