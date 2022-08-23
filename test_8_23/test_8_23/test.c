#define _CRT_SECURE_NO_WARNINGS



typedef struct {
    int* a;//˳����ַ
    int Front;//ͷ�±�
    int rear;
    int N;
} MyCircularQueue;

//MyCircularQueue(k): �����������ö��г���Ϊ k ��
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->a = (int*)malloc(sizeof(int) * (k + 1));
    obj->Front = obj->rear = 0;
    obj->N = k + 1;
    return obj;
}

//isEmpty(): ���ѭ�������Ƿ�Ϊ�ա�
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {

    return obj->Front == obj->rear;
}

//isFull(): ���ѭ�������Ƿ�������
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->Front == (obj->rear + 1) % obj->N;
}

//enQueue(value): ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;

    obj->a[obj->rear] = value;
    obj->rear++;
    obj->rear %= obj->N;
    return true;
}

//deQueue(): ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;
    obj->Front++;
    obj->Front %= obj->N;
    return true;
}

//Front: �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� -1 ��
int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->a[obj->Front];
}


//Rear: ��ȡ��βԪ�ء��������Ϊ�գ����� -1 ��
int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->a[(obj->rear - 1 + obj->N) % obj->N];
}



void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    free(obj);
}