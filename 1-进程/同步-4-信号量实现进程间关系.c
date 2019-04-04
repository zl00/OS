/** 同步
    要求 X -> Y的执行顺序
*/
semaphore s = 0;
P1 {
    X;
    V(s);
}

P2 {
    P(s);
    Y;
}

/** 互斥
*/
semaphore s= 1;
P1 {
    P(s);
    critical section;
    V(s);
}

P2 {
    P(s);
    critical section;
    V(s);
}

/** 前驱
*/