#include "SeqList.h"
//��ʼ��
void initList(SeqList& L) {
	L.data=(DataType*)malloc(initSize* sizeof(DataType));
	if (!L.data) {printf("�洢�������.\n");exit(1);}
	L.maxSize = initSize; L.n = 0;
}
//�п�
bool Empty(SeqList& L) {
	return (L.n == 0) ? true : false;
}

//����
bool isFull(SeqList& L) {
	return (L.n == L.maxSize) ? true : false;
}

//����
int Search(SeqList& L, DataType x) {
	if(Empty(L)) return -1;
	for (int i = 0; i < L.n; i++) {
		if(L.data[i]==x) return i+1;
	}
	return -1;
}

//����
int Insert(SeqList& L, int i, DataType x) {
	if (isFull(L)) return false;
	if (i<1 || i>L.n + 1) return false;
	for (int j = L.n; j >=i; j--){
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = x;
	L.n++; return true;
}

//ɾ��
bool Remove(SeqList& L, int i, DataType& x) {
	if (Empty(L)) return false;
	if (i<1 || i>L.n) return false;
	x = L.data[i - 1];
	for (int j = i; j <=L.n; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.n--;
	return true;
}

//����
void createList(SeqList& L, DataType A[], int n) {
	initList (L);
	for (int i = 0; i < n; i++)
	{
		L.data[i] = A[i];
	}
	if (n > L.maxSize) L.maxSize = n;
	L.n = n;
}

//���
void printList(SeqList& L){
	for (int i = 0; i < L.n; i++) printf("%d ", L.data[i]);
		printf("\n");
}

int main() {
	SeqList L;
	int A[10] = { 11,12,13,14,15,16,17,18,19,20 };

	//����
	createList(L, A, 10);
	printList(L);

	//����Ԫ��15
	if (Search(L, 15) != -1)printf("��Ԫ��λ�ڵ�%d��λ��\n", Search(L, 15));
	else printf("��Ԫ�ز�����");

	//��5��λ�ò���648
	Insert(L, 5, 648);
	printList(L);

	//ɾ����5��Ԫ�ز�ȡ��ֵ
	int x;
	Remove(L, 5, x);
	printf("ɾ����Ԫ��ֵΪ%d\n",x);
	printList(L);

	return 0;
}
