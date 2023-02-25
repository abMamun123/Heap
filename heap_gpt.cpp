#include <iostream>
#include <vector>

using namespace std;

class Heap {
public:
    Heap() {}

    void push(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i > 0 && heap[i] < heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        int i = 0;
        while (left_child(i) < heap.size()) {
            int j = left_child(i);
            if (right_child(i) < heap.size() && heap[right_child(i)] < heap[j]) {
                j = right_child(i);
            }
            if (heap[i] <= heap[j]) break;
            swap(heap[i], heap[j]);
            i = j;
        }
    }

    int top() const {
        if (heap.empty()) return -1;
        return heap[0];
    }

    bool empty() const {
        return heap.empty();
    }

private:
    vector<int> heap;

    int parent(int i) const {
        return (i - 1) / 2;
    }

    int left_child(int i) const {
        return 2 * i + 1;
    }

    int right_child(int i) const {
        return 2 * i + 2;
    }
};

int main() {
    Heap heap;
    heap.push(5);
    heap.push(2);
    heap.push(7);
    heap.push(3);

    while (!heap.empty()) {
        cout << heap.top() << " ";
        heap.pop();
    }
    cout << endl;

    return 0;
}
