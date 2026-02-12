class myQueue {

  public:
    int *arr;
    int frontindex;
    int rear;
    int capacity;
    myQueue(int n) {
        // Define Data Structures
        capacity=n;
        arr=new int[capacity];
        frontindex=0;
        rear=-1;
    }

    bool isEmpty() {
        // check if the queue is empty
        return (rear<frontindex);
    }

    bool isFull() {
        // check if the queue is full
        return (rear-frontindex+1==capacity);
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull()) return;
        arr[++rear]=x;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty())
        return ;
        frontindex++;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty()) return -1;
        return arr[frontindex];
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty()) return -1;
        return arr[rear];
    }
};