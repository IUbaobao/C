#define _CRT_SECURE_NO_WARNINGS



typedef struct {
    int* a;//顺序表地址
    int Front;//头下标
    int rear;
    int N;
} MyCircularQueue;

//MyCircularQueue(k): 构造器，设置队列长度为 k 。
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->a = (int*)malloc(sizeof(int) * (k + 1));
    obj->Front = obj->rear = 0;
    obj->N = k + 1;
    return obj;
}

//isEmpty(): 检查循环队列是否为空。
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {

    return obj->Front == obj->rear;
}

//isFull(): 检查循环队列是否已满。
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->Front == (obj->rear + 1) % obj->N;
}

//enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;

    obj->a[obj->rear] = value;
    obj->rear++;
    obj->rear %= obj->N;
    return true;
}

//deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;
    obj->Front++;
    obj->Front %= obj->N;
    return true;
}

//Front: 从队首获取元素。如果队列为空，返回 -1 。
int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->a[obj->Front];
}


//Rear: 获取队尾元素。如果队列为空，返回 -1 。
int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->a[(obj->rear - 1 + obj->N) % obj->N];
}



void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    free(obj);
}