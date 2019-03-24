/** 生产消费者问题
分析：
1. 互斥：生产消费者对资源池的访问是互斥的
2. 同步：将资源池分作 -- 空闲资源和待用资源
    有空闲资源，生产者才生产；
    有待用资源，消费者才消费。
*/
semaphore mutex = 1;
semaphore full = 0;
semaphore empty = n;

producer() {
    while (1) {
        Produce an item in nextp;
        P(empty);
        P(mutext);
        Add nextp to buffer;
        V(mutex);
        V(full);
    }
}

consumer() {
    while (1) {
        P(full);
        P(mutex);
        Remove an item from buffer;
        V(mutex);
        V(empty);
        
        Consume the item;
    }
}


/** 读写问题
*/
int count = 0; // reader count
semaphore mutext = 1;
semaphore rw = 1;

writer () {
    P(rw);
    Writing...
    V(rw);
}

reader() {
    P(mutex);
    if (count == 0) P(rw);
    count++;
    V(mutex);

    reading...

    P(mutex);
    count--;
    if (count == 0) V(rw);
    V(mutex);
}