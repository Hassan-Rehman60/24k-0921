#include <iostream>
#include <exception>
using namespace std;

class OverflowError : public exception {};
class UnderflowError : public exception {};

template<typename T>
class BoundedQueue {
private:
    T* buffer;
    int head, tail, count;
    int capacity;

public:
    BoundedQueue(int size) : capacity(size), head(0), tail(0), count(0) {
        buffer = new T[capacity];
    }

    ~BoundedQueue() {
        delete[] buffer;
    }

    void enqueue(T value) {
        if (count == capacity) {
            throw OverflowError();
        }
        buffer[tail] = value;
        tail = (tail + 1) % capacity;
        count++;
    }

    T dequeue() {
        if (count == 0) {
            throw UnderflowError();
        }
        T val = buffer[head];
        head = (head + 1) % capacity;
        count--;
        return val;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    int size() const {
        return count;
    }
};

int main() {
    BoundedQueue<int> q(3);

    try {
        cout << "Adding elements to queue...\n";
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40); 
    } catch (OverflowError& e) {
        cout << "Error: Queue is full!" << endl;
        cout << "Exception info: " << e.what() << endl;
    }

    try {
        cout << "Dequeuing elements:\n";
        cout << q.dequeue() << endl;
        cout << q.dequeue() << endl;
        cout << q.dequeue() << endl;
        cout << "Trying to dequeue again...\n";
        cout << q.dequeue() << endl;
    } catch (UnderflowError& e) {
        cout << "Error: Queue is empty!" << endl;
        cout << "Exception info: " << e.what() << endl;
    }

    return 0;
}
