#include<stdio.h>
#include<stdlib.h>
#define initSize 30
typedef int DataType;
typedef struct {
	DataType* data;
	int maxSize;
	int n;
}SeqList;
