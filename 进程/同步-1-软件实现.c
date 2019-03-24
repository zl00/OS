// MARK: - 软件实现同步

/** version 0.1 - 单标志法
分析：
1. 必须交替执行，违背“空闲让进”
*/
p0 {
    while(turn != 0);
    critical section;
    turn = 1;

    remainder section;
}

p1 {
    while (turn != 1);
    critical section;
    turn = 0;

    remainder section;
}

/** version 0.2 - 双标志先检查
分析：
1. 实现“空闲让进”；
2. 若按照 ① ② ③ ④顺序，违背“忙则等待”
*/
pi {
    while (flag[j]); ①
    flag[i] = true; ③
    critical section;
    flag[i] = false;

    remainder section;
}

pj {
    while (flag[i]); ②
    flag[j] = true; ④
    critical section;
    flag[j] = false;

    remainder section;
}

/** version 0.3 - 双标志后检查
分析：
若按照 ① ② ③ ④顺序，2个进程互相谦让，导致“饥饿”现象。
*/
pi {
    flag[i] = true; ①
    while (flag[j]); ③
    critical section;
    flag[i] = false;

    remainder section;
}

pj {
    flag[j] = true; ②
    while (flag[i]); ④
    critical section;
    flag[j] = false;

    remainder section;
}

/** Peterson's Algorithm
`flag[i] = true; turn = j;`要保持原子性吧，否则也有可能错吧
*/
pi {
    flag[i] = true; turn = j;
    while (flag[j] && turn == j);
    critical section;
    flag[i] = false;

    remainder section;
}

pj {
    flag[j] = true; turn = i;
    while (flag[i] && turn == i);
    critical section;
    flag[j] = false;

    remainder section;
}