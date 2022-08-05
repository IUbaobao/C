#define _CRT_SECURE_NO_WARNINGS





//
//������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������
//
//ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��
//
//���ʵ��Ӧ��֧�����²�����
//
//MyCircularQueue(k) : �����������ö��г���Ϊ k ��
//Front : �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1 ��
//Rear : ��ȡ��βԪ�ء��������Ϊ�գ����� - 1 ��
//enQueue(value) : ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
//deQueue() : ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
//isEmpty() : ���ѭ�������Ƿ�Ϊ�ա�
//isFull() : ���ѭ�������Ƿ�����
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/design-circular-queue
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
typedef struct {
    int* a;
    int Front;
    int Back;
    int N;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->a = (int*)malloc(sizeof(int) * (k + 1));
    obj->Front = obj->Back = 0;
    obj->N = k + 1;
    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {

    return obj->Front == obj->Back;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->Front == (obj->Back + 1) % obj->N;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;

    obj->a[obj->Back] = value;
    obj->Back++;
    obj->Back %= obj->N;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;
    obj->Front++;
    obj->Front %= obj->N;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->a[obj->Front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->a[(obj->Back - 1 + obj->N) % obj->N];
}



void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    free(obj);
}