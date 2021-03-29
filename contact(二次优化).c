#include"contact(二次优化).h"

void check_capacity(contact* c)
{
	if (c->sz == c->capacity)
	{

		//增加容量
		Peoinfo* ptr = (Peoinfo*)realloc(c->data, (c->capacity + 2) * sizeof(Peoinfo));
		if (ptr != NULL)
		{
			c->data = ptr;
			c->capacity += 2;
			printf("增容成功\n");
		}
		else
		{
			perror("add_contact::realloc");
			return;
		}
	}
}
void load_contact(contact* c)
{
	Peoinfo tmp = { 0 };
	int i = 0;
	FILE* pfread = fopen("contact.dat", "rb");
	if (pfread == NULL)
	{
		perror("open file for reading");
	}
	else
	{
		//加载数据
		while (fread(&tmp, sizeof(Peoinfo), 1, pfread) == 1)
		{
			check_capacity(c);
			//不用EOF，是因为EOF只能文本文档用
			c->data[c->sz] = tmp;
			c->sz++;
		}
	}
	fclose(pfread);
	pfread = NULL;
}
void InitContact(contact* c)
{
	c->sz = 0;
	c->capacity = DEFAULT_SZ;
	c->data = (Peoinfo*)malloc(DEFAULT_SZ * sizeof(Peoinfo));
	if (c->data == NULL)
	{
		perror("InitContact::malloc");
		return;
	}
	//加载通讯录的信息
	load_contact(c);
}
void add_contact(contact* c)
{
	//if (c->sz == MAX)
	//{
	//	printf("通讯录已满\n");
	//}
	//else
	//{
	//	printf("请输入名字:");//添加
	//	scanf("%s", c->data[c->sz].name);
	//	printf("请输入电话:");
	//	scanf("%s", c->data[c->sz].tele);
	//	printf("请输入地址:");
	//	scanf("%s", c->data[c->sz].addr);
	//	printf("请输入qq:");
	//	scanf("%s", c->data[c->sz].qq);
	//	printf("请输入性别:");
	//	scanf("%s", c->data[c->sz].sex);
	//	printf("请输入年龄:");
	//	scanf("%d", &(c->data[c->sz].age));//age是变量，需要取地址
	//	c->sz++;
	//	printf("添加成功\n");
	//}

	    check_capacity(c);
		printf("请输入名字:");//添加
		scanf("%s", c->data[c->sz].name);
		printf("请输入电话:");
		scanf("%s", c->data[c->sz].tele);
		printf("请输入地址:");
		scanf("%s", c->data[c->sz].addr);
		printf("请输入qq:");
		scanf("%s", c->data[c->sz].qq);
		printf("请输入性别:");
		scanf("%s", c->data[c->sz].sex);
		printf("请输入年龄:");
		scanf("%d", &(c->data[c->sz].age));//age是变量，需要取地址
		c->sz++;
		printf("添加成功\n");
}

void show_contact(contact* c)
{
	int i = 0;
	printf("%10s %12s %10s %13s %5s %5s\n", "名字", "电话", "地址", "qq", "年龄", "性别");
	for (i = 0;i < c->sz;i++)
	{
		printf("%10s %12s %10s %13s %5d %5s\n", 
			c->data[i].name,c->data[i].tele,
			c->data[i].addr, c->data[i].qq,
			c->data[i].age, c->data[i].sex);
	}
}
static int find_peop_by_name(contact* c,char name[])
//static 让函数只能在源文件内部被看到
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
		printf("抱歉，通讯录为空\n");
	}
	else
	{
		//1.找到指定的联系人的位置
		char name[MAX_NAME] = { 0 };
		printf("请输入要删除人名字:\n");
		scanf("%s", name);
		int pos = find_peop_by_name(c, name);
		if (pos == -1)
		{
			printf("很遗憾，删除的人不存在\n");
		}
		else
		{
			//2.删除指定练习人;
			int j = 0;
			for (j = 0;j < c->sz - 1;j++)
			{
				c->data[j] = c->data[j + 1];
			}
			c->sz--;
			printf("删除成功\n");
		}
	}
}

void search_contact(contact* c)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字:");
	scanf("%s", name);
	int ret = find_peop_by_name(c, name);
	if (ret == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("%10s %12s %10s %13s %5s %5s\n", 
			"名字", "电话", "地址", "qq", "年龄", "性别");
			printf("%10s %12s %10s %13s %5d %5s\n",
				c->data[ret].name, c->data[ret].tele,
				c->data[ret].addr, c->data[ret].qq,
				c->data[ret].age, c->data[ret].sex);
	}
}

void modify_contact(contact* c)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字:");
	scanf("%s", name);
	int ret = find_peop_by_name(c, name);
	if (ret == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("请输入新的名字:");
		scanf("%s", c->data[ret].name);
		printf("请输入新的电话:");
		scanf("%s", c->data[ret].tele);
		printf("请输入新的地址:");
		scanf("%s", c->data[ret].addr);
		printf("请输入新的qq:");
		scanf("%s", c->data[ret].qq);
		printf("请输入新的性别:");
		scanf("%s", c->data[ret].sex);
		printf("请输入新的年龄:");
		scanf("%d", &(c->data[ret].age));
		printf("修改成功\n");
	}
}

void sort_contact(contact* c)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < c->sz - 1;i++)
	{
		int flag = 1;//假设已经有序
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

void DestroyContact(contact* c)
{
	free(c->data);
	c->data = NULL;
	c->capacity = 0;
	c->sz = 0;
}

void save_contact(contact* c)
{
	int i = 0;
	FILE* pfwrite = fopen("contact.dat", "wb");
	if (pfwrite == NULL)
	{
		perror("open file for writting");
	}
	else
	{
		for (i = 0;i < c->sz;i++)
		{
			fwrite(c->data + i, sizeof(Peoinfo), 1, pfwrite);
		}
	}
	fclose(pfwrite);
	pfwrite = NULL;
}

