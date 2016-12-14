#include <stdlib.h>

#define OK 1
#define ERROR 0
#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12  //定义散列表长为数组的长度
#define NULLKEY -32768
typedef int Status;

typedef struct
{
    int *elem;  //数据元素存储基址，动态分配数组
    int count;  //当前数据元素个数
}HashTable;

int m=0;  //散列表表长，全局变量


Status InitHashTable (HashTable *H)
{
    int i;
    m = HASHSIZE;
    H->count = m;
    H->elem = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++)
        H->elem[i] = NULLKEY;
    return OK;
}


int Hash (int key)
{
    return key % m;  //散列函数为除留余数法
}


void InsertHash (HashTable *H, int key)
{
    int addr = Hash(key);
    while (H->elem[addr] != NULLKEY)
    {
        addr = (addr+1) % m;  //开放定址法的线性探测
    }
    H->elem[addr] = key;
}


Status SearchHash (HashTable H, int key, int *addr)  //哈希表H为取值操作，取H的复制，保护哈希表H
{
    *addr = Hash(key);
    while (H.elem[*addr] != key)  //由于是地址取余，如果未查找到key值，循环查找
    {
        *addr = (*addr + 1) % m;
        if (H.elem[*addr] == NULLKEY || *addr == Hash(key))  //当发现数组出现空位置或循环到数组首地址，说明关键字不存在
            return UNSUCCESS;
    }
    return SUCCESS;
}
