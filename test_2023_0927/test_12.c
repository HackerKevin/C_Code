#define _CRT_SECURE_NO_WARNINGS	1
//���������ʹ��
#include <stdio.h>
typedef struct st_type
{
	int i;
	int arr[0];//���������Ա
}type_a;
int main()
{
	printf("%d\n", sizeof(type_a));
	type_a* S1 = (type_a*)malloc(sizeof(type_a) + 40);//40�Ƿ��������������ڴ�
	if (S1 == NULL)
	{
		perror("malloc");
		return 1;
	}
	printf("%d\n", sizeof(type_a));
	for (int i = 0; i < 10; i++)
	{
		S1->arr[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", S1->arr[i]);
	}
	printf("\n");
	//����
	type_a* S2 = (type_a*)realloc(S1, sizeof(type_a) + 60);
	if (S2 == NULL)
	{
		perror("realloc");
		return 1;
	}
	S1 = S2;
	for (int i = 10; i < 15; i++)
	{
		S1->arr[i] = i;
	}
	for (int i = 0; i < 15; i++)
	{
		printf("%d ", S1->arr[i]);
	}
	free(S1);
	S1 = NULL;
	S2 = NULL;
	return 0;
}