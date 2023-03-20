typedef struct
{
    int* data;
    int size;
    int front;
    int rear;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k)
{
    MyCircularQueue* newCircularQueue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    assert(newCircularQueue);
    newCircularQueue->data = (int*)malloc(sizeof(int) * (k + 1));
    newCircularQueue->size = k;
    newCircularQueue->front = 0;
    newCircularQueue->rear = 0;
    return newCircularQueue;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    return (obj->rear + 1) % (obj->size + 1) == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
    if (myCircularQueueIsFull(obj)) {
        return false;
    }
    else
    {
        (obj->data)[obj->rear++] = value;
        obj->rear %= (obj->size + 1);
        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }
    else
    {
        obj->front++;
        obj->front %= (obj->size + 1);
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    else {
        return (obj->data)[obj->front];
    }
}

int myCircularQueueRear(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    else {
        return (obj->data)[(obj->rear - 1 + obj->size + 1) % (obj->size + 1)];
    }
}

void myCircularQueueFree(MyCircularQueue* obj)
{
    free(obj->data);
    free(obj);
}