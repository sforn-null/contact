#include<stdio.h>
#include"contact.h"
//第一个版本的通讯录
//1000个人的信息
//每个人的信息:
//名字+电话+地址+qq+性别+年龄

//0.退出
//1.增加
//2.删除
//3.查找
//4.修改
//5.排序
//6.显示
void menu()
{
	printf("*******************************\n");
	printf("******1. add       2. del   ***\n");
	printf("******3. search    4.modify ***\n");
	printf("******5. sort      6.show   ***\n");
	printf("******        0.exit        ***\n");
	printf("*******************************\n");

}
enum
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW
	//默认大写
};
void test()
{
	//创建的通讯录
	contact con = { 0 };
	int input = 0;
	do
	{
		menu();
		printf("请选择: ");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add_contact(&con);//实参的con会改变，所以得传地址
			break;
		case DEL:
			del_contact(&con);
			break;
		case SEARCH:
			search_contact(&con);
			break;
		case MODIFY:
			modify_contact(&con);
			break;
		case SORT:
			sort_contact(&con);
			break;
		case SHOW:
			show_contact(&con);
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}