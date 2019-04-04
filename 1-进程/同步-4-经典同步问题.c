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
        P(mutex);
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
分析： 典型的竞争关系
1. writer与其他都互斥
2. reader与writer互斥
3. reader与reader并不互斥

实现：
1. writer枷锁（writer与其他都互斥）
2. 第一个reader枷锁（reader与writer互斥）
3. 其他reader直接访问（reader与reader并不互斥）

缺点：
可能会造成写进程饿死
*/
int reader_count = 0; // 不为0则处于读状态，读进程可以直接读取文件
semaphore mutex = 1; 
semaphore rw = 1;

writer() {
    P(rw);
    Writing...
    V(rw);
}

reader() {
    P(mutex);
    if (reader_count == 0) P(rw);
    reader_count++;
    V(mutex);

    reading...

    P(mutex);
    reader_count--;
    if (reader_count == 0) V(rw);
    V(mutex);
}

/** 读写公平法
*/
int reader_count = 0;
semaphore mutex = 1;
semaphore rw = 1;
semaphore w = 1; // 限制了reader entry section的几率

writer() {
    P(w);
    P(rw);
    Writing...
    V(rw);
    V(w);
}

reader() {
    P(w);
    P(mutex);
    if (reader_count == 0) P(rw);
    reader_count++;
    V(mutex);
    V(w);

    Reading...

    P(mutex);
    reader_count--;
    if (reader_count) V(rw);
    V(mutex);
}