#include<stdio.h>
#include"contact.h"
//��һ���汾��ͨѶ¼
//1000���˵���Ϣ
//ÿ���˵���Ϣ:
//����+�绰+��ַ+qq+�Ա�+����

//0.�˳�
//1.����
//2.ɾ��
//3.����
//4.�޸�
//5.����
//6.��ʾ
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
	//Ĭ�ϴ�д
};
void test()
{
	//������ͨѶ¼
	contact con = { 0 };
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��: ");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add_contact(&con);//ʵ�ε�con��ı䣬���Եô���ַ
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}