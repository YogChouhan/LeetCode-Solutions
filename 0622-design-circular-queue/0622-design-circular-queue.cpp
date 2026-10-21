class MyCircularQueue {
private:
    int capacity;
    int head;
    int count;
    vector<int> queue;
public:
    MyCircularQueue(int k) {
        queue.resize(k);
        capacity = k;
        head = 0;
        count = 0;
    }
    
    bool enQueue(int value) {
        if(count>=capacity) return false;
        int tail_index = (head + count) % capacity;
        queue[tail_index] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(count==0) return false;
        head = (head + 1) % capacity;
        count--;
        return true;
    }
    
    int Front() {
        if(count==0) return -1;
        return queue[head];
    }
    
    int Rear() {
        if(count==0) return -1;
        int tail_index = (head + count - 1) % capacity;
        return queue[tail_index];
    }
    
    bool isEmpty() {
        if(count==0) return true;
        return false;
    }
    
    bool isFull() {
        if(count==capacity) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */