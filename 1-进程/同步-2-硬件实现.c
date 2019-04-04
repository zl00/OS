// 关闭中断方式
...
关中断
critical section
开终端
...


// 硬件指令

// MARK: -- testandset
bool TestAndSet(bool *lock) {
    bool old;
    old = *lock;
    *lock = true;
    return old;
}
p {
    while TestAndSet(&lock);
    critical section;
    lock = false;

    remainder section;
}

// MARK: -- swap
Swap(bool *a, bool *b) {
    bool tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
p {
    key = true;
    while (key != false)
        Swap(&lock, key);
    critical section;
    lock = false;

    remainder section;
}