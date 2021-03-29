#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//类型的声明+函数的声明
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

//默认可以存放五个人的信息
typedef struct contact
{
	Peoinfo *data;//数据
	int sz;//记录通讯录里面有效人的信息
	int capacity;//通讯录当前的容量
}contact;

//初始化通讯录
void InitContact(contact* c);

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

//销毁通讯录
void DestroyContact(contact* c);

//保存通讯录到文件
void save_contact(contact* c);

//读取文件数据
void load_contact(contact* c);

//检测是否要增容,并且增容
void check_capacity(contact* c);