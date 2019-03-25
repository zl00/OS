/** 整型信号量
*/
wait(S) {
    while (S <= 0);
    S--;
}
signal(S) {
    S++;
}

/** 记录型信号量
*/
typedef struct {
    int value;
    struct process *L;
} semaphore;
void wait(semaphore s) {
    s.value--;
    if (s.value < 0) {
        Add 'this' process to S.L;
        block(S.L);
    }
}
void signal(semaphore s) {
    s.value++;
    if (s.value < 0) {
        Remove a process P from S.L;
        wakeup(P);
    }
}