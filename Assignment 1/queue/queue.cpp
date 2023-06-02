#include <iostream>
#include <cstdlib>
#include <chrono>
#include <queue>

#define CAPACITY 10000

class Queue {
public:
    int cap, sz, f, e;
    int* a;

    Queue() : cap{CAPACITY}, sz{0}, f{0}, e{0}, a{new int[CAPACITY]} {}

    // Check if the queue is empty
    bool empty() {
        return (sz == 0);
    }

    // Return the size of queue
    int size() {
        return sz;
    }

    // Return the element at the front of the queue
    int front() {
        return a[f];
    }

    // Return the element at the back of the queue
    int back() {
        int idx = e - 1;
        if (idx == -1) idx = cap - 1;
        return a[idx];
    }

    // Insert an element to the queue
    void push(int i) {
        if (sz == cap) return; // Return if the queue is full
        a[e] = i;
        e = (e + 1) % cap;
        ++ sz;
    }

    // Pop an element out of the queue
    void pop() {
        if (empty()) return; // Return if the queue is empty
        f = (f + 1) % cap;
        -- sz;
    }

    void print() {
        if (empty()) return;
        if (f >= e) {
            for (int i = f; i < cap; ++ i) std::cout << a[i] << " ";
            for (int i = 0; i < e; ++ i) std::cout << a[i] << " ";
            if (f != e) std::cout << a[e];
        } else for (int i = f; i <= e; ++ i) std::cout << a[i] << " ";
        std::cout << "\n";
    }

};



int main() {

    Queue q = Queue();
    std::queue<int> stlQ;

    // Let's try some test cases
    std::cout << std::boolalpha;

    std::cout << "Push 5 to queue:\n";
    auto start = std::chrono::steady_clock ::now();
    q.push(5);
    auto stop = std::chrono::steady_clock ::now();
    std::cout << "\tUsing my own queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
    start = std::chrono::steady_clock ::now();
    stlQ.push(5);
    stop = std::chrono::steady_clock ::now();
    std::cout << "\tUsing the stl's queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";

    std::cout << "Push 8 to queue:\n";
    start = std::chrono::steady_clock ::now();
    q.push(8);
    stop = std::chrono::steady_clock ::now();
    std::cout << "\tUsing my own queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
    start = std::chrono::steady_clock ::now();
    stlQ.push(8);
    stop = std::chrono::steady_clock ::now();
    std::cout << "\tUsing the stl's queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";

    std::cout << "Push 4 to queue:\n";
    start = std::chrono::steady_clock ::now();
    q.push(4);
    stop = std::chrono::steady_clock ::now();
    std::cout << "\tUsing my own queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
    start = std::chrono::steady_clock ::now();
    stlQ.push(4);
    stop = std::chrono::steady_clock ::now();
    std::cout << "\tUsing the stl's queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";

//    std::cout << "Push 2 to queue:\n";
//    start = std::chrono::steady_clock ::now();
//    q.push(2);
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing my own queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//    start = std::chrono::steady_clock ::now();
//    stlQ.push(2);
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing the stl's queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//
//    std::cout << "Print queue's front:\n";
//    start = std::chrono::steady_clock ::now();
//    std::cout << q.front() << "\n";
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing my own queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//    start = std::chrono::steady_clock ::now();
//    std::cout << stlQ.front() << "\n";
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing the stl's queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//
    std::cout << "Pop queue's front:\n";
    start = std::chrono::steady_clock ::now();
    q.pop();
    stop = std::chrono::steady_clock ::now();
    std::cout << "\tUsing my own queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
    start = std::chrono::steady_clock ::now();
    stlQ.pop();
    stop = std::chrono::steady_clock ::now();
    std::cout << "\tUsing the stl's queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//
//    std::cout << "Print queue's front:\n";
//    start = std::chrono::steady_clock ::now();
//    std::cout << q.front() << "\n";
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing my own queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//    start = std::chrono::steady_clock ::now();
//    std::cout << stlQ.front() << "\n";
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing the stl's queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//
//    std::cout << "Pop queue's front:\n";
//    start = std::chrono::steady_clock ::now();
//    q.pop();
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing my own queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//    start = std::chrono::steady_clock ::now();
//    stlQ.pop();
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing the stl's queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//
//    std::cout << "Print queue's front:\n";
//    start = std::chrono::steady_clock ::now();
//    std::cout << q.front() << "\n";
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing my own queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//    start = std::chrono::steady_clock ::now();
//    std::cout << stlQ.front() << "\n";
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing the stl's queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//
//    std::cout << "Pop queue's front:\n";
//    start = std::chrono::steady_clock ::now();
//    q.pop();
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing my own queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//    start = std::chrono::steady_clock ::now();
//    stlQ.pop();
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing the stl's queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//
//    std::cout << "Print queue's front:\n";
//    start = std::chrono::steady_clock ::now();
//    std::cout << q.front() << "\n";
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing my own queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//    start = std::chrono::steady_clock ::now();
//    std::cout << stlQ.front() << "\n";
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing the stl's queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//
//    std::cout << "Print queue's back:\n";
//    start = std::chrono::steady_clock ::now();
//    std::cout << q.back() << "\n";
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing my own queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//    start = std::chrono::steady_clock ::now();
//    std::cout << stlQ.back() << "\n";
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing the stl's queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//
    std::cout << "Check if queue is empty:\n";
    start = std::chrono::steady_clock ::now();
    std::cout << q.empty() << "\n";
    stop = std::chrono::steady_clock ::now();
    std::cout << "\tUsing my own queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
    start = std::chrono::steady_clock ::now();
    std::cout << stlQ.empty() << "\n";
    stop = std::chrono::steady_clock ::now();
    std::cout << "\tUsing the stl's queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//
//    std::cout << "Pop queue's front:\n";
//    start = std::chrono::steady_clock ::now();
//    q.pop();
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing my own queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//    start = std::chrono::steady_clock ::now();
//    stlQ.pop();
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing the stl's queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//
//    std::cout << "Check if queue is qmpty:\n";
//    start = std::chrono::steady_clock ::now();
//    std::cout << q.empty() << "\n";
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing my own queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
//    start = std::chrono::steady_clock ::now();
//    std::cout << stlQ.empty() << "\n";
//    stop = std::chrono::steady_clock ::now();
//    std::cout << "\tUsing the stl's queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";

    std::cout << "Print queue's size:\n";
    start = std::chrono::steady_clock ::now();
    std::cout << q.size() << "\n";
    stop = std::chrono::steady_clock ::now();
    std::cout << "\tUsing my own queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";
    start = std::chrono::steady_clock ::now();
    std::cout << stlQ.size() << "\n";
    stop = std::chrono::steady_clock ::now();
    std::cout << "\tUsing the stl's queue: " << std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count() << " ms\n";

    return 0;

}
