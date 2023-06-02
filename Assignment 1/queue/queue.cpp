#include <iostream>
#include <cstdlib>

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

    // Let's try some test cases
    std::cout << std::boolalpha;
    q.push(5);
    q.push(8);
    q.push(4);
    q.push(2);
    std::cout << q.front() << "\n";
    q.pop();
    std::cout << q.front() << "\n";
    q.pop();
    std::cout << q.front() << "\n";
    q.pop();
    std::cout << q.front() << "\n";
    std::cout << q.back() << "\n";
    std::cout << q.empty() << "\n";
    q.pop();
    std::cout << q.empty() << "\n";
    std::cout << q.size() << "\n";

    return 0;

}
