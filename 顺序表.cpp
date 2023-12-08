#include "SeqList.h"
//初始化
void initList(SeqList& L) {
	L.data=(DataType*)malloc(initSize* sizeof(DataType));
	if (!L.data) {printf("存储分配错误！.\n");exit(1);}
	L.maxSize = initSize; L.n = 0;
}
//判空
bool Empty(SeqList& L) {
	return (L.n == 0) ? true : false;
}

//判满
bool isFull(SeqList& L) {
	return (L.n == L.maxSize) ? true : false;
}

//查找
int Search(SeqList& L, DataType x) {
	if(Empty(L)) return -1;
	for (int i = 0; i < L.n; i++) {
		if(L.data[i]==x) return i+1;
	}
	return -1;
}

//插入
int Insert(SeqList& L, int i, DataType x) {
	if (isFull(L)) return false;
	if (i<1 || i>L.n + 1) return false;
	for (int j = L.n; j >=i; j--){
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = x;
	L.n++; return true;
}

//删除
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

//创建
void createList(SeqList& L, DataType A[], int n) {
	initList (L);
	for (int i = 0; i < n; i++)
	{
		L.data[i] = A[i];
	}
	if (n > L.maxSize) L.maxSize = n;
	L.n = n;
}

//输出
void printList(SeqList& L){
	for (int i = 0; i < L.n; i++) printf("%d ", L.data[i]);
		printf("\n");
}

int main() {
	SeqList L;
	int A[10] = { 11,12,13,14,15,16,17,18,19,20 };

	//创建
	createList(L, A, 10);
	printList(L);

	//查找元素15
	if (Search(L, 15) != -1)printf("该元素位于第%d个位置\n", Search(L, 15));
	else printf("该元素不存在");

	//第5个位置插入648
	Insert(L, 5, 648);
	printList(L);

	//删除第5个元素并取出值
	int x;
	Remove(L, 5, x);
	printf("删除的元素值为%d\n",x);
	printList(L);

	return 0;
}
