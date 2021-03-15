#include"contact.h"
void add_contact(contact* c)
{
	if (c->sz == MAX)
	{
		printf("ͨѶ¼����\n");
	}
	else
	{
		printf("����������:");//���
		scanf("%s", c->data[c->sz].name);
		printf("������绰:");
		scanf("%s", c->data[c->sz].tele);
		printf("�������ַ:");
		scanf("%s", c->data[c->sz].addr);
		printf("������qq:");
		scanf("%s", c->data[c->sz].qq);
		printf("�������Ա�:");
		scanf("%s", c->data[c->sz].sex);
		printf("����������:");
		scanf("%d", &(c->data[c->sz].age));//age�Ǳ�������Ҫȡ��ַ
		c->sz++;
		printf("��ӳɹ�\n");
	}
}

void show_contact(contact* c)
{
	int i = 0;
	printf("%10s %12s %10s %13s %5s %5s\n", "����", "�绰", "��ַ", "qq", "����", "�Ա�");
	for (i = 0;i < c->sz;i++)
	{
		printf("%10s %12s %10s %13s %5d %5s\n", 
			c->data[i].name,c->data[i].tele,
			c->data[i].addr, c->data[i].qq,
			c->data[i].age, c->data[i].sex);
	}
}
static int find_peop_by_name(contact* c,char name[])
//static �ú���ֻ����Դ�ļ��ڲ�������
{

	int i = 0;
	for (i = 0;i < c->sz;i++)
	{
		if (strcmp(name, c->data[i].name)==0)
		{
			return i;
		}
	}
	return -1;
}

void del_contact(contact* c)
{
	if (c->sz == 0)
	{
		printf("��Ǹ��ͨѶ¼Ϊ��\n");
	}
	else
	{
		//1.�ҵ�ָ������ϵ�˵�λ��
		char name[MAX_NAME] = { 0 };
		printf("������Ҫɾ��������:\n");
		scanf("%s", name);
		int pos = find_peop_by_name(c, name);
		if (pos == -1)
		{
			printf("���ź���ɾ�����˲�����\n");
		}
		else
		{
			//2.ɾ��ָ����ϰ��;
			int j = 0;
			for (j = 0;j < c->sz - 1;j++)
			{
				c->data[j] = c->data[j + 1];
			}
			c->sz--;
			printf("ɾ���ɹ�\n");
		}
	}
}

void search_contact(contact* c)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�����˵�����:");
	scanf("%s", name);
	int ret = find_peop_by_name(c, name);
	if (ret == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("%10s %12s %10s %13s %5s %5s\n", 
			"����", "�绰", "��ַ", "qq", "����", "�Ա�");
			printf("%10s %12s %10s %13s %5d %5s\n",
				c->data[ret].name, c->data[ret].tele,
				c->data[ret].addr, c->data[ret].qq,
				c->data[ret].age, c->data[ret].sex);
	}
}

void modify_contact(contact* c)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸��˵�����:");
	scanf("%s", name);
	int ret = find_peop_by_name(c, name);
	if (ret == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("�������µ�����:");
		scanf("%s", c->data[ret].name);
		printf("�������µĵ绰:");
		scanf("%s", c->data[ret].tele);
		printf("�������µĵ�ַ:");
		scanf("%s", c->data[ret].addr);
		printf("�������µ�qq:");
		scanf("%s", c->data[ret].qq);
		printf("�������µ��Ա�:");
		scanf("%s", c->data[ret].sex);
		printf("�������µ�����:");
		scanf("%d", &(c->data[ret].age));
		printf("�޸ĳɹ�\n");
	}
}

void sort_contact(contact* c)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < c->sz - 1;i++)
	{
		int flag = 1;//�����Ѿ�����
		for (j = 0;j < c->sz - i - 1;j++)
		{
			if (strcmp(c->data[j].name, c->data[j + 1].name) > 0)
			{
				Peoinfo tmp = c->data[j];
				c->data[j] = c->data[j + 1];
				c->data[j + 1] = tmp;
				flag = 0;
			}
		}
		if (1 == flag)
		{
			break;
		}
	}
}
